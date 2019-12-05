//城市规划
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 5e4 + 10;
const int K = 1e2 + 10;
int n, m, k, u, v, w;
int num[N];
ll dp[N][K], tmp[K];//dp[x][y]表示的是以x为根节点的子树中选择Y个重要子节点所需的最小路径
vector<P> E[N];
bool ok[N];
void dfs(int u, int fa)
{
	dp[u][0] = 0;
	if (ok[u])//若这个点就是一个重要节点
	{
		num[u] = 1;//因为该节点是重要节点，所以以该节点的子树一定有一个重要节点
		dp[u][1] = 0; //在以点U为子树的根节点中挑选一个重要节点所需的长度为0；
	}
	for (int i = 0; i < E[u].size(); ++i)
	{
		int v = E[u][i].fi, w = E[u][i].se;
		if (v == fa)
			continue;
		dfs(v, u);
		int sum = min(k, num[u] + num[v]), mn = min(k, num[u]);
		for (int p = 0; p <= sum; ++p)//
			tmp[p] = dp[u][p];
		for (int p = 0; p <= mn; ++p)		   //其余子树p个
			for (int q = 0; p + q <= sum; ++q) //当前子树q个
				tmp[p + q] = min(tmp[p + q], dp[u][p] + dp[v][q] + 1ll * q * (k - q) * w);
		for (int p = 0; p <= sum; ++p)
			dp[u][p] = min(dp[u][p], tmp[p]);
		num[u] += num[v];
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	memset(dp, INF, sizeof dp);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &v);
		ok[v] = 1;
	}
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(P(v, w));
		E[v].push_back(P(u, w));
	}
	dfs(1, -1);
	//for(int i=1;i<=n;++i)
	//for(int j=1;j<=k;++j)
	//printf("dp[%d][%d]:%lld\n",i,j,dp[i][j]);
	printf("%lld\n", dp[1][k]);
	return 0;
}
