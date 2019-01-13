/*
GIVEN N X N GRID IN WHICH RAT IS AT 0,0. THE RAT CAN MOVE EITHER UP OR DOWN, THE CHESSE WILL BE AT (N-1,N-1).
THERE CAN BE MANY OBSTACLES.
WE NEED TO FIND THE PATHS THROUGH WHICH THE RAT CAN FIND TEH CHEESE. 
*/
#include<iostream>
using namespace std;
void print(char arr[][4],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j];
        cout<<endl;
    }
}
void check(char a[][4],int i,int j,int n)
{

    if(a[i][j]=='3')
    {
        print(a,n);
        cout<<endl;
        return;
    }
   else
   {
       if((j+1!=n&&a[i][j+1]!='X')||(i+1!=n&&a[i+1][j]!='X'))
       {
           if((j+1!=n&&a[i][j+1]!='X'))
          {
            a[i][j]='1';
           check(a,i,j+1,n);
          }


       if((i+1!=n&&a[i+1][j]!='X'))
       {
         a[i][j]='1';
           check(a,i+1,j,n);


       }
         a[i][j]='0';
           return;
       }
       else
       return;
   }


}
int main()
{
    int n=4;

    char a[4][4];
    int blocks,b1,b2;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        a[i][j]='0';
       }
    cin>>blocks;
    for(int i=0;i<blocks;i++)
    {cin>>b1>>b2;
    a[b1][b2]='X';
    }
    a[3][3]='3';
    print(a,n);
    cout<<endl;
   check(a,0,0,n);

}
