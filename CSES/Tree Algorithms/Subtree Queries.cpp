#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif

#define entry uaicsk
#define exit fdcks

const int MAXN=2e5+5;
int n, q;
vector<int> adj[MAXN];
long long wt[MAXN];
long long seg[8*MAXN];
vector<int> euler;
int entry[MAXN], exit[MAXN];

void dfs(int node, int par) {
  euler.push_back(node);
  entry[node]=euler.size()-1;
  for (auto e:adj[node]) {
    if (e==par) continue;
    dfs(e, node);
  }
  euler.push_back(node);
  exit[node]=euler.size()-1;
}

void build(int node, int ss, int se) {
  if (ss>se) return;
  if (ss==se) {
    seg[node]=wt[euler[ss]];
  }
  else {
    int mid=(ss+se)/2;
    build(node*2+1, ss, mid);
    build(node*2+2, mid+1, se);
    seg[node]=seg[node*2+1]+seg[node*2+2];
  }
}

void update(int node, int ss, int se, int uidx, long long val) {
  if (ss>se || ss>uidx || se<uidx) return;
  if (ss==se) {
    seg[node]=val;
  }
  else {
    int mid=(ss+se)/2;
    update(node*2+1, ss, mid, uidx, val);
    update(node*2+2, mid+1, se, uidx, val);
    seg[node]=seg[node*2+1]+seg[node*2+2];
  }
}

long long query(int node, int ss, int se, int qs, int qe) {
  if (ss>se || ss>qe || se<qs) return 0;
  if (ss>=qs && se<=qe) return seg[node];
  int mid=(ss+se)/2;
  long long q1=query(node*2+1, ss, mid, qs, qe);
  long long q2=query(node*2+2, mid+1, se, qs, qe);
  return q1+q2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i=0; i<n; i++) cin >> wt[i];
  for (int i=0; i<n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  int esz=euler.size();
  build(0, 0, esz-1);
  while (q--) {
    int type; cin >> type;
    if (type==1) {
      int node; cin >> node;
      node--;
      long long val; cin >> val;
      update(0, 0, esz-1, entry[node], val);
      update(0, 0, esz-1, exit[node], val);
    }
    else {
      int node; cin >> node;
      node--;
      cout << query(0, 0, esz-1, entry[node], exit[node])/2 << "\n";
    }
  }
}
