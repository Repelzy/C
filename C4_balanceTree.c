#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <time.h>

typedef struct Node{
    int id;
    struct Node *left;
    struct Node *right;
}Node;

Node *root;
Node *cache[50001]= {0};

Node *makeRoot(int v){
    Node *p = (Node*)malloc(sizeof(Node));
    p-> id = v;
    p-> left = NULL;
    p-> right = NULL;
    cache[v] = p;
    return p;
}

Node *find(Node *r, int v){
    if (cache[v] != NULL)
        return cache[v];
    if(r==NULL) return NULL;
    if(r-> id == v) 
    {
        return r;
    }
    Node *p = find(r->left, v);
    if(p != NULL) return p;
    return find(r->right, v);
}
void addLeft(int u, int left){
    Node *tmp = find(root, u);
    if(tmp == NULL) return;
    if(tmp -> left != NULL){
        return;
    }
    tmp ->left = makeRoot(left);
}

void addRight(int u, int right){
    Node *tmp = find(root, u);
    if(tmp == NULL) return;
    if(tmp -> right != NULL){
        return;
    }
    tmp ->right = makeRoot(right);
}

int isBalanced(Node *r, int *height){
    int leftHeight = 0, rightHeight = 0;
    int l = 0, r_r = 0;
    if(r == NULL)  {
        *height = 0;
        return 1;
    }
    l = isBalanced(r->left, &leftHeight);
    r_r = isBalanced(r->right, &rightHeight);
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    if (abs(leftHeight - rightHeight) >= 2)
        return 0;
    else return l && r_r;
}

int main() {
    char cmd[10];
    int height = 0;
    int id, parent_id;
    while (scanf("%s", cmd) && cmd[0] != '*') {
        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &id);
            root = makeRoot(id);
        } else {
            scanf("%d %d", &id, &parent_id);
            if (strncmp(cmd, "AddL", 4) == 0) {
                addLeft(parent_id, id);
            } else if (strncmp(cmd, "AddR", 4) == 0) {
                addRight(parent_id, id);
            }
        }
    }
    isBalanced(root, &height);
    printf("%d %d\n", isBalanced(root, &height), height);
    return 0;
}
