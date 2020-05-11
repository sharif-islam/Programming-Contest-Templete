#include<bits/stdc++.h>
#define  mem(a,b)            memset(a, b, sizeof(a) )
using namespace std;
int value[1000020];
void build_array(string pattern)
{
    int i=0;
    int index=0;
    int p=pattern.length();
    for(i=1;i<p;)
    {
        if(pattern[i]==pattern[index])
        {
            value[i]=index+1;
            i++;
            index++;
        }
        else
        {
            if(index!=0)
                index=value[index-1];
        else
        {
            value[index]=0;
            i++;
        }
    }
}
}
void KMP(string str,string pattern)
{
    int i=0;
    int j=0;
    while(i<str.length() && j<pattern.length())
    {
        if(str[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=value[j-1];
            else
            {
                i++;
            }
        }
      if(j==pattern.length()){
            cout << i-pattern.length()<<endl;
            j=value[j-1];
      }
    }
}
int main ()
{
    int n;
    string str,pattern;
    while(cin >> n){
    cin >> str >> pattern;
    string q=str;
    str=pattern;
    pattern=q;
    build_array(pattern);
    KMP(str,pattern);
//    for(int i=0;i<pattern.length();i++)
//        cout << value[i] << " ";
//    cout <<endl;
        cout <<endl;
    }
    return 0;
}

