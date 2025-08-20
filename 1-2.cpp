// Parallel Summation (std::thread)

#include <iostream>
#include <thread>
#include <vector>
#include <ctime>

std::vector<int> debug_list = {1,2,3,4,5,6,7,8,9,10}; // works

void sum(const std::vector<int>& data, int i_start, int i_end, int *total_to_add_to) // incl. - excl.
{
    for (int i = i_start ; i < i_end; i++) 
    {
        *total_to_add_to += data.at(i);
    }
}

void rand_numbers(std::vector<int>& data, int count) 
{
    while (count > 0)
    {
        data.push_back(std::rand()%25);
        count--;
    }
}

int main () 
{ 
    int total = 0;
    std::srand(std::time(0));
    std::vector<int> list;
    rand_numbers(list, 20);

    std::thread t(sum, list, 0, 10, &total);
    std::thread t2(sum, list, 10, 20, &total);

    t.join();
    t2.join();

    std::cout << "the sum of the list is " << total;

    //tba dynamic sizing & future creations
    
    return 0; 
}