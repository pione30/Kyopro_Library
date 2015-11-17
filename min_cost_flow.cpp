// 辺を表す構造体
struct edge { int to, cap, cost, rev; };

const int INF = 0x3fffffff;
int V;
vector<edge> G[V];      // グラフの隣接リスト表現
vi dist(V);             // 最短距離(通る辺のコストの和)
vi prevv(V), preve(V);  // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
  G[from].PB((edge){to, cap, cost, G[to].size()});
  G[to].PB((edge){from, 0, -cost, G[from].size() - 1});
}

// sからtへの流量fの最小費用流を求める
// 流せない場合は-1を返す
int min_cost_flow(int s, int t, int f){
  int res = 0;
  while(f > 0){
    // ベルマンフォード法により、s-t間最短路を求める
    fill(all(dist), INF);
    dist[s] = 0;
    bool update = true;
    while(update){
      update = false;
      rep(v, V){
        if(dist[v] == INF) continue;
        int vs = G[v].size();
        rep(i, vs){
          edge &e = G[v][i];
          if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            update = true;
          }
        }
      }
    }

    if(dist[t] == INF){
      // これ以上流せない
      return -1;
    }

    // s-t間最短路に沿って目一杯流す
    int d = f;
    for(int v = t; v != s; v = prevv[v]){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * dist[t];
    for(int v = t; v != s; v = prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}
