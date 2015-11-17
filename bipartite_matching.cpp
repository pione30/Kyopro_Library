int V = 1000;
vi G[V];              // グラフの隣接リスト表現 
vi match(V);          // マッチングのペア
vector<bool> used(V); // DFSですでに調べたかのグラフ

void add_edge(int u, int v){
  G[u].PB(v);
  G[v].PB(u);
}

// 増加パスをDFSで探す
bool dfs(int v){
  used[v] = true;
  for(int u : G[v]){
    int w = match[u];
    if(w < 0 || !used[w] && dfs(w)){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

// 二部グラフの最大マッチングを求める
int bipartite_matching(){
  int res = 0;
  fill(all(match), -1);
  rep(v, V){
    if(match[v] < 0){
      fill(all(used), false);
      if(dfs(v)) res++;
    }
  }
  return res;
}
