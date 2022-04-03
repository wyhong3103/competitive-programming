```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}



void solve(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);
		a[0] = 1;
		if (n > 19){
			cout << "NO" << '\n';
		}else{
		for (int i{1}; i < n; i++){
			a[i] = a[i-1]*3;
		}

		cout << "YES" << '\n';
		for(auto& i: a){
			cout << i << ' ';
		}
		cout << '\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}


```