#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int climbStairs(int n){
    //base case
    if(n==0 || n==1)
    return 1;

    int ans=climbStairs(n-1)+climbStairs(n-2);
    return ans;
}

void print(int arr[],int n,int i){
    //base case
    if(i>=n)
    return;
// 1 case solve kardia
    cout<<arr[i]<<" ";
    // baki recursion sambhal lega
    print(arr,n,i+1); 
}

 void findMax(int arr[],int n,int i, int& maxi){
    // used int& maxi for pass by refrence  
    //base case
    if(i>=n)
    return;

    //1 case solve
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    //baki recursion sambhal lega
    findMax(arr,n,i+1,maxi);
 }

 void findMin(int arr[],int n,int i, int& mini ){
// base case
  if(i>=n)
  return;
//1 case solve
  mini=min(mini,arr[i]);
//baki recurisn sambhal lega
 findMin(arr,n,i+1,mini);
  
 }

 int checkKey(string& str,int& n,int i,char& key,vector<int>& ans){
    // base case
    if(i>=n){
        // key not found
        return -1;
    }
    //1 case solve
    if(str[i]==key){
        //store in vector
        ans.push_back(i);
    }
    // baki recursion karlega
    return checkKey(str,n,i+1,key,ans);
    
 }

 void printDigits(int n){
    // base case
    if(n==0)
    return;
   
    int newValueofN=n/10;

    //bakki recursion karlega
    printDigits(newValueofN);
    
    // 1 case sol

    int digit=n%10;
    cout<<digit<<" ";
 }

int main(){

 /*int n;
 cout<<"enter the value of n "<<endl;
 cin>>n;

 int ans=climbStairs(n);
 cout<<"answer is : "<< ans ;
*/
   
   /*int arr[5]={10,20,30,40,50};
   int n=5;
   int i=0;
   print(arr,n,i);
*/

  /* int arr[]={10,30,21,44,32,5,19,66};
   int n=8;

   int maxi=INT_MIN;
   int mini=INT_MAX;
   int i=0;

   findMax(arr,n,i,maxi );
   findMin(arr,n,i,mini);
   cout<<"maximum no is : "<< maxi<<endl;
   cout<<"minimum no is : "<< mini<<endl;*/

   string str="loverbabbar";
   int n=str.length();
   int i=0;
   char key='r';
   vector<int> ans;

   checkKey(str,n,i,key,ans);
   
   cout<<"printing ans "<<endl;

   for(auto val:ans){
    cout<< val <<" ";
   }
   cout<<endl;


/*
   int n=647;
   
   printDigits( n);
*/








    return 0;
}