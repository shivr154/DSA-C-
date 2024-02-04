#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

   Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
   }
};

int findPosition(int arr[], int n, int element){
    for(int i=0; i<n; i++){
        if(arr[i] == element){
             return i;  
        }
    }
    return -1;
}

// build tree  from inorder and preorder traversal
Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size ,/*IMP*/ int &preIndex , int inorderStart, int inorderEnd ){
       // base case
       if(preIndex >= size || inorderStart > inorderEnd){
             return NULL;
       }

       // Step A; find first element from preOrder and find that element in inorder
       int element = preorder[preIndex++];
       Node* root = new Node(element);
       int pos = findPosition(inorder, size ,element);

       // step B; root->left solve
       root->left = buildTreeFromPreOrderInOrder(inorder, preorder,size , preIndex , inorderStart, pos-1);
       // step C: root->right solve
       root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos+1, inorderEnd);

       return root;

}


Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int &postIndex , int size ,int inorderStart, int inorderEnd,unordered_map<int,int> &mapping ){
        // base case
        if(postIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        // Step A:
        int element = postorder[postIndex--];
        Node* root = new Node(element);

      //  int pos = findPosition(inorder, size, element);
      // using map to reduce TC
        int pos = mapping[element];
        
        // imp--> isme phle right ki call jayegi phir left ki (LRC) kyuki right se left ki taraf areh hai
        // step B:root->right 
        root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos+1, inorderEnd,mapping);
        // step C:root->left
        root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos-1, mapping);
         
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

// reducing the complexity of finding element by O(n) to O(1) by using map
void createMapping(unordered_map<int, int> &mapping, int inorder[], int n) {
    for(int i=0; i<n; i++){
        mapping[inorder[i]] = i;
    }
}


int main(){
 /* Ques-->1 build Tree from preOrder ans Inorder Traversal
   int inorder[] = {40,20,50,10,60,30,70};
   int preorder[] = {10,20,40,50,30,60,70};
   int size = 7;
   int preIndex = 0;
   int inorderStart = 0;
   int inorderEnd = size -1;

   cout<< "Building Tree "<<endl;
   Node* root = buildTreeFromPreOrderInOrder(inorder, preorder,size ,preIndex, inorderStart , inorderEnd);
   
   cout<<"printing level Order Traversal "<<endl;
   levelOrderTraversal(root);
*/

// Ques --> 2 Build Tree From PostOrder And Inorder Traversal

   int inorder[] = {40,20,10,50,30,60};
   int postorder[] = {40,20,50,60,30,10};
   int size =6;
   int postIndex = size -1;
   int inorderStart= 0;
   int inorderEnd= size -1;

   unordered_map<int,int> mapping;
   createMapping(mapping, inorder, size);

   cout<< "Building the tree "<<endl;
  Node* root = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex,size, inorderStart, inorderEnd, mapping);
   cout<<"Printing the Tree"<<endl;
   levelOrderTraversal(root );



   return 0;
}