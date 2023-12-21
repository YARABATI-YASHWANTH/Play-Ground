#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*top = NULL;

void push(int value){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void display(){
    struct node* temp;
    temp = top;
    if(top==NULL){
        printf("stack underflow");
    }
    else{
        while(temp != NULL){
            printf("%d | ",temp->data);
            temp = temp->next;
        }
    }
}

void peek(){
    if(top == NULL){
        printf("stack underflow");
    }
    else{
        printf("Top of stack is:%d",top->data);
    }
}

void pop(){
    struct node* temp;
    temp = top;
    if(top= NULL){
        printf("stack underflow");
    }
    else{
        printf("%d",top->data);
        top = top->next;
        free(temp);
    }
}





int main(){
    int n;
    printf("enter no of elements:");
    scanf("%d",&n);
    while(n--){
        push(n*10);
    }
    display();
    pop();
    pop();
    peek();
    
    return 0;
}
