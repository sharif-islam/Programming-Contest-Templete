#include<bits/stdc++.h>
using namespace std;
typedef  long long int       lli;
int main ()
{
    lli a;
    lli b;
    cin >> a >> b;
    a= (-1000000000+(-1000000000));
    b=1000000007;
    if(a <0)
    {
        lli c=a*(-1);
        lli result=a +(b * ceil(c/b));
        cout << result <<endl;
    }
    else
        cout << a % (lli)b <<endl;
    return 0;
}

