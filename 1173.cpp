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
    
    int a, b, c;
    cin >> a >> b >> c;

    bool f1 = false, f2 = false;
    
    if (a != 0 && b != 0 && c != 0) {
        if (a * c == b * b) {
            f2 = true;
        }
    }

    if (b - a == c - b)
        f1 = true;
    
    if (f1 && f2)
        cout << "both\n";
    else if (f1)
        cout << "arithmetic\n";
    else if (f2)
        cout << "geometric\n";
    else
        cout << "normal\n";
    
    return 0;
}