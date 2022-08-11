DO NOT SOLVE YET, LACKING ON THE CASE {3,3,4} (ONE-MAN SITUATION)
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MOD = 998244353;

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;

    if (p%2) return (sq * n) % MOD;
    return sq;
}


ll ncr(ll n, ll r){
    ll num = 1;
    for(ll i{n}; i > n-r; i--){
        num = (num * i) % MOD;
    }

    ll denom = 1;
    for(ll i{1}; i <= r; i++){
        denom = (denom * i) % MOD;
    }
    return  (num * modpow(denom, MOD-2)) % MOD;
}

void solve(){
    ll n,x;
    cin >> n >> x;

    ll res = modpow(min(n-1,x), n);
    cout << res << '\n';

    //lacking {3,3,4} such cases
    for(ll i{n}; i <= x; i++){
        for(ll j{2}; j <= n; j++){
            res = (res + ((ncr(n, j) * modpow(i-1,n-j)) % MOD)) % MOD;
            cout << n << 'C' << j << '*' << i-1 << '^' << n-j << " + ";
        }    
        cout << '\n';
    }

    cout << res;
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

Brute Force
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

map<int,int> cnt;

bool simulate(vi a){
    int alive = sz(a);
    while (alive){
        if (alive == 1) return false;
        int temp = 0;
        for(int i{}; i < sz(a); i++){
            if (a[i] > 0) a[i] -= alive-1;
            if (a[i] > 0) temp++;
        } 
        alive = temp;
    }
    return true;
}

void gen(int i, int n, int x, vi& a){
    if (i == n){
        if (simulate(a)){
            pi mx{-1,-1};
            for(auto& i : a){
                if (i > mx.fir){
                    mx.fir = i;
                    mx.sec = 0;
                }
                if (i == mx.fir) mx.sec++;
            }
            if (mx.fir >= n && mx.sec == 1){
                if (!cnt.count(mx.fir)) cnt[mx.fir] = 0;
                cnt[mx.fir]++;
                for(auto& i : a) cout << i << ' ';
                cout << '\n';
            }
        }
        return;
    }

    for(int j{1}; j <= x; j++){
        a.pb(j);
        gen(i+1, n, x, a);
        a.pop_back();
    }
}
 
void solve(){
    int n, x;
    cin >> n >> x;

    vi a{};
    gen(0, n, x, a);
    for(auto& i : cnt) cout << i.fir << ' ' << i.sec << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

```