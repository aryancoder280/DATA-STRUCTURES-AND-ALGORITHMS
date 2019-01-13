//better than linear search. Jump search takes O(sqrt(n)) and less comparison compare to linear search
//CONDITION= Array must be sorted
#include<iostream>
#include<cmath>
using namespace std;
int jump_search(int*a,int n,int key)
{/*In the worst case-: 
we have to do n/m jumps and if the last checked value is greater than the element to be searched for, we perform m-1 comparisons more for linear search. 
Therefore the total number of comparisons in the worst case will be ((n/m) + m-1).
The value of the function ((n/m) + m-1) will be minimum when m = √n.
Therefore, the best step size is m = √n.
*/
   int k=sqrt(n);
   int last;
   for(int i=0;i<n;i+=k)
   {
       if(key>=a[i]&&key<=a[i+k-1])
       {
           if(key<a[i])
            return -1;
           else
           {
               for(int j=i;j<=i+k;j++)
           {

               if(a[j]==key)
                return j;

           }
           }
       }
       else if(key<a[i])//IMP=this condition is used to check if key is less than a[0]. if i not use this condition the algo will traverse whole array and at the end retirn -1.
        return -1;


   }
   return -1;
}
int main()
{
    int n,num;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<jump_search(a,n,key);
}
