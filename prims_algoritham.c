// Algoritham
// 999 for non edgecency.
// initialize the cost maxtrix 999 insted of zero 
// till number of edges add the loop
// create a cost matrix first.
// get sppannig matrix and inintilize it to zero.
//this matrix is also useful for the 
// infix to post fix for the stack.
//priority queue
//circular queue
//linked list
// hashig
// avl tree
//b tree ans b+ tree not for practical
//threaded
//binary tree
//20 marks for implimentation
//10 for change given by external
//20 for viva and all
// tower of honae using stack.
// tic toc toe using stack.
#include <stdio.h>

#define INF 999 // A very large number to represent infinity

int main() {
    int numNodes; // Number of nodes in the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int costMatrix[numNodes][numNodes]; // The cost matrix representing edge weights
    int spanningMatrix[numNodes][numNodes]; // The spanning tree matrix

    // Initialize the cost matrix
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            costMatrix[i][j] = INF; // Initially, set all edge costs to infinity
            spanningMatrix[i][j] = 0; // Initialize the spanning matrix to 0
        }
    }

    // Input the edge costs
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            int cost;
            printf("Enter the cost between Node %d and Node %d (or 999 for no connection): ", i + 1, j + 1);
            scanf("%d", &cost);

            if (cost != 999) {
                costMatrix[i][j] = cost;
                costMatrix[j][i] = cost; // Since the graph is undirected update the reverse edge
            }
        }
    }

    // Prim's algorithm to find the minimum spanning tree
    int selectedNodes[numNodes]; // To keep track of selected nodes
    for (int i = 0; i < numNodes; i++) {
        selectedNodes[i] = 0; // Initially no nodes are selected
    }

    int numSelectedNodes = 1; // Start with one node
    selectedNodes[0] = 1; // Select the first node

    while (numSelectedNodes < numNodes) {
        int minCost = INF;
        int u, v;

        // Find the minimum cost edge that connects a selected node to an unselected node
        for (int i = 0; i < numNodes; i++) {
            if (selectedNodes[i]) {
                for (int j = 0; j < numNodes; j++) {
                    if (!selectedNodes[j] && costMatrix[i][j] < minCost) {
                        minCost = costMatrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Select the node v and mark the edge (u, v) as part of the minimum spanning tree
        selectedNodes[v] = 1;
        spanningMatrix[u][v] = minCost;
        spanningMatrix[v][u] = minCost;

        numSelectedNodes++;
    }

    // Print the minimum spanning tree
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (spanningMatrix[i][j] != 0) {
                printf("Edge %d-%d: Cost %d\n", i + 1, j + 1, spanningMatrix[i][j]);
            }
        }
    }

    return 0;
}
