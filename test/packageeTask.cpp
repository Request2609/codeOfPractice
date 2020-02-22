#include <iostream>
#include <future>

int shutdown(int from, int to) {
    for(int i=from;i!=to; i--) {
        std::cout << i << std::endl ;
        std::this_thread::sleep_for(std::chrono::seconds(1)) ;
    }
    std::cout << "finish" << std::endl ;
    return from-to ;
}

//packaged_task 包装一个可调用的对象，并且异步获取一个可调用对象的结果
//package_task内部包含两个最基本的元素，被包装的任务，任务是一个可调用的对象
//共享状态，用于保存任务的返回值，可以通过future对象来达到异步访问共享状态的结果
int main()
{
    std::packaged_task<int(int,int)>task(shutdown) ; 
    std::future<int>ret = task.get_future() ;
    std::thread t1(std::move(task),10, 0) ;

    int value = ret.get() ;
    std::cout << "value:" << value <<std::endl ;
    std::cout << "Hello world" << std::endl;
    t1.join() ;
    return 0;
}

