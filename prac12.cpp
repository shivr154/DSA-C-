#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
      
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib(n-1,dp)+fib(n-2,dp);
    return dp[n];

}

int main(){
     
    // int n;
    // cout<<"enter the value of n "<<endl;
    // cin>>n;

    // vector<int> dp(n+1, -1);
    
    // int ans = fib(n,dp);
    
    // cout<<ans;

    int bt = 4|5 ;
    cout<<bt;

    return 0;
}
