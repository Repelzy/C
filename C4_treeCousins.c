#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char STRING[1024];

struct node_
{
    char value[256];
    struct node_* leftMostChild;
    struct node_* rightSibling;
    struct node_* nextInQueue;
    struct node_* diameterRoot;
    struct node_* diameterMax1;
    struct node_* diameterMax2;
    struct node_* maxHeightChild;
    int maxHeight;
    int dfsOrder;
};
typedef struct node_ NODE;

NODE* makeNode(char* name);
NODE* addLast(NODE* p, char* name);
void addChild(char* parent, char* child);
NODE* findNode(NODE* p, char* name);
void enqueueNode(NODE* newNode);
void dequeueNode();
void printCousins(NODE* root, char* targetValue);

NODE* g_queueStart = NULL;
NODE* g_queueEnd = NULL;
int g_queueSize = 0;
NODE* g_root = NULL;

NODE* makeNode(char* name)
{
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    strcpy(newNode->value, name);
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    newNode->nextInQueue = NULL;
    newNode->diameterRoot = NULL;
    newNode->diameterMax1 = NULL;
    newNode->diameterMax2 = NULL;
    newNode->maxHeightChild = NULL;
    newNode->maxHeight = 0;
    newNode->dfsOrder = 0;

    return newNode;
}

NODE* addLast(NODE* p, char* name)
{
    NODE* newNode = makeNode(name);
    NODE* tmp = p;
    if (tmp == NULL)
    {
        return newNode;
    }
    else
    {
        while (tmp->rightSibling != NULL)
        {
            tmp = tmp->rightSibling;
        }
        tmp->rightSibling = newNode;
        return p;
    }
}

void addChild(char* parent, char* child)
{
    NODE* p = findNode(g_root, parent);
    if (p != NULL)
    {
        NODE* tmp = p->leftMostChild;
        p->leftMostChild = addLast(tmp, child);
    }
}

NODE* findNode(NODE* p, char* name)
{
    if (p == NULL)
        return NULL;
    else
    {
        if (strcmp(p->value, name) == 0)
        {
            return p;
        }
        else
        {
            NODE* tmp = findNode(p->leftMostChild, name);
            if (tmp != NULL)
            {
                return tmp;
            }
            else
            {
                NODE* tmp = p->rightSibling;
                if (tmp != NULL)
                {
                    NODE* tmp1 = findNode(tmp, name);
                    if (tmp1 != NULL)
                    {
                        return tmp1;
                    }
                }
            }
        }
    }
}

void enqueueNode(NODE* newNode)
{
    if (g_queueStart == NULL)
    {
        g_queueStart = newNode;
        g_queueEnd = newNode;
    }
    else
    {
        g_queueEnd->nextInQueue = newNode;
        g_queueEnd = newNode;
    }
    g_queueSize += 1;
}

void dequeueNode()
{
    if (g_queueStart != NULL)
    {
        g_queueSize -= 1;
        if (g_queueStart == g_queueEnd)
        {
            g_queueStart = NULL;
            g_queueEnd = NULL;
        }
        else
        {
            g_queueStart = g_queueStart->nextInQueue;
        }
    }
}

void printCousins(NODE* root, char* targetValue)
{
    enqueueNode(root);
    int found = 0;
    while (g_queueSize > 0 && found == 0)
    {
        int size = g_queueSize;
        while (size > 0)
        {
            NODE* top = g_queueStart;
            NODE* tmp = top->leftMostChild;
            int isChild = 0;
            while (tmp != NULL)
            {
                if (strcmp(tmp->value, targetValue) == 0)
                {
                    isChild = 1;
                    found = 1;
                    break;
                }
                tmp = tmp->rightSibling;
            }

            if (isChild == 0)
            {
                tmp = top->leftMostChild;
                while (tmp != NULL)
                {
                    enqueueNode(tmp);
                    tmp = tmp->rightSibling;
                }
            }
            dequeueNode();
            size -= 1;
        }
    }

    if (g_queueSize > 0)
    {
        while (g_queueSize > 0)
        {
            printf("%s ", g_queueStart->value);
            dequeueNode();
        }
    }
    else
        printf("NOT FOUND");

    printf("\n");
}

int main()
{
    char targetNode[256];
    scanf("%s", targetNode);

    char buffer[1024] = {0};
    char name[1024] = {0};
    char parent[1024] = {0};
    int root = 1;
    getchar();
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer) - 1, stdin);

        if (strstr(buffer, "$$") == buffer)
            break;
        else
        {
            int count = 0;
            char* tmpBuf = (char*)buffer;

            while (1)
            {
                memset(name, 0, sizeof(name));
                sscanf(tmpBuf, "%s", name);
                tmpBuf = strstr(tmpBuf, name) + strlen(name);

                if (strcmp(name, "$") == 0)
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
                    }
                    else
                    {
                        addChild(parent, name);
                    }
                    count += 1;
                }
            }
        }
    }

    printCousins(g_root, targetNode);

    return 0;
}
