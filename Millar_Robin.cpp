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
ulli mulmod(lli a,lli b,lli m)
{
    lli res=0;
    a=a%m;
    while(b)
    {
        if(b& 1)
            res=(res+a)%m;
        a= (2*a)%m;
        b >>=1;
    }
    return res;
}
lli bigmod(lli b,lli p,lli m)
{
    if(p==0)
        return 1;
    lli x=bigmod(b,p/2,m);
    x=mulmod(x,x,m)%m;
    if((p&1)!=0)
        x=mulmod(x,b,m)%m;
    return x;
}
bool test(lli n,lli m,lli k)
{
    lli a;
    a = rand() % (n-1)+1;
    lli b1,b0= bigmod(a,m,n);
    if(b0==1 || b0== n-1 )
        return true;
    else
    {
        for(int i=1; i<k; i++)
        {
            b0=mulmod(b0,b0,n);
            if(b0== n-1)
                return  true;
        }
    }
    return false;
}
int main ()
{
    lli n;
    int t;
    cin >> t;
    for(int cs=1; cs<=t; cs++)
    {
        cin >> n;
        lli ami=n;
        if(n==2)
        {
            cout << "YES"<<endl;
            continue;
        }
        if(n%2==0)
        {
            cout << "NO"<<endl;
            continue;
        }
        lli p=n-1;
        lli k=0,m;
        while(p%2==0)
        {
            k++;
            p/=2;
        }
        m=p;
        int flag=0;
        for(int tt=1; tt<=5; tt++)
        {
            bool tot= test(ami,m,k);
            if(tot)
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout << "NO"<<endl;
        else
            cout << "YES"<<endl;
    }
    return 0;
}
