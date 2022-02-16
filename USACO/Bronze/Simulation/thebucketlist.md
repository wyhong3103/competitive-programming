honestly, i did not know what have I done in this problem, I mean i knew, but the implementation just came out of luck, i couldn't think of the way of implementing it at first, the gist of this problem is looking for the maximum bucket we need at a moment, and i couldn't think of a better way to solve it rn, im literally doing it wit O(max endtime - min startime), there's a lot of operation that occur in between, here right now, I am going to explain my solution...
<br>
Explanation:
- First, I sort the array of Cow(Cow struct consist of 3 attributes, start , end , and buckets) according to their start time, and from there I got the min start time
- Then, I look for the max end time, with the min_element which return an iterator (pointer), i have to use -> to access the class and it's member(end time) and assign it to the integer variable
- Then i basically used a for loop (from min start time to max end time) to iterate between the times, and in betweeen every iteration, i go through the array of Cow, if the cow im iterating to has a greater start time than the current iteration's time, then we break, if we found a cow's start time, we break, we add the bucekts,and use max operation to track the greatest amount of buckets we had at a time, if we found a cow's end time, we break, we subtract the buckets.
- This is a little inefficient i know that, I know there's a better way other than *simulation* , hope I find out soon....

<br>
PS: Mine actually takes up to O(n log n), because of the sorting....

```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


struct Cow{
	int start;
	int end;
	int buckets;
	};


void solve(){
	int n;
	cin >> n;
	vector <Cow> cows(n);
	for (auto& i : cows){
		cin >> i.start >> i.end >> i.buckets;
		}
	sort(cows.begin(), cows.end(),[](const Cow& a, const Cow& b){
		return (a.start < b.start);
		} );
	
	int start(cows[0].start);
	int end{min_element(cows.begin(), cows.end(), [](const Cow& a, const Cow& b){
		return a.end > b.end;
		})->end};
	
	int buckets{};
	int max_buckets{};
	for (int i{start}; i <= end; i++){
		for (auto& cow_now: cows){
			if (cow_now.start <= i){
				if (cow_now.start == i){
					buckets += cow_now.buckets;
					max_buckets = max(buckets, max_buckets);
					break;
				}
				if (cow_now.end == i){
					buckets -= cow_now.buckets;
					break;
				}
			}else{
				break;
				}
			}
		}
	cout << max_buckets;
}

int main(){
	setIO("blist");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```
<br>
Solution from USACO:

```cpp

#include <iostream>
#include <algorithm>  
#include <cstdio>
using namespace std;
int event[1001]; // declaring the array globally to initialize all the elements to 0
int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout); 
	int maxtime = 1000;
	int n; cin >> n;
		
		
	for (int i = 0; i < n; i++) { // iterating through every cow
		int start; cin >> start; 
		int end; cin >> end;
		int amt; cin >> amt;
		// at time start, cow i needs to be milked, so 
		// we'll need amt additional buckets (hence adding amt)
		event[start] += amt;
		// at time end, cow i is done milking, so we can free up 
		// amt buckets (hence subtracting amt)
		event[end] -= amt; 
	}
		
	// res represents the maximum number of buckets we'll need 
	// to use at any given time and cur represents 
	// how many buckets we need to use at the current 
	// time we're processing
	int res = 0, cur = 0;
	for (int i = 0; i <= maxtime; i++) {
		// at time i, the number of buckets in use changes by event[i]
		// so we want to update the number of buckets 
		// we are currently using accordingly
		cur += event[i];
		// we want res to be the greatest number of buckets 
		// we need to use at any given point in time
		res = max(res, cur); 
		
	}
	
	
	cout << res << '\n'; 
	
}
```
<br>
A pretty cool solution, I like the approach

Explanation:
- It's basically, record every instant + - of buckets, and iterate through every instant, and do the math, pretty cool