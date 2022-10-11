```

Keep a monotonic stack (small -> high) for the height of the fence!

Notice that, every element in that stack can create a rectangle as large as (the index of current end point - the index of the stack element before current) * current height

This is because the current end point guarantee that any element from current element to the end point has height > current height. And also bc of the fact that it's monotonic between every 2 adjacent element, it is guaranteed that there is no smaller element between the two!


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
    int n;
    cin >> n;
    stack<pll> s;

    ll mx = 0;
    for(int i{}; i < n; i++){
        ll x;
        cin >> x;
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