#include<iostream>
#include<queue>
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
    cin >> data;

    if(data == -1){
        return NULL;
    }

    // step A
    Node* root = new Node(data);
    // step B
    cout<<"Enter data for left part of "<< data << " Node "<<endl;
    root->left = buildTree();
    // step C
    cout<<"Enter data for Right part of "<< data << " Node "<<endl;
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
            cout<< endl;
               if(!q.empty()){
                   q.push(NULL);
               }
        }
        else{
           // C
             cout<< temp->data <<" ";
            // D
            if(temp -> left){
              q.push(temp->left);
               }
               if(temp->right){
                q.push(temp->right);
                }
            }
    }
}


void inorderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    // LNR
    inorderTraversal(root->left);
    cout<< root->data<<" ";
    inorderTraversal(root->right);

}

void preOderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
   
    // NLR
    cout<<root->data<<" ";
    preOderTraversal(root->left);
    preOderTraversal(root->right);
}

void postOrderTraversal(Node* root){
      // base case
      if(root == NULL){
        return;
      }

      // LRN
      postOrderTraversal(root->left);
      postOrderTraversal(root->right);
      cout<<root->data<<" ";
}

int height(Node* root){
     if(root == NULL) return 0;  

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight ,rightHeight) + 1;
    return ans;
}

int main(){
      Node* root = NULL;
      root = buildTree();

      levelOrderTraversal(root);
      cout<<"height "<< height(root) << endl;

    return 0;
}
