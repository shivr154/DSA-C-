#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//function for getting length
int getlength(char name[]){
    int length=0;
    int i=0;
    while(name[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

// function for reverse a string
void reverseCharArray(char name[]){
    int i=0;
    int n=getlength(name);
    int j=n-1;  
    
    while(i<=j){
         swap(name[i],name[j]);
         i++;
         j--;
    }
}

void replaceSpaces(char sentence[ ]){
    int i=0;
    int n= getlength(sentence);
    for(int i=0;i<n;i++){
        if(sentence[i]==' '){
            sentence[i]='@';
        }
    }
}

bool checkPalindrome(char word[]){
    int i=0;
    int n=getlength(word);
    int j=n-1;

    while(i<=j){
        if(word[i] != word[j]){
            return false;
        }
        else{
        i++;
        j--;
        }
    }
    return true;
}

// convert into upper case
 void convertIntoUppercase(char arr[100]){
    int n=getlength(arr);
    for(int i=0;i<n;i++){
        arr[i]=arr[i] -'a'+'A';
    }
 }
  
  //compare function for strings
  bool compareString(string a,string b){
    if(a.length() != b.length()){
        return false;
    }
    else{
        int i=0;
        int j=0;
        for(int i=0;i<a.length();i++){
            if(a[i] != b[j]){
                return false;
            }
           j++;
        }
    }
    return true;
  }

int main(){
  /*  char name[100];

    cout<<"enter your name : "<< name << endl;
    cin>>name;
    cout<<endl;

    char ch[100];

    ch[0]='a';
    ch[1]='b';
    cout<<"enter the character "<< endl;
    cin >> ch[2] ;
    cout<<ch[0]<<ch[1]<<ch[2];*/
/*
    char name[100];

    cin>> name;

    for(int i=0;i<7;i++){
        cout<<"index : "<< i << " value: "<< name[i] <<endl;
    }

    int value = (int)name[4];
    cout<<"value is : "<< value << endl; // ascii value
*/

   /* char ch[100];
   // cin>>ch;

    cin.getline(ch,50); // used to read spaces,tab,newline which can't  be read by cin function.
    cout<<ch;
    cout<<endl;
*/

 /*   char name[100];
    cin.getline(name,50);

    cout<<"length is : "<< getlength(name)<< endl;
    //cout<<"length is : "<< strlen(name)<< endl; // pre defined function for length.

    cout<<"initially : "<< name<<endl;
    reverseCharArray(name);
    cout<<"after reversal process: "<< name<<endl;
*/

/*char sentence[100];
cin.getline(sentence,100);

replaceSpaces(sentence);
cout<<"printing sentence : "<< endl << sentence<<endl;
*/

 /*char arr[100]="racecar";
  cout<<"palindrome check : "<< checkPalindrome(arr);*/

/* char arr[100]="babbar";
 convertIntoUppercase(arr);
 cout<<arr<<endl;
*/

 // ------------->>>>>>> string create

 /*string str;

 // input
 //cin>>str;
 getline(cin,str);

 // output
 cout<<str;
 cout<<endl;

// pre deined function basically used in string

 cout<<" length is : "<< str.length()<<endl;
 cout<<" is empty : "<< str.empty()<<endl; 
 str.push_back('A');
 cout<<str<<endl;
 str.pop_back();
 cout<<str<<endl;
 cout<<str.substr(0,8) << endl; // used for getting a sub part of a string
 cout<<str<<endl; // string is pass by value char array is pass by refrence

 string a="love";
 string b="Love";

 if(a.compare(b)==0){
    cout<<"a and b are exactly same strings "<<endl;
 }
else{
    cout<<"a and b are not same " << endl;
}

  string sentence = "hello jee kaise ho saree ";
  string target = "jee";

  cout<< sentence.find(target);
*/

 /*string str="this is my first message"; 
 string word="babbar";

 str.replace(0,4,"word");
 cout<<str<<endl;
*/

/*
string str="abcdefghijklmn";
str.erase(0,4);
cout<<str<<endl;

*/




    return 0;
}