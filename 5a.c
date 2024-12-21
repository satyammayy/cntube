#include<stdio.h>
int a[10][10], n;
void adj(int);
void main() { 
    int i, j, root; 
    printf("Enter number of nodes: "); 
    scanf("%d", &n);  
    printf("Enter adjacency matrix:\n"); 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Is there a connection from %d to %d (1 for Yes, 0 for No): ", i + 1, j + 1); 
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter root node (1 to %d): ", n); 
    scanf("%d", &root);
    // Convert to zero-based indexing for internal use
    if (root >= 1 && root <= n) {
        adj(root - 1); 
    } else {
        printf("Invalid root node!\n");
    }
}
void adj(int k) { 
    int j;
    printf("Adjacent nodes of root node %d are:\n", k + 1); 
    for (j = 0; j < n; j++) { 
        if (a[k][j] == 1) {  // Check adjacency
            printf("%d\t", j + 1); 
        }
    }
    printf("\n");
}
