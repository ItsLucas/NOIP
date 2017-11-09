/*
|Dijkstra算法|
|适用于边权为正的有向图或者无向图|
|求从单个源点出发，到所有节点的最短路|
|优化版：时间复杂度 O(elbn)|
|16/11/05ztx, thanks to chaixiaojun|
*/

struct node {
    int v, len;
    node(int v = 0, int len = 0) : v(v), len(len) {}
    bool operator<(const node &a) const { //  距离从小到大排序
        return len > a.len;
    }
};

vector<node> G[maxn];
bool vis[maxn];
int dis[maxn];

int dijkstra(int s, int e) {
    priority_queue<node> Q;
    Q.push(node(s, 0)); //  加入队列并排序
    dis[s] = 0;
    while (!Q.empty()) {
        node now = Q.top(); //  取出当前最小的
        Q.pop();
        int v = now.v;
        if (vis[v])
            continue; //  如果标记过了, 直接continue
        vis[v] = true;
        for (int i = 0; i < G[v].size(); i++) { //  更新
            int v2 = G[v][i].v;
            int len = G[v][i].len;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                Q.push(node(v2, dis[v2]));
            }
        }
    }
    return dis[e];
}
/*
    |SPFA算法|
    |队列优化|
    |可处理负环|
*/

vector<node> G[maxn];
bool inqueue[maxn];
int dist[maxn];

void Init() {
    for (int i = 0; i < maxn; ++i) {
        G[i].clear();
        dist[i] = INF;
    }
}
int SPFA(int s, int e) {
    int v1, v2, weight;
    queue<int> Q;
    memset(inqueue, false, sizeof(inqueue)); // 标记是否在队列中
    memset(cnt, 0, sizeof(cnt));             // 加入队列的次数
    dist[s] = 0;
    Q.push(s);         // 起点加入队列
    inqueue[s] = true; // 标记
    while (!Q.empty()) {
        v1 = Q.front();
        Q.pop();
        inqueue[v1] = false;                     // 取消标记
        for (int i = 0; i < G[v1].size(); ++i) { // 搜索v1的链表
            v2 = G[v1][i].vex;
            weight = G[v1][i].weight;
            if (dist[v2] > dist[v1] + weight) { // 松弛操作
                dist[v2] = dist[v1] + weight;
                if (inqueue[v2] == false) { // 再次加入队列
                    inqueue[v2] = true;
                    // cnt[v2]++;  // 判负环
                    // if(cnt[v2] > n) return -1;
                    Q.push(v2);
                }
            }
        }
    }
    return dist[e];
}

/*
    不断的将s的邻接点加入队列，取出不断的进行松弛操作，直到队列为空

    如果一个结点被加入队列超过n-1次，那么显然图中有负环
*/
/*
    |Floyd算法|
    |任意点对最短路算法|
    |求图中任意两点的最短距离的算法|
*/

for (int i = 0; i < n; i++) { //  初始化为0
    for (int j = 0; j < n; j++)
        scanf("%lf", &dis[i][j]);
}
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}

/*
    |埃式筛法|
    |快速筛选素数|
    |16/11/05ztx|
*/

int prime[maxn];
bool is_prime[maxn];

int sieve(int n) {
    int p = 0;
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) { //  注意数组大小是n
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = i + i; j <= n; j += i) //  轻剪枝，j必定是i的倍数
                is_prime[j] = false;
        }
    }
    return p; //  返回素数个数
}

/*
    |快速幂|
    |16/11/05ztx|
*/

typedef long long LL; //  视数据大小的情况而定

LL powerMod(LL x, LL n, LL m) {
    LL res = 1;
    while (n > 0) {
        if (n & 1) //  判断是否为奇数，若是则true
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1; //  相当于n /= 2;
    }
    return res;
}

/*
    |合并节点操作|
    |16/11/05ztx, thanks to chaixiaojun|
*/

int father[maxn]; //  储存i的father父节点

void makeSet() {
    for (int i = 0; i < maxn; i++)
        father[i] = i;
}

int findRoot(int x) {              //  迭代找根节点
    int root = x;                  // 根节点
    while (root != father[root]) { // 寻找根节点
        root = father[root];
    }
    while (x != root) {
        int tmp = father[x];
        father[x] = root; // 根节点赋值
        x = tmp;
    }
    return root;
}

void Union(int x, int y) { //  将x所在的集合和y所在的集合整合起来形成一个集合。
    int a, b;
    a = findRoot(x);
    b = findRoot(y);
    father[a] = b; // y连在x的根节点上   或father[b] = a为x连在y的根节点上；
}

/*
    在findRoot(x)中：
    路径压缩 迭代 最优版
    关键在于在路径上的每个节点都可以直接连接到根上
*/

/*
    |Kruskal算法|
    |适用于 稀疏图 求最小生成树|
    |16/11/05ztx thanks to wangqiqi|
*/

/*
    第一步：点、边、加入vector，把所有边按从小到大排序
    第二步：并查集部分 + 下面的code
*/

void Kruskal() {
    ans = 0;
    for (int i = 0; i < len; i++) {
        if (Find(edge[i].a) != Find(edge[i].b)) {
            Union(edge[i].a, edge[i].b);
            ans += edge[i].len;
        }
    }
}

/*
    |01背包|
    |完全背包|
    |多重背包|
    |16/11/05ztx|
*/

//  01背包：

void bag01(int cost, int weight) {
    for (i = v; i >= cost; --i)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

//  完全背包：

void complete(int cost, int weight) {
    for (i = cost; i <= v; ++i)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

//  多重背包：

void multiply(int cost, int weight, int amount) {
    if (cost * amount >= v)
        complete(cost, weight);
    else {
        k = 1;
        while (k < amount) {
            bag01(k * cost, k * weight);
            amount -= k;
            k += k;
        }
        bag01(cost * amount, weight * amount);
    }
}

// other

int dp[1000000];
int c[55], m[110];
int sum;

void CompletePack(int c) {
    for (int v = c; v <= sum / 2; ++v) {
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void ZeroOnePack(int c) {
    for (int v = sum / 2; v >= c; --v) {
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void multiplePack(int c, int m） {
    if (m * c > sum / 2)
        CompletePack(c);
    else {
        int k = 1;
        while (k < m) {
            ZeroOnePack(k * c);
            m -= k;
            k <<= 1;
        }
        if (m != 0) {
            ZeroOnePack(m * c);
        }
    }
}

/*
    |最长上升子序列|
    |状态转移|
    |16/11/05ztx|
*/
/* 
    优化方法：
    dp[i]表示长度为i+1的上升子序列的最末尾元素  
    找到第一个比dp末尾大的来代替 
*/

void solve() {
    for (int i = 0; i < n; ++i) {
        dp[i] = INF;
    }
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp, dp + n, a[i]) = a[i]; //  返回一个指针
    }
    printf("%d\n", *lower_bound(dp, dp + n, INF) - dp;  
}

/*
    |求最长公共子序列|
    |递推形式|
    |16/11/05ztx|
*/

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
}

/*
    线段树 点更新
    |16/12/07ztx|
*/

struct node
{
    int left, right;
    int max, sum;
};

node tree[maxn << 2];
int a[maxn];
int n;
int k = 1;
int p, q;
string str;

void build(int m, int l, int r)//m 是 树的标号
{
    tree[m].left = l;
    tree[m].right = r;
    if (l == r) {
        tree[m].max = a[l];
        tree[m].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(m << 1, l, mid);
    build(m << 1 | 1, mid + 1, r);
    tree[m].max = max(tree[m << 1].max, tree[m << 1 | 1].max);
    tree[m].sum = tree[m << 1].sum + tree[m << 1 | 1].sum;
}

void update(int m, int a, int val)//a 是 节点位置， val 是 更新的值（加减的值）
{
    if (tree[m].left == a && tree[m].right == a) {
        tree[m].max += val;
        tree[m].sum += val;
        return;
    }
    int mid = (tree[m].left + tree[m].right) >> 1;
    if (a <= mid) {
        update(m << 1, a, val);
    } else {
        update(m << 1 | 1, a, val);
    }
    tree[m].max = max(tree[m << 1].max, tree[m << 1 | 1].max);
    tree[m].sum = tree[m << 1].sum + tree[m << 1 | 1].sum;
}

int querySum(int m, int l, int r)
{
    if (l == tree[m].left && r == tree[m].right) {
        return tree[m].sum;
    }
    int mid = (tree[m].left + tree[m].right) >> 1;
    if (r <= mid) {
        return querySum(m << 1, l, r);
    } else if (l > mid) {
        return querySum(m << 1 | 1, l, r);
    }
    return querySum(m << 1, l, mid) + querySum(m << 1 | 1, mid + 1, r);
}

int queryMax(int m, int l, int r)
{
    if (l == tree[m].left && r == tree[m].right) {
        return tree[m].max;
    }
    int mid = (tree[m].left + tree[m].right) >> 1;
    if (r <= mid) {
        return queryMax(m << 1, l, r);
    } else if (l > mid) {
        return queryMax(m << 1 | 1, l, r);
    }
    return max(queryMax(m << 1, l, mid), queryMax(m << 1 | 1, mid + 1, r));
} 

build(1,1,n);  
update(1,a,b);  
query(1,a,b);

/*
    线段树 区间更新
    |16/11/06ztx|
*/

typedef long long ll;  
const int maxn = 100010;  

int t,n,q;  
ll anssum;  

struct node{
    ll l, r;
    ll addv, sum;  
}tree[maxn<<2];  

void maintain(int id) {
    if (tree[id].l >= tree[id].r)
        return;
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;  
}  

void pushdown(int id) {
    if (tree[id].l >= tree[id].r)
        return;
    if (tree[id].addv) {
        int tmp = tree[id].addv;
        tree[id << 1].addv += tmp;
        tree[id << 1 | 1].addv += tmp;
        tree[id << 1].sum += (tree[id << 1].r - tree[id << 1].l + 1) * tmp;
        tree[id << 1 | 1].sum +=
            (tree[id << 1 | 1].r - tree[id << 1 | 1].l + 1) * tmp;
        tree[id].addv = 0;
    }  
}  

void build(int id,ll l,ll r) {
    tree[id].l = l;
    tree[id].r = r;
    tree[id].addv = 0;
    tree[id].sum = 0;
    if (l == r) {
        tree[id].sum = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    maintain(id);  
}  

void updateAdd(int id,ll l,ll r,ll val) {
    if (tree[id].l >= l && tree[id].r <= r) {
        tree[id].addv += val;
        tree[id].sum += (tree[id].r - tree[id].l + 1) * val;
        return;
    }
    pushdown(id);
    ll mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid)
        updateAdd(id << 1, l, r, val);
    if (mid < r)
        updateAdd(id << 1 | 1, l, r, val);
    maintain(id);  
}  

void query(int id,ll l,ll r) {
    if (tree[id].l >= l && tree[id].r <= r) {
        anssum += tree[id].sum;
        return;
    }
    pushdown(id);
    ll mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid)
        query(id << 1, l, r);
    if (mid < r)
        query(id << 1 | 1, l, r);
    maintain(id);  
}  

int main() {
    scanf("%d", &t);
    int kase = 0;
    while (t--) {
        scanf("%d %d", &n, &q);
        build(1, 1, n);
        int id;
        ll x, y;
        ll val;
        printf("Case %d:\n", ++kase);
        while (q--) {
            scanf("%d", &id);
            if (id == 0) {
                scanf("%lld %lld %lld", &x, &y, &val);
                updateAdd(1, x + 1, y + 1, val);
            } else {
                scanf("%lld %lld", &x, &y);
                anssum = 0;
                query(1, x + 1, y + 1);
                printf("%lld\n", anssum);
            }
        }
    }
    return 0;  
}

/*
    树状数组
    |16/11/06ztx|
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int maxn = 50005;

int a[maxn];
int n;

int lowbit(const int t) {
    return t & (-t);
}

void insert(int t, int d) {
    while (t <= n) {
        a[t] += d;
        t = t + lowbit(t);
    }
}

ll getSum(int t) {
    ll sum = 0;
    while (t > 0) {
        sum += a[t];
        t = t - lowbit(t);
    }
    return sum;
}

int main() {
    int t, k, d;
    scanf("%d", &t);
    k = 1;
    while (t--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &d);
            insert(i, d);
        }
        string str;
        printf("Case %d:\n", k++);
        while (cin >> str) {
            if (str == "End")
                break;
            int x, y;
            scanf("%d %d", &x, &y);
            if (str == "Query")
                printf("%lld\n", getSum(y) - getSum(x - 1));
            else if (str == "Add")
                insert(x, y);
            else if (str == "Sub")
                insert(x, -y);
        }
    }
    return 0;
}