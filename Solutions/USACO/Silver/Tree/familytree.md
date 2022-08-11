This problem ain't that hard, it's just the output section that is super annoying, it's just about linking them, and the direction matter we link them together matters as well. 
```cpp
#include <bits/stdc++.h>
#include <limits>
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

map<string, vector<string>> adj;
map<string, vector<string>> adj1;
string a, b;
bool found;
vi rel;

void dfs(string cur, string prev){
    if (cur == b){
        found = 1;
        return;
    }
    //Checking from descendent
    for(auto& i : adj[cur]){
        if (i != prev){
            dfs(i, cur);
            if (found){
                rel.pb(-1);
                return;
            }
        }
    }

    //Checking from ancestor
    for(auto& i : adj1[cur]){
        if (i != prev){
            dfs(i, cur);
            if (found){
                rel.pb(1);
                return;
            }
        }
    }

}

void solve(){ 
    int n;
    cin >> n;
    cin >> a >> b;

    for(int i{}; i < n; i++){
        string f, t;
        cin >> f >> t;
        adj[f].pb(t);
        adj1[t].pb(f);
    }

    dfs(a, "");
    

    //Super annoying part
    int dir = 0;
    for(auto& i : rel){
        dir += i;
    }
    string res = "NOT RELATED";
    int cnt = 0;
    bool is = 0;
    if (dir < 0){
        reverse(all(rel));
        for(auto& i : rel) i = -i;
    }
    for(int i{sz(rel)-1}; i >= 0; i--){
        cnt += rel[i];
        if (rel[i] > 0){
            if (cnt == 1){
                res = "mother";
            }else if (cnt == 2){
                res = "grand-mother";
            }else{
                string grt = "great-";
                res = grt+res;
            }
            is = 1;
        }else{
            if (res == "mother"){
                res = "SIBLINGS";
                is = 0;
            }
            else if (res == "grand-mother"){
                res = "aunt";
                is = 1;
            }
            else if (sz(res) > 6 && res.substr(sz(res)-6, 6) == "mother"){
                string temp = "";
                for(int j{}; j < sz(res); j++){
                    if (res.substr(j, 5) == "grand") break;
                    else{
                        temp += res[j]; 
                    }
                }
                string aunt = "aunt";
                res = temp + aunt;
                is = 1;
            }else if (res.substr(sz(res)-4, 4) == "aunt"){
                res = "COUSINS";
                is = 0;
            }
        }
    }
    if (is){
        cout << (dir > 0 ? b : a) << " is the " << res << " of " <<  (dir > 0 ? a : b);
    }else{
        cout << res;
    }
}

int main(){
    setio("family");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```