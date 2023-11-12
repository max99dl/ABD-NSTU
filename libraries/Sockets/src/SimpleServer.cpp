#include "SimpleServer.h"


SimpleServer::SimpleServer(int domain, int service,
													 int protocol, int port,
													 u_long interface, int bklg)
{
	sock = std::make_unique<ListeningSocket>(
			domain, service, protocol,
			port, interface, bklg);
}
