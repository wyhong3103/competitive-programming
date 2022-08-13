I knew this question was about contribution to the sum. It's just the definition of complexity of a subset is not clear to me, not even after I read the editorial.
```
From my understanding, the test case

2
1 3
2 4

Should be

{1,3} = 1
{2,4} = 1
{1,3},{2,4} = 2

But it turned out

{1,3},{2,4} = 1

Apparently, they can't intersect even though they're representing different interval.
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MOD = 1e9 + 7;

ll modpow(int n, int p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    if (p%2){
        return sq * n;
    }
    return sq;
}

void solve(){
    int n;
    cin >> n;
    
    vector<pi> a(n);
    for(auto& i : a){
        cin >> i.fir >> i.sec;
        i.fir--;i.sec--;
    }
    
    vi prefix(2*n);
    for(auto& i : a) prefix[i.fir]++,prefix[i.sec]--;
    for(int i{1}; i < 2*n; i++) prefix[i] += prefix[i-1];
    
    ll res = 0;
    for(auto& i : a){
        res += modpow(2, n-1-(!i.fir ? 0 : prefix[i.fir-1]));
        res %= MOD;
    }
    cout << res;
}

int main(){
    setio("help");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```