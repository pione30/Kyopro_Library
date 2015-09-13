typedef long long int lli;

lli MAX_P = 1000;

vi fact(MAX_P); // n! mod p のテーブル O(p)

void init(lli p){
  fact[0] = 1;
  fact[1] = 1;
  for(lli i = 2; i < p; i++){
    fact[i] = fact[i - 1] * i % p;
  }
}

lli extgcd(lli a, lli b, lli& x, lli& y){
	lli d = a;
	if (b != 0){
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}

lli mod_inverse(lli a, lli m){
  lli x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

// n! = a * p^e としたときの a mod p を求める。O(log_p n)
lli mod_fact(lli n, lli p, lli& e){
  e = 0;
  if (n == 0) return 1;

  // pの倍数の部分を計算
  lli res = mod_fact(n / p, p, e);
  e += n / p;

  // (p - 1)! ≡ -1 なので (p - 1)! ^ (n / p) は n / p の偶奇だけで計算できる
  if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
  return res * fact[n % p] % p;
}

// nCk mod p を求める。 O(log_p n)
lli mod_comb(lli n, lli k, lli p){
  if (n < 0 || k < 0 || n < k) return 0;
  lli e1, e2, e3;
  lli a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
  if(e1 > e2 + e3) return 0;
  return a1 * mod_inverse(a2 * a3 % p, p) % p;
}
