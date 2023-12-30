#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1001

typedef struct Node
{
    int row;
    int col;
    int dist;
    struct Node* next;
}Node;

int n,m,r,c;
int a[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dist[MAX][MAX];

Node* queue = NULL;

bool isValid(int arr[][MAX], int row, int col) {
    return row >= 0 && col >= 0 && row < n && col < m && arr[row][col] == 0 && !visited[row][col];
}

Node *makeNode(int r, int c, int d) {
    Node *new_node = (Node*)calloc(1, sizeof(Node));
    new_node->col = c;
    new_node->row = r;
    new_node->dist = d;
    new_node->next = NULL;
    return new_node;
}


void enqueue(int r, int c, int d){
    visited[r][c] = true;
    Node * newNode = makeNode(r,c,d);
    if(queue == NULL){
        queue = newNode;
    }
    else{
        Node* temp = queue;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


Node* dequeue(){
    if(queue != NULL){
        Node *res = makeNode(queue->row, queue->col, queue->dist);
        Node* temp = queue;
        queue = queue->next;
        free(temp);
        return res;
    }
    else{
        return NULL;
    }
}


int isExit(int r, int c){
    return (r==0) || (c==0) || ( r== n-1) || (c==m-1);
}

int find(int r, int c){
    enqueue(r,c,0);
    while(1){
        Node *tmp = dequeue();
        if(tmp != NULL){
            int row = tmp->row;
            int col = tmp->col;
            int dist = tmp->dist;
            free(tmp);
            if(isExit(row,col) == 1){
                return dist + 1;
            }
            else{
                for(int i = 0; i < 4; i++){
                    int newX = row + dx[i];
                    int newY = col + dy[i];
                    if(isValid(a, newX, newY)){
                        enqueue(newX, newY, dist+1);
                    }
                }
            }
        }
        else{
            return -1;
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    memset(visited, false, sizeof(visited));
    int ans = find(r-1,c-1);
    printf("%d", ans);
}