I don't know why that I couldn't solve this yesterday, this is like extremely easy.
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        vi b(n);

        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;

        ll ans = 0;
        for(int i{1}; i < n; i++){
            if (abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]) > abs(a[i] - b[i-1]) + abs(b[i] - a[i-1])){ 
                swap(a[i-1], b[i-1]);
            }
            ans += abs(a[i]-a[i-1]) + abs(b[i] - b[i-1]);
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