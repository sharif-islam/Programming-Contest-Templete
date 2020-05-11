#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii>g[105];
#define inf 9999
int dis[105];
int node,edge;
void bfs(int src)
{
    for(int i=0;i<node;i++)
        dis[i]=inf;
    dis[src]=0;
    deque<int>dq;
    int p;
    dq.push_back(src);
    while(!dq.empty())
    {
        p=dq.front();
        dq.pop_front();
        for(int i=0;i<g[p].size();i++)
        {
            if(dis[g[p][i].first]>dis[p]+g[p][i].second)
            {
                dis[g[p][i].first]=dis[p]+g[p][i].second;
                if(g[p][i].second==0)
                    dq.push_front(g[p][i].first);
                else
                    dq.push_back(g[p][i].first);
            }
        }
    }
    for(int i=0;i<node;i++)
       cout << dis[i]<<" ";
    cout <<endl;
}
int main ()
{
    int u,v,cost;
    cin >>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin >>u >>v >>cost;
        g[u].push_back(make_pair(v,cost));
        g[v].push_back(make_pair(u,cost));
    }
    bfs(0);
    return 0;
}
