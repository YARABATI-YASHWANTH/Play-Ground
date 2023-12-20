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
struct Node* InsertAtPos(struct Node* head , int value , int pos){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = value;
    if(head==NULL){
        NewNode->next = NULL;
        head = NewNode;
    }
    else{
        int i;
        struct Node* temp = head;
        for(i=1;i<pos-1;i++){
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
    return head;
}

void DeleteAtPos(struct Node* head,int pos){
    if(head==NULL){
        printf("list is empty");
    }
    struct Node* temp = head;
    int i;
    for(i=1;i<pos-1;i++){
        temp = temp->next;
    }
    struct Node* delete = temp->next;
    temp->next = delete->next;
    free(delete);
}

int Length(struct Node* head){
    struct Node* temp = head;
    int count = 0;
    if(head==NULL){
        return 0;
    }
    else{
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
}


int main(){
    
    int A[] = {10,20,40,50,60};
    
    Create(A,5);
    Display(head);
    int length = Length(head);
    head = InsertAtPos(head,30,3);
    Display(head);
    head = InsertAtPos(head,70,7);
    Display(head);
    int i = 1;
    while(i<=length){
        if(i%2==0){
            DeleteAtPos(head,i);
            Display(head);
        }
        i++;
    }
    return 0;
}