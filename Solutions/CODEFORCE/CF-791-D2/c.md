This is a problem that requires fenwick tree. The idea is to have two fenwick trees, one for columna and one for row, in order or each cell in the subrectangle to be attacked, there has to be at least one cell in each column and row. So the idea is to detect the presence of cell using fenwick tree, so that every update of the cells can be done in log n instead of n(with normal prefix sum array). To see if the subrectangle is getting fulfilled, we check if the number of rows in the subrectangles == number of rows that have rook. Another thing to take note of, is we don't want to add the actual number to the trees. Because of some special cases, like the one below
```

......
.RR.X.
....X.
......
......
......

X = subrectangle
R = rook

In this example, if we were to keep track of the actual numbers in fenwick tree, this might be evaluated to true, while it's not, because there isn't a rook in second row.
```

```cpp
#include <bits/stdc++.h>
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
 
const int MAX = 1e5 +5;
int fenwick_tree_row[MAX];
int fenwick_tree_col[MAX];
int actual_row[MAX];
int actual_col[MAX];
int n, q;

int sum(int k, char dir){
    int s = 0;
    while (k >= 1){
        s += (dir == 'r' ? fenwick_tree_row[k]: fenwick_tree_col[k]);
        k -= k&-k;
    }
    return s;
}

void upd(int k, char op, char dir){
    if (op == '+'){
        (dir == 'r' ? actual_row[k] : actual_col[k])++;
    }
    else {
        (dir == 'r' ? actual_row[k] : actual_col[k])--;
    }
    if ((dir == 'r' && (op == '+' ? actual_row[k] == 1 : actual_row[k] == 0)) || (dir == 'c' && (op == '+' ? actual_col[k] == 1 : actual_col[k] == 0))){
        while (k <= n){
            if (op == '+'){
                (dir == 'r' ? fenwick_tree_row[k] : fenwick_tree_col[k])++;
            }
            else {
                (dir == 'r' ? fenwick_tree_row[k] : fenwick_tree_col[k])--;
            }
            k += k&-k;
        }
    }
}

void solve(){
    cin >> n >> q;
    
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int r, c;
            cin >> r >> c;
            upd(r, '+', 'r');
            upd(c, '+', 'c');
        }else if (t == 2){
            int r, c;
            cin >> r >> c;
            upd(r, '-', 'r');
            upd(c, '-', 'c');
        }else{
            int f_row, f_col, t_row, t_col; 
            cin >> f_row >> f_col >> t_row >> t_col;
            if (sum(t_row, 'r') - sum(f_row-1, 'r') == t_row-f_row+1 || (sum(t_col, 'c') - sum(f_col-1, 'c')== t_col-f_col+1)){
                cout << "Yes" << '\n';
            }else{
                cout << "No" << '\n';
            }
        }
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```