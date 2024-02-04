#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
 /*vector<int> arr{5,4,3,2,1};
 int n=arr.size();

 //selection sort
 // outer lopp-> (n-1)rounds

 for(int i=0;i<n-1;i++){
     
     int minIndex=i;
     // inner loop -> index of minimum element in range i->n
     for(int j=i+1;j<n;j++){
         if(arr[j]<arr[minIndex]){
             //new minimum then store
             minIndex=j;
         }
     }
     //swap
     swap(arr[i],arr[minIndex]);
 }

 //printing
 for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
 }
 cout<<endl;*/

  // Bubble sort
   
  /* vector<int> arr{10,1,7,6,14,9};
   int n=arr.size();

   // buuble sort
   for(int round=1;round<n;round++){
    bool swapped=false;
    for(int j=0;j<n-round;j++){
        if(arr[j]>arr[j+1]){
            swapped=true;
            swap(arr[j],arr[j+1]);
        }
    }
    if(swapped == false){
        // sort ho chuka hai no need to further check
        break;
    }
   }

   // printing
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;*/

   // insertion sort

  /*   vector<int> arr{10,1,7,6,14,9};
  int n = arr.size();

  //insertion sort
  for(int round = 1; round < n; round++) {
      //Step A - fetch
      int val = arr[round];
      //StepB: Compare
      int j=round-1;
      for(; j>=0; j--) {
          if(arr[j] > val) {
              // Step C: shift
              arr[j+1] = arr[j];
          }
          else {
              //rukna hai
              break;
          }

      }
      //stepD: Copy
      arr[j+1] = val;
  }

  //printinhg
  for(int i=0; i<n; i++) {
      cout << arr[i] << " ";
  }
  cout << endl;
*/

// pre defined function for sorting

vector<int> v{10,1,7,6,14,9,15};

sort(v.begin(), v.end());

//printing
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}
cout<<endl;



  return 0;
}