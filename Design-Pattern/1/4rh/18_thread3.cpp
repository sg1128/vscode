#include <iostream>
#include <thread>

void foo()
{
    std::cout << "foo" << std::endl;
}

// int main()
// {
//     std::cout << "main thread" << std::endl;
//     std::thread t1(&foo);

//     t1.join();
// }

void thread_routine(const char *name)
{
    std::cout << name << std::endl;
}

int main()
{
    std::thread t1(&thread_routine, "A");
    std::thread t2(&thread_routine, "B");

    t1.join();
    t2.join();
}