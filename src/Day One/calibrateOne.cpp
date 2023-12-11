/*
Given a file containing many lines such that each line has a mixture of characters where 
the FIRST NUMBER and THE LAST NUMBER of that line forming a 2 digit number is the calibration value for that line,
and the sum of all the individual calibration value is the doc's calibration value, return the doc's calibration value
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int GetIndividualCalib(const std::string& line)
{
    std::vector<int> num;

    for(const char x : line)
    {
        if(x >= '0' && x <= '9')
            num.push_back((int)(x - '0'));
    }


    if(num.size() == 1)
    {
        return (num[0] * 10 + num[0]);
    }

    int first = num[0];
    int last = num[num.size() - 1];

    return first*10 + last;
}


int main()
{
    std::fstream inputFile("./res/input.txt");

    if(!inputFile.is_open())
    {
        std::cout << "File opening failed!! ABORT" << std::endl;
        return -1;
    }

    std::string line;

    int calibVal = (int)0.0f;

    while(std::getline(inputFile, line))
    {
        calibVal += GetIndividualCalib(line);
    }

    std::cout << "\nThe calibiration value of the doc is = " << calibVal << std::endl;

    return 0;
}