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
    int n,x,y,z;
    cin >> n >> x >> y >> z;
 
    vi a(n);
    vi b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
 
    set<int> available;
    for(int i{}; i < n; i++) available.insert(i);
 
    set<int> res;
    map<int,set<int>> math;
    map<int, set<int>> english;
    map<int,set<int>> total;
    for(int i{}; i < n; i++){
        math[a[i]].insert(i);
        english[b[i]].insert(i);
        total[a[i]+b[i]].insert(i);
    }
    
    while (x){
        auto it = (((--math.end())->sec).begin());
        if (available.count(*it)){
            x--;
            res.insert(*it);
        }
        available.erase(*it);
        ((--math.end())->sec).erase(*it);
        if (((--math.end())->sec).empty()) math.erase((--math.end())->fir);
    }
 
    while (y){
        auto it = (((--english.end())->sec).begin());
        if (available.count(*it)){
            y--;
            res.insert(*it);
        }
        available.erase(*it);
        ((--english.end())->sec).erase(*it);
        if (((--english.end())->sec).empty()) english.erase((--english.end())->fir);
    }
 
    while (z){
        auto it = (((--total.end())->sec).begin());
        if (available.count(*it)){
            z--;
            res.insert(*it);
        }
        available.erase(*it);
        ((--total.end())->sec).erase(*it);
        if (((--total.end())->sec).empty()) total.erase((--total.end())->fir);
    }
 
    for(auto& i: res) cout << i+1 << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
```