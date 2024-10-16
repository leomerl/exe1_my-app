#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

void handle_client(int client_socket) {
    char buffer[1024] = {0};
    
    // Read the client's request (we're not actually using it in this simple example)
    read(client_socket, buffer, 1024);

    // Respond with a basic HTTP message
    char *hello_response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 13\n\nHello, World!";
    write(client_socket, hello_response, strlen(hello_response));
    
    // Close the connection with the client
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // Listen on all network interfaces
    address.sin_port = htons(PORT);        // Bind to the specified port

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Main loop to handle incoming connections
    while (1) {
        // Accept an incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Handle the client's request in a separate function
        handle_client(client_socket);
    }

    return 0;
}

