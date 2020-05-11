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

int a[1001];
int pos[1001][1001];
int main ()
{
    int t;
    sci(t);
    string s;
    for(int cs=1; cs<=t; cs++)
    {
        cin >> s;
        int n=s.length();
        mem(pos,0);
        for(int i=0; i<n; i++)
        {
            pos[i][i]=1;
        }
        for(int length=2; length<=n; length++)
        {
            for(int i=0; i<=n-length; i++)
            {
                int j= length-1+i;
                if(length==2)
                {
                    if(s[i]==s[j])
                    {
                        pos[i][j]=1;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(pos[i+1][j-1]==1)
                        {

                            pos[i][j]=1;
                        }
                    }
                }
            }
        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout << pos[i][j]<< " ";
//            }
//            cout <<endl;
//        }
        for(int i=0; i<n; i++)
        {
            if(pos[0][i]==1)
                a[i]=0;
            else
            {
                a[i]=MAX;
                for(int j=0; j<i; j++)
                {
                    if(pos[j+1][i]==1 && 1+a[j]<a[i])
                        a[i]=1+a[j];
                }
            }
        }

        cout <<"Case " <<cs<< ": "<<a[n-1]+1<<endl;
        mem(a,0);
        mem(pos,0);
    }

    return 0;
}


