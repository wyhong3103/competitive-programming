```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	string s;
	cin >> s;
	pair<int,int> count{};
	for(auto& i : s){
		if (i >= 'a' && i <= 'z'){
			count.first ++;
		}else{
			count.second++;
		}
	}
	
	for(auto& i: s){
		if (count.first >= count.second){
			cout << (char)tolower(i);
		}else{
			cout << (char)toupper(i);

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