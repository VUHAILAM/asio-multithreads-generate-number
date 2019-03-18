#include "Generator.hpp"

#include <iostream>

Generator::Generator() {
    this->io_service = boost::shared_ptr< boost::asio::io_service >(
		new boost::asio::io_service
	);
    this->work = boost::shared_ptr< boost::asio::io_service::work >(
		new boost::asio::io_service::work( *io_service )
	);
}

Generator::~Generator() {

}

int Generator::generateNumber() {
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> num(1, 100);
    int number = num(gen);
    boost::this_thread::sleep( boost::posix_time::milliseconds(1000) );
    return number;
}

void Generator::run() {
    boost::thread_group threads;
    for(int i = 1; i <= 5; i++) {
        threads.create_thread([&]() {
            io_service->run();
        });
    }
    for(int i = 0; i < 100; i++) {
        io_service->post([&]() {
            m_mutex.lock();
            std::cout << "Thread " << boost::this_thread::get_id() << ": " << this->generateNumber() << std::endl;
            m_mutex.unlock();
        });
    }

    work.reset();

	threads.join_all();

}