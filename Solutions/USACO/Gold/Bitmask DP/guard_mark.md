```
DP state = subset S

DP value = {height, maximum safety factor we could get with the subset}

DP transition = dp[s] = max(dp[s], min(dp[s ^ (1 << j)].sec - cows[j].weight (if there was no cow beneath it, then INF), cows[j].strength))

For each cow that is going to be stacked, the safety factor of the stack is either the strength of the current cow, or the current safety factor - the weight such that there is cow beneath it.


For each subset s, we let each j (each bit 1) transition to it, and let the one with the maximum safety factor be it.

Base case = dp[0]
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

const int MXN = 20;
//{height, safety factor}
pll dp[1 << MXN];

struct Cow{
    ll h, w, s;
};

void solve(){
    ll n, h;
    cin >> n >> h;
    
    vector<Cow> cows(n);
    for(auto& i : cows) cin >> i.h >> i.w >> i.s;

    
    for(int i(1); i < (1 << n); i++) dp[i] = {-1,-1};
    dp[0] = {0,0};

    ll ans = -1;
    for(int i{1}; i < (1 << n); i++){
        for(int j{}; j < n; j++){
            if ((i & (1 << j)) && dp[i ^ (1 << j)].fir >= 0){
                dp[i].fir = dp[i ^ (1 << j)].fir + cows[j].h;
                dp[i].sec = max(dp[i].sec, min(((i^(1<<j)) == 0 ? INT_MAX : dp[i ^ (1 << j)].sec - cows[j].w), cows[j].s));
                if (dp[i].sec >= 0 && dp[i].fir >= h){
                    ans = max(dp[i].sec, ans);
                }
            }
        }
    }

    if (ans == -1){
        cout << "Mark is too tall";
    }else{
        cout << ans;
    }
}

int main(){
    setio("guard");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```