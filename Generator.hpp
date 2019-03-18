#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <random>


class Generator {
    private:
        boost::mutex m_mutex;
        boost::shared_ptr< boost::asio::io_service > io_service;
	    boost::shared_ptr< boost::asio::io_service::work > work;
        std::random_device rd;
    public:
        Generator();
        ~Generator();
        int generateNumber();
        void run();
};

#endif //GENERATOR_HPP