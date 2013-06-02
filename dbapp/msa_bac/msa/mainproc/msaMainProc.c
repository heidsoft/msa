#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#define extern 
#include <sys/io.h> 

#include "msa.h"

int errno;
/*����ϵͳ��������*/
lt_shmHead   *lt_MMHead;

void die(int e)
{ 
	_exit(e); 
}


/*��ʼ��ϵͳ�������ڴ�ṹ*/	
int ltStartApp(int sysActiveFlag){

	
	char *p;
	int  intMaxShmSize;
	int  intShmKey;
	

  
  /*��ȡ������ڴ���*/
	p=bcCnfGetValueS(_pubconfdir,"kernel", "maxshmsize");
	if(p==NULL){
		fprintf(stderr,"Start applicatin error: maxshmsize is NULL!\n");
		return -1;	
	}
	intMaxShmSize=atol(p);

	/*��ȡϵͳshmKey*/
	p=bcCnfGetValueS(_pubconfdir,"kernel", "shmkey");
	if(p==NULL){
		fprintf(stderr,"Start applicatin error: shmkey is NULL!\n");
		return -1;	
	} 
	intShmKey=atol(p);
	
	lt_MMHead=msacreateShmMem(intShmKey,intMaxShmSize);
  
	if(lt_MMHead){
		_ltPubInfo = (msaPubInfo *)lt_MMHead->ShmMemPtr;
    _ltPubInfo->sysActive=sysActiveFlag;
		return 0;
	}
	return -1;

}

	
void catch_hup(int signum)
{
	printf("system receive hup signal.\n");
	_ltPubInfo->lRunning=0;
	    
  /*�����Լ���hup�źŴ������*/
  
  
  _ltPubInfo->lRunning=1;
  printf("mainsystem hup reset ok.\n");
	//exit(0);
}

void catch_int(int signum)
{
	printf("system receive int signal.\n");
	
	
}
void catch_alrm(int signum)
{
  /*ϵͳʱ�Ӵ�����*/
  
  _exit(0);
}






int main(int argc,char **argv){

		int  sysActiveFlag;
		int  iReturn;
		int  iPid;
		char **binqqargs;
	
		/**/
		int msaLocalServerPid;
	
		/*ϵͳ�ź�ʶ��*/
    signal(SIGHUP,catch_hup);
    signal(SIGINT,catch_int);
    signal(SIGCHLD, SIG_IGN);
	  signal(SIGINT,  SIG_IGN);
	  signal(SIGTERM, SIG_IGN);
  	signal(SIGPIPE, SIG_IGN);
    
    /*����ϵͳ����*/
    
    /*ʱ��ͬ��*/
    /*system("/etc/cron.daily/ntpdate &");*/
   
    sysActiveFlag=1; /*ϵͳ���ñ�����*/
 
    if(ltStartApp(sysActiveFlag)<0){
				printf("starting application error!\n");
				return 0;
    }
    
    /*1>��ʼ�������ڴ����*/
    printf("begin init pubinfo ok\n");
    iReturn=msaInitPubInfo(lt_MMHead);
    if(iReturn != 0) {
				printf("Init PubInfo error\n");
				closeShmMem(lt_MMHead);
        return -1;
    } 
    printf("Start init pubinfo ok\n");
    

    
   msaInitPubVar(lt_MMHead);
   
	  /*������ʱ�ļ��������*/
		printf("starting local server proccess...\n");
	  iPid=fork();
	  if(iPid==0){
			 chdir("/app/msa/bin");
			 binqqargs = (char **) malloc(2 * sizeof(char *));
			 binqqargs[0]= "msaLocalServer";
			 binqqargs[1]= 0;
			 execv(*binqqargs,binqqargs);
			 die(0);
	  }
	  if (iPid>0){
				msaLocalServerPid=iPid;
	  }

	 
	  
   /*���ݱ��ݵ�������*/
   printf("system start success\n");
   while(1){
			sleep(30);
   }
   return 0;

}



