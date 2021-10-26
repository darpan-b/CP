template<typename T>
class SparseTable
{
    int n,logn;
    vector<vector<T>> table;

public:
    SparseTable()
    {
        n = logn = 0;
        table.clear();
    }

    SparseTable(int _n)
    {  
        n = _n;
        logn = __lg(n)+1;
        table.assign(n,vector<T>(logn,0));
    }

    T combine(const T& a, const T& b)
    {
        // TODO: modify as per problem
        return min(a,b);
    }

    void build(vector<T>& a)
    {
        for(int i = 0; i < n; i++) table[i][0] = a[i];
        for(int i = 1; i <= logn; i++){
            for(int j = 0; j < n; j++){
                if(j+(1<<(i-1)) >= n) continue;
                table[j][i] = combine(table[j][i-1],table[j+(1<<(i-1))][i-1]);
            }
        }
    }

    T query(int l,int r)
    {
        int logsz = __lg(r-l+1);
        return combine(table[l][logsz],table[r -(1<<logsz)+1)][logsz]);
    }
};
