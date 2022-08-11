Solution for maximum distance , not much to explain i guess...


```cpp
#include <bits/stdc++.h>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
	int n;
	cin  >> n;
	vector <int> x(n);
	vector <int> y(n);
	for (auto& i: x){
		cin >> i;
		}
	for (auto& i: y){
		cin >> i;
		}

	
	int ans{};
	for (int i{}; i < n; i++){
		for (int j{i+1}; j < n; j++){
			ans = max(ans, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
			}
		}
	
	cout << ans;
}



int main(){
	//setIO("measurement");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```