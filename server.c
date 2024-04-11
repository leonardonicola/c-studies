#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT         4000
#define MAX_MSG_SIZE 1024

int main(int argc, char * argv[]) {
  int server_fd, new_socket;

  // Socket IPV4
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char * http_msg_with_headers =
      "HTTP/1.1 200 OK\n Content-Type: text/plain\n Content-Length: 13\n\n "
      "Hello World!";

  // Criar socket com dominio IPV4, do tipo stream e protocolo
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Erro ao criar socket");
    exit(EXIT_FAILURE);
  }

  // Dominio IPV4
  address.sin_family = AF_INET;
  // Accept localhost connections
  address.sin_addr.s_addr = INADDR_ANY;

  // Converter de número inteiro para network byte
  address.sin_port = htons(PORT);

  // Vincula socket ao endereço do servidor
  if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0) {
    perror("Erro ao vincular socket");
    exit(EXIT_FAILURE);
  }

  // Escutar por conexões
  if (listen(server_fd, 3) < 0) {
    perror("Erro ao escutar conexões");
    exit(EXIT_FAILURE);
  }

  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t *)&addrlen)) < 0) {
    perror("Erro ao aceitar conexão");
    exit(EXIT_FAILURE);
  }

  // Envia hello world
  send(new_socket, http_msg_with_headers, strlen(http_msg_with_headers), 0);

  // Fecha conexão
  close(new_socket);
  return 0;
}