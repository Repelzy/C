#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL;

void print()
{
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void addfirst(int x)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->next = head;
    head = tmp;
}

void addlast(int x)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        struct Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = tmp;
    }
}

void removeNode(int k)
{
    struct Node *cur = head;
    struct Node *prev = NULL;
    while (cur != NULL && cur->value != k)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur != NULL)
    {
        if (prev == NULL)
        {
            head = cur->next;
        }
        else
        {
            prev->next = cur->next;
        }
        free(cur);
    }
}

void addafter(struct Node *prev, int x)
{
    if (prev == NULL)
    {
        return;
    }
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->next = prev->next;
    prev->next = tmp;
}

void addbefore(struct Node *after, int x)
{
    if (after == NULL)
    {
        return;
    }
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->next = after;
    if (after == head)
    {
        head = tmp;
    }
    else
    {
        struct Node *cur = head;
        while (cur->next != after)
        {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void reverse()
{
    struct Node *cur = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

struct Node *findNode(int value)
{
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int checkExist(int value)
{
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int main()
{
    head = NULL;
    int n, x;
    char s[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!checkExist(x))
        {
            addlast(x);
        }
    }
    while (1)
    {
        scanf("%s", s);
        if (strcmp(s, "addlast") == 0)
        {
            scanf("%d", &x);
            if (!checkExist(x))
            {
                addlast(x);
            }
        }
        else if (strcmp(s, "addfirst") == 0)
        {
            scanf("%d", &x);
            if (!checkExist(x))
            {
                addfirst(x);
            }
        }
        else if (strcmp(s, "addafter") == 0)
        {
            int v;
            scanf("%d%d", &x, &v);
            if (!checkExist(x))
            {
                struct Node *prev = findNode(v);
                if (prev != NULL)
                {
                    addafter(prev, x);
                }
            }
        }
        else if (strcmp(s, "addbefore") == 0)
        {
            int v;
            scanf("%d%d", &x, &v);
            if (!checkExist(x))
            {
                struct Node *after = findNode(v);
                if (after != NULL)
                {
                    addbefore(after, x);
                }
            }
        }
        else if (strcmp(s, "remove") == 0)
        {
            scanf("%d", &x);
            removeNode(x);
        }
        else if (strcmp(s, "reverse") == 0)
        {
            reverse();
        }
        else if (strcmp(s, "#") == 0)
        {
            print();
            return 0;
        }
    }
}
