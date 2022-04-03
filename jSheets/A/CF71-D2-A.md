```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		if (size(s) > 10){
			string ans;
			cout<< s[0] << size(s)-2 << s[size(s)-1] << '\n';
		}else{
			cout << s << '\n';

		}

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}

```