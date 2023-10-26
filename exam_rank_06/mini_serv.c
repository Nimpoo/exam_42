#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENT 128
#define BUFFER_SIZE 200000

int main( int argc, char **argv ) {

	if (argc != 2) {
		write(2, "Usage: a.out <port>\n", 20);
		exit(1);
	}

	int		clientSockets[MAX_CLIENT];
	int		next_id = 0;

	fd_set	activeSockets, readySockets;
	char	buffer[BUFFER_SIZE];
	int		serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (serverSocket < 0) {
		write(2, "Error creating server socket\n", 29);
		exit(1);
	}

	struct sockaddr_in serverAddress = { 0 };
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = htons(atoi(argv[1]));

	if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
		write(2, "Error binding server socket\n", 28);
		exit(1);
	}

	if (listen(serverSocket, MAX_CLIENT) < 0) {
		write(2, "Error listening server socket\n", 30);
		exit(1);
	}

	FD_ZERO(&activeSockets);
	FD_SET(serverSocket, &activeSockets);
	int	maxSocket = serverSocket;

	while (1)
	{

		readySockets = activeSockets;
		if (select(maxSocket + 1, &readySockets, NULL, NULL, NULL) < 0) {
			write(2, "Error in select\n", 16);
			exit(1);
		}

		for (int socketID = 0; socketID <= maxSocket; socketID++) {
			if (FD_ISSET(socketID, &readySockets)){
				if (socketID == serverSocket) {
					int clientSocket = accept(serverSocket, NULL, NULL);
					if (clientSocket < 0) {
						write(2, "Error accepting client connection\n", 34);
						exit(1);
					}

					FD_SET(clientSocket, &activeSockets);
					maxSocket = (clientSocket > maxSocket) ? clientSocket : maxSocket;
					sprintf(buffer, "server: client %d just arrived\n", next_id);
					send(clientSocket, buffer, strlen(buffer), 0);
					clientSockets[next_id++] = clientSocket;
				} else {
					int byte_read = recv(socketID, buffer, sizeof(buffer) - 1, 0);

					if (byte_read <= 0) {
						sprintf(buffer, "server: client %d just left\n", socketID);

						for (int i = 0; i < next_id; i++) {
							if (clientSockets[i] != socketID) {
								send(clientSockets[i], buffer, strlen(buffer), 0);
							}
						}
						close(socketID);
						FD_CLR(socketID, &activeSockets);
					} else {
						buffer[byte_read] = '\0';
						sprintf(buffer, "client %d: %s\n", socketID, buffer);
						for (int i = 0; i < next_id; i++) {
							if (clientSockets[i] != socketID) {
								send(clientSockets[i], buffer, strlen(buffer), 0);
							}
						}
					}
				}
			}
		}

	}
	return (0);
}
