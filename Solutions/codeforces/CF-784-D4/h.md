The solution is pretty simple, count the number of j-th bit of the entire sequence, and only fill up those that can be filled as n. 
```
For example, say n = 3, and the sequence:

4 1 1

And say k = 4

After counting the j-th bit we got ourself a sequence like this

30 - 0
29 - 0
..
..
..
..
2 - 1 (2^2 = 4)
1 - 0
0 - 2 (2^0 = 1)

So we got k = 3, and we start from 30, and apparently, we can fill up 30 to 3, so we will fill it up, then we only left with k = 1, there is no number that can be filled up between 29 to 1, but 0 can be filled up with just 1, so we will fill it up

And finally the answer is 

2^30 + 2^0
```
```cpp
#include <bits/stdc++.h>
#include <limits>
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
 
        vector<pi> mp;
        for(int i{30}; i >= 0; i--){
            mp.pb({i, 0});
        } 
 
        vector<ll> a(n);
        for(auto& i : a){
            cin >> i;
            for(int j{30}; j >= 0; j--){
                if ((i >> j) & 1){
                    mp[30-j].sec++; 
                }
            }
        }
 
        ll ans = 0;
        for(auto& i : mp){
            if (i.sec + k >= n){
                k -= min(k, n-i.sec);
                i.sec = n;
            }
            if (i.sec == n){
                ans += 1 << i.fir;
            }
        }
        cout << ans << '\n';
 
 
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```