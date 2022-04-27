Not much to explain lol, pretty straightfoward. No way we're working with an array/vector, it will takes up to N^2. One key observation is that, only the top element matters.
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
    int n;
    cin >> n;

    map<ll, ll> mp;

    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        auto it = mp.upper_bound(x);
        if (it != mp.end()){
            (*(it)).sec--;
            if ((*(it)).sec == 0){
                mp.erase((*(it)).fir);
            }
        }
        if (!mp.count(x)) mp[x] = 0;
        mp[x]++;
    }

    ll total = 0;
    for(auto& i : mp){
        total += i.sec;
    }
    cout << total;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```