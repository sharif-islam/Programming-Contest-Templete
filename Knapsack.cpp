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
int w[1000];
int v[1000];
int a[1000][1000];
int knapsack(int n,int c)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(j>=w[i])
                a[i][j]= max(a[i-1][j],v[i]+a[i-1][j-w[i]]);
            else
                a[i][j]=a[i-1][j];
        }
    }
}
int main ()
{
    int n;
    int c;
    while(1)
    {
       sci(c);
       sci(n);
        if(c==0 && n==0)
            break;
        for(int i=1; i<=n; i++)
        {
            sci(w[i]);
           sci(v[i]);
        }

        knapsack(n,c);
//        for(int i=0; i<=n; i++)
//        {
//            for(int j=0; j<=c; j++)
//                cout << a[i][j] << " ";
//            cout <<endl;
//        }


    int i;
    for(i=0;i<=c;i++)
    {
        //cout << i<< " " <<a[n][i]<< " tot "<<endl;
        if(a[n][i]>=a[n][c])
            break;
    }
       pf("%d %d\n",i,a[n][c]);
        mem(v,0);
        mem(a,0);
        mem(w,0);
    }

    return 0;
}



