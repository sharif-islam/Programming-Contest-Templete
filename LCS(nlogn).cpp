#include<bits/stdc++.h>

#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  MAX                 1234567899
#define  mod                 1000000007
#define  all(v)              (v).begin(),(v).end()
#define  vSort(v)            sort(all(v))
#define  maxSort(v)          sort(all(v),greater<int>())
#define  Unique(v)           v.erase(unique(all(v)),v.end())
#define  sqr(x)              ((x)*(x))
#define  qube(x)             ((x)*(x)*(x))
#define  deci(n)             cout<<fixed<<setprecision(n)
#define  sci(n)              sc("%d",&(n))
#define  scii(x,y)           sc("%d %d",&(x),&(y))
#define  scl(x)              sc("%lld",&(x))
#define  scll(x,y)           sc("%lld %lld",&(x),&(y))
#define  vi                  vector<int>
#define  hi                  pf(" HI \n")
#define  pp                  pair<int,int>
#define  pb(x)               push_back(x)
#define  mp(x,y)             make_pair(x,y)
#define  F                   first
#define  S                   second
#define  check(n,pos)        (n & (1<<(pos)))
#define  biton(n,pos)        (n  (1<<(pos)))
#define  bitoff(n,pos)       (n & ~(1<<(pos)))
typedef  long long int       lli;
typedef  unsigned long long int ulli;
int dx4[] = { 0, 0, -1, 1 } ;
int dy4[] = { -1, 1, 0, 0 } ;
bool valid( int r, int c, int x, int y )
{
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ;
    return 0 ;
}
using namespace std;
int a[2001][2001];
vector<char>v;
string s,s1;
int m,n;
int lcs(string s,string s1,int m,int n)
{
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                a[i][j]=0;
            else if(s[i-1]==s1[j-1])
            {
                a[i][j]=1+a[i-1][j-1];
            }
            else
            {
                a[i][j]=max(a[i][j-1],a[i-1][j]);
            }
        }
    }
    return a[m][n];
}
void print_lcs(int index)
{
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(s[i-1]==s1[j-1])
        {
            v.pb(s[i-1]);
            i--;
            j--;
        }
        else if(a[i][j-1]>a[i-1][j])
            j--;
        else
            i--;
    }
    for(int i=v.size()-1 ; i>=0; i--)
        cout << v[i];
    cout <<endl;
}
int main ()
{
    int t;
    sci(t);
    for(int cs=1; cs<=t; cs++)
    {
        cin >> s >> s1;
        m=s.length();
        n=s1.length();
        int ans=lcs(s,s1,m,n);
        cout << ans <<endl;
        print_lcs(ans);
        v.clear();
        mem(a,0);
        // cout <<ans <<endl;
    }
    return 0;
}
