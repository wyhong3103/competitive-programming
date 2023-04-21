```

Bruteforce every letter i, let it be the final letter

For every substring that is not letter i, find the max length 

The minimal needed is just log2(max length)

Becuse for each substring of that, we cannot select adjacent, so we will have to log2 at least, as each time we can select half of them.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    string s;
    cin >> s;
 
    int res = INT_MAX;
    for(int i{}; i < 26; i++){
        int cur = 0;
        int cnt = 0;
        for(int j{}; j < sz(s); j++){
            if (s[j]-'a' == i) {
                cnt = max(cnt, cur);
                cur = 0;
            }else{
                cur++;
            }
        }
        cnt = max(cur, cnt);
 
        int temp = 0;
        while (cnt){
            cnt /= 2;
            temp++;
        }
        res = min(res, temp);
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