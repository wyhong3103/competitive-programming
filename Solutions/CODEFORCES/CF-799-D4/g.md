When i-th is doubled it has to be bigger than i-1-th, this property has to be true for every element from i to i+k, then we can simply do sliding windows.
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
 
        vector<ll> a(n);
        for(auto& i : a) cin >> i;
 
        vi prefix(n);
        prefix[0] = 1;
        for(int i{1}; i < n; i++){
            if (a[i]*2 > a[i-1]){
                prefix[i]++;
            }
            prefix[i] += prefix[i-1];
        }
 
        int cnt = 0;
        for(int i{}; i < n-k; i++){
            if ((prefix[i+k] - prefix[i]+1) == k+1){
                cnt++;
            }
        }
        
        cout << cnt << '\n';
    }     
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```