Travelling and hashing at the same time.
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
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for(auto& i : a) cin >> i;

    map<int,int> m;

    for(int i{}; i < n; i++){
        if (m.count(x-a[i])){
            cout << m[x-a[i]]+1 << ' ' << i+1;
            return;
        }else{
            m[a[i]] = i;
        }
    }
    cout << "IMPOSSIBLE";
}
    



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```
