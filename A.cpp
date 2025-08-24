#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int count = 0;
    bool zero_found = 0;
    for (size_t i = 0; i <= s.size(); ++i) {
        if (i % 2) {
            if (s[i] == '+' || s[i] == '\0') {
                count += 1 - zero_found;
                zero_found = 0;
            }
        } else {
            if (s[i] == '0') {
                zero_found = 1;
            }
        }
    }
    std::cout << count;
}