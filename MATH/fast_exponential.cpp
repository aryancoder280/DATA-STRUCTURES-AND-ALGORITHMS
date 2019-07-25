#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long int ll;
int main()
{
    ll x,exp,result=1;
    cin>>x>>exp;
    while(exp>0)
    {
        if(exp&1)
        {
            result=(result*x)%M;
            exp--;
        }
        else
        {x=(x*x)%M;
        exp/=2;
        }


    }
    cout<<(result)%M<<endl;
}
