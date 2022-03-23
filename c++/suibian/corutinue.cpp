#include <coroutine> 
#include <iostream>
#include <stdexcept>
#include <thread>
 
auto switch_to_new_thread(std::jthread& out) {
  struct awaitable {
    std::jthread* p_out;
    bool await_ready() { return false; }
    void await_suspend(std::coroutine_handle<> h) {
      std::jthread& out = *p_out;
      if (out.joinable())
        throw std::runtime_error("jthread 输出参数非空");
      out = std::jthread([h] { h.resume(); });
      // 潜在的未定义行为：访问潜在被销毁的 *this
      // std::cout << "新线程 ID：" << p_out->get_id() << "\n";
      std::cout << "新线程 ID：" << out.get_id() << "\n"; // 这样可以
    }
    void await_resume() {}
  };
  return awaitable{&out};
}
 
struct task {
    struct promise_type {
        task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};
 
task resuming_on_new_thread(std::jthread& out) {
  std::cout << "协程开始，线程 ID：" << std::this_thread::get_id() << "\n";
  co_await switch_to_new_thread(out);
  // 等待器在此销毁
  std::cout << "协程恢复，线程 ID：" << std::this_thread::get_id() << "\n";
}
 
int main() {
  std::jthread out;
  resuming_on_new_thread(out);
}