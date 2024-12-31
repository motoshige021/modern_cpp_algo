#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>


struct Seiza {
    std::string name;
    int8_t start_month;
    int8_t start_day;
    int8_t end_month;
    int8_t end_day;
};

const std::vector<Seiza> seiza_list = {
    { "水瓶座", 1, 20, 2, 18},
    { "魚座", 2, 19, 3, 20 },
    { "牡羊座", 3, 21, 4, 19 },
    { "牡牛座", 4, 20, 5, 20 },
    { "双子座", 5, 21, 6, 21 },
    { "蟹座", 6, 22, 7, 22 },
    { "獅子座", 7, 23, 8, 22 },
    { "乙女座", 8, 23, 9, 22 },
    { "天秤座", 9, 23, 10, 23 },
    { "蠍座", 10, 24, 11, 22 },
    { "射手座", 11, 23, 12, 21 },
    { "山羊座", 12, 22, 1, 19 },
};

const std::vector<int8_t> month_maxday = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int8_t get_monthday(int32_t month) {
    if (month < 1 || month > month_maxday.size()) {
        return -1;
    } 
    return month_maxday[month -1]; 
}

int32_t check_nubmer(std::string str_number, int8_t max_number) {
    int32_t number = 0;
    try {
        number = std::stoi(str_number, nullptr, 10);
    } catch (std::exception ex) {
        std::cout << ex.what() << '\n';
        return -1; 
    }
    if (number < 1) { return -1; }
    if (number > max_number) { return -1; }
    return number;
}

int main(void) {
    int32_t month = 0;
    int32_t day = 0;
    std::string buf;
    std::cout << "Input month ";
    std::cin >> buf;
    month = check_nubmer(buf, 12);
    if (month < 0) {
        std::cout << "Error Invalid number: " << buf << '\n';
        return -1;
    }
    std::cout << "Input day ";
    std::cin >> buf;
    day = check_nubmer(buf, get_monthday(month));
    if (day < 0) {
        std::cout << "Error Invalid number: " << buf << '\n';
        return -1;
    }
    for (const auto &seiza : seiza_list) {
        if ((seiza.start_month == month && seiza.start_day <= day) || 
            (seiza.end_month == month && seiza.end_day >= day)) {
            std::cout << seiza.name << '\n';
            return 0;
        }
    }
    std::cout << "No match seiza" << '\n';
    return 0;
}
