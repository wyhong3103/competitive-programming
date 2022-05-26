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
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto& i :a) cin >> i;
 
    int ans = INT_MAX;
    for(int i{}; i < 10; i++){
        vi temp(10);
        for(auto& s : a){
            for(int j{}; j < 10; j++){
                if (s[j]-'0' == i){
                    temp[j]++;    
                }
            }
        }
 
        pi mx{-1,-1}; 
        for(int j{}; j < sz(temp); j++){
            if (temp[j] > mx.sec){
                mx.fir = j;
                mx.sec = temp[j];
            }
            else if (temp[j] == mx.sec && j > mx.fir){
                mx.fir = j;
                mx.sec = temp[j];
            }
        }
        ans = min(ans, ((mx.sec-1) * 10) + mx.fir);
    }
    cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}

```