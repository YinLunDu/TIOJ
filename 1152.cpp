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

vector <int> G[10005];
int mx, pt;

void dfs(int v, int p, int step)
{
    if (step > mx) {
        mx = step;
        pt = v;
    }
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v, step + 1);
    }
}

signed main()
{
    IOS
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        while (cin >> u) {
            if (u == -1) break;
            G[i].push_back(u);
            G[u].push_back(i);
        }
    }

    mx = -1, pt = -1;
    dfs(0, -1, 0);
    int tmp = pt;
    mx = -1, pt = -1;
    dfs(tmp, -1, 0);

    cout << mx << "\n";
    
    return 0;
}