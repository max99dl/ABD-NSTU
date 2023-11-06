#include<iostream>
#include<string>

#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define PORT    54000
#define ADDRESS "127.0.0.1"
#define BUFFER  4096


int main() {
	int client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(client_sock == -1) {
		std::cerr << "Can't create a socket" << std::endl;
		return EXIT_FAILURE;
	}
	
	//_in(internet version)
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(PORT);
	inet_pton(AF_INET, ADDRESS, &hint.sin_addr);

	//connecting to the server on the socket
	int connect_result = connect(client_sock, reinterpret_cast<sockaddr*>(&hint), sizeof(hint));
	if(connect_result == -1) {
		std::cerr << "Can't connect to the server" << std::endl;
		return EXIT_FAILURE;
	}

	char buf[BUFFER];
	std::string user_input;
	while(true) {
		//enter a message
		std::cout << "CLIENT> ";
		std::getline(std::cin, user_input);
	
		//send to the server
		int send_result = send(client_sock, user_input.c_str(), user_input.size() + 1, 0);
		if(send_result == -1) {
			std::cout << "Could not send to the server. Try again\r\n";
			continue;
		}

		//clear buffer and fiil with received information from server
		memset(buf, 0, BUFFER);
		int bytesReceived = recv(client_sock, buf, BUFFER, 0);
		if(bytesReceived == -1) {
			std::cout << "There was an error getting response from server\r\n";
		} else {
			std::cout << "SERVER> " << std::string(buf, bytesReceived) << "\r\n";
		}
	}
	
	//close the client socket
	close(client_sock);

	return 0;
}
