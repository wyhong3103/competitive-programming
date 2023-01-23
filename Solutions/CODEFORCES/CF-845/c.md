```

Bricked this problem during contest, cus thinking in the wrong direction.

We can use sieve-like method, to compute the factors for all number < m in O(n log n).

But how do we find the minimal difference??

Two pointers

We can have two pointer starts at index 0, and then notice that when we increase the right pointer, the more factors for each number we have.

So we can increase it until it hits m, and then increase the left pointer, to make it insufficient again, and then do right again.

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
 
 
const int MX = 1e5 + 5;
vector<int> factor[MX];
int freq[MX];
 
void gen(){
    for(int i{2}; i < MX; i++){
        for(int j{i}; j < MX; j += i) factor[j].pb(i);
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    
    vi a(n);
    for(auto& i : a) cin >> i;
 
    sort(all(a));
 
    int mn = INT_MAX;
    int l = 0, r = 1;
    int cnt = 1;
 
    for(auto& i : factor[a[0]]){
        if (i > m) break;
        freq[i]++;
        cnt += (freq[i] == 1);
    }
 
    if (cnt == m){
        cout << 0 << '\n';
        for(auto& i : factor[a[0]]){
            if (i > m) break;
            freq[i]--;
        }
        return;
    }
 
    while (r < n){ 
        if (cnt < m){
            for(auto& i : factor[a[r]]){
                if (i > m) break;
                freq[i]++;
                cnt += (freq[i] == 1);
            }
            r++;
        }else{
            for(auto& i : factor[a[l]]){
                if (i > m) break;
                freq[i]--;
                cnt -= (freq[i] == 0);
            }
            l++;
        }
        if (cnt == m){
            mn = min(mn, a[r-1]-a[l]);
        }
    }
 
    while (l < n){
        if (cnt == m){
            mn = min(mn, a[n-1]-a[l]);
        }
        for(auto& i : factor[a[l]]){
            if (i > m) break;
            freq[i]--;
            cnt -= (freq[i] == 0);
        }
        l++;
    }
 
 
    if (mn == INT_MAX) cout << -1 << '\n';
    else{
        cout << mn << '\n';
    }
 
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    gen();
    while(t--){
        solve();
    }
    return 0;
}
```