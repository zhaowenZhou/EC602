// Copyright 2021  ZhaowenZhou zzwzhou@bu.edu
#include "bigint.h"
#include <vector>

using std::vector;

BigInt multiply_int(const BigInt &a, const BigInt &b) {
  vector<int> p;
  vector<int> q;
  for (auto i = a.begin(); i != a.end(); ++i) {
    p.push_back(*i - '0');
  }
  for (auto k = b.begin(); k != b.end(); ++k) {
    q.push_back(*k - '0');
  }
  int l1 = p.size();
  int l2 = q.size();

  vector<int> r(l1 + l2 - 1);
  for (int i = 0; i < l1; i++) {
    for (int j = 0; j < l2; j++) {
      r.at(i + j) += p.at(i) * q.at(j);
    }
  }

  vector<int> res;
  for(int i = r.size() - 1; i >= 0; i--) {
    if (r.at(i) > 9) {
      int shang = r.at(i) / 10;
      int yu = r.at(i) % 10;
      if(i == 0) {
        res.insert(res.begin(), yu);
        res.insert(res.begin(), shang);
        break;
      }
      r.at(i - 1) += shang;
      res.insert(res.begin(), yu);
    } else {
      res.insert(res.begin(), r.at(i));
    }
  }

  while (res.size() > 1){
    if (res.at(0) == 0)
      res.erase(res.begin());
    else
      break;
  }

  BigInt str = "";
  for(auto i = res.begin(); i != res.end(); ++i) {
    str += *i + '0';
  }

  return str;
}
