```

The idea is to do dfs on Trie, again.

We are going to remove every letter if its not in a "good" path, a "good" path is a path with the longest string.

Let's prove that we should always keep the longest string by induction.


Base Case

When we node x, x has two linked list like children, its obvious that we should keep the longest one, and remove on the other one.

Now as we go up to the ancestor of x, all the sibling of x, have their own good path (after excluding/removing those bad path), we are only going to pick the one with the longest for the same reason.

We could repeat the process to the root node, the good path will be the path with the longest string.
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

struct Trie{
    map<char, Trie> c;
    bool mark = false;
    int len = 1;

    void insert(string& s, int pos){
        if (pos != sz(s)) c[s[pos]].insert(s, pos+1);
        else mark = true;
    }

    int dfs(){
        int mx = 0;
        for(auto& i : c){
            mx = max(mx, i.sec.dfs());
        } 
        len += mx;
        return len;
    }

    void dfs2(bool good, vector<char>& res){
        if (mark) res.pb('P');
        pi bst = {-1, 0};
        if (good){
            for(auto& i : c){
                bst =max(bst, {i.sec.len, i.fir}); 
            }
        }

        for(auto& i : c){
            if (i.fir != bst.sec){
                res.pb(i.fir);
                i.sec.dfs2(0, res);
            }
        }
        if (bst.fir != -1){
            res.pb(bst.sec);
            c[bst.sec].dfs2(1, res);
        }
        if (!good) res.pb('-');
    }
    
};

void solve(){
    int n;
    cin >> n;

    Trie tr;

    for(int i{}; i < n; i++){
        string s;
        cin >> s;
        tr.insert(s, 0);
    }

    vector<char> res;

    tr.dfs();
    tr.dfs2(1, res);
    cout << sz(res) << '\n';
    for(auto& i :res) cout << i << '\n';
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