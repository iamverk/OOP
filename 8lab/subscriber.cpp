#include "subscriber.h"

void subscriber::operator()() {
    while(true) {
        std::unique_lock<std::mutex> lock(mtx);
        //std::cout << "thread lock\n";
        cv.wait(lock,[&]{ return (buffer != nullptr || end);});
        //std::cout << "thread unlock\n";
        if (end) {
            break;
        }
        for (const auto& processor_elem: processors) {
            processor_elem->process(buffer);
        }
        buffer = nullptr;
        cv.notify_all();
    }
}