/* k-ary tree can be stored in a "Breadth first search order" as implicit data structures in arrays, and if the tree
is a complete k-ary tree, this method waste no space.
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void insert(vector<int>&v,int n,int i,int k)
{
    bool t=false;//to check whether a node has 3 children or not
   if(v[0]==-1)
    {
        v[0]=n;
        t=true;
    }
    else if(v[k*i+1]==-1)//k*i+1 gives first child
    {
        v[k*i+1]=n;
        t=true;
    }
   else if(v[k*i+2]==-1)//k*i+2 gives first child
    {
        v[k*i+2]=n;
        t=true;
    }
  else  if(v[k*i+3]==-1)//k*i+3 gives first child
    {
        v[k*i+3]=n;
        t=true;
    }
    if(t==false)
    {
        return insert(v,n,i+1,k);//Through recursion, we move to the  children of current node follow the procedure again.
    }
    else
        return;
}
 int main()
 {
 int k;
 cout<<"enter value of k in k-ary tree=";
 cin>>k;
 int h;
 cout<<"enter height of tree=";
 cin>>h;
     //for a complete k ary tree total number of nodes=((k^(h+1)-1)/(k-1))
 int total_nodes=pow(k,h+1)-1;
     total_nodes=total_nodes/(k-1);
 vector<int>v(total_nodes,-1);
 int n;
 int count=0;
 while(count<total_nodes&&n!=-1)
  {
  cin>>n;
  if(n!=-1)
  {
      insert(v,n,0,k);
  }
  count++;
  }


 for(int i=0;i<total_nodes;i++)
 {
     cout<<v[i]<<" ";
 }
 }
