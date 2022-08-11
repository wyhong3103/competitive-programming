It's only been 2 days since my last CP practice, it felt so rusty (It's not me being lazy, it's that I had an annoying assessment, which is about animation). This problem wasn't hard, but I've wasted 10 minutes or so on the implementation because I messed up. I didn't put the coordinate variable, which should've been reset in every single iteration(in the while loop), that's why i got stuck in an infinite loop bruh.

<br><br>
Explanation:
- This question is about flipping all the ones into zeros, by using this rectangle in a grid(that always start from 0,0 , which is upper-left).



```cpp
#include <bits/stdc++.h>
#include <limits>
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 

void toggle(vector<string>& herd,int i, int j){
	for(int x{}; x <= i; x++){
		for(int y{}; y <= j; y++){
			if (herd[x][y] == '1'){
				herd[x][y] = '0';
				}
			else{
				herd[x][y] = '1';
				}
			}
		}
}

bool valid(vector<string>& herd){
	for(auto& i : herd){
		for(auto& j: i){
			if (j == '1') return false;
			}
		}
	return true;
}
 
void solve(){
	int n;
	cin >> n;
	vector<string> herd(n);
	for(auto& i : herd)cin >> i;

	int count{};

	while(!valid(herd)){
		pair<int,int> coord{};
		bool tog{false};
		for(int i{}; i < n; i++){
			for (int j{}; j < n; j++){
				if (herd[i][j] == '1'){
					tog = true;
					if (i >= coord.first){
						if(j >= coord.second){
						coord.first = i;
						coord.second = j;
						}
					}
					}
				}
	
			}
		if (tog) toggle(herd, coord.first, coord.second);
		count++;
		}
	
	cout <<  count;
	
}
 
int main(){
	setIO("cowtip");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}

```