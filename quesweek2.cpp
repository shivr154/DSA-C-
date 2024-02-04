#include<iostream>
using namespace std;


float circle_area(float radius){
  float area=3.14 * radius * radius;
  return area;
}

bool checkEven(int n){
    if(/*n%2==0*/ (n&1) == 0){
        return true;
    }
    else{
        return false;
    }
}

int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

bool checkPrime(int n){
    int i=2;
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
        else{
            return true;
        }
    }
}

int main(){

   /*float radius;
    cin>>radius;

    float area=circle_area(radius);
    cout<<"area of the circle is : "<<area<<endl;
*/
    
  /*  int n;
    cin>>n;
    bool isEven=checkEven(n);

     if(isEven){
        cout<<n <<" is even no";

     }
     else{
        cout<<n <<" is odd no";
     }
*/
  /*    int n;
      cin>>n;
      int ans=fact(n);
      cout<<"factorial of n : "<< ans;
*/

  /*int n;
  cin>>n;
  bool isPrime=checkPrime(n);
  if(isPrime){
    cout<<"prime";
  }
  else{
    cout<<"not a prime";
  }*/

  int n;
  cin>>n;

  for(int i=1;i<=n;i++){
    bool isiPrime=checkPrime(i);
    if(isiPrime){
        cout<<i<<" ";
    }
  }
  

}