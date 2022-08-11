The idea of this problem is pretty simple, it's just the implementation takes a little time. So the idea is to fill up as many columns as possible, starting from the prefix of the column.
```
To solve this problem, I've broken down it into a few steps	

First, get an array that keep tracks of number of icons in each and every columns, and the total number of icons of every columns

Second, process the query, every time we process the query, we have to toggle the grid on that position, * -> . , . -> *, and change the total number of icons

Third, divide total number of icons by the number of rows, so that we could find how many fully occupied column we can build, then iterate from the first column to the column that we can fully fill up. Notice that which icon are we moving doesn't really matter, it only matter when it's the last column (column that only it's prefix is filled up but not it's entire cells). And it's best that we move the icons from the right most, so that we avoid the possibility of messing up the last column, and until we fill all of them up. It's simply just about deducting the right most and add it to the filled up column, and at the same time, keep tracks of number of icons we moved.

Lastly, the column that is not fill up completely, we can simply count the number of cells we need for that column, by doing total number of icons % number of rows, and this time, the order matters, because there are already some preoccupied cells that we don't need to move, so we just need to calcualte from row = 1 to the total number of cells we need for that column, how many cells aren't '*', and that's the answer.
```
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, m,q;
    cin >> n >> m >> q;

    vector<string> grid(n);
    for(auto& i : grid) cin >> i;

    vi icons(m);
    for(int i{}; i < m; i++){
        int count = 0;
        for(int j{}; j < n; j++){
            if (grid[j][i] == '*'){
                count++;
            }
        }
        icons[i] = count;
    }

    int total = 0;
    for(auto& i : icons) total += i;

    for(int i{}; i < q; i++){
        int row, col;
        cin >> row >> col;
        row--;col--;

        if (grid[row][col] == '*'){
            total--;
            grid[row][col] = '.';
            icons[col]--;
        }else{
            total++;
            grid[row][col] = '*';
            icons[col]++;
        }

        vi cur = icons; 
        //total columns that can be fully occupied
        int occ = total/n;

        int ans = 0;
        int p1 = m-1;
        //fill up occupied icons
        for(int i{}; i < occ; i++){
            int need = n-cur[i];
            ans += need;
            while (p1 >= 0){
                need -= min(need, cur[p1]);
                cur[p1] -= need;
                if (cur[p1] == 0) p1--;
                if (need == 0) break;
            }
        }

        //last col
        int last_need = total % n;
        for(int i{}; i < last_need; i++){
            if (grid[i][occ] == '.') ans++;  
        }

        cout << ans << '\n';
    }
    
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```