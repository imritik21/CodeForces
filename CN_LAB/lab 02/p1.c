#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1050
#define IP_ADDRESS "127.0.0.1"

int main() {
    printf("This is server!!\n");

    int sockfd;
    struct sockaddr_in my_addr;
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Initialize server address structure
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP_ADDRESS, &my_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return 1;
    }
    
    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }
    
    printf("Bind successful\n");
    
    // In a real server, you would typically have a loop here to handle client requests
    // For example:
    // while (1) {
    //     // Receive and process client requests
    // }
    
    // Close the socket
    close(sockfd);
    
    return 0;
}