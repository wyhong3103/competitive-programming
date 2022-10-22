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

const int MAX = 2e5 +5;
ll fenwick_tree[MAX];
int n, q;

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

void solve(){
    cin >> n >> q;
    
    for(int i{}; i < n; i++){
        ll x;
        cin >> x;
        upd(i+1, x);
    }

    while(q--){
        ll t, a, b;
        cin >> t >> a >> b;

        if (t == 1){
            ll initial = sum(a)-sum(a-1);
            upd(a, -initial);
            upd(a, b);
        }else{
            cout << sum(b) - sum(a-1) << '\n';
        }
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