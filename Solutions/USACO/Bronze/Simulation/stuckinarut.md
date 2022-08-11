BRUHHHH, I SOLVED A VERY HARD RATED QUESTION!!! Although, I cheated a little bit by looking at the test cases, but hey , it's very hard, i mean , i almost got it at the my first attempt, it just one of the part i did not realise i was not implementing the correct thing, i knew what i was doing is correct, so let's start dissecting it
<br>
Problem Link : http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
<br>
Problem :
- Basically problem is asking us to get where the cows will finally end at, it could be infinity, all cows heading direction & initial position is given , and they will only head in that direction each hour, until they get stopped (they only stopped if they're in a rut), rut means that the grass on the cell has been eaten by another cow, everytime a cow pass through a cell, they eat it, and leave it as a rut

Explanation of my solution :
- First, we store the cow in a Cow struct, which stores its directions, and initial x,y coordinates, and stores all cow in a vector of cows
- Second, we create a multidimensional array(n x n), to track the cow movement, i-th array represent how i-th cow got affected by j-th cow, ,if it's a positive integer value on j-th that means i-th cow has been affected by j and,it (might) got stopped at that point, if it's -1 , that means j-th cow wasn't affecting i-th cow at all
- We're going to iterate through the vector of cows, and try to get the above 2nd step information, 
with a simple algorithm:
	- if i-th cow is heading North, and j-th cow is heading north as well, j-th cow must have the same x coordinate and higher y-coordinate than i-th cow in order to stop i-th cow
	- if j-th cow is heading east at this point, its x coordinate must be smaller than i-th cow x coordinate and its y coordinate must be higher than ith cow's
	- if i-th cow is heading East, and j-th cow is heading east as well, j-th cow must have the same y coordinate and higher x coordinate than i-th cow in order to stop i-th cow
	- if j-th cow is heading north at this point, its y coordinate must be smaller than i-th cow y coordiante and its x coordinate must be higher than ith cow's
- Once we're done with the above operation with the above algorithm, we basically done our multidimensional array tracker thing, which tells us that if a cow would stop, when and by stop by which cow, like the pattern above: 
```
-1 -1 -1 -1 8 5
-1 -1 3 -1 -1 -1
-1 -1 -1 -1 7 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 2 -1 -1
-1 -1 5 -1 -1 -1
```
- Eg : first cow might be stopped after taking its 8-th step or 5-th step, and our job is to find it out
- To find out what's the actual step that might stop a cow, or might now, we need to do the operation below:
	- First , we need to understand what might caused the possible stopping step impossible, is , the j-th cow that stop i-th cow might already be stopped before it even reached j-th step, and that's what we essentially doing in this case
	- Iterate through every single element in every array in the 2D array, if it's a positive integer, we will use a helper function
	- In this helper function, it will go to j-th cow's array, and iterate through every single element in it, if there's an element that is a positive integer and is smaller than it's step that will eat the cell that stop i-th cow, then we're going to set the original j-th element to -1
	- Finally, we will return the minimum element in the array(without -1), if minimum is -1, then we print Infinity


```cpp
#include <bits/stdc++.h>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


struct Cow{
	char direction{};
	int x{};
	int y{};
	};



bool willCollide(int a, int b, vector<Cow>& cow){
	if (cow[a].direction == 'N'){
		if ((cow[b].direction == 'E' && (cow[b].x < cow[a].x && cow[b].y > cow[a].y ))|| (cow[b].direction == 'N' && (cow[b].x == cow[a].x && cow[b].y > cow[a].y))){
			return true;
			}
		}
	else if (cow[a].direction == 'E'){
		if ((cow[b].direction == 'N' && (cow[b].x > cow[a].x && cow[b].y < cow[a].y)) || (cow[b].direction == 'E' && (cow[b].y == cow[a].y && cow[b].x > cow[a].x))){
			return true;
			}
		}
	return false;
	}



// first integer indicating cow a's step to that interception, second integer indicating cow b's
pair <int,int> stepsCount(int a, int b,const vector<Cow>& cow){
	if (cow[a].direction == 'N'){
		if (cow[b].direction == 'N'){
			return {cow[b].y - cow[a].y, 0};
			}
		else{
			return {cow[b].y - cow[a].y, cow[a].x - cow[b].x};
			}
		}
	else{
		if (cow[b].direction == 'N'){
			return {cow[b].x - cow[a].x, cow[a].y - cow[b].y};
			}
		else{
			return {cow[b].x - cow[a].x, 0 };
			}
		}
	}

void updateHelper(vector<vector<int>>& cowTracker,const vector<Cow>& cow, int n, int i, int j){
	pair <int,int> steps = stepsCount(i,j,cow);
	for (int index{}; index < n; index++){
		if (cowTracker[j][index] != -1 && cowTracker[j][index] < steps.second){
				cowTracker[i][j] = -1;
				}
			
			}
}
	


void updateTracker(vector<vector<int>>& cowTracker,const vector<Cow>& cow, int n){
	for (int i{}; i < n; i++){
		for (int j{}; j <n; j++){
			if (cowTracker[i][j] != -1){
				updateHelper(cowTracker, cow, n , i, j);
				}
				}
			}
}

void solve(){
	int n;
	cin >> n;
	vector<Cow> cows(n);
	for (auto& i: cows){
		cin >> i.direction >> i.x >> i.y;
		}
	
	vector <vector<int>> cowTracker;
	
	cowTracker.resize(n);

	for (int i{}; i < n; i++){
		cowTracker[i].resize(n);
		for (int j{}; j < n; j++){
			cowTracker[i][j] = -1;
			}
		}

	for (int i{}; i < n; i++){
		for (int j{}; j < n; j++){
			if (j != i  && willCollide(i,j,cows)){
				pair<int,int> steps = stepsCount(i, j, cows);
				if (steps.first > steps.second){
					cowTracker[i][j] = steps.first;
					}
				}
			}
		}
	

	updateTracker(cowTracker,cows, n);

	for (int i{}; i < n; i++){
		int ans{-1};
		for (int j{}; j < n; j++){
			if (cowTracker[i][j] > 0){
				if (ans == -1){
					ans = cowTracker[i][j];
					}
				ans = min(ans,cowTracker[i][j]);
					}
			}
		if (ans == -1){
			cout << "Infinity";
			}
		else{
			cout << ans;
			}
		cout << '\n';
		}

	for (int i{}; i < n; i++){
		for (int j{}; j <n; j++){
			cout << cowTracker[i][j] << ' ';
			}
			cout << '\n';
		}

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}

```