#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 50001;
vector<int> G[maxn];
int fa[maxn][16],d[maxn],ans[maxn];

void dfs1(int u,int p) {
    fa[u][0] = p;
    d[u] = d[p]+1;
    for(int i : G[u]) {
        if(i!=p) dfs1(i,u);
    }
}

void dfs2(int u,int p) {
    for(int i : G[u]) {
        if(i!=p) {
            dfs2(i,u);
            ans[u]+=ans[i];
        }
    }
}

int lca(int u,int v) {
    if(d[u]<d[v]) swap(u,v);
    for(int k=15;k>=0;k--) {
        if(d[u]-d[v] >= (1<<k)) u=fa[u][k];
    }
    if(u==v) return u;
    for(int k=15;k>=0;k--) {
        if(fa[u][k] != fa[v][k]) {
            u=fa[u][k];
            v=fa[v][k];
        }
    }
    return fa[u][0];
}

int main() {
    int n,k;
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++) {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    for(int k=1;k<=15;k++) {
        for(int u=1;u<=n;u++) {
            int v=fa[u][k-1];
            fa[u][k] = fa[v][k-1];
        }
    }
    for(int i=0;i<k;i++) {
        cin>>u>>v;
        int p = lca(u,v);
        ans[u]++;ans[v]++;ans[p]--;ans[fa[p][0]]--;
    }
    dfs2(1,0);
    int m = 0;
    for(int i=1;i<=n;i++) {
        if(ans[i]>=m) m=ans[i];
    }
    cout<<m<<endl;
    return 0;
}