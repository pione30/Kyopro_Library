#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll binarySearch(function<bool(ll)> func, ll include, ll exclude) {
  while (abs(exclude - include) > 1) {
    ll middle = (include + exclude) / 2;
    (func(middle) ? include : exclude) = middle;
  }
  return include;
}
