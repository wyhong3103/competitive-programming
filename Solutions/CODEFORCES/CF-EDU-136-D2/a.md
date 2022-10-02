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
    int n,m;
    cin >> n >> m;
 
    vi dr = {1, 2, 2, 1, -1, -2 , -2, -1};
    vi dc = {-2, -1, 1, 2, 2, 1, -1, -2};
 
    pi found = {1, 1};
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            bool ok = 0;
            for(int k{}; k < 8; k++){
                if (i+dr[k] >= 0 && i + dr[k] < n && j + dc[k] >= 0 && j + dc[k] < m) ok = 1;
            }
            if (!ok) found = {i, j};
        }
    }
 
    cout << found.fir+1 << ' ' << found.sec+1 << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
 
```