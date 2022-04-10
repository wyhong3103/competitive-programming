Okay, this is a better solution, inspired by Geothermal. What happened is, it turned out, you could try iterate from 0 to 15, and plus the number with it , then do the multiplication of 2 until we got the answer. It will always give you the optimal answer. My biggest question is that, wouldn't number that adds between a multiplication of 2 helps? I need proofs.
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
    int n;
    cin >> n;
    for(int i{}; i < n; i++){
        int a;
        cin >> a;
        int k = 0;
        int ans = 15;
        while (k <= 15){
            int l = k;
            int temp = a + k;
            while (temp % 32768 != 0){
                temp *= 2;
                l++;
            }
            ans = min(l, ans) ;
            k++;
        }
        cout << ans << ' ';
    }
    
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```

```cpp
void solve() {
    int N; cin >> N;
    int ans = 15; 
    F0R(i, 16) {
        int K = (N + i) % 32768;
        int cur = i;
        while (K != 0) {
            K *= 2; K %= 32768;
            cur++;
        }
        ckmin(ans, cur);
    }
    cout << ans << " ";
}
```