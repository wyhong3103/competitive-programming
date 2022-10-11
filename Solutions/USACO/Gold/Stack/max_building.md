```

Largest rectangle in histogram, but level by level.

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
 
ll getArea(vi& a){
    int n = sz(a);
    stack<pll> s;
 
    ll mx = 0;
    for(int i{}; i < n; i++){
        ll x = a[i];
        while (!s.empty() && s.top().sec >= x){
            pll cur = s.top();
            ll sm = ((i-s.top().fir)) * s.top().sec;
            s.pop();
            if (!s.empty()) sm += ((cur.fir - 1) - s.top().fir) * cur.sec;
            else sm += cur.fir * cur.sec;
            mx = max(sm, mx);
        }
 
        s.push({i, x});
    }
 
    while (!s.empty()){
        pll cur = s.top();
        ll sm = ((n-s.top().fir)) * s.top().sec;
        s.pop();
        if (!s.empty()) sm += ((cur.fir - 1) - s.top().fir) * cur.sec;
        else sm += cur.fir * cur.sec;
        mx = max(sm, mx);
    }
 
    return mx;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(auto& i : a) cin >> i;

    vector<vi> prefix(n, vi(m));

    for(int i{}; i < m; i++){
        for(int j{}; j < n; j++){
            if (a[j][i] == '*') prefix[j][i] = 0;
            else prefix[j][i] = (!j ? 0 : prefix[j-1][i]) + 1;
        }
    }

    ll mx = 0;
    for(int i{}; i < n; i++){
        vi temp(m);
        for(int j{}; j < m; j++) temp[j] = prefix[i][j];
        mx = max(mx, getArea(temp));
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