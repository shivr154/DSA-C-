#include<Iostream>
using namespace std;


int main(){
    /*int n=528;

    while(n!=0){
        int rem=n%10;
        cout<<rem<<" ";
        n=n/10;
    }
    cout<<endl;
    
    return 0;*/


    int n=15;
    int ans=0;

    while(n!=0){
        if(n&1){
            ans++;
        }
        n=n>>1;
    }
    
    cout<<"no of set bits "<< ans << endl;
}