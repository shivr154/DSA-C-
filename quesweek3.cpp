#include<iostream>
#include<vector>
using namespace std;

void moveAllNegToLeft(int*a,int n){
    // two pointer approach, dutch national flag
    int l=0,h=n-1;
    while(l<h){
        if(a[l]<0){
            l++;
        }
        else if(a[h]>0){
            h--;
        }
         else{
            swap(a[l],a[h]);
         }
    }

}

void findMissing(int*a,int n){
  //METHOD 1 --> visited method (-ve marking )
  /*
  for(int i=0;i<n;i++){
    int index= abs(a[i]);
    if(a[index-1]>0){
        a[index-1]*=-1; 
    }
  }

  // printing the array
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;

  // all positive indexes are missing 
  for(int i=0;i<n;i++){
    if(a[i]>0)
    cout<<i+1<<" ";
  }
  */

  // METHOD 2 --> sorting swapping method

  int i=0;
  while(i<n){
    int index=a[i]-1;
    if(a[i] != a[index]){
      swap(a[i],a[index]);
    }
    else{
      ++i;
    }
  }
  // printing array
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";

  }
  cout<<endl;
// which are not equal are missing in the array
  for(int i=0;i<n;i++){
    if(a[i] != i+1){
      cout<<i+1<<" ";
    }
  }
  cout<<endl;
}

void wavePrintMatrix(vector<vector<int>>v){
  int m=v.size(); // row size
  int n=v[0].size();// col size

  for(int startCol=0;startCol<n;startCol++){
    // even no of col-> top to bottom
    if((startCol & 1)==0){
      for(int i=0;i<m;i++){
        cout<<v[i][startCol]<<" ";
      }
    }
    else{
      // odd no of col -> bottom to top
      for(int i=m-1; i>=0; i--){
           cout<<v[i][startCol]<<" ";
      }

    }

}

}

int main(){
   /* int a[]={1,2,-3,4,-5,6};
    int n=sizeof(a)/sizeof(int);

   moveAllNegToLeft(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;*/ 

 /*  int n;
   int a[]={1,3,3,3,3};
   n=sizeof(a)/sizeof(int);

   findMissing(a,n);
*/
vector<vector<int>>v {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12}
 
};

  wavePrintMatrix(v);




   return 0;



}