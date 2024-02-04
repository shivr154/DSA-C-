#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


// very imp ques ques 1
int solve(vector<int>& arr, int target){
    // base case
    if(target == 0){  // agar target hi 0 hai to 0 hi coin lagenge use bnane ke liye
        return 0;
    }
    if(target < 0){  // agar target hi negative hai to infinite coin langege ,, invalid hai ye
        return INT_MAX;
    }

    // let's solve 1 case
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){   // loop to iterate on all elements of arr
        int ans= solve(arr, target-arr[i]); // this ans is of 1 element less than target
        if(ans != INT_MAX)
        mini=min(mini,ans+1); // thats why we add 1 in ans here
    }

    return mini;
}

// ques 2
int solve(int n , int x, int y , int z){
    // base case
    if(n==0){    // agar n==0 iska matlab 0 hi segment hai
        return 0;
    }

   if(n < 0){
    return INT_MIN;  // negative wood kese hogi isliye infinte ans invalid hai ye
   }

   int ans1=solve(n-x, x ,y, z) +1; // isme x ko - karke ans aya hai aur +1 se pure rod ka ans aya hai
   int ans2=solve(n-y, x ,y, z) +1; // isme y ko - karke ans aya hai aur +1 se pure rod ka ans aya hai
   int ans3=solve(n-z, x, y ,z) +1; // isme z ko - karke ans aya hai aur +1 se pure rod ka ans aya hai
   
   int ans=max(ans1, max(ans2,ans3)); // isme hum max le rahe hai 3 ka
   return ans;

}

// ques 3
   void solve(vector<int>& arr,int i, int sum , int& maxi){
   // base case
   if(i >= arr.size()){
    // maxi update
    maxi= max(sum,maxi);
    return;
   }
     // include
     solve(arr,i+2,sum+arr[i],maxi);

     // exclude
     solve(arr,i+1,sum,maxi);

   }

int main(){
    /*
    // very imp ques 
   // ques --> minimum no of coins req to make target sum

    vector<int> arr{1,2};
    int target=5;

    int ans=solve(arr, target);
    cout<<"answer is : "<<ans << endl;
*/

/*
   //ques-->  to find the max no of segments of rod only of x y z size

   int n=7;
   int x=5;
   int y=2;
   int z=2;

    // solve function--> this return max no of segments 
    int ans= solve(n,x,y,z);
    // ans--> valid && invalid

    if(ans < 0){  // agar ans -ve hoga to use invalid manege
        ans=0;
        }

    else{
     cout<<"ans is : " << ans << endl;
         }
         */

  // Ques-->3 maximum sum of non adjacent elements

        vector<int> arr{2,1,4,9};
        int sum=0;
        int maxi= INT_MIN;
        int i=0;

        solve(arr,i,sum,maxi);

       cout<< maxi <<endl;

 
    return 0;

}