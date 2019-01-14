/*
In a binary tree, a node with two children cannot be deleted unambiguously. 
However, in certain binary trees (including binary search trees) these nodes can be deleted, though with a rearrangement of the tree structure.
BUT WHAT ABOUT BINARY TREES?
ANS= Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom(i.e. the deleted node is replaced by bottom most and rightmost node). 
*/
#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    node*left,*right;
}*root=NULL;
class tree
{

  public:
    node*insert(node*root,int data)
    {  node*temp=root;
        if(!root)
        {
            root=new node;
            root->data=data;
            root->left=root->right=NULL;
         return root;
        }
        else
        {
            queue<node*>q;
            q.push(root);
            while(!q.empty())
            {
                node* top=q.front();
                q.pop();
                if(top->left)
                {
                    q.push(top->left);
                }
                else
                {
                    top->left=new node;
                    top->left->data=data;
                    top->left->left=NULL;
                    top->left->right=NULL;
                  break;
                }
                if(top->right)
                {
                    q.push(top->right);
                }
                else
                {
                    top->right=new node;
                    top->right->data=data;
                    top->right->left=NULL;
                    top->right->right=NULL;
                  break;
                }
        }
        return temp;
        }
    }

 void inorder(node*root)
 {
     if(!root)
        return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
     return;
 }
void deletionBT(struct node* root, int data)
{  node*t=root;
     struct node*n,*deep,*parentofdeep;
     queue<node*>q;
     if(root!=NULL)//VERY IMPORTANT CONDITION OTHERWISE IT WILL GIVE SEGMENTATION FAULT
     {
         q.push(root);
     while(!q.empty())
     {  struct node*temp=q.front();
     q.pop();
         if(data==temp->data)
         {
             n=temp;
         }
         if(temp->left)
             {
                 q.push(temp->left);
                 parentofdeep=temp;
                 deep=temp->left;
             }
            if(temp->right)
            {
                q.push(temp->right);
                parentofdeep=temp;
                deep=temp->right;
            }
        }

        n->data=deep->data;
        if(parentofdeep!=NULL&&parentofdeep->left==deep)
        {
            parentofdeep->left=NULL;

        }
        else
        {
          parentofdeep->right=NULL;

        }
    }//60 70 80 30 50 20 10
        //4 2 5 1 7 3

}
};
int main()
{
  int n;
  tree obj1;
  cout<<"ENTER THE NODE VALUES AND STOP TAKING INPUT BY GIVING -1 AS INPUT\n";
  do
  {
      cin>>n;
      if(n!=-1)
      {
          root=obj1.insert(root,n);
      }
  }while(n!=-1);
cout<<"inorder before deleletion=\n";
obj1.inorder(root);
int key;
cout<<"\nenter element to be deleted=";
cin>>key;
obj1.deletionBT(root,key);
cout<<"inorder after deleletion=\n";
obj1.inorder(root);

}
