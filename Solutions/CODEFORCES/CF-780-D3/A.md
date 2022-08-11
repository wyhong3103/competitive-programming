```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
 
        if (a == 0){
            cout << 1;
        }
        else{
            cout << (a+(b*2)+1);
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