#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void display(){
    struct node* temp;
    if(front == NULL && rear == NULL){
        printf("queue is empty");
    }
    else{
        temp = front;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}


void dequeue(){
    struct node* temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("queue is empty");
    }
    else{
        printf("\n%d is deleted \n",front->data);
        front = front->next;
        free(temp);
    }
}



int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    display();
    return 0;
}