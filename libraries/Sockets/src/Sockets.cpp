#include "Sockets.hpp"

namespace Socket {


Simple::Simple(int domain, int service, int protocol,
													 int port, u_long interface) {
	//Define address structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);
	//Establish socket
	sock = socket(domain, service, protocol);
	test_connection(sock);
} 

void Simple::test_connection(int item_to_test) {
	if(item_to_test < 0) {
		perror("Failed_to_connect..");
		exit(EXIT_FAILURE);
	}
}

struct sockaddr_in Simple::get_address() {
	return address;
}

int Simple::get_socket() {
	return sock;
}

int Simple::get_connection() {
	return connection;
}



Binding::Binding(int domain, int service, int protocol,
														 int port, u_long interface)
		: Simple(domain, service, protocol, port, interface)
{
	//Establish network connection
	connection = connect_to_network(sock, address);
	test_connection(connection);
}

int Binding::connect_to_network(int sock,
																			struct sockaddr_in interface)
{
	return bind(sock, reinterpret_cast<sockaddr*>(&interface),
							sizeof(interface));
}



Connecting::Connecting(int domain, int service, int protocol,
																	 int port, u_long interface)
		: Simple(domain, service, protocol, port, interface)
{
	connection = connect_to_network(sock, address);
	test_connection(connection);
}

int Connecting::connect_to_network(int sock,
																				 struct sockaddr_in address)
{
	return connect(sock, reinterpret_cast<sockaddr*>(&address), sizeof(address));
}



Listening::Listening(int domain, int service,
																 int protocol, int port,
																 u_long interface, int bklg)
		: Binding(domain, service, protocol, port, interface)
{
	backlog = bklg;
	start_listening();
	test_connection(listening);
}

void Listening::start_listening() {
	listening = listen(sock, backlog);
}


}
