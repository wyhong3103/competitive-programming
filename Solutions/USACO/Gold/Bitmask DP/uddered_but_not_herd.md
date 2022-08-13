This doesn't work.
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
    string s;
    cin >> s;
    
    int total = 0;
    set<char> st;
    for(auto& i : s){
        st.insert(i);
    }

    total = sz(st);

    vector<char> a(all(st));

    vector<vi> need(total+1, vi (total));

    vi dp(1 << total);

    for(auto& i : s) need[0][lower_bound(all(a), i) - a.begin()]++;

    for(int i{}; i < total; i++){
        for(int j{}; j < total; j++){
            if (i == j) continue;
            //append j to i
            bool with_i = 0;
            for(int k{}; k < sz(s); k++){
                if (s[k] == a[j]){
                    if (with_i) with_i = 0;
                    else need[i+1][j]++;
                }
                else if (s[k] == a[i]){
                    if (!with_i) with_i = 1;
                }
            }
        } 
    }

    for(int i{1}; i < (1 << total); i++){
        dp[i] = INT_MAX;
        for(int j{}; j < total; j++){
            if (i & (1 << j)){
                int mn = need[0][j];
                for(int k{}; k < total; k++){
                    if (j != k && (i & (1 << k))) mn = min(need[k+1][j], mn);
                }
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + mn);
            }
        }
    }

    cout << dp[(1 << total)-1];
}

int main(){
    //setio("input");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```