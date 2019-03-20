#include<iostream>
#include<algorithm>
using namespace std;
struct edge
{
    int src,des,weight;
};
struct graph
{
    int v,e;
    edge *arr;
};
bool comp(edge a,edge b)
{
    if(a.weight<b.weight)
        return true;
    else
        return false;
}
struct parent
{
    int par,rank;
};
int find(parent p[],int i)
{
    if(p[i].par==i)
        return i;
    else
    {
        p[i].par=find(p,p[i].par);
        return p[i].par;
    }
}
void uni(parent p[],int x,int y,int v)
{
    int xroot=find(p,x);
    int yroot=find(p,y);
    if(p[xroot].rank < p[yroot].rank)
    {
        p[xroot].par=yroot;

    }
    else if(p[xroot].rank > p[yroot].rank)
    {
        p[yroot].par=xroot;
    }
    else
    {
        p[yroot].par=xroot;
        p[xroot].rank++;
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    graph g;
    g.v=v;
    g.e=e;
    g.arr=new edge[g.e];
    int x,y,weight;
    for(int i=0;i<g.e;i++)
    {
        cin>>x>>y>>weight;
        g.arr[i].src=x;
        g.arr[i].des=y;
        g.arr[i].weight=weight;
    }
    //step 1 sort wrt weight of the edge
    sort(g.arr,g.arr+e,comp);
    parent p[v];
    edge res[v];
    for(int i=0;i<v;i++)
    {
        p[i].par=i;
        p[i].rank=0;
    }
    int j=0;
    for(int i=0;i<e;i++)
    {
        int x=find(p,g.arr[i].src);
        int y=find(p,g.arr[i].des);
        if(x!=y)
        {
            uni(p,x,y,v);
            res[j++]=g.arr[i];
        }
    }
    for(int i=0;i<j;i++)
    {
        cout<<res[i].src<<" "<<res[i].des<<" "<<res[i].weight<<endl;
    }
}
