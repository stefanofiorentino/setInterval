#include <iostream>
#include <future>

template<typename... Args_t> using void_t = void;

void initSetInterval()
{
    std::thread([](){for(;;){
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    };}).join();
}

template<typename F, typename T>
void setInterval(F &&f, T &&t, void_t<decltype(f())> * = nullptr)
{
    std::thread([f = std::move(f), t = std::move(t)]()
                {
                    begin: // wonderful weirdity
                    std::this_thread::sleep_for(t);
                    f();
                    goto begin;
                }).detach();

    static std::once_flag of;
    std::call_once(of, initSetInterval);
}

int main()
{
    setInterval([]()
                {
                    std::cout << "print" << std::endl;
                }, std::chrono::seconds(3));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}