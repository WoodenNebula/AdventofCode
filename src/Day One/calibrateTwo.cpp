/* Same concept as part one but it also accounts for spelt out words now i.e. "one" is a valid number*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

bool CompareStrings(std::string::const_iterator& indexItr, const std::string& target)
{
    bool isSame = true;

    for(int i = 0; i < target.size(); i++, indexItr++)
    {
        isSame *= *indexItr == target[i];
        if(!isSame)
            return isSame;
    }

    return isSame;
    
}

int GetIndividualCalib(const std::string& line)
{

    std::vector<int> num;

    for(int i = 0; i < line.size(); i++)
    {
        char temp = line[i];

        switch (temp)
        {
            case 'O':
                {
                    std::string number = "ONE";

                    if(line.size() - i < number.size())
                        break;
                    else
                    {
                        auto itr = line.cbegin() + i;
                        if(CompareStrings(itr, number))
                        {
                            num.push_back(1);
                        }
                    }    
                    break;
                }

            case 'N':
                {
                    std::string number = "NINE";

                    if(line.size() - i < number.size())
                        break;
                    else
                    {
                        auto itr = line.cbegin() + i;
                        if(CompareStrings(itr, number))
                        {
                            num.push_back(9);
                        }
                    }                
                    break;
                }

            case 'E':
                {
                    std::string number = "EIGHT";

                    if(line.size() - i < number.size())
                        break;
                    else
                    {
                        auto itr = line.cbegin() + i;
                        if(CompareStrings(itr, number))
                        {
                            num.push_back(8);
                        }
                    }
                    break;

                }

            case 'T':
                {
                    std::string two = "TWO";
                    std::string three = "THREE";
                    std::string ten = "TEN";

                    auto itr = line.cbegin() + i;

                    // Check for Two or Ten
                    if(line.size() - i >= two.size())
                    {
                        if(CompareStrings(itr, two))
                        {
                            num.push_back(2);
                            break;
                        }
                        else if(CompareStrings((itr = line.cbegin() + i), ten))
                        {
                            num.push_back(10);
                            break;
                        }
                    }

                    if(line.size() - i < three.size())
                        break;
                    else
                    {
                        if(CompareStrings((itr = line.cbegin() + i), three))
                        {
                            num.push_back(3);
                            break;
                        }
                    }
                }

            case 'F':
                {
                    std::string four = "FOUR";
                    std::string five = "FIVE";

                    auto itr = line.cbegin() + i;

                    if(line.size() - i >= four.size())
                    {
                        if(CompareStrings(itr, four))
                        {
                            num.push_back(4);
                            break;
                        }
                        else if(CompareStrings((itr = line.cbegin() + i), five))
                        {
                            num.push_back(5);
                            break;
                        }
                    }
                    break;
                }

            case 'S':
                {
                    std::string six = "SIX";
                    std::string seven = "SEVEN";

                    auto itr = line.cbegin() + i;

                    if(line.size() - i >= six.size())
                    {
                        if(CompareStrings(itr, six))
                        {
                            num.push_back(6);
                            break;
                        }
                    }

                    if(line.size() - i < seven.size())
                        break;
                    else if(CompareStrings((itr = line.cbegin() + i), seven))
                    {
                        num.push_back(7);
                        break;
                    }
                    break;
                }

            default:
                {
                    if(temp >= '0' && temp <= '9')
                        num.push_back((int)(temp - '0'));
                    break;
                }
        }
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

    long int calibVal = 0;

    // int i = 1;
    
    while(std::getline(inputFile, line))
    {
        std::transform(line.begin(), line.end(), line.begin(), toupper);

        // std::cout << "[" << i << "] Individual Calib: " << GetIndividualCalib(line) << std::endl;

        calibVal += GetIndividualCalib(line);
        
        // i++;
    }

    std::cout << "\nThe calibiration value of the doc is = " << calibVal << std::endl;

    return 0;
}