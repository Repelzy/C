#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef char STRING[1024];

struct node_
{
    char value[256];
    struct node_* leftMostChild;
    struct node_* rightSibling;
    struct node_* diameterRoot;
    struct node_* diameterMax1;
    struct node_* diameterMax2;
    struct node_* maxHeightChild;
    int maxHeight;
    int dfsOrder;
};
typedef struct node_ NODE;
NODE* makeNode(char* name);
NODE* findNode(NODE* p, char* name);
NODE* addLast(NODE* p, char* name);
void addChild(char* parent, char* child);
NODE* g_root = NULL;
STRING g_lines[1024];
int g_count = 0;
int g_order = 0;

NODE* makeNode(char* name)
{
    NODE* newNode = (NODE*)calloc(1 , sizeof(NODE));
    strcpy(newNode->value, name);
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    newNode->diameterRoot = NULL;
    newNode->diameterMax1 = NULL;
    newNode->diameterMax2 = NULL;
    newNode->maxHeightChild = NULL;
    newNode->maxHeight = 0;
    newNode->dfsOrder = 0;
}

NODE* addLast(NODE* p, char* name)
{
    NODE* newNode = makeNode(name);
    NODE* tmp = p;
    if (tmp == NULL)
    {
        return newNode;
    }else
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
        }else
        {
            NODE* tmp = findNode(p->leftMostChild, name);
            if (tmp != NULL)
            {
                return tmp;
            }else
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


void visitTree(NODE* p)
{
    if (p != NULL)
    {
        p->dfsOrder = g_order++;
        NODE* tmp = p->leftMostChild;
        visitTree(tmp);
        tmp = p->rightSibling;
        if (tmp != NULL)
        {
            visitTree(tmp);
        }
    }
}

int heightTree(NODE* p)
{
    if (p == NULL)
        return 0;
    else
    {
        int h = 1;
        NODE* tmp = p->leftMostChild;
        while (tmp != NULL)
        {
            int h1 = heightTree(tmp) + 1;
            if (h1 > h)
            {
                h = h1;        
                p->maxHeightChild = tmp;
                p->maxHeight = h;
            }
            tmp = tmp->rightSibling;
        }
        return h;
    }
}

int diameterTree(NODE* p)
{
    if (p == NULL)
        return 0;
    int max1 = 0, max2 = 0;
    NODE* tmp = p->leftMostChild;
    NODE* tmpMax1 = NULL;
    NODE* tmpMax2 = NULL;
    while (tmp != NULL)
    {
        int h = heightTree(tmp);
        if (h > max1)
        {
            tmpMax2 = tmpMax1;
            tmpMax1 = tmp;
            max2 = max1;
            max1 = h;
        }else if (h > max2)
        {
            tmpMax2 = tmp;
            max2 = h;
        }
        tmp = tmp->rightSibling;
    }
    int maxChildD = 0;
    NODE* diameterRoot = NULL;
    tmp = p->leftMostChild;
    int d = 0;
    while (tmp != NULL)
    {
        int d = diameterTree(tmp);
        if (d > maxChildD)
        {
            maxChildD = d;
            diameterRoot = tmp;
        }
        tmp = tmp->rightSibling;
    }
    if (maxChildD > max1 + max2)
    {
        p->diameterRoot = diameterRoot;
        return maxChildD;
    }
    else
    {
        p->diameterMax1 = tmpMax1;
        p->diameterMax2 = tmpMax2;
        return max1 + max2;
    }
}


int main()
{
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
    printf("%d\n", diameterTree(g_root));
    NODE* tmpDiameterRoot = g_root;
    while (tmpDiameterRoot->diameterRoot != NULL)
    {
        tmpDiameterRoot = tmpDiameterRoot->diameterRoot;
    }
    NODE* tmp1 = tmpDiameterRoot->diameterMax1;
    NODE* tmp2 = tmpDiameterRoot->diameterMax2;
    int maxHeight1 = tmp1->maxHeight;
    int maxHeight2 = tmp2->maxHeight;

    STRING* nodes = (STRING*)calloc(tmp1->maxHeight + tmp2->maxHeight + 1, sizeof(STRING));
    int i = 0;
    while (tmp1 != NULL)
    {
        strcpy(nodes[maxHeight1 - 1 - i], tmp1->value);
        tmp1 = tmp1->maxHeightChild;
        i += 1;
    }
    strcpy(nodes[maxHeight1], tmpDiameterRoot->value);
    i = 0;
    while (tmp2 != NULL)
    {
        strcpy(nodes[maxHeight1 + 1 + i], tmp2->value);
        tmp2 = tmp2->maxHeightChild;
        i += 1;
    }
    visitTree(g_root);
    if (tmpDiameterRoot->diameterMax1->dfsOrder < tmpDiameterRoot->diameterMax2->dfsOrder)
    {
        for (int i = 0;i < maxHeight1 + maxHeight2 + 1;i++)
        {
            printf("%s ", nodes[i]);
        }
    }else
    {
        for (int i = maxHeight1 + maxHeight2;i >= 0;i--)
        {
            printf("%s ", nodes[i]);
        }
    }
    free(nodes);
    nodes = NULL;
    printf("\n");
}