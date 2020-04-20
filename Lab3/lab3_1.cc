#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

void server(void )
{
  int rcvid;         //Ykazivaet komy nado otvechat
  int chid;          //Identifikator kanala
  char message[512]; // 
  
  printf("Server start working \n");
 
 chid=ChannelCreate(0);         //Sozdanie Kanala
 printf("Chanel id: %d \n", chid);
 printf("Pid: %d \n", getpid());
 // vipolniaetsa vechno- dlia servera eto normalno
 while(1) 
    {
    // Polychit i vivesti soobshenie

    rcvid=MsgReceive(chid,message,sizeof(message), NULL);
    printf("Polychili soobshenie, rcvid  %X \n",rcvid  );
    printf("Soobshenie takoe : \"%s\". \n", message  );
    
    // Podgotovit otvet 
    
    strcpy(message,"Eto otvet");
    
    MsgReply(rcvid, EOK, message, sizeof(message)) ;
    printf("\"%s\". \n", message  );
    }  
}

int main(void)
{
printf("Prog server  \n");
server();
sleep(5);
return(1);
}