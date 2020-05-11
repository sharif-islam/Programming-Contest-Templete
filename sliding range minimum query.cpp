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
deque< pair<int,int> >dq;
vi v;
vi range_min(int a[],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        while(!dq.empty() && dq.front().F>= a[i])
        {
            dq.pop_front();
        }
        dq.push_front(mp(a[i],i));
      while(!dq.empty() && dq.back().S<=i-k)
        dq.pop_back();
    if(i>=k-1)
    {
        v.pb(dq.back().F);
    }

    }
    return v;

}
int main ()
{
    int n,k;
    cin >> n>> k;
    int p;
    int a[n+2];

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
   vi ans = range_min(a,n,k);
    for(int i=0;i<ans.size();i++)
        cout << ans[i]<<  " ";
    cout <<endl;

    return 0;
}
/*
6 3
10 2 5 9 6 4
output : 2 2 5 4
*/
