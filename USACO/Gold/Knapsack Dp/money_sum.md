Same method from previous knapsack problems.
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

const int MAX = 1e5+5;

bool dp[MAX];
bool dp2[MAX];

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    dp[0] = 1;
    dp2[0] = 1;
    for(int c{}; c < n; c++){
        for(int i{1}; i < MAX; i++){
            if (i - a[c] >= 0){
                dp[i] = dp2[i] || dp2[i-a[c]];
            }
        }
        for(int i{1}; i < MAX; i++){
            dp2[i] = dp[i];
        }
    }

    vi ans;
    for(int i{1}; i < MAX; i++){
        if (dp[i]) ans.pb(i);
    }

    cout << sz(ans) << '\n';
    for(auto& i : ans) cout << i << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```