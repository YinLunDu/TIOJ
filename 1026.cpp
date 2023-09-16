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
    
    int n;
    cin >> n;

    int bit[32] = {0};
    
    int i = 0;
    while (n > 0) {
        bit[i] = n & 1;
        n >>= 1;
        i++;
    }

    int len = i;
    cout << len << "\n";

    for (int i = 1; i < len; i++) {
        if (bit[i] == 0) {
            bit[i - 1] = 0;
            bit[i] = 1;
        }
    }

    for (int i = 0; i < len; i++)
        cout << (bit[i] ? '+' : '-');
    cout << "\n";

    return 0;
}