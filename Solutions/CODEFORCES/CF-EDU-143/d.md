```

To get max weight, it is guaranteed that each triangle will have all their max 2 edges.

There are 3 different situation for the weight of the edges of the triangle

3 of the same weight, in this situation, we can color it anyway we want, long as 2 get selected (3C2)

2 of the same weight that is smaller than 1 of the weight, we can keep the greater one, and the other one be either one of the 2 (2 ways to form that exactly)

Rest has only one way

Now remember, we can only have n/2 red and n/2 blue. Notice that for each triangle, we either have more red or more blue, to even out their, we can pair up with triangle to even out. (red red blue in first, blue blue red in second)

So basically, the way we color the triangle is just (N/3)C(n/6) (as there are equal red (majority) triangle and blue (majority) triangle) * the total way we can select edges for each triangle


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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}



const int MOD = 998244353;

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);

    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}


long long ncr(ll n, ll r){
    ll nom = 1;
    for(int i{n-r+1}; i <= n; i++){
        nom *= i;
        nom %= MOD;
    }

    ll denom = 1;
    for(int i{1}; i <= r; i++){
        denom *= i;
        denom %= MOD;
    }
    return (nom * modpow(denom, MOD-2)) % MOD;
}

void solve(){
    int n;
    cin >> n;
    
    vi a;
    ll cur = 1;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        a.pb(x);
        if (sz(a) == 3){
            sort(all(a));
            if (a[0] == a[1] && a[1] == a[2]){
                cur *= 3;
            }
            else if (a[0] == a[1]){
                cur *= 2;
            }
            a.clear();
        }
        cur %= MOD;
    }

    cout << (cur * ncr(n/3, (n/3)/2))% MOD;

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