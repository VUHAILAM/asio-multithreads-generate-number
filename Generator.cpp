#include "Generator.hpp"

#include <iostream>
#include <chrono>

Generator::Generator() {
    this->io_service = std::shared_ptr< asio::io_service >(
	new asio::io_service
	);
    this->work = std::shared_ptr< asio::io_service::work >(
	new asio::io_service::work( *io_service )
	);
}

Generator::~Generator() {

}

int Generator::generateNumber() {
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> num(1, 100);
    int number = num(gen);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return number;
}

void Generator::io_run() {
    io_service->run();
}

void Generator::run() {
    std::vector< std::thread > threads;

    for(int i = 1; i <= 5; i++) {
        threads.push_back(std::thread(io_run, this));
    }

    for(int i = 0; i < 100; i++) {
        io_service->post([&]() {
            m_mutex.lock();
            std::cout << "Thread " << std::this_thread::get_id() << ": " << this->generateNumber() << std::endl;
            m_mutex.unlock();
        });
    }

    work.reset();

    for(int i = 0; i < 5; i++) {
       if(threads[i].joinable()) {
          threads[i].join();
       }
    }
}