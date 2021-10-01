#include<iostream>
using namespace std;
 
#define int long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define pll pair<int,int>
#define MOD 1000000007
#define M2 998244353
#define INF 2e18
#define EPS 1e-9
#define minheap priority_queue<int, vector<int>, greater<int>>
const ld PI = 3.14159265358979323846;
const int MAX_N = 1e6 + 5;
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
 
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] == '*') {
                int len = 0;
                int a1 = i - 1, l1 = j - 1, l2 = j + 1;
                vector<pair<int, int>> v;
                while (a1 >= 0 && l1 >= 0 && l2 < m) {
                    if (a[a1][l1] == '*' && a[a1][l2] == '*') {
                        len++;
                        v.pb({a1, l1});
                        v.pb({a1, l2});
                        l1--;
                        l2++;
                        a1--;
                        continue;
                    }
                    break;
                }
                if (len < k && vis[i][j] == 0) {
                    cout << "NO\n";
                    return;
                }
                if (len >= k) {
                    for (auto p:v) {
                        vis[p.F][p.S] = 1;
                    }
                }
                vis[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*' && !vis[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}