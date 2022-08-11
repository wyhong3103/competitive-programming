Solution comes up to my mind in no time, it's that implementation which cost me ton of times. I messed up the first implementation, I'll have to recode it. And it works.
<br>
Explanation:
- The reason it works, is probably because of next_permutation, next_permutation is a really good way to use permutation, because it's built in, and most importantly, it's being permutated in order it goes from lowest order to highest order, which will guarantee us find the "alphebatically first" sequence in the first succeed search.
- We must sort it before the permutation, to guarantee all grounds are covered.

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) (x).begin(),(x).end()


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

vector<pair<string, string>> order{};
vector<string> cows {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue"};


void solve(){
	int n;
	cin >> n;
	for(int i{}; i < n; i++){
		string fname, sname, temp;
		for (int j{}; j < 6; j++){
			if (j == 0)	cin >> fname;
			else if(j == 5) cin >> sname;
			else cin >> temp;
		}
		order.push_back({fname,sname});
	}

	sort(all(cows));

	do{
		bool valid{true};
		for(int i{}; i < 8; i++){
			for(auto& j: order){
				if (cows[i] == j.first || cows[i] == j.second){
					if (cows[i] == j.first) swap(j.first, j.second);
					if (i > 0 && i < 7){
						if (cows[i-1] != j.first && cows[i+1] != j.first){
							valid = false;
							break;
							}
					}
					else if (i == 0){
						if (cows[i+1] != j.first){
							valid = false;
							break;
						}
					}
					else if (i == 7){
						if (cows[i-1] != j.first){
							valid= false;
							break;
							}
						}

					}
			if (!valid) break;
			}
		if (!valid) break;
		}

		if (valid){
			for (auto& i: cows){
				cout << i << '\n';
				}
			break;
		}

	}while(next_permutation(all(cows)));

}


int main(){
	setIO("lineup");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```