#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef struct Node
{
    int c;
    int e;
    struct Node *next;
} Node;
Node* expr[10001] = { NULL };

Node *makeNode(int c, int e){
    Node *new_node = malloc(sizeof(Node));
    new_node -> c = c;
    new_node -> e = e;
    new_node -> next = NULL;
    return new_node; 
}

void addTerm(int id, int c, int e){
    Node *new_node = makeNode(c,e);
    Node *tmp = expr[id];
    Node *prev = NULL;
    if(tmp == NULL){
        expr[id] = new_node;
    }else{
        while(tmp != NULL){
            if(tmp -> e <= e){
                break;
            }
            else{
                prev = tmp;
                tmp = tmp -> next;
            }
        }
        if(tmp == NULL){
            prev -> next = new_node;
        }else{
            if(tmp -> e == e){
                tmp -> c += c;
            }
            else{
                new_node -> next = tmp;
                if(prev != NULL){
                    prev->next = new_node;
                }
                else{
                    expr[id] = new_node;
                }
            }
        }
    }
}

int EvalPoly(int id, int v){
    Node *tmp = expr[id];
    if(tmp == NULL){
        return 0;
    }
    else{
        int res = 0; 
        while(tmp != NULL){
            res += tmp -> c * pow(v, tmp->e);
            tmp = tmp -> next;
        }
        return res;
    } 
}

void Destroy(int id){
    Node *tmp = expr[id];
    Node *next = NULL;
    while(tmp != NULL){
        next = tmp -> next;
        free(tmp);
        tmp = next;
    }
    expr[id] = NULL;
}

void addPoly(int id1, int id2, int id3){
    Destroy(id3);
    Node *tmp = expr[id1];
    while (tmp != NULL)
    {
        addTerm(id3, tmp->c, tmp->e);
        tmp = tmp->next;
    }
    tmp = expr[id2];
    while (tmp != NULL)
    {
        addTerm(id3, tmp->c, tmp->e);
        tmp = tmp->next;
    }
}

void PrintPoly(int id)
{
    Node* tmp = expr[id];
    while (tmp != NULL)
    {
        printf("%d %d ", tmp->c, tmp->e);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){
    char cmd[50];
    while (0 == 0)
    {
        scanf("%s", cmd);
        if (strcmp(cmd,"Create") == 0)
        {
        }else if (strcmp(cmd,"AddTerm") == 0)
        {
            int id, c, e;
            scanf("%d%d%d",&id, &c, &e);
            addTerm(id, c, e);
        }else if (strcmp(cmd,"EvaluatePoly") == 0)
        {
            int id, v;
            scanf("%d%d",&id, &v);
            printf("%d\n", EvalPoly(id, v));    
        }else if (strcmp(cmd,"AddPoly") == 0)
        {
            int id1, id2, id3;
            scanf("%d%d%d",&id1, &id2, &id3);
            addPoly(id1, id2, id3);
        }else if (strcmp(cmd,"PrintPoly") == 0)
        {
            int id;
            scanf("%d", &id);
            PrintPoly(id);
        }else if (strcmp(cmd,"Destroy") == 0)
        {
            int id;
            scanf("%d", &id);
            Destroy(id);
        }else
            break;       
    }
}