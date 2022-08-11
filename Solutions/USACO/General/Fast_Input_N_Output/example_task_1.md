# Task

The input consists of two integers <img src="https://latex.codecogs.com/svg.image?M&space;(0\le&space;M\le&space;1)" title="M (0\le M\le 1)" /> and <img src="https://latex.codecogs.com/svg.image?N(1\le&space;N\le&space;10^6)" title="N(1\le N\le 10^6)" />, followed by a sequence of <img src="https://latex.codecogs.com/svg.image?N" title="N" /> non-negative integers each
less than <img src="https://latex.codecogs.com/svg.image?10^9&plus;7" title="10^9+7" />.

If <img src="https://latex.codecogs.com/svg.image?M=0" title="M=0" />, output the sum of the input sequence modulo <img src="https://latex.codecogs.com/svg.image?10^9&plus;7" title="10^9+7" />.
If <img src="https://latex.codecogs.com/svg.image?M=1" title="M=1" />, output the sum of each prefix of the input sequence modulo <img src="https://latex.codecogs.com/svg.image?10^9&plus;7" title="10^9+7" />.

```
#include <bits/stdc++.h>

using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	using ll = long long;
	int m;
	ll n, total;
	cin >> m >> n;
	vector <ll> num_vec(n);
	for(auto& x : num_vec){
		cin >> x;
		}
	for (auto x: num_vec){
		total += x;
		if (m == 1){
			cout << (total % static_cast<ll>(1e9 + 7)) << '\n';
			}
		}
	if (!m){
		cout << (total % static_cast<ll>(1e9 + 7));
		}
}
int main(){
	//setIO("");
	solve();
	return 0;
	}


``` cpp
