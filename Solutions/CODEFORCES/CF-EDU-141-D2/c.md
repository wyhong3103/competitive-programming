```

Observations

1. Everyone is going to have a fixed amount of win before we play, which is 0, 1, 2 .... according to index

2. If we beat someone in a game they're simply going to remain the same number of win, otherwise + 1.

3. It's always optimal to take as many win as possible. 

Now imagine we have two scenario :

One with x+1 wins

The x-th player has x wins before us, so if we have x+1, we're definitely tied with that guy or won over that guy, depending on whether we have defeated the guy.

One with x wins

The x-th player has x wins before us, so if we have x, we either tied (if we have defeated that guy) or lose to the guy

So it's clear that the greater wins we have the greater place we got and it's more secure

4. Say we have x wins, only the x-th opponent mattered to us. Players that initially have > x wins, is going to be better than us anyway, since we aren't going to have more than x wins, even if we defeated them, they still have better wins. So for the x-th opponent, we're going to check if we have defeated him, or it's possible to defeat him (by trading the largest win and the remaining M we have)

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
    ll n, m;
    cin >> n >> m;
 
    multiset<pi> ms;
 
    vll a(n);
    for(int i{}; i < n; i++){
        cin >> a[i];
        ms.insert({a[i], i});
    }
 
    set<int> taken;
    int mx = -1;
    for(auto& i : ms){
       if (i.fir <= m) {
            mx = max(mx, i.fir);
            m -= i.fir;
            taken.insert(i.sec);
       }
    }
 
    if (mx == -1){
        cout << n+1 << '\n';
        return;
    }
 
    if (sz(taken) == n || taken.count(sz(taken))){
        cout << n-(sz(taken)+taken.count(sz(taken)))+1 << '\n';
    }else{
        if (m+mx >= a[sz(taken)]){
            cout << n-sz(taken) << '\n';
        }else{
            cout << n-sz(taken)+1 << '\n';
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```