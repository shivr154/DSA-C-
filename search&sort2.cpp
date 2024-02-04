#include<iostream>
#include<vector>
using namespace std;

// finding pivot element
int findpivot(vector<int> arr){
     int s=0;
     int e=arr.size()-1;
     int mid=s+(e-s)/2;

     while(s<=e){
        if(mid+1<arr.size() && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(mid-1>=0 && arr[mid-1]>arr[mid]){
            return mid-1;
        }
        if(arr[s]>=arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
     }
     return -1;
}


int findSqrt(int n){
    int target =n;
    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    int ans =-1;

    while(s<=e){
        if(mid*mid==target){
            return mid;
        }
        if(mid*mid>target){
            // left search
            e=mid-1;
        }
        else{
            // ans store
            ans=mid;
            // right search
            s=mid+1;
        }
         mid=s+(e-s)/2;
    }
    return ans;
}

bool binarySearch(int arr[][4], int rows, int cols, int target){
  int s=0;
  int e= rows*cols - 1;
  int mid = s+(e-s)/2;

  while(s<=e){
    int rowIndex= mid/cols;
    int colIndex= mid%cols;
    
    if(arr[rowIndex][colIndex] == target){
        cout<<"found at "<< rowIndex <<" "<< colIndex << endl; 
        return true;
    }
    if(arr[rowIndex][colIndex] < target){
        s=mid+1;
    }
    else{
        e=mid-1;
    }
    mid=s+(e-s)/2;

  }
  return false;
}





int main(){
   /* vector<int> arr{3,4,5,6,7,1,2};
    int ans= findpivot(arr);

    cout<<"pivot element is "<< arr[ans] <<endl;

*/
// done 1 ques in leet code Q-> 33 


// finding square root of a no using binary search

/*int n;
cout<<"enter the number"<<endl;
cin>>n;

int ans= findSqrt(n);
cout<<"ans is "<< ans << endl;

int precision;
cout<<"enter the no of floating digit in precision "<< endl;
cin>>precision;

double step=0.1;
double finalans=ans;
for(int i=0;i<precision;i++){

    for(double j=finalans ; j*j<=n; j= j+step){
        finalans=j;
    }
    step=step/10;
}
cout<<"final ans is "<< finalans << endl;*/

// binary search in 2d matrix

int arr[5][4]={ {1,2,3,4} , {5,6,7,8} , {9,10,11,12} , {13,14,15,16} , {17,18,19,20} };
int rows=5;
int cols=4;

int target=99;

bool ans= binarySearch(arr,rows,cols,target);

if(ans){
    cout<<"found "<< endl;
}
else{
    cout<<"not found "<< endl;
}

    return 0;




}