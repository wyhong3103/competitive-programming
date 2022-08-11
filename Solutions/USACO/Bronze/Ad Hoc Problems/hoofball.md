This problem was not obvious at first, but then idk how, i was very lucky, i kinda got an algorithm to solve this problem, i kind of cheated in this problem, because I've looked at the test data, I've misinterpreted the problem statement, first is the upper bound of x, i thought its 100, and the one situation when distance between two ball is the same, i chose to pass it to the right instead.(I thought that was left)
<br>
Explanation:
- This problem is about finding the minimum ball we need to allow every cow get at least the ball once, each cow will pass its ball to the nearest cow to it, no matter left or right. If they have the same distance, we pass it to the left(which is closer to the farm).
- My solution is initially pass all ball to every single cow, and get the range (starting point and ending point of the ball) from each one of them, and add it to a vector. And in the meantime, there will be a integer pair to store the highest and lowest point we've got so far, this is to prevent getting unncessary set being added to the array.
- Then all we need to do lastly, is to filted the set in the array,say the size of the array we filled previosuly is n, and this operation takes n^2, it essentially keep track of the ranges, for those ranges that is being covered by another ranges is considered unnecessary, so we add those to another set. 
- When this operation is done. We will get our a set of unnecessary elements. So we just print the size of the array - the size of the set.
<br><br>
Link to problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=808
<br><br>
Solution:

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


void solve(){
	int n;
	cin >> n;
	vector<int> coord(n);
	for (auto& i : coord) cin >> i;
	sort(all(coord));

	pair<int,int> cowRange{coord[0], coord[n-1]};


	vector<pair<int,int>> possible;
	pair<int,int> hadCovered{1001,0};
	for (int i{}; i < n; i++){
		set<int> range;
		pair<int,int> covered{1001, 0};
		int j{i};
		while(!range.count(coord[j])){
			covered.first = min(covered.first, coord[j]);
			covered.second = max(covered.second, coord[j]);
			range.insert(coord[j]);
			if (j > 0 && j < n-1){
				if (abs(coord[j]-coord[j-1]) > abs(coord[j]-coord[j+1])){
					j +=1;
				}
				else if (abs(coord[j]-coord[j-1]) < abs(coord[j]-coord[j+1])){
					j -=1;
				}
				else{
					j -= 1;
				}
			}
			else if(j == 0){
				j += 1;
			}
			else if (j == n-1){
				j -= 1;
				}
			}
		if (covered.first < hadCovered.first || covered.second > hadCovered.second){
			possible.push_back(covered);
			hadCovered.first =min(hadCovered.first, covered.first);
			hadCovered.second = max(hadCovered.second, covered.second);
		}
	}
	
	//remove all that is being covered
	set<int> useless;
	for (int i{}; i < size(possible); i++){
		for (int j{}; j < size(possible); j++){
			if (possible[j].first >= possible[i].first && possible[j].second <= possible[i].second && j != i){
				useless.insert(j);
				}
			}
	}

	cout << size(possible) - size(useless);
}

int main(){
	setIO("hoofball");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}

``` 