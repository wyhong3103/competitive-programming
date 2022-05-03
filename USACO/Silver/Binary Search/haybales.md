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
    int n, q;
    cin >> n >> q;

    vi a(n);
    for(auto& i:  a) cin >> i;

    sort(all(a));

    for(int i{}; i < q; i++){
        int l, r;
        cin >> l >> r;
        auto f = lower_bound(all(a), l);
        auto t = upper_bound(all(a), r);
        cout << t-f << '\n';
    }
}
 
int main(){
    setio("haybales");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```