int bitCount(int x){
  int num = 0;
  for (int f = 1; f < (1 << N); f <<= 1){
    if (x & f) ++num;
  }
  return num;
}

int main(){
  
  for (int i = 0; i < (1 << N); ++i){
    if (bitCount(i) !=  ) continue;

    for (int j = 0; j < N; ++j){
      if ((i >> j) % 2 == 1){
        
      }
    }
  }
  return 0;
}
