#include <stdio.h>
#include <stdbool.h> 

#define MAX 20

struct graph {
    int G[10][10], n, e, U, D;
    char type;
} obj;

struct queue {
    int q_arr[MAX];
    int rear, front;
} Q;

void insertEdge(int u, int v) {
    obj.G[u][v] = 1;
    if (obj.type == 'U')
        obj.G[v][u] = 1;
}

bool empty() { 
    return Q.front == Q.rear; 
}

void enqueue(int x) {
    if (Q.rear < (MAX - 1)) { 
        Q.rear++;
        Q.q_arr[Q.rear] = x;
    }
}

int dequeue() {
    if (!empty()) {
        Q.front++;
        return Q.q_arr[Q.front];
    }
    return -1; 
}

void BFT(int start, int visited[]) {
    int i, front;

    for (i = 0; i < obj.n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!empty()) {
        front = dequeue();
        printf("%d ", front);

        for (i = 0; i < obj.n; i++) {
            if (obj.G[front][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int choice, u, v;
    int visited[10];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &obj.n);


    printf("Enter the number of edges: ");
    scanf("%d", &obj.e);

    printf("Enter the edges (u v): \n");
    for (int i = 0; i < obj.e; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(u, v);
    }

    printf("Enter the starting vertex for BFT: ");
                scanf("%d", &u);
                printf("Breadth-First Traversal (BFT): ");
                BFT(u, visited);
                printf("\n");

    return 0;
}
