// RECURSION QUESTIONS
#include<iostream>
#include<vector>
using namespace std;

 void lastOccLTR( string&s, char x,int i, int&ans){
    // base case
     if(i>=s.size()){
        return;
     }

    // ek case soln
    if(s[i]==x){
        ans=i;
    }
    // recursive call
    lastOccLTR(s,x,i+1,ans);
 }

  void lastOccRTL( string&s, char x,int i, int&ans){
    // base case
     if(i<0){
        return;
     }

    // ek case soln
    if(s[i]==x){
        ans=i;
        return;
    }
    // recursive call
    lastOccLTR(s,x,i-1,ans);
 }

 void swapstring(string&s, int i, int j){
    // base case
    if(i>=j){
        return;
    }
    // ek case solve
    swap(s[i],s[j]);
        
    // baki recursion kar lega
    swapstring(s,i+1,j-1);
 }

 bool isPalindrome(string&s, int start, int end){
    // base case
     if(start>=end){
        return true; 
     }

    // ek case solve
    if(s[start] != s[end]){
        return false; 
    }
    //RE
    return isPalindrome(s, start+1, end-1);
 }

 void printSubarray_util(vector<int>&nums, int start, int end){
   // base
     if(end==nums.size()){
      return;
     }
   // 1 case
   for(int i=start;i<=end;i++){
      cout<<nums[i]<<" ";
   }
   cout<<endl;

   // RE
   printSubarray_util(nums,start,end+1);
 }

 void printSubarray(vector<int>&nums){
   for(int start=0;start<nums.size();start++){
      int end=start;
      printSubarray_util(nums,start,end);
   }
 }

int main(){
// Q->1 last occ of a char
 /*   string s;
    cin>>s;
    char x;
    cin>>x;

    int ans=-1;

    lastOccLTR(s,x,0,ans);
    cout<<ans<<endl;

    lastOccRTL(s,x,s.size()-1,ans);
    cout<<ans<<endl;
*/
// Q->2 reverse a string
/*

   string s;
   cin>>s;

   int start=0;
   int end=s.size()-1;

   swapstring(s,start,end);
   cout<<s;
*/
// Q-> 3 add strings Leetcode -> 415

//Q->4  palindrome check

   /*string s;
   cin>>s;
   cout<<isPalindrome(s,0,s.size()-1)<<endl;
*/

 // Q->5 remove all occ of a sub array  Leetcode --> 1910
     
  // Q->6 print all sub array using RE
  /*
     vector<int>nums{1,2,3,4,5};
     printSubarray(nums);
*/
  // Q--> 7 buy & sell stocks Leetcode--> 121

  // Q--> 8 House Robber problem Leetcode--> 198

  // Q--> 9 Integer to english word Leetcode--> 273
  
  // Q--> 10 WildCard Matching Leetcode --> 44

  // Q--> 11 Perfect Squares Leetcode--> 279
  
   
   
    return 0;

}