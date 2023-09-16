// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

struct edge
{
    int v, u, w, id;
};
vector <edge> E;
vector <int> G[100005];
int vis[100005];

bool dfs(int v)
{
    vis[v] = 1;
    bool f = false;
    for (int u : G[v]) {
        if (vis[u] == 1)
            return true;
        else if (!vis[u])
            f |= dfs(u);
    }
    vis[v] = 2;
    return f;
}

bool check(int n, int k)
{
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    for (auto e : E) {
        if (e.w > k)
            G[e.v].push_back(e.u);
    }
    bool res = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            res |= dfs(i);
    }
    for (int i = 1; i <= n; i++)
        G[i].clear();
    return res;
}

int in[100005];
int dp[100005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        E.push_back({a, b, c, i});
    }
    sort(E.begin(), E.end(), [&](edge e1, edge e2){
        return e1.w > e2.w;
    });

    int l = -1, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(n, mid)) { /// have cycle
            l = mid;
        } else {
            r = mid;
        }
    }
    /// ans = r
    int ans = r;
    for (auto e : E) {
        if (e.w > ans) {
            G[e.v].push_back(e.u);
            in[e.u]++;
        }
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            Q.push(i);
    
    int timecnt = 0;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        dp[v] = ++timecnt;
        for (int u : G[v]) {
            in[u]--;
            if (!in[u])
                Q.push(u);
        }
    }

    int anscnt = 0;
    vector <int> E_id;
    for (auto e : E) {
        if (e.w <= ans && dp[e.v] > dp[e.u]) {
            E_id.push_back(e.id);
            anscnt++;
        }
    }
    cout << ans << " " << anscnt << "\n";
    for (int it : E_id)
        cout << it << "\n";
    
    return 0;
}