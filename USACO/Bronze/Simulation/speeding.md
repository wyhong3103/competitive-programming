BRUH , this question took me the longer than it should , it just the problem of the logic and the implementation, real bruh moment :|
<br>
Explanation:
- Make sure the current_distance bessie travelled is bigger or equal to the distance segment
- Everytime we add a segment of bessie's speed and distnace , we do the comparison between it and the speed limit
- We do an extra checking outside the while loop, because of this case
```
3 3
40 75
50 35
10 30
40 76
20 30
40 40
```
Link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=568


```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> speed_limits(n);
	for (auto& i : speed_limits){
		cin >> i.first >> i.second;
		}
	vector<pair<int,int>> bessie(m);
	for (auto& i : bessie){
		cin >> i.first >> i.second;
		}
	
	int distance{}, current_distance{}, current_speed{}, ans{};
	size_t index{};
	for (auto& i : speed_limits){
		distance += i.first;
		while (current_distance < distance){
			current_distance += bessie[index].first;
			current_speed = bessie[index].second;
			ans = max(current_speed - i.second, ans);
			if (index < m){
				index++;
				}
			}
		ans = max(current_speed - i.second, ans);
		}
	cout << ans;
}

int main(){
	setIO("speeding");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}


```