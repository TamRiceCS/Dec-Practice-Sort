#include <iostream>
#include <string>
#include <vector>

bool buildMenu(char& userChar, std::vector<int>& userSortable){
    while(userChar != 'x' && userSortable.empty()) {
        std::cout << "\n1. Enter a vector..." << std::endl;
        std::cout << "2. Randomly generate a vector..." << std::endl;
        std::cout << "3. Use a sample vector..." << std::endl;
        std::cout << "Press \'x\' to exit the program..." << std::endl;

        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> userChar;

        // TODO: Saturday -> work on the vector generation c:
        switch(userChar) {
            case '1': {
                std::cout << "\nYou selected option 1..." << std::endl;
                //userSortable = {1,2,3,4,5};
                break;
            }
            case '2': {
                std::cout << "\nYou selected option 2..." << std::endl;
                break;
            }
            case '3': {
                std::cout << "\nYou selected option 3..." << std::endl;
                break;
            }
            case 'x': {
                std::cout << "\nLooks like you chose to exit..." << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool sortMenu(char& userChar, std::vector<int>& userSortable) {

    while(userChar != 'x') {
        std::cout << "\n1. Bubble Sort..." << std::endl;
        std::cout << "2. Insertion Sort..." << std::endl;
        std::cout << "3. Selection Sort..." << std::endl;
        std::cout << "4. Merge Sort..." << std::endl;
        std::cout << "5. Quick Sort..." << std::endl;
        std::cout << "Press \'b\' to enter another vector..." << std::endl;
        std::cout << "Press \'x\' to exit the program..." << std::endl;

        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> userChar;

        switch(userChar) {
            case '1': {
                std::cout << "\nYou chose to run Bubble Sort..." << std::endl;
                break;
            }
            case '2': {
                std::cout << "\nYou chose to run Insertion Sort..." << std::endl;
                break;
            }
            case '3': {
                std::cout << "\nYou chose to run Selection Sort..." << std::endl;
                break;
            }
            case '4': {
                std::cout << "\nYou chose to run Merge Sort..." << std::endl;
                break;
            }
            case '5': {
                std::cout << "\nYou chose to run Quick Sort..." << std::endl;
                break;
            }
            case 'b': {
                std::cout << "\nLooks like you chose to enter another vector, heading back..." << std::endl;
                userSortable.clear();
                return true;
            }
            case 'x': {
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
    std::cout << "\n######################################################################################" << std::endl;
    std::cout << "Welcome to my sorting algorithm practice code." << std::endl;
    std::cout << "######################################################################################\n" << std::endl;

    std::cout << "To get started, let's generate a vector to work with. Please choose one of the following options: " << std::endl;
    

    while(progress) {
        // Initial menu
        progress = buildMenu(userChar, userSortable);
        if(!userSortable.empty()) {
            progress = sortMenu(userChar, userSortable);
        }
    }

    std::cout << "Thank you, bye!\n" << std::endl;
  

}