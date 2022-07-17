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
    string s;
    cin >> s;
 
    ll p;
    cin >> p;
 
    ll cur = 0;
    map<char,int> mp;
    for(auto& i : s){
        if (!mp.count(i)) mp[i] = 0;
        mp[i]++;
        cur += (i - 'a') + 1;
    }
 
    while (cur > p){
        auto it = --mp.end();
        cur -= it->fir - 'a' + 1;
        it->sec--;
        if (it->sec == 0) mp.erase(it->fir);
    }
 
    string res;
    for(auto& i :s){
        if (mp.count(i) && mp[i]){
            res += i;
            mp[i]--;
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