```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n;
    cin >> n;
 
    vector<string> a(n);
    set<string> s;
    for(auto& i : a){
        cin >> i;
        s.insert(i);
    }
 
    string res = "";
    for(int i{}; i < n; i++) res += '0';
 
    for(int i{}; i < n; i++){
        for(int j{}; j < sz(a[i])-1; j++){
            if (s.count(a[i].substr(0, j+1)) && s.count(a[i].substr(j+1,sz(a[i])-(j+1)))){
                res[i] = '1';
            }
        }
    }
    cout << res << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```