```

given an array A of length N

starting as X = 0

each time we do

X += A[X mod N]

what is X after K operations

there is going to be a cycle

we're going to find the cycle

And then count the sum

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
    ll n, k;
    cin >> n >> k;

    vll a(n);
    for(auto& i : a) cin >> i;
        
    set<int> used;
    ll x = 0;

    while (!used.count(x % n) && k){
        used.insert(x % n);
        x += a[x % n];
        k--;
    }
    
    if (!k){
        cout << x;
        return;
    }

    vi order;
    int start = x % n;
    order.pb(start);
    ll temp = start + a[start];

    while (temp % n != start){
        order.pb(temp % n);
        temp += a[temp % n];
    }
    
    ll cycle_sm = 0;
    for(auto& i : order) cycle_sm += a[i];
    
    x += cycle_sm * (k/(ll)sz(order));

    for(int i{}; i < (k % (ll)sz(order)); i++) x += a[order[i]];

    cout << x;
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