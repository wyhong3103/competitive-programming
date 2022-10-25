```

It's best if we pair it in a segment of 2.

Starting from 1

x x+y

x+1 x+1+y

x+2 x+2+y
.
.
.


And reverse the pairing order notice that, one end of a pair and the beginning of its previosu pair has a gap >= z

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
 
    vector<pi> pairs;
    
    set<int> remain;
    for(int i{1}; i <= n; i++){
        remain.insert(i);
    }
 
    for(int i{1}; i <= n; i++){
        if (remain.count(i) && remain.count(i+(n/2))){
            remain.erase(i);
            remain.erase(i+(n/2));
            pairs.pb({i, i+(n/2)});
        }
    }
 
    if (n % 2){
        cout << n << ' ';
    }
    reverse(all(pairs));
    for(auto& i : pairs) cout << i.fir << ' ' << i.sec << ' ';
    cout << '\n';
 
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