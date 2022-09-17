```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vll> dist(n, vll(n, LONG_LONG_MAX));
    
    for(int i{}; i < m; i++){
        ll f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        w = min(w, dist[f][t]);
        dist[f][t] = w;
        dist[t][f] = w;
    }

    for(int i{}; i < n; i++) dist[i][i] = 0;

    for(int k{}; k < n; k++){
        for(int i{}; i < n; i++){
            for(int j{};j < n; j++){
                if (i == j || dist[k][i] == LONG_LONG_MAX || dist[k][j] == LONG_LONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[k][i] + dist[k][j]);
            }
        }
    }

    while(q--){
        int f,t;
        cin >> f >> t;
        f--;t--;
        cout << (dist[f][t] == LONG_LONG_MAX ? -1 : dist[f][t]) << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```