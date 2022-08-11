I don't know why I spent so much time (not really) on this question, when it's just about complete search and a little sorting... There's some semantic error while im testing it , cost me some times to fix it

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
	n*=2;
	vector<int> w(n);
	for(auto& i: w) cin >>i;
	sort(all(w));


	int ins{10000};
	for (int i{}; i < n; i++){
		for (int j{i+1}; j < n; j++){

			pair<int, int> tk{};
			int insta{};
			for (int k{}; k < n; k++){
				if (k != i && k != j) {
					if (!tk.first && !tk.second){
						tk.first = w[k];
						}
					else if(tk.first && !tk.second){
						tk.second = w[k];
						insta += (tk.second - tk.first);
						}
					else if (tk.first && tk.second){
						tk.first = w[k];
						tk.second = 0;
						}
					}
				}
			ins = min(ins, insta);
			}
		}
	cout << ins;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}

```