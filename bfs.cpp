typedef pair<int, int> P;

void bfs(){
  vector<bool> used(N);
  queue<int> que;
  que.push(0);
  while(!que.empty()){
    int v = que.front();
    used[v] = true;
    for(P &p : tree[v]){
      if(!used[p.first]){

        que.push(p.first);
      }
    }
    que.pop();
  }
}
