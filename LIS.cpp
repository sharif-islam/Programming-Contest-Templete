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
int n;
int v[1000000];
int pos[1000000];
int result_pos[1000000];
int ceilpos(int v[],int l,int r, int key)
{
    while(r-l>1)
    {
        int m=l+(r-l)/2;
        if(v[m]>=key)
            r=m;
        else
            l=m;
    }
    return r;
}
 int LIS(int a[])
 {
    mem(result_pos,-1);
    v[0]=a[0];
    int length=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            continue;
        if(a[i]<v[0]){
            v[0]=a[i];
            pos[0]=i;
            //result_pos[0]=i;
        }
        else if(a[i]==v[length])
            continue;
        else if(a[i]>v[length]){
            v[++length]=a[i];
            pos[length]=i;
            result_pos[i]=pos[length-1];
            }
        else
        {
            int p=ceilpos(v,0,length,a[i]);
            v[p]=a[i];
            pos[p]=i;
            result_pos[i]=pos[p-1];
        }
    }
    return length;
 }
int main ()
{
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++){
    sci(n);
    vi vec;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans=LIS(a);
    cout << " ans "<< ans <<endl;
    int x=pos[ans];
    mem(pos,0);
    while(1)
    {
        if(result_pos[x]==-1){
                cout << a[x]<<endl;
            vec.pb(a[x]);
            break;}
            vec.pb(a[x]);
        cout << a[x] <<" ";
            x=result_pos[x];
    }
    vec.clear();
    }
    return 0;
}
