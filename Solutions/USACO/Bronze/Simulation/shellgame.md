This one is quite easy, it's just about understanding the question and the process of simulation, 
<br>
Explanation:
- It's really just about swapping the shell(with a temp variable, or you can do swap() maybe), and keeping track the scores as if we got right shell	
<br>
Link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=891

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
	array <int, 3> pebbles{1,2,3};
	array <int, 3> scores{};
	while (n--){
		int a,b,g, temp;
		cin >> a >> b >> g;
		temp = pebbles[a-1];
		pebbles[a-1] = pebbles[b-1];
		pebbles[b-1] = temp;
		for (int i{}; i < 3; i++){
			if (pebbles[g-1] == i+1){
				scores[i] += 1;
			}
			}
		}
	cout << *max_element(scores.begin(), scores.end());
	

}
int main(){
	setIO("shell");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```