Prime factorization + a little combinatorics to find the number of divisors
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
        for(int i{2}; i * i <= n; i++){
            while (n % i == 0){
                if (!mp.count(i)) mp[i] = 0;
                mp[i]++;
                n /= i;
            }
        }
        if (n > 1){
            if (!mp.count(n)) mp[n] = 0;
            mp[n]++;
        }

        ll ans = 1;
        for(auto& i : mp){
            ans *= i.sec+1; 
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