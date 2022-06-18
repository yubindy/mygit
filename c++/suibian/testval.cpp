#include <cstdio>
#include <memory>
#include <thread>
#include <utility>
class Test {
    int a;
    int b;

public:
    Test() = default;
    template <class... Args>
    std::shared_ptr<Test> create(Args &&...args) {
        class EnableMakeShared : public Test {
            EnableMakeShared(Args &&...arg) :
                Test(std::forward<Args>(arg)...) {
            }
        };
        return std::make_shared<EnableMakeShared>(std::forward<Args>(args)...);
    }
    Test(Test &&) {
        printf("Move\n");
    }
};
void ThreadMain(std::shared_ptr<Test> x) {
    //
    printf("Nothing");
}
int main() {
    auto t = std::make_shared<Test>();
    ThreadMain(std::move(t));
    // auto t1 = std::thread(ThreadMain,t);
    // t1.detach();
}