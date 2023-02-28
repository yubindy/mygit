#include <bits/stdc++.h>
std::mutex s;
std::condition_variable cv;
void f(int *t) {
    printf("fr");
    // for (int i = 0; i < 10; i++) {
    //     std::lock_guard<std::mutex> p(s);
    //     printf("%d", (*t)++);
    // }
    //cv.notify_one();
}
int main() {
    int t = 0;
    std::thread p(f, &t);
    std::thread pp(f, &t);
    {
        // std::unique_lock<std::mutex> p(s);
        // cv.wait(p);
        sleep(5);
    }
    return 0;
}