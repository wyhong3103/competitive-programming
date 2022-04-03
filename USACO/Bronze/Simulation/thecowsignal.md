This problem is literally about manipulating the string, good , learn a few things here, push_back with string etc etc.

<br>
Explanation:
- I guess there's no need for explanation for this question

<br>
Link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=665



```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int m,n,k;
	cin >> m >> n >> k;
	vector <string> signals(m);
	for (auto& i: signals){
		cin >> i;
		string new_i{""};
		for (size_t j{}; j < i.length(); j++){
				for (int x{}; x < k; x++){
					new_i.push_back(i[j]);
					}
			}
		for (int x{}; x < k; x++){
			cout << new_i << '\n';
			}
	}

		

}
int main(){
	setIO("cowsignal");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```