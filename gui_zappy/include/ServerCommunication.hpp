/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ServerCommunication
*/

#ifndef SERVERCOMMUNICATION_HPP_
    #define SERVERCOMMUNICATION_HPP_
    #include "HostentByName.hpp"
    #include <SFML/Network.hpp>
    #include <list>
class ServerCommunication {
    public:
        ServerCommunication();
        ~ServerCommunication();
        void setPort(std::string port);
        void setHost(std::string host);
        // read the data sent by the server using sfml socket.
        int readFromServer();
        // write the data inside the string msg on the socket so the server can read it using sfml sockets.
        int writeToServer(std::string msg);
        // As the name suggest when you call this function it will connect to the server with the port and host set in the constructor
        void connectToServer();
        // It gives you the first command reiceved from the server and it will pop it from the vector. The function will return an empty string if there is no more command.
        std::string popCmd();
    protected:
    private:
        sf::TcpSocket _clientSocket;
        sf::Socket::Status status;
        std::string _port;
        std::string _host;
        std::list<std::string> _cmdList;
        sf::SocketSelector _selector;
};

#endif /* !SERVERCOMMUNICATION_HPP_ */
