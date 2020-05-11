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
int dx4[] = { 0 , 0 , -1 , 1 } ;
int dy4[] = { -1 , 1 , 0 , 0 } ;
bool valid( int r, int c, int x, int y )
{
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ;
    return 0 ;
}
using namespace std;
vector<pp>node;
int vis[1000][1000];
int level[1000][1000];
queue<pp>q;
pair<int,int>p;
int xxx,yyy;
int BFS(int x,int y)
{
    vis[x][y]=1;
    level[x][y]=0;
    q.push(mp(x,y));
    while(!q.empty())
    {
        p=q.front();
        int a=p.F;
        int b=p.S;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx= a+ dx4[i];
            int yy= b+ dy4[i];
            if(vis[xx][yy]==0 && valid(4,4,xx,yy))
            {
                level[xx][yy]=level[a][b]+1;
                vis[xx][yy]=1;
                q.push(mp(xx,yy));
                if(xx==xxx && yy==yyy)
                {
                    return level[xx][yy];
                }
            }
        }
    }
}
int main ()
{
    int x,y;
    cin >> x >> y;
    cin >> xxx>> yyy;
    int ans=BFS(x,y);
    cout << ans <<endl;
    return 0;
}


