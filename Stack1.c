#include<stdio.h>
#define MAX 10
int stack[MAX];
int top = -1;

void push(){
    int data;
    printf("enter data:");
    scanf("%d",&data);
    if(top == MAX-1 ){
        printf("stack overflow \n");
    }
    else{
        top++;
        stack[top] = data;
    }
}

void pop(){
    
    int data;
    if(top == -1){
        printf("stack underflow\n");
    }
    else{
        data = stack[top];
        top--;
        printf("%d is deleted",data);
    }
}

void peek(){
    if(top == -1){
        printf("stack underflow\n");
    }
    else{
        printf("top of the stack is :%d",stack[top]);
    }
}

void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d | ",stack[i]);
    }
}


int main(){
    
    int n;
    printf("enter no of elements:");
    scanf("%d",&n);
    while(n--){
        push();
    }
    display();
    pop();
    pop();
    peek();
    display();
    
    return 0;
}