const int INF = 0x7FFFFFFF - 10;

struct edge {int to, cost; };
typedef pair<int, int> P;

const int MAX_V = 100;
vector<edge> G[MAX_V]; // グラフを表す
vi d(MAX_V, INF); // 始点からの最小コストが格納される

void dijkstra(int s){
  // greater<P>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P> > que;
  // fill(all(d), INF);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}
