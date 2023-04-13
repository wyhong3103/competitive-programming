```

We can binary search on the answer.

How to check?

For an answer n, we try to place all the most frequent element on all n cell first, until we exhaust them until n, if we have reached n we can start stacking it up on the cell, and check if the cell above is the same as below.

Why this work?

|    x    |  y  |

Let this be the bottom row, 2 element with the most frequency. In this case, all block of x is finished. What if y haven't finish, it is possible for y to be placed above another y?

Not hard to see that its impossible, since if y need to be stacked on y, it has to be larger than x, so no elements would be stacked on the same block, if we are to place them in such way.

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
    int n;
    cin >> n;
 
    map<int,int> mp;
 
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    
    vector<pi> a;
    for(auto& i : mp){
        a.pb(i);
    }
 
    sort(all(a), [&](pi a, pi b){
        return a.sec > b.sec;
    });
 
    int lo = max(mp.rbegin()->sec, (n+1)/2), hi = n;
    while(hi > lo){
        int mid = lo + (hi-lo)/2;
         
        vi bot(mid);
        int at = 0;
        bool ok = 1;
        for(auto& i : a){
            for(int j{}; j < i.sec; j++){
                if (at+j >= mid){
                    ok &= bot[(at+j) % mid] != i.fir;
                }else{
                    bot[at+j] = i.fir;
                }
            } 
            at += i.sec;
        }
        if (ok) hi = mid;
        else lo = mid+1;
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