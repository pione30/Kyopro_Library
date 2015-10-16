const int INF = 0x3fffffff;
const int MAX_N = 100;
vvi D(MAX_N, vi(MAX_N, INF));

int N;

void init(){
  for(int i = 0; i < N; i++) D[i][i] = 0;
}

void warshall_floyd(){
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}
