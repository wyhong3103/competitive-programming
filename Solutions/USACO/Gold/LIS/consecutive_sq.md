Honestly, i don't even know if im doing dp, or more of greedy.
```
Anyways, the idea is simple, in order for one consecutive sequence to happen, a[i]-1 must exist, we can accomplish this using hash map/bst instead of a LIS dp array.

If a[i]-1 exist , we also must check whether a[i] exist, if it does, we only replace it if length of a[i]-1 >= a[i]

else if a[i]-1 doesn't exist, and a[i] doesn't exist, we create a new LIS with it

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

 
void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    map<int,pi> mp;
    vi ancestor(n);
    
    for(int i{}; i < n; i++){
        if (!mp.count(a[i]-1) && !mp.count(a[i])){
            mp[a[i]] = {i, 1};
            ancestor[i] = -1;
        }else if (mp.count(a[i]-1) && ((mp.count(a[i]) && mp[a[i]].sec <= mp[a[i]-1].sec) || (!mp.count(a[i])))){
            pi it = mp[a[i]-1];
            ancestor[i] = it.fir;
            it.fir = i;
            it.sec++;
            mp.erase(a[i]-1);
            mp[a[i]] = it;
        }
    }

    pi bst;
    for(auto& i : mp){
        if (i.sec.sec > bst.sec){
            bst = i.sec;
        }
    }

    cout << bst.sec << '\n';
    vi res;
    while (bst.fir != -1){
        res.pb(bst.fir);
        bst.fir = ancestor[bst.fir];
    }

    for(int i{sz(res)-1}; i >= 0; i--) cout << res[i]+1 << ' ';
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