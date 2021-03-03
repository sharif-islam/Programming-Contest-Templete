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
int dx4[] = { 0, 0, -1, 1 } ;
int dy4[] = { -1, 1, 0, 0 } ;
bool valid( int r, int c, int x, int y )
{
    if( x >= 1 && x <= r && y >= 1 && y <= c ) return 1 ;
    return 0 ;
}

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    orderset<int> s ;
    orderset<int>::iterator it ;
    s.insert(5); // insert a number
    s.insert(3);
    s.insert(2);
    s.insert(6);
    s.insert(10);
    s.insert(11);
    s.erase(5);  // delete a number

    if(s.empty()) // set empty or not
        cout << " not empty "<< endl;

    s.clear();  // delete all element from the list

    s.size();   //how many distinct number in a list

    *s.begin();   // find small element in the list

    *s.rbegin(); // find greatest number in the list
    // or
    // auto pos = s.end();
    // pos--;
    // *pos;
    int x=5;
    if(s.find(x)==s.end())  // find a number in this list or not
        cout << "not fount "<< endl;
    else
        auto pos = s.find(x);
    s.order_of_key(7);  // how many numbers are smaller than a given number 7

    s.order_of_key(7+1);  // how many numbers are smaller than or equal to a given number 7

    int pos = s.size()- s.order_of_key(7);  // how many numbers are greater or equal to a given number 7
    int k= 3;
    int val = *s.find_by_order(k);  // show (k+1)th number in the list

    s.erase( *s.find_by_order(k));   // delete (k+1)th element from list

    s.erase(*s.begin());  // delete first element from list

    s.erase(*s.rbegin()); // delete last element from list


    for(auto it=s.begin();it!=s.end();it++)  // print all element in ascending order
        cout << (*it) << " ";
        cout << endl;

    cout << *s.lower_bound(k) << endl; // find smallest number which is greater than or equal to given number

    cout << *s.upper_bound(k) << endl; // find smallest number which is greater than a given number

    return 0;
}



