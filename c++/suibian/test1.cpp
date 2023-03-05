#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>
int ptr = 0;
std::mutex a;
std::condition_variable b;
void func1() {
    for (int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> A(a);
        b.wait(A, [] { return ptr % 3 == 0; });
        ptr++;
        printf("a ");
        b.notify_all();
    }
}
void func2() {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> B(a);
        b.wait(B, [] { return ptr % 3 == 1; });
        ptr++;
        printf("b ");
        cnt++;
        b.notify_all();
    }
}
void func3() {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> C(a);
        b.wait(C, [] { return ptr % 3 == 2; });
        ptr++;
        printf("c ");
        b.notify_all();
    }
}
int main() {
    std::thread a1(func1);
    std::thread a2(func2);
    std::thread a3(func3);
    a1.join();
    a2.join();
    a3.join();
    return 0;
}