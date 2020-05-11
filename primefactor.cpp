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
bool mark[2000005];
vector<int>prime;
void primeee(int n)
{
    mark[1]=1;
    for(int i=4; i<=n; i+=2)
        mark[i]=1;
    for(int i=3; i<=sqrt(n); i+=2)
    {
        if(mark[i]==0)
        {
            for(int j=(i*i); j<=n; j+=(i+i))
                mark[j]=1;
        }
    }
}
vector< pp >v;
void primefactor(int n)
{
    int power=0;
    for(int i=0; i<prime.size() && (prime[i]*prime[i])<=n; i++)
    {
        while(n%prime[i]==0) n/=prime[i],power++;
        v.pb(mp(prime[i],power));
        power=0;
    }
    if(n>1)
        v.pb(mp(n,1));
}
int main ()
{
    int p=2000000;
    primeee(p);
    prime.pb(2);
    for(int i=3; i<=p; i+=2)
    {
        if(mark[i]==0)
            prime.pb(i);
    }
    int n;
    cin >> n;
    primefactor(n);
    cout << v.size()<<endl;
    for(int i=0; i<v.size(); i++)
        cout << v[i].F << " "<< v[i].S<<endl;
    return 0;
}
