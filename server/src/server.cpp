#include<iostream>
#include<string>
#include<string.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT    54000
#define ADDRESS "0.0.0.0"
#define BUFFER  4096


int main() {
	int listening = socket(AF_INET, SOCK_STREAM, 0);
	if(listening == -1) {
		std::cerr << "Can't create a socket" << std::endl;
		return EXIT_FAILURE;
	}

	//bind the socket to a IP / port
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	//we can't just write a number, because proccesor store data in little-endian format
	//so we need to use htons(host_to_network_short) function. Also there is a function ntohs(network_to_host_short)
	hint.sin_port = htons(PORT);
	//pton(pointer_to_number), there will be four numbers(IPV4) from string "0.0.0.0", use "0.0.0.0" when you want to bind any valid address
	//the last argument is the buffer where you gonna store ip address pointer
	inet_pton(AF_INET, ADDRESS, &hint.sin_addr);

	if( bind(listening, reinterpret_cast<sockaddr*>(&hint), sizeof(hint)) == -1) {
		std::cerr << "Can't bind to IP/port" << std::endl;
		return EXIT_FAILURE;
	}

	//mark the socket for listening, where the second argument is the number of accept connections
	//SOMAXCONN meaning the maximum count of connections(128)
	if( listen(listening, SOMAXCONN) == -1) {
		std::cerr << "Can't listen" << std::endl;
		return EXIT_FAILURE;
	}

	//Accept a call
	sockaddr_in client;
	socklen_t client_size = sizeof(client);
	//names of the host and server
	char host[NI_MAXHOST];
	char srv[NI_MAXSERV];

	int clientSocket = accept(listening,
														reinterpret_cast<sockaddr*>(&client),
														&client_size);
	if(clientSocket == -1) {
		std::cerr << "Problem with client connection" << std::endl;
		return EXIT_FAILURE;
	}

	//stop socket to listen
	close(listening);
	
	//fill host buffer and srv by 0
	memset(host, 0, NI_MAXHOST);
	memset(srv, 0, NI_MAXSERV);

	int result = getnameinfo(reinterpret_cast<sockaddr*>(&client),
													 sizeof(client),
													 host, NI_MAXHOST,
													 srv, NI_MAXSERV, 0);
	if(result) {
		std::cout << host << " connected on " << srv << std::endl;
	} else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on " << ntohs(client.sin_port)
							<< std::endl;
	}

	//while receiving display message, echo message
	char buf[BUFFER];
	for(;;) {
		//clear the buffer
		memset(buf, 0, BUFFER);
		//wait for a message
		int bytesRecv = recv(clientSocket, buf, BUFFER, 0);
		if(bytesRecv == -1) {
			std::cerr << "there was a connection issue" << std::endl;
			break;
		}
		if(bytesRecv == 0) {
			std::cout << "the client disconnected" << std::endl;
			break;
		}
		
		//display message
		std::cout << "Received: " << std::string(buf, 0, bytesRecv) << std::endl;
		//resend message
		send(clientSocket, buf, bytesRecv + 1, 0);
	}

	//close socket
	close(clientSocket);

	return 0;
}
