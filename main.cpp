#include "mat.h"
#include <iostream>
#include <vector>

int main(){
    int nfac, npow, ns, ms, nd, md, nfib;
    std::cout << "Введите число большее 100: ";
    std::cin >> nfac;
    std::vector<int> resfac = factorial(nfac);
    std::cout << nfac << "! = ";
    for (int i = resfac.size() - 1; i >= 0; i--) std::cout << resfac[i];
    std::cout << "\n";
    std::cout << "Введите число большее 64: ";
    std::cin >> npow;
    std::vector<int> respow = powtwo(npow);
    std::cout << "2^" << npow << " = ";
    for (int i = respow.size() - 1; i >= 0; i--) std::cout << respow[i];
    std::cout << "\n";
    std::cout << "Введите два числа большее 64 каждое: ";
    std::cin >> ns >> ms;
    std::vector<int> ress = sumpowtwo(powtwo(ns), powtwo(ms));
    std::cout << "2^" << ns << " + 2^" << ms << " = ";
    for (int i = ress.size() - 1; i >= 0; i--) std::cout << ress[i];
    std::cout << "\n";
    std::cout << "Введите два числа большее 64 каждое, первое строго больше второго: ";
    std::cin >> nd >> md;
    std::vector<int> resd = difpowtwo(nd, md);
    std::cout << "2^" << ns << " - 2^" << ms << " = ";
    for (int i = resd.size() - 1; i >= 0; i--) std::cout << resd[i];
    std::cout << "\n";
    std::cout << "Введите число большее 100: ";
    std::cin >> nfib;
    std::vector<int> resfib = fibonachi(nfib);
    std::cout << nfib << "-ый член числа Фибоначчи: ";
    for (int i = resfib.size() - 1; i >= 0; i--) std::cout << resfib[i];
    return 0;
}
