// // craeting adjecency matrix and performing DFT recursive
// #include<stdio.h>

// int G[10][10];

// void initialize(int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//           G[i][j]=1;
//           G[i][j]++;  
//         }
//     }
// }

// void add_edges(int u, int v)
//  {   char g,d;
//     // printf("Enter the type of graph:\n Directed or Unidirected(d OR D):");
//     // scanf("%c ",&g);
//     // if(g==d)
//     // {
//     //     G[u][v]=G[v][u]=0;
//     // }
//     // else
//     // {
//         G[u][v]=G[v][u]=1;
//         // if(G[u][v]==G[v][u]==1)
//         // printf("1");
//     // }
// }

// void print(int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {  
//             add_edges(i,j);
//             printf("%d ",G[i][j]);
//             initialize(n);////////////
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int n,e,v,u;
//     printf("Enter Number of vertex:\n");
//     scanf("%d",&n);

//     printf("Enter Number of Edges:\n");
//     scanf("%d",&v);

//     initialize(n);

//     //add_edges(u,v);
//     printf("Enter the Edges(u and v)\n");
//     for(int i=0;i<n;i++)
//     {
//         int v,u;
//         scanf("%d %d",&u,&v);
//         if(G[u][v]==G[v][u]==1)
//         // {
//         //     printf("1");
//         // }
//         add_edges(u,v);
//     }
//     printf("Adjacency Matrix:\n");
//     print(n);
//     return 0;
// } 

// #include<stdio.h>

// struct graph()
// {
//     int G[10][10],n,e,U,D;
//     char type;
// }obj;

// int main()
// {
   
//      //read obj.n,obj.e,type,
//     // intilize G[10][10] to 0;

//     for(i=0;i<e;i++)
//     {
//         //read u,v
//        if(obj.type=='U')
//        G=insert(G);
//        //G[u][v]=g[v][u];
//     }
//        if(obj.type=='D')
//        {
//        //G[u][v]=1;
//     }//print matrix;
// }



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

void DFT(int vertex, int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int v = 0; v < obj.n; v++) {
        if (obj.G[vertex][v] && !visited[v]) {
            DFT(v, visited);
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
 
      printf("Depth-First Traversal starting from vertex 0: ");
    int visited[10] = {0};
    DFT(0, visited);

    return 0;
}

