// Copyright 2021 ZhaowenZhou zzwzhou@bu.edu
#include <iostream>
#include <string>
using namespace std;
int power(int base, int power) {
  int result = base;
  if (power == 0) {
    result = 1;
  } else {
    for (int p = 1; p < power; p++) {
      result = result * base;
    }
  }
  return result;
}
int main(int argc, char** argv) {
  string result = "";
  int n = argv[1];
  int b0 = stoi(argv[2]);
  int b1 = stoi(argv[3]);
  int l = par.length();
  // for (int i = 0; i < l; i++) {
  //   n = n + (static_cast<int>(par.at(i) - 48) * power(b0, l - i - 1));
  // }
  while (n > 0) {
    char re = n % b1 + '0';
    result = re + result;
    n /= b1;
  }
  cout << result << endl;
  return 0;
}
