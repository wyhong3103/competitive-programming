I had it correct hours ago, but man fuck, long input from cses doesn't work the same if i input it in my cmd, but works when i've submitted it! But anyways, after seeing cph, i've gained insights and more understanding for the transition.
```
Basically

state = dp[i][j] = minimum number of operations that are needed to make prefix i of string a and prefix j of string b the same

transition = dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) if a[i] != b[j], else it's just dp[i-1][j-1]

dp[i-1][j] and dp[i][j-1] represents inserting/adding character
dp[i-1][j-1] represents replacing the character

We kind of need to take care on the edge cases, where i = 0 or j = 0, when i = 0 or j = 0, and a[i] == b[j], we can't refer to dp[i-1][j-1] so the answer is simply i (from 0 indexed), because when i = 0 or j = 0, it's just similar to not having the need to remove/replace one character but others still have to be removed. When a[i] != b[j], we set it to infinity as it is unreachable.
```
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
    string s1, s2;
    cin >> s1 >> s2;
    
    vector<vi> dp(sz(s1));
    for(auto& i : dp) i.resize(sz(s2));
 
    for(int i{}; i < sz(s1); i++){
        for(int j{}; j < sz(s2); j++){
            if (!i && !j){
                dp[i][j] = !(s1[i] == s2[j]);
            }
            else if (s1[i] == s2[j]){
                dp[i][j] = (!i || !j ? (!i ? j : i) : dp[i-1][j-1]);
            }else{
                dp[i][j] = min({(!i || !j ? INT_MAX : dp[i-1][j-1]), (!i ? INT_MAX : dp[i-1][j]), (!j ? INT_MAX : dp[i][j-1])}) + 1;
            }
        }
    }
 
    cout << dp[sz(s1)-1][sz(s2)-1];
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