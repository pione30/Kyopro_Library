const int INF = 0x3fffffff;
const int MAX_V = 1000;

struct edge { int to, cost; };
typedef pair<int, int> P;       // firstは最短距離、secondは頂点の番号

int V;                          // 頂点数
vi mincost(MAX_V);              // 集合Xからの辺の最小コスト
vector<edge> G[MAX_V];

int prim(){
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> > que;
  fill(mincost.begin(), mincost.begin() + V, INF);
  mincost[0] = 0;
  que.push(P(0, 0));

  int res = 0;
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(mincost[v] < p.first) continue;

    res += p.first;  // 辺のコストを加える
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(mincost[e.to] > e.cost){
        mincost[e.to] = e.cost;
        que.push(P(e.cost, e.to));
      }
    }
  }
  return res;
}
