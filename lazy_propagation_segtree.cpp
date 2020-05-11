#include<bits/stdc++.h>

#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  MAX                 91234567234567899
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

lli segtree[1000000];
lli lazy[1000000];
lli input[1000000];
lli tot[5];
void construct_tree(lli input[],lli low,lli high,lli pos)
{
    if(low==high)
    {
        segtree[pos]=input[low];
        return ;
    }
    lli mid=low+((high-low)/2);
    construct_tree(input,low,mid,2*pos+1);
    construct_tree(input,mid+1,high,2*pos+2);
    segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}
void pushdown(lli low,lli high,lli pos)
{
    if(lazy[pos]!=0)
    {
        segtree[pos]+=lazy[pos];
        if(low!=high){
        lazy[2*pos+1]+=lazy[pos];
        lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    else
        return ;
}
void lazy_tree(lli st,lli en,lli value,lli low,lli high,lli pos)
{
    if(low>high)
        return ;
    pushdown(low,high,pos);
    if(en<low || st>high)
        return ;
    if(low>=st && high<=en)
    {
        segtree[pos]+=value;
        if(low!=high){
        lazy[2*pos+1]+=value;
        lazy[2*pos+2]+=value;
        }
        return ;
    }
    lli mid=low+((high-low)/2);
    lazy_tree(st,en,value,low,mid,2*pos+1);
    lazy_tree(st,en,value,mid+1,high,2*pos+2);
    segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}
lli rangequery(lli st,lli en,lli low,lli high,lli pos)
{
    if(low>high)
        return MAX;
    pushdown(low,high,pos);
    if(en<low || st>high)
        return MAX;
    if(low>=st && high<=en)
    {
        return segtree[pos];
    }
    lli mid=low+((high-low)/2);
    return min(rangequery(st,en,low,mid,2*pos+1),
            rangequery(st,en,mid+1,high,2*pos+2));
}
int main ()
{
    lli t,p,x,y,r;
    lli n,q;
    scl(t);
    for(int tt=1; tt<=t; tt++)
    {
        mem(segtree,0);
        mem(lazy,0);
        mem(input,0);
        scll(n,q);
        for(int i=0;i<n;i++)
            scl(input[i]);
        construct_tree(input,0,n-1,0);
        pf("Case %d:\n",tt);
        for(int i=1; i<=q; i++)
        {
            scl(p);
            if(p==0)
            {
                scll(x,y);
                scl(r);
                lazy_tree(x,y,r,0,n-1,0);
            }
            else
            {
                scll(x,y);
                lli ppp=rangequery(x,y,0,n-1,0);
                pf("%lld\n",ppp);
            }
        }
    }
    return 0;
}
