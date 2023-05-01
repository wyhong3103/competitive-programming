```

DP with Trie

We could do this with string hashing

But a Trie solution makes it easier, we check each substring of s, check if there's any given dictionary words fit that substring, and then do a transition from it.

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

const int MOD = 1e9 + 7;
const int MX = 5005;
ll dp[MX];

struct Trie{
    map<char, Trie> c;
    bool mark = false;

    void insert(string& s, int pos){
        if (sz(s) != pos) c[s[pos]].insert(s, pos+1);
        else mark =true;
    }

    void dfs(string& s, int pos, int at){
        if (mark){
            dp[pos-1] = (dp[pos-1] + dp[at]) % MOD;
        }
        if (pos > sz(s)) return;
        for(auto& i : c){
            if (i.fir == s[pos-1]){
                i.sec.dfs(s, pos+1, at);
            }
        }  
    }
};

void solve(){
    string s;
    cin >> s;

    int k;
    cin >> k;
        
    Trie tr;
    
    for(int i{}; i < k; i++){
        string temp;
        cin >> temp;
        tr.insert(temp, 0);
    }
    dp[0] = 1;
    for(int i{1}; i <= sz(s); i++){
        tr.dfs(s, i, i-1);
    } 
    cout << dp[sz(s)];
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