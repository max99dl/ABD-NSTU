#pragma once

#include<stdio.h>
#include<memory>
#include "SimpleSocket.hpp"
#include "ListeningSocket.hpp"

class SimpleServer {
public:
	SimpleServer(int domain, int srvice,
							 int protocol, int port,
							 u_long interface, int bklg);
	virtual void launch() = 0;
private:
	std::unique_ptr<ListeningSocket> lis_sock;
	virtual void accepter()   = 0;
	virtual void handler()    = 0;
	virtual void responder()  = 0;
};
