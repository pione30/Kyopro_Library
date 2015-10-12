#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli binarySearch(function<bool(lli)> func, lli include, lli exclude) {
  while (abs(exclude - include) > 1) {
    lli middle = (include + exclude) / 2;
    (func(middle) ? include : exclude) = middle;
  }
  return include;
}
