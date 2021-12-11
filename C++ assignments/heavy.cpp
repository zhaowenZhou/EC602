// Copyright 2021 ZhaowenZhou zzwzhou@bu.edu
#include <string>
#include <vector>
using std::string;

int main(int argc, char** argv) {
  int n = std::stoi(argv[1]);
  int b = std::stoi(argv[2]);
  std::vector<int> r;
  std::vector<int> s;
  while(true) {
    while (n > 0) {
      int re = n % b ;
      r.push_back(re);
      n /= b;
    }
    int ele_sum = 0;
    for(int i = 0; i < r.size(); i++) {
      ele_sum = ele_sum + r.at(i) * r.at(i);
    }
    if(ele_sum == 1) {
      return 1;
      break;
    }
    int sign = 0;
    for(int k = 0; k < s.size(); k++) {
      if (ele_sum == s.at(k)) {
        sign = sign + 1;
      }
    }
    if(sign > 0) {
      return 0;
      break;
    }
    s.push_back(ele_sum);
    n = ele_sum;
    r.clear();
  }

}
