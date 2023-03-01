```

Let '2-component' be all the compeitions that have an interval of 2.

Notice that each "2-component" can either be at odd or even. We need to make sure after combining all the 2-component, we have the shortest length!

We can easily do that with dp.

dp[i][j] = min odd number so far at i-th "2-component" with j even number

It's like a knapsack

Actually we don't really need to store the odd number (because we can know the total odd number we have just by looking at the total even number) , we just need to see if we can reach the state or no, at the end we will find the one that has smallest length max(mx, min(even*2, (odd-1)*2 + 1))

And then with that, we just try to simulate it, and try to place all the '1-component' see if its possible


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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 5005;
 
//[i-th][number of even] = min odd
int dp[MX][MX];
//from even or odd
int from[MX][MX];
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<pair<int,pi>> a(n);
    
    vi two;
    for(int i{}; i < n; i++){
        cin >> a[i].sec.fir >> a[i].sec.sec;
        a[i].fir = i;
        if (a[i].sec.sec == 2) two.pb(i);
    }
 
    memset(dp, -1, sizeof(dp));
    
    vi parity(n);
 
    if (sz(two)){
        dp[0][0] = a[two[0]].sec.fir;
        //from odd
        from[0][0] = 1;
        dp[0][a[two[0]].sec.fir] = 0;
        //from even
        from[0][a[two[0]].sec.fir] = 0;
 
        for(int i{1}; i < sz(two); i++){
            for(int j{}; j < m; j++){
                if (dp[i-1][j] != -1){
                    int amt = a[two[i]].sec.fir;
                    if (j+amt < m){
                        dp[i][j+amt] = dp[i-1][j];
                        from[i][j+amt] = 0;
                    }
                    dp[i][j] = dp[i-1][j] + amt;
                    from[i][j] = 1;
                }
            } 
        }
 
        pi mn{INT_MAX, -1};
 
        for(int i{}; i < m; i++){
            if (dp[sz(two)-1][i] != -1 && dp[sz(two)-1][i]){
                mn = min(mn, {max(i*2, (dp[sz(two)-1][i]-1)*2+1), i});
            }
        }
 
        int cur = sz(two)-1;
        while (cur >= 0){
            parity[two[cur]] = from[cur][mn.sec];
            mn.sec = (parity[two[cur]] ? mn.sec : mn.sec-a[two[cur]].sec.fir);
            cur--;
        }
 
    }
 
 
    vi day(m,-1);
 
    bool ok = 1;
    for(auto& i : two){
        bool found = 0;
        for(int j{1-parity[i]}; j < m; j+=2){
            found = day[j] == -1;
            if (found){
                day[j] = i;
                a[i].sec.fir--;
            }
            if (!a[i].sec.fir) break;
        }
        ok &= !a[i].sec.fir;
    }
 
    for(int i{}; i < n; i++){
        if (a[i].sec.sec == 1 && a[i].sec.fir){
            for(int j{}; j < m; j++){
                if (day[j] == -1 && (j+1 < m && day[j+1] == -1)){
                    for(int k{j}; k < m; k++){
                        day[k] = i;
                        a[i].sec.fir--;
                        if (!a[i].sec.fir) break;
                    }
                    break;
                }
            }
            ok &= !a[i].sec.fir;
        }
    }
 
    if (!ok){
        cout << -1;
        return;
    }
 
 
    vi res(n, INT_MAX);
 
    for(int i{}; i < m; i++){
        if (day[i] == -1) continue;
        res[day[i]] = min(res[day[i]], i);
    }
 
    for(auto& i : res) cout << i+1 << ' ';
    
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