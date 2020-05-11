#include<bits/stdc++.h>

#define sci(n)          scanf("%d",&n)
#define scii(a,b)       scanf("d",&a,&b)
#define sclli(n)        scanf("%lld",&n)
#define scs(s)          scanf("%s",s)
#define scd(n)          scanf("%lf",&n);
#define scld(n)         scanf("%llf",&n);
#define sc              scanf
#define pf              printf
#define vi              vector<int>
#define pp              pair<int,int>
#define pb(x)           push_back(x)
#define mp(x,y)         make_pair(x,y)
#define f               first
#define s               second
#define Unique(v)       v.erase(unique(all(v)),v.end());
#define all(v)          (v).begin(),(v).end()
#define arrsort         sort(arr,arr+n)
#define vsort           sort(all(v))
#define maxsort         sort(all(v),greater<int>())
#define sqr(x)          ((x)*(x))
#define qube(x)         ((x)*(x)*(x))
#define deci(n)         cout<<fixed<<setprecision(n);
#define for0(i,n)       for(i = 0 ; i < n ; i++)
#define for1(i,n)       for(i = 1 ; i <= n ; i++)
#define E               "\n"
#define TC(T)           int T;cin>>T;while(T--)
#define FTC(T)          int T;cin>>T;for(int i=1;i<=T;i++)
#define Case            printf("Case %d: ",i)
typedef long long int lli;
typedef unsigned long long int ulli;
using namespace std;
int a[1000000];
int longestPrefixSuffix(string s)
{
    int n = s.length();
    a[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            a[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = a[len-1];
            }
            else
            {
                a[i] = 0;
                i++;
            }
        }
    }

    int res = a[n-1];
    return (res > n/2)? n/2 : res;
}
int main()
{
    string s = "abcab";
    cout << longestPrefixSuffix(s);
    return 0;
}

