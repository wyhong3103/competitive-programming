```

Four distinct elmenets sums up to x.

We will iterate through the pair of the last two element, and then use a hash map to store the pairs that sums up to x, sorted by their endpoint. There is no need to sort it actually, we just need to make sure that we iterate in an ascending order of the endpoints. And then we can easily binary search the first pair (first two elemtn) s.t the end point of the pair (the second elmeent index) is strictly smaller than the first point of the last two element.

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
 
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
 
void solve(){
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for(auto& i :  a) cin >> i;
 
    //{x : {{r, l},...}}
    unordered_map<int, vector<pi>, chash> mp;
 
    for(int i{}; i < n; i++){
        for(int j{}; j < i; j++){
            if (mp.count(x - (a[i]+a[j]))){
                auto& p = mp[x-(a[i]+a[j])];
 
                int lo = 0, hi = sz(p)-1;
 
                while (hi > lo){
                    int mid = lo + (hi-lo+1)/2;
                    if (p[mid].fir >= j) hi = mid-1;
                    else{
                        lo = mid;
                        break;
                    }
                }
 
                if (lo >= 0 && p[lo].fir < j){
                    cout << p[lo].sec+1 << ' ' <<  p[lo].fir+1 << ' ' << j+1 << ' ' << i+1 << '\n';
                    return;
                }
            }
            mp[a[i] + a[j]].pb({i, j});
        }
    }
    cout << "IMPOSSIBLE";
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