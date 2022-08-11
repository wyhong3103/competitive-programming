no comments

```cpp
#include <bits/stdc++.h>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<string>spotted(n);
	vector<string>plain(n);

	for (auto& i: spotted){
		cin >> i;
		}
	for (auto& i: plain){
		cin >> i;
		}

	
	int ans{};

	for (int i{}; i < m; i++){
		pair<string, string> genome;
		bool isDistinct{true};
		for (const auto& cow: spotted){
			genome.first += cow[i];
			}

		for (const auto& cow: plain){
			genome.second += cow[i];
			}		
		


		for (int j{}; j < n; j++){
			for (int k{}; k < n; k++){
				if (genome.first[j] == genome.second[k]){
					isDistinct= false;
					break;
					}
				}
			}
		if (isDistinct){
			ans++;
			}


		}

	cout << ans;
}



int main(){
	setIO("cownomics");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```