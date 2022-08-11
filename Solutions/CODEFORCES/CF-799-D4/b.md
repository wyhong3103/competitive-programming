Sum of frequency of every number - n, (subtract n because we want to leave as much distinct as possible). If the result is an odd number, that means there's one number which doesn't have a pair number, so we will have to sacrifice one distinct number.
```cpp
#include <bits/stdc++.h>
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
        }
        
        int cnt = 0;
        for(auto& i : mp){
            cnt += i.sec-1; 
        } 
 
        if (cnt % 2){
            cout << sz(mp)-1 << '\n';
        }else cout << sz(mp) << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```