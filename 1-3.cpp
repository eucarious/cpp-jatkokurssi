// Parallel Summation with std::async

#include <iostream>
#include <future>
#include <vector>
#include <ctime>

std::vector<int> debug_list = {1,2,3,4,5,6,7,8,9,10}; // works

int sum(const std::vector<int>& data, int i_start, int i_end) // incl. - excl.
{
    int total = 0;
    for (int i = i_start ; i < i_end; i++) 
    {
        total += data.at(i);
    }
    return total;
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
    std::srand(std::time(0));
    std::vector<int> list;
    rand_numbers(list, 20);

    std::future<int> fut = std::async(sum, list, 0, 10);
    std::future<int> fut2 = std::async(sum, list, 10, 20);

    std::cout << "the sum of the list is " << (fut.get() + fut2.get());

    //tba dynamic sizing & future creations
    
    return 0; 
}