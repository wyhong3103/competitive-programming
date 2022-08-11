bruh, this question, is literally about implementation, set, vector, vector to set, accessing set element.... it was nothing about others, it's really about implementation

Explanation: 
- Solve by horizontal, vertical, diagonal line, look for one by one
- It was unnecessary with all the loop, but hey, i learned things :)

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
	array<array<char,3>, 3> board;
	for (auto& i : board){
		for (int j{}; j < 3; j++){
			cin >> i[j];
			}
		}
	set<char> individual;
	set<pair<int,int>> team;
	
	//horizontal
	for (const auto& i: board){
		set<char> player;
		for (const auto& j : i){
			player.insert(j);
		}
		vector<int> player_vec (player.begin(), player.end());
		if (size(player) == 1){
			individual.insert(player_vec[0]);
			}
		else if (size(player) == 2){
			team.insert({player_vec[0],player_vec[1]});
			}
		}
	
	//vertical
	for (int i{}; i < size(board); i++){
		set<char> player;
		for (int j{}; j < size(board[i]); j++){
			player.insert(board[j][i]);
			} 
		vector<int> player_vec (player.begin(), player.end());
		if (size(player) == 1){
			individual.insert(player_vec[0]);
			}
		else if (size(player) == 2){
			team.insert({player_vec[0],player_vec[1]});
			}
		}
	

	//diagonal1
	{
	set<char> player;
	for (int i{}; i < size(board); i++){
		player.insert(board[i][i]);
		}
		vector<int> player_vec (player.begin(), player.end());
		if (size(player) == 1){
			individual.insert(player_vec[0]);
			}
		else if (size(player) == 2){
			team.insert({player_vec[0],player_vec[1]});
			}
	}

	//diagonal2	
	{
	set<char> player;
	for (int i{}; i < size(board); i++){
		player.insert(board[i][(size(board)-1)-i]);
		}
		vector<int> player_vec (player.begin(), player.end());
		if (size(player) == 1){
			individual.insert(player_vec[0]);
			}
		else if (size(player) == 2){
			team.insert({player_vec[0],player_vec[1]});
			}
	}
	cout << size(individual) << '\n' << size(team);
}
int main(){
	setIO("tttt");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```