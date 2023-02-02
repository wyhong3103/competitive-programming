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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n, m, d;
    cin >> n >> m >> d;
 
    vi a(n);
    for(auto& i : a){
        cin >> i;
        i--;
    }
 
    vi b(m);
    for(auto& i : b){
        cin >> i;
        i--;
    }
 
    vi at(n);
    for(int i{}; i < n; i++){
        at[a[i]] = i;
    }
 
    bool ok = 0;
    int mn = INT_MAX;
    for(int i{}; i < m-1; i++){
        if (at[b[i]] < at[b[i+1]]){
            if (at[b[i+1]] <= at[b[i]] + d){
                // either move out of range or swap
                int dist = at[b[i+1]]-at[b[i]];
                if (at[b[i]] + (n-1-at[b[i+1]]) >= d-dist+1){
                    mn = min(mn, d-dist+1);
                }
 
                mn = min(mn, dist);
            }else ok = 1;
        }else{
            ok = 1;
        }
    }
    cout << (ok ? 0 : mn) << '\n';
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