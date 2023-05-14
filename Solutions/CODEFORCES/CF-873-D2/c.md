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
 
const int MOD =1e9 + 7;
 
const int MX = 2e5 + 5;
 
ll fact[MX];
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}
 
void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i ) %MOD;
    }
}
 
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n), b(n);
    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;
 
    sort(all(a));
    sort(all(b));
 
    for(int i{}; i < n; i++){
        if (a[i] <= b[i]){
            cout << 0 << '\n';
            return;
        }
    }
 
    ll res = 1;
    ll cnt = 0;
    vi bp(n);
    for(int i{}; i < n; i++){
        cnt++;
        res = (res * cnt) % MOD;
        int lo = i, hi = n-1;
        while (hi > lo){
            int mid = lo+(hi-lo+1)/2;
            if (b[mid] < a[i]){
                lo = mid;
            }else hi = mid-1;
        }
        bp[lo]--;
        cnt += bp[i];
    }
    cout << res << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    gen_fact();
    while(t--){
        solve();
    }
    return 0;
}

```