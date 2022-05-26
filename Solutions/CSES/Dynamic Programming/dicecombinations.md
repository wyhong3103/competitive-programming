This idea of this problem is pretty similar to coin change.
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

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
int value[MAX];

void solve(){
    int n;
    cin >> n;
    value[0] = 1;

    for(int i{1} ; i <= n; i++){
        for(int j{1}; j <= 6; j++){
            if (i - j >= 0){
                value[i] = (value[i] + value[i-j]) % MOD;
            }
        }
    }

    cout << value[n];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```