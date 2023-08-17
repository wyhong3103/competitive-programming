## Abridged Statement

Refer to the original statement.

## Approach

It is always optimal to exhaust $c$ buttons first. If $c$ is an even number, then by the time $c$ exhausted, Anna will go first, otherwise Katie.

When $c$ is exhausted, if Anna go first, Anna can only win if $b \lt a$. If Katie go first, Katie can only win if $a \lt b$.

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;

    if (c % 2){
        cout << (a >= b ? "First" : "Second") << '\n';
    }else{
        cout << (b >= a ? "Second" : "First") << '\n';
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