Binary search just made this question so much simpler, the old me would have use greedy + sets to do it. Anyways, by using binary search + math, the problem has became much more simpler. Basically, we split each group into min(a[i], expected group), for each group, we do the same. And we can just check whether the final number of people is >= expected * k. This will always be true, bc we made sure that no group will gives more than expected group (number of people).
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
    int k, n;
    cin >> k >> n;


    vll a(n);
    for(auto& i : a){
        cin >> i;
    }

    auto good = [&](ll mid){
        ll sm = 0;
        for(auto& i : a){
            sm += min(i, mid);
        }
        return sm >= mid * k;
    };

    ll lo = 0, hi = 1e12;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (good(mid)){
            lo = mid;
        }else hi = mid-1;
    }

    cout << lo;
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