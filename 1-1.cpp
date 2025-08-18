// Hello, Threads

#include <iostream>
#include <thread>
#include <chrono>

void rolecall()
{
    std::this_thread::sleep_for(std::chrono::seconds(std::rand()%6));
    std::cout << "ready for duty! " << std::this_thread::get_id() << "\n";
}

int main()
{

    std::thread one(rolecall);
    std::thread two(rolecall);
    std::thread three(rolecall);
    std::thread four(rolecall);

    one.join();
    two.join();
    three.join();
    four.join();

    return 0;
}