template<typename T>
struct FenwickTree{
    int n;
    vector<T> ftree; // 1-indexed

    FenwickTree(){
        n = 0;
        ftree.clear();
    }

    FenwickTree(int _n){
        n = _n;
        ftree.assign(n + 5, 0);
    }

    /* this just ADDS data to index, not REPLACE it */
    void update(int pos, T data){
        pos++;
        for (; pos <= n; pos += (pos & (-pos))){
            ftree[pos] += data;
        }
    }

    T query(int pos){
        pos++;
        T res = 0;
        for (; pos > 0; pos -= (pos & (-pos))){
            res += ftree[pos];
        }
        return res;
    }

    /* returns sum in range [lo, hi] */
    T query(int lo, int hi){
        return query(hi) - query(lo - 1);
    }
};
