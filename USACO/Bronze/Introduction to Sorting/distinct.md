I've used quite of the tricks I learned in the previous article from code forces, smth like the all(x) macro, unique() method, and I know i could have use generate(), and nxt() in this question, but i just chose not to, that really make it seems like i am lazy and all xD, and im not even on that level that i need to be fast and all, now imma just stick to these fill macros and methods...

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
	vector<int> x(n);
	for(auto& i: x) cin >> i;
	sort(all(x));
	x.resize(unique(all(x)) - x.begin());
	cout << size(x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}
```