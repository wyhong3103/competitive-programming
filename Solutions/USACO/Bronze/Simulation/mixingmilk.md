This problem is aight, just a simple trick on how much amount of milk we're going to pour to the next bucket
<br>
Explanation:
- (i-1)%3 is the last bucket, why %3? because the the index is iterating through a 100
- choosing the minimum amount between remaining volume of the bucket and the volume of the milk we're going to pour, because the milk could be  > remaining volume
<br>
Link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=855


```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	array <pair <int,int>, 3> buckets;
	for (auto& i: buckets){
		cin >> i.first >> i.second;
		}
	for (int i{1}; i <= 100;i ++){
		int amt_to_pour{};
		amt_to_pour = min(buckets[(i-1)%3].second, buckets[i%3].first - buckets[i%3].second);
		buckets[(i-1)%3].second -= amt_to_pour;
		buckets[i%3].second += amt_to_pour;
		}
	for (const auto& i: buckets){
		cout <<i.second << '\n';
		} 


}
int main(){
	setIO("mixmilk");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}
```