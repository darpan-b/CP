#include <bits/stdc++.h>

#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#define endl '\n'
#endif

using namespace std;

const int MAX_N = 1e5 + 5;
const int LOG_N = __lg(MAX_N) + 2;

int n;
vector<int> adj[MAX_N];

//////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> adj_centroid[MAX_N];
bool marked_as_centroid[MAX_N];
queue<pair<int, int>> pending_nodes;
int subtree_size_centroid[MAX_N];
int parent_in_centroid_tree[MAX_N];

void dfsSubtreeSizes(int node, int par) {
  subtree_size_centroid[node] = 1;
  for (int u : adj[node]) {
    if (u == par || marked_as_centroid[u]) continue;
    dfsSubtreeSizes(u, node);
    subtree_size_centroid[node] += subtree_size_centroid[u];
  }
}

void dfsFindCentroid(int node, int par, int& current_centroid, int tree_size) {
  current_centroid = node;
  for (int u : adj[node]) {
    if (u == par || marked_as_centroid[u]) continue;
    if (subtree_size_centroid[u] * 2 > tree_size) {
      dfsFindCentroid(u, node, current_centroid, tree_size);
    }
  }
}

int findCentroid() {
  /// First, preprocess subtree sizes of all remaining nodes.
  /// Then figure out the centroid from there.
  
  while (marked_as_centroid[pending_nodes.front().first]) pending_nodes.pop();
  auto current_node = pending_nodes.front();
  pending_nodes.pop();
  
  dfsSubtreeSizes(current_node.first, -1);
  int current_centroid = current_node.first;
  dfsFindCentroid(current_node.first, -1, current_centroid, subtree_size_centroid[current_node.first]);
  parent_in_centroid_tree[current_centroid] = current_node.second;
  marked_as_centroid[current_centroid] = true;
  return current_centroid;
}

void buildCentroidTree() {
  pending_nodes.push({0, -1});
  while (!pending_nodes.empty()) {
    /// Find out the next centroid
    int next_centroid = findCentroid();
    
    /// Now, for all children of the centroid, if they are not processed already,
    /// add them to the queue.
    for (int u : adj[next_centroid]) {
      if (!marked_as_centroid[u]) {
        pending_nodes.push({u, next_centroid});
      }
    }
  }
  
  /// All preprocessing done, now build centroid tree from parent array.
  for (int i = 0; i < n; i++) {
    if (parent_in_centroid_tree[i] == -1) continue;
    adj_centroid[parent_in_centroid_tree[i]].push_back(i);
    adj_centroid[i].push_back(parent_in_centroid_tree[i]);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
int ancestor[MAX_N][LOG_N];
int depth[MAX_N];

void dfsLCA(int node, int par, int dep) {
  ancestor[node][0] = par;
  depth[node] = dep;
  for (int i = 1; i < LOG_N; i++) {
    if (ancestor[node][i - 1] == -1) ancestor[node][i] = -1;
    else ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1];
  }
  for (int u : adj[node]) {
    if (u == par) continue;
    dfsLCA(u, node, dep + 1);
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = LOG_N - 1; i >= 0; i--) {
    if (depth[u] - (1 << i) >= depth[v]) {
      u = ancestor[u][i];
    }
  }
  if (u == v) return u;
  for (int i = LOG_N - 1; i >= 0; i--) {
    if (ancestor[u][i] != ancestor[v][i]) {
      u = ancestor[u][i];
      v = ancestor[v][i];
    }
  }
  return ancestor[u][0];
}

int distanceInTree(int u, int v) {
  return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

int best[MAX_N];

void update(int node, int coloured_node) {
  if (node < 0 || node >= n) return;
  best[node] = min(best[node], distanceInTree(node, coloured_node));
  update(parent_in_centroid_tree[node], coloured_node);
}

void query(int node, int concerned_node, int& current_answer) {
  if (node < 0 || node >= n) return;
  current_answer = min(current_answer, best[node] + distanceInTree(node, concerned_node));
  query(parent_in_centroid_tree[node], concerned_node, current_answer);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(ancestor, -1, sizeof(ancestor));

  buildCentroidTree();
  dfsLCA(0, -1, 0);
  
  for (int i = 0; i < n; i++) best[i] = 1e9;
  update(0, 0);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int node;
      cin >> node;
      node--;
      update(node, node);
    } else {
      int node;
      cin >> node;
      node--;
      int answer = 1e9;
      query(node, node, answer);
      cout << answer << endl;
    }
  }
  return 0;
}
