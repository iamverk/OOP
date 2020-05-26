#include <iostream>
#include <iostream>
#include <memory>
#include <vector>
#include "factory.h"
#include "pentagon.h"
#include "rhombus.h"
#include "hexagon.h"
#include "subscriber.h"

int main(int argc,char* argv[]) {
    if (argc != 2) {
        std::cout << " Usage:\n" << argv[0] << " not enough arguments\n";
        return 1;
}
    const int32_t buffer_size = std::stoi(argv[1]);
    std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer =
            std::make_shared<std::vector<std::shared_ptr<figure>>>();
    buffer->reserve(buffer_size);
    factory factory;
    std::string command;
    std::cout << "add - add a new figure\n" << "exit - the end of the program\n";
    //thread
    subscriber sub;
    sub.processors.push_back(std::make_shared<stream_processor>());
    sub.processors.push_back(std::make_shared<file_processor>());
    std::thread sub_thread(std::ref(sub));

    while (true) {
        std::unique_lock<std::mutex> guard(sub.mtx);
        std::cout << "begin\n";
        std::cin >> command;
        if (command == "add") {
            try {
                buffer->push_back(factory.FigureCreate(std::cin));
            } catch (std::logic_error &e) {
                std::cout << e.what() << '\n';
                continue;
            }
            if (buffer->size() == buffer_size) {
                sub.buffer = buffer;
                sub.cv.notify_all();
                sub.cv.wait(guard, [&](){ return sub.buffer == nullptr;});
                buffer->clear();
            }
        } else if (command == "exit")  {

            break;
        } else {
            std::cout << "unknown command\n";
        }
    }
    sub.end = true;
    sub.cv.notify_all();
    sub_thread.join();


    return 0;
}