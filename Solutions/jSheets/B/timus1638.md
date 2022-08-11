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
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}



void solve(){
    int tv, tc, f, s;
    cin >> tv >> tc >> f >> s;
    
    cout << (s > f ? (s-f-1)*((tc * 2) + (tv)) + (tc*2) : (((f-s+1) * (tv)) + ((f-s) * (tc*2)))) ;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```