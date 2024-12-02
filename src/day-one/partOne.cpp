#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using Col = std::array<unsigned int, 1000>;

void parseInput(Col& arrL, Col& arrR) {
  std::ifstream io("./src/day-one/partOneInput.txt");

  if (!io) { std::cerr << "file open failed!"; return; }

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

int main() {
  Col arrL, arrR;
  parseInput(arrL, arrR);
  unsigned int totalDistance = findTotalDistance(arrL, arrR);
  std::cout << "Total Distance is " << totalDistance << std::endl;
}