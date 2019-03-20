#include<iostream>
#include<vector>
using namespace std;
bool colour(int **arr,int m,int pos,vector<int>&vertex,int v)
{
    if(pos==v+1)
    {
        return true;
    }
    vector<bool>col(m+1,true);
    for(int j=1;j<=v;j++)
    {
        if(arr[pos][j]==1)
        {
            if(vertex[j]!=m+1)
            {
                col[vertex[j]]=false;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(col[i]==true)
        {   // cout<<"i="<<i<<endl;
            vertex[pos]=i;
            if(colour(arr,m,pos+1,vertex,v))
                 return true;
          else
          {
              vertex[pos]=m+1;

          }
        }
    }
    return false;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,m,e;
        cin>>v>>m>>e;
        int **arr;
        arr=(int**)malloc((v+1)*sizeof(int*));
        for(int i=1;i<=v;i++)
        {
            arr[i]=(int*)malloc((v+1)*sizeof(int));
        }
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
                arr[i][j]=0;
        }
        int x,y;
        for(int i=0;i<e;i++)
        {
            cin>>x>>y;
            arr[x][y]=1;
            arr[y][x]=1;
        }
        vector<int>vertex(v+1,m+1);
        if(colour(arr,m,1,vertex,v))
        {
            //for(int i=0;i<v;i++)
            //cout<<vertex[i]<<" ";
            cout<<1<<endl;

        }
        else
            cout<<0<<endl;

    }
}

