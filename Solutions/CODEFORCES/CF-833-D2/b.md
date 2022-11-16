```

Because there are only 10 characters.

Worst case scenario for a substring to be a diverse substring, the character length is only 100! Anything more than that is definitely not a diverse substring. The idea is if we have 10 distinct character, frequency of each character can be at most 10 only. 

So we could bruteforce every substring of length 1-100!

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
 
    string s;
    cin >> s;
 
    ll res = 0;
    for(int i{}; i < n; i++){
        int mx = 0;
        int dis = 0;
        vi cnt(10);
        for(int j{}; j < 100; j++){
            if (i+j >= n) break;
            int x = s[i+j]-'0';
            if (!cnt[x]) {
                dis++;
            }
            cnt[x]++;
            mx = max(mx, cnt[x]);
            res += (dis >= mx);
        }
    }
    cout << res << '\n';
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