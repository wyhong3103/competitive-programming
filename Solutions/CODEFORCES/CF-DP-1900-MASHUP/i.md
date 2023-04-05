```

Prefix sum is intended, any log n range sum query would fail the TL.

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

const int MOD =1e9 + 7;

void solve(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    a--;b--;

    vll dp1(n+5);
    for(int i{a}; i < n; i++) dp1[i] = 1;

    for(int i{}; i < k; i++){
        vll dp2(n+5);
        for(int j{}; j < n; j++){
            if (j < b){
                if (j) dp2[j] = dp1[j-1];
                if (b-j-1 >= 2){
                    dp2[j] += (dp1[j+(b-j-1)/2]-dp1[j]+MOD) % MOD;
                }
            }else if (j > b){
                dp2[j] = (dp1[n-1] - dp1[j] + MOD) % MOD;
                if (j-b-1 >= 2) dp2[j] += (dp1[j-1] - dp1[j-(j-b-1)/2-1] + MOD) % MOD;
            }
            if (j) dp2[j] = (dp2[j] + dp2[j-1]) % MOD;
        }
        swap(dp1, dp2);
    }

    cout << dp1[n-1];
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
```

Fenwick Tree barely pass the TL.

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

const int MOD =1e9 + 7;
const int MAX = 5005;
int n, a, b, k;

struct FenwickTree{
    vll fenwick_tree;

    void init(){
        fenwick_tree.resize(n + 5);
    }

    //Sum of [1,k]
    int sum(int k){
        int s = 0;
        while (k >= 1){
            s += fenwick_tree[k];
            s %= MOD;
            k -= k&-k;
        }
        return s;
    }

    //Update
    void upd(int k, ll x){
        x += MOD;
        x %= MOD;
        while (k <= n){
            fenwick_tree[k] += x;
            fenwick_tree[k] %= MOD;
            k += k&-k;
        }
    }
};
void solve(){
    cin >> n >> a >> b >> k;

    FenwickTree dp1;
    dp1.init();
    dp1.upd(a, 1);
    for(int i{}; i < k; i++){
        FenwickTree dp2;
        dp2.init();
        for(int j{(b > a ? 1 : b+1)}; j < (b > a ? b : n+1); j++){
            if (j < b){
                dp2.upd(j, dp1.sum(j-1));
                if (b-j-1 >= 2){
                    dp2.upd(j, dp1.sum(j+(b-j-1)/2)-dp1.sum(j));
                }
            }else if (j > b){
                dp2.upd(j, dp1.sum(n)-dp1.sum(j));
                if (j-b-1 >= 2) dp2.upd(j, dp1.sum(j-1) - dp1.sum(j-(j-b-1)/2-1));
            }
        }
        swap(dp1, dp2);
    }

    cout << dp1.sum(n);
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