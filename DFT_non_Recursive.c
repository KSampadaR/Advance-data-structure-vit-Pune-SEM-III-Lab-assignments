#include <stdio.h>

struct graph {
    int G[10][10], n, e, U, D;
    char type;
} obj;

void insertEdge(int u, int v) {
    obj.G[u][v] = 1;
    if (obj.type == 'U')
        obj.G[v][u] = 1; 
}

struct Stack {
    int items[10];
    int top;
};

void push(struct Stack *s, int item) {
    if (s->top < 9)
        s->items[++(s->top)] = item;
}

int pop(struct Stack *s) {
    if (s->top >= 0)
        return s->items[(s->top)--]; 
    return -1;
}

void DFTStack(int start) {
    int visited[10] = {0};
    struct Stack stack;
    stack.top = -1;

    push(&stack, start);
    visited[start] = 1;

    while (stack.top != -1) {
        int vertex = pop(&stack);
        printf("%d ", vertex);

        for (int v = 0; v < obj.n; v++) {
            if (obj.G[vertex][v] && !visited[v]) {
                push(&stack, v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    int i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &obj.n);

    printf("Enter number of edges: ");
    scanf("%d", &obj.e);

    printf("Enter graph type (U for undirected, D for directed): ");
    scanf(" %c", &obj.type);

 
    for (u = 0; u < obj.n; u++) {
        for (v = 0; v < obj.n; v++) {
            obj.G[u][v] = 0;
        }
    }

    for (i = 0; i < obj.e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= obj.n || v < 0 || v >= obj.n) {
            printf("Invalid vertices!\n");
            i--;
           continue;
        }

        insertEdge(u, v);
    }

    printf("Adjacency Matrix:\n");
    for (u = 0; u < obj.n; u++) {
        for (v = 0; v < obj.n; v++) {
            printf("%d ", obj.G[u][v]);
        }
        printf("\n");
    }
 
    printf("Depth-First Traversal starting from vertex 0 using stack: \n");
    DFTStack(0);

    return 0;
}


