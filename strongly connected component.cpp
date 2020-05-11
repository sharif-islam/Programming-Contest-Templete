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
bool valid( int r , int c , int x , int y ){
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ; return 0 ;}

using namespace std;

vector<int>g[100000],gr[100000];
vector<int>order,component;
int vis[1000000];
void DFS1(int v)
{
    vis[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        if(vis[g[v][i]]==0)
            DFS1(g[v][i]);
    }
    order.pb(v);
}
void DFS2(int v)
{
    vis[v]=1;
    component.pb(v);
    for(int i=0;i<gr[v].size();i++)
    {
        if(vis[gr[v][i]]==0)
            DFS2(gr[v][i]);
    }
}
int main ()
{
    int node,edge;
    cin >> node >> edge;
    int x,y;
    for(int i=1;i<=edge;i++)
    {
        cin >> x>> y;
        g[x].pb(y);
        gr[y].pb(x);
    }
    mem(vis,0);
    for(int i=1;i<=node;i++)
    {
        if(vis[i]==0)
            DFS1(i);
    }
    mem(vis,0);
    for(int i=0;i<node;i++)
    {
        int v = order[node-1-i];
        if(vis[v]==0)
        {
            DFS2(v);
            for(int j=0;j<component.size();j++)
                cout << component[j]<<  " ";
            cout <<endl;
            component.clear();
        }
    }
    return 0;
}
