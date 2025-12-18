#include <iostream>
#include <vector>

class sorting
{
private:
public:
    // swap neighbors when necessary
    static void bubble(std::vector<int> sortable)
    {
        std::cout << "\nStarting bubble sort..." << std::endl;
        utility::outputVector(sortable);
        for (int i = 0; i < sortable.size(); i++)
        {
            std::cout << "\nThis is the " << i << "th pass..." << std::endl;
            for (int j = 0; j < sortable.size() - (1 + i); j++)
            {
                std::cout << "   Compare " << sortable[j + 1] << " and " << sortable[j] << std::endl;
                if (sortable[j] > sortable[j + 1])
                {
                    std::swap(sortable[j + 1], sortable[j]);
                    std::cout << "    Swap..." << std::endl;
                    std::cout << "    ";
                    utility::outputVector(sortable);
                }
                else
                {
                    std::cout << "    No swap..." << std::endl;
                }
            }
        }
        utility::outputVector(sortable);
    }
    // place in the correct index of a sorted section
    static void insert(std::vector<int> sortable)
    {
        std::cout << "\nStarting insertion sort..." << std::endl;
        utility::outputVector(sortable);

        for (int i = 0; i < sortable.size() - 1; i++)
        {
            int place = sortable[i + 1];
            sortable[i + 1] = sortable[i];
            int j;

            std::cout << "\nTrying to place " << place << "..." << std::endl;
            for (j = i; j >= 0; j--)
            {
                if (place <= sortable[j])
                {
                    sortable[j + 1] = sortable[j];
                    std::cout << "   ";
                    std::cout << "Index " << j << " is not the correct spot..." << std::endl;
                }
                else
                {
                    j++;
                    break;
                }
            }

            if (j < 0)
            {
                j = 0;
            }
            sortable[j] = place;
            std::cout << "    Index " << j << " IS the correct spot..." << std::endl;
            std::cout << "     ";

            utility::outputVector(sortable);
        }
    }
    static void select();
    static void merge();
    static void quick();
};