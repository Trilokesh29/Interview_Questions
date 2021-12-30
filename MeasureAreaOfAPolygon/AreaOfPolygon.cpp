#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

std::pair<float, float> split(std::string data) {

  size_t pos = 0;
  std::string token;
  const std::string delimiter = ",";
  std::string::size_type sz;
  while ((pos = data.find(delimiter)) != std::string::npos) {
    token = data.substr(0, pos);
    data.erase(0, pos + delimiter.length());
  }

  data.erase(std::remove(data.begin(), data.end(), ' '), data.end());
  token.erase(std::remove(token.begin(), token.end(), ' '), token.end());

  return std::make_pair<float, float>(stof(token, &sz), stof(data, &sz));
}

void parse_input(std::vector<std::vector<std::pair<float, float>>> &input) {

  std::ifstream in("input.txt");
  if (in.is_open()) {
    std::string row;
    std::vector<std::pair<float, float>> temp;
    while (std::getline(in, row)) {

      if (row.empty()) {
        input.push_back(temp);
        temp.clear();
      } else {
        temp.push_back(split(row));
      }
    }
    input.push_back(temp);
  }
}

int main() {
  std::vector<std::vector<std::pair<float, float>>> input;
  parse_input(input);

  int count = 1;
  for (const auto &data : input) {
    if (data.size() == 4) {
      cout << "Area of set no: " << count << " is: ";
      const auto x1 = data[0].first;
      const auto y1 = data[0].second;
      const auto x2 = data[1].first;
      const auto y2 = data[1].second;
      const auto x3 = data[2].first;
      const auto y3 = data[2].second;
      const auto x4 = data[3].first;
      const auto y4 = data[3].second;
      const auto area = ((x1 * y2 - y1 * x2) + (x2 * y3 - y2 * x3) +
                         (x3 * y4 - y3 * x4) + (x4 * y1 - y4 * x1)) /
                        2;

      cout << area << "\n";
      ++count;
    } else {
      cerr << "check the input file: there must be four co-ordinates before "
              "empty line \n";
    }
  }
}