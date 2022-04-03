This problem is fun xD, although, i've peeked into the backtracking topic before solving this, but i still considered it as a fun problem, backtracking basically, it's a very similar problem to all of those that is stated in this chapter, only difference is , i am given a board with reserved space, which i have to modify the thing i've already knew, which works well
<br>
<br>
Explanation:
- First, receive its input
- Backtrack it, but meanwhile, keep track of the queens that are on the board, to validate if a position is alright to place a queen, we check if that position is reserved, or has collided with the previous queens (same column, row, diagonal), there was this one trick in that diagonal section which is pretty cool, they're diagonally the same, if the difference betweeen their x is equal to their difference between their y

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


char cb[8][8];
int solution{};
vector <pair<int, int>> queens;

bool validate(int i, int j){
	for (auto& a: queens){
		if (a.first == i || a.second == j || abs(a.first-i) == abs(a.second - j)) return false;
		}
	return true;
}


void search(int row){
	if (row == 8) solution++;
	else{
	for (int i{}; i < 8; i++){
		if (cb[row][i] == '*' || !validate(row, i)) continue;
		queens.push_back({row, i});
		search(row+1);
		queens.pop_back();
		}
	}
	
	}

void solve(){
	for (int i{}; i < 8; i++){
		for (int j{}; j < 8; j++){
			cin >> cb[i][j];
			}
		}

	search(0);
	cout << solution;

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```