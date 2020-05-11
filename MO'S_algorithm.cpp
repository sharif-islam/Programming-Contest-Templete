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
const int maxn = 200002;
int ans[maxn],a[maxn],sum,k;
struct Query
{
    int index,l,r;
    bool operator < (const Query &other) const
    {
        int block_own  = l/k;
        int block_other = other.l/k;
        if(block_own == block_other )
            return r<other.r;
        return block_own < block_other;
    }
} query[maxn];
void add(int index)
{
    sum+=a[index];
}
void remove(int index)
{
    sum-=a[index];
}
int main ()
{
    int n;
    cin >> n ;
    k =sqrt(n);
    for(int i=0; i<n; i++)
        cin >>a[i];
    int q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        cin >> query[i].l >> query[i].r;
        query[i].index=i;
    }
    sort( query, query+q);
    int r= -1;
    int l = 0;
    for(int i=0; i<q; i++)
    {
        while(r<query[i].r) add(++r);
        while(l<query[i].l) remove(l++);
        while(r>query[i].r) remove(r--);
        while(l>query[i].l) add(--l);
        ans[query[i].index]=sum;
    }
    for(int i=0; i<q; i++)
        cout << ans[i]<< " ";
    cout <<endl;
    return 0;
}
