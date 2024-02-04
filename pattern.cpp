#include<iostream>
using namespace std;

int main(){
    //printing solid rectangle

    //outer loop row observer
   /* for(int row=0;row<3;row++){
        //inner loop col observer
        for(int col=0;col<5;col++){
            cout<<"* ";
        }
        cout<<endl;
    }*/

    //solid square

   /* for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            cout<<"* ";
       }
       cout<<endl;
    }*/

    // hollow rectangle

   /* int rowcount, colcount;
    cin>>rowcount;
    cin>>colcount;

    for(int row=0;row<rowcount;row++){
        if(row==0 || row==rowcount-1){
            for(int col=0;col<colcount;col++){
                cout<<"* ";
            }

        }
        else{
            cout<<"* ";
            for(int i=0; i<colcount-2;i++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }*/

    //half pyramid

   /* int n;
    cin>>n;

    for(int row=0;row<n;row++){
        for(int col=0;col<row+1;col++){
            cout<<"* ";
        }
        cout<<endl;
    }*/

    //inverted half pyramid

    /*int n;
    cin>>n;

    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }*/

    //numeric half pyramid

    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<row+1;col++){
            cout<<col+1;
        }
        cout<<endl;
    }
   
       
}