#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 1000

typedef enum { TERMINAL, NON_TERMINAL, EPSILON } VarType;

typedef struct {
    char lhs;
    char rhs[MAX_LEN];
    int n_rhs;
} Production;

typedef struct {
    bool data[127];
    int count;
} Set;

VarType get_type(char ch) {
    if (ch == '#')
        return EPSILON;
    else if (ch >= 'A' && ch <= 'Z')
        return NON_TERMINAL;
    else
        return TERMINAL;
}

// merge two sets
void merge(Set* s1, Set s2) {
    int count = 0;
    for (int i = 0; i < 127; i++) {
        if (s1->data[i] || s2.data[i]) {
            count++;
            s1->data[i] = true;
        }
    }
    s1->count = count;
}

// Forward declaration
void find_first_for_nt(Production productions[MAX_LEN], int n_prod, char nt,
                       Set first[127]);

// Find first for a given rhs
Set find_first(char rhs[MAX_LEN], int n_rhs, int start, Set first[127],
               Production productions[MAX_LEN], int n_prod) {
    Set st = {0};
    if (start >= n_rhs) {
        st.count = 1;
        st.data['#'] = 1;
        return st;
    }
    if (get_type(rhs[start]) == TERMINAL || get_type(rhs[start]) == EPSILON) {
        st.data[rhs[start]] = 1;
        st.count++;
        return st;
    }
    if (first[rhs[start]].count == 0) {
        find_first_for_nt(productions, n_prod, rhs[start], first);
    }
    if (first[rhs[start]].count == 1 && first[rhs[start]].data['#'] == 1) {
        Set st2 = find_first(rhs, n_rhs, start + 1, first, productions, n_prod);
        merge(&st, st2);
        return st;
    } else {
        return first[rhs[start]];
    }
}

// find first for a given non-terminal using all productions
void find_first_for_nt(Production productions[MAX_LEN], int n_prod, char nt,
                       Set first[127]) {
    if (first[nt].count != 0)
        return;
    for (int i = 0; i < n_prod; i++) {
        if (productions[i].lhs != nt)
            continue;
        Set found = find_first(productions[i].rhs, productions[i].n_rhs, 0,
                               first, productions, n_prod);
        merge(&first[productions[i].lhs], found);
    }
}

// find follow for given non terminal
void find_follow_nt(Production productions[MAX_LEN], int n_prod, char nt,
                 Set first[127], Set follow[127], bool visited[127]) {
    Set follow_nt = {0};
    if (productions[0].lhs == nt) {
        // start symbol
        follow_nt.count++;
        follow_nt.data['$'] = true;
    }
    if (visited[nt]) {
        // loop -> no follow
        return;
    }
    visited[nt] = true;
    for (int i = 0; i < n_prod; i++) {
        for (int j = 0; j < productions[i].n_rhs; j++) {
            if (productions[i].rhs[j] == nt) {
                Set after_nt =
                    find_first(productions[i].rhs, productions[i].n_rhs, j + 1,
                               first, productions, n_prod);
                if (after_nt.count == 0 || after_nt.data['#'] == true) {
                    find_follow_nt(productions, n_prod, productions[i].lhs, first,
                                follow, visited);
                    merge(&follow_nt, follow[productions[i].lhs]);
                }
                merge(&follow_nt, after_nt);
                follow_nt.data['#'] = false;
            }
        }
    }
    follow[nt] = follow_nt;
}

int main() {
    int n_prod;
    printf("Enter the number of productions: ");
    scanf("%d", &n_prod);

    Production productions[MAX_LEN];
    printf("Enter productions\n");
    printf("Form: A->BC, use '#' for epsilon\n");
    for (int i = 0; i < n_prod; i++) {
        printf("%d > ", i + 1);
        char prod[MAX_LEN];
        scanf("%s", prod);

        // Parse production

        char lhs = prod[0];

        int n_rhs = 0;
        char rhs[MAX_LEN];
        for (int i = 3; prod[i] != 0; i++) {
            char rhs_val = prod[i];
            rhs[n_rhs] = rhs_val;
            n_rhs++;
        }
        Production production;
        production.lhs = lhs;
        for (int j = 0; j < n_rhs; j++) {
            production.rhs[j] = rhs[j];
        }
        production.n_rhs = n_rhs;
        productions[i] = production;
    }

    Set first[127] = {0};
    Set follow[127] = {0};

    // compute first
    for (int i = 0; i < n_prod; i++) {
        find_first_for_nt(productions, n_prod, productions[i].lhs, first);
    }

    // compute follow
    bool visited[127] = {false};
    for (int i = 0; i < n_prod; i++) {
        find_follow_nt(productions, n_prod, productions[i].lhs, first, follow,
                    visited);
    }

    printf("Firsts:-\n");
    for (int i = 0; i < 127; i++) {
        if (first[i].count == 0)
            continue;
        printf("%c: ", i);
        for (int j = 0; j < 127; j++) {
            if (first[i].data[j])
                printf("%c ", j);
        }
        printf("\n");
    }

    printf("Follows:-\n");
    for (int i = 0; i < 127; i++) {
        if (follow[i].count == 0)
            continue;
        printf("%c: ", i);
        for (int j = 0; j < 127; j++) {
            if (follow[i].data[j])
                printf("%c ", j);
        }
        printf("\n");
    }

    return 0;
}
