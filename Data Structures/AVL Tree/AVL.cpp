#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int x){
        data=x;
        left=right=NULL;
        height=1;
    }
};

int Height(Node* root){
    if(!root)
        return 0;
    return root->height;
}
Node* SingleRotationLeft(Node* root){
    Node* x=root->left;
    root->left=x->right;
    x->right=root;
    root->height=max(Height(root->left),Height(root->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return x;
}
Node* SingleRotationRight(Node* root){
    Node* x=root->right;
    root->right=x->left;
    x->left=root;
    root->height=max(Height(root->left),Height(root->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return x;
}
Node* DoubleRotationLeft(Node* root){
    root->left=SingleRotationRight(root->left);
    root=SingleRotationLeft(root);
    return root;
}
Node* DoubleRotationRight(Node* root){
    root->right=SingleRotationLeft(root->right);
    return SingleRotationRight(root);
}
Node* insertToAVL(Node* node, int data)
{
    if(!node)
        {
            node=new Node(data);
            //cout<<node->data<<endl;
        }
    else if(data<node->data){
        node->left=insertToAVL(node->left,data);
        if(abs(Height(node->left)-Height(node->right))==2){
            if(data<node->left->data)
                node=SingleRotationLeft(node);
            else 
                node=DoubleRotationLeft(node);
        }
    }
    else if(data>node->data){
        node->right=insertToAVL(node->right,data);
        if(abs(Height(node->left)-Height(node->right))==2){
            if(data>node->right->data){
                node=SingleRotationRight(node);
            }
            else
                node=DoubleRotationRight(node);
        }
    }
        node->height=max(Height(node->left),Height(node->right))+1;
    return node;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node* root=NULL;
    root=insertToAVL(root,850);
    root=insertToAVL(root,859);
    root=insertToAVL(root,912);
    root=insertToAVL(root,50);
    root=insertToAVL(root,218);
    root=insertToAVL(root,545);
    root=insertToAVL(root,815);
    root=insertToAVL(root,22);
    root=insertToAVL(root,903);
    root=insertToAVL(root,903);

    inorder(root);
    cout<<endl;
    return 0;
}