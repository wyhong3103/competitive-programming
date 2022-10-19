```

Finding min/max in a fixed size subarray in O(N)

```
```cpp

int m; // m = size of subarray
vi a(n);
deque<int> q;

for(int i{}; i < n; i++){
	if (i >= m){
		if (q.front() == a[i-m]) q.pop_front();
	}

	while (!q.empty() && q.back() < a[i])
		q.pop_back();

	q.push_back(a[i]);

	if (i >= m-1){
		// do something with the min
	}
}
```