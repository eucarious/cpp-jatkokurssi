// Monte Carlo π Estimation

#include <iostream>
#include <thread>
#include <ctime>
#include <cmath>

int main () 
{ 
    std::srand(std::time(0));
    int hits = 0;
    int max_attempts = 1200000;
    for (int i = 0 ; i < max_attempts ; i++) 
    {
        float x = -1 + 2*((float)std::rand()/RAND_MAX);
        float y = -1 + 2*((float)std::rand()/RAND_MAX);
        if (std::sqrt(x*x + y*y) <= 1) 
            hits++;
    }

    std::cout << "Pi is " << ((float)(4 * hits)/(float)max_attempts);

    
    return 0; 
}