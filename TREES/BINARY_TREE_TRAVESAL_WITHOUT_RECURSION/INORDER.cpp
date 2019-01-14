//RECURSION MAKES EASY TO IMPLEMENT TREE TRAVERSAL
#include<iostream>
#include<stack>
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
 void inorder(node*root)//left-right-node
 {
     stack<node*>s;
     while(root||!s.empty())
     {
       while(root!=NULL)
         {
             s.push(root);
             root=root->left;
         }
         if(!root&&!s.empty())
         {  cout<<s.top()->data<<" ";
              root=(s.top())->right;
             s.pop();
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
cout<<"inorder=";
obj1.inorder(root);

}
