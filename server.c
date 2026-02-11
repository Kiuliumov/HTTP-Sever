#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "request.h"

#define PORT 8080
#define BUFFER_SIZE 4096

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);

    printf("Server running at http://localhost:%d\n", PORT);

    while (1)
    {
        client_fd = accept(server_fd,
                           (struct sockaddr *)&address,
                           (socklen_t *)&addrlen);

        memset(buffer, 0, BUFFER_SIZE);
        read(client_fd, buffer, BUFFER_SIZE);

        HttpRequest req;

        if (parse_http_request(buffer, &req) == 0)
        {
            printf("Method: %s\n", method_to_string(req.method));
            printf("Path: %s\n", req.path);
            printf("Version: %s\n", req.version);
        }
        else
        {
            printf("Failed to parse request\n");
        }

        const char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Connection: close\r\n"
            "\r\n"
            "Hello from structured C HTTP server!\n";

        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
