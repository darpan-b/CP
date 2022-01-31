template <typename T>
class SegmentTree
{
public:
    vector<T> seg;

    SegmentTree() = default;

    SegmentTree(int n)
    {
        seg.assign(4 * n, 0);
    }

    inline T combine(const T& lhs, const T&  rhs)
    {
        return lhs + rhs;
    }

    void build(int node, int ss, int se, const vector<T>& a)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            seg[node] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(node * 2 + 1, ss, mid, a);
        build(node * 2 + 2, mid + 1, se, a);
        seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
    }

    void update(int node, int ss, int se, int uidx, const T& val)
    {
        if (ss > se || uidx > se || uidx < ss)
            return;
        if (ss == se && ss == uidx)
        {
            seg[node] = val;
            return;
        }
        int mid = (ss + se) / 2;
        update(node * 2 + 1, ss, mid, uidx, val);
        update(node * 2 + 2, mid + 1, se, uidx, val);
        seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
    }

    T query(int node, int ss, int se, int qs, int qe)
    {
        if (ss > se || qs > se || qe < ss)
            return 0LL;
        if (ss >= qs && se <= qe)
            return seg[node];
        int mid = (ss + se) / 2;
        T leftQuery = query(node * 2 + 1, ss, mid, qs, qe);
        T rightQuery = query(node * 2 + 2, mid + 1, se, qs, qe);
        return combine(leftQuery, rightQuery);
    }
};
