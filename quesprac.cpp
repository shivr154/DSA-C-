#include<iostream>
#include<vector>
using namespace std;

bool CheckPrime(int n){
    int i=2;
    for(int i=2;i<n;i++){
      if(n%i==0){
           return false;
      }
    }
    return true;
}

  void moveallnegtoleft(int*a,int n){
    // Dutch National Flag Algo
    int l=0;
    int h=n-1;

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

void findMissing(int*a, int n){
  // visited method
  for(int i=0;i<n;i++){
    int index = abs(a[i]);
    if(a[index - 1]>0){
         a[index - 1] *= -1;
    }
  }

   for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
   }
   cout<<endl;

   // all postive indexes are missing
   for(int i=0;i<n;i++){
    if(a[i]>0){
      cout<<i+1<<" ";
    }
   }
}

  void wavePrintMatrix(vector<vector<int>> v){
    int m=v.size();
    int n=v[0].size();
    for(int startCol=0;startCol<n;startCol++){
      //even no of col Top to bottom
      if((startCol & 1)==0){
        for(int i=0;i<m;i++){
          cout<<v[i][startCol]<<" "; 
        }
      }
      else{
        //odd no of col bottom to 
        for(int i=m-1;i>=0;i--){
          cout<<v[i][startCol]<<" ";
        }
      }

    }
  }
  


int main(){
 /*  int n;
   cin >> n;
   for(int i=1;i<=n;i++){
   bool isiprime= CheckPrime(i);
   if(isiprime){
    cout<<i<<" ";
   }   
   }
*/
   /*int a[]={1,2,-3,4-5,6};
   int n=sizeof(a)/sizeof(int);

   moveallnegtoleft(a,n);

   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;
*/

// missing element with duplicate
 /* int n;
  int a[]={1,3,3,4,5};
  n=sizeof(a)/sizeof(int);
  findMissing(a,n);
*/

vector<vector<int>> v { 
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12},
  {13,14,15,16},
  {17,18,19,20}
};

wavePrintMatrix(v);



return 0;
}