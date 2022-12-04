```

Prime factorize k, for every prime number we can divide it in all the natural numbers until it is all wasted.

For each prime number, we at max only have to travel through the natural number < 100. (Just think about 2^100, it is really large)

And we can save the natural number we divided in a map.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    ll k;
    cin >> k;
 
    map<ll,int> primes;
    for(ll i{2}; i * i <= k; i++){
        while (k % i == 0){
            k /= i;
            primes[i]++;
        }
    }
    if (k > 1){
        primes[k]++;
    }
 
    map<ll, ll> remain;
    ll mx = 0;
    for(auto& i : primes){
        ll cur = 1;
        while (i.sec){
            if (remain.count(i.fir * cur) && remain[i.fir*cur] % i.fir == 0 && remain[i.fir*cur] != 0){
                remain[i.fir*cur] /= i.fir;
                i.sec--;
            }else if (remain.count(i.fir*cur)){
                cur++; 
            }else{
                remain[i.fir*cur] = i.fir*cur;
            }
        }
        mx = max(i.fir*cur, mx);
    }
    cout << mx;
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