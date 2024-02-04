#include<iostream>
using namespace std;


void merge(int* arr, int s, int e){
    int mid=s+(e-s)/2;

    int len1= mid-s+1;// length of left array
    int len2= e-mid; // length of right array

    int* left= new int[len1]; // creating a array dynamically
    int* right= new int[len2];

    // copy values
    int k=s;
    for(int i=0;i<len1;i++){
        left[i]= arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        right[i]= arr[k];
        k++;
    }

    // merge logic
    int leftIndex=0;
    int rightIndex=0;
    int mainArrayIndex= s;

    while(leftIndex < len1 && rightIndex < len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex]= right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // copy logic for left array
    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // copy logic for right array
    while(rightIndex < len2){
        arr[mainArrayIndex++] = right[rightIndex++]; 
    }   

    // TODO: delete left and right wala newly created array to save space

    

}

void mergeSort(int* arr, int s, int e){
    // base case
    // s==e -> single element
    // s>e -> invalid array
    if(s>=e)
    return;

     int mid=s+(e-s)/2;
    // left part sort kardo recursion
    mergeSort(arr,s,mid);

    // right part sort kardo recursion
    mergeSort(arr,mid+1,e);

    // now merge 2 sorted arrays
    merge(arr,s,e);

}

int main(){
    int arr[]={4,5,13,2,12};
    int n=5;
    int s=0;
    int e=n-1;

    mergeSort(arr,s,e);

  // printing the sorted array
  
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<< endl;


    return 0;
}