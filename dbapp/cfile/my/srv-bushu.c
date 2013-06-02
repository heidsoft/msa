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
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <gdfontmb.h>
#include "msa.h"

/*
*�豸����
*��ʼ��ҳ��
*/
int msaEquipment(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
  		int   nownum;
      int   match;
  		int   jjjj;
      char  mynownum[16];
      
     	ltDbHeadPtr dbPtr;
     	dbPtr=lt_dbinit();
	    lt_db_htmlpage(dbPtr,"utf-8");
	    
  		static char inbuf[4096];
  		int   fd;
  		fd=open("/proc/net/dev",O_RDONLY | O_NDELAY); 
		  static stralloc line = {0};
		  buffer ss;
			nownum=0;
		  buffer_init(&ss,read,fd,inbuf,sizeof(inbuf));
		  for (;;){
				if (getln(&ss,&line,&match,'\n') == -1){ break;}
				if (!match && !line.len) { break; }
				for(jjjj=0;jjjj<line.len;jjjj++){
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h'){
						 nownum++;		
				  }
			  }
				for(jjjj=0;jjjj<line.len;jjjj++){
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='0'){
					 		lt_dbput_rootvars(dbPtr,1,"eth0","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='1'){
					 		lt_dbput_rootvars(dbPtr,1,"eth1","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='2'){
					 		lt_dbput_rootvars(dbPtr,1,"eth2","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='3'){
					 		lt_dbput_rootvars(dbPtr,1,"eth3","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='4'){
					 		lt_dbput_rootvars(dbPtr,1,"eth4","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='5'){
					 		lt_dbput_rootvars(dbPtr,1,"eth5","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='6'){
					 		lt_dbput_rootvars(dbPtr,1,"eth6","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='7'){
					 		lt_dbput_rootvars(dbPtr,1,"eth7","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='8'){
					 		lt_dbput_rootvars(dbPtr,1,"eth8","1");
				   }
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h' && line.s[jjjj+3]=='9'){
					 		lt_dbput_rootvars(dbPtr,1,"eth9","1");
				   }
			  }
		  }
	    sprintf(mynownum,"%d",nownum);
	    
			char strBuf[1024];
			
		  char *dbUser;
			char *dbPass;
			char *dbName;
			dbName=_ltPubInfo->_dbname;
			dbUser=_ltPubInfo->_dbuser;
			dbPass=_ltPubInfo->_dbpass;
			G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
			if(G_DbCon==NULL){
						ltMsgPk->msgpktype=1;
						lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html\n","lthtml",LT_TYPE_STRING,"db error!");
						ltMsgFree(ltMsgPk);			
						return 0;
			}
			sprintf(strBuf,"delete from msaVLanArea where vlanid>=%d",nownum);
			ltDbExecSql(G_DbCon,strBuf);
			ltDbClose(G_DbCon);
			
			lt_dbput_rootvars(dbPtr,1,"nownum",mynownum);
	    lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/manager/naslanlist.htm",dbPtr->head,0);
			ltMsgFree(ltMsgPk);
			lt_dbfree(dbPtr);
			return 0;
}

/*
*��ѯ����������Ϣ
*/
int msaVLanListAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
   char strBuf[1024];
   ltDbCursor *tempCursor;
   LT_DBROW tempRow;     
   char caTmpp[512];
   long lRowNum,lStartRec,lSumRec,lCount,lNum;
   int k;
	 char *dbUser;
	 char *dbPass;
	 char *dbName;
	 dbName=_ltPubInfo->_dbname;
	 dbUser=_ltPubInfo->_dbuser;
	 dbPass=_ltPubInfo->_dbpass;
	 G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
	 if(G_DbCon==NULL){
			 ltMsgPk->msgpktype=1;
			 lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html\n","lthtml",LT_TYPE_STRING,"");
		 	 ltMsgFree(ltMsgPk);			
			 return 0;
	 }
   char *mywk;
   mywk=ltMsgGetVar_s(ltMsgPk,"mywk");
   stralloc strTemp;
   lRowNum=20; /*ÿҳ������*/
   lSumRec=0;/*������*/
   lCount=0; 
   lStartRec=0;
   lNum=0; /*��ҳʣ�������*/
   if(ltMsgGetVar_s(ltMsgPk,"limit"))
	 {
     lRowNum=atol(ltMsgGetVar_s(ltMsgPk,"limit"));
   }
   if(ltMsgGetVar_s(ltMsgPk,"start"))
	 {
     lStartRec=atol(ltMsgGetVar_s(ltMsgPk,"start"));
   }
   if(strcmp(mywk,"-1")==0){
   	 sprintf(strBuf,"select count(*) from msaVLanArea");
   }else{
   	 sprintf(strBuf,"select count(*) from msaVLanArea where vlanid='%s'",mywk);
   }   
   tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
   if(tempCursor!=NULL){
	  tempRow= ltDbFetchRow(tempCursor);
	  if(tempRow!=NULL){
		  lCount=atol(tempRow[0]);
	  }
   }
   ltDbCloseCursor(tempCursor);
   strTemp.s=0;
   sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
   stralloc_cats(&strTemp,caTmpp);
   k=0;
   if(strcmp(mywk,"-1")==0){
  	 sprintf(strBuf,"select vlanid,intercept,promisc,switch,netvlan,ipaddress,passaway,apply,mask from msaVLanArea  order by vlanid limit %lu offset %lu",lRowNum,lStartRec);
   }else{
  	 sprintf(strBuf,"select vlanid,intercept,promisc,switch,netvlan,ipaddress,passaway,apply,mask from msaVLanArea where vlanid='%s' limit %lu offset %lu ",mywk,lRowNum,lStartRec);
   }
   tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
   if(tempCursor!=NULL){
     tempRow=ltDbFetchRow(tempCursor);
     while(tempRow!=NULL){                
        if(k==0){
          sprintf(caTmpp,"{\"vlanid\":\"%s\",\"intercept\":\"%s\",\"promisc\":\"%s\",\"switch\":\"%s\",\"netvlan\":\"%s\",\"ipaddress\":\"%s\",\"passaway\":\"%s\",\"mask\":\"%s\",\"apply\":\"%s\"}",tempRow[0],tempRow[1],tempRow[2],tempRow[3],tempRow[4],tempRow[5],tempRow[6],tempRow[8],tempRow[7]);
          stralloc_cats(&strTemp,caTmpp);     
				}else{
			    sprintf(caTmpp,",{\"vlanid\":\"%s\",\"intercept\":\"%s\",\"promisc\":\"%s\",\"switch\":\"%s\",\"netvlan\":\"%s\",\"ipaddress\":\"%s\",\"passaway\":\"%s\",\"mask\":\"%s\",\"apply\":\"%s\"}",tempRow[0],tempRow[1],tempRow[2],tempRow[3],tempRow[4],tempRow[5],tempRow[6],tempRow[8],tempRow[7]);
	        stralloc_cats(&strTemp,caTmpp);     
				}                         
				tempRow= ltDbFetchRow(tempCursor);
				k++;
	    }
     ltDbCloseCursor(tempCursor);
   }
   stralloc_cats(&strTemp,"]}");
   stralloc_0(&strTemp);
   ltMsgPk->msgpktype=1;
   lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,strTemp.s);
   ltMsgFree(ltMsgPk);
   return 0;
}

/*
*����������Ϣ
*/
int msaAddVlanAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){//msaAddVlanAction
	   char *caIntercept;
	   char *caPromisc;
	   char *caSwitch;
	   char *caNetvlan;
	   char *caIpaddress;
	   char *camask;
	   char *caPassaway;
     char sqlBuf[2048];
	   long lCount;
     lCount=0;
	   char *mywk;
     mywk=ltMsgGetVar_s(ltMsgPk,"Mywk");
		 caIntercept=ltMsgGetVar_s(ltMsgPk,"intercept");
	     if(!caIntercept){
	         caIntercept="";
		 }
	    caPromisc=ltMsgGetVar_s(ltMsgPk,"promisc");
	     if(!caPromisc){
	         caPromisc="";
		 }
	    caSwitch=ltMsgGetVar_s(ltMsgPk,"switch0");
	     if(!caSwitch){
	         caSwitch="";
		 }
	    caNetvlan=ltMsgGetVar_s(ltMsgPk,"netvlan");
	     if(!caNetvlan){
	         caNetvlan="";
		 } 
	    caIpaddress=ltMsgGetVar_s(ltMsgPk,"ipaddress");
	     if(!caIpaddress){
	         caIpaddress="";
		 }
	    camask=ltMsgGetVar_s(ltMsgPk,"mask");
	     if(!camask){
	         camask="";
		 } 
	    caPassaway=ltMsgGetVar_s(ltMsgPk,"passaway");
	     if(!caPassaway){
	         caPassaway="";
		 } 
	 
		 char *dbUser;
		 char *dbPass;
		 char *dbName;
		 dbName=_ltPubInfo->_dbname;
		 dbUser=_ltPubInfo->_dbuser;
		 dbPass=_ltPubInfo->_dbpass;
		 G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		 if(G_DbCon==NULL){
				 ltMsgPk->msgpktype=1;
				 lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html\n","lthtml",LT_TYPE_STRING,"");
			 	 ltMsgFree(ltMsgPk);			
				 return 0;
		 }
		 
	   ltDbCursor *tempCursor;
	   LT_DBROW tempRow; 
	   sprintf(sqlBuf,"select count(*) from msaVLanArea where vlanid=%s",mywk);	
	   tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf); 
	   if(tempCursor!=NULL){
			  tempRow= ltDbFetchRow(tempCursor);
			  if(tempRow!=NULL){
				  lCount=atol(tempRow[0]);
			  }
		 }     
	   if(lCount==0){
		     sprintf(sqlBuf,"insert into msaVLanArea(vlanid,intercept,promisc,switch,netvlan,ipaddress,passaway,mask,apply)values (%s,%s,%s,%s,%s,'%s',%s,'%s',0)",mywk,caIntercept,caPromisc,caSwitch,caNetvlan,caIpaddress,caPassaway,camask);	  
		     ltDbExecSql(G_DbCon,sqlBuf);
	   }else{
		     sprintf(sqlBuf,"update msaVLanArea set intercept=%s,promisc=%s,switch=%s,netvlan=%s,ipaddress='%s',passaway=%s,mask='%s',apply=0 where vlanid=%s",caIntercept,caPromisc,caSwitch,caNetvlan,caIpaddress,caPassaway,camask,mywk); 
		     ltDbExecSql(G_DbCon,sqlBuf); 
		 }
     ltDbCloseCursor(tempCursor);
printf("sqlBuf:%s\n",sqlBuf);
     
	   ltDbHeadPtr dbPtr;
	   dbPtr=lt_dbinit();
  	 ltMsgPk->msgpktype=1;
     lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\r\n","lthtml",LT_TYPE_STRING,"0");   
	   ltMsgFree(ltMsgPk);
     ltDbCloseCursor(tempCursor);
    return 0;
}
//����Ӧ��
int msaApplyAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){   
     int fileproc;
		 char caCmdCon[1024];
		 char strS[128];
		 fileproc=0;
		 char strBuf[1024];
     ltDbCursor *tempCursor;
     LT_DBROW tempRow;
     char *appflag; 
     int k;
     /*char *rid; 
     char *intercept; 
     char *promisc; 
     char *switch0; 
     char *netvlan;
     char *ipaddress;
     char *passaway; 
     char *mask;*/
	   char *dbUser;
		 char *dbPass;
		 char *dbName;
		 dbName=_ltPubInfo->_dbname;
		 dbUser=_ltPubInfo->_dbuser;
		 dbPass=_ltPubInfo->_dbpass; 
		 G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		 if(G_DbCon==NULL){
					ltMsgPk->msgpktype=1;
					lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html\n","lthtml",LT_TYPE_STRING,"db error!");
					ltMsgFree(ltMsgPk);			
					return 0;
		 }
		 appflag=ltMsgGetVar_s(ltMsgPk,"deflag");
     if(ltMsgGetVar_s(ltMsgPk,"deflag")){
     		if(strcmp(appflag,"1")==0){
     		 k=0;
	     	 sprintf(strBuf,"select vlanid,intercept,promisc,switch,netvlan,ipaddress,mask,passaway,apply from msaVLanArea order by vlanid asc");
			   tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
			   if(tempCursor!=NULL){
						tempRow= ltDbFetchRow(tempCursor);
					  while(tempRow!=NULL){
					  	if(k==0){
							  	 memset(caCmdCon,0,sizeof(caCmdCon));
							     //�����ⲿ����
							     if(strcmp(tempRow[3],"0")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 up",atoi(tempRow[0]));
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"1")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 up   <promisc>",atoi(tempRow[0]));
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"2")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 up   <promisc>",atoi(tempRow[0]));
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"3")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 netmask %s  up   <promisc>",atoi(tempRow[0]),tempRow[6]);
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"4")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 netmask %s  up   <promisc>",atoi(tempRow[0]),tempRow[6]);
							     		sprintf(caCmdCon,"iptables  -t nat -A");			     		 
							     		//system(caCmdCon);
							     }
							  	 //д�����ű�
							  	 memset(strS,0,sizeof(strS));//_ltPubInfo->_msaLinkInfo[iii].issniffer      
							  	 sprintf(strS,"echo 'eth%d-%s-%s-eth%s-%s' > /proc/baochuang/linkinfo",atoi(tempRow[0]),tempRow[1],tempRow[3],tempRow[4],tempRow[7]);
							  	 if(!(strcmp(tempRow[4],"-1")==0)){
							     	 sprintf(caCmdCon,"echo '%s' > /etc/msa/msa/start/linkup",strS);     	 
							     	 system(caCmdCon);
							     }
							     //ɾ����һͨ��
							     memset(strS,0,sizeof(strS));
							     sprintf(strS,"echo eth%d >> /proc/baochuang/linkinfo",atoi(tempRow[0]));
							     sprintf(caCmdCon,"echo '%s' >> /etc/msa/msa/start/linkup",strS);
							     //system(caCmdCon);
							     sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 down",atoi(tempRow[0]));
							     //system(caCmdCon);
									 
									 //resetȫ����λ
									 //echo 'r' > /proc/baochuang/linkinfo
									 //��λ״̬Ϊȫ��һ��ͨ�ſ�
									 //ifconfig ethx 0.0.0.0 down
									 memset(strS,0,sizeof(strS));
									 sprintf(strS,"echo 'r' >> /proc/baochuang/linkinfo");
									 sprintf(caCmdCon,"echo '%s' >> /etc/msa/msa/start/linkup",strS);
									 //system(caCmdCon);
									 
									 sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 down",atoi(tempRow[0]));
									 //system(caCmdCon);
							}else{
							  	 memset(caCmdCon,0,sizeof(caCmdCon));
							     //�����ⲿ����
							     if(strcmp(tempRow[3],"0")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 up",atoi(tempRow[0]));
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"1")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 up   <promisc>",atoi(tempRow[0]));
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"2")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 up   <promisc>",atoi(tempRow[0]));
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"3")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 netmask %s  up   <promisc>",atoi(tempRow[0]),tempRow[6]);
							     		//system(caCmdCon);
							     }else if(strcmp(tempRow[3],"4")==0){
							     		sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 netmask %s  up   <promisc>",atoi(tempRow[0]),tempRow[6]);
							     		sprintf(caCmdCon,"iptables  -t nat -A");			     		 
							     		//system(caCmdCon);
							     }
							  	 //д�����ű�
							  	 memset(strS,0,sizeof(strS));//_ltPubInfo->_msaLinkInfo[iii].issniffer      
							  	 sprintf(strS,"echo 'eth%d-%s-%s-eth%s-%s' >> /proc/baochuang/linkinfo",atoi(tempRow[0]),tempRow[1],tempRow[3],tempRow[4],tempRow[7]);
							  	 if(!(strcmp(tempRow[4],"-1")==0)){
							     	 sprintf(caCmdCon,"echo '%s' >> /etc/msa/msa/start/linkup",strS);     	 
							     	 system(caCmdCon);
							     }
							     //ɾ����һͨ��
							     memset(strS,0,sizeof(strS));
							     sprintf(strS,"echo eth%d >> /proc/baochuang/linkinfo",atoi(tempRow[0]));
							     sprintf(caCmdCon,"echo '%s' >> /etc/msa/msa/start/linkup",strS);
							     //system(caCmdCon);
							     sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 down",atoi(tempRow[0]));
							     //system(caCmdCon);
									 
									 //resetȫ����λ
									 //echo 'r' > /proc/baochuang/linkinfo
									 //��λ״̬Ϊȫ��һ��ͨ�ſ�
									 //ifconfig ethx 0.0.0.0 down
									 memset(strS,0,sizeof(strS));
									 sprintf(strS,"echo 'r' >> /proc/baochuang/linkinfo");
									 sprintf(caCmdCon,"echo '%s' >> /etc/msa/msa/start/linkup",strS);
									 //system(caCmdCon);
									 
									 sprintf(caCmdCon,"ifconfig eth%d 0.0.0.0 down",atoi(tempRow[0]));
									 //system(caCmdCon);
							}
							tempRow= ltDbFetchRow(tempCursor);
							k++;
						}
			     ltDbCloseCursor(tempCursor);
			   }
				 sprintf(strBuf,"update msaVLanArea set apply=1");
				 ltDbExecSql(G_DbCon,strBuf);
				 ltDbClose(G_DbCon);
				 
			   ltMsgPk->msgpktype=1;
			   lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,"0");
			   ltMsgFree(ltMsgPk);
			   
			   return 0;
				}
	   }
	 
	   ltMsgPk->msgpktype=1;
	   lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,"1");
	   ltMsgFree(ltMsgPk);
	   return 0;
}
//������������ҳ��
int ltappPage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	char str[16];
	//�Ƿ�����  �Ƿ�����promisc����ģʽ
  int myintercept,mypromisc;
  //���ݵ����Ĵ��䷽ʽ   ת���������� ����ͨ�� ת��IP
	char myswitch[32],mynetvLan[32],mypassAway[32],mymask[32],myipAddress[32];	
	
	int mywk;
  char sqlBuf[1024];
  ltDbHeadPtr dbPtr;
  ltDbCursor *tempCursor;
  LT_DBROW tempRow;
  
  char *dbUser;
  char *dbPass;
  char *dbName;
  dbName=_ltPubInfo->_dbname;
  dbUser=_ltPubInfo->_dbuser;
  dbPass=_ltPubInfo->_dbpass;
  G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
  if(G_DbCon==NULL){
		 ltMsgPk->msgpktype=1;
		 lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html\n","lthtml",LT_TYPE_STRING,"");
	 	 ltMsgFree(ltMsgPk);			
		 return 0;
  }
		
	dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8");
	if(ltMsgGetVar_s(ltMsgPk,"mywk")!=NULL)
	{
		mywk=atol(ltMsgGetVar_s(ltMsgPk,"mywk"));
		sprintf(sqlBuf,"select vlanid,intercept,promisc,switch,netvlan,ipaddress,passaway,apply,mask from msaVLanArea where vlanid=%d",mywk);
	}
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
      tempRow= ltDbFetchRow(tempCursor);
      if(tempRow!=NULL){
         myintercept=atoi(tempRow[1]);
         mypromisc=atoi(tempRow[2]);
         sprintf(myswitch,"%s",tempRow[3]);
         sprintf(mynetvLan,"%s",tempRow[4]);
         sprintf(myipAddress,"%s",tempRow[5]);
         sprintf(mypassAway,"%s",tempRow[6]);
         sprintf(mymask,"%s",tempRow[8]);
         
         memset(str,0,sizeof(str));//1
	       sprintf(str,"interceptchk%d",myintercept);
	       lt_dbput_rootvars(dbPtr,1,str,"checked");
	       
	       memset(str,0,sizeof(str));//2
	       sprintf(str,"promiscchk%d",mypromisc);
	       lt_dbput_rootvars(dbPtr,1,str,"checked");
	       
	       memset(str,0,sizeof(str));
	       sprintf(str,"netvLan%ssel",mynetvLan);
	       lt_dbput_rootvars(dbPtr,1,str,"selected");
	       	
	       memset(str,0,sizeof(str));
	       sprintf(str,"switch%ssel",myswitch);
	       lt_dbput_rootvars(dbPtr,1,str,"selected");
	       	
	       memset(str,0,sizeof(str));
	       sprintf(str,"passAway%ssel",mypassAway);
	       lt_dbput_rootvars(dbPtr,1,str,"selected");
       
	       //memset(myipAddress,0,sizeof(myipAddress));
				 lt_dbput_rootvars(dbPtr,1,"ipAddress",myipAddress);
				 
				 lt_dbput_rootvars(dbPtr,1,"mask",mymask);
					
         tempRow= ltDbFetchRow(tempCursor);
      }
      ltDbCloseCursor(tempCursor);
    }

	lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/manager/page.htm",dbPtr->head,0);
	ltMsgFree(ltMsgPk);
	lt_dbfree(dbPtr);
	return 0;
}

/*
*���������ҳ���ʼ������
*/
int vserver(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
			int   nownum;
      int   match;
  		int   jjjj;
      char  mynownum[16];
      char enable1[24],enable2[24],enable3[24],enable4[24],enable5[24],enable6[24],enable7[24],enable8[24];
      char Lan1[24],Lan2[24],Lan3[24],Lan4[24],Lan5[24],Lan6[24],Lan7[24],Lan8[24];
      char pro1[24],pro2[24],pro3[24],pro4[24],pro5[24],pro6[24],pro7[24],pro8[24];
      char ip1[24],ip2[24],ip3[24],ip4[24],ip5[24],ip6[24],ip7[24],ip8[24];
      char ip11[24],ip22[24],ip33[24],ip44[24],ip55[24],ip66[24],ip77[24],ip88[24];
      char lan11[24],lan22[24],lan33[24],lan44[24],lan55[24],lan66[24],lan77[24],lan88[24];
      
      
      char str[16];
      char *pFile="/etc/msa/msa/VPS/settings";
	   	ltDbHeadPtr dbPtr;
     	dbPtr=lt_dbinit();
	    lt_db_htmlpage(dbPtr,"utf-8");
	    //����
	     memset(enable1,0,sizeof(enable1));
		   bcCnfGetValue_s(pFile,"enable1",enable1);
		   if(strcmp(enable1,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk1","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk1","");
		   }
	     memset(enable2,0,sizeof(enable2));
		   bcCnfGetValue_s(pFile,"enable2",enable2);
		   if(strcmp(enable2,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk2","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk2","");
		   }
	     memset(enable3,0,sizeof(enable3));
		   bcCnfGetValue_s(pFile,"enable3",enable3);
		   if(strcmp(enable3,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk3","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk3","");
		   }
	     memset(enable4,0,sizeof(enable4));
		   bcCnfGetValue_s(pFile,"enable4",enable4);
		   if(strcmp(enable4,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk4","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk4","");
		   }
	     memset(enable5,0,sizeof(enable5));
		   bcCnfGetValue_s(pFile,"enable5",enable5);
		   if(strcmp(enable5,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk5","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk5","");
		   }
	     memset(enable6,0,sizeof(enable6));
		   bcCnfGetValue_s(pFile,"enable6",enable6);
		   if(strcmp(enable6,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk6","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk6","");
		   }
	     memset(enable7,0,sizeof(enable7));
		   bcCnfGetValue_s(pFile,"enable7",enable7);
		   if(strcmp(enable7,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk7","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk7","");
		   }
	     memset(enable8,0,sizeof(enable8));
		   bcCnfGetValue_s(pFile,"enable8",enable8);
		   if(strcmp(enable8,"1")==0){
		   	lt_dbput_rootvars(dbPtr,1,"enablechk8","checked"); 
		   }else{
		   	lt_dbput_rootvars(dbPtr,1,"enablechk8","");
		   }
		   //��������
		   memset(Lan1,0,sizeof(Lan1));
		   bcCnfGetValue_s(pFile,"Lan1",Lan1);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN1%s",Lan1);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan2,0,sizeof(Lan2));
		   bcCnfGetValue_s(pFile,"Lan2",Lan2);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN2%s",Lan2);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan3,0,sizeof(Lan3));
		   bcCnfGetValue_s(pFile,"Lan3",Lan3);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN3%s",Lan3);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan4,0,sizeof(Lan4));
		   bcCnfGetValue_s(pFile,"Lan4",Lan4);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN4%s",Lan4);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan5,0,sizeof(Lan5));
		   bcCnfGetValue_s(pFile,"Lan5",Lan5);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN5%s",Lan5);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan6,0,sizeof(Lan6));
		   bcCnfGetValue_s(pFile,"Lan6",Lan6);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN6%s",Lan6);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan7,0,sizeof(Lan7));
		   bcCnfGetValue_s(pFile,"Lan7",Lan7);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN7%s",Lan7);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(Lan8,0,sizeof(Lan8));
		   bcCnfGetValue_s(pFile,"Lan8",Lan8);
			 memset(str,0,sizeof(str));
			 sprintf(str,"LAN8%s",Lan8);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 //Э��
		   memset(pro1,0,sizeof(pro1));
		   bcCnfGetValue_s(pFile,"pro1",pro1);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro1%s",pro1);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro2,0,sizeof(pro2));
		   bcCnfGetValue_s(pFile,"pro2",pro2);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro2%s",pro2);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro3,0,sizeof(pro3));
		   bcCnfGetValue_s(pFile,"pro3",pro3);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro3%s",pro3);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro4,0,sizeof(pro4));
		   bcCnfGetValue_s(pFile,"pro4",pro4);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro4%s",pro4);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro5,0,sizeof(pro5));
		   bcCnfGetValue_s(pFile,"pro5",pro5);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro5%s",pro5);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro6,0,sizeof(pro6));
		   bcCnfGetValue_s(pFile,"pro6",pro6);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro6%s",pro6);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro7,0,sizeof(pro7));
		   bcCnfGetValue_s(pFile,"pro7",pro7);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro7%s",pro7);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 
		   memset(pro8,0,sizeof(pro8));
		   bcCnfGetValue_s(pFile,"pro8",pro8);
			 memset(str,0,sizeof(str));
			 sprintf(str,"pro8%s",pro8);
			 lt_dbput_rootvars(dbPtr,1,str,"selected");
			 //IP��ַ
		   memset(ip1,0,sizeof(ip1));
		   bcCnfGetValue_s(pFile,"ip1",ip1);
		   lt_dbput_rootvars(dbPtr,1,"ip1",ip1);
			 
		   memset(ip2,0,sizeof(ip2));
		   bcCnfGetValue_s(pFile,"ip2",ip2);
		   lt_dbput_rootvars(dbPtr,1,"ip2",ip2);
			 
		   memset(ip3,0,sizeof(ip3));
		   bcCnfGetValue_s(pFile,"ip3",ip3);
		   lt_dbput_rootvars(dbPtr,1,"ip3",ip3);
			 
		   memset(ip4,0,sizeof(ip4));
		   bcCnfGetValue_s(pFile,"ip4",ip4);
		   lt_dbput_rootvars(dbPtr,1,"ip4",ip4);
			 
		   memset(ip5,0,sizeof(ip5));
		   bcCnfGetValue_s(pFile,"ip5",ip5);
		   lt_dbput_rootvars(dbPtr,1,"ip5",ip5);
			 
		   memset(ip6,0,sizeof(ip6));
		   bcCnfGetValue_s(pFile,"ip6",ip6);
		   lt_dbput_rootvars(dbPtr,1,"ip6",ip6);
			 
		   memset(ip7,0,sizeof(ip7));
		   bcCnfGetValue_s(pFile,"ip7",ip7);
		   lt_dbput_rootvars(dbPtr,1,"ip7",ip7);
			 
		   memset(ip8,0,sizeof(ip8));
		   bcCnfGetValue_s(pFile,"ip8",ip8);
		   lt_dbput_rootvars(dbPtr,1,"ip8",ip8);
		   //ӳ��IP��ַ
		   memset(ip11,0,sizeof(ip11));
		   bcCnfGetValue_s(pFile,"ip11",ip11);
		   lt_dbput_rootvars(dbPtr,1,"ip11",ip11);
		   
		   memset(ip22,0,sizeof(ip22));
		   bcCnfGetValue_s(pFile,"ip22",ip22);
		   lt_dbput_rootvars(dbPtr,1,"ip22",ip22);
		   
		   memset(ip33,0,sizeof(ip33));
		   bcCnfGetValue_s(pFile,"ip33",ip33);
		   lt_dbput_rootvars(dbPtr,1,"ip33",ip33);
		   
		   memset(ip44,0,sizeof(ip44));
		   bcCnfGetValue_s(pFile,"ip44",ip44);
		   lt_dbput_rootvars(dbPtr,1,"ip44",ip44);
		   
		   memset(ip55,0,sizeof(ip55));
		   bcCnfGetValue_s(pFile,"ip55",ip55);
		   lt_dbput_rootvars(dbPtr,1,"ip55",ip55);
		   
		   memset(ip6,0,sizeof(ip66));
		   bcCnfGetValue_s(pFile,"ip66",ip66);
		   lt_dbput_rootvars(dbPtr,1,"ip66",ip66);
		   
		   memset(ip77,0,sizeof(ip77));
		   bcCnfGetValue_s(pFile,"ip77",ip77);
		   lt_dbput_rootvars(dbPtr,1,"ip77",ip77);
		   
		   memset(ip88,0,sizeof(ip88));
		   bcCnfGetValue_s(pFile,"ip88",ip88);
		   lt_dbput_rootvars(dbPtr,1,"ip88",ip88);
			 //����˿�
		   memset(lan11,0,sizeof(lan11));
		   bcCnfGetValue_s(pFile,"lan11",lan11);
		   lt_dbput_rootvars(dbPtr,1,"lan11",lan11);
		   
		   memset(lan22,0,sizeof(lan22));
		   bcCnfGetValue_s(pFile,"lan22",lan22);
		   lt_dbput_rootvars(dbPtr,1,"lan22",lan22);
		   
		   memset(lan33,0,sizeof(lan33));
		   bcCnfGetValue_s(pFile,"lan33",lan33);
		   lt_dbput_rootvars(dbPtr,1,"lan33",lan33);
		   
		   memset(lan44,0,sizeof(lan44));
		   bcCnfGetValue_s(pFile,"lan44",lan44);
		   lt_dbput_rootvars(dbPtr,1,"lan44",lan44);
		   
		   memset(lan55,0,sizeof(lan55));
		   bcCnfGetValue_s(pFile,"lan55",lan55);
		   lt_dbput_rootvars(dbPtr,1,"lan55",lan55);
		   
		   memset(lan66,0,sizeof(lan66));
		   bcCnfGetValue_s(pFile,"lan66",lan66);
		   lt_dbput_rootvars(dbPtr,1,"lan66",lan66);
		   
		   memset(lan77,0,sizeof(lan77));
		   bcCnfGetValue_s(pFile,"lan77",lan77);
		   lt_dbput_rootvars(dbPtr,1,"lan77",lan77);
		   
		   memset(lan88,0,sizeof(lan88));
		   bcCnfGetValue_s(pFile,"lan88",lan88);
		   lt_dbput_rootvars(dbPtr,1,"lan88",lan88);
			 
	    
	    static char inbuf[4096];
  		int   fd;
  		fd=open("/proc/net/dev",O_RDONLY | O_NDELAY); 
		  static stralloc line = {0};
		  buffer ss;
			nownum=0;
		  buffer_init(&ss,read,fd,inbuf,sizeof(inbuf));
		  for (;;){
		  	if (getln(&ss,&line,&match,'\n') == -1){ break;}
				if (!match && !line.len) { break; }
				for(jjjj=0;jjjj<line.len;jjjj++){
					 if(line.s[jjjj]=='e' && line.s[jjjj+1]=='t' && line.s[jjjj+2]=='h'){
						 nownum++;
				   }
			  }
			}
	    sprintf(mynownum,"%d",nownum);	
	    lt_dbput_rootvars(dbPtr,1,"nownum",mynownum);	
	    
	    lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/manager/nasVPSList.htm",dbPtr->head,0);
			ltMsgFree(ltMsgPk);
			lt_dbfree(dbPtr);
			return 0;
}
/*
*�������������
*/
int ltVPSok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
    char *enable1,*enable2,*enable3,*enable4,*enable5,*enable6,*enable7,*enable8;
    char *Lan1,*Lan2,*Lan3,*Lan4,*Lan5,*Lan6,*Lan7,*Lan8;
    char *pro1,*pro2,*pro3,*pro4,*pro5,*pro6,*pro7,*pro8;
    char *ip1,*ip2,*ip3,*ip4,*ip5,*ip6,*ip7,*ip8;
    char *ip11,*ip22,*ip33,*ip44,*ip55,*ip66,*ip77,*ip88;
    char *lan11,*lan22,*lan33,*lan44,*lan55,*lan66,*lan77,*lan88;
    char caCmdCon[128];
    
    //��������
     Lan1=ltMsgGetVar_s(ltMsgPk,"Lan1");
     Lan2=ltMsgGetVar_s(ltMsgPk,"Lan2");
     Lan3=ltMsgGetVar_s(ltMsgPk,"Lan3");
     Lan4=ltMsgGetVar_s(ltMsgPk,"Lan4");
     Lan5=ltMsgGetVar_s(ltMsgPk,"Lan5");
     Lan6=ltMsgGetVar_s(ltMsgPk,"Lan6");
     Lan7=ltMsgGetVar_s(ltMsgPk,"Lan7");
     Lan8=ltMsgGetVar_s(ltMsgPk,"Lan8");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan1=%s' > %s",Lan1,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan2=%s' >> %s",Lan2,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan3=%s' >> %s",Lan3,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan4=%s' >> %s",Lan4,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan5=%s' >> %s",Lan5,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan6=%s' >> %s",Lan6,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan7=%s' >> %s",Lan7,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'Lan8=%s' >> %s",Lan8,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
    //ӳ��IP��ַ
     ip11=ltMsgGetVar_s(ltMsgPk,"txtIp11");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip11=%s' >> %s",ip11,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip22=ltMsgGetVar_s(ltMsgPk,"txtIp22");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip22=%s' >> %s",ip22,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip33=ltMsgGetVar_s(ltMsgPk,"txtIp33");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip33=%s' >> %s",ip33,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip44=ltMsgGetVar_s(ltMsgPk,"txtIp44");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip44=%s' >> %s",ip44,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip55=ltMsgGetVar_s(ltMsgPk,"txtIp55");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip55=%s' >> %s",ip55,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip66=ltMsgGetVar_s(ltMsgPk,"txtIp66");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip66=%s' >> %s",ip66,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip77=ltMsgGetVar_s(ltMsgPk,"txtIp77");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip77=%s' >> %s",ip77,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip88=ltMsgGetVar_s(ltMsgPk,"txtIp88");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip88=%s' >> %s",ip88,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
	   //����˿�
     lan11=ltMsgGetVar_s(ltMsgPk,"lan11");
     lan22=ltMsgGetVar_s(ltMsgPk,"lan22");
     lan33=ltMsgGetVar_s(ltMsgPk,"lan33");
     lan44=ltMsgGetVar_s(ltMsgPk,"lan44");
     lan55=ltMsgGetVar_s(ltMsgPk,"lan55");
     lan66=ltMsgGetVar_s(ltMsgPk,"lan66");
     lan77=ltMsgGetVar_s(ltMsgPk,"lan77");
     lan88=ltMsgGetVar_s(ltMsgPk,"lan88");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan11=%s' >> %s",lan11,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan22=%s' >> %s",lan22,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan33=%s' >> %s",lan33,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan44=%s' >> %s",lan44,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan55=%s' >> %s",lan55,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan66=%s' >> %s",lan66,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan77=%s' >> %s",lan77,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'lan88=%s' >> %s",lan88,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
	   //IP��ַ
     ip1=ltMsgGetVar_s(ltMsgPk,"txtIp1");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip1=%s' >> %s",ip1,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip2=ltMsgGetVar_s(ltMsgPk,"txtIp2");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip2=%s' >> %s",ip2,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip3=ltMsgGetVar_s(ltMsgPk,"txtIp3");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip3=%s' >> %s",ip3,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip4=ltMsgGetVar_s(ltMsgPk,"txtIp4");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip4=%s' >> %s",ip4,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip5=ltMsgGetVar_s(ltMsgPk,"txtIp5");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip5=%s' >> %s",ip5,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip6=ltMsgGetVar_s(ltMsgPk,"txtIp6");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip6=%s' >> %s",ip6,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip7=ltMsgGetVar_s(ltMsgPk,"txtIp7");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip7=%s' >> %s",ip7,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     ip8=ltMsgGetVar_s(ltMsgPk,"txtIp8");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'ip8=%s' >> %s",ip8,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
	   //Э��
     pro1=ltMsgGetVar_s(ltMsgPk,"pro1");
     pro2=ltMsgGetVar_s(ltMsgPk,"pro2");
     pro3=ltMsgGetVar_s(ltMsgPk,"pro3");
     pro4=ltMsgGetVar_s(ltMsgPk,"pro4");
     pro5=ltMsgGetVar_s(ltMsgPk,"pro5");
     pro6=ltMsgGetVar_s(ltMsgPk,"pro6");
     pro7=ltMsgGetVar_s(ltMsgPk,"pro7");
     pro8=ltMsgGetVar_s(ltMsgPk,"pro8");
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro1=%s' >> %s",pro1,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro2=%s' >> %s",pro2,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro3=%s' >> %s",pro3,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro4=%s' >> %s",pro4,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro5=%s' >> %s",pro5,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro6=%s' >> %s",pro6,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro7=%s' >> %s",pro7,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'pro8=%s' >> %s",pro8,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     //����
     enable1=ltMsgGetVar_s(ltMsgPk,"enable1");
     enable2=ltMsgGetVar_s(ltMsgPk,"enable2");
     enable3=ltMsgGetVar_s(ltMsgPk,"enable3");
     enable4=ltMsgGetVar_s(ltMsgPk,"enable4");
     enable5=ltMsgGetVar_s(ltMsgPk,"enable5");
     enable6=ltMsgGetVar_s(ltMsgPk,"enable6");
     enable7=ltMsgGetVar_s(ltMsgPk,"enable7");
     enable8=ltMsgGetVar_s(ltMsgPk,"enable8");
     
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable1=%s' >> %s",enable1,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable2=%s' >> %s",enable2,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable3=%s' >> %s",enable3,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable4=%s' >> %s",enable4,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable5=%s' >> %s",enable5,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable6=%s' >> %s",enable6,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable7=%s' >> %s",enable7,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
     memset(caCmdCon,0,sizeof(caCmdCon));
		 sprintf(caCmdCon,"echo 'enable8=%s' >> %s",enable8,"/etc/msa/msa/VPS/settings");
		 system(caCmdCon);
		 
		 //д���ýű�
		 if(strcmp(enable1,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro2,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' > %s",ip11,lan11,Lan1,ip1,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro2,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' > %s",ip11,lan11,Lan1,ip1,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro2,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' > %s",ip11,lan11,Lan1,ip1,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable2,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro2,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip22,lan22,Lan2,ip2,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro2,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip22,lan22,Lan2,ip2,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro2,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip22,lan22,Lan2,ip2,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable3,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro3,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip33,lan33,Lan3,ip3,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro3,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip33,lan33,Lan3,ip3,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro3,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip33,lan33,Lan3,ip3,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable4,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro4,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip44,lan44,Lan4,ip4,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro4,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip44,lan44,Lan4,ip4,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro4,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip44,lan44,Lan4,ip4,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable5,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro5,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip55,lan55,Lan5,ip5,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro5,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip55,lan55,Lan5,ip5,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro5,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip55,lan55,Lan5,ip5,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable6,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro6,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip66,lan66,Lan6,ip6,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro6,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip66,lan66,Lan6,ip6,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro6,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip66,lan66,Lan6,ip6,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable7,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro7,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip77,lan77,Lan7,ip7,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro7,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip77,lan77,Lan7,ip7,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro7,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip77,lan77,Lan7,ip7,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 if(strcmp(enable8,"1")==0){
			  //#/sbin/iptables -t nat -A PREROUTING -p tcp -d $addr0 --dport 20 -i eth0 -j DNAT --to $addr3:20  
				if(strcmp(pro8,"-1")==0){//all
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip88,lan88,Lan8,ip8,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro8,"0")==0){//UDP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p udp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip88,lan88,Lan8,ip8,"/etc/msa/msa/start/vps.up");
			  }else if(strcmp(pro8,"1")==0){//TCP
			   sprintf(caCmdCon,"echo 'iptables -t nat -I PREROUTING -p tcp -d %s --dport %s -i eth%s -j DNAT --to %s' >> %s",ip88,lan88,Lan8,ip8,"/etc/msa/msa/start/vps.up");
			  }
			  system(caCmdCon);
		 }
		 ///////system("chmod 755 %s",�ļ���);
		 vserver(confd,ltMsgPk,lt_MMHead);
		 return 0;
}
/*
*DDNS
*/
int ddnsset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
			char servername[24],username[24],userpass[24];
			char str[16];
      char *pFile="/etc/msa/msa/DDNS/settings";
      
     	ltDbHeadPtr dbPtr;
     	dbPtr=lt_dbinit();
	    lt_db_htmlpage(dbPtr,"utf-8");
    
	    
		  memset(servername,0,sizeof(servername));
		  bcCnfGetValue_s("/etc/msa/msa/DDNS/settings1","ddnsenable",servername);
			memset(str,0,sizeof(str));
			sprintf(str,"servername%s",servername);
			lt_dbput_rootvars(dbPtr,1,str,"selected");
    
	    memset(username,0,sizeof(username));
	    bcCnfGetValue_s(pFile,"szUserID",username);
	    lt_dbput_rootvars(dbPtr,1,"username",username);
		 
	    memset(userpass,0,sizeof(userpass));
	    bcCnfGetValue_s(pFile,"szUserPWD",userpass);
	    lt_dbput_rootvars(dbPtr,1,"userpass",userpass);
		   
	    lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/manager/nasDDNSPage.htm",dbPtr->head,0);
			ltMsgFree(ltMsgPk);
			lt_dbfree(dbPtr);
			return 0;
}
/*
*����DDNS
*/
int ltDDNSok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	char *servername,*username,*userpass;
	char caCmdCon[128];
	
	servername=ltMsgGetVar_s(ltMsgPk,"servername");
	username=ltMsgGetVar_s(ltMsgPk,"username");
	userpass=ltMsgGetVar_s(ltMsgPk,"userpass");
	
	if(strcmp(servername,"0")==0){
		memset(caCmdCon,0,sizeof(caCmdCon));
	  sprintf(caCmdCon,"echo 'ddnsenable=0' > %s","/etc/msa/msa/DDNS/settings1");
	  system(caCmdCon);
	}else{
		memset(caCmdCon,0,sizeof(caCmdCon));
	  sprintf(caCmdCon,"echo 'ddnsenable=1' > %s","/etc/msa/msa/DDNS/settings1");
	  system(caCmdCon);
	}
	
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'szHost = PH031.Oray.Net' > %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
	
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'szServiceHost = phservice2.oray.net' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'szUserID=%s' >> %s",username,"/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'szUserPWD=%s' >> %s",userpass,"/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'nUserType=0' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'bStartMiniHttp=1' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'httproot = /usr/local/phlinux/webadmin' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'runas =' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo '' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo '[log]' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'file = /var/log/phlinux.log' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  memset(caCmdCon,0,sizeof(caCmdCon));
  sprintf(caCmdCon,"echo 'level = 1' >> %s","/etc/msa/msa/DDNS/settings");
  system(caCmdCon);
  
  ddnsset(confd,ltMsgPk,lt_MMHead);
	return 0;
}


int ltdesktopset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){      
     	ltDbHeadPtr dbPtr;
     	dbPtr=lt_dbinit();
	    lt_db_htmlpage(dbPtr,"utf-8");
	    
		  char *dbName;
			dbName=_ltPubInfo->_dbname;
			
			lt_dbput_rootvars(dbPtr,1,"dbName",dbName);
	    lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/desktop/desktop.html",dbPtr->head,0);
			ltMsgFree(ltMsgPk);
			lt_dbfree(dbPtr);
			return 0;
}
