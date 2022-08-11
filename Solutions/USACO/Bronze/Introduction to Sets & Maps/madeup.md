hell, i solved this question like 30 minutes earlier,but i got 5 WA, and i didn't know what is going on, until i changed all the integer to long long type, i guess i gotta do some homework with this, a good question by the way
<br><br>
Explanation:
- First this question want us to find a pair where , A_i = B_C_j (B\[C\[j\]\])
- The approach is to store the number of elements that has value A_i, in a map, basically , value : number of elements , pair, notice that we do not need the index of A, all that matter is how many element we got with that particular value we're looking for.
- Second, everytime we're receiving the input C, we use it as the index of B, and search if there's element in A with that value, if yes, we add the number of elements that is stored in that value
- Super simple.
<br>
Link to the problem : https://atcoder.jp/contests/abc202/tasks/abc202_c

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
	ll n;
	cin >> n;
	vector <ll> b(n);
	map<ll, ll> am;
	for (ll i{}; i < n; i++){
		ll x;
		cin >> x;
		if (!am.count(x)) am[x] = 0;
		am[x]++;
	}

	for (auto& i: b) cin >> i;

	ll ans{};

	for (ll i{}; i < n; i++){
		ll x;
		cin >> x;
		if (am.count(b[x-1])) ans += am[b[x-1]];
		}
	
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}

```