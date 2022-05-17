#include "spdlog/spdlog.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <gtest/gtest.h>
#include <iostream>
#include <stdio.h>
using namespace boost::asio;
using namespace boost::asio;
io_service service;
void func(int i) {
    spdlog::error("Some error message with arg: {}", i);
}
void worker_thread() {
    service.run();
}
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    io_service::strand strand_one(service), strand_two(service);
    for (int i = 0; i < 5; ++i)
        service.post(strand_one.wrap(boost::bind(func, i)));
    for (int i = 5; i < 10; ++i)
        service.post(strand_two.wrap(boost::bind(func, i)));
    boost::thread_group threads;
    for (int i = 0; i < 1; ++i)
        threads.create_thread(worker_thread);
    // 等待所有线程被创建完
    boost::this_thread::sleep(boost::posix_time::millisec(500));
    threads.join_all();
    return RUN_ALL_TESTS();
}