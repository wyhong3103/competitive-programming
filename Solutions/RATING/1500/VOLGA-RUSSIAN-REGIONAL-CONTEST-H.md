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
    int t;
    cin >> t;
    while(t--){
        vi candles(10);

        pi mn{-1,INT_MAX};

        for(int i{}; i < 10; i++){
           cin >> candles[i];
           if (candles[i] < mn.sec || (mn.fir == 0 && candles[i] <= mn.sec)){
                mn.fir = i;
                mn.sec = candles[i];
           }
        }
        
        if (mn.fir == 0) cout << 1;
        for(int i{}; i <= mn.sec; i++){
            cout << mn.fir;
        }
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