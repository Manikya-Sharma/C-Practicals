#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define INF (int)1e9

class LinkStateTable {
    // table :-
    //   _______________________
    //  | Neighbour | Distance |
    //  |----------------------|
   public:
    vector<pair<int, int>> table;
    void add_neighbour(int node, int distance) {
        table.push_back({node, distance});
    }
};

class RoutingTable {
    // table :-
    //  ________________________
    // | Node | Distance | Via |
    // |-----------------------|
   public:
    vector<tuple<int, int, vector<int>>> table;
    RoutingTable(int id, int num_nodes) {
        for (int i = 0; i < num_nodes; i++) {
            if (i == id)
                table.push_back({i, 0, {id}});
            else
                table.push_back({i, INF, {}});
        }
    }
    void update(int id, LinkStateTable* link_state_table) {
        for (auto& [node, dist] : link_state_table->table) {
            int new_distance = get<1>(table[id]) + dist;
            int old_distance = get<1>(table[node]);
            if (new_distance < old_distance) {
                vector<int> new_path = get<2>(table[id]);
                new_path.push_back(node);
                table[node] = {node, new_distance, new_path};
            }
        }
    }
};

class Router {
   public:
    LinkStateTable* link_state_table;
    RoutingTable* routing_table;
    int id;
    // set to keep track of the link states already received
    set<int> received;

    Router(vector<vector<pair<int, int>>>& adj, int id) : id(id) {
        link_state_table = new LinkStateTable();
        routing_table = new RoutingTable(id, adj.size());
        // prepare link state table
        for (auto& [nbr, dist] : adj[id]) {
            link_state_table->add_neighbour(nbr, dist);
        }
    }
    ~Router() {
        delete link_state_table;
        delete routing_table;
    }
    void flood(int lsr_id, LinkStateTable* nbr_table, vector<Router*> routers) {
        if (received.find(lsr_id) != received.end()) {
            return;
        }
        received.insert(lsr_id);
        // update its own routing table
        routing_table->update(lsr_id, nbr_table);
        // flood to neighbours
        for (auto& [node, dist] : link_state_table->table) {
            // don't send to parent
            if (node == lsr_id)
                continue;
            routers[node]->flood(lsr_id, nbr_table, routers);
        }
    }
};

int main() {
    // network configuration
    //        3
    //     B ---- D
    //  1 / |     |\ 12
    //   A  |2   3| F
    //  4 \|      |/ 5
    //     C ---- E
    //        7

    vector<vector<pair<int, int>>> adj = {
        {{1, 1}, {2, 4}},         {{0, 1}, {2, 2}, {3, 3}},
        {{0, 4}, {1, 2}, {4, 7}}, {{1, 3}, {4, 3}, {5, 12}},
        {{2, 7}, {3, 3}, {5, 5}}, {{3, 12}, {4, 5}}};

    int num_nodes = adj.size();

    vector<Router*> routers(num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        routers[i] = new Router(adj, i);
    }

    // flood the routers
    for (int i = 0; i < num_nodes; i++) {
        routers[i]->flood(i, routers[i]->link_state_table, routers);
    }

    // view the graph prepared by any node using dijkstra
    int start = 1;
    for (auto& [node, distance, via] : routers[start]->routing_table->table) {
        cout << "Path from node " << start << " to node " << node
             << " has distance " << distance << " with path ";
        for (auto& v : via) {
            cout << v << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < num_nodes; i++) {
        delete routers[i];
    }

    return 0;
}
