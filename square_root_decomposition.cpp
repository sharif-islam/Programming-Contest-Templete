#include<bits/stdc++.h>
#define  pf                  printf
#define  sc                  scanf
#define  PI                  2*acos(0.0)
#define  fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define  mem(a,b)            memset(a, b, sizeof(a) )
#define  gcd(a,b)            __gcd(a,b)
#define  lcm(a,b)            (a*(b/gcd(a,b)))
#define  min3(a,b,c)         min(a,min(b,c))
#define  min4(a,b,c,d)       min(d,min(a,min(b,c)))
#define  max3(a,b,c)         max(a,max(b,c))
#define  max4(a,b,c,d)       max(d,max(a,max(b,c)))
#define  MX                  200005
#define  mxx                 1234567899
#define  mod                 1000000007
#define  inf                 (1<<28)
#define  all(v)              (v).begin(),(v).end()
#define  vSort(v)            sort(all(v))
#define  ub                  upper_bound
#define  lb                  lower_bound
#define  maxSort(v)          sort(all(v),greater<int>())
#define  Unique(v)           v.erase(unique(all(v)),v.end())
#define  MAX(x)              *max_element(all(x))
#define  MIN(x)              *min_element(all(x))
#define  sqr(x)              ((x)*(x))
#define  qube(x)             ((x)*(x)*(x))
#define  deci(n)             cout<<fixed<<setprecision(n)
#define  sci(n)              sc("%d",&(n))
#define  scii(x,y)           sc("%d %d",&(x),&(y))
#define  scl(x)              sc("%lld",&(x))
#define  scll(x,y)           sc("%lld %lld",&(x),&(y))
#define  yes                 cout<<"YES"<<endl
#define  no                  cout<<"NO"<<endl
#define  stringtoint(a)      atoi(a.c_str())
#define  vi                  vector<int>
#define  vl                  vector<long long int>
#define  hi                  pf(" HI \n")
#define  Case(x)             cout<<"Case "<<x<<": "
#define  pp                  pair<int,int>
#define  ppl                 pair<long long int,long long int>
#define  pb(x)               push_back(x)
#define  mp(x,y)             make_pair(x,y)
#define  F                   first
#define  S                   second
#define  check(n,pos)        (n & (1<<(pos)))
#define  biton(n,pos)        (n  (1<<(pos)))
#define  bitoff(n,pos)       (n & ~(1<<(pos)))
typedef  long long int       lli;
typedef  long long           ll;
typedef  unsigned long long int ulli;
int dx4[] = { 0 , 0 , -1 , 1 } ;
int dy4[] = { -1 , 1 , 0 , 0 } ;
bool valid( int r , int c , int x , int y ){
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ; return 0 ;}

using namespace std;
int segment[10000];
int segment_size;
int input[1000000];
void preprocess(int n)
{

    int current_segment= -1;
    segment_size = sqrt(n*1.0);
    for(int i=0;i<n;i++)
    {
        if(i%segment_size==0)
        {
            current_segment++;
        }
        segment[current_segment]+=input[i];
    }
}
int query(int l,int r)
{
    lli sum=0;
    while(l<r && l%segment_size!=0)
    {
        sum+=input[l];
        l++;
    }
    while((l+segment_size)<=r)
    {
        sum+=segment[l/segment_size];
        l+=segment_size;
    }
    while(l<=r)
    {
        sum+=input[l];
        l++;
    }
    return sum;
}

void update(int pos,int val)
{
    int segment_no = pos/segment_size;
    segment[segment_no]-=input[pos];
    segment[segment_no]+=val;
    input[pos]=val;

}
int main()
{
    int t;
    t =1;
    //cin >> t;
    for(int cs=1; cs<=t; cs++)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> input[i];
        preprocess(n);
        cout << query(3,7)<< endl;
        update(4,5);
        cout << query(3,7)<< endl;

    }

    return 0;
}


