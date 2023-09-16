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

signed main()
{
    IOS
    
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        int ans = 0;
        int times = min(n, m);
        int low = 0;
        int high = min(n, m) - 1;
        ans += 1ll * high * (high + 1) * (2 * high + 1) / 6;
        ans += 1ll * n * m * times;
        ans -= 1ll * (n + m) * high * (high + 1) / 2;
        cout << ans << "\n";
    }
    
    return 0;
}