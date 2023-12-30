#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200005

typedef struct Node {
    int id;
    struct Node* next;
} Node;

Node* graph[MAX];
int visited[MAX];
int maxD, maxNode;

Node* createNode(int id) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->id = id;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v){
    Node *node = createNode(v);
    node->next = graph[u];
    graph[u] = node;
}

void dfs(int u, int d){
    visited[u] = 1;
    if(d>maxD){
        maxD = d;
        maxNode = u;
    }
    for(Node *node= graph[u]; node != NULL; node = node -> next){
        if(!visited[node->id]){
            dfs(node->id, d+1);
        }
    }
}   

int main(){
    char buffer[1024] = { 0 };
    int u, v;
    while (1)
    {
        fgets(buffer, sizeof(buffer) - 1, stdin);
        if (strstr(buffer,"$$") == buffer) 
            break;
        int i = 0; 
        int len = strlen(buffer);
        while(i < len && buffer[i] != '$'){
            sscanf(buffer + i, "%d", &v);
            if(i == 0){
                u = v;
            }
            else{
                addEdge(u,v);
                addEdge(v,u);
            }
        while (i < len && buffer[i] != ' ') i++;
        while (i < len && buffer[i] == ' ') i++;
        }
    }
    maxD = -1;
    dfs(0,0);
    for (int i = 0; i < MAX; i++) visited[i] = 0; 
    dfs(maxNode, 0);
    printf("%d\n", maxD);
    return 0;
}

