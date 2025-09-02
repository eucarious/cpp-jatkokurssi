// Log_Ptr
// Lord have mercy

#include <iostream>
#include <thread>
#include <memory>
#include <iostream>
#include <fstream>
#include <ctime>


class Guy
{ 
    public:

    int age = 0;

    Guy( ) 
    { 
        std::cout << "I live!!" << std::endl;
    }
    Guy( int a ) 
    { 
        std::cout << "I live!!" << std::endl;
        age = a;
    }

    ~Guy() 
    { 
        std::cout << "NOOOOOOOOOOOO!!" << std::endl;
    }
    
};


template <typename T> struct Log_Ptr 
{
    T* pointah[5];
    T pointee;
    int count = 0;

    Log_Ptr(T the_president) {
        pointee = the_president;
        pointah[0] = &pointee;
        // kill the president
        the_president.~T();
        count = 1;
        std::cout << std::time(0) << " ownership transferred " << &pointah << std::endl; 
    }

    Log_Ptr(Log_Ptr &the_log) {
        count = the_log.count;
        std::copy(the_log.pointah, the_log.pointah+the_log.count, pointah);
        pointee = the_log.pointee;
        std::cout << std::time(0) << " whole log struct copied " << &pointah << std::endl; 
    };

    Log_Ptr operator=(const Log_Ptr&) {
        if (count == 5)
            return;
        pointah[count] = Log_Ptr->pointah[0];
        count++;
        std::cout << std::time(0) << " pointer assigned " << &pointah << std::endl; 
        return pointah[0];
    };


    ~Log_Ptr() {
        std::cout << std::time(0) << " pointer destroyed " << &pointah << std::endl; 
        count--;
        if (count <= 0) {
            pointee.~T();
            std::cout << std::time(0) << " object destroyed " << &pointah << std::endl; 
        }
    }

    T* operator->() const {
        std::cout << std::time(0) << " operator-> " << &pointah << std::endl; 
        return pointah[0];
    }

    T operator*() const {
         std::cout << std::time(0) << " operator* " << &pointah << std::endl; 
        return pointee;
     } // couldnt figure this one out. or at least not in the way that the Pointee
    // console print for now
};


void yo_how_old_this_guy(std::shared_ptr<Guy> old_man) 
{
    std::cout << "i am a whole " << old_man->age << " years old!" << std::endl;
}

void yo_how_old_this_guy(int age) 
{
    std::cout << "i am a whole " << age << " years old!" << std::endl;
}

std::shared_ptr<Guy> create_a_man(int how_old)
{
    std::shared_ptr<Guy> pointy(new Guy(how_old));
    return pointy;
}

int main () 
{ 

    // std::shared_ptr<Guy> sp1(new Guy(5));
    // yo_how_old_this_guy(sp1);
    // // print should be 
    // // I live!!
    // // 5
    // // I live!!
    // // NOOOOOO!!!
    // // after this line (below) runs
    // sp1 = create_a_man(91);
    
    Log_Ptr<Guy> someguy = *new Guy(50);
    // yo_how_old_this_guy(someguy->pointah);
    Log_Ptr<Guy> thatguy(someguy); 
    Log_Ptr<Guy> yes_thatguy = thatguy;

    std::cout << "I think I'm in hell. " << std::endl << "I've been here for " << someguy->age << " years" << std::endl ;
    std::cout << "I think I'm in hell. " << std::endl << "I've been here for " << thatguy.operator*().age << " years" << std::endl ;

    thatguy.~Log_Ptr();
    return 0; 
} // oops! all memory leaks!. 
// anyways. yeah this isnt behaving like i expected it to.
// ,mmmmmmmwhateva. next. 
// i gotta get to the demo work :,) conway save me (he won't)