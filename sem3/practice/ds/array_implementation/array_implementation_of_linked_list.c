#define NUM_NODES 50
#include <stdio.h>

struct node {
    int info;
    int next;
};
struct node Node[NUM_NODES];
int avail = 0;

void initialize()
{
    for (int i = 0; i < NUM_NODES; i++) {
        Node[i].next = i + 1;
    }
    Node[NUM_NODES - 1].next = -1;
}

int getNode()
{
    struct node nd = Node[avail];
    int p = avail;
    avail = nd.next;
    return p;
}

int freeNode(int p)
{
    int val = Node[p].info;
    Node[p].next = avail;
    avail = p;
    return val;
}

int main()
{
    initialize();
    int linked_list[10];
    int size = 0;
    char option;
    int val;
    int elem;
    while (1) {
        printf("Enter your option:\n");
        printf("1. Append element\n");
        printf("2. Pop element\n");
        printf("3. Print Array\n");
        printf("4. Quit\n");
        scanf("%c", &option);
        switch (option) {
        case '1':
            if (size == NUM_NODES) {
                printf("Overfow!\n");
                break;
            }
            printf("Enter element: ");

            scanf("%d", &elem);
            if (size == 0) {
                linked_list[size] = getNode();
                Node[linked_list[size]].info = elem;
                Node[linked_list[size]].next = -1;
                size++;
            }
            else {
                int p = getNode();
                Node[linked_list[size - 1]].next = p;
                linked_list[size] = p;
                Node[linked_list[size]].info = elem;
                Node[linked_list[size]].next = -1;
                size++;
            }
            printf("Element succesfully added\n");
            break;
        case '2':
            if (size == 0) {
                printf("Undeflow!\n");
                break;
            }
            val = freeNode(linked_list[size - 1]);
            size--;
            Node[linked_list[size - 1]].next = -1;
            printf("Succesfully removed %d\n", val);
            break;

        case '3':
            if (size == 0) {
                printf("Empty!\n");
                break;
            }
            printf("%d", Node[linked_list[0]].info);
            for (int i = 1; i < size; i++) {
                printf(", %d", Node[linked_list[i]].info);
            }
            printf("\n");
            break;

        case '4':
            break;
        }
        if (option == '4') {
            break;
        }
    }
    return 0;
}