```

Notice that number a[i] can connect to any number that is smaller than a[i] that has index j, s.t j < i


this gives us an idea to have

dp[i][j] = number of increasing subsequences that has i elements s.t the i-th element is j

dp[i][j] = sum(dp[i-1][k]), k < j

We can do range sum query to do this in log n

base case, when i == 1,

simply let dp[1][j] += 1


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

const int MAX = 1e5 +5;
int n, k;

struct FenwickTree{
    ll fenwick_tree[MAX];

    //Sum of [1,k]
    ll sum(int k){
        ll s = 0;
        while (k >= 1){
            s += fenwick_tree[k];
            k -= k&-k;
        }
        return s;
    }

    //Update
    void upd(int k, ll x){
        while (k <= n){
            fenwick_tree[k] += x;
            k += k&-k;
        }
    }
};

void solve(){
    cin >> n >> k;

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<FenwickTree> dp(k+2);

    for(int i{}; i < n; i++){
        dp[1].upd(a[i], 1);
        for(int j{2}; j <= k+1; j++){
            dp[j].upd(a[i], dp[j-1].sum(a[i]-1));
        }
    }

    cout << dp[k+1].sum(n);
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