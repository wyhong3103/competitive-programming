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
    
    vll a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
 
 
    //i-th tea will be drunk by j >= i
    //j-th person will keep drinking bi until it's up
    //for i-th tea find the time where it will finish
    //if j finsh it, for every x, x < j will drink b_x
    //range query
 
    vi diff(n+1);
    
    vll pref(n);
    for(int i{}; i < n; i++){
        pref[i] = b[i];
        if (i) pref[i] += pref[i-1];
    }
 
    vll cnt(n);
 
    for(int i{}; i < n; i++){
        int lo = i, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (pref[mid]-(!i ? 0 : pref[i-1]) >= a[i]) hi =mid;
            else lo = mid+1;
        }
        diff[i]++;
        if (pref[lo]-(!i ? 0 : pref[i-1]) >= a[i]){
            cnt[lo] += a[i]-((!lo ? 0 : pref[lo-1])-(!i ? 0 : pref[i-1]));
            diff[lo]--;
        }
    }
 
    vi preffin(n);
    for(int i{}; i <n; i++){
        preffin[i] = diff[i];
        if (i) preffin[i] += preffin[i-1];
    }
 
    for(int i{}; i< n; i++){
        cout << cnt[i]+(preffin[i]*b[i]) << ' ';
    }
    cout << '\n';
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