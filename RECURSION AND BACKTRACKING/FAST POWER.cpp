/* what if we need to find a^b where a and b both can be greater than 100. Then the brute force approach will gives TIME LIMITE EXCEED.
THEN THIS CONCEPT COMES "FAST POWER"
*/

#include<iostream>
void fastpower(int&val,int a,int b)
{
    if(b<=0)
        return;
    if(b&1)
    {
       val*=a;
       return fastpower(val,a,b-1);
    }
    else
    {
    //val=a*a;
    return fastpower(val,a*a,b/2);
    }


}
using namespace std;
 int main()
 {
     int a,b;
     cin>>a>>b;
     int val=1;
     fastpower(val,a,b);
     cout<<val;
 }
