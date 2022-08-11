This question is about finding a string that start between the enty and exit but doesn't end between it

```cpp
#include <bits/stdc++.h>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
	string entries{};
	cin >> entries;

	int ans{};
	string found{};

	for (int i{}; i < 52; i++){
		string pairs{};
		if (found.find(entries[i]) == string::npos){
			for (int j{i+1}; j < 52; j++){
				if (entries[i] == entries[j]){
					found += entries[i];
					ans += pairs.length();
					break;
					}
				if (pairs.find(entries[j]) != string::npos){
					pairs.erase(pairs.begin()+pairs.find(entries[j]));
					}
				else if (found.find(entries[j]) == string::npos ){
					pairs += entries[j];
					}

				}
		}
		}
	cout << ans;
}



int main(){
	setIO("circlecross");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}

```