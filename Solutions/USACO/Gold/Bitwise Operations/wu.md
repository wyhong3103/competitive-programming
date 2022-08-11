Barely passed, 919ms.
```
We can precompute everything, since n <= 12, there would only be 4096 combinations out there.

Precompute the value for each numbers, from 0 to 4095, in fact, we could use prefix sum array, to answer the queries.
```
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 


void solve(){
    ll n, m, q;
    cin >> n >> m >> q;

    vi a(n);
    for(auto& i : a) cin >> i;
    
    vi cnt(4096);
    for(int i{}; i < m; i++){
       string s;
       cin >> s;
       ll cur = n-1;
       ll val = 0;
       for(auto& i : s){
            val += (i - '0') * (1 << cur);
            cur--; 
       }
       cnt[val]++;
    }

    //prefix sum array for each number
    vector<vi> bits(4096);
    for(int i{}; i < 4096; i++){
        bits[i].resize(101);
        for(int j{}; j < 4096; j++){
            if (!cnt[j]) continue;
            ll val = 0;
            for(int k{}; k < n; k++){
                if (((i >> k) & 1) == ((j >> k) & 1)){
                    val += a[n-1-k];
                } 
            }            
            if (val <= 100) bits[i][val] += cnt[j];
        }
        for(int j{1}; j <= 100; j++) bits[i][j] += bits[i][j-1];
    }

    while (q--){
        string t;
        cin >> t;
        int k;
        cin >> k;

        ll cur = n-1;
        ll val = 0;
        for(auto& i : t){
            val += (i - '0') * (1 << cur);
            cur--; 
        }

        cout << bits[val][k] << '\n';
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