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
#include <dirent.h>
#include "msa.h"
#define _reportdir   "/report/sysreport"
#define _sysmodeldir   "/reportplt/syslineplt"
#define _riskmodeldir   "/reportplt/risklineplt/"
#define _MAXRERORD   20   //����¼����
#define _p2pUrlSort   78   //P2P����URLSORT
#define _videoUrlSort   79   //��Ƶ����URLSORT
//ϵͳ״̬��������	
int msaReportSysLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{	 
   	ltDbCursor *tempCursor;
		LT_DBROW tempRow;
		ltDbHeadPtr dbPtr;
		ltTablePtr  tablePtr;   
		char caSdate[32],caEdate[32],caSdate2[32],caSdate1[32];
		char email[32],sqlBuf[1024];
		char caTempDataDir1[128],caTempDataDir2[128];
		char caLabel[256],caTempDir[256],caTempFile[256],index[16];
		char caItem[16];
		char caTemp[1024];
		char caTemp1[1024];	
		char flow[256];	
		char responseDir[256]; 
		char *work=NULL;	
		char *reportname=NULL;	
		int j,srcfd1,srcfd2,step;
		unsigned long fileName=0;
		unsigned long tmpDir=0;
		long lTime,lTime1,lTime2;    
	 	unsigned int  Max2;
    unsigned long long lUbytes,lDbytes,lMaxBytes;	
    char sDate[64],sTime[64];
	  char caFile1[256];   
    char caCmd[256];
    int  fdwrite=-1,num;
    memset(caCmd,0,sizeof(caCmd));
		memset(caSdate,0,sizeof(caSdate));//��ʼ��
		memset(caEdate,0,sizeof(caEdate));
		memset(caSdate1,0,sizeof(caSdate1));
		memset(caSdate2,0,sizeof(caSdate2));
		memset(sDate,0,sizeof(sDate));
		memset(sTime,0,sizeof(sTime));	
		memset(sqlBuf,0,sizeof(sqlBuf));
		memset(email,0,sizeof(email));
		memset(caTempDir,0,sizeof(caTempDir));
		memset(caTempDataDir1,0,sizeof(caTempDataDir1));
		memset(caTempDataDir2,0,sizeof(caTempDataDir2));
		memset(index,0,sizeof(index));		
		memset(flow,0,sizeof(flow));		
		srcfd1=srcfd2=-1;
		lMaxBytes=0;
		Max2=0;
		step=0;
		num=1;
		j=0;
		 //�������ݿ�
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon==NULL){
			return 0;
		}	
		dbPtr=lt_dbinit();
    tablePtr=lt_dbput_table(dbPtr,"list");
		lt_db_htmlpage(dbPtr,"utf-8");	
		if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
				  sprintf(caSdate,"%s","");
	  }else{
	    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
	  }
	  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
				  sprintf(caEdate,"%s","");
	  }else{
	    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
	  }
	 	if(ltMsgGetVar_s(ltMsgPk,"work")==NULL){
				  work="";
	  }else{
	    		work=ltMsgGetVar_s(ltMsgPk,"work");
	  }
		if( ltMsgGetVar_s(ltMsgPk,"email")==NULL){
				  sprintf(email,"%s","");
	  }else{
	    		sprintf(email,"%s",ltMsgGetVar_s(ltMsgPk,"email"));
	  }
		if(ltMsgGetVar_s(ltMsgPk,"reportname")){	
	  	reportname=ltMsgGetVar_s(ltMsgPk,"reportname");
	  } 
	  if(ltMsgGetVar_s(ltMsgPk,"step")){
				step=atoi(ltMsgGetVar_s(ltMsgPk,"step"));
	  }	  
	  if(ltMsgGetVar_s(ltMsgPk,"filedir")){	  
	  		fileName=atoll(ltMsgGetVar_s(ltMsgPk,"filedir"));
	  }
	  printf("step:%d\n",step);
    if(fileName==0){
		    tmpDir=ltStrGetId();
		    sprintf(caTempDir,"%s%s/%lu/",_datacenterdir,_reportdir,tmpDir);
		    sprintf(responseDir,"%lu",tmpDir);	
		    if(ltFileIsExist(caTempDir)!=1){	    	
		       if(mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)!=0) {
				      ltMsgPk->msgpktype=1;
							lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");		
							ltMsgFree(ltMsgPk);
			        return 0;
       		 }
    		} 
    }else{
    	  sprintf(caTempDir,"%s%s/%lu/",_datacenterdir,_reportdir,fileName);   
    	  sprintf(responseDir,"%lu",fileName);
    } 
	  
	  
	  //���ڴ���
    lTime = time(0);
    if(!ltStrIsSpaces(caSdate)){
        lTime1 = nasCvtLongTime(caSdate,"00:00:00");
    }else{
        lTime1 = 0;
    } 
    if(!ltStrIsSpaces(caEdate)) {
        lTime2 = nasCvtLongTime(caEdate,"23:59:59");
    }else{
        lTime2 = 0;
    } 
    
    if(lTime1 == 0) {
         lTime1 = lTime;       
    }
	  if(lTime2 == 0) {
         lTime2 = lTime;
    }
	  if(lTime1 > lTime) {
         lTime1 = lTime;
    }
    if(lTime2>lTime){
		 		 lTime2=lTime;
	  }
	  
	  if(step==1){
	  	    nasCvtStime(time(0),sDate,sTime); 
			    sprintf(caFile1,"%sinfo.ini",caTempDir);     
			    fdwrite = open(caFile1, O_APPEND | O_WRONLY | O_CREAT, 0644);
					if(fdwrite == (-1)) {
						 ltMsgPk->msgpktype=1;
						 lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");		
						 ltMsgFree(ltMsgPk);
						 return 0;
					}			
					sprintf(caCmd,"date=%s_%s\n",sDate,sTime);
				  write(fdwrite,caCmd,strlen(caCmd));
				  sprintf(caCmd,"reportname=%s\n",reportname);
				  write(fdwrite,caCmd,strlen(caCmd));
				  sprintf(caCmd,"email=%s\n",email);
				  write(fdwrite,caCmd,strlen(caCmd));
				  close(fdwrite);
			    sprintf(caLabel,"/bin/cp %s%s/right-top-d.jpg  %s",_msahtmldir,_sysmodeldir,caTempDir);
				  system(caLabel);
				  sprintf(caLabel,"/bin/cp %s%s/right-top.jpg  %s",_msahtmldir,_sysmodeldir,caTempDir);
				  system(caLabel);
				  sprintf(caLabel,"/bin/cp %s%s/banner.jpg  %s",_msahtmldir,_sysmodeldir,caTempDir);
				  system(caLabel);
				  sprintf(caLabel,"/bin/cp %s%s/up-1.jpg  %s",_msahtmldir,_sysmodeldir,caTempDir);
				  system(caLabel);
				  sprintf(caLabel,"/bin/cp %s%s/up-2.jpg  %s",_msahtmldir,_sysmodeldir,caTempDir);
				  system(caLabel);
					sprintf(caLabel,"/bin/cp %s%s/up-3.jpg  %s",_msahtmldir,_sysmodeldir,caTempDir);
				  system(caLabel);   
	  }
 
    nasTimeGetDate(caSdate1,lTime1);
    nasTimeGetDate(caSdate2,lTime2);
    if(step==1){
    			sprintf(sqlBuf,"select sdate,cast(avg(ubytes) as dec(18,2)) as ubytes,cast(avg(dbytes) as dec(18,2)) as dbytes,cast(avg(tcpconnect) as dec(18,2)) as tcpconnect,cast(avg(udpconnect) as dec(18,2)) as udpconnect,cast(avg(onlineuser) as dec(18,2)) as onlineuser from msatimereport where sdate>='%s' and sdate<='%s' group by sdate order by sdate asc",caSdate1,caSdate2);	
    }else if(step==2){
    			sprintf(sqlBuf,"select service,sum(ubytes+dbytes) as flow,sum(onlinetime) as atime from msatimesrvreport where sdate>='%s' and sdate<='%s' group by service order by flow desc",caSdate1,caSdate2);
    }else if(step==3){								//top���ź���Ա msatimesrvreport
    			
    			sprintf(sqlBuf,"select b.dispname,c.name,sum(bytes) as flow,sum(onlinetime) from msasrvreport a,msauser b,msagroup c where sdate>='%s' and sdate<='%s' and a.userid=b.userid and b.groupid0=c.id and workflag=%s group by b.dispname,c.name order by flow desc",caSdate1,caSdate2,work);
    			printf("SQL: %s \n",sqlBuf);
    			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
				  if(tempCursor == NULL){
					      sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir); 
				    	  system(caLabel);
				    	  ltMsgFree(ltMsgPk); 
				        return 0;
				  }
				  tablePtr=lt_dbput_table(dbPtr,"list2");
				  if(tempCursor!=NULL){
					    tempRow= ltDbFetchRow(tempCursor);
				    	while(tempRow!=NULL){					   		  
					   		   if(atoll(tempRow[2])>1024000){
				             sprintf(flow,"%0.3fM",atoll(tempRow[2])/1024000.00);
				           }else{
				             sprintf(flow,"%0.3fKB",atoll(tempRow[2])/1024.00);
				           }
				           char numchar[32];
									 sprintf(numchar,"%d",num);
				           lt_dbput_recordvars(tablePtr,5,
				           "num",LT_TYPE_STRING,numchar,
				           "gname",LT_TYPE_STRING,tempRow[1],
				           "uname",LT_TYPE_STRING,tempRow[0],
				           "allflow",LT_TYPE_STRING,flow,
					 				 "otime",LT_TYPE_STRING,time2str(atoi(tempRow[3])));
					 				 num++;
						    	 tempRow= ltDbFetchRow(tempCursor);
					    }
				      ltDbCloseCursor(tempCursor);
				  }
    			sprintf(sqlBuf,"select cast(avg(msasrvreport.bytes) as dec(18,3)) as flow,cast(avg(msasrvreport.onlinetime) as dec(18,3)) as onlinetime,msauser.groupid0 from msasrvreport left join msauser on msasrvreport.userid=msauser.userid where msasrvreport.sdate<'%s' and msasrvreport.sdate>'%s' group by msauser.groupid0 order by flow desc",caEdate,caSdate);
    }else if(step==4){					//��վǰ50��������������ַ����ַ����
    			sprintf(sqlBuf,"select host,urlsort,sum(bytes) as abyte,sum(ctime) from msahttpreport where sdate>='%s' and sdate<='%s' group by host,urlsort order by abyte desc limit %d offset 0",caSdate1,caSdate2,50);
    }else if(step==5){					//msaDipReportǰ50������������Ŀ�ĵ�ַ
    			sprintf(sqlBuf,"select dip,sum(bytes) as abyte,sum(ctime) as acount,sum(onlinetime) as atime from msaDipReport  where sdate>='%s' and sdate<='%s' group by dip order by abyte desc limit %d offset 0",caSdate1,caSdate2,50);
    }
    printf("SQL:%s \n",sqlBuf);
    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
	  if(tempCursor == NULL){
		      sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir); 
	    	  system(caLabel);
	    	  ltMsgFree(ltMsgPk); 
	        return 0;
	  }
	  if(step==1){
				sprintf(caTempDataDir1,"%sdata1",caTempDir);
				srcfd1 = open(caTempDataDir1,O_WRONLY | O_CREAT | O_TRUNC);
			  if(srcfd1 == (-1)) {
			  	    sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�����ļ�д����,�޷����ɱ���",caTempDir);
				      system(caLabel);
				    	ltMsgFree(ltMsgPk);
				      return 0;
				}
				sprintf(caTempDataDir2,"%sdata2",caTempDir);
				srcfd2 = open(caTempDataDir2,O_WRONLY | O_CREAT | O_TRUNC);
			  if(srcfd2 == (-1)){
			  	    sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�����ļ�д����,�޷����ɱ���",caTempDir);
				      system(caLabel);
				    	ltMsgFree(ltMsgPk);
				      return 0;
				}
	  }else if(step==3){
	  		sprintf(caTempDataDir1,"%sdata1",caTempDir);
				srcfd1 = open(caTempDataDir1,O_WRONLY | O_CREAT | O_TRUNC);
			  if(srcfd1 == (-1)) {
			  	    sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�����ļ�д����,�޷����ɱ���",caTempDir);
				      system(caLabel);
				    	ltMsgFree(ltMsgPk);
				      return 0;
				}  
	  }
	  
	  
	  char upflow[32];//up
	  char downflow[32];//down	 	
	  num=1;  
    if(tempCursor!=NULL){
		    tempRow= ltDbFetchRow(tempCursor);
	    	while(tempRow!=NULL){	  
	    		   if(step==1){
	    		   		 memset(upflow,0,sizeof(upflow));
				   		   memset(downflow,0,sizeof(downflow));
				   		   memset(caItem,0,sizeof(caItem));
				   		   memset(caTemp,0,sizeof(caTemp));
				   		   memset(caTemp1,0,sizeof(caTemp1));		   		   
				   		   if(atoll(tempRow[1])>1024000){
		               sprintf(upflow,"%0.3fM",atoll(tempRow[1])/1024000.00);
		             }else{
		               sprintf(upflow,"%0.3fKB",atoll(tempRow[1])/1024.00);
		             }
				   		   if(atoll(tempRow[2])>1024000){
		               sprintf(downflow,"%0.3fM",atoll(tempRow[2])/1024000.00);
		             }else{
		               sprintf(downflow,"%0.3fKB",atoll(tempRow[2])/1024.00);
		             }
								 sprintf(caItem,"%s",tempRow[0]);						 
			           lt_dbput_recordvars(tablePtr,6,
				           "stime",LT_TYPE_STRING,tempRow[0],
				           "upflow",LT_TYPE_STRING,upflow,
				           "downflow",LT_TYPE_STRING,downflow,
					 				 "tcpcon",LT_TYPE_STRING,tempRow[3],
				           "udpcon",LT_TYPE_STRING,tempRow[4],
				           "online",LT_TYPE_STRING,tempRow[5]
			           );          
						     lUbytes=atoll(tempRow[2])/1024;
				         lDbytes=atoll(tempRow[3])/1024;		         
					       if( lMaxBytes <= (lUbytes + lDbytes) ) {
					           lMaxBytes = lUbytes + lDbytes+5;
					       }			       
			           if(Max2<atoll(tempRow[5])) Max2=atoll(tempRow[5]+5);
			            
						 		 if( (j%3)==0 ){
					          sprintf(caTemp,"%s,%llu,%llu,%llu,\r\n",caItem,lUbytes+lDbytes,lDbytes,lUbytes);
					          write(srcfd1, caTemp, strlen(caTemp));
					       }else{
					      		sprintf(caTemp,"%s,%llu,%llu,%llu \r\n","",lUbytes+lDbytes,lDbytes,lUbytes);
					        	write(srcfd1, caTemp, strlen(caTemp));
					       }		       
					       j++;
					       //��Ա����
			      		 sprintf(caTemp1,"%s,%llu \r\n","",atoll(tempRow[5]));
			        	 write(srcfd2, caTemp1, strlen(caTemp));
			    	}else if(step==2){
			    		   char srvname[128];
			    			 if(atoll(tempRow[1])>1024000){
			             sprintf(flow,"%0.3fM",atoll(tempRow[1])/1024000.00);
			           }else{
			             sprintf(flow,"%0.3fKB",atoll(tempRow[1])/1024.00);
			           }
			           sprintf(srvname,"%s",_ltPubInfo->topSrvName[atoi(tempRow[0])].srvname);
			           lt_dbput_recordvars(tablePtr,3,
			           "srvname",LT_TYPE_STRING,srvname,
			           "srvtime",LT_TYPE_STRING,time2str(atoi(tempRow[2])),
				 				 "srvflow",LT_TYPE_STRING,flow);
			    	}else if(step==3){
			    		   char gname[128];
			    		   tablePtr=lt_dbput_table(dbPtr,"list1");
			    			 if(atoll(tempRow[0])>1024000){
			             sprintf(flow,"%0.3fM",atoll(tempRow[0])/1024000.00);
			           }else{
			             sprintf(flow,"%0.3fKB",atoll(tempRow[0])/1024.00);
			           }
			           if(strcmp(tempRow[0],"")!=0){
					       	 sprintf(gname,"%s",_ltPubInfo->_GroupList[atoi(tempRow[2])].name);
			           }
			           lt_dbput_recordvars(tablePtr,3,
			           "gname",LT_TYPE_STRING,gname,
			           "allflow",LT_TYPE_STRING,flow,
				 				 "ctime",LT_TYPE_STRING,tempRow[1]);
				 				 //��ͼ
				 				 sprintf(caTemp,"%s,%s \r\n",gname,flow);
			       		 write(srcfd1, caTemp, strlen(caTemp));
			    	}else if(step==4){
			    			 if(atoll(tempRow[2])>1024000){
			             sprintf(flow,"%0.3fM",atoll(tempRow[2])/1024000.00);
			           }else{
			             sprintf(flow,"%0.3fKB",atoll(tempRow[2])/1024000.00);
			           }
			           char sortname[128],numchar[32];
			           sprintf(sortname,"%s",_ltPubInfo->ltService[atoi(tempRow[1])].srvName);
			           sprintf(numchar,"%d",num);
			           lt_dbput_recordvars(tablePtr,5,
			           "num",LT_TYPE_STRING,numchar,
			           "sortname",LT_TYPE_STRING,sortname,
			           "webhost",LT_TYPE_STRING,tempRow[0],
			           "ctimes",LT_TYPE_STRING,time2str(atoi(tempRow[3])),
				 				 "flow",LT_TYPE_STRING,flow);
			    	}else if(step==5){
			    			 if(atoll(tempRow[1])>1024000){
			             sprintf(flow,"%0.3fM",atoll(tempRow[1])/1024000.00);
			           }else{
			             sprintf(flow,"%0.3fKB",atoll(tempRow[1])/1024.00);
			           }
			           char numchar[32];
			           sprintf(numchar,"%d",num);
			           lt_dbput_recordvars(tablePtr,5,
			           "num",LT_TYPE_STRING,numchar,
			           "dip",LT_TYPE_STRING,tempRow[0],
			           "ctimes",LT_TYPE_STRING,tempRow[2],
			           "otime",LT_TYPE_STRING,time2str(atoi(tempRow[3])),
				 				 "flow",LT_TYPE_STRING,flow);	
			    	}
			    	num++;
			    	tempRow= ltDbFetchRow(tempCursor);
		    }
	     ltDbCloseCursor(tempCursor);
    }   
    if(step==1){		    
			    close(srcfd1);	 
			    close(srcfd2);			    
			    memset(caTempFile,0,sizeof(caTempFile));
			    sprintf(caTempFile,"%sflowview.gif",caTempDir);	
			    sprintf(caTemp,"%s/Scripts/outflowplt.pl   %s %s %llu ",_msahtmldir,caTempDataDir1,caTempFile,lMaxBytes);
			    system(caTemp);			    	
					memset(caTempFile,0,sizeof(caTempFile));
			    sprintf(caTempFile,"%sonlineuser.gif",caTempDir);
			    sprintf(caTemp,"%s/Scripts/outflowpltline.pl   %s %s %u ",_msahtmldir,caTempDataDir2,caTempFile,Max2);
			    system(caTemp);	  
			    lt_dbput_rootvars(dbPtr,1,"file1","flowview.gif");	  
			    lt_dbput_rootvars(dbPtr,1,"file2","onlineuser.gif"); 
			    lt_dbput_rootvars(dbPtr,3,"reportname",reportname,"bdate",caSdate1,"edate",caSdate2);
    }else if(step==3){
    			close(srcfd1);	 	    
			    memset(caTempFile,0,sizeof(caTempFile));
			    unsigned int Max = 10000;
				  sprintf(caTempFile,"%s/groupPie.gif",caTempDir);
				  sprintf(caTemp,"%s/Scripts/onlinesrv1_s.pl   %s %s %u ",_msahtmldir,caTempDataDir1,caTempFile,Max);
				  system(caTemp);
				  lt_dbput_rootvars(dbPtr,1,"file","groupPie.gif"); 	    	
    }
   	char  *lt_page_content;
	  int   iFd;
	  char  modelpath[128];
	  memset(modelpath,0,sizeof(modelpath));
	  sprintf(modelpath,"%s%s/step%d.htm",_msahtmldir,_sysmodeldir,step);
	  printf("modelpath:%s\n",modelpath);
    lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
    if(lt_page_content==NULL){
            sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
            system(caLabel);/*����Ŀ¼�����ڴ����־*/
            ltMsgFree(ltMsgPk);
            lt_dbfree(dbPtr);
            return 0;
  	}else{
		        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
		        if(step==1){
		        	sprintf(caLabel,"%sindex.htm",caTempDir);
		        }else{
		        	sprintf(caLabel,"%sstep%d.htm",caTempDir,step);
		        }	 
		        printf("caLabel:%s\n",caLabel);       
		        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
		        if(iFd >0) {
		            write(iFd,lt_page_content,strlen(lt_page_content));
		        }
		        close(iFd);
  	}  	
  	if(step==5){
	    sprintf(caLabel,"%s/Scripts/html2mail  %s index.htm %sindex.mht report %s",_msahtmldir,caTempDir,caTempDir,email);
	    system(caLabel);
    }
    chdir(caTempDir);
    system("rm -f report.tgz"); 
	  system("tar -cvzf report.tgz *");  	  
	  sprintf(caLabel,"/bin/rm  %sproccess.ini",caTempDir);
	  system(caLabel);    
	  sprintf(caLabel,"/bin/rm  %serrmsg.ini",caTempDir);
	  system(caLabel);   
	  ltMsgPk->msgpktype=1;
	  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,responseDir);
	  ltMsgFree(ltMsgPk);
	  return 0;
}



//������շ���
int riskstep1(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
	
		char caSdate[32],caEdate[32],caSdate2[32],caSdate1[32],name[32];
		char caLabel[256],caTempDir[256],sqlBuf[1024],email[32],index[16];
		long lTime;
		int j,num;
	 	unsigned int time1,time2;
		char sortname[128],numchar[8];
		char sDate[64],sTime[64];
		memset(sDate,0,sizeof(sDate));
		memset(sTime,0,sizeof(sTime));
		memset(caSdate,0,sizeof(caSdate));
		memset(caEdate,0,sizeof(caEdate));
		memset(caSdate2,0,sizeof(caSdate2));
		memset(caSdate1,0,sizeof(caSdate1));
		memset(sqlBuf,0,sizeof(sqlBuf));
		memset(email,0,sizeof(email));
		memset(name,0,sizeof(name));	
		memset(caTempDir,0,sizeof(caTempDir));
		memset(index,0,sizeof(index));
		j=0;
	 	ltDbCursor *tempCursor;
		LT_DBROW tempRow;
		ltDbHeadPtr dbPtr;
		ltTablePtr  tablePtr1;
		ltTablePtr  tablePtr2;
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon!=NULL){
			printf("db connect ok\n");
		}else{
			fprintf(stderr,"db connect error\n");
		}
    		
		dbPtr=lt_dbinit();
    tablePtr1=lt_dbput_table(dbPtr,"list1");
    tablePtr2=lt_dbput_table(dbPtr,"list2");
		lt_db_htmlpage(dbPtr,"utf-8");
		if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
				  sprintf(caSdate,"%s","");
	  }else{
	    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
	  }
	  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
				  sprintf(caEdate,"%s","");
	  }else{
	    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
	  }
		if( ltMsgGetVar_s(ltMsgPk,"email")==NULL){
				  sprintf(email,"%s","");
	  }else{
	    		sprintf(email,"%s",ltMsgGetVar_s(ltMsgPk,"email"));
	  }
		if( ltMsgGetVar_s(ltMsgPk,"reportname")==NULL){
				  sprintf(name,"%s","");
	  }else{
	    		sprintf(name,"%s",ltMsgGetVar_s(ltMsgPk,"reportname"));
	  }
	  
	  
	  //���ڴ���
	  lTime = time(0);
    if(!ltStrIsSpaces(caSdate)) {
        time1 = nasCvtLongTime(caSdate,"00:00:00");
    }else{
        time1 = 0;
    } 
    if(!ltStrIsSpaces(caEdate)) {
        time2 = nasCvtLongTime(caEdate,"23:59:59");
    }else {
        time2 = 0;
    } 
    
    if(time1 == 0) {
         time1 = lTime;       
    }
	  if(time2 == 0) {
         time2 = lTime;
    }
    
	  if(time1 > lTime){//�����ʼʱ��ȵ�ǰʱ�����ʼ���ڵ�ǰʱ��
         time1 = lTime;
    }
    if(time2>lTime){//�����ֹʱ��ȵ�ǰʱ������ֹʱ����ڵ�ǰʱ��
		 		 time2 = lTime;
	  }
	  
	  
	  sprintf(index,"%lu",ltStrGetId());
	  sprintf(caTempDir,"%s/riskreport/%s/",_reportdir,index);
    if(ltFileIsExist(caTempDir)!=1) {
	        if(mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)!=0) {
            // ���ɸñ���Ŀ¼����
            ltMsgPk->msgpktype=1;
						lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"white\" >Error:�������ɴ���,�޷���������Ŀ¼!<br><a href=\"javascript:history.back(1);\" >�����±���?</a></body></html>");
						ltMsgFree(ltMsgPk);
            return 0;
	        }
   	}

   	char caCmd[256],infofile[128];
   	memset(caCmd,0,sizeof(caCmd));
   	memset(infofile,0,sizeof(infofile));
    int  fdwrite=0;
    sprintf(infofile,"%sinfo.ini",caTempDir);
    fdwrite = open(infofile, O_APPEND | O_WRONLY | O_CREAT, 0644);
		if(fdwrite == (-1)) {
			 ltMsgPk->msgpktype=1;
			 lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
			 ltMsgFree(ltMsgPk);
			 return 0;
		}		
		nasCvtStime(time(0),sDate,sTime); 
		sprintf(caCmd,"date=%s_%s\n",sDate,sTime);
	  write(fdwrite,caCmd,strlen(caCmd));
	  sprintf(caCmd,"reportname=%s\n",name);
	  write(fdwrite,caCmd,strlen(caCmd));
	  sprintf(caCmd,"email=%s\n",email);
	  write(fdwrite,caCmd,strlen(caCmd));
	  close(fdwrite); 
    sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/reportplt/risklineplt/banner.jpg %s",caTempDir);
	  system(caLabel);
	  sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/reportplt/risklineplt/right-top.jpg  %s",caTempDir);
	  system(caLabel);
	  sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/reportplt/risklineplt/banner.jpg  %s",caTempDir);
	  system(caLabel);
	  sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/reportplt/risklineplt/up-1.jpg  %s",caTempDir);
	  system(caLabel);
	  sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/reportplt/risklineplt/up-2.jpg  %s",caTempDir);
	  system(caLabel);
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/reportplt/risklineplt/up-3.jpg  %s",caTempDir);
	  system(caLabel);

	  char flow[32];
	  num=0;
	  nasTimeGetDate(caSdate1,time1);
    nasTimeGetDate(caSdate2,time2);
		sprintf(sqlBuf,"select cast(avg(bytes) as dec(18,3)) as flow,cast(avg(lcount) as dec(18,0)) as lcount,cast(avg(ctime) as dec(18,0)) as ctime,urlsort from msahttpreport where sdate>='%s' and sdate<='%s'group by urlsort order by flow desc",caSdate1,caSdate2);
    printf("SQL %s \n",sqlBuf);
    tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor!=NULL){
		    tempRow= ltDbFetchRow(tempCursor);
	    	while(tempRow!=NULL){
	    			 num++;
		   		   memset(flow,0,sizeof(flow));
		   		   memset(sortname,0,sizeof(sortname));
		   		   if(atoll(tempRow[0])>1024000){
               sprintf(flow,"%0.3fM",atoll(tempRow[0])/1024000.00);
             }else{
               sprintf(flow,"%0.3fKB",atoll(tempRow[0])/1024.00);
             }
           	 sprintf(sortname,"%s",_ltPubInfo->ltService[atoi(tempRow[3])].srvName);
             sprintf(numchar,"%d",num);
	           lt_dbput_recordvars(tablePtr1,5,
           	 "num",LT_TYPE_STRING,numchar,
	           "flow",LT_TYPE_STRING,flow,
	           "lcount",LT_TYPE_STRING,tempRow[1],
		 				 "ctime",LT_TYPE_STRING,tempRow[2],
	           "sortname",LT_TYPE_STRING,sortname);
		 				 if(num>=_MAXRERORD){
		 				 		break;
		 				 }
		    	   tempRow= ltDbFetchRow(tempCursor);
		    }
	     ltDbCloseCursor(tempCursor);
    }
    
    //�����������
    memset(sqlBuf,0,sizeof(sqlBuf));
    num=0;
    sprintf(sqlBuf,"select cast(avg(bytes) as dec(18,3)) as flow,cast(avg(lcount) as dec(18,0)) as lcount,cast(avg(ctime) as dec(18,0)) as ctime,urlsort from msahttpreport where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s' group by urlsort order by lcount desc",caSdate1,caSdate2);
    printf("SQL %s \n",sqlBuf);
    tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor!=NULL){
		    tempRow= ltDbFetchRow(tempCursor);
	    	while(tempRow!=NULL){
	    			 num++;
		   		   memset(flow,0,sizeof(flow));
		   		   memset(sortname,0,sizeof(sortname));
		   		   if(atoll(tempRow[0])>1024000){
               sprintf(flow,"%0.3fM",atoll(tempRow[0])/1024000.00);
             }else{
               sprintf(flow,"%0.3fKB",atoll(tempRow[0])/1024.00);
             }
           	 sprintf(sortname,"%s",_ltPubInfo->ltService[atoi(tempRow[3])].srvName);
             sprintf(numchar,"%d",num);
	           lt_dbput_recordvars(tablePtr2,5,
           	 "num",LT_TYPE_STRING,numchar,
	           "flow",LT_TYPE_STRING,flow,
	           "lcount",LT_TYPE_STRING,tempRow[1],
		 				 "ctime",LT_TYPE_STRING,tempRow[2],
	           "sortname",LT_TYPE_STRING,sortname);
		 				 if(num>=_MAXRERORD){
		 				 		break;
		 				 }
		    	 	 tempRow= ltDbFetchRow(tempCursor);
		    }
	     ltDbCloseCursor(tempCursor);
    }
    
    lt_dbput_rootvars(dbPtr,3,"reportname",name,"bdate",caSdate1,"edate",caSdate2);
    
   	char  *lt_page_content;
	  int   iFd;
	  char  modelpath[128];
	  memset(modelpath,0,sizeof(modelpath));
	  sprintf(modelpath,"%sstep1.htm",_riskmodeldir);
    lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
    if(lt_page_content==NULL){
            sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
            system(caLabel);/*����Ŀ¼�����ڴ����־*/
            ltMsgFree(ltMsgPk);
            lt_dbfree(dbPtr);
            return 0;
  	}else{
		        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
		        sprintf(caLabel,"%sindex.htm",caTempDir);
		        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
		        if(iFd >0) {
		            write(iFd,lt_page_content,strlen(lt_page_content));
		        }
		        close(iFd);
		      	/*����html��ʽ����*/
  	}
	  sprintf(caLabel,"/bin/rm  %sproccess.ini",caTempDir);
	  system(caLabel);
	  sprintf(caLabel,"/bin/rm  %serrmsg.ini",caTempDir);
	  system(caLabel);

		chdir(caTempDir);
	  system("tar -cvzf report.tgz *.htm *.gif *.jpg");
	  ltMsgPk->msgpktype=1;
	  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,index);
	  ltMsgFree(ltMsgPk);
	  return 0;
}





//��Ա��������
int riskstep2(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
	char sqlBuf[1024];
	char caTempDir[256],caLabel[128],caSdate[32],caEdate[32],numchar[8];
	int num;
 	unsigned int time1,time2,stime;
	char flow[32];
	memset(sqlBuf,0,sizeof(sqlBuf));
	memset(caTempDir,0,sizeof(caTempDir));
	memset(caLabel,0,sizeof(caLabel));
	memset(caSdate,0,sizeof(caSdate));
	memset(caEdate,0,sizeof(caEdate));
	num=0;
 	stime=0;
 	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	ltDbHeadPtr dbPtr;
	ltTablePtr  tablePtr;
	
	 //�������ݿ�
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon!=NULL){
			printf("db connect ok\n");
		}else{
			fprintf(stderr,"db connect error\n");
		}
    
	
	dbPtr=lt_dbinit();
  tablePtr=lt_dbput_table(dbPtr,"list");
	lt_db_htmlpage(dbPtr,"utf-8");

	if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
			  sprintf(caSdate,"%s","");
  }else{
    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
  }
  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
			  sprintf(caEdate,"%s","");
  }else{
    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
  }
  time1 = nasCvtLongTime(caSdate,"00:00:00");
  time2 = nasCvtLongTime(caEdate,"23:59:59");
  sprintf(caTempDir,"%s/riskreport/%ld",_reportdir,atol(ltMsgGetVar_s(ltMsgPk,"index")));
  printf("caTempDir   %s \n",caTempDir);
	sprintf(sqlBuf,"select cast(avg(msauserhttpreport.bytes) as dec(18,3)) as flow,cast(avg(msauserhttpreport.lcount) as dec(18,0)) as lcount,cast(avg(msauserhttpreport.ctime) as dec(18,0)) as ctime,msauser.dispname from msauserhttpreport left join msauser on msauserhttpreport.userid=msauser.userid where msauserhttpreport.sdate<'%s' and msauserhttpreport.sdate>'%s' group by msauser.dispname order by flow desc",caEdate,caSdate);
  printf("||||||SQL %s \n",sqlBuf);
  tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
  if(tempCursor!=NULL){
	    tempRow= ltDbFetchRow(tempCursor);
    	while(tempRow!=NULL){
    			 num++;
	   		   memset(flow,0,sizeof(flow));
	   		   if(atoll(tempRow[0])>1024000){
             sprintf(flow,"%0.3fM",atoll(tempRow[0])/1024000.00);
           }else{
             sprintf(flow,"%0.3fKB",atoll(tempRow[0])/1024.00);
           }
           sprintf(numchar,"%d",num);
           lt_dbput_recordvars(tablePtr,5,
           "num",LT_TYPE_STRING,numchar,
           "name",LT_TYPE_STRING,tempRow[3],
           "ctime",LT_TYPE_STRING,tempRow[2],
	 				 "lcount",LT_TYPE_STRING,tempRow[1],
	 				 "flow",LT_TYPE_STRING,flow);
	 				 if(num>=_MAXRERORD){
	 				 		break;
	 				 }
		    	 tempRow= ltDbFetchRow(tempCursor);
	    }
      ltDbCloseCursor(tempCursor);
  }

 	char  *lt_page_content;
  int   iFd;
  char  modelpath[128];
  memset(modelpath,0,sizeof(modelpath));
  sprintf(modelpath,"%sstep2.htm",_riskmodeldir);
  lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
  if(lt_page_content==NULL){
          sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
          system(caLabel);/*����Ŀ¼�����ڴ����־*/
          ltMsgFree(ltMsgPk);
          lt_dbfree(dbPtr);
          return 0;
	}else{
	        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
	        sprintf(caLabel,"%s/step2.htm",caTempDir);
	        printf("caLabel    %s \n",caLabel);
	        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
	        if(iFd >0) {
	            write(iFd,lt_page_content,strlen(lt_page_content));
	        }
	        close(iFd);
	      	/*����html��ʽ����*/
	}
	chdir(caTempDir);
  system("tar -cvzf report.tgz *.htm *.gif *.jpg");
  ltMsgPk->msgpktype=1;
  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
  ltMsgFree(ltMsgPk);
  return 0;
}




//p2p����Ƶ����top50��Ա
int riskstep3(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
	char sqlBuf[1024];
	char caTempDir[256],caLabel[128],caSdate[32],caEdate[32],numchar[8];
	int num;
 	unsigned int time1,time2,stime;
	char flow[32];
	memset(sqlBuf,0,sizeof(sqlBuf));
	memset(caTempDir,0,sizeof(caTempDir));
	memset(caLabel,0,sizeof(caLabel));
	memset(caSdate,0,sizeof(caSdate));
	memset(caEdate,0,sizeof(caEdate));
	num=0;
 	stime=0;
 	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	ltDbHeadPtr dbPtr;
	ltTablePtr  tablePtr;
	
	 //�������ݿ�
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon!=NULL){
			printf("db connect ok\n");
		}else{
			fprintf(stderr,"db connect error\n");
		}
    
	
	dbPtr=lt_dbinit();
  tablePtr=lt_dbput_table(dbPtr,"list");
	lt_db_htmlpage(dbPtr,"utf-8");

	if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
			  sprintf(caSdate,"%s","");
  }else{
    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
  }
  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
			  sprintf(caEdate,"%s","");
  }else{
    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
  }
  time1 = nasCvtLongTime(caSdate,"00:00:00");
  time2 = nasCvtLongTime(caEdate,"23:59:59");
  sprintf(caTempDir,"%s/riskreport/%ld",_reportdir,atol(ltMsgGetVar_s(ltMsgPk,"index")));
  printf("caTempDir   %s \n",caTempDir);
	sprintf(sqlBuf,"select cast(avg(msauserhttpreport.bytes) as dec(18,3)) as flow,cast(avg(msauserhttpreport.lcount) as dec(18,0)) as lcount,cast(avg(msauserhttpreport.ctime) as dec(18,0)) as ctime,msauser.dispname from msauserhttpreport left join msauser on msauserhttpreport.userid=msauser.userid where msauserhttpreport.sdate<'%s' and msauserhttpreport.sdate>'%s' and urlsort=%d or urlsort=%d group by msauser.dispname order by flow desc",caEdate,caSdate,_p2pUrlSort,_videoUrlSort);
  printf("||||||SQL %s \n",sqlBuf);
  tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
  if(tempCursor!=NULL){
	    tempRow= ltDbFetchRow(tempCursor);
    	while(tempRow!=NULL){
    			 num++;
	   		   memset(flow,0,sizeof(flow));
	   		   if(atoll(tempRow[0])>1024000){
             sprintf(flow,"%0.3fM",atoll(tempRow[0])/1024000.00);
           }else{
             sprintf(flow,"%0.3fKB",atoll(tempRow[0])/1024.00);
           }
           sprintf(numchar,"%d",num);
           lt_dbput_recordvars(tablePtr,5,
           "num",LT_TYPE_STRING,numchar,
           "name",LT_TYPE_STRING,tempRow[3],
           "ctime",LT_TYPE_STRING,tempRow[2],
	 				 "lcount",LT_TYPE_STRING,tempRow[1],
	 				 "flow",LT_TYPE_STRING,flow);
	 				 if(num>=50){
	 				 		break;
	 				 }
		    	 tempRow= ltDbFetchRow(tempCursor);
	    }
      ltDbCloseCursor(tempCursor);
  }

 	char  *lt_page_content;
  int   iFd;
  char  modelpath[128];
  memset(modelpath,0,sizeof(modelpath));
  sprintf(modelpath,"%sstep3.htm",_riskmodeldir);
  lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
  if(lt_page_content==NULL){
          sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
          system(caLabel);/*����Ŀ¼�����ڴ����־*/
          ltMsgFree(ltMsgPk);
          lt_dbfree(dbPtr);
          return 0;
	}else{
	        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
	        sprintf(caLabel,"%s/step3.htm",caTempDir);
	        printf("caLabel    %s \n",caLabel);
	        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
	        if(iFd >0) {
	            write(iFd,lt_page_content,strlen(lt_page_content));
	        }
	        close(iFd);
	      	/*����html��ʽ����*/
	}
	chdir(caTempDir);
  system("tar -cvzf report.tgz *.htm *.gif *.jpg");
  ltMsgPk->msgpktype=1;
  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
  ltMsgFree(ltMsgPk);
  return 0;
}



//�ǹ�����վ��������top50��Ա
int riskstep4(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
	char sqlBuf[1024];
	char caTempDir[256],caLabel[128],caSdate[32],caEdate[32],numchar[8];
	int num;
 	unsigned int time1,time2,stime;
	char flow[32],gname[64],ctime[64];
	memset(sqlBuf,0,sizeof(sqlBuf));
	memset(caTempDir,0,sizeof(caTempDir));
	memset(caLabel,0,sizeof(caLabel));
	memset(caSdate,0,sizeof(caSdate));
	memset(caEdate,0,sizeof(caEdate));
	num=0;
 	stime=0;
 	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	ltDbHeadPtr dbPtr;
	ltTablePtr  tablePtr;
	
	 //�������ݿ�
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon!=NULL){
			printf("db connect ok\n");
		}else{
			fprintf(stderr,"db connect error\n");
		}
    
	
	dbPtr=lt_dbinit();
  tablePtr=lt_dbput_table(dbPtr,"list");
	lt_db_htmlpage(dbPtr,"utf-8");
	if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
			  sprintf(caSdate,"%s","");
  }else{
    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
  }
  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
			  sprintf(caEdate,"%s","");
  }else{
    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
  }
  time1 = nasCvtLongTime(caSdate,"00:00:00");
  time2 = nasCvtLongTime(caEdate,"23:59:59");
  sprintf(caTempDir,"%s/riskreport/%ld",_reportdir,atol(ltMsgGetVar_s(ltMsgPk,"index")));
  printf("caTempDir   %s \n",caTempDir);
	sprintf(sqlBuf,"select userid,sum(bytes)as flow,sum(ctime)as ctime from msauserhttpreport where sdate<='%s' and sdate>='%s' group by userid order by flow desc",caEdate,caSdate);
  printf("||||||SQL %s \n",sqlBuf);
  tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	nasDbUserInfo *tmpdbuserinfo;
  if(tempCursor!=NULL){
	    tempRow= ltDbFetchRow(tempCursor);
    	while(tempRow!=NULL){
    			 num++;
	   		   memset(flow,0,sizeof(flow));
	   		   if(atoll(tempRow[1])>1024000){
             sprintf(flow,"%0.3fM",atoll(tempRow[1])/1024000.00);
           }else{
             sprintf(flow,"%0.3fKB",atoll(tempRow[1])/1024.00);
           }
	 		 		 tmpdbuserinfo=msaLookUpDbUserById(_ltPubInfo,atoi(tempRow[0]));
	 		 		 //���Ŵ���
	   		   memset(gname,0,sizeof(gname));
	   		   sprintf(gname,"%s",_ltPubInfo->_GroupList[0].name);
	 		 		 int j;
	 		 		 for(j=0;j<5;j++){
	 		 		 		if(tmpdbuserinfo->groupid[j]!=0){
	 		 		 			sprintf(gname,"%s",_ltPubInfo->_GroupList[tmpdbuserinfo->groupid[j]].name);
	 		 		 		}
	 		 		 }
	 		 		 //ʱ��
	   		   memset(ctime,0,sizeof(ctime));
					 nasTimeGetTime(ctime,atol(tempRow[2]));

           sprintf(numchar,"%d",num);
           lt_dbput_recordvars(tablePtr,5,
           "num",LT_TYPE_STRING,numchar,
           "group",LT_TYPE_STRING,gname,
           "name",LT_TYPE_STRING,tmpdbuserinfo->dispname,
           "flow",LT_TYPE_STRING,flow,
	 				 "ctime",LT_TYPE_STRING,ctime);
	 				 if(num>=20){
	 				 		break;
	 				 }
		    	 tempRow= ltDbFetchRow(tempCursor);
	    }
      ltDbCloseCursor(tempCursor);
  }

 	char  *lt_page_content;
  int   iFd;
  char  modelpath[128];
  memset(modelpath,0,sizeof(modelpath));
  sprintf(modelpath,"%sstep4.htm",_riskmodeldir);
  lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
  if(lt_page_content==NULL){
          sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
          system(caLabel);/*����Ŀ¼�����ڴ����־*/
          ltMsgFree(ltMsgPk);
          lt_dbfree(dbPtr);
          return 0;
	}else{
	        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
	        sprintf(caLabel,"%s/step4.htm",caTempDir);
	        printf("caLabel    %s \n",caLabel);
	        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
	        if(iFd >0) {
	            write(iFd,lt_page_content,strlen(lt_page_content));
	        }
	        close(iFd);
	      	/*����html��ʽ����*/
	}
	chdir(caTempDir);
  system("tar -cvzf report.tgz *.htm *.gif *.jpg");
  ltMsgPk->msgpktype=1;
  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
  ltMsgFree(ltMsgPk);
  return 0;
}



//�ǹ�����վ��������top50��Ա������
typedef struct username_s {
    char     name[32];
}username;

int riskstep5(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
	username  _username[20];
	char sqlBuf[1024];
	char caTempDir[256],caLabel[128],caSdate[32],caEdate[32],ctime[32],gname[32],sortname[32],uname[32];
	int num,i,iii,index;
 	unsigned int time1,time2;
	char numchar[8],caTempDataDir[128],caTempFile[128];
  
	memset(sqlBuf,0,sizeof(sqlBuf));
	memset(caTempDir,0,sizeof(caTempDir));
	memset(caTempDataDir,0,sizeof(caTempDataDir));
	memset(caTempFile,0,sizeof(caTempFile));
	memset(caLabel,0,sizeof(caLabel));
	memset(caSdate,0,sizeof(caSdate));
	memset(caEdate,0,sizeof(caEdate));
	
	num=0;
	index=0;
 	ltDbCursor *tempCursor;
	nasDbUserInfo *tmpdbuserinfo;
	LT_DBROW tempRow;
	ltDbHeadPtr dbPtr;
	
	 //�������ݿ�
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon!=NULL){
			printf("db connect ok\n");
		}else{
			fprintf(stderr,"db connect error\n");
		}
    
	
	dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8");
	
	int userid[20];
	ltTablePtr  tablePtr[20];
	char tablename[16];
	for(iii=0;iii<20;iii++){
			memset(tablename,0,sizeof(tablename));
			sprintf(tablename,"list%d",iii);
  		tablePtr[iii]=lt_dbput_table(dbPtr,tablename);
	  	userid[iii]=-1;
	}
	
	if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
			  sprintf(caSdate,"%s","");
  }else{
    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
  }

  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
			  sprintf(caEdate,"%s","");
  }else{
    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
  }
  time1 = nasCvtLongTime(caSdate,"00:00:00");
  time2 = nasCvtLongTime(caEdate,"23:59:59");
  sprintf(caTempDir,"%s/riskreport/%ld",_reportdir,atol(ltMsgGetVar_s(ltMsgPk,"index")));

	sprintf(sqlBuf,"select msauser.dispname,sum(msauserhttpreport.bytes)as flow,msauserhttpreport.userid from msauserhttpreport left join msauser on msauser.userid=msauserhttpreport.userid where msauserhttpreport.sdate<='%s' and msauserhttpreport.sdate>='%s' group by msauser.dispname,msauserhttpreport.userid order by flow desc",caEdate,caSdate);
	printf("SQL:  %s \n",sqlBuf);
  tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
  if(tempCursor!=NULL){
	    tempRow= ltDbFetchRow(tempCursor);
    	while(tempRow!=NULL){
		    	 sprintf(_username[num].name,"%s",tempRow[0]);
		    	 userid[num]=atoi(tempRow[2]);
		    	 num++;
		    	 tempRow= ltDbFetchRow(tempCursor);
	    }
      ltDbCloseCursor(tempCursor);
  }
  int j;
	for(i=0;i<num;i++){
			index=0;
		  tmpdbuserinfo=msaLookUpDbUserById(_ltPubInfo,userid[i]);
		  //���Ŵ���
	    memset(gname,0,sizeof(gname));
	    sprintf(gname,"%s",_ltPubInfo->_GroupList[0].name);
		  for(j=0;j<5;j++){
			 		if(tmpdbuserinfo->groupid[j]!=0){
			 			sprintf(gname,"%s",_ltPubInfo->_GroupList[tmpdbuserinfo->groupid[j]].name);
			 		}
		  }
		  //�û���
	    memset(uname,0,sizeof(uname));
	    sprintf(uname,"username%d",i);
			lt_dbput_rootvars(dbPtr,1,uname,_username[i].name);
			
			memset(sqlBuf,0,sizeof(sqlBuf));
			sprintf(sqlBuf,"select host,urlsort,sum(ctime) as ctime,sum(bytes) as flow from msauserhttpreport where userid=%d and msauserhttpreport.sdate<='%s' and msauserhttpreport.sdate>='%s' group by host,urlsort order by flow desc",userid[i],caEdate,caSdate);
			printf("SQL2:  %s \n",sqlBuf);
		  tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
		  if(tempCursor!=NULL){
			    tempRow= ltDbFetchRow(tempCursor);
		    	while(tempRow!=NULL){
							 index++;
							 sprintf(numchar,"%d",index);
							 //ʱ��
							 memset(ctime,0,sizeof(ctime));
							 nasTimeGetTime(ctime,atol(tempRow[2]));
							 //URL����
							 memset(sortname,0,sizeof(sortname));
							 sprintf(sortname,"%s",_ltPubInfo->ltService[atoi(tempRow[1])].srvName);
							 lt_dbput_recordvars(tablePtr[i],6,
			           "iIndex",LT_TYPE_STRING,numchar,
			           "groupname",LT_TYPE_STRING,gname,
			           "uname",LT_TYPE_STRING,_username[i].name,
				 				 "host",LT_TYPE_STRING,tempRow[0],
				 				 "urlsort",LT_TYPE_STRING,sortname,
				 				 "contime",LT_TYPE_STRING,ctime);
			 				 if(index>=10){
			 				 		break;
			 				 }
				    	 tempRow= ltDbFetchRow(tempCursor);
			    }
		      ltDbCloseCursor(tempCursor);
		  }
	}
 	char  *lt_page_content;
  int   iFd;
  char  modelpath[128];
  memset(modelpath,0,sizeof(modelpath));
  sprintf(modelpath,"%sstep5.htm",_riskmodeldir);
  lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
  if(lt_page_content==NULL){
          sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
          system(caLabel);/*����Ŀ¼�����ڴ����־*/
          ltMsgFree(ltMsgPk);
          lt_dbfree(dbPtr);
          return 0;
	}else{
	        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
	        sprintf(caLabel,"%s/step5.htm",caTempDir);
	        printf("caLabel    %s \n",caLabel);
	        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
	        if(iFd >0) {
	            write(iFd,lt_page_content,strlen(lt_page_content));
	        }
	        close(iFd);
	      	/*����html��ʽ����*/
	}
	chdir(caTempDir);
  system("tar -cvzf report.tgz *.htm *.gif *.jpg");
  ltMsgPk->msgpktype=1;
  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
  ltMsgFree(ltMsgPk);
  return 0;
}

//�Ʒѱ���
typedef struct userlist_s {
    int     userid;
    int     jftype;
    char    dispname[32];
    char    groupname[32];
}userlist;

static int sortuserlist(const void *p1,const void *p2)
{
    userlist *gname1,*gname2;
    gname1 = (userlist *)p1;
    gname2 = (userlist *)p2;
    return (gname2->groupname - gname1->groupname);
}


int jfreport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{	  
	  char caSdate[32],caEdate[32],sqlBuf[1024],email[32],caTime1[32],caSdate1[32],name[32];
		char caLabel[256],caTempDir[256],index[16],gname[32],tempstr[32],nowaccount[8],otime[32];
		long lTime;
		int i,j,num,lcount;
		int gid,level;
	 	unsigned int time1,time2;
	 	nasDbUserInfo *tmpdbuserinfo;
		memset(caSdate,0,sizeof(caSdate));
		memset(caEdate,0,sizeof(caEdate));
		memset(sqlBuf,0,sizeof(sqlBuf));
		memset(email,0,sizeof(email));
		memset(name,0,sizeof(name));
		memset(caTime1,0,sizeof(caTime1));
		memset(caSdate1,0,sizeof(caSdate1));
		memset(caTempDir,0,sizeof(caTempDir));
		memset(index,0,sizeof(index));
		memset(otime,0,sizeof(otime));
		j=0;
		i=0;
		lcount=1;
	 	ltDbCursor *tempCursor;
		LT_DBROW tempRow;
		ltDbHeadPtr dbPtr;
		ltTablePtr  tablePtr;
		
		 //�������ݿ�
  	char *dbUser;
	  char *dbPass;
	  char *dbName;
	  dbName=_ltPubInfo->_dbname;
		dbUser=_ltPubInfo->_dbuser;
		dbPass=_ltPubInfo->_dbpass;
		G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		if(G_DbCon!=NULL){
			printf("db connect ok\n");
		}else{
			fprintf(stderr,"db connect error\n");
		}
    
		
		dbPtr=lt_dbinit();
    tablePtr=lt_dbput_table(dbPtr,"list");
		lt_db_htmlpage(dbPtr,"utf-8");
		gid=atoi(ltMsgGetVar_s(ltMsgPk,"gid"));
		if( ltMsgGetVar_s(ltMsgPk,"sdate")==NULL){
				  sprintf(caSdate,"%s","");
	  }else{
	    		sprintf(caSdate,"%s",ltMsgGetVar_s(ltMsgPk,"sdate"));
	  }
	  if( ltMsgGetVar_s(ltMsgPk,"edate")==NULL){
				  sprintf(caEdate,"%s","");
	  }else{
	    		sprintf(caEdate,"%s",ltMsgGetVar_s(ltMsgPk,"edate"));
	  }
		if( ltMsgGetVar_s(ltMsgPk,"email")==NULL){
				  sprintf(email,"%s","");
	  }else{
	    		sprintf(email,"%s",ltMsgGetVar_s(ltMsgPk,"email"));
	  }
		if( ltMsgGetVar_s(ltMsgPk,"reportname")==NULL){
				  sprintf(name,"%s","");
	  }else{
	    		sprintf(name,"%s",ltMsgGetVar_s(ltMsgPk,"reportname"));
	  }
	  time1 = nasCvtLongTime(caSdate,"00:00:00");
	  time2 = nasCvtLongTime(caEdate,"23:59:59");
	  lTime=time(0);
	  nasCvtStime(lTime,caSdate1,caTime1);
	  sprintf(index,"%lu",ltStrGetId());
	  sprintf(caTempDir,"%s/jfreport/%s/",_reportdir,index);
    if(ltFileIsExist(caTempDir)!=1) {
	        if(mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)!=0) {
            // ���ɸñ���Ŀ¼����
            ltMsgPk->msgpktype=1;
						lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"white\" >Error:�������ɴ���,�޷���������Ŀ¼!<br><a href=\"javascript:history.back(1);\" >�����±���?</a></body></html>");
						ltMsgFree(ltMsgPk);
            return 0;
	        }
   	}

   	char caCmd[256],infofile[128];
   	memset(caCmd,0,sizeof(caCmd));
   	memset(infofile,0,sizeof(infofile));
    int  fdwrite=0;
    sprintf(infofile,"%sinfo.ini",caTempDir);
    fdwrite = open(infofile, O_APPEND | O_WRONLY | O_CREAT, 0644);
		if(fdwrite == (-1)) {
			 ltMsgPk->msgpktype=1;
			 lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
			 ltMsgFree(ltMsgPk);
			 return 0;
		}
		sprintf(caCmd,"date=%s_%s\n",caSdate1,caTime1);
	  write(fdwrite,caCmd,strlen(caCmd));
	  sprintf(caCmd,"reportname=%s\n",name);
	  write(fdwrite,caCmd,strlen(caCmd));
	  sprintf(caCmd,"email=%s\n",email);
	  write(fdwrite,caCmd,strlen(caCmd));
	  close(fdwrite);
	  
		sprintf(caLabel,"/bin/cp %sindex.htm  %s",_sysmodeldir,caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/images/banner.jpg  %s",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/images/right-top-d.jpg  %s",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/images/right-top.jpg  %s",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/    
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/images/up-1.jpg  %s",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/images/up-2.jpg  %s",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
		sprintf(caLabel,"/bin/cp /app/msa/msa/htmlplt/images/up-3.jpg  %s",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
		memset(sqlBuf,0,sizeof(sqlBuf));
    sprintf(sqlBuf,"select count(*) from (select count(*) from msaaccountreport where sdate>='%s' and sdate<='%s' group by userid) foo",caSdate,caEdate);
		printf("countSQL   %s  \n",sqlBuf);
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
		if(tempCursor){
			tempRow= ltDbFetchRow(tempCursor);
			if(tempRow){
				lcount=atoi(tempRow[0]);
			}
			ltDbCloseCursor(tempCursor);
		}
		//��ѯUSER
		userlist  _userlist[lcount];
	  char flow[32];
	  num=0;
	  level=_ltPubInfo->_GroupList[gid].level;
	  memset(sqlBuf,0,sizeof(sqlBuf));
		sprintf(sqlBuf,"select userid from msaaccountreport where sdate>='%s' and sdate<='%s' group by userid",caSdate,caEdate);
    printf("SQL %s \n",sqlBuf);
    tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor!=NULL){
		    tempRow= ltDbFetchRow(tempCursor);
	    	while(tempRow!=NULL){
	    			 tmpdbuserinfo=msaLookUpDbUserById(_ltPubInfo,atoi(tempRow[0]));
	    			 if(gid!=-1&&tmpdbuserinfo->groupid[level]!=gid){
			    			//���Ź���
		    	   		tempRow= ltDbFetchRow(tempCursor);
			    			continue;
	    			 }
					   //���Ŵ���
				     memset(gname,0,sizeof(gname));
				     sprintf(gname,"%s",_ltPubInfo->_GroupList[0].name);
					   for(j=0;j<5;j++){
						 		if(tmpdbuserinfo->groupid[j]!=0){
						 			sprintf(gname,"%s",_ltPubInfo->_GroupList[tmpdbuserinfo->groupid[j]].name);
						 		}
					   }
		    	 	 sprintf(_userlist[num].groupname,"%s",gname);
		    	 	 sprintf(_userlist[num].dispname,"%s",tmpdbuserinfo->dispname);
		   		   _userlist[num].userid=atoi(tempRow[0]);
		   		   _userlist[num].jftype=tmpdbuserinfo->jftype;
	    			 num++;
		    	   tempRow= ltDbFetchRow(tempCursor);
		    }
	     ltDbCloseCursor(tempCursor);
    }
    //��������
		qsort(_userlist,lcount,sizeof(userlist),sortuserlist);
    for(i=0;i<num;i++){
    		//�˻�����ѯ
    		memset(sqlBuf,0,sizeof(sqlBuf));
		    sprintf(sqlBuf,"select nowaccount from msaaccountreport where sdate>='%s' and userid=%d order by sdate asc,nowaccount desc",caSdate,_userlist[i].userid);
				printf("nowaccountSQL   %s  \n",sqlBuf);
				tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
				if(tempCursor){
					tempRow= ltDbFetchRow(tempCursor);
					if(tempRow){
						memset(nowaccount,0,sizeof(nowaccount));
						sprintf(nowaccount,"%s",tempRow[0]);
					}
					ltDbCloseCursor(tempCursor);
				}
    		//������ͳ��
    		memset(sqlBuf,0,sizeof(sqlBuf));
				sprintf(sqlBuf,"select sum(ubytes+dbytes) as flow,sum(onlinetime) as onlinetime,sum(account) as account from msaaccountreport where sdate>='%s' and sdate<='%s' and userid=%d group by userid",caSdate,caEdate,_userlist[i].userid);
		    printf("SQL%d %s \n",i,sqlBuf);
		    tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
		    if(tempCursor!=NULL){
				    tempRow= ltDbFetchRow(tempCursor);
			    	while(tempRow!=NULL){
				   		   memset(flow,0,sizeof(flow));
				   		   if(atoll(tempRow[0])>1024000){
		               sprintf(flow,"%0.3fM",atoll(tempRow[0])/1024000.00);
		             }else{
		               sprintf(flow,"%0.3fKB",atoll(tempRow[0])/1024.00);
		             }
							   //jftype�Ʒѷ�ʽ
							   switch(_userlist[i].jftype)
								 {
								      case 0:
								      memset(tempstr,0,sizeof(tempstr));
      								strgb2utf8("���Ʒ�",tempstr,strlen("���Ʒ�"));
								      break;
								      case 1:
								      memset(tempstr,0,sizeof(tempstr));
      								strgb2utf8("��ʱ�Ʒ�",tempstr,strlen("��ʱ�Ʒ�"));
								      break;
								      case 2:
								      memset(tempstr,0,sizeof(tempstr));
      								strgb2utf8("�������Ʒ�",tempstr,strlen("�������Ʒ�"));
								      break;
								      case 3:
								      memset(tempstr,0,sizeof(tempstr));
      								strgb2utf8("��ʱ��Ʒ�",tempstr,strlen("��ʱ��Ʒ�"));
								      break; 
								      case 4:
								      memset(tempstr,0,sizeof(tempstr));
      								strgb2utf8("Ԥ�������Ʒ�",tempstr,strlen("Ԥ�������Ʒ�"));
								      break;
								      case 5:
								      memset(tempstr,0,sizeof(tempstr));
      								strgb2utf8("Ԥ�������Ʒ�",tempstr,strlen("Ԥ�������Ʒ�"));
								      break;
								 }
								 //�Ʒ�ʱ��
								 nasTimeGetTime(otime,atol(tempRow[1]));
			           lt_dbput_recordvars(tablePtr,8,
		           	 "uname",LT_TYPE_STRING,_userlist[i].dispname,
			           "gname",LT_TYPE_STRING,_userlist[i].groupname,
			           "flow",LT_TYPE_STRING,flow,
				 				 "jftime",LT_TYPE_STRING,otime,
			           "jftype",LT_TYPE_STRING,tempstr,
			           "sum",LT_TYPE_STRING,tempRow[2],
			           "balance",LT_TYPE_STRING,nowaccount,
			           "payments",LT_TYPE_STRING,tempRow[2]);
				    	   tempRow= ltDbFetchRow(tempCursor);
				    }
			      ltDbCloseCursor(tempCursor);
		    }
    }
	  
    lt_dbput_rootvars(dbPtr,1,"sdate",caSdate);
    lt_dbput_rootvars(dbPtr,1,"edate",caEdate);
   	char  *lt_page_content;
	  int   iFd;
	  char  modelpath[128];
	  memset(modelpath,0,sizeof(modelpath));
	  sprintf(modelpath,"%sindex.htm","/app/msa/msa/htmlplt/reportplt/jfreportlt/");
    lt_page_content=ltPltFileParse(modelpath,dbPtr->doc,0);
    if(lt_page_content==NULL){
            sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
            system(caLabel);/*����Ŀ¼�����ڴ����־*/
            ltMsgFree(ltMsgPk);
            lt_dbfree(dbPtr);
            return 0;
  	}else{
		        lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
		        sprintf(caLabel,"%sindex.htm",caTempDir);
		        iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644);
		        if(iFd >0) {
		            write(iFd,lt_page_content,strlen(lt_page_content));
		        }
		        close(iFd);
		      	/*����html��ʽ����*/
  	}
	  sprintf(caLabel,"/bin/rm  %sproccess.ini",caTempDir);
	  system(caLabel);
	  sprintf(caLabel,"/bin/rm  %serrmsg.ini",caTempDir);
	  system(caLabel);

		chdir(caTempDir);
	  system("tar -cvzf report.tgz *.htm *.gif *.jpg");
	  ltMsgPk->msgpktype=1;
	  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");
	  ltMsgFree(ltMsgPk);
	  return 0;
	  
}
