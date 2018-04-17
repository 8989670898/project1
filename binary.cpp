#include<stdio.h>
#include<stdlib.h>
#include<queue>  
struct node
{
    int key;
    struct node *left, *right;
};
  
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    //prajjwal will add here
}
//changes made by Nishkarsh Raj Khare
void insert(struct Node* temp, int key)
{
    queue<struct Node*> q;
    q.push(temp);
 
    // Do level order traversal until we find
    // an empty place. 
    while (!q.empty()) {
        struct Node* temp = q.front();
        q.pop();
 
        if (!temp->left) {
            temp->left = newNode(key);
            break;
        } else
            q.push(temp->left);
 
        if (!temp->right) {
            temp->right = newNode(key);
            break;
        } else
            q.push(temp->right);
    }
}  



struct node* deleteNode(struct node* root, int key)
{
    
    if (root == NULL) return root;
 
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
   
    else
    {
        
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 

        struct node* temp = minValueNode(root->right);
 

        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}

int main()
{

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    
    inorder(root);
  
    return 0;
}

