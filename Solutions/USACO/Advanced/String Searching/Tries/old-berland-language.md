```

We can dfs on trie-like structure, but we dont really need trie

Time complexity is O(N^2)

A simple dfs on the 1/0 trie structure would work, the idea is no word can be prefix of another word, so if the current prefix is a word, we dont continue explore down, that can be achieved with dfs.

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


void dfs(int dep, int& p, vi& order, string& s, vector<string>& res){
    if (dep ==order[p]){
        res.pb(s);
        p++;
        return;
    }
    for(auto& i : {'1', '0'}){
        s.pb(i);
        dfs(dep+1, p, order, s, res);
        if (p == sz(order)) return;
        s.pop_back();
    }
}

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    vi order = a;
    sort(all(order));

    vector<string> res;
    string s = "";
    int p = 0;
    dfs(0, p, order, s, res);

    if (p != sz(order)){
        cout << "NO";
    }else{
        cout << "YES" << '\n';
        vector<vector<string>> len(1001);
        for(auto& i: res) len[sz(i)].pb(i);
        for(auto& i : a){
            cout << len[i].back() << '\n';
            len[i].pop_back();
        }
    }
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