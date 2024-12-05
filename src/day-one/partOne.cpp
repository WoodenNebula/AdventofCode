#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <unordered_map>

using Col = std::array<unsigned int, 1000>;

void parseInput(Col& arrL, Col& arrR) {
  std::ifstream io("./src/day-one/partOneInput.txt");

  if (!io) { std::cerr << "file open failed!"; abort(); }

  size_t i = 0;
  while (!io.eof()) {
    io >> arrL[i] >> arrR[i];
    i++;
  }

  std::sort(arrL.begin(), arrL.end());
  std::sort(arrR.begin(), arrR.end());
}

unsigned int findTotalDistance(const Col& arrL, const Col& arrR) {
  unsigned int distanceSum = 0;
  for (size_t i = 0; i < arrL.size(); i++) {
    distanceSum += abs(arrL[i] - arrR[i]);
  }
  return distanceSum;
}


struct Repeats {
  unsigned int left = 0;
  unsigned int right = 0;

  friend std::ostream& operator<<(std::ostream& out, const Repeats& r) {
    out << "{" << r.left << ", " << r.right << "}";
    return out;
  }
};

void partTwo(const Col& L, const Col& R) {
  std::unordered_map<unsigned int, Repeats> repeatList;
  repeatList.reserve(L.size());

  for (const unsigned int& l : L) {
    if (repeatList.contains(l)) {
    // increase the count of left elements
      auto& [_l, _r] = repeatList[l];
      _l++;
    }
    else {
      // element from l doesnt exist so need to count all l in colR
      unsigned int countInR = 0;

      for (unsigned int r : R) {
        if (l < r) { continue; }
        else if (l == r) { countInR++; }
        else if (countInR > 0 && r < l) { break; }
      }

      repeatList[l] = { 1, countInR };
    }
  }

  unsigned int totalScore = 0;
  for (const auto& [l, repeats] : repeatList) {
    totalScore += l * repeats.left * repeats.right;
  }
  std::cout << totalScore << std::endl;
}

int main() {
  Col arrL, arrR;
  parseInput(arrL, arrR);

    // unsigned int totalDistance = findTotalDistance(arrL, arrR);
    // std::cout << "Total Distance is " << totalDistance << std::endl;
  partTwo(arrL, arrR);
}