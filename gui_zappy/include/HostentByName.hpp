/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Hostent
*/

#ifndef HOSTENT_HPP_
#define HOSTENT_HPP_
    #include <string>
    #include <netdb.h>

class HostentByName {
    public:
        HostentByName(std::string ip) {
            this->_info = gethostbyname(ip.data());
            if (_info == NULL)
                throw std::exception(); //TODO(zach): finish doing error handling
        };
        ~HostentByName() {
            free(_info);
        };
        hostent &gethostent(void) {
            return *_info;
        }

    protected:
    private:
        struct hostent *_info;
        
};

#endif /* !HOSTENT_HPP_ */
