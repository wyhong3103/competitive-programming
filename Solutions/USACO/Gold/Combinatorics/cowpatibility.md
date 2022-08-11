```
Simple PIE, but few things failed our code.

BST is too slow, and vector couldn't be used as a key for hash map.

So we got this custom hash function from the internet and it worked.
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
struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

void solve(){
    ll n;
    cin >> n;

    vector<vi> a(n);
    for(auto& i : a){
        i.resize(5);
        for(auto& j : i) cin >> j;
        sort(all(i));
    }
    
    unordered_map<vi, ll, VectorHasher> mp;

    ll res = (n * (n-1))/2;
    for(int i{}; i < n; i++){
        ll compatible = 0;
        for(int j{1}; j < (1 << 5); j++){
            vi temp;
            for(int k{}; k < 5; k++){
                if (j & (1 << k)){
                    temp.pb(a[i][k]);
                }
            }
            if (mp.count(temp)){
                compatible += (sz(temp) % 2 ? mp[temp] : -mp[temp]);
            }else mp[temp] = 0;
            mp[temp]++;
        }
        res -= compatible;
    }

    cout << res;
}

int main(){
    setio("cowpatibility");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```