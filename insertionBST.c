#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *makeNode(int x)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = x;
    tmp->right = tmp->left = NULL;
}

Node *insert(Node *p, int v)
{
    if (p == NULL)
    {
        return makeNode(v);
    }
    if (v < p->data)
    {
        p->left = insert(p->left, v);
    }
    if (v > p->data)
    {
        p->right = insert(p->right, v);
    }
    return p;
}

void printInOrder(Node *node)
{
    if (node == NULL)
        return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

Node *find(struct Node *root, int key)
{

    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return find(root->right, key);

    return find(root->left, key);
}

struct Node *deleteNode(struct Node *root, int k)
{

    if (root == NULL)
        return root;
    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }

    if (root->left == NULL)
    {
        struct Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct Node *temp = root->left;
        free(root);
        return temp;
    }

    else
    {

        struct Node *succParent = root;

        struct Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;

        free(succ);
        return root;
    }
}

void printTree(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    space += 3;
    printTree(root->left, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printTree(root->right, space);
    
}

int main()
{
    Node *root = NULL;
    root = insert(root, 3);
    insert(root, 4);
    insert(root, 8);
    insert(root, 20);
    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 2);

    printf("Inorder traversal of the given tree \n");
    printInOrder(root);
    printf("\n\nTree structure after insertion:\n");
    printTree(root, 0);
    return 0;
}
