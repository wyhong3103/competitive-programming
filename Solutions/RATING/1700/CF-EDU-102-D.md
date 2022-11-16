```

It's not hard to see that, the number of distinct value between a range is simply the max-mn+1! 

So how do we go about doing this problem??

Here is how

For every [l,r] given

We can tell directly how many distinct value we're given from [0:l-1], it's simply the prefix_mx - prefix_min.

And the current value is simply prefix_sum [0:l-1]

Now we simply need to know how much do we gain/lose from [r+1:n-1]

The idea is simple, we could find the suffix max / suffix min, suffix max - prefix_sum[r-1] is simply the max we gain in that suffix! same goes to suffix min!

We could simply check if the max/min gained added to the current number (prefix_sum[0:l-1]) will change the max and min of the value!

Answer is simply max-min+1

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

    string s;
    cin >> s;

    vi pref_sm(n);
    for(int i{}; i < n; i++){
        pref_sm[i] += (s[i] == '+' ? 1 : -1);
        if (i) pref_sm[i] += pref_sm[i-1];
    }

    vi pref_mx(n);
    vi pref_mn(n);
    vi suf_mx(n);
    vi suf_mn(n);
    for(int i{}; i < n; i++){
        pref_mx[i] = pref_sm[i];
        if (i) pref_mx[i] = max(pref_mx[i-1], pref_mx[i]);
        pref_mn[i] = pref_sm[i];
        if (i) pref_mn[i] = min(pref_mn[i-1], pref_mn[i]);
    }
    for(int i{n-1}; i >= 0; i--){
        suf_mx[i] = pref_sm[i];
        if (i < n-1) suf_mx[i] = max(suf_mx[i+1], suf_mx[i]);
        suf_mn[i] = pref_sm[i];
        if (i < n-1) suf_mn[i] = min(suf_mn[i+1], suf_mn[i]);
    }

    while(m--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        int mn = min(0, (!l ? 0 : pref_mn[l-1])), mx = max(0, (!l ? 0 : pref_mx[l-1]));
        int mn_gain = (r >= n-1 ? 0 : suf_mn[r+1]-pref_sm[r]), mx_gain = (r >= n-1 ? 0 : suf_mx[r+1]-pref_sm[r]);
        int cur = (!l ? 0 : pref_sm[l-1]);
        if (mn_gain >= 0 && mx_gain >= 0){
            cout << max(cur+mx_gain, mx)-mn+1 << '\n';
        }else if (mn_gain < 0 && mx_gain < 0){
            cout << mx-min(cur+mn_gain, mn)+1 << '\n';
        }else{
            cout << max(mx, cur+mx_gain) - min(mn, cur+mn_gain) + 1 << '\n';
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