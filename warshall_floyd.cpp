const int MAX_N = 100;
vvi D(MAX_N, vi(MAX_N));

void warshall_floyd(){
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}