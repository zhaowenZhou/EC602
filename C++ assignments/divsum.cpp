// Copyright 2021 ZhaowenZhou zzwzhou@bu.edu
#include <iostream>
#include <cstdint>
using std::cin;
using std::cout;
int main(){
    while(true){
    int64_t total, i, x;
    cin >> x;
    if (x != 0){
        total = 1;
        cout << x << ":" << " " << 1;
        for (i = 2; i < (x/2 + 1) ; i++){
            if(x % i == 0){
                total = total + (x/i);
                cout << "+" << i;
            }
        }
        cout << " = " << total << "\n";
    }
    else{
        break;
    }
    }
    return 0;
}