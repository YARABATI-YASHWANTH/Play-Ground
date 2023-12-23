#include<stdio.h>

int Factorial(int n){
    if(n<1){
       return 1; 
    }
    else{
        return n*Factorial(n-1);
    }
}

int Power(int base , int power){
    if(power == 0){
        return 1;
    }
    else{
        return base*Power(base,power-1);
    }
}

void Print(int n){
    if(n>0){
        // Print(n-1);
        printf(" | %d | \n",n);
        Print(n-1);
    }
}


int Fibonacci(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}

int DigitSum(int digit){
    if(digit==0){
        return 0;
    }
    else{
        return (digit%10) +DigitSum(digit/10);
    }
}


int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}


int main(){
    // Print(10);
    // printf("%d ",Factorial(5);
    // printf("%d ",Power(10,3));
    // int i;
    // for(int i=0;i<20;i++){
    //     printf("%d ",Fibonacci(i));
    // }
    // printf("%d ",DigitSum(1234));
    printf("%d ",gcd(20,24));
    return 0;
}