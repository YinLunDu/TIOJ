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

int a[55];

signed main()
{
    IOS
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (__gcd(a[i], a[j]) == 1)
                    cnt++;
            }
        }
        if (cnt == 0) {
            cout << "No estimate for this data set.\n";
            continue;
        }
        long double _cnt = cnt;
        long double _n = n;
        long double pi = (6.0 * (_n * (_n - 1) * 0.5)) / _cnt;
        pi = sqrtl(pi);
        cout << fixed << setprecision(6) << pi << "\n";
    }
    
    return 0;
}