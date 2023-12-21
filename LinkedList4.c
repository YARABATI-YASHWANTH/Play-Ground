#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head=NULL;

void Create(int A[],int n){
    int i;
    struct Node* temp ,*tail;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    tail = head;
    for(i=1;i<n;i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void Display(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* Reverse(struct Node* head){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


int main(){
    int A[] = {1,2,3,4,5,6,7};
    Create(A,7);
    Display(head);
    head = Reverse(head);
    Display(head);
    
    return 0;
}