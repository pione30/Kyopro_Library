/* dfs(深さ優先探索)とlca(最小共通祖先)に関するライブラリ */
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int MAX_N = 100000;
const int MAX_LOG_V = 20;
int N, root = 0;
vvi g(MAX_N);
vvi parent(MAX_LOG_V, vi(MAX_N));
vi depth(MAX_N);

void dfs(int v, int p, int d){
  depth[v] = d;
  parent[0][v] = p;
  for(int i = 0; i < g[v].size(); ++i){
    if(g[v][i] != p){
      dfs(g[v][i], v, d+1);
    }
  }
}

void init(){
  dfs(root, -1, 0);
  for(int i = 0; i < MAX_LOG_V - 1; ++i){
    for(int v = 0; v < N; ++v){
      if(parent[i][v] == -1) parent[i + 1][v] = -1;
      else parent[i + 1][v] = parent[i][parent[i][v]];
    }
  }
}

int lca(int u,int v){
  if(depth[u] > depth[v])swap(u,v);
  for(int i = MAX_LOG_V - 1; i >= 0; --i){
    if((depth[v] - depth[u]) >> i) v = parent[i][v];
  }
  if(u == v)return u;
  for(int i = MAX_LOG_V - 1; i >= 0; --i){
    if(parent[i][u] != parent[i][v]){
      u = parent[i][u];
      v = parent[i][v];
    }
  }
  return parent[0][u];
}

int main(){
  cin >> N;
  for(int i = 0; i < N; ++i){
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  init();

  return 0;
}
