#include<stdio.h>
#include<stdlib.h>

struct node {
    int content;
    struct node *left;
    struct node *right;
};

struct node *newnode(int c) {
    struct node *temp = malloc(sizeof(struct node));
    temp->content = c;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int c) {
    if (root == NULL) return newnode(c);
    if (c < root->content)
        root->left = insert(root->left, c);
    else
        root->right = insert(root->right, c);
    return root;
}

void printinorder(struct node *root) {
    if (root == NULL) return;
    printinorder(root->left);
    printf("%d ", root->content);
    printinorder(root->right);
}

int countnodes(struct node *root) {
    if (root == NULL) return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}

int sumnodes(struct node *root) {
    if (root == NULL) return 0;
    return root->content + sumnodes(root->left) + sumnodes(root->right);
}

struct node *findminimum(struct node *root) {
    if (root == NULL) return NULL;
    struct node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node *deletetree(struct node *root) {
    if (root == NULL) return NULL;
    deletetree(root->left);
    deletetree(root->right);
    printf("Deleting node with value: %d\n", root->content);
    free(root);
    return NULL;
}

int main() {
    struct node *root = NULL;

    // Insert nodes into the tree with values: 5, 15, 3, 10
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 10);

    // Print nodes of the tree in inorder
    printf("In Order Display\n");
    printinorder(root);
    printf("\n");

    // Count number of nodes
    printf("The number of nodes in the tree:\n");
    printf("%d\n", countnodes(root));

    // Sum values of nodes
    printf("Sum of the contents in the tree:\n");
    printf("%d\n", sumnodes(root));

    // Print minimum value in the tree
    printf("Minimum value in a node:\n");
    struct node *min_node = findminimum(root);
    if (min_node != NULL) {
        printf("%d\n", min_node->content);
    }

    // Deleting all nodes of the tree
    printf("Deleting all nodes of tree\n");
    root = deletetree(root);

    return 0;
}
