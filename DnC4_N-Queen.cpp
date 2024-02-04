#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,bool> rowcheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;

void printSolution(vector<vector<char>> &board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< board[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n){
   
    if(rowcheck[row]==true){
        return false;
    }
    if(upperLeftDiagonalCheck[n-1+row-col]==true){
        return false;
    }
    if(bottomLeftDiagonalCheck[row+col]==true){
        return false;
    }

    return true;




  /*  // check karna hai h ,k kya mai current cell par queen rakh sakta hoo ya nhi
    int i=row;
    int j=col;

    // check row
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }

    // check upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q' ){
            return false;
        }
        i--;
        j--;
    }
    // check bottom left diagonal
    i=row;
    j=col;
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;

    }
    // kahi par bhi queen nhi mili iska matlab safe hai place kardo
    return true;
    */
}

void solve(vector<vector<char>> &board, int col, int n){
    // base case
    if(col >= n){
        printSolution(board,n);
        return;
    }
    // 1case solve kardo, baki recursion kar lega

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            // rakh do
            board[row][col]='Q';  
            rowcheck[row]=true;
            upperLeftDiagonalCheck[n-1+row-col]=true;
            bottomLeftDiagonalCheck[row+col]=true;
            // recursion call
            solve(board,col+1,n);
            // backtrack
            board[row][col]='-'; 
            rowcheck[row]=false;
            upperLeftDiagonalCheck[n-1+row-col]=false;
            bottomLeftDiagonalCheck[row+col]=false;
        }
    }
}

int main(){
    int n=5;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    int col=0;
    //0 -> empty cell
    //1 -> queen at the cell
    solve(board, col ,n);

    return 0;
   
}