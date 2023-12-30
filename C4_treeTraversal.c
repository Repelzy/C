#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{
    int id;
    struct Node *leftmostChild;
    struct Node *rightSibling;
}Node;

Node *root;

Node *makeRoot(int v){
    Node *p = (Node*)malloc(sizeof(Node));
    p-> id = v;
    p-> leftmostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node *find(int v, Node *r){
    if(r==NULL) return NULL;
    if(r-> id == v) return r;
    Node *p = r->leftmostChild;
    while(p != NULL){
        Node *q = find(v, p);
        if(q != NULL) return q;
        p = p-> rightSibling;
    }
    return NULL;
}

void insert(int u, int v){
    Node *r = find(v, root);
    Node *p = NULL;
    p = makeRoot(u);
    if(r->leftmostChild == NULL) r->leftmostChild = p;
    else{
        Node *h = r->leftmostChild;
        while(h->rightSibling != NULL) h = h->rightSibling;
        h->rightSibling = p;
    }
}

void inOrder(Node *r){
    if(r == NULL) return;
    Node *p = r-> leftmostChild; 
    inOrder(p);
    printf("%d ", r->id); 
    if(p == NULL) return;
    p = p->rightSibling;
    while(p!=NULL){
        inOrder(p); 
        p = p->rightSibling;
    }
}

void preOrder(Node *r){
    if (r == NULL) return;
    printf("%d ", r->id);
    Node *p = r-> leftmostChild; 
    while(p!= NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node *r){
    if (r == NULL) return;
    Node *p = r-> leftmostChild; 
    while(p!= NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->id);
}

int main(){
    char cmd[50];
    while(0==0){
        scanf("%s", cmd);
        if(strcmp(cmd, "MakeRoot") == 0){
            int v;
            scanf("%d", &v);
            root = makeRoot(v);
        }
        else if(strcmp(cmd, "Insert") == 0){
            int u,v; 
            scanf("%d %d", &u, &v);
            insert(u,v);
        }
        else if(strcmp(cmd, "InOrder")==0){
            inOrder(root);
            printf("\n");
        }
        else if(strcmp(cmd, "PostOrder")==0){
            postOrder(root);
            printf("\n");
        }
        else if(strcmp(cmd, "PreOrder")==0){
            preOrder(root);
            printf("\n");
        }
        else if(strcmp(cmd, "*") == 0){
            break;
        }
    }
}
