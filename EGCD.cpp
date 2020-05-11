#include<bits/stdc++.h>
using namespace std;
#define ulli long long int
ulli GCDExtended(ulli a,ulli m,ulli *x,ulli *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return m;
    }
    ulli x1,y1;
    ulli gcd=GCDExtended(m%a,a,&x1,&y1);
    *x=y1-(m/a)*x1;
    *y=x1;
    return gcd;
}
ulli mod_inverse(ulli a,ulli m)
{
    ulli x,y;
    ulli g=GCDExtended(a,m,&x,&y);
    if(g!=1)
        cout << "Impossible"<<endl;
    else{
        ulli ans=((x%m)+m)%m;
        cout << ans <<endl;}
}
int main ()
{
    ulli a,m;
    cin >> a >> m;
    mod_inverse(a,m);
    return 0;
}
