```

Two pointers

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
    int n, m;
    cin >> n >> m;

    vll a(n);
    for(auto& i : a) cin >> i;

    map<ll, int> freq;
    ll cnt = 0;

    int l = 0, r = 0;
    while (r < n){
        if (sz(freq) < m || (sz(freq) == m && freq.count(a[r]))){
            freq[a[r]]++;
            r++;
        }else{
            freq[a[l]]--;
            if (!freq[a[l]]) freq.erase(a[l]);
            cnt += r-l;
            l++;
        }
    }

    while (l < n){
        cnt += (n-1)-l+1;
        l++;
    }

    cout << cnt;
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