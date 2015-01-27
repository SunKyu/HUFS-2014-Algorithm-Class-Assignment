#include <iostream>

using namespace std;

struct TreeNode{
  int data;
  TreeNode * parent=NULL;
  TreeNode * left=NULL;
  TreeNode * right=NULL;
};

void maketree(int input, TreeNode * root){
  if(root->parent==NULL){
    root->data=input;
  }
  else if(root->data>input)
    maketree(input, root->left);
  else if(root->data<=input) 
    maketree(input, root->right);
  else{
    TreeNode* q=new TreeNode;
    q->data=input;
    q->parent=root;
    if(input>=root->data)
      root->right=q;
    else
      root->left=q;
  }
}
void printvlaue(TreeNode* root){
  if(root->right==NULL&&root->left==NULL){
    cout<<root->data<<endl;
    return;
  }
  printvlaue(root->left);
  cout<<root->data<<endl;
  printvlaue(root->right);
}

int main(){
  int T;
  cin>>T;
  TreeNode Tree;
  
  int n;
  while(T--){
      cin>>n;
      int input;
      for(int i=0;i<n;i++){
        cin>>input;
        maketree(input,&Tree);
      }
      printvlaue(&Tree);
  }

}
