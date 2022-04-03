This problem is essentially about looking for every pair in each session , and see if they are consistent, if they are, we +1 to the tracker, and return it
<br>
Explanation:
- What i essentially did in this problem is, first I create an array of cow struct, a cow struct consists of its ranking (in every session)
- Iterate through every pair in an array, and check if they are consistent, if it is , then we add the pair to a set
- Return the length of a set

```cpp
#include <bits/stdc++.h>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Cow{
	vector<int> ranking{};
	};


void solve(){
	int n, k;
	cin >> k >> n;
	vector<Cow> cows(n);

	for (auto& i: cows){
		i.ranking.resize(k);
		}
	
	
	for (int i{}; i < k; i++){
		for (int rank{}; rank < n; rank++){
			int j;
			cin >> j;
			cows[j-1].ranking[i] = rank;
			}
		}

	set<pair<int,int>> ans;

	for (int i{}; i < n; i++){
		for (int j{i+1}; j < n; j++){
			bool isConsistent{true};
			bool larger{false};
			if (cows[i].ranking[0] > cows[j].ranking[0]){
				larger = true;
				}
			for (int x{}; x < k; x++){
				if (larger && cows[i].ranking[x] < cows[j].ranking[x]){
					isConsistent = false;
					}
				else if (!larger && cows[i].ranking[x] > cows[j].ranking[x]){
					isConsistent = false;
					}
				}
			if (isConsistent){
				ans.insert({i,j});
			}
			}
		}
	
	
	cout << size(ans);


	
}



int main(){
	setIO("gymnastics");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```