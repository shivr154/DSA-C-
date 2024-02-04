#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool cmp(char first,char second){
    return first > second;
}

bool compare(int a,int b){
    return a>b;
}

int main(){
/*string s="babbar";
sort(s.begin(),s.end(),cmp);

vector<int> v{5,3,1,2,4};
sort(v.begin(),v.end(),compare);
for(auto i:v){
    cout<< i << " ";
}
cout<<endl;

cout<< s << endl;*/

// creation of map
 map<int,char> meraMap;
 meraMap[0]='a';
 meraMap[1]='b';
 meraMap[25]='z';

cout<< "your ans is : " << meraMap[25]<< endl;
return 0;

}