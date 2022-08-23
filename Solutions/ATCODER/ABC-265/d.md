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
 
bool valid(int at, int cur, int n, vll& prefix, vll& val){
    if (cur >= 3){
        return 1;
    }
    if (at >= n){
        return 0;
    }
 
    int found = -1;
    int lo = at, hi = n-1;
    while (hi >= lo){
        int mid = lo + (hi-lo)/2;
        ll sum = prefix[mid]-(!at ? 0 : prefix[at-1]);
 
        if (sum == val[cur]) found = mid;
        if (sum > val[cur]){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
 
    if (found != -1){
        return valid(found+1, cur+1, n, prefix, val);
    }else{
        return 0;
    }
}
 
void solve(){
    int n;
    cin >> n;
 
    vll val(3);
    for(auto& i : val) cin >> i;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    vll prefix(n);
    for(int i{}; i < n; i++){
        prefix[i] += a[i];
        if (i) prefix[i] += prefix[i-1];
    }
 
    bool ok = 0;
    for(int i{}; i < n; i++){
        if (valid(i, 0, n, prefix, val)){
            ok = 1;
        }
    }
 
    cout << (ok ? "Yes" : "No");
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