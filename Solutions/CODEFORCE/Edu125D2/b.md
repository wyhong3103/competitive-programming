Simple construction, this should've been A level question.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
    int t;
    cin >> t;
    while(t--){
        ll n,b,x,y;
        cin >> n >> b >> x >>y;
        n++;
        vector<ll> a(n);

        ll ans{};
        for(int i{1}; i < n; i++){
            if (a[i-1] + x <= b){
                a[i] += (a[i-1] + x);
            }else{
                a[i] += (a[i-1] - y);
            }
            ans += a[i];
        }
        cout << ans << '\n';
    }
}
int main(){
//   setIO("reduce");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```