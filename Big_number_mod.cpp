#include<bits/stdc++.h>
using namespace std;
int main ()
{
    char bhajjo[100000];
    int bhajok,bhagshesh=0,p;
    cin >> bhajjo;
    cin >> p;
    bhajok=abs(p);
    int l=strlen(bhajjo);
    if(bhajjo[0]=='-')
    {
        for(int i=1; i<l; i++)
        {
            bhagshesh=((bhagshesh*10)+(bhajjo[i]-'0'))%bhajok;
        }
    }
    else
    {
        for(int i=0; i<l; i++)
        {
        bhagshesh=((bhagshesh*10)+(bhajjo[i]-'0'))%bhajok;
        }
        cout << bhagshesh<<endl;
    }
    return 0;
}
