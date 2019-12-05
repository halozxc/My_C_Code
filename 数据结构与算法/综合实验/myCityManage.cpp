#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll infinity=0x3f3f3f3f3f3f3fll;
const int N=5e4+10;
const int K=1e2 +10;
int n,m,k,u,v,w;
int n,m,k,u,v,dis;
int contain[N];
ll dp[N][K];
vector<Edge> E[N];
int imp[N];
struct Edge{
    int des;
    ll second;
    Edge(int x,int y){
        des=x;
        second=y;
    }
};
void dfs(int u,int father){
    dp[u][0]=0;
    if(imp[u]){
        contain[u]=1;
        dp[u][1]=0;
    }
    for(int i=0;i<E[u].size();++i){
        int v=E[u][i].des,w=E[u][i].second;
        if(v==father){
            continue;
        }
        dfs(v,u);
        contain[u]+=contain[v];
        dp[u][k]=min(dp[v][k],dp[u][k]);
        for(int j=min(k,contain[u]);j>=1;j--){
            for(int l=1;l<=min(j,contain[v]);l++){
                dp[u][j]=min(dp[u][j],dp[u][j-l]+dp[v][l]+1ll*w*l*(k-l));
            }
        }

    }
}
int main()
{
    cin>>n>>m>>k;
    memset(dp,infinity,sizeof dp);
    memset(imp,0,sizeof imp);
for(int i=1;i<=m;++i){
    scanf("%d",&v);
    imp[v]=1;
}
for(int i=2;i<=n;++i)
{
    scanf("%d%d%d",&u,&v,&w);
    E[u].push_back(new Edge(v,w));
    E[v].push_back(new Edge(u,w));
}
dfs(2,-1);
printf("%lld\n",dp[1][k]);
return 0;
}