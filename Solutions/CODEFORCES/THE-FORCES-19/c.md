
The one hit observation is that the highest number of factor for $m$ is $\approx 2000$.

We could generate every factors for $m$, and then iterate through every pair of numbers in $O(n^2)$, to compute the answer.


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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    ll n, m;
    cin >> n >> m;
 
    ll target = m;
 
    map<ll, ll> a, b, c;
    for(int i{}; i < n; i++){
        ll x;
        cin >> x;
        a[x]++;
    }
    for(int i{}; i < n; i++){
        ll x;
        cin >> x;
        b[x]++;
    }
    for(int i{}; i < n; i++){
        ll x;
        cin >> x;
        c[x]++;
    }
 
    map<ll, int> pf;
 
    for(int i{2}; i * i <= m; i++){
        while (m % i == 0){
            m /= i;
            pf[i]++;
        }
    }   
 
    if (m > 1){
        pf[m]++;
    }
 
    vll factors = {1};
    for(auto& i : pf){
        for(int j{}; j < i.sec; j++){
            int siz = sz(factors);
            for(int k{}; k < siz; k++){
                factors.pb(factors[k] * i.fir);
            } 
        }
    }
 
 
    sort(all(factors));
    factors.resize(unique(all(factors)) - factors.begin());
 
    ll res = 0;
    for(int i{}; i < sz(factors); i++){
        for(int j{}; j < sz(factors); j++){
            if (target % (factors[i] * factors[j]) == 0){
                res += a[factors[i]] * b[factors[j]] * c[target / (factors[i] * factors[j])];
            }
        }
    }
 
    cout << res << '\n';
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