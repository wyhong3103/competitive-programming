Try every combinators, either first number adds up to it, 2 first + 1 second, first + second + third. The reason we can do this is because, there's only 10 numbers in MOD 10.
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
            x %= 10;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }
 
        vector<pi> a;
        for(auto& i : mp){
            a.pb({i.fir, i.sec});
        }
 
        bool ok = 0;
 
        for(int i{}; i < sz(a); i++){
 
            if (a[i].sec >= 3 && (((a[i].fir)*3)%10) ==3) ok = 1;
 
            for(int j{i+1}; j < sz(a); j++){
 
                if (a[i].sec >= 2 && ((a[i].fir*2) + a[j].fir) % 10 == 3) ok =1; 
                if (a[j].sec >= 2 && ((a[j].fir*2) + a[i].fir) % 10 == 3) ok =1; 
 
                for(int k{j+1}; k < sz(a); k++){
 
                    if (((a[i].fir + a[j].fir + a[k].fir) % 10) == 3){
                            ok = 1;
                    }
                }
            }
        }
 
        cout << (ok ? "YES" : "NO" ) << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```