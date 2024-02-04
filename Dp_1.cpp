#include<iostream>
#include<vector>
using namespace std;

// Ques-->1 Fibonacci series
int f(int n, vector<int> &dp){
    if(n<=1) return n;
    
    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}
// Ques-->2 print all SubSequences 
void printF(int ind, vector<int> &ds, int arr[], int n){
  if(ind == n){
    for(auto it: ds){
      cout<< it <<" ";
    }
    if(ds.size()==0){
      cout<<"{}";
    }
    cout<<endl;
    return;
  }
  // take or pick the particular index into the subsequence
  ds.push_back(arr[ind]);
  printF(ind+1,ds,arr,n);
  ds.pop_back();

// not pick, not take index into subsequence
printF(ind+1,ds,arr,n);

}
// Ques-->3 print subsequence whose sum is k
// void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
//   if(ind == n){
//     if(s == sum){
//       for(auto it:ds) cout<<it<<" ";
//       cout<<endl;
//     }
//     return;
//   }
//   // pick
//    ds.push_back(arr[ind]);
//    s += arr[ind];
   
//    printS(ind+1,ds,s,sum,arr,n);

//    s-=arr[ind];
//    ds.pop_back();
//   // not pick
//    printS(ind+1, ds,s,sum,arr,n);
// }

//Ques-> print only one subsequence whose sum is k
bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
  if(ind == n){
    if(s == sum){
      for(auto it:ds) cout<<it<<" ";
      cout<<endl;
      return true;  
    }
   else return false;
  }
  // pick
   ds.push_back(arr[ind]);
   s += arr[ind];
   
  if(printS(ind+1,ds,s,sum,arr,n) == true){
    return true;
  }

   s-=arr[ind];
   ds.pop_back();
  // not pick
  if(printS(ind+1, ds,s,sum,arr,n) == true){
    return true;
  }
  return false;
}

int main(){
  // Ques-->1 Dp fibonacci series 
// Method 1->TC->O(N), SC->O(N)
//    int n;
//    cin>>n;
// //    vector<int> dp(n+1,-1);
// //    cout<< f(n,dp);
   
   // Method 2->space optimized SC->O(1)(dnt need array to store)
//   int prev2 = 0;
//   int prev = 1;
//   for(int i=2; i<=n; i++){
//     int curi = prev + prev2;
//     prev2 = prev;
//     prev = curi;
//   }
//   cout<< prev;

  // Ques-->2 print all subsequence of an array by recursion
  // int arr[] = {3,1,2};
  // int n =3;
  // vector<int> ds;
  // printF(0,ds,arr,n);

  // Ques-->3 print subsequence whose sum is k
  int arr[] = {1,2,1};
  int n=3;
  int sum =2;
  vector<int> ds;
  printS(0,ds,0,sum,arr,n);
 
}
