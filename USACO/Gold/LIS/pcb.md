This question is all about finding the minimum number of LIS to cover a sequence. And for some reasons, the answer is equivalent to the length of longest non-increasing subsequence (l[i] >= l[i+1]), well one thing we're for sure is that, the number of LIS needed to cover the sequence >= length of longest non-increasing subsequence, this is because no two element in L-NIS can be in the same LIS. For the part that number of LIS needed to cover the sequence = length of longest NIS, Dilworth's theorem is the proof.
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

const int MX = 1e6+5;
 
void solve(){
    int n;
    cin >> n;

    vi a(MX);
    fill(all(a), -1);
    for(int i{}; i < n; i++){
        int f,t;
        cin >> f >> t;
        a[f] = t;
    }
 
    vi dp(MX+1);
    fill(all(dp), -INT_MAX);
    dp[0] = -dp[0];
 
    for(int i{}; i < MX; i++){
        if (a[i] == -1) continue;
        int lo = 0, hi = MX-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (a[i] <= dp[mid]){
                lo = mid;
            }else hi = mid-1;
        }
        if (dp[lo+1] < a[i]) dp[lo+1] = a[i];
    }
 
    int mx = 0;
    for(int i{1}; i <= MX; i++){
        if (dp[i] != -INT_MAX) mx = max(mx, i);
    }
 
    cout << mx;
}
 
 
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}

```