#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
}*root=nullptr;
int height(node*root)
{
    if(!root)
        return 0;
    else
    {
       int l=1+height(root->left);
       int r=1+height(root->right);
       if(l>=r)
        return l;
       else
        return r;
    }
}
void rotate(node*&root,node*unbalanced,int key,node*parent)
{  char t[2];
node*temp=unbalanced;
    if(unbalanced->data>key)
        {
            t[0]='l';
            unbalanced=unbalanced->left;
        }
    else
      {
          t[0]='r';
            unbalanced=unbalanced->right;
      }
     if(unbalanced->data>key)
        {
            t[1]='l';
            unbalanced=unbalanced->left;
        }
    else
      {
          t[1]='r';
            unbalanced=unbalanced->right;
      }
      cout<<t[0]<<" "<<t[1]<<endl;
//four cases
if(t[0]=='l'&&t[1]=='l')//left rotation
{
    if(parent!=nullptr)
    {
        if(parent->left==temp)
    {
        node*t=temp->left;
        node*t2=t->right;
        t->right=temp;
        temp->left=t2;
        parent->left=t;
        return ;
    }
  }
  else
  {
      node*t=temp->left;
      node*t2=t->right;
      temp->left=t2;
      t->right=temp;
      root=t;
      return;
  }
}
else if(t[0]=='r'&&t[1]=='r')
{
    if(parent!=nullptr)
    {
        if(parent->right==temp)
    {
        node*t=temp->right;
        node*t2=t->left;
        t->left=temp;
        temp->right=t2;
        parent->right=t;
        return ;
    }
  }
  else
  {
      node*t=temp->right;
      node*t2=t->left;
      temp->right=t2;
      t->left=temp;
      root=t;
      return;
  }
}
else if(t[0]=='l'&&t[1]=='r')
{
    if(parent==NULL)
    {  //right first
        {
        node*temp=root->left;
        parent=root;
        node*t=temp->right;
        temp->right=t->left;
        t->left=temp;
        parent->left=t;
        }
       //left
      {
      node*t=temp->left;
      node*t2=t->right;
      temp->left=t2;
      t->right=temp;
      root=t;
      return;
      }
    }
    else
    {
         {
        node*t1=temp->left;
        node*parent=temp;
        node*t=t1->right;
        t1->right=t->left;
        t->left=t1;
        parent->left=t;
        }
       node*t=temp->left;
       temp->left=t->right;
       t->right=temp;
       parent->right=t;
        return;

    }
}
else
{
    if(parent==NULL)
    {  //right first
        {
        node*temp=root->right;
        parent=root;
        node*t=temp->left;
        temp->left=t->right;
        t->right=temp;
        parent->right=t;
        }
       //left
      {
      node*t=temp->right;
      node*t2=t->left;
      temp->right=t2;
      t->left=temp;
      root=t;
      return;
      }
    }
    else
    {

    }
}
}
void preorder(node*root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
bool find(node*temp,node*root,int key,node*&unbalance,node*&parent)
{
    if(root->data==key)
    {
        return true;
    }
    else if(root->data>key)
    {
        bool x=find(temp,root->left,key,unbalance,root);
        if(x)
        {int l=1+height(root->left);
        int r=1+height(root->right);
    int diff=l-r;
    if(diff==-1||diff==0||diff==1)
            {
                return true;
            }
    else
        {unbalance=root;
          cout<<"before rotation\n";
          preorder(temp);
          cout<<endl;
          rotate(temp,unbalance,key,parent);
         cout<<"after rotation\n";
         preorder(temp);
             cout<<endl;
            return true;
        }
        }
   }
  else
    {
     bool x=find(temp,root->right,key,unbalance,root);
        if(x)
        {int l=1+height(root->left);
        int r=1+height(root->right);
    int diff=l-r;
    if(diff==-1||diff==0||diff==1)
            {
                return true;
            }
    else
        {unbalance=root;
        cout<<"before rotation\n";
          preorder(temp);
          cout<<endl;
          rotate(temp,unbalance,key,parent);
         cout<<"after rotation\n";
         preorder(temp);
         cout<<endl;
            return true;
        }
        }
    }
}


node*insert(node*root,int key)
{ node*temp=root;
    if(!root)
    {
        root=new node;
        root->data=key;
        root->left=root->right=nullptr;
        return root;
    }
    else
    {
        while(1)
        {
            if(root->data>key)
            {
                if(root->left)
                    root=root->left;
                else
                {
                    root->left=new node;
                    root->left->data=key;
                    root->left->left=root->left->right=nullptr;
                    node*unbalance=nullptr,*parent=nullptr;
                    find(temp,temp,key,unbalance,parent);

                    break;

                }
            }
            else
            {// cout<<root->data<<" ";
                if(root->right)
                    root=root->right;
                else
                {
                    root->right=new node;
                    root->right->data=key;
                    root->right->left=root->right->right=nullptr;
                    node*unbalance=nullptr,*parent=nullptr;
                    find(temp,temp,key,unbalance,parent);
                   break;
                }
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
}
int main()
{
    int n;
    do
    {
        cin>>n;
        if(n!=-1)
        {
            root=insert(root,n);
        }
    }while(n!=-1);
    inorder(root);

}

