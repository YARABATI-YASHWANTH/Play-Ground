#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BubbleSort(vector<int> &a){
    int n = a.size();
    bool flag;
    for(int pass = 1;pass < n-1;pass++){ 
        flag = false;               //flag is used to check if array is already sorted
        for(int i=0;i<n-1-pass;i++){ 
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);   // if control enters this block it means that array is not sorted
                flag = true; 
            }
        }
        if(flag==false){      // if flag is false , that means that a[i]<a[i+1] is true for every value of i
            break;            
        }
    }
}


void SelectionSort(vector<int> &a){
    int min;
    for(int i=0;i<a.size() - 1;i++){ 
        min = i; // assume the minimum element is at index i
        for(int j=i+1;j<a.size();j++){
            if(a[j]<a[min]){
                min = j; //found an element smaller thn i , update min to j
            }
        }
        swap(a[min],a[i]); 
    }
}


void InsertionSort(vector<int> &a){

    for(int i=1;i<a.size();i++){
            int j = i-1;   // j keeps track of the sorted array
            int temp = a[i];
            while(j>=0 && a[j]>temp){
                a[j+1] = a[j];
                j--;
            } 
        a[j+1] = temp;
    }
}




void  Merge(vector<int> &a,int low,int mid,int high){
    vector<int> b;
    int i = low;
    int j = mid+1;
    int k = low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;k++; 
        }
        else{
            b[k] = a[j];
            j++;k++;
        }
    }
    while(i<=mid){
        b[k] = a[i];
        i++;k++;
    }
    while(j<=high){
        b[k] = a[j];
        j++;k++;
    }
    for(int x = low;x<high;x++){
        a[x] = b[x];
    }
}

void MergeSort(vector<int> &a,int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}




int Partition(vector<int> &a,int low , int high){
    int pivot = a[low];
    int i = low;
    int j = high;
    while(i<j){
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;
}

void QuickSort(vector<int> &a,int low,int high){
    if(low<high){
        int j = Partition(a,low,high);
        QuickSort(a,low,j-1);
        QuickSort(a,j+1,high);
    }
}
int BinarySearch(vector<int> &a,int key){
    int low = 0;
    int high = a.size() -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid] > key){
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return -1;
}



int main(){

    vector<int> a = {6,7,4,1,9,3,0,2,5,8};
    cout<<"before sorting\n";
    for(int i : a){
        cout<<i<<" ";
    }
    

   // BubbleSort(a);
   // SelectionSort(a);
   // InsertionSort(a);
   // MergeSort(a,0,a.size());
   // QuickSort(a,0,a.size());
   // BinarySearch(a,6);

    
    cout<<"\n after sorting \n";
    for(int i : a){
        cout<<i<<" ";
    }

    
    return 0;
}
