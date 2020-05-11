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
int vis[1000000];
int node;
int mx_node_vis= -1;
int start[200005];
int last[200005];
int val=0;
void DFS_VISIT(int node)
{
    vis[node]=1;
    val++;
    start[node]=val;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(vis[graph[node][i]]==0)
            DFS_VISIT(graph[node][i]);
    }
    val++;
    last[node]=val;
    return ;
}
int DFS(int node)
{
    int tot=0;
    for(int i=1; i<=node; i++)
    {
        if(vis[i]==0){
                tot++;
            DFS_VISIT(i);}
    }
    return tot;
}
int main ()
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
    int ans=DFS(node);
    cout << ans <<endl;
    return 0;
}


