#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\n elements are\n");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

void Append(struct Array *arr,int val){
    if(arr->length < arr->size){
        arr->A[arr->length++] = val;
    }
    
}

void Insert(struct Array *arr,int index,int val){
    int i;
    if(index>=0 && index<= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=val;
        arr->length++;
    }
}

int Delete(struct Array *arr ,int index){
    int x=0;
    int i;
    
    if(index>=0 && index<arr->length){
        x = arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
        
    }
    return 0;
    
}



int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        int current = arr.A[i];
        if(current > max){
            max = current;
        }
        
    }
    return max;
}


int Min(struct Array arr){
    int min= arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        int current = arr.A[i];
        if(current < min){
            min = current;
        }
        
    }
    return min;
}

int Sum(struct Array arr,int index){
    int sum =0;
    if(index<0){
        return 0;
    }
    else{
        return arr.A[index] + Sum(arr,index-1);
    }
}


int main(){
    struct Array arr;
    int n,i,val;
    printf("enter size of the array:");
    scanf("%d",&arr.size);
    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length =0;

    printf("enter no of elements:");
    scanf("%d",&n);

    printf("enter %d elements",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length =n;
    
    Display(arr);
    
    // printf("enter an element to append:");
    // scanf("%d",&val);
    
    // Append(&arr,val);
    
    // Insert(&arr,5,60);
    // int deleted = Delete(&arr,3);
    // printf("deleted element is :%d",deleted);
    // Display(arr);
    // printf("min:%d",Min(arr));
    // printf("max:%d",Max(arr));
    // printf("sum:%d",Sum(arr,arr.length));

    return 0;
}
