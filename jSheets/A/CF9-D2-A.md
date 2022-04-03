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

int gcd(int a, int b){
	if (b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}

}

void solve(){
	int x,y;
	cin >> x >> y;
	int num = 7 - max(x,y);
	int denom = 6;
	int gc = gcd(denom, num);
	num /=gc ;
	denom /= gc;
	cout << num << '/' << denom;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}



```