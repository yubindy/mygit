#include <atomic>
#include <thread>
#include <assert.h>
#include<iostream>
std::atomic<bool> x, y;
std::atomic<int> z;
void write_x()
{
    x.store(true, std::memory_order_seq_cst);
} // 1
void write_y()
{
    y.store(true, std::memory_order_seq_cst);
} // 2
void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst))
        ;
    if (y.load(std::memory_order_seq_cst)) // 3
        ++z;
}
void read_y_then_x()
{
    while (!y.load(std::memory_order_seq_cst))
        ;
    if (x.load(std::memory_order_seq_cst)) // 4
        ++z;
}
int main()
{
    x = false;
    y = false;
    z = 0;
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);
    a.join();
    b.join();
    c.join();
    d.join();
    assert(z.load() != 0); // 5

}