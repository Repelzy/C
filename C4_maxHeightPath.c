#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char STRING[1024];

struct node_
{
    char value[256];
    struct node_* leftMostChild;
    struct node_* rightSibling;
};
typedef struct node_ NODE;

NODE* makeNode(char* name);
NODE* findNode(NODE* p, char* name);
NODE* addLast(NODE* p, char* name);
void addChild(char* parent, char* child);

NODE* g_root = NULL;
STRING g_lines[1024];
int g_count = 0;
NODE* longestPath[1024];
int longestPathLength = 0;
int maxDepth = 0;


NODE* makeNode(char* name)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    strcpy(newNode->value, name);
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

NODE* addLast(NODE* p, char* name)
{
    NODE* newNode = makeNode(name);
    if (p == NULL)
    {
        return newNode;
    }
    
    NODE* tmp = p;
    while (tmp->rightSibling != NULL)
    {
        tmp = tmp->rightSibling;
    }
    tmp->rightSibling = newNode;
    return p;
}

void addChild(char* parent, char* child)
{
    NODE* p = findNode(g_root, parent);
    if (p != NULL)
    {
        p->leftMostChild = addLast(p->leftMostChild, child);
    }
}

NODE* findNode(NODE* p, char* name)
{
    if (p == NULL)
        return NULL;

    if (strcmp(p->value, name) == 0)
    {
        return p;
    }

    NODE* tmp = findNode(p->leftMostChild, name);
    if (tmp != NULL)
    {
        return tmp;
    }

    return findNode(p->rightSibling, name);
}

void find_max_depth(NODE* node, int depth, NODE* path[], int pathLength){
    if(node == NULL){
        return;
    }
    else{
        path[pathLength] = node;
        pathLength++;
        if(depth > maxDepth){
            maxDepth = depth;
            longestPathLength = pathLength;
            for(int i = 0; i < pathLength; i++){
                longestPath[i] = path[i];
            }
        }
        NODE* tmp = node->leftMostChild;
        while(tmp != NULL){
            find_max_depth(tmp, depth+1, path, pathLength);
            tmp = tmp->rightSibling;
        }
    }
}

int main(){
    NODE* path[1024];
    char buffer[1024] = { 0 };
    char name[1024] = { 0 };
    char parent[1024] = { 0 };
    int root = 1;
    while (0 == 0)
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer) - 1, stdin);
        if (strstr(buffer,"$$") == buffer) 
            break;
        else
        {
            int count = 0;
            char* tmpBuf = (char*)buffer;
            while (0 == 0)
            {
                memset(name, 0, sizeof(name));
                sscanf(tmpBuf,"%s", name);
                tmpBuf = strstr(tmpBuf, name) + strlen(name);
                if (strcmp(name,"$") == 0)
                    break;
                else
                {
                    if (count == 0)
                    {
                        memset(parent, 0, sizeof(parent));
                        strcpy(parent, name);        
                        if (root == 1)
                        {
                            root = 0;
                            g_root = makeNode(name);
                        }
                    }else
                    {
                        addChild(parent, name);
                    }
                    count += 1;
                }
            }
        }
    }
    find_max_depth(g_root, 1, path, 0);
    printf("%d\n", maxDepth);
    for (int i = 0; i < longestPathLength; i++) {
        printf("%s ", longestPath[i]->value);
    }
    printf("\n");
}