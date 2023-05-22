#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
node *insert_node(node *root, int data)
{
    if (root == NULL)
    {
        root = create_node(data);
    }
    else if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}
void print_tree(node *root)
{
    if (root != NULL)
    {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}
int main()
{
    node *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    print_tree(root);
    return 0;
}