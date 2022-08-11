Custom hash function that lets us use vector as a key for hash map. Taken from [Stack Overflow](https://stackoverflow.com/a/53283994/17715769)
```cpp
struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

// USAGE : unordered_map<vi, ll, VectorHasher> mp;
```