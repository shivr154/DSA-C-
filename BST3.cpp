#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right=NULL;
    }

};

class NodeData{
         public:
         int size;
         int minVal;
         int maxVal;
         bool validBST;
         
         NodeData(){

         }
         NodeData(int size, int max, int min, int valid){
              this->size = size;
              minVal = min;
              maxVal = max;
              validBST = valid;

         }

};

Node* insertIntoBST(Node* root, int data){
      if(root == NULL){
        // this is the first node we have to create
          root = new Node(data);
          return root;
      }
      // not the first node
      if(root->data > data){
         // insert in left 
         root->left = insertIntoBST(root->left, data);
      }
       else{
        // insert into right
           root->right = insertIntoBST(root->right, data);
      }
      return root;

}

void takeInput(Node* &root){
    int data;
    cin>>data;
    
    while(data != -1){
          root = insertIntoBST(root, data);
          cin>>data;
    }
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

Node* bstUsingInorder(int inorder[], int s, int e){
    // base case
    if(s > e) return NULL;

    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = bstUsingInorder(inorder, s, mid-1);
    root->right = bstUsingInorder(inorder, mid+1, e);
    return root;

}

// ques-->1 covert BST to Sorted Doubly LL
void convertIntoSortedDLL(Node* root, Node* &head){
    // base case
    if(root == NULL){
        return ;
    }
    // right subtree into LL
    convertIntoSortedDLL(root->right, head);
    
    // attach root node
    root->right = head;
    if(head!=NULL){
        head->left = root;
    }
    //update head
    head = root;

    // left subtree LL
    convertIntoSortedDLL(root->left, head);

}

void printLinkedList(Node* head){
    Node* temp = head;
    cout<<endl;

    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp->right;
    }
    cout<<endl;
}

// Ques-->2 covert Sorted LL into BST
Node* sortedLinkedListIntoBST(Node* &head, int n){
        // base case
        if(n <= 0 || head == NULL)
            return NULL;
        // left Subtree bnana hai
        Node* leftSubtree = sortedLinkedListIntoBST(head, n-1-n/2);
        // left subtree ke agla element root node hai
        Node* root = head;
        root->left = leftSubtree; // link root ka left to left Subtree
        // update head
        head = head->right;
        // right part solve karna h
        root->right = sortedLinkedListIntoBST(head, n/2);  
        return root;

}

// Ques--> 3 Find Largest BST in BT
NodeData* findLargestBST(Node* root, int &ans){
    // base case
    if(root == NULL){
       NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }
    NodeData* leftkaAns = findLargestBST(root->left, ans);   
    NodeData* rightkaAns = findLargestBST(root->right, ans);

    // checking starts here
    NodeData* currNodekaAns = new NodeData();
    currNodekaAns->size = leftkaAns->size + rightkaAns->size + 1;
    currNodekaAns->maxVal = max(root->data , rightkaAns->maxVal); 
    currNodekaAns->minVal = min(root->data , leftkaAns->minVal);

    if(leftkaAns->validBST && rightkaAns->validBST && (root->data > leftkaAns->maxVal && root->data < rightkaAns->minVal)){
        currNodekaAns->validBST = true;
    }
    else{
        currNodekaAns->validBST = false;
    }

    if(currNodekaAns->validBST){
        ans = max(ans, currNodekaAns->size);
    }
     return currNodekaAns;

}


int main(){
    //  int inorder[] = {1,2,3,4,5,6,7,8,9};
    //  int s=0;
    //  int e=8;

    //  Node* root = bstUsingInorder(inorder,s,e);
    //  levelOrderTraversal(root);

    // cout<<"printing Sorted LL "<< endl;
    //  Node* head= NULL;
    //  convertIntoSortedDLL(root, head);
    //  printLinkedList(head);

    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);
    
    root->left = first;
    root->right = second;
    first -> left = third; 
    first ->right = fourth;

    cout<<"Printing the tree "<< endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);
    cout<<"Largest BST ka size: "<< ans<< endl;
  

    return 0;
}