#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};


struct Node* CreateNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root,int value){
    if(root == NULL){
        return CreateNode(value);
    }
    
    
    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value > root->data){
        root->right = insert(root->right,value);
    }
    return root;
}


void Inorder(struct Node* node){
    if(node != NULL){
        Inorder(node->left);
        printf(" %d ",node->data);
        Inorder(node->right);
    }
}

void Preorder(struct Node* node){
    if(node != NULL){
        printf(" %d ",node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Postorder(struct Node* node){
    if(node != NULL){
        Postorder(node->left);
        Postorder(node->right);
        printf(" %d ",node->data);
    }
}


int main(){
    
    struct Node* root = NULL;
    root = insert(root,100);
    insert(root,120);
    insert(root,70);
    insert(root,110);
    insert(root,140);
    insert(root,60);
    insert(root,90);
    insert(root,130);
    insert(root,80);
    
    printf("\n Inorder traversal is :\n");
    Inorder(root);
    
    printf("\n Preorder traversal is :\n");
    Preorder(root);
    
    printf("\n Postorder traversal is :\n");
    Postorder(root);
    
    return 0;
}