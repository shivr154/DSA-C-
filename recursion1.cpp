#include<iostream>
using namespace std;

int factorial(int n){
    // base case
     if(n==1){
        return 1;
     }

     int chotiProblemAns=factorial(n-1);
     int badiProblemAns= n * chotiProblemAns;


    return badiProblemAns;
}

void printCounting(int n){
    //base case
    if(n==0){
        return;
    }
    // processing 
    cout<< n <<" ";

    // recursive relation
    printCounting(n-1);
    cout<<endl;
}

int fib(int n){
    // base case
    if(n==1){
        // first term
        return 0;
    }
    if(n==2){
        // second term
        return 1;
    }
    // RR-> f(n)=f(n-1)+f(n-2)
    int ans=fib(n-1)+fib(n-2);
    return ans;
}

int main(){

    /*int n;
    cout<<"enter the value of n "<<endl;
    cin>>n;

    int ans=factorial(n);
    cout<<"answer is: "<< ans << endl;
*/

   /*  int n;
    cout<<"enter the value of n "<<endl;
    cin>>n;

   
   printCounting(n);*/

   int n;
   cout<<"enter the term you want to see "<<endl;
   cin>>n;

   int ans=fib(n);
   cout<<n<<"th term is : "<< ans;
   cout<<endl;

   


    return 0;
}