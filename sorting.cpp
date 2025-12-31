#include <iostream>
#include <vector>

class sorting
{
private:
    static void merge(std::vector<int> &sortable, int start, int mid, int end)
    {
        std::vector<int> left;
        std::vector<int> right;

        int lptr = 0;
        int rptr = 0;

        for (int i = start; i <= mid; i++)
        {
            left.push_back(sortable[i]);
        }

        for (int i = mid + 1; i <= end; i++)
        {
            right.push_back(sortable[i]);
        }

        std::cout << "\nSorting the range [" << start << "," << end << "]" << std::endl;

        while (lptr < left.size() || rptr < right.size())
        {
            if (rptr >= right.size())
            {
                sortable[start] = left[lptr];
                std::cout << "   Placed " << left[lptr++] << " at index " << start++ << std::endl;
            }
            else if (lptr >= left.size())
            {
                sortable[start] = right[rptr];
                std::cout << "   Placed " << right[rptr++] << " at index " << start++ << std::endl;
            }
            else if (left[lptr] < right[rptr])
            {
                sortable[start] = left[lptr];
                std::cout << "   Placed " << left[lptr++] << " at index " << start++ << std::endl;
            }
            else
            {
                sortable[start] = right[rptr];
                std::cout << "   Placed " << right[rptr++] << " at index " << start++ << std::endl;
            }
        }

        utility::outputVector(sortable);
    }

    static int partition(std::vector<int> &sortable, int start, int end)
    {
        int pivot = sortable[end];
        int place = start - 1;
        int curr = start;

        std::cout << "\nCurrently working on [" << start << "," << end << "]" << std::endl;

        for (curr = start; curr < end; curr++)
        {
            if (sortable[curr] < pivot)
            {
                place++;
                std::swap(sortable[place], sortable[curr]);
                std::cout << "   Placing " << sortable[place] << " at " << place << " because it is less than " << pivot << std::endl;
                std::cout << "   ";
                utility::outputVector(sortable);
            }
            else
            {
                std::cout << "   " << sortable[curr] << " is greater than " << pivot << " keep out of the lesser indexes." << std::endl;
            }
        }

        std::swap(sortable[place + 1], sortable[end]);
        std::cout << "   Placing " << sortable[end] << " at " << place + 1 << " because we finished the partition " << pivot << std::endl;
        std::cout << "   ";
        utility::outputVector(sortable);
        return place + 1;
    }

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

    static void select(std::vector<int> sortable)
    {
        int smallestInd;

        for (int i = 0; i < sortable.size(); i++)
        {
            std::cout << "\nWorking on index " << i << " with a value of " << sortable[i] << std::endl;
            smallestInd = i;
            for (int j = i; j < sortable.size(); j++)
            {
                smallestInd = (sortable[smallestInd] > sortable[j]) ? j : smallestInd;
                std::cout << "   Found the new smallest number: " << sortable[smallestInd] << std::endl;
            }
            std::swap(sortable[smallestInd], sortable[i]);
            std::cout << "   Placed smallest number " << sortable[smallestInd] << std::endl;
            std::cout << "     ";
            utility::outputVector(sortable);
        }
    }
    static void mergesort(std::vector<int> &sortable, int start, int end)
    {
        if (start == end)
        {
            return;
        }
        int mid = (start + end) / 2;
        mergesort(sortable, start, mid);
        mergesort(sortable, mid + 1, end);
        merge(sortable, start, mid, end);
    }

    static void quick(std::vector<int> &sortable, int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int mid = partition(sortable, start, end);
        quick(sortable, start, mid - 1);
        quick(sortable, mid + 1, end);
    }
};