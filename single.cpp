#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
class single{
public :
    ~single() {}
    static std::shared_ptr<single>getInstance() {
        std::lock_guard<std::mutex>lk(mute) ;
        if(ptr == nullptr) {
                ptr = std::make_shared<single>() ;
        }
        return ptr ;
    }
private:
    static std::mutex mute ;
    single() {}
    static std::shared_ptr<single>ptr ;
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

