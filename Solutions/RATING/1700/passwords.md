```
Got the correct idea on searching for string t, which is by binary searching.

Basically, we could keep track of every substring that is valid (prefix == suffix).

And then binary search on it. The idea is that, if one of the string that has longer length doesn't exist in the middle (do not start from 0 and ends at n-1), then those that are longer simply doesn't exist, vice versa, shorter exist, we go for longer one.

But testing string equality takes too long, we can't solve it without string hashing.
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
    string s;
    cin >> s;

    vector<string> possible;
    int n = sz(s);

    string cur = "";
    for(int i{}; i < n-1; i++){
        cur += s[i];
        if (cur == s.substr(n-sz(cur),sz(cur))) possible.pb(cur);
    }

    int lo = 0, hi = sz(possible)-1;
    int res = -1;
    while (hi >= lo){
        int mid = lo + (hi-lo)/2;
        bool ok = 0;
        for(int i{1}; i < n-sz(possible[mid]); i++){
            if (s.substr(i, sz(possible[mid])) == possible[mid]){
                ok = 1;
                break;
            }
        }
        if (ok){
            res = mid;
            lo = mid+1;
        }else hi = mid-1;
    }

    cout << (res == -1 ? "Just a legend" : possible[res]);
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