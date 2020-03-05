#include <iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool checkSum(Node *root){
    if(!root){
        return true;
    }
    if(!root->left && !root->right){
        return true;
    }
    int sum = 0;
    if(root->left)
        sum+=root->left->data;
    if(root->right)
        sum+=root->right->data;

    return ((sum==root->data) && checkSum(root->left) && checkSum(root->right));
}

int main()
{
  Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    root->left->left->left = new Node(2);
    if(checkSum(root))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
