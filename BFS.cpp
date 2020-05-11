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
int vis[100000];
int level[100000];
vi level_element[1000];
queue<int>q;
vi node[1000];
int previous[100000];
int BFS(int u)
{
    vis[u]=1;
    level[u]=0;
    previous[u]=0;
    level_element[level[u]].pb(u);
    q.push(u);
    while(!q.empty())
    {
        int v= q.front();
        q.pop();
        for(int i=0; i<node[v].size(); i++)
        {
            if(vis[node[v][i]]==0)
            {
                level[node[v][i]]= level[v]+1;
                level_element[level[node[v][i]]].pb(node[v][i]);
                vis[node[v][i]]=1;
                previous[node[v][i]]=v;
                q.push(node[v][i]);
            }
        }
    }
}
int main ()
{
    int n,edge_number;
    cin >> n >> edge_number;
    int u,v;
    for(int i=1; i<=edge_number; i++)
    {
        cin >> u >> v;
        node[u].pb(v);
        node[v].pb(u);
    }
    BFS(1);
    for(int i=1;i<=n;i++)
        cout << i<< " node level is "<<level[i]<<endl;
    int n_level_element;
    cin >> n_level_element;
    cout << "those are level "<< n_level_element<< " element ";
    for(int i=0;i<level_element[n_level_element].size();i++)
        cout << level_element[n_level_element][i]<< " ";
    cout <<endl;
    int n_er_ager_node;
    cin >> n_er_ager_node;
    cout <<  n_er_ager_node<< " er ager node ";
    cout << previous[n_er_ager_node]<<endl;
    return 0;
}
