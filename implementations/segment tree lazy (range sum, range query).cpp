struct SegmentTreeLazy {
  vector<long long> seg, lazy;
  
  void init(int n) {
    seg.assign(4*n, 0);
    lazy.assign(4*n, 0);
  }
  
  void build(int node, int ss, int se, vector<long long>& arr) {
    if (ss>se) return;
    if (ss==se) {
      seg[node]=arr[ss];
      return;
    }
    int mid=(ss+se)/2;
    build(node*2+1, ss, mid, arr);
    build(node*2+2, mid+1, se, arr);
    seg[node]=seg[node*2+1]+seg[node*2+2];
  }
  
  void push(int node, int ss, int se) {
    if (ss==se) return;
    seg[node*2+1]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    seg[node*2+2]+=lazy[node];
    lazy[node*2+2]+=lazy[node];
    lazy[node]=0;
  }
  
  void update(int node, int ss, int se, int us, int ue, long long val) {
    if (ss>se || us>se || ue<ss) return;
    push(node, ss, se);
    if (ss>=us && se<=ue) {
      seg[node]+=val;
      lazy[node]+=val;
      return;
    }
    int mid=(ss+se)/2;
    update(node*2+1, ss, mid, us, ue, val);
    update(node*2+2, mid+1, se, us, ue, val);
    seg[node]=seg[node*2+1]+seg[node*2+2];
  }
  
  long long query(int node, int ss, int se, int qs, int qe) {
    if (ss>se || qs>se || qe<ss) return 0;
    push(node, ss, se);
    if (ss>=qs && se<=qe) return seg[node];
    int mid=(ss+se)/2;
    long long q1=query(node*2+1, ss, mid, qs, qe);
    long long q2=query(node*2+2, mid+1, se, qs, qe);
    return q1+q2;
  }
};
