/*Given an array A[] of N integers, where each integer is greater than 1. 
The task is to find the number of Full binary tree from the given integers, such that each non leaf node value is the product of its children value.
Note: Each integer can be used multiple times in a full binary tree.
Examples:

Input : A[] = { 2, 3, 4, 6 }.
Output : 7
There are 7 full binary tree with the given product property.

// Four trees with single nodes
2  3  4  6

// Three trees with three nodes
  4   ,
 / \
2   2

  6    ,
 / \
2   3

  6
 / \
3   2  


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer N denoting the size of the array A[]. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print an integer denoting the result.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
4
2 3 4 6
3
2 4 5

Output:
7
4*/
GIVE IT A TRY BEFORE MOVING TO THE SOLUTION.






--------------------------------SOLUTION--------------------------------
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {  int n;
        cin>>n;
        int arr[n];
        int count=0;
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }

        sort(arr,arr+n);
       /* queue<int>p;
        for(int j=0;j<n;j++)
        {  if(!p.empty())
            {
                p.push(arr[j]);
               count++;
            }
        else
        {  int top=p.front();
          p.pop();
          if(top==arr[j])
          {
             ;

          }
          else
          {
              count++;
              p.push(arr[j]);
          }
          }
        }*/
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                count++;
            }
            else
            {
                if(arr[j-1]!=arr[j])
                    count++;
            }

        }

        queue<int>q;
    for(int j=0;j<n;j++)
    {
        q.push(arr[j]);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            for(int k=2;k*k<=top;k++)
            {
                if(top%k==0)
                {   bool c=binary_search(arr,arr+n,k);
                    bool b=binary_search(arr,arr+n,top/k);
                    //cout<<"k="<<k<<" "<<"top="<<top<<" "<<"b="<<b<<endl;
                    if(k!=(top/k))
                    {
                        if(b&&c)
                      { count+=2;
                      q.push(k);
                      q.push(top/k);
                      }
                    }
                    else
                    {
                        if(b&&c)
                        {count++;
                        q.push(k);
                        q.push(top/k);
                        }
                    }
                }
            }
        }
    }
    cout<<count<<endl;
    }
}
