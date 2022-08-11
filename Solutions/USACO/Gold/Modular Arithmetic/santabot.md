Okay this problem is not hard, it's just confusing... The part where I got confused is in this [comment](https://codeforces.com/blog/entry/72577?#comment-645633)
```
For one pair of x, y

Probability = (1/n * 1/k * 1/n) * number of kids that has y

1/n = probability to select x
1/k = probability to select y
1/n = probability to select z

* number of kids that has y

Is equal to the number of valid decision based of the pair
```
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
 

const int MOD =998244353;

ll modpow(ll x, ll n, ll MOD){
    if (n == 0) return 1;
    ll sq = modpow(x, n/2, MOD) % MOD;
    sq = (((sq % MOD) * (sq % MOD)) % MOD);
    if (n % 2 != 0){
        sq = (sq * x) % MOD;
    }
    return sq;
}

void solve(){
    int n;
    cin >> n;

    unordered_map<int,int> mp;
    vector<vi> kids(n);
    for(auto& i : kids){
        int k;
        cin >> k;
        for(int j{}; j < k; j++){
            int a;
            cin >> a;
            i.pb(a);
            if (!mp.count(a)) mp[a] = 0;
            mp[a]++;
        }
    }

    ll res = 0;
    for(auto& i : kids){
        for(auto& j : i){
            ll nom = mp[j];
            ll denom =  (modpow(n, 2, MOD)* sz(i)) % MOD;
            res = (res + (nom * modpow(denom, MOD-2, MOD))) % MOD;
        }
    }

    cout << res;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```