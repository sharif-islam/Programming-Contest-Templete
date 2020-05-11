#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define  mod                 100000000743856857
lli power(lli a,lli b,lli m)
{
    if(b==0)
        return 1%m;
    lli x=power(a,b/2,m);
    x=((x%m)*(x%m))%m;
    if(b&1)
        x=((x%m)*a)%m;
    return x;
}
lli gcd(lli a,lli m)
{
    if(a==0)
        return m;
    lli p=gcd(m%a,a);
    return p;
}
lli mod_inverse(lli a, lli m)
{
    int g=gcd(a,m);
    if(g!=1)
        cout << "Impossible"<<endl;
    else
        cout << power(a,m-2,m)<<endl;
}
int main ()
{
    lli a,m;
    cin >> a>>m;
    mod_inverse(a,m);
    return 0;
}
