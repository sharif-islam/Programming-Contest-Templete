#include<bits/stdc++.h>

#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  MAX                 92387654567899987
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

lli segment_tree[1000000];
lli a;
void construct_tree(lli input[],lli low,lli high,lli pos)
{
    if(low==high)
    {
        segment_tree[pos]=input[low];
        return ;
    }
    lli mid=(low+high)/2;
    construct_tree(input,low,mid,2*pos+1);
    construct_tree(input,mid+1,high,2*pos+2);
    segment_tree[pos]=min(segment_tree[2*pos+1],segment_tree[2*pos+2]);
}
void update(int low,int high,int pos,int up_pos,int v)
{
    if(up_pos>high || up_pos<low)
        return;
    if(up_pos<=low && up_pos>=high)
    {
        segment_tree[pos]+=v;
        return ;
    }
    int mid=(low+high)/2;
    update(low,mid,2*pos+1,up_pos,v);
    update(mid+1,high,2*pos+2,up_pos,v);
    segment_tree[pos]=(segment_tree[2*pos+1]+segment_tree[2*pos+2]);
}
lli range_max_query(lli qlow,lli qhigh,lli low,lli high,lli pos)
{
    if(low>=qlow && high<=qhigh)
    {
        return segment_tree[pos];
    }
    if(qlow>high || qhigh <low )
        return MAX;
    int mid=(low+high)/2;
    return min(range_max_query(qlow,qhigh,low,mid,2*pos+1),
               range_max_query(qlow,qhigh,mid+1,high,2*pos+2));
}
int main ()
{
    lli n,q;
    lli t;
    scl(t);
    for(lli cs=1; cs<=t; cs++)
    {
        pf("Case %lld:\n",cs);
        scl(n);
        scl(q);
        lli input[n+2];
        mem(input,0);
        mem(segment_tree,0);
        lli x,y;
        int up_pos;
        int value=0;
        for(int i=0; i<n; i++)
            scl(input[i]);
        construct_tree(input,0,n-1,0);
        // update(0,n-1,0,up_pos,value);
        for(int i=0; i<(pow(2,ceil(log(n)))*2-1); i++)
            cout << segment_tree[i] << " ";
        cout <<endl;
        for(int i=1; i<=q; i++)
        {
            scll(x,y);
            pf("%lld\n",range_max_query(x-1,y-1,0,n-1,0));
        }
    }
    return 0;
}

