#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int CountHighlyProfitableMonths(std::vector<int> stockPrices, int k) {

  int j = 1;
  int ans = 0;
  int count = 0;

  while (j < stockPrices.size()) {
    if (stockPrices[j] > stockPrices[j - 1]) {
      count++;
    } else {
      if (count + 1 >= k) {
        ans += count - k + 2;
        count = 0;
      }
    }
    j++;
  }
  if (count + 1 >= k)
    ans += count - k + 2;
  return ans;
}

int main() {
  std::cout << CountHighlyProfitableMonths({5, 3, 5, 7, 8}, 3) << "\n";
  return 0;
}