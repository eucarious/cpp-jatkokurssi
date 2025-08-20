// Parallel STL (Sorting & Counting)

#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include <algorithm>

void generate_numbers(std::vector<int> &target_vector, int amount_to_generate) 
{ 
    while (amount_to_generate > 0)
    {
        target_vector.push_back(std::rand()%50);
        amount_to_generate--;
    }
}

bool is_even(int number) 
{
    if (number % 2 == 0) 
        return true;
    return false;
}

int main () 
{ 
    std::srand(std::time(0));
    std::vector<int> veccy;
    generate_numbers(veccy, 50);

    int veccy_size = veccy.size();
    for (int i = 0; i < veccy_size; i++)
        std::cout << veccy.at(i) << ", ";
    std::cout << std::endl;

    int evens = std::count_if(veccy.begin(), veccy.end(), is_even);
    std::sort(veccy.begin(), veccy.end());

    std::cout << std::endl;
    for (int i = 0; i < veccy_size; i++)
        std::cout << veccy.at(i) << ", ";
    std::cout << std::endl;
    std::cout << "even numbers: " << evens;
        
    return 0; 
}