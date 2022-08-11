```cpp

int length_3n_plus_1(int i){
    if (i == 1){
        return 1;
    }
    return 1 + length_3n_plus_1((i % 2 == 0 ? i/2 : 3*i + 1));
}

int maximum(int arr[], int len){
    if (len == 0){
        return arr[len];
    }
    return max(arr[len], maximum(arr, len-1));
}

int sum(int arr[], int len){
    if (len == 0){
        return arr[len];
    }
    return arr[len] + sum(arr, len-1) ;
}

double average(int arr[], int len){
    if (len == 0){
        return arr[len];
    }
    return (double)arr[len]/(len+1) + (((double)len/(len+1)) * average(arr, len-1));
}

//The idea of this version is really simple, we simply need to multiply the average by the number of elements to retrieve the sum, and divide it again
double average2(int arr[], int len){
    if (len == 0) return arr[len];

    double sub_result =  average2(arr, len-1);
    sub_result = ((sub_result * len) + arr[len])/(len+1);
    return sub_result;
}


void array_increment(int arr[], int len){
    if (len >= 0){
        arr[len] += len;
        array_increment(arr, len-1);
    }else{
        return;
    }
}


void accumulate_arr(int arr[], int len){
    if (len <= 5){
        arr[len] += arr[len-1];
        accumulate_arr(arr,len+1);
    }
}
//Idk if there's a better way to do this, it's just dumb that I have to manually state the length of the array

void left_max(int arr[], int len){
    if (len >= 6) return;
    arr[len] = max(arr[len], arr[len-1]);
    left_max(arr, len+1);
}

void right_max(int arr[], int len){
    if (len < 0) return;
    arr[len] = max(arr[len], arr[len+1]);
    right_max(arr, len-1);
}

int suffix_sum(int arr[], int n, int i){
    if (n == 1) return arr[i];
    return arr[i] + suffix_sum(arr,n-1,i-1);
}

int prefix_sum(int arr[], int n, int i){
    if (n == 1) return arr[i];
    return arr[i] + prefix_sum(arr, n-1, i+1);
}

bool is_palindrome(string s, int i = 0){
    if (i >= s.length()) return true;
    return (s[i] == s[s.length()-i-1]) && is_palindrome(s, i+1);
}

bool is_prefix(string s, string prefix, int start_pos = 0){
    if (start_pos >= prefix.length()) return true;
    return s[start_pos] == prefix[start_pos] && (is_prefix(s,prefix,start_pos+1));
}

bool is_prime(int i, int test_num = 3){
    if (i == test_num || i == 2) return true;
    if (test_num * test_num > i) return true;
    if (i % test_num == 0 || i < 2) return false;
    if (i % 2 == 0) return false;
    return (is_prime(i, test_num + 2));
}

int count_prime(int start, int end){
    if (start == end){
        return is_prime(start);
    }   
    return is_prime(start) + count_prime(start+1,end);
}

int grid[100][100];

int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS){    
    vector<pi> mve = {{1,0}, {0,1}, {1,1}};
    int mx = 0;
    pi best{};
    for(int i{}; i < 3; i++){
        if (row + mve[i].fir < ROWS && col + mve[i].sec < COLS){
            if (grid[row+mve[i].fir][col+mve[i].sec] > mx) {
                mx = grid[row+mve[i].fir][col+mve[i].sec];
                best = mve[i];
            }
        } 
    }
    if (best.fir == 0 && best.sec ==0) return grid[row][col];

    return grid[row][col] + path_sum(grid, row+best.fir, col+best.sec, ROWS, COLS);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }
    cout << path_sum(grid, 0, 0, n, m);
}


int memo[1000];

int fib(int n){
    if (memo[n]) return memo[n];
    else{
        if (n <= 1) return 1;
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
}

```