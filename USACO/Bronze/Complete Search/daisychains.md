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
	vector<int> flowers(n);
	for(auto& i: flowers) cin >> i;
	
	int ans{};
	for(int i{}; i < n; i++){
		for (int j{i}; j < n; j++){
			double petals{};
			set<int> p{};
			for ( int k{i}; k <= j; k++){
				petals+=flowers[k];
				p.insert(flowers[k]);
				}
			double average = petals/(abs(i-j)+1);
			if (abs(average - ceil(average)) < 0.000001 && p.count(average)){
				ans++;
				}
			}
		}
	cout << ans;

		
}
 
int main(){
	//setIO("pails");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}

```