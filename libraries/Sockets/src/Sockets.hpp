#pragma once

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h> //for sockaddr struct
#include<iostream>

namespace Socket {

class Simple {
public:
	Simple(int domain, int service, int protocol,
							 int port, u_long interface);
	virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
	void test_connection(int item_to_test);
	struct sockaddr_in get_address();
	int get_socket();
	int get_connection();
protected:
	struct sockaddr_in address;
	int sock;
	int connection;	
};


class Binding : public Simple {
public:
	Binding(int domain, int service, int protocol,
								int port, u_long interface);
	int connect_to_network(int sock, struct sockaddr_in address) override;

};


class Connecting : public Simple {
public:
	Connecting(int domain, int service, int protocol,
									 int port, u_long interface);
	int connect_to_network(int sock, struct sockaddr_in address) override;

};


class Listening : public Binding {
public:
	Listening(int domain, int service,
									int protocol, int port,
									u_long interface, int bklg);
	void start_listening();
private:
	int backlog;
	int listening;

};

}
