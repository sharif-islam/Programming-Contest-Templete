#include<bits/stdc++.h>

#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  MAX                 109
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
bool valid( int r , int c , int x , int y ){
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ; return 0 ;}

using namespace std;
#define sz 105
int cap[sz][sz];
int flow[sz][sz];
bool vis[sz];
int par[sz];
int n;
bool BFS(int src,int sink)
{
    mem(vis,0);
    vis[src]=1;
    par[src]= -1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(!vis[v] && (cap[u][v]-flow[u][v])>0)
            {
                q.push(v);
                vis[v]=1;
                par[v]=u;
            }
        }
    }
    return vis[sink];
}

int maxFlow(int src,int sink)
{
    int u;
    int maxflow=0;
    int mnpath;
    while(BFS(src,sink))
    {
        mnpath = mod;
        for(int v=sink;v!=src;v=par[v])
        {
            u= par[v];
            mnpath= min(mnpath,cap[u][v]-flow[u][v]);
        }
        for(int v=sink;v!=src;v=par[v])
        {
            u= par[v];
            flow[u][v]+=mnpath;
            flow[v][u]-=mnpath;
        }
        maxflow+=mnpath;
    }
    return maxflow;
}
int main ()
{
    int t;
    cin >> t;
    for(int cs=1;cs<=t;cs++){
    int src,sink,e;
    cin >> n;
    cin >> src >> sink >> e;
    int u,v,c;
    mem(cap,0);
    mem(flow,0);
    for(int i=1;i<=e;i++)
    {
        cin >> u >> v >> c;
        cap[u][v]+=c;
        cap[v][u]+=c;
    }
    int ans = maxFlow(src,sink);
    cout << "Case "<<cs<< ": "<<ans <<endl;
    }
    return 0;
}
/*
6
1 6 7
1 2 2
1 3 5
2 4 3
3 4 3
2 5 1
5 6 4
4 6 4
*/
