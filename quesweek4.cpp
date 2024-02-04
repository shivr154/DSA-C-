#include<iostream>
#include<vector>
#include<algorithm> // used for max element stl function
using namespace std;

int findPivot(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(s==e){
            // single element
            return s;
        }
        if(mid <= e && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid-1 >= s && arr[mid-1] > arr[mid]){
            return mid-1;
        }
        if(arr[s] > arr[mid]){
            e=mid-1;
        }

        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

  int bs(int a[], int start, int end, int x){
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==x){
            return mid;
        }
        else if(x>a[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    return -1;
  }


 int expSearch(int a[], int n, int x){
    if(a[0]==x){
        return 0;
    }
    int i=1;
    while(i<n && a[i]<=x ){
        i=i*2; // i*=2 // i=i << 1;

    }
    return bs(a, i/2 ,min(i,n-1), x);
 }

 bool isPossibleSol(vector<long long int> trees, long long int m, long long int mid){ // eko spoj
         long long int woodCollected=0;
         for(long long int i=0;i<trees.size();i++){
            if(trees[i] > mid){
              woodCollected += trees[i] - mid; 
            }
         }
         return woodCollected >= m;
 }

 long long int maxBladeHeight(vector<long long int> trees, long long int m){ // eko spoj
    long long int start=0, end;
    long long int ans= -1;
     end= *max_element(trees.begin(), trees.end());
      while(start<=end){
        long long int mid= start+(end-start)/2;
        if(isPossibleSol(trees, m , mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
      }
      return ans;


 }

  // PRATA SPOJ problem

  bool isPossibelSol(vector<int>cooksRanks, int nP, int mid){
    int currP=0; // initial cook prata count
    for(int i=0;i<cooksRanks.size();i++){
          int R=cooksRanks[i], j=1;
          int timeTaken=0;

          while(true){
            if(timeTaken + j * R <= mid){
                ++currP;
                timeTaken += j*R;
                ++j;
            }
            else{
                break;
            }
          }
          if(currP >= nP){
            return true;
          }
    }
     return false;

  }


 // PRATA SPOJ Problem

 int minTimeToCompleteOrder(vector<int>cooksRanks, int nP){
         int start=0;
         int highestRank=*max_element(cooksRanks.begin(), cooksRanks.end());
         int end= highestRank * ( nP* (nP+1) / 2 ); // first n natural no wla formula hai
         int ans=-1;

         while(start<=end){
            int mid= start+(end-start)/2;
            if(isPossibelSol(cooksRanks, nP,mid)){
                ans=mid;
                end=mid-1;
            
            }
            else{
                start=mid+1;
            }

         }
         return ans;
 }


int main(){

/*vector<int> arr{2,4,6,8,9,10};
int ans=findPivot(arr);
if(ans==-1){
    cout<<"kuch gadbad hai"<<endl;
}
else{
    cout<<"ans is at index "<<ans << endl;
    cout<<"value of ans is "<< arr[ans]<<endl;
}*/

/* int a[]={3,4,5,6,11,13,14,15,56,70};
  int n=sizeof(a) / sizeof(int);
  int x=13;
  int ans=expSearch(a , n, x);
  cout<<ans<<endl;
*/


  // EKO SPOJ problem

 /*  long long int m,n;
   cout<<"enter the value of n  enter the value of m "<<endl;
   cin >> n >> m; 
   vector<long long int> trees;

   while(n--){
        long long int height;
        cout<<"enter the height "<<endl;
        cin>>height;
        trees.push_back(height);
   }

   cout << maxBladeHeight(trees, m)<<endl;  */

//   PRATA SPOJ problem

  int T; cin>>T;  // T-> test case
  while(T--){
    int nP ,nC;  // nP-> no of prata , nC-> no of cooks
    cin>> nP >> nC ;

    vector<int> cooksRanks;

    while(nC--){
        int R;cin>>R;  // R-> Rank
        cooksRanks.push_back(R);
    }

    cout<<minTimeToCompleteOrder(cooksRanks, nP)<<endl;
  }


    return 0;
}