More complete search aka Brute Forcing

```cpp
#include <bits/stdc++.h>
#include <limits>
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
	int n;
	cin >> n;
	vector <pair<int,int>> time(n);

	pair<int,int> se = {1001,0};

	for(auto& i: time){
		cin >> i.first >> i.second;
		se.first = min(i.first, se.first);
		se.second = max(i.second, se.second);
	}
	
	int ans{};

	for (int i{}; i < n; i++){
		int covered{};
		for (int t{se.first}; t <= se.second ; t++){
			for (int j{}; j < n; j++){
				if (j != i){
					if (t > time[j].first && t <= time[j].second){
						covered++;
						break;
						}
					}
				}
			}
		ans = max(covered, ans);
		}
	
	cout << ans;
	
}
 
int main(){
	setIO("lifeguards");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}


```