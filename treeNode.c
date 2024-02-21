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
    //Node *p = find(u, root);
    //if(p!=NULL) return;
    p = makeRoot(u);
    if(r->leftmostChild == NULL) r->leftmostChild = p;
    else{
        Node *h = r->leftmostChild;
        while(h->rightSibling != NULL) h = h->rightSibling;
        h->rightSibling = p;
    }
}

int count(Node *r){
    if (r == NULL) return 0;
    int res = 1;
    Node *p = r-> leftmostChild;
    while(p != NULL){
        res += count(p);
        p = p->rightSibling;
    }
    return res;
}

int countLeaves(Node *r){
    if(r == NULL) return 0;
    if(r->leftmostChild == NULL) return 1;
    int ans = 0;
    for(Node *p = r->leftmostChild; p!= NULL; p = p->rightSibling){
        ans += countLeaves(p);
    }
    return ans;
}

int heightNode(Node *r){
    if (r== NULL) return 0;
    int maxHeight = 0;
    for(Node *p = r->leftmostChild; p!=NULL; p=p->rightSibling){
        int h = heightNode(p);
        if (h > maxHeight) maxHeight = h;
    }
    return maxHeight + 1;
}

int height(int v){
    Node *p = find(v, root);
    return heightNode(p);
}

int depthNode(int v, Node *r, int d){
    if(r == NULL) return -1; // ko ton tai
    if(r->id == v) return d;
    for(Node *p = r->leftmostChild; p!=NULL; p=p->rightSibling){
        if(p->id == v) return d+1;
        int nd = depthNode(v, p, d+1);
        if(nd > -1) return nd;
    }
    return -1;
}

int depth(int v){
    return depthNode(v, root ,1);
}

void printTree(Node *r){
    if(r == NULL) return;
    printf("%d: ", r->id);
    for(Node *p = r->leftmostChild; p != NULL; p = p->rightSibling){
        printf("%d ", p->id);
    }
    printf("\n");
    for(Node *p = r->leftmostChild; p != NULL; p = p->rightSibling){
        printTree(p);
    }
}

void inOrder(Node *r){
    if(r == NULL) return;
    Node *p = r-> leftmostChild; // p tro vao root r1
    inOrder(p);
    printf("%d ", r->id); // tham nut goc
    if(p == NULL) return;
    p = p->rightSibling;// truy cap root r2
    while(p!=NULL){
        inOrder(p); // tham theo thu tu giua
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
        else if(strcmp(cmd, "*") == 0) {
            break;
        }
    }
        // printf("%d \n", countLeaves(root));
        // printf("%d \n", count(root));
        // printf("%d \n", height(1));
        // printf("%d \n", depth(1));
    return 0;
}
