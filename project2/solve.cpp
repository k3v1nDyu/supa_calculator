#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

std::string multiply(std::string s, long long n){
    reverse(s.begin(), s.end());
    int mem = 0;
    std::string result;
    int res;
    for (int i = 0; i<s.size(); i++){
        res = n * ((int)s[i] - 48) + mem;
        mem = res/10;
        res %= 10;
        result += res + 48;
    }
    if (mem > 0) result += mem + 48;
    reverse(result.begin(), result.end());
    return result;
}

std::string add(std::string a, std::string b){
    if (b.size() > a.size()) swap(a,b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (b.size()<a.size()) b += 48;
    std::string result;
    int res;
    int mem = 0;
    for (int i = 0; i<a.size(); i++){
        res = a[i] + b[i] - 2*48 + mem;
        mem = res/10;
        res %= 10;
        result += res +  48;
    }
    if (mem > 0) result += mem + 48;
    reverse(result.begin(), result.end());
    return result;
}

std::string multiply(std::string a, std::string b){
    reverse(b.begin(), b.end());
    std::vector<std::string> store;
    for (int i = 0; i<b.size(); i++) {
        store.push_back(multiply(a, (int)b[i] - 48));
        int e = i;
        while (e>0){
            store[i] += 48;
            e--;
        }
    }
    std::string result = store[0];
    for (int i = 1; i<store.size(); i++) result = add(result, store[i]);

    return result;
}

std::string factorial(long long n){
    std::string res = "1";
    for (long long i = 1; i <= n; i++) res = multiply(res, std::to_string(i));
    return res;
}

int main() {
    // std::string a; std::cin >> a;
    // std::string b; std::cin >> b;
    // if (a == "0" || b == "0") {
    //     std::cout << 0;
    //     return 0;
    // }
    //std::cout << MULTIPLY(a,b);
    auto t1 = Clock::now();
    std::cout << factorial(1000);
    auto t2 = Clock::now();
    std::cout << "\nThoi gian tinh toan: " 
              << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()/1000000000 << std::endl;
}