#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin >>t;
    for(int i=1;i<=t;i++)
    {
        int n;
         cin >>n;
         int a[n];
         int max=INT_MIN;
         int value=0;
         for(int i=0;i<n;i++)
         {
             cin >> a[i];
             value=value+a[i];
             if(max<value)
                max=value;
             if(value<0)
                value=0;
         }
         cout << max <<endl;
    }
    return 0;
}

