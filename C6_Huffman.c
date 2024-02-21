#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node
{
    int data;
    int freq;
    struct Node *left, *right;
} Node;

Node *nodes[100001] = {0};
int arr[100001] = {0};
int total = 0;
int n = 0;
int freq[256] = {0};

void swap(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void pushDown(int i)
{
    int min = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    if (L < n && nodes[L]->freq < nodes[min]->freq)
    {
        min = L;
    }
    if (R < n && nodes[R]->freq < nodes[min]->freq)
    {
        min = R;
    }
    if (min != i)
    {
        swap(&nodes[i], &nodes[min]);
        pushDown(min);
    }
}

void pushUp(int i)
{
    int parent = (i - 1) / 2;
    while (i > 0 && nodes[parent]->freq > nodes[i]->freq)
    {
        swap(&nodes[parent], &nodes[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void enqueue(Node *x)
{
    if (n == 100001)
    {
        return;
    }
    nodes[n] = x;
    int i = n;
    pushUp(n);
    n++;
}

Node *dequeue()
{
    if (n == 0)
    {
        return NULL;
    }
    Node *min = nodes[0];
    nodes[0] = nodes[n - 1];
    n--;
    pushDown(0);
    return min;
}

void calcBits(Node *root, int arr[], int cnt)
{
    if (root->left == NULL && root->right == NULL)
    {
        total += cnt * freq[root->data];
    }
    else
    {
        if (root->left != NULL)
        {
            arr[cnt] = 0;
            calcBits(root->left, arr, cnt + 1);
        }
        if (root->right != NULL)
        {
            arr[cnt] = 1;
            calcBits(root->right, arr, cnt + 1);
        }
    }
}

int main()
{
    char cmd[1024] = {0};
    fgets(cmd, sizeof(cmd), stdin);
    for (int i = 0; i < strlen(cmd)-1; i++)
    {
        freq[cmd[i]] += 1;
    }
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->data = i;
            new_node->freq = freq[i];
            new_node->left = new_node->right = NULL;
            enqueue(new_node);
        }
    }
    while (n > 1)
    {
        Node *tmp1 = dequeue();
        Node *tmp2 = dequeue();
        Node *newNode = (Node *)calloc(1, sizeof(Node));
        newNode->data = 0;
        if (tmp1->freq < tmp2->freq)
        {
            newNode->left = tmp1;
            newNode->right = tmp2;
        }
        else
        {
            newNode->left = tmp2;
            newNode->right = tmp1;
        }
        newNode->freq = tmp1->freq + tmp2->freq;
        enqueue(newNode);
    }

    Node *root = dequeue();
    calcBits(root, arr, 0);
    printf("%d\n", total);
}
