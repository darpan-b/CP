template<typename T>
class SegmentTree
{
    int n;
    vector<T> seg;

public:
    SegmentTree()
    {
        n = 0;
        seg.clear();
    }   
    SegmentTree(int _n)
    {
        n = _n;
        seg.assign(4*n, 0);
    }

private:
    inline T combine(const T& a, const T& b)
    {
        // TODO: change as per problem
        return a+b;        
    }
    void build(int node,int ss, int se, const vector<T>& a)
    {
        if(ss > se) return;
        if(ss == se){
            seg[node] = a[ss];
            return;
        }
        int mid = (ss+se)/2;
        build(node*2+1,ss,mid,a);
        build(node*2+2,mid+1,se,a);
        seg[node] = combine(seg[node*2+1], seg[node*2+2]);
    }
    void update(int node, int ss,int se,int updidx, const T& val)
    {
        if(ss > se || updidx > se || updidx < ss) return;
        if(ss == se){
            assert(ss == updidx);
            seg[node] = val;
            return;
        }
        int mid = (ss+se)/2;
        update(node*2+1,ss,mid,updidx,val);
        update(node*2+2,mid+1,se,updidx,val);
        seg[node] = combine(seg[node*2+1],seg[node*2+2]);
    }
    T query(int node,int ss,int se, int qs,int qe)
    {
        if(ss > se || qs > se || qe < ss){
            // TODO: change as per problem
            return 0;
        }
        if(ss >= qs && se <= qe) return seg[node];
        int mid = (ss+se)/2;
        T q1 = query(node*2+1,ss,mid,qs,qe);
        T q2 = query(node*2+2,mid+1,se,qs,qe);
        return combine(q1,q2);
    }
public:
    inline void build(vector<T>& a)
    {
        build(0,0,n-1,a);
    }
    inline void update(int updidx,T val)
    {
        update(0,0,n-1,updidx,val);
    }
    inline T query(int qs,int qe)
    {
        return query(0,0,n-1,qs,qe);        
    }
};
