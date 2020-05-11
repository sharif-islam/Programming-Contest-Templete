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

typedef struct tree
{
    int number;
    struct tree *leftchild;
    struct tree *rightchild;
}node;
node *root = NULL;
void insertnode(int value)
{
    node *tempnode;
    node *currentnode;
    node *parentnode;
    tempnode= (node *)malloc(sizeof(node));
    tempnode->number = value;
    tempnode->leftchild= NULL;
    tempnode->rightchild=NULL;
    if(root== NULL)
        root= tempnode;
    else
    {
        currentnode= root;
        parentnode= NULL;
        while(1)
        {
            parentnode= currentnode;
            if(value<= parentnode->number)
            {
                currentnode= currentnode->leftchild;
                if(currentnode==NULL)
                {
                    parentnode->leftchild= tempnode;
                    return ;
                }
            }
            else
            {
                currentnode= currentnode->rightchild;
                if(currentnode== NULL)
                {
                    parentnode->rightchild= tempnode;
                    return ;
                }
            }
        }
    }
}
void searchontree(int value)
{
    node *currentnode = root;
    int flag=0;
    while(1)
    {
        if(value==currentnode->number)
        {
            flag=1;
            break;
        }
        else if(value<=currentnode-> number)
            currentnode= currentnode->leftchild;
        else
            currentnode= currentnode->rightchild;
        if(currentnode== NULL)
            break;
    }
    if(flag)
        cout << currentnode->number <<" is found in tree "<<endl;
    else
        cout << value <<  " is not  fount in tree "<<endl;
}
void preorder( node *rootnode)
{
    if(rootnode== NULL)
        return ;
    printf("%d ",rootnode->number);
    preorder(rootnode->leftchild);
    preorder(rootnode->rightchild);
}
void inorder(node *rootnode)
{
    if(rootnode==NULL)
        return ;
    inorder(rootnode->leftchild);
    printf("%d ",rootnode->number);
    inorder(rootnode->rightchild);
}
void postorder(node *rootnode)
{
    if(rootnode== NULL)
        return ;
    postorder(rootnode->leftchild);
    postorder(rootnode->rightchild);
    printf("%d ",rootnode->number);
}
node *findminimum(node *rootnode)
{
    if(rootnode->leftchild==NULL)
        return rootnode;
    return findminimum(rootnode->leftchild);

}
//node *findmaximum(node *rootnode)
//{
//    if(rootnode->rightchild==NULL)
//        return rootnode;
//    return findmaximum(rootnode->rightchild);
//}
node *findmaximum(node *rootnode)
{
    if(rootnode==NULL)
        return rootnode;
    while(rootnode->rightchild!=NULL)
    {
        rootnode= rootnode->rightchild;
    }
    return rootnode;
}
node *deletenode(node *currentnode,int value)
{
    if(currentnode==NULL)
        return NULL;
    else if(value<currentnode->number)
        currentnode->leftchild=deletenode(currentnode->leftchild,value);
    else if(value>currentnode->number)
        currentnode->rightchild= deletenode(currentnode->rightchild,value);
    else
    {
        if(currentnode->leftchild== NULL && currentnode->rightchild==NULL)
            currentnode= NULL;
        else if(currentnode->leftchild==NULL )
            currentnode= currentnode->rightchild;
        else if(currentnode->rightchild== NULL)
            currentnode= currentnode->leftchild;
        else
        {
            node *tempnode= findminimum(currentnode->rightchild);
            currentnode->number = tempnode->number;
            currentnode->rightchild= deletenode(currentnode->rightchild,tempnode->number);
        }

    }
    return currentnode;
}
int main ()
{
    int n;
    pf("Enter number of element in a tree : ");
    cin >> n;
    int p;
    for(int i=1;i<=n;i++)
    {
        cin >> p;
        insertnode(p);
    }
    int q;
    pf("Enter a value ,which is present or not in the tree : ");
        cin >> p;
        searchontree(p);
    pf("preorder tree \n");
    preorder(root);
    pf("\n");
    pf("inorder tree \n");
    inorder(root);
    pf("\n");
    pf("posrorder tree \n");
    postorder(root);
    pf("\n");
    node *minvalue = findminimum(root);
    cout << "min value = " <<minvalue->number <<endl;
    node *maxvalue = findmaximum(root);
    cout << "max value = "<<maxvalue->number << endl;
    pf("Enter a value,which is delete from the tree :");
    cin >> q;
    deletenode(root,q);
    pf("delete one element from the tree,preorder tree is :\n");
    preorder(root);
    pf("\n");
    pf("delete one element from the tree,inorder tree is :\n");
    inorder(root);
    pf("\n");
    pf("delete one element from the tree,postorder tree is :\n");
    postorder(root);
    pf("\n");
     node *delafterminvalue = findminimum(root);
    cout << "det after min value = " <<delafterminvalue->number <<endl;
    node *delaftermaxvalue = findmaximum(root);
    cout << "del after max value = "<<delaftermaxvalue->number << endl;
    return 0;
}
/*
11
45 54 40 49 38 70 30 39 41 45 44
*/
