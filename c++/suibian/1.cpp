#include <iostream>
#include <future>
#include <memory>
#include <thread>
#include <memory.h>

int fun(int x, std::promise<int>& p) {
	x++;
	x *= 10;
	p.set_value(x);
	std::cout << std::this_thread::get_id() << std::endl;
	return x;
}
class A{
public:
	A();
	virtual ~A()=0;
	virtual int mat(int t)=0;

};
class B : public A{
public:
	B();
	virtual ~B()=0;
private:
	std::shared_ptr<>
};

int main()
{
	std::promise<int> p;
	std::future<int> fu = p.get_future();        // 并将结果返回给future
	std::thread t(fun, 1, std::ref(p));
	std::cout << fu.get() << std::endl;          // 当promise还没有值的时候在此等待
	std::cout << std::this_thread::get_id() << std::endl;
	t.join();
	return 0;
}