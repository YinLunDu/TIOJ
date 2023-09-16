// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
const int INF = 1e18;
/// ------- Initialization End -------

vector <int> G[2][200005];
int mx = -1, pt = -1;
int dia = -1;
int dia_a = -1, dia_b = -1;
void dfs(int T, int v, int p, int cnt)
{
    if (cnt > mx)
        mx = cnt, pt = v;
    for (int u : G[T][v]) {
        if (u == p) continue;
        dfs(T, u, v, cnt + 1);
    }
}

vector <int> mid[2];
bool find_mid(int T, int v, int p, int cnt)
{
    if (v == dia_b)
        return true;
    bool on_dia = false;
    for (int u : G[T][v]) {
        if (u == p) continue;
        bool f = find_mid(T, u, v, cnt + 1);
        if (f) {
            if (cnt == dia / 2 || (dia % 2 == 1 && cnt == dia / 2 + 1))
                mid[T].push_back(v);
            on_dia = true;
        }
    }
    return on_dia;
}

const int P = 1e6 + 3, M = 1e9 + 7;

int get_hash(int T, int v, int p)
{
    int cnt = 0;
    for (int u : G[T][v]) {
        if (u == p) continue;
        cnt += get_hash(T, u, v);
        cnt %= M;
    }
    cnt *= P;
    cnt ++;
    cnt = cnt % M;
    return cnt;
}

signed main()
{
    IOS
    
    int n;
    int a, b;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            G[0][i].clear();
            G[1][i].clear();
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> a >> b;
            G[0][a].push_back(b);
            G[0][b].push_back(a);
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> a >> b;
            G[1][a].push_back(b);
            G[1][b].push_back(a);
        }
        vector <int> rh[2];
        for (int i = 0; i < 2; i++) {
            mx = -1, pt = -1;
            dfs(i, 1, -1, 0);
            dia_a = pt;
            mx = -1, pt = -1;
            dfs(i, dia_a, -1, 0);
            dia = mx;
            dia_b = pt;
            find_mid(i, dia_a, -1, 0);

            for (int j : mid[i])
                rh[i].push_back(get_hash(i, j, -1));
        }
        bool f = false;
        for (int i : rh[0])
            for (int j : rh[1])
                if (i == j)
                    f = true;
        if (f)
            cout << "Same\n";
        else
            cout << "Different\n";
    }
    
    return 0;
}