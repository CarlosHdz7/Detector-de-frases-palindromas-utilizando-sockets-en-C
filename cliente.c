#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>


int main(int argc,char *argv[])
{
   struct sockaddr_in dir_client;
   int  fd;
   int flag;
   char buffer[20];
   
   dir_client.sin_family=AF_INET;
   dir_client.sin_addr.s_addr=inet_addr("127.0.0.1");
   dir_client.sin_port=3000;

   if((fd= socket(AF_INET,SOCK_STREAM,0)) == -1)
     perror("Cliente: no se puede abrir socket");
   
   if(connect(fd,(struct sockaddr *)&dir_client,sizeof(dir_client)) < 0)
     perror("Cliente: error funcion connect");

   for(;;)
    {
        printf("Ingrese un frase: ");
        scanf("%[^\n]",buffer);
        send(fd,buffer,sizeof(buffer),0);
        //Esperando recibir respuesta del server....
        recv(fd,&flag,sizeof(int),0);
        if(flag==1)
        {
           printf("Servidor: si es palindromo\n");
           break;
        }
        else
        {
           printf("Servidor:No es palindromo.\n");
           break;
        }
     }
    close(fd);
   return 0;
}
