typedef long long int lli;
const lli INF = 0x3fffffffffffffff;
const int MAX_V = 100000;

// 辺を表す構造体 (行き先、容量、逆辺)
struct edge { int to; lli cap; int rev; };

vector<edge> G[MAX_V];  // グラフの隣接リスト表現
vi level(MAX_V);      // sからの距離
vi iter(MAX_V);       // どこまで調べ終わったか

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, lli cap){
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

// sからの最短距離をBFSで計算する
void bfs(int s){
  fill(all(level), -1);
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    int v = que.front(); que.pop();
    for(int i = 0; i < G[v].size(); i++){
      edge &e = G[v][i];
      if(e.cap > 0 && level[e.to] < 0){
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

// 増加パスをDFSで探す
lli dfs(int v, int t, lli f){
  if(v == t) return f;
  for(int &i = iter[v]; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to]){
      lli d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

// sからtへの最大流を求める
lli max_flow(int s, int t){
  lli flow = 0;
  for(;;){
    bfs(s);
    if(level[t] < 0) return flow;
    fill(all(iter), 0);
    lli f;
    while(f = dfs(s, t, INF) > 0) flow += f;
  }
}
