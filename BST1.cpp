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
        this->left = NULL;
        this->right=NULL;
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

void preOrderTraversal(Node* root){
      // preOrder --> CLR
      if(root == NULL) return;

      cout<< root->data <<" ";
      preOrderTraversal(root->left);
      preOrderTraversal(root->right);

}

void inOrderTraversal(Node* root){
    // InOrder--> LCR
    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout<<root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    // PostOrder Traversal --> LRC
    if(root == NULL)  return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data <<" ";

}

Node* findNodeInBST(Node* root, int target){
    // base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == target) return root;

    if(target > root->data){
        // right subtree me search
        return findNodeInBST(root->right, target);
    }
    else{
        return findNodeInBST(root->left, target);
    }
    

}

int minVal(Node* root){
    Node* temp = root;
    if(temp == NULL){
        return -1;
    }
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;

}

int maxVal(Node* root){
    Node* temp = root;
    if(temp == NULL) return -1;
    
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;  
}

// Node* deleteNodeInBST(Node* root, int target){
//     // base case
//     if(root == NULL)
//        return root;

//        // step 1:
//         Node* temp = findNodeInBST(root, target);
//        // delete Temp(4 case exist)
//        // 1 case Leaf Node
//        if(temp->left == NULL && temp->right == NULL){
//         delete temp;
//         return NULL;
//        }
//        // 2 case
//       else if(temp->left == NULL && temp->right != NULL){
//         Node* child = temp->right;
//         delete temp;
//         return child;
//        }
//        // 3 case
//      else if(temp->left != NULL && temp->right == NULL){
//         Node* child = temp->left;
//         delete temp;
//         return child;
//        }
//        // 4 case  both child exist(use Inorder predecessor / successor)
//         else{
//             int inorderPre = maxVal(temp->left);
//             temp->data = inorderPre;
//             temp->left = deleteNodeInBST(temp->left , inorderPre);
//             return root;
//         }

// }

Node* deleteNodeInBST(Node* root, int target){
    // base case
    if(root==NULL) return NULL;
     
     if(root->data == target){
        // 4 case
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            delete root;
            return child;
        }
        else{
            // both child
            int inorderPre = maxVal(root->left);
            root->data = inorderPre;
            root->left = deleteNodeInBST(root->left, inorderPre);
            return root;
        }
     }   
     else if(root->data > target){
        // left search
         root->left = deleteNodeInBST(root->left , target);
     }
     else if(root->data < target){
        // right search
        root->right = deleteNodeInBST(root->right, target);
     }
     return root;

} 


int main(){
     Node* root = NULL;
     cout<<"enter the data for Node "<<endl;
     takeInput(root);
     cout<<"printing the tree "<<endl;
     levelOrderTraversal(root);
     cout<<endl;
    //  cout<<"printing InOrder : "<< endl;
    //  inOrderTraversal(root); 
    //  cout<<endl;
    //  cout<<"printing preOrder : "<< endl;
    //  preOrderTraversal(root);
    //  cout<<endl;
    //  cout<<"printing postOrder : "<< endl;
    //  postOrderTraversal(root);
    //  cout<<endl;

    //  bool ans = findNodeInBST(root, 15);
    //  cout<<"present or not : "<< ans << endl;
    //  cout<< endl << " minimum val : "<< minVal(root)<<endl;
    //  cout<<endl<< "maximum val : "<< maxVal(root)<< endl;

    deleteNodeInBST(root, 150);
    levelOrderTraversal(root);
     

   return 0;
}