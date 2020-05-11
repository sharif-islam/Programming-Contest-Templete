#include<bits/stdc++.h>
using namespace std;
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
#define SIZE 1000007
typedef  long long int       lli;
typedef  unsigned long long int ulli;
int dx4[] = { 0, 0, -1, 1 } ;
int dy4[] = { -1, 1, 0, 0 } ;
bool valid( int r, int c, int x, int y )
{
    if( x >= 1 && x <= r && y >= 1 && y <= c )
        return 1 ;
    return 0 ;
}
using namespace std;
vector <lli> prime;
bool mark[SIZE];
void primeSieve(lli n) {
    mark[0] = mark[1] = 1;
    prime.push_back(2);
    for (lli i=4;i<=n;i+=2) mark[i]=1;
    int sqrtn=sqrt(n);
    for(lli i=3;i<=sqrtn;i+=2){
        if(mark[i]==0){
            for(lli j=i*i;j<=n;j+=2*i)mark[j]=1;
        }
    }
    for(lli i=3;i<=n;i+=2)if(mark[i]==0)prime.push_back(i);
}
bool arr[SIZE];
int segmentedSieve(lli a,lli b)
{
    if(a==1)
        a++;
    lli sqrtn=sqrt(b);
    memset(arr,0,sizeof arr);
    for(lli i=0;i<prime.size()&&prime[i]<=sqrtn;i++)
    {
        lli p=prime[i];
        lli j= p*p;
        if(j<a)
            j=((a+p-1)/p)*p;
        for (;j<=b;j+=p)
        {
            arr[j-a]=1;
        }
    }
    lli res=0;
    for(lli i=a;i<=b;i++)
    {
        if(arr[i-a]==0)
            res++;
    }
    return res;
}
int main ()
{
    int t;
    primeSieve(100007);
    sci(t);
    for(int cs=1; cs<=t; cs++)
    {
        lli a,b;
        scll(a,b);
        lli ans =segmentedSieve(a,b);
        pf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}



