#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int status[(N>>5)+2] = {0};
    int i, j, sqrtN;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if((status[i>>5] & (1<< (i&31)))==0) // if((status[i/32] & (1<< (i%32)))==0)
        {
            for( j = i*i; j <= N; j += (i<<1) )
                status[j>>5] |= (1<< (j&31)); //status[j/32] = status[j/32] | (1<< (j%32));
        }
    }
    printf("2 ");
    for(i=3; i<=N; i+=2)
        if((status[i>>5] & (1<< (i&31)))==0)
            printf("%d ",i);
    return 0;
}
