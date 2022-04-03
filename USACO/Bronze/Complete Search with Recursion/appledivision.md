I have encountered this type of question before in the first hackathon i've particiapted, it was about getting the minimal differences between two groups of thing(it does't necessarily has to be the same amount of item)
<br>
<br>
Explanation:
- Basically get every subset, but instead of using array elements, we can add its value, and everytime we got a complete subset, we use the total - the subset number to get the value of the other group, then we get the absolute difference between values of 2 group, and we're done
- USE LONG LONG IN THIS CASE


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


vector<ll> ans;
vector<ll> arr;
ll temp{};
ll total{};
int n;
void search(int k){
	if (k == n){
		if (temp){
		ans.push_back(abs(temp - (total-temp)));
		}
		}
	else{
		search(k+1);
		temp += arr[k];
		search(k+1);
		temp -= arr[k];
		}
	}



void solve(){
	cin >> n;
	for (int i{}; i < n; i++){
		int j;
		cin >> j;
		total += j;
		arr.push_back(j);
		}
	
	search(0);

	ll a{numeric_limits<ll>::max()};
	for (auto& i: ans){
		a = min(a, i);
		}
	cout << a;

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```

<br>
A better solution from USACO, it looks cleaner

```cpp
ll solve(int i, ll s1, ll s2){
	if(i == n){
		return abs(s1 - s2);
	}
	return min(solve(i + 1, s1 + weights[i], s2),
			solve(i + 1, s1, s2 + weights[i]));
}

int main() {
	setIO();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	cout << solve(0, 0, 0) << "\n";
}

```