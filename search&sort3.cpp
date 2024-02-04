#include<iostream>
using namespace std;
#include<vector>


// binary search in nearly sorted array 
int binarySearch(vector<int> arr , int target){
    int s=0;
    int e=arr.size()-1;

    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==target)
         return mid;
        if(mid-1>=0 && arr[mid-1]==target)
         return mid-1;
        if(mid+1<arr.size() && arr[mid+1]==target)
         return mid+1;
 
        if(target<arr[mid]){
            //right search
            s=mid+2;
        }
        else{
            //left search
            e=mid-2;
        }
       mid=s+(e-s)/2;
     }
     return -1;
}

// divide 2 number using binary search

int solve(int dividend,int divisor){
    int s=0;
    int e=abs(dividend);
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        // perfect solution
        if(abs(mid*divisor)==abs(dividend)){
            ans=mid;
            break;
        }
        // not perfect solution
        if(abs(mid*divisor)>abs(dividend)){
            //left search
            e=mid-1;
        }
        else{
            //ans store
            ans=mid;
            //right search
            s=mid+1;
        }
        mid=s+(e-s)/2;
    
    }
    if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
    return ans;
    
    else{
        return -ans;
    }
}

// find the odd occuring element in an array

int solve(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(s==e){
            //single element
            return s;
        }
        // 2 cases-> mid - even or odd
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                s=mid+2;
            }
            else{
                e=mid;
            }
        }
        else{
            if(arr[mid]==arr[mid-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        mid=s+(e-s)/2;
    }
    return -1;

}

int main(){
 /*vector<int> arr{10,3,40,20,50,80,70};
 int target =40;

int ans= binarySearch(arr,target);
cout<<"index of "<< target << " is "<< ans <<endl;
  */

/*  int dividend=-21;
  int divisor=7;
  int ans=solve(dividend,divisor);
  cout<<"ans is "<< ans << endl;
*/

 vector<int> arr{1,1,2,2,3,3,4,4,3,600,600,4,4};
 int ans=solve(arr);
 cout<<"index is "<< ans<<endl;
 cout<<"value is " << arr[ans]<<endl;
 


 return 0;
}
