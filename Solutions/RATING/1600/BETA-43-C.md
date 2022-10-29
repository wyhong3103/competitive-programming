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

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt_h{};
    vi prefix_tg(n);
    for(int i{}; i < n; i++){
        if (s[i] == 'T') prefix_tg[i]++;
        else cnt_h++;
        if (i) prefix_tg[i] += prefix_tg[i-1];
    }

    int ans = INT_MAX;
    for(int i{}; i <= n-cnt_h; i++){
        ans = min(ans, prefix_tg[i+(cnt_h-1)] - (!i ? 0 : prefix_tg[i-1]));
    }
    for(int i{}; i < cnt_h; i++){
        ans = min(ans, prefix_tg[i] + (prefix_tg[n-1]-prefix_tg[n-1-(cnt_h-i-1)]));
    }
    cout << ans;
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