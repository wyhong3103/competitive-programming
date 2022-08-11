This is a pretty bad implementation I would say, but anyways, it's just about simulating. At least for what I've implemented.
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
        int x, y;
        cin >> x >> y;
 
        if (x >= y){
            if (x == y) cout << 1 << ' ' << 1;
            else cout << 0 << ' ' << 0;
        }else{
            bool ok = false;
            for(int i{2}; i <= 100; i++){
                int temp = x;
                int count = 0;
                while (temp < y){
                    temp *= i;
                    count++;
                }
                if (temp == y){
                    cout << count << ' ' << i ;
                    ok = true;
                    break;
                }
            }
            if (!ok){
                cout << 0 << ' ' << 0;
            }   
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