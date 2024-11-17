#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <list>

using LIST = std::list<int32_t>;

/*
 * 整数入力
 * out_number : 入力された整数
 * 戻り値 : true 整数が入力された false: 数値以外が入力された
 */
bool intput_number(LIST::value_type *out_number) {
  std::string strtmp;

  std::cout << "Input number: ";
  std::cin >> strtmp;
  // all_of() : 全ての要素が条件を満たしているかを調べる
  if (!std::all_of(strtmp.cbegin(), strtmp.cend(), isdigit)) {
     std::cerr << "Invalid Input number!" << std::endl;
     return false;
  }
  auto ss = std::istringstream(strtmp);
  ss >> *out_number;

  return true;
}

/*
 * n の素数一覧を返す
 * 引数 n : 素数を求める整数
 * 戻り値 : 素数一覧のvector
 */
LIST get_prime(LIST::value_type n) {
  LIST list_prime;
  if (n <=1) { // n が 1以下
    return list_prime; // 空のリストを返す
  }
  list_prime.push_back(2); // 素数リストに2を追加
  int32_t limit = static_cast<int>(sqrt(static_cast<float>(n))); // 検索する上限=√n
  LIST list_data;
  for (int pos = 2; pos < n; pos +=2) { // 奇数リストを作成
    list_data.push_back(1 + pos);
  }
  while (limit > list_data.front()) { // 上限 > 奇数リストの先頭
    list_prime.push_back(list_data.front()); // 素数リストに奇数リストの先頭を追加
    LIST list_tmp; // 空のリストを生成
    // 奇数リストのうち先頭の数で割り切れない数をリストに追加
    for (auto i : list_data) {
      if (i % list_data.front() != 0) {
          list_tmp.push_back(i);
      } 
    }
    list_data = std::move(list_tmp); // 奇数リスト = リスト
  }
  // 素数リストに奇数リストを合わせたリストを返す
  std::copy(list_data.begin(), list_data.end(),
            std::back_inserter(list_prime));
  return list_prime;
}

/*
 * prime_numbersの一覧出力
 * 引数 pirime_numbers 素数一覧のvector
 */
void print_prime_numbers(LIST &prime_numbers) {
  for (auto &prime : prime_numbers) {
    std::cout << prime << " ";
  }
  std::cout << std::endl;
}

int main() {
  LIST::value_type number = 0; //素数を求める数
  if (!intput_number(&number)) {
    std::cout << "Invalid Input Number" << std::endl;
    return -1;
  }
  auto list_prime = get_prime(number);
  print_prime_numbers(list_prime); // 返ったリストを表示
  return 0;
}
