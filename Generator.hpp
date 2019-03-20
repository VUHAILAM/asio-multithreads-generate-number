#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#define ASIO_STANDALONE
#define _WIN32_WINNT 0x0500

#include <asio.hpp>
#include <thread>
#include <mutex>
#include <random>


class Generator {
    private:
        std::mutex m_mutex;
        std::shared_ptr< asio::io_service > io_service;
	    std::shared_ptr< asio::io_service::work > work;
        std::random_device rd;
    public:
        Generator();
        ~Generator();
        void io_run();
        int generateNumber();
        void run();
};

#endif //GENERATOR_HPP