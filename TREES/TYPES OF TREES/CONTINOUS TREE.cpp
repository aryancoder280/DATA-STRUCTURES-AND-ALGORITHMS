/*
A tree is Continuous tree if in each root to leaf path, absolute difference between keys of two adjacent is 1.
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
//--------------CONTINOUS TREE----------------//
 bool continous_tree(node*root,node*temp)
 {
    if(temp==NULL)
    {
        return 1;
    }
    if(temp==root)
    {
        bool b=continous_tree(root,root->left);
        if(b)
        {
            bool d=continous_tree(root,root->right);
            if(d)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        int diff=abs(temp->data-root->data);
        if(diff==1)
        {
            bool b=continous_tree(temp,temp->left);
            if(b)
            {
                bool d=continous_tree(temp,temp->right);
                if(d)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
    }

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
//obj1.bfs(root);
if(obj1.continous_tree(root,root))
    cout<<"yes";
else
    cout<<"no";
}
