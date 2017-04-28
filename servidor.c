#include <sys/socket.h>
#include <string.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <math.h>
#include <stdio.h>
#include <sys/types.h>


int main(int argc,char *argv[])
{
  struct sockaddr_in dir_client,dir_server;
  int  fd,n,sock;
  int flag;
  char pal[30];
  char pal2[30];
  char b = ' '; 
  int j=0;
  int e=0;
  int p=0;
  int a=0;
  int x;

  dir_server.sin_family=AF_INET;
  dir_server.sin_addr.s_addr=inet_addr("127.0.0.1");
  dir_server.sin_port=3000;
  
  if((fd =socket(AF_INET,SOCK_STREAM,0)) == -1)
     perror("Cliente: no se puede abrir socket");

  if(bind(fd,(struct sockaddr *)&dir_server,sizeof(dir_server)) < 0)
     perror("Servidor: no se puede asociar la dir local");

  listen(fd,5);
 
   n = sizeof dir_client;
   sock=accept(fd,(struct sockaddr *)&dir_client,&n);

   for(;;)
   {
      recv(sock,pal,sizeof(pal),0);
      printf("Servidor: Cadena recibida:%s\n",pal);
       
        int n = strlen(pal);      
        for(int i =0; i <= n;i++){
        
           if(pal[i] == b)
              i++;
              pal2[e]=pal[i];
              e++;
        }               
         x=0;
         n=strlen(pal2);
         for(x=n-1;x>=0;x--){
            if(pal2[x]==pal2[a])
         p++;
         a++;
       }
       if(p==n){
           flag=1; //"Es palindromo"
       }
       else{
           flag=0; //"No es palindromo"
       }
        
     send(sock,&flag,sizeof(int),0);
     break;
   } 
  close(sock);
  close(fd);
return 0;
}
