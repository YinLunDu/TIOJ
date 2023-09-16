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

int a[200005];
pii b[200005];
int x[200005];
int y[200005];

pii bit[200005];

pii query(int idx)
{

}

void update(int idx, pii val)
{
    while (idx <= 200000) {
        ;
    }
}

signed main()
{
    IOS
    
    int n;
    cin >> n;

    vector <pii> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++) {
        x[i] = v[i - 1].first;
        y[i] = v[i - 1].second;
    }
    
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        b[i].first = y[lower_bound(x + 1, x + n + 1, tmp) - x];
        b[i].second = tmp;
    }
/*
    for (int i = 1; i <= n; i++)
        dbg(b[i].first); ent();
    for (int i = 1; i <= n; i++)
        dbg(b[i].second); ent();
*/



    return 0;
}