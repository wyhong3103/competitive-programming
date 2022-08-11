Didn't managet to solve it, so the solution below is actually wrong, I am not sure if i understand the problem completely
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
        map<string, int> mp;
        vector<string> a;
 
        ll ans = 0;
        for(int i{}; i < n; i++){
            string s;
            cin >> s;
            if (!mp.count(s)){
                mp[s] = 0;
                a.pb(s);
            }
            mp[s]++;
            for(int j{}; j < sz(a); j++){
               bool ok = false;
                if (s[0] == a[j][0] && s[1] != a[j][1]) ok = true;
                if (s[1] == a[j][1] && s[0] != a[j][0]) ok = true;
                if (s[0] == a[j][1] && s[1] != a[j][0]) ok = true;
                if (s[1] == a[j][0] && s[0] != a[j][1]) ok = true;
                if (ok){
                    ans += mp[a[j]];
                } 
            }
        }
        cout << ans << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```