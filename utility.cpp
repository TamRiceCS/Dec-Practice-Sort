#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class utility
{
private:
    static bool processFile(std::string fileName, std::vector<int> &sortable)
    {
        std::string fileLine = "";
        std::vector<int> temp = {};
        try
        {
            std::ifstream vectorFile(fileName);
            if (!vectorFile.is_open())
            {
                std::cout << "Could not open the file..." << std::endl;
            }
            else
            {
                std::getline(vectorFile, fileLine);
            }
        }
        catch (...)
        {
            std::cout << "Something went wrong with the file... Please try again..." << std::endl;
            return false;
        }
        if (fileLine != "")
        {
            int index = 0;
            int sign = 1;
            temp.clear();
            for (int i = 0; i < fileLine.size(); i++)
            {
                if (std::isdigit(fileLine[i]))
                {
                    index *= 10;
                    index += (fileLine[i] - '0');
                }
                else if (fileLine[i] == '-')
                {
                    sign = -1;
                }
                else if (fileLine[i] == ',' || fileLine[i] == '}')
                {
                    temp.push_back(index * sign);
                    index = 0;
                    sign = 1;
                }
            }
        }

        outputVector(temp);
        sortable = temp;
        return true;
    }

public:
    static void outputVector(std::vector<int> outputVector)
    {
        std::cout << "{";
        for (int i = 0; i < outputVector.size(); i++)
        {
            if (i == outputVector.size() - 1)
            {
                std::cout << outputVector[i];
            }
            else
            {
                std::cout << outputVector[i] << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
    static bool loadUnique(std::vector<int> &sortable)
    {
        std::string fileName = "";
        bool temp = false;

        std::cout << "Please provide a file (.txt) to load a vector in from." << std::endl;
        std::cout << "Enter \'b\' to go back to the main menu..." << std::endl;

        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> fileName;

        if (fileName != "b")
        {
            return processFile(fileName, sortable);
        }

        return false;
    }
    static bool loadRandom(std::vector<int> &sortable)
    {
        int indexes = (rand() % 25) + 5; // [5, 24]
        for (int i = 0; i < indexes; i++)
        {
            sortable.push_back((rand() % 101) - 50); // [-50, 50]
        }

        std::cout << "\nThe randomly generated vector is: " << std::endl;
        outputVector(sortable);
        return true;
    }
    static bool loadGeneric(std::vector<int> &sortable)
    {
        std::vector<std::string> sampleFiles = {"neg_example.txt", "pos_neg_zero_example.txt", "simple_example.txt"};
        int choice = rand() % 3;

        std::cout << "\nA sample vector is being generated with the file " + sampleFiles[choice] << std::endl;

        return processFile(sampleFiles[choice], sortable);
    }
    std::vector<int> getVector();
};