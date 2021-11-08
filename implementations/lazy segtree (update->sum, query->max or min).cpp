//NOT TESTED

// Lazy Segment Tree, update: sum, query: combine()

template<typename T>
struct LazySegmentTree {
    vector<T> seg;
    vector<T> lazy;
    
    LazySegmentTree() {
    }
    
    LazySegmentTree(int n) {
        //update NULL value as per datatype used
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    
    //update as per problem
    T combine(T a, T b) {
        return max(a, b);
    }
    
    void build(int node, int ss, int se, vector<T>& a) {
        if (ss > se) return;
        if (ss == se) {
            seg[node] = a[i];
            return;
        }
        int mid = (ss + se) / 2;
        build(node * 2 + 1, ss, mid);
        build(node * 2 + 2, mid + 1, se);
        seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
    }
    
    void push(int node, int ss, int se) {
        if (ss < se) {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
            seg[node * 2 + 1] += lazy[node];
            seg[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    void update(int node, int ss, int se, int us, int ue, T val) {
        if (ss > se || us > se || ue < ss) return;
        if (ss >= us && se <= ue) {
            seg[node] += val;
            lazy[node] += val;
            return;
        }
        push(node, ss, se);
        int mid = (ss + se) / 2;
        update(node * 2 + 1, ss, mid, us, ue, val);
        update(node * 2 + 2, mid + 1, se, us, ue, val);
        seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
    }
    
    T query(int node, int ss, int se, int qs, int qe) {
        //update return value as per problem
        if (ss > se || qs > se || qe < ss) return -1e18;
        push(node, ss, se);
        if (ss >= qs && se <= qe) return seg[node];
        push(node, ss, se);
        int mid = (ss + se) / 2;
        T q1 = query(node * 2 + 1, ss, mid, qs, qe);
        T q2 = query(node * 2 + 2, mid + 1, se, qs, qe);
        return combine(q1, q2);
    }
};
