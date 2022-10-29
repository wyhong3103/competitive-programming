```

Think of the swapping puzzle, wehere you have a grid of numbers and then 1 empty square. The thing is you can basically get a number to anywhere as long as there is 1 empty square!

So we can simulate the game process.

If top of (1,1) is the current element we need, we move it straight to the end, it doesn't matter how we move it is always guarnateed that it's possible, but one thing is, we need at least 2 spaces when we do this. 1 space to place this element, another space to allow moving.

If top isn't what we want, we move it to anywhere, but make sure at all time, to have at least 1 spaces.

And also, if the current that we need is on the board's elsewhere, we can simply move it to the end, and ++ spaces.

If any point of time, spaces went below 1, or when we want to move the top to end and space is below 2. it's impossible to solve!

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
    ll n, m, k;
    cin >> n >> m >> k;
 
    vi a(k);
    for(auto& i : a) cin >> i;
    reverse(all(a));
 
 
    int cur = k;
 
    set<int> waiting;
 
    bool ok = 1;
    ll spaces = (n*m) - 2;
    while (cur >= 1 && ok){
        if (waiting.count(cur)){
            waiting.erase(cur);
            cur--;
            spaces++;
        }
        else if (sz(a) && a.back() != cur){
            waiting.insert(a.back());
            a.pop_back();
            if (spaces == 0) ok = 0;
            spaces--;
        }else if (sz(a) && a.back() == cur){
            if (spaces <= 1) ok = 0;
            a.pop_back();
            cur--;
        }
    }
 
    cout << (ok ? "YA" : "TIDAK") << '\n';
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