We just have to identify the starting point of the rotation.
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
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    ll n, q;
    cin >> n >> q;
 
    string s;
    cin >> s;
 
    ll offset = 0;
    while(q--){
        int t, x;
        cin >> t >> x;
        if (t == 1){
            offset += x;
        }
        else{
            cout << s[(((((n)-offset)%n) + n) + (x-1))%n] << '\n';
        }
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```