#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BST{
    Node* root;
    Node*temp;
    public:
    BST(){
        root = nullptr;
    }
    void insert(int value){
        if(root == nullptr){
            root = new Node(value);
            return;
        }else{
            InsertRec(root,value);
        }
    }
    void InsertRec(Node* node, int value){
        if(node->data > value){
            if(node->left == nullptr){
                node->left = new Node(value);
            }else{
                InsertRec(node->left,value);
            }
        }else{
            if(node->right == nullptr){
                node->right = new Node(value);
            }else{
                InsertRec(node->right,value);
            }
        }
    }
    // bool search(int x){//this is not the optimal way. 
    //     if(root == nullptr){
    //         return false;
    //     }
    //     if(root ->data = x){
    //         return true;
    //     }
    //     else{
    //         searchBST(root,x);
    //     }
    // }
    // void searchBST(Node* node,int x){
    //     if(node->data > x){
    //         searchBST(node->left,x);
    //     }else{
    //         searchBST(node->right,x);
    //     }
    // }
    bool search(int x){
        temp = root;
        while(temp!=nullptr){
            if(temp->data == x){
                return true;
            }else{
                if(temp->data > x){
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }
        }
        return 0;
    }
    void deleteNode(int x){
        if(search(x)){
            cout<<"value Deleted."<<endl;
            delete temp;
        }else{
            cout<<"Value not found."<<endl;
        }
    }
    void inorder(){
        cout<<"Inorder Traversal: ";
        inorderRec(root);
        cout<<endl;
    }
    void inorderRec(Node* node){
        if(node!=nullptr){
            inorderRec(node->left);
            cout<<node->data<<" ";
            inorderRec(node->right);
        }
    }
};
int main(){
    BST bt;
    bt.insert(10);
    bt.insert(4);
    bt.insert(6);
    bt.insert(14);
    bt.insert(2);
    bt.insert(30);
    bt.inorder();
    if(bt.search(2)){
        cout<<"!Hurey we found the element."<<endl;
    }else{
        cout<<"! sorry we could not found the element"<<endl;
    }
    bt.deleteNode(2);
    // bt.inorder();
    // bt.deleteNode(2);
    if(bt.search(2)){
        cout<<"!Hurey we found the element."<<endl;
    }else{
        cout<<"! sorry we could not found the element"<<endl;
    }
}