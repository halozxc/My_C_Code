#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
class reader {
public:
    static int read() {
        int x;
        scanf("%d", &x);
        return x;
    }
};
struct tree{
    static const int Maxn = 1e6 + 7;
    int tol;
    int head[Maxn];
    vector<int> edge[Maxn];
    tree()
    {
        memset(head, 0, sizeof(head));
        tol = 0;
    }
    void addEdge(int u, int v);
    void addHead(int value);
    int findRoot();
};

struct DP{
    tree T;
    int func[tree::Maxn][2];
public:
    DP();
   void input(int n);
   void output();
private:

    void solDP(int rt);
};
DP::DP() {
        memset(func, 0, sizeof(func));
}
int tree::findRoot() {
    int vis[Maxn];
    memset(vis,0, sizeof(vis));
    for(int i=0;i < tol; ++i)
        for(int j = 0; j < edge[i].size(); ++j)
            vis[edge[i][j]] = 1;
    for(int i = 0; i < tol; ++i) {
        if(vis[i] == 0){
            return i;
        }
    }
return 0;
}
void DP::solDP(int rt) {
    for(int i = 0; i < T.edge[i].size(); ++i)
    {
        int pos = T.edge[rt][i];
        solDP(pos);
        func[rt][0] += max(func[pos][1],func[pos][0]);
        func[rt][1]+=func[pos][0];
    }
    func[rt][1] += T.head[rt];
}
void tree::addEdge(int u, int v) {
    edge[u].push_back(v);
}
void tree::addHead(int value) {
    head[++tol] = value;
}
void DP::input(int n) {
    reader rd;
    for(int i = 0; i < n; i++) T.addHead(rd.read());
    for(int i = 1; i < n; i++) T.addEdge(rd.read(), rd.read());
}

void DP::output() {
    int rt;
    solDP(rt = T.findRoot());
    cout<<max(func[rt][0], func[rt][1])<<'\n';
}

int main() {
    reader rd;
    int n = rd.read();
    DP a;
    a.input(n);
    a.output();
    return 0;
}