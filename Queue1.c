#include<stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;


void enqueue(int value){
    if(rear == MAX -1){
        printf("overflow");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("underflow");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        printf("%d is enqueued\n",queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("underflow");
    }
    else{
        int i;
        for(i=front;i<= rear;i++){
            printf("%d ",queue[i]);
            }
        printf("\n");
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