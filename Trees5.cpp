#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
     public:
      int data;
      Node* left;
      Node* right;

      Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
      }
};

Node* buildTree(){
    int data;
    cout<<"enter the data "<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout<<"enter data for left part of  "<< data << " NODE" <<endl;
    root->left = buildTree();
    cout<<"enter data for right part of  "<< data << " NODE"<<endl;
    root->right = buildTree();
    return root;
}



void levelOrderTraversal(Node* root){
    queue<Node*> q;
    // initially
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        // A
        Node* temp = q.front();
        // B
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // C
            cout<<temp->data<<" ";
            // D
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }

}

void printTopView(Node* root){
    if(root == NULL){
        return;
    }
    // create a map for storing Horizontal Distande(HD) -> TopNode -> data;
    map<int, int> topNode;

    // level order
    // we will store  a pair consisting of Node and Horizontal distance
    queue< pair<Node* ,int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance aya hai, check if answer alerady exist or not
        if(topNode.find(hd) == topNode.end()){ // iska matlab hme map mai ans nhi mila to unique val hai entry create karnge
             // creating entry
             topNode[hd] = frontNode->data;
        }

        if(frontNode -> left)
             q.push(make_pair(frontNode->left, hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));

    }

    // ab apka answer store hua hoga apke map mai
    cout<<"Printing the answer: " << endl;
    for(auto i: topNode){
        cout<<i.first<<" -> "<< i.second << endl; 
    }

}


void printBottomView(Node* root){
    if(root == NULL){
        return;
    }
    // create a map for storing Horizontal Distande(HD) -> TopNode -> data;
    map<int, int> topNode;

    // level order
    // we will store  a pair consisting of Node and Horizontal distance
    queue< pair<Node* ,int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // creating entry
             topNode[hd] = frontNode->data;

        if(frontNode -> left)
             q.push(make_pair(frontNode->left, hd-1));

        if(frontNode -> right)
            q.push(make_pair(frontNode->right, hd+1));

    }

    // ab apka answer store hua hoga apke map mai
    cout<<"Printing the answer: " << endl;
    for(auto i: topNode){
        cout<<i.first<<" -> "<< i.second << endl; 
    }
}


void printLeftView(Node* root , vector<int> &ans , int level){
    // base case
    if(root == NULL){
         return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // left
    printLeftView(root->left, ans, level+1);
    // right
    printLeftView(root->right, ans, level+1);
    
    }

  void printRightView(Node* root ,vector<int> &ans, int level){
          // base case
          if(root == NULL) return;

          if(level == ans.size()){
             ans.push_back(root->data);
          }
          // right
          printRightView(root, ans, level+1);
          // left
          printRightView(root , ans, level+1);

  }

  void printLeftBoundary(Node* root){
    // base case
    if(root == NULL) return;
    // if root is leaf node return
    if(root->left == NULL && root->right == NULL)
        return;
        
      cout<< root->data <<" ";
     if(root->left){
        printLeftBoundary(root->left);
     }
     else{
         printLeftBoundary(root->right); 
     }
     
  }

   void printLeafBoundary(Node* root){
      // base case
      if(root == NULL) return;
      if(root->left == NULL && root->right == NULL) { 
          cout<<root->data<<" ";
      } 

      printLeafBoundary(root->left);
      printLeafBoundary(root->right);
   }

   void printRightBoundary(Node* root){ 
     // base case
     if(root == NULL){
        return;
     }
     if(root->left == NULL && root->right == NULL)
        return;
     
     if(root->right){
       printRightBoundary( root->right);
     }
     else{
       printRightBoundary( root->left);
     }
    
     cout<< root->data <<" ";    

   }


  void boundaryTraversal(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
     
     // A
     printLeftBoundary(root->left);
     // B
     printLeafBoundary(root);
     // C
     printRightBoundary(root->right);
  }
  


int main(){
      Node* root = buildTree();
    //   printBottomView(root);
    //  vector<int>ans;
    //  int level = 0;
    //  printLeftView(root , ans ,level);

    //  cout<<"Printing the left view " << endl;
    //  for(auto i: ans){
    //       cout<< i << " ";
    //  }

    boundaryTraversal(root);
    
     return 0;
}