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
    int n;
    cin >> n;
 
    set<int> s;
    for(int i{1}; i <= n; i++){
        s.insert(i);
    }
 
    int cur = 1;
    while (n--){
        auto it = s.begin();
        while (it != s.end()){
            if ((*it) % cur != 0){
                break;
            }
            it++;
        }
        if (it == s.end()) --it;
        s.erase(*it);
        cout << (*it) << ' ';
        cur++; 
    }
    cout << '\n';
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