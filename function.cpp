#include<iostream>
using namespace std;

//void printNumber(int num){
    //cout<<num<<endl;
//}
/*int getsum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    return sum;
}*/
int getEvenSum(int n){
     int sum=0;
     for(int i=2;i<=n;i=i+2){
        sum=sum+i;

     }
     return sum;
}


int main(){
       /* int n;
        cout<<"enter the value of n"<<endl;
        cin>>n;

        int ans=getsum(n);

        cout<<"sum upto "<< n << " is " << ans <<endl;

    return 0;*/
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;

    int ans = getEvenSum(n);
    cout<<"even sum upto "<< n << " is "<< ans <<endl;
    return 0;
}