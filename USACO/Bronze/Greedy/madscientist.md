A greedy algorithm huh, I didn't realise that, but good to know that.

```cpp
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	int ans{};
	bool count{false};
	for(int i{}; i < n; i++){
		if (a[i] != b[i]){
			count = true;
			ans++;
		}
		else if(a[i] == b[i] && count) {
			count = false;
		}
	}	
	cout << ans;

}

int main(){
	setIO("breedflip");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	

	return 0;
	}

```