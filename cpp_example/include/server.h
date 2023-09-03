#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>
#include <thread>

class Server
{
public:
    Server(const std::string &host, const uint16_t port);
    ~Server();

private:
    void run_server();
    void handle_client(int client_fd);

private:
    const uint16_t m_port;
    const std::string m_host;

    int m_fd;
    std::thread m_server_thread;
};

#endif // __SERVER_H__
