/**
 * Data structure for range min / max queries in O(1).
 * Build : O(N log N), Query : O(1)
 * Author : winxtron
 */

template <typename T>
struct SparseTable
{
    /**
     * SparseTable() : Default constructor initializing everthing to null.
     * SparseTable(n) : Creates a null sparse table of size n.
     * T combine(a, b) : Combination function for the table. Can be either max(a, b) or min(a, b).
     * void build(a, _n) : Builds a sparse table with the vector a of size n.
     * T query(l, r) : Returns the combine() over the range [l, r].
     */

    int n;
    int log_n;
    vector<vector<T>> sparse;

    SparseTable()
    {
        n = 0;
        sparse.clear();
    }

    SparseTable(int _n)
    {
        n = _n;
        log_n = __lg(n) + 2;
        sparse.assign(n, vector<T>(log_n, 0));
    }
    
    T combine(T a, T b)
    {
        // To be modified as per requirement
        return max(a, b);
    }

    void build(vector<T>& a, int _n)
    {
        n = _n;
        log_n = __lg(n) + 2;
        sparse.assign(n, vector <T>(log_n, 0));
        for (int i = 0; i < n; i++)
            sparse[i][0] = a[i];
        for (int i = 1; i < log_n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j + (1 << (i - 1)) >= n)
                    continue;
                sparse[j][i] = combine(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    T query(int l, int r)
    {
        if (r - l < 0)
            return 0;
        int log_sz = __lg(r - l + 1);
        return combine(sparse[l][log_sz], sparse[r - (1 << log_sz) + 1][log_sz]);
    }
};
