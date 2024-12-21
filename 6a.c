#include<stdio.h>
struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];
int main() {
    int costmat[20][20];
    int nodes, i, j, k, count = 0;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &nodes); // Input number of nodes
    // Input validation
    if (nodes <= 0 || nodes > 20) {
        printf("Invalid number of nodes. Please enter a value between 1 and 20.\n");
        return 1;
    }
    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);   
            // If distance is negative or infinity-like, prompt the user
            if (costmat[i][j] < 0) {
                printf("Invalid cost! Distance cannot be negative.\n");
                return 1;
            }
            // Initialize the routing table
            costmat[i][i] = 0; // Self-distance is 0
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }
    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    // Update distance if a shorter path is found
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0); // Continue until no updates are needed
    // Display the routing table for each router
    for (i = 0; i < nodes; i++) {
        printf("\nRouting Table for Router %d:\n", i + 1);
        for (j = 0; j < nodes; j++) {
            printf("Node %d via %d Distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    return 0;
}
