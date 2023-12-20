#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*head=NULL;

void Create(int A[],int n){
    int i;
    struct Node *temp,*tail;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    tail = head;
    for(i=1;i<n;i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next= NULL;
        tail->next = temp;
        tail=temp;
    }
}

void Display(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("null \n");
}

struct Node* InsertAtEnd(struct Node* head,int value){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = value;
    if(head==NULL){
        NewNode->next = NULL;
        head = NewNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        NewNode->next = NULL;
        temp->next = NewNode;
    }
    return head;
    
}

void DeleteAtEnd(struct Node* head){
    if(head==NULL){
        printf("list is empty");
    }
    else{
        struct Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next=NULL;
    }
    
}






int main(){
    
    int A[] = {10,20,30,40,50};
    
    Create(A,5);
    Display(head);
    head = InsertAtEnd(head,60);
    Display(head);
    head = InsertAtEnd(head,70);
    Display(head);
    int i=4;
    for(;i>=0;i--){
        DeleteAtEnd(head);
        Display(head);
    }
    return 0;
}