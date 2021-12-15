#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int minimumSwaps(vector<int> popularity) {
  int nrSwaps = 0;
  size_t nrOfElements = popularity.size();
  size_t indexArray[nrOfElements + 1];
  for (uint32_t index = 0U; index < nrOfElements; ++index) {
    indexArray[popularity[index]] = index;
  }

  int desiredPopularity = 0;
  int currentPopularity = 0;
  for (uint32_t index = 0U; index < nrOfElements; ++index) {
    desiredPopularity = nrOfElements - index;
    currentPopularity = popularity[index];
    if (currentPopularity != desiredPopularity) {
      popularity[index] = desiredPopularity;
      size_t swapIndex = indexArray[desiredPopularity];
      popularity[swapIndex] = currentPopularity;

      indexArray[desiredPopularity] = nrOfElements - index;
      indexArray[currentPopularity] = swapIndex;
      ++nrSwaps;
    }
  }
  return nrSwaps;
}

int main() {
  cout << minimumSwaps({3, 4, 1, 2}) << "\n";
  return 0;
}