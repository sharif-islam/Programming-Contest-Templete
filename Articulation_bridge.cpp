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
vi graph[200005];
int vis[200005];
int start[200005];
int par[200005];
int low[200005];
int val=0;
vector<pp> vec;
void tarjan(int u)
{
    vis[u]=1;
    val++;
    start[u]=val;
    low[u]=val;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(par[u]==v)
            continue;
        if(vis[v]==0)
        {
            par[v]=u;
            tarjan(v);
            low[u] = min(low[u],low[v]);
            if(low[v]>start[u])
            {
                int x = u;
                int y = v;
                if(x>y)
                    swap(x,y);
                vec.pb(mp(x,y));
            }
        }
        else
        {
            low[u] = min(low[u],start[v]);
        }
    }
}
void  Articulation_bridge(int node)
{
    for(int i=1; i<=node; i++)
        par[i] = -1;
    for(int i=1; i<=node; i++)
    {
        if(vis[i]==0)
        {
            tarjan(i);
        }
    }
}
int main ()
{
    int t;
    cin >> t;
    for(int cs=1; cs<=t; cs++)
    {
        int node,edge;
        cin>> node >> edge;
        int u,v;
        for(int i=1; i<=edge; i++)
        {
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        Articulation_bridge(node);
        cout <<"Case "<<cs <<":"<<endl;
        vSort(vec);
        Unique(vec);
        cout << vec.size()<< " critical links"<<endl;
        for(int j=0;j<vec.size();j++)
            cout << vec[j].F << " - "<<vec[j].S<< endl;
        for(int i=0; i<=node; i++)
        {
            vis[i]=0;
            graph[i].clear();
            start[i]=1;
        }
        vec.clear();
    }
    return 0;
}



