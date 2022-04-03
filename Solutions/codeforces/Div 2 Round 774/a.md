Should've solve this problem faster, i couldn't understand the problem in the first place...

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
 
 
using ll = long long;
using namespace std;
 
 
void solve(){
	int t;
	cin >> t;
	while(t--){
		ll n,s;
		cin >> n >> s;
		if (s < n*n){
			cout << 0 << '\n';
			continue;
			}
		
		cout << s/(n*n) << '\n';
 
		}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}

```