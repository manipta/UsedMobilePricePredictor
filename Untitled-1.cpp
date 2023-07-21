#include<bits/stdc++.h>
void inorder(TreeNode<int> *root,vector<int>&arr){

    if(root==NULL){

        return ;

    }

   inorder(root->left,arr);

    arr.push_back(root->data);

       inorder(root->right,arr);

}

 

vector<int>mergearr(vector<int>&arr1,vector<int>&arr2){

     int m=arr1.size();

    int n=arr2.size();

    vector<int>ans(m+n);

    int i=0,j=0;

   int k=0;

    while(i<arr1.size() && j<arr2.size()){

        if(arr1[i]<arr2[j]){

            ans[k++]=arr1[i];

            i++;

        }

        else{

          ans[k++]=arr2[j];

            j++;

          }

    }

          

          while(i<arr1.size()){

                 ans[k++]=arr1[i]; 

              i++;

          }

          

            while(j<arr2.size()){

                 ans[k++]=arr2[j];  

              j++;

          }

          

     return ans;

}

TreeNode<int>* inordertoBST(vector<int>&in,int s,int e){

    if(s>e){

        return NULL;

    }

    int mid=(s+e)/2;

    //creating a new node

    TreeNode<int>* root=new TreeNode<int>(in[mid]);

    //recursion call

    root->left=inordertoBST(in,s,mid-1);

    root->right=inordertoBST(in,mid+1,e);

    return root;

}

 

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){

   vector<int>arr1,arr2;

    

    inorder(root1,arr1);

    inorder(root2,arr2);

   

 vector<int>merge=mergearr(arr1,arr2);

    int s=0;

    int e=merge.size()-1;

     return inordertoBST(merge,s,e);

}