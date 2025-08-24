#include <iostream>
#include <string>
#include <vector>


int del_and_chk(const std::string& s, const std::vector<std::string>::iterator& iterator, std::vector<std::string>& strings) {
    size_t s_size = s.size();
    if (s_size == 1) {
        return 0;
    }
    int total = 0;
    std::string tmp[2];
    for (int i = 0; i < s_size; ++i) {
        if (i != 0) {
            tmp[0] += s[i];
        }
        if (i != 1) {
            tmp[1] += s[i];
        }
    }
    for (auto it = strings.begin(); it != strings.end(); ) {
        if (it != iterator) {
            for (int j = 0; j < 2; ++j) {
                if (tmp[j] == *it) {
                    total += 1;
                    it = strings.erase(it);
                }
            }
        }
        ++it;
    }
    
    
    for (int i = 0; i < 2; ++i) {
        total += del_and_chk(tmp[i], iterator, strings);
    } 
    return total;
}

int main() {
    std::string s;
    int num_of_str;
    std::getline(std::cin, s);
    num_of_str = s[0] - '0';

    std::vector<std::string> strings(num_of_str);
    for (int i = 0; i < num_of_str; ++i) {
        std::getline(std::cin, strings[i]);
    }
    int count = 0;
    for (int i = 0; i < num_of_str; ++i) {
        std::vector<std::string> tmp_cpy = strings;
        auto it = tmp_cpy.begin() + i;
        count += del_and_chk(strings[i], it, tmp_cpy);
    }
    std::cout << count;

    return 0;
}