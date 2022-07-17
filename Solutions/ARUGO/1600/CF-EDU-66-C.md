Totally have no idea how i bricked this problem the first time, it was so easy....
```
Because we want to find the minimal distance between, (k+1)-th node closest point from x and x

That literally means we want the minimal size of the interval of k+1 points across the all the points we got.

And the answer is literally the middle of the starting and ending point of the minimal interval

This runs in O(N), a faster way to do it is with binary search, since it's already sorted.
```
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    vi a(n);
    for(auto& i : a){
        cin >> i;
    }
 
    //{start, end, dist}
    vector<ll> res = {INT_MAX, -1,-1};
    for(int i{}; i < n-k; i++){
        if (abs(a[i+k]-a[i]) < res[0]){
            res[0] = abs(a[i+k]-a[i]);
            res[1] = i;
            res[2] = i+k;
        }
    }
 
    cout << (a[res[1]]+a[res[2]])/2 << '\n';
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