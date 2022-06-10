#include <cstdio>
#include <memory>
#include <string>
#include <utility>
class Foo {
  int x;

  Foo(int a, int b, int c) { x = a; }
  Foo(std::string) { x = 0; }
  Foo() = default;

public:
  template <class... Args>
  [[nodiscard]] static std::shared_ptr<Foo> create(Args &&...args) {
    class EnableMakeShared : public Foo {
    public:
      EnableMakeShared(Args &&...args) : Foo(std::forward<Args>(args)...) {}
    };
    return std::make_shared<EnableMakeShared>(std::forward<Args>(args)...);
  }
};
int main() {
  auto foo = Foo::create(1, 2, 3);
  printf("Success\n");
}