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
        cout << "Division ";
        //This is actually unnecessary lol, it can be down by just rearranging it, from < 1400, < 1600, < 1900 , > 1900
        if (n >= 1900 ) cout << 1;
        else if (n <= 1899 && n >= 1600)cout << 2;
        else if (n <= 1599 && n >= 1400) cout << 3;
        else cout << 4;
 
        cout << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```