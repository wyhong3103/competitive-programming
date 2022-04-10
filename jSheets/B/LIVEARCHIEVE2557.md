```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()

using namespace std;
using vi = vector<int>;
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

        vector<bool> a(n);
        fill(all(a), true);
        
        for(int i{1}; i <= n; i++){
            for(int j{i}; j <= n; j+=i){
                a[j-1] = !a[j-1];
            }
        }
        
        int ans = 0;
        for(auto i : a){
            if (!i) ans++;
        }
        cout << ans << '\n';
    }
}


int main(){
    //setio("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```

Idea:
- For a room to be unlocked it need to have odd number of divisors including 1 and itself, only a perfect square would have an odd number of divisors.
- Number that have a perfect squares in range from 1 to N is all numbers from 1 to sqrt(N), so the answer is sqrt(N) 