#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;  // previous
    struct Node *right; //next
};

struct Node *Create(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int is_bst(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!is_bst(root->left))
        {
            return 0;
        }

        // checking for ascending order
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return (is_bst(root->right));
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct Node *root = Create(5);
    struct Node *n1 = Create(3);
    struct Node *n2 = Create(6);
    struct Node *n3 = Create(1);
    struct Node *n4 = Create(4);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    printf("%d ", is_bst(root));
    return 0;
}