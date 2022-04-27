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
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
 
        for(int i{}; i < n; i++){
            int x;
            cin >> x;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++;
            //I think we can check in here instead
        }
 
        bool found = false;
        for(auto& i : mp){
            if (i.sec >= 3){
                cout << i.fir << '\n';
                found = true;
                break;
            }
        }
        if (found) continue;
        else cout << -1 << '\n';
 
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```