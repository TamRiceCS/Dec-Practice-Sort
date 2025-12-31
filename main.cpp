#include <iostream>
#include <string>
#include <vector>
#include "utility.cpp"
#include "sorting.cpp"

bool buildMenu(char &userChar, std::vector<int> &userSortable)
{
    userSortable.clear();
    while (userChar != 'x' && userSortable.empty())
    {
        std::cout << "\n\nPlease generate a vector to work with, empty vectors are not valid." << std::endl;
        std::cout << "   1. Enter a vector..." << std::endl;
        std::cout << "   2. Randomly generate a vector..." << std::endl;
        std::cout << "   3. Use a sample vector..." << std::endl;
        std::cout << "   Press \'x\' to exit the program..." << std::endl;

        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> userChar;

        switch (userChar)
        {
        case '1':
        {
            std::cout << "\nYou selected option 1..." << std::endl;
            if (utility::loadUnique(userSortable))
            {
                return true;
            }
            break;
        }
        case '2':
        {
            std::cout << "\nYou selected option 2..." << std::endl;
            if (utility::loadRandom(userSortable))
            {
                return true;
            }
            break;
        }
        case '3':
        {
            std::cout << "\nYou selected option 3..." << std::endl;
            if (utility::loadGeneric(userSortable))
            {
                return true;
            }
            break;
        }
        case 'x':
        {
            std::cout << "\nLooks like you chose to exit..." << std::endl;
            return false;
            break;
        }
        }
    }
    return true;
}

bool sortMenu(char &userChar, std::vector<int> &userSortable)
{

    while (userChar != 'x')
    {
        std::cout << "\n\nPlease pick a sortign algoritm to work with (all sort smallest -> biggest)..." << std::endl;
        std::cout << "   1. Bubble Sort..." << std::endl;
        std::cout << "   2. Insertion Sort..." << std::endl;
        std::cout << "   3. Selection Sort..." << std::endl;
        std::cout << "   4. Merge Sort..." << std::endl;
        std::cout << "   5. Quick Sort..." << std::endl;
        std::cout << "   Press \'b\' to enter another vector..." << std::endl;
        std::cout << "   Press \'x\' to exit the program..." << std::endl;

        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> userChar;

        switch (userChar)
        {
        case '1':
        {
            std::cout << "\nYou chose to run Bubble Sort..." << std::endl;
            sorting::bubble(userSortable);
            break;
        }
        case '2':
        {
            std::cout << "\nYou chose to run Insertion Sort..." << std::endl;
            sorting::insert(userSortable);
            break;
        }
        case '3':
        {
            std::cout << "\nYou chose to run Selection Sort..." << std::endl;
            sorting::select(userSortable);
        }
        case '4':
        {
            std::cout << "\nYou chose to run Merge Sort..." << std::endl;
            sorting::mergesort(userSortable, 0, userSortable.size() - 1);
            break;
        }
        case '5':
        {
            std::cout << "\nYou chose to run Quick Sort..." << std::endl;
            sorting::quick(userSortable, 0, userSortable.size() - 1);
            break;
        }
        case 'b':
        {
            std::cout << "\nLooks like you chose to enter another vector, heading back..." << std::endl;
            userSortable.clear();
            return true;
        }
        case 'x':
        {
            std::cout << "\nLooks like you chose to exit..." << std::endl;
            return false;
        }
        }
    }
    return true;
}

int main()
{
    char userChar = '-';
    std::string userStr = "";
    std::vector<int> userSortable = {};
    bool progress = true;

    // Todo: Center text between #'s (should be simple just figure out what the L and R buffer needs to be)
    std::cout << "\nWelcome to my sorting algorithm practice code." << std::endl;

    while (progress)
    {
        // Initial menu
        progress = buildMenu(userChar, userSortable);
        if (!userSortable.empty())
        {
            progress = sortMenu(userChar, userSortable);
        }
    }

    std::cout << "Thank you, bye!\n"
              << std::endl;
}