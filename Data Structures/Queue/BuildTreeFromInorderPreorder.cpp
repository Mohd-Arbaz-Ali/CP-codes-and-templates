#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

int searching(int in[],int str,int end,int pre){
    for(int i=str;i<=end;i++){
        if(in[i]==pre)
            return i;
    }
    return 0;
}
Node* BuildBinaryTree(int in[],int pre[],int inStr,int inEnd,int& preIdx){
    if(inStr>inEnd)
        return NULL;
    Node* new_node=new Node(pre[preIdx++]);
    if(inStr==inEnd)
        return new_node;
    int inorderIdx=searching(in,inStr,inEnd,new_node->data);
    new_node->left=BuildBinaryTree(in,pre,inStr,inorderIdx-1,preIdx);
    new_node->right=BuildBinaryTree(in,pre,inorderIdx+1,inEnd,preIdx);
    return new_node;
}
Node* buildTree(int in[],int pre[], int n)
{
    Node* root=NULL;
    int p=0;
    root=BuildBinaryTree(in,pre,0,n-1,p);
    return root;
}

void printPostOrder(Node* root){
    if(root){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    printPostOrder(buildTree(in,pre,6));
    cout<<endl;
    return 0;
}