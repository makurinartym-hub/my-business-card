#include "mat.h"
#include <iostream>
#include <vector>


std::vector<int> factorial(int n){
    std::vector<int> res;
    res.push_back(1);
    if (n == 0) return res;
    for(int i=2; i <= n; i++){
        int carry = 0;
        for(int j = 0; j < res.size(); j++){
            int prod = res[j]*i+carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry){
            res.push_back(carry%10);
            carry/=10;
        }
    }
    return res;
}
std::vector<int> powtwo(int n){
    std::vector<int> res;
    res.push_back(1);
    if (n == 0) return res;
    for(int i=2; i <= n; i++){
        int carry = 0;
        for(int j = 0; j < res.size(); j++){
            int prod = res[j]*2+carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry){
            res.push_back(carry%10);
            carry/=10;
        }
    }
    return res;
}
std::vector<int> sumpowtwo(std::vector<int> n,  std::vector<int> m){
    std::vector<int> resn(n);
    std::vector<int> resm(m);
    std::vector<int> res;
    if(resm.size() > resn.size()) resn.resize(resm.size());
    else if(resm.size() < resn.size()) resm.resize(resn.size());
    int carry = 0;
    for(int i = 0; i < resn.size(); i++){
        int prod = resn[i]+resm[i]+carry;
        res.push_back(prod % 10);
        carry = prod / 10;
    }
    if (carry > 0) res.push_back(carry);
    return res;
}
std::vector<int> difpowtwo(int n,  int m){
    std::vector<int> resn = powtwo(n);
    std::vector<int> resm = powtwo(m);
    std::vector<int> res;
    if(resm.size() > resn.size()) resn.resize(resm.size());
    else if(resm.size() < resn.size()) resm.resize(resn.size());
    int borrow = 0;
    for(int i = 0; i < resn.size(); i++){
        int prod = resn[i]-resm[i]-borrow;
        if(prod < 0){
            res.push_back(prod+10);
            borrow = 1;
        }
        else{
            res.push_back(prod);
            borrow = 0;
        }
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}
std::vector<int> fibonachi(int n) {
    std::vector<std::vector<int>> fib;
    fib.push_back({0});
    if (n == 0) return fib[0];
    fib.push_back({1});
    if (n == 1) return fib[1];
    for (int i = 2; i <= n; i++) {
        std::vector<int> next = sumpowtwo(fib[i-1], fib[i-2]);
        fib.push_back(next);
    }
    return fib[n];
}