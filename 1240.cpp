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

int a[205];

signed main()
{
    IOS
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    multiset <int> s;
    for (int i = 1; i <= n; i++) {
        auto it = s.lower_bound(a[i]);
        if (it == s.begin()) {
            s.insert(a[i]);
        } else {
            it = prev(it);
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout << s.size() << "\n";
    
    return 0;
}