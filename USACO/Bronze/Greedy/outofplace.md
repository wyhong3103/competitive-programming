Bruh, i overthink this problem , it could be solve so easily..... I hate it.
<br>
Explanation to my solution:
- Get a sorted list and get the new location of Bessie, and start simulating the process of swapping(ik it wasn't necessary after looking at the solution, im too exhausted atm so i didn't think of nothing)
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}



void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sorted(n);
    for(int i{}; i < n; i++){
        cin >> a[i];
        sorted[i] = a[i];
    }

    char dir{};
    int ind{};
    sort(all(sorted));
    vector<pair<int,int>> a2;
    for(int i{}; i < n ;i++){
        if (sorted[i] != a[i]){
            a2.push_back({sorted[i], i});
        }
    }

    int las = size(a2)-1;
    if (a2[0].fir == a[a2[las].sec]){
        ind = a2[las].sec;
        dir = 'l';
    }else{
        ind = a2[0].sec;
        dir = 'r';
    }

    bool found = false;
    int i{(dir == 'r' ? ind+1 : ind-1)};
    int count{};
    int last{};
    while(!found){
        if (dir == 'r'){
            if (i < n){
                if (a[i] >= a[ind] && a[ind-1] <= a[ind]){
                    found = true;
                }else{
                    if (a[i] != last){
                        count++;
                    }
                    last = a[i];
                    swap(a[i],a[ind]);
                    ind = i;
                    i++;
                }
            }else break;
        }else{
            if (i >= 0){
                if (a[i] <= a[ind] && a[ind+1] >= a[ind]){
                    found = true;
                }else{
                    if (a[i] != last){
                        count++;
                    }
                    last = a[i];
                    swap(a[i],a[ind]);
                    ind = i;
                    i--;
                }
            }else break;
    }
    }

    cout << count;
}

int main(){
    setIO("outofplace");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}

```
<br>
Solution
```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	int n;
	cin >> n;
	int cows[100], sorted[100];
	for (int i = 0; i < n; i++)
	{
		cin >> cows[i];
		sorted[i] = cows[i];
	}
	sort(sorted, sorted + n);
	int swaps = 0;
	for (int i = 0; i < n; i++)
	{
		if (cows[i] != sorted[i])
		{
			swaps++;
		}
	}
	cout << swaps - 1 << endl;
	return 0;
}

```
<br>
Lesson learned. Always plan it , or else you could go so wrong. Always think of another solution before you actually going to do some insane and complicated solution.