#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// for finding first occurence 

int firstOccurence(vector<int> arr , int target){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans =-1;

    while(s<=e){
        if(arr[mid]==target){
            // ans store
            ans=mid;
            // left search
            e=mid-1;
        }
        else if(target < arr[mid] ){
            // left me search
            e=mid-1;
        }
        else if(target> arr[mid]){
           // right me search
           s=mid+1;
        }
        mid=s+(e-s)/2;
    }
return ans;
}

// for finding last occurence

int lastocc(vector<int> v,int target){
int s=0;
int e= v.size()-1;
int mid=s+(e-s)/2;
int ans=-1;

while(s<=e){
    if(v[mid]==target){
      // store ans
      ans=mid;
      // right search
      s=mid+1;
    }
    else if (target<v[mid]){
        // left search
        e=mid-1;
    }
    else if (target>v[mid]){
        // right search
         s=mid+1;
    }
    mid=s+(e-s)/2;
}
   return ans;


}




int main(){
   /* vector<int> v{1,2,3,4,5,7};
    int arr[]={1,3,4,5,6,7};
    int size=6;
    //for array binary search
    if(binary_search(arr, arr+size, 30)){
        cout<<"found "<<endl;
    }
    else{
        cout<<" not found " <<endl;
    }
// for vector binary search
   /* if(binary_search(v.begin(), v.end() ,3)){
        cout<<"found "<<endl;
    }
    else{
        cout<<" not found " <<endl;
    }
*/
  /*vector<int> arr{1,3,3,3,3,4,4,4,4,6,7};
  int target = 4;
  int indexOfFirstOcc = firstOccurence(arr,target);

  cout<< "ans is "<< indexOfFirstOcc <<endl;

// lower_bound is the function used to find the first occurence

  auto ans2=lower_bound(arr.begin(),arr.end(),target);
  cout<< " ans2 is "<< ans2-arr.begin()<<endl;
*/
  vector<int> v{1,3,7,7,7,7,7,7,7,7,7,7,7,9};
  int target =7;
  int ans= lastocc(v,target);
  
  cout<<"last occurence is at "<< ans ;

 // u can use upper bound to find the last occurence

 


  



return 0;


}