#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_WIDTH 5
#define GRID_HEIGHT 5
#define MAX_SIZE (GRID_WIDTH * GRID_HEIGHT)

typedef struct {
    int x, y;    // Coordinates of the node
    int f, g, h; // F, G, H values of the node
    bool visited; // Track if the node is visited
} Node;

typedef struct {
    int x, y;    // Coordinates of the node
} PathNode;

typedef struct {
    Node arr[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue createPriorityQueue() {
    PriorityQueue pq;
    pq.size = 0;
    return pq;
}

void enqueue(PriorityQueue *pq, Node node) {
    int idx = pq->size++;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (node.f <= pq->arr[parent].f) {
            break;
        }
        pq->arr[idx] = pq->arr[parent];
        idx = parent;
    }
    pq->arr[idx] = node;
}

Node dequeue(PriorityQueue *pq) {
    Node minNode = pq->arr[0];
    Node lastNode = pq->arr[--pq->size];

    int idx = 0;
    while (idx * 2 + 1 < pq->size) {
        int child = idx * 2 + 1;
        if (child + 1 < pq->size && pq->arr[child + 1].f < pq->arr[child].f) {
            child++;
        }
        if (lastNode.f >= pq->arr[child].f) {
            break;
        }
        pq->arr[idx] = pq->arr[child];
        idx = child;
    }
    pq->arr[idx] = lastNode;
    return minNode;
}

int calculateHeuristic(Node current, Node goal) {
    return abs(current.x - goal.x) + abs(current.y - goal.y);
}

void generateNeighbors(Node current, Node *neighbors) {
    int index = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Node neighbor;
            neighbor.x = current.x + i;
            neighbor.y = current.y + j;

            if (neighbor.x >= 0 && neighbor.x < GRID_WIDTH && neighbor.y >= 0 && neighbor.y < GRID_HEIGHT) {
                neighbors[index++] = neighbor;
            }
        }
    }
}

int main() {
    // Create grid and nodes
    Node grid[GRID_WIDTH][GRID_HEIGHT];
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            grid[x][y].x = x;
            grid[x][y].y = y;
        }
    }

    Node start = {0, 0};
    Node goal = {GRID_WIDTH - 1, GRID_HEIGHT - 1};

    PriorityQueue openList = createPriorityQueue();
    enqueue(&openList, start);

    while (openList.size > 0) {
        Node current = dequeue(&openList);

        if (current.x == goal.x && current.y == goal.y) {
            printf("Goal reached!\n");

            // Display the path
            PathNode path[MAX_SIZE];
            int pathLength = 0;

            while (current.x != start.x || current.y != start.y) {
                path[pathLength].x = current.x;
                path[pathLength].y = current.y;
                pathLength++;
                current = grid[current.x][current.y];
            }

            printf("Path: ");
            for (int i = pathLength - 1; i >= 0; i--) {
                printf("(%d, %d) ", path[i].x, path[i].y);
            }
            printf("\n");

            return 0;
        }

        current.visited = true;

        // Generate neighbors and calculate their g, h, and f values
        Node neighbors[4];
        generateNeighbors(current, neighbors);
        for (int i = 0; i < 4; i++) {
            Node neighbor = neighbors[i];
            if (!neighbor.visited) {
                neighbor.g = current.g + 1; // Uniform movement cost
                neighbor.h = calculateHeuristic(neighbor, goal);
                neighbor.f = neighbor.g + neighbor.h;

                enqueue(&openList, neighbor);
                grid[neighbor.x][neighbor.y] = current;
            }
        }
    }

    printf("No path found.\n");

    return 0;
}
