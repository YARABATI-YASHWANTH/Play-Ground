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

// void Display(struct Node *ptr){
//     while(ptr!=NULL){
//         printf("%d -> ",ptr->data);
//         ptr = ptr->next;
//     }
//     printf("null");
// }
void Display(struct Node *ptr){
    if(ptr!=NULL){
        printf("%d -> ",ptr->data);
        Display(ptr->next);
    }
    else
        printf("null\n");
}

struct Node* InsertAtBeg(struct Node *head, int value){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = value;
    if(head==NULL){
        NewNode->next = NULL;
        head = NewNode;
    }
    else{
        NewNode->next = head;
        head = NewNode;
    }
    return head;
}


struct Node* DeleteAtBeg(struct Node *head){
    
    if(head==NULL){
        printf("list is empty");
    }
    else{
        int deleted = head->data;
        head = head->next;
        printf("%d is deleted\n",deleted);
    }
    return head;
}


int main(){
    
    // struct Node head;
    // head.data = 10;
    // head.next = NULL;
    // struct Node *head =(struct Node*)malloc(sizeof(struct Node));
    // head->data = 10;
    // head->next = NULL;
    
    int A[] = {10,20,30,40,50};
    
    Create(A,5);
    Display(head);
    head = InsertAtBeg(head,5);
    Display(head);
    head = DeleteAtBeg(head);
    Display(head);
    head = DeleteAtBeg(head);
    Display(head);
    return 0;
}