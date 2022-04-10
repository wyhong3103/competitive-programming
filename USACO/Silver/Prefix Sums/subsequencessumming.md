https://www.youtube.com/watch?v=wXNhLjiuTgw
<br>
I do not solve this problem, I couldn't think of the solution.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()

using namespace std;
using vi = vector<int>;
using ll = long long;

void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi f(7);
    vi l(7);
    for(auto& i : a) cin >> i;

    fill(all(f),1000000);

    int currentprf = (a[0] % 7);
    f[currentprf] = 0; l[currentprf] = 0;
    for(int i{1}; i < n; i++){
        currentprf = ((currentprf + a[i]) % 7);
        f[currentprf] = min(f[currentprf], i);
        l[currentprf] = max(l[currentprf], i);
    }

    int ans = 0;
    for(int i{}; i < 7; i++){
        ans = max(ans, l[i] - f[i]);
    }

    cout << ans;

}


int main(){
    setio("div7");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```