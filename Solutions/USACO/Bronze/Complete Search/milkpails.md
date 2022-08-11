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
	int x,y,m;
	cin >> x >> y >> m;
	
	int temp{};
	int ans{};

	for (int i{}; i < 1001; i++){
		if (x * i > m) break;
		for (int j{}; j < 1001; j++){
			if ((x * i) + (y * j) > m)break;
			temp = (x * i) + (y * j);
			ans = max(temp, ans);
			}
		}
	
	cout << ans;

}
 
int main(){
	setIO("pails");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}


```