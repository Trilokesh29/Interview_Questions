/*
for an analysis parameter 'aParam', a group of aparam consecutive months is said
to be  highly profitable if the values of the stocks are strictly in increasing
order for those months.
*/

#include <iostream>
#include <stack>
#include <vector>

int FindProfitableMonthsGroup(const std::vector<int> aStockPrices, int aParam) {

  std::vector<int> reference;
  reference.reserve(aParam);

  int count = 0;
  int refValue = aStockPrices[0];
  reference.push_back(refValue);

  for (int index = 1; index < aStockPrices.size();) {

    if (refValue < aStockPrices[index]) {
      reference.push_back(aStockPrices[index]);

      if (reference.size() == aParam) {
        reference.clear();
        refValue = aStockPrices[index];
        count++;
      } else {
        refValue = aStockPrices[index];
        index++;
      }
    } else {

      reference.clear();
      reference.push_back(aStockPrices[index]);
      refValue = aStockPrices[index];
      index++;
    }
  }

  return count;
}

int main() {

  const auto count = FindProfitableMonthsGroup({10, 20, 30, 30, 40, 50, 60}, 4);

  std::cout << "Result is ========== " << count << "\n";
  return 0;
}