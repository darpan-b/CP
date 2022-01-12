template <typename T>
class SparseTable
{
public:
    int n, logN;
    vector<vector<T>> sparse;

    SparseTable() = default;

    explicit SparseTable(int n)
    {
        this->n = n;
        logN = __lg(n) + 2;
        sparse.assign(n, vector<T>(logN, -1));
    }

    T combine(const T& lhs, const T& rhs)
    {
        return min(lhs, rhs);
    }

    void build(const vector<T>& a)
    {
        for (int i = 0; i < n; i++)
            sparse[i][0] = a[i];
        for (int i = 1; i < logN; i++)
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
        int logSz = __lg(r - l + 1);
        return combine(sparse[l][logSz], sparse[r - (1 << logSz) + 1][logSz]);
    }
};
