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
#include <unistd.h>
#include <ctype.h>
#include <errno.h>     
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <asm/types.h>
#include <dirent.h>   
#include <stdarg.h>
#include "msa.h"   

char  gids[20];
char  userids[20];  
int   gid;
int   userid;
int   glevel;
char  element[256];
char  checkb[20];
int   deployscope;
char  reportname[120];
char  email[64];
char  language[4];
int   lang;
char  topusernum[32];
int   inttopusernum;   
char  caSdates[32],caEdates[32];
char  *dbUser;
char  *dbPass;
char  *dbName;
 
void catch_alarm(int signum)
{
	printf("signum:%d\n",signum);
	_exit(0);
}
  
 

/* ͳ������ */
int dailyReport(long tempIndex)
{ 
    char caSdate[32],caEdate[32];
    char sqlBuf[1024];
    long lTime,lTime1,lTime2,lTime0;
    char caSdate1[32],caTime1[32],caTime[32];
    char caSdate2[32],caTime2[32];
    char caTempDir[256];
    char reportnames[64];
    char caLabel[256];
    char *lt_page_content=NULL;
    int  iFd;
 
    char caTemp[18192];
    int  lStep;
    int  i,iMax; 
		char fileDate[32];  
    unsigned long iMaxItem;
    unsigned long long lUbytes,lDbytes,lMaxBytes;
    ltDbCursor *tempCursor;
    LT_DBROW tempRow;
    ltDbHeadPtr dbPtr;
    ltTablePtr tablePtr;
    char  caItem[128];
    char  caTempFile[256];
    int   iTemp;
		unsigned long long lMax;
		char  oldgname[128];
		char  egname[128];
		char  G_sdate[32];
    
    lTime=0;
    lTime1=0;
    lTime2=0;
    lTime0=0;
    lMaxBytes=0;
      
	printf("dailyReport start ....................\n");  
	if(deployscope==0){//ÿ�����ɱ��� 
			printf("deployscope==0");
			lTime = time(0)-3600*24 ;
			nasTimeGetDate(caSdate,lTime);
			sprintf(G_sdate,"%s",caSdate);
			sprintf(caEdate,"%s",caSdate);
			sprintf(reportnames,"%s-%s-daily",reportname,G_sdate);	
			lTime = time(0);
			lTime1 = nasCvtLongTime(caSdate,"00:00:01");
			lTime2 = nasCvtLongTime(caSdate,"23:59:59");
	}
	 
	if(deployscope==1){//ÿ��     
			printf("deployscope==1\n");
	    lTime = time(0);
    	nasTimeGetDate(caSdate,lTime-3600*24*6); //������Ϊһ�ܣ�3600�루һСʱ��*24��һ�죩*6��һ�ܣ�
    	nasTimeGetDate(caEdate,lTime);
    	sprintf(caSdate,"%s",caSdate);
    	sprintf(caEdate,"%s",caEdate);  	
    	sprintf(G_sdate,"%s",caEdate);  	
    	lTime1 = nasCvtLongTime(caSdate,"00:00:01");
			lTime2 = nasCvtLongTime(caEdate,"23:59:59");  	
			sprintf(reportnames,"%s-%s-weekly",reportname,G_sdate);	
	}
	 
	if(deployscope==2){//�������� 
			printf("deployscope==2\n");
			lTime = time(0);
			sprintf(caSdate,"%s",caSdates);
			sprintf(caEdate,"%s",caEdates);
		  sprintf(reportnames,"%s",reportname);
			lTime1 = nasCvtLongTime(caSdate,"00:00:01");
			lTime2 = nasCvtLongTime(caEdate,"23:59:59");
			nasTimeGetDate(caSdate,lTime1); 
			nasTimeGetDate(caEdate,lTime2);
			sprintf(G_sdate,"%s",caSdate);  
	}
	
	 
	printf("caSdate:%s\n",caSdate);//����ǰ���,��ôcaSdate,caEdate����ͬ ����ǰ��� ��ô��caSdate��ȥ�����ʱ��
	printf("caSdate:%s\n",caEdate);

    tempCursor=NULL;  
    if(deployscope==0){//ÿ�����ɱ��� 
			sprintf(caTempDir,"/datacenter/msa/report/dailyreport/%ld/",tempIndex);    
		}
		if(deployscope==1){//ÿ�� 
			sprintf(caTempDir,"/datacenter/msa/report/dailyreport/%ld/",tempIndex);
		}
		if(deployscope==2){//�ֶ����ɱ����б�
	    sprintf(caTempDir,"/datacenter/msa/report/instantreport/%ld/",tempIndex);
		}
	 
    
    
    if(ltFileIsExist(caTempDir)!=1) {
        if(mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)!=0) {
            printf("mkdir daily report dir error!\n");
            return 0;
        }
    } 

		ltStrAddF(caTempDir,"%lu/",ltStrGetId());
    mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);	
    nasCvtStime(lTime1,caSdate1,caTime1); 
    caTime1[5]=0;   
    if(deployscope==1){//ÿ��
			nasCvtStime(lTime2,caSdate2,caTime2);
			sprintf(caLabel,"echo 'date=%s %s' > %sinfo.ini",caSdate2,caTime2,caTempDir);
			system(caLabel);/*����Ŀ¼��־*/
    }else if(deployscope==0){//ÿ��
			nasTimeGetDate(fileDate,time(0)); 
		  nasCvtStime(time(0),fileDate,caTime1);
			sprintf(caLabel,"echo 'date=%s %s' > %sinfo.ini",fileDate,caTime1,caTempDir);
			system(caLabel);/*����Ŀ¼��־*/
    }else{
	    nasTimeGetDate(fileDate,lTime); 
	    nasCvtStime(lTime,fileDate,caTime1);
			sprintf(caLabel,"echo 'date=%s %s' > %sinfo.ini",fileDate,caTime1,caTempDir);
			system(caLabel);
    }
   
    sprintf(caLabel,"echo 'name=%s' >> %sinfo.ini",reportnames,caTempDir);
    system(caLabel);/*����Ŀ¼��־*/
    sprintf(caLabel,"echo 'user=system' >> %sinfo.ini",caTempDir);
    system(caLabel);/*����Ŀ¼��־*/
    sprintf(caLabel,"/bin/echo '1' > %sproccess.ini",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/
    
	  if(lang==0){//Ch
			sprintf(caLabel,"/bin/cp -f /app/msa/msa/htmlplt/reportplt/dailyreport_ch/*.gif %s",caTempDir);
			system(caLabel); 
			sprintf(caLabel,"/bin/cp -f /app/msa/msa/htmlplt/reportplt/dailyreport_ch/*.jpg %s",caTempDir);
			system(caLabel); 
		}else if(lang==1){//Eng
			sprintf(caLabel,"/bin/cp -f /app/msa/msa/htmlplt/reportplt/dailyreport_en/*.gif %s",caTempDir);
			system(caLabel); 
			sprintf(caLabel,"/bin/cp -f /app/msa/msa/htmlplt/reportplt/dailyreport_en/*.jpg %s",caTempDir);
			system(caLabel); 
		}
	       
    /*part1 ������ҳ*/
    dbPtr=lt_dbinit();
    lt_db_htmlpage(dbPtr,"utf-8");
    lt_dbput_rootvars(dbPtr,1,"reportbdate",caSdate);
    if(lang==0){//Ch
			lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart1.htm",dbPtr->doc,0);
		}else if(lang==1){//Eng
			lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart1.htm",dbPtr->doc,0);
		}
    
    if(lt_page_content==NULL){
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
				system(caLabel);/*����Ŀ¼�����ڴ����־*/
				lt_dbfree(dbPtr);
        return 0;
		}else{
				lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
				sprintf(caLabel,"%sindex.htm",caTempDir);
				iFd = open(caLabel,O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT,0644); 
				if(iFd >0) {
					write(iFd,lt_page_content,strlen(lt_page_content));
				}
				close(iFd); /*����html��ʽ����*/
		}
		lt_dbfree(dbPtr);	  
 	                                                                     
		if(element[0]=='1'){/*chr0:part2�豸״̬���� ����perl�ű�����*/
	    printf("0:\n");			  		
			unsigned long long rootdiskinfo=0;
			unsigned long long appdiskinfo=0;
			FILE *fp;
			char *p;
			char caBuffer[132];
			char caDev[32];
			char caRate[32];
			char caMount[32];
			char caLine[2048];
			unsigned long long lTotal,lUsed,lFree;
			memset(caLine,0,sizeof(caLine));
			dbPtr=lt_dbinit();
	  	tablePtr=lt_dbput_table(dbPtr,"llista");	
			fp = popen("/sbin/df -k","r");
			if(fp){
				p = fgets(caBuffer,131,fp);
				p = fgets(caBuffer,131,fp);
				while(p){			    
						sscanf(caBuffer,"%s %lld %lld %lld %s %s",caDev,&lTotal,&lUsed,&lFree,caRate,caMount);												
						if(strcmp(caMount,"/")==0) {
							rootdiskinfo=(lUsed*100)/lTotal;		
							sprintf(caLine,"<tr>\r\n<td>%s</td><td>%s</td><td>%lldKb</td><td>%lldKb</td><td>%lldKb</td><td>%s</td>\r\n</tr>",
											caDev,caMount,lTotal,lUsed,lFree,caRate);					
							lt_dbput_recordvars(tablePtr,1,"diskinfo",LT_TYPE_STRING,caLine);				
						}
						if(strcmp(caMount,"/app")==0) {
							appdiskinfo=(lUsed*100)/lTotal;
							sprintf(caLine,"<tr>\r\n<td>%s</td><td>%s</td><td>%lldKb</td><td>%lldKb</td><td>%lldKb</td><td>%s</td>\r\n</tr>",
											caDev,caMount,lTotal,lUsed,lFree,caRate);					
							lt_dbput_recordvars(tablePtr,1,"diskinfo",LT_TYPE_STRING,caLine);	
							break;
						}						
						p = fgets(caBuffer,132,fp);
				}
				if(pclose(fp) == -1){
				  perror("pclose error");
				  return -1;
				}
			}		

			if(lang==0){//Ch
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart2.htm",dbPtr->doc,0);
			}else if(lang==1){//Eng
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart2.htm",dbPtr->doc,0);
			}
		
			if(lt_page_content==NULL){
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
				return 0;
			}else{    
		    lt_page_content=strstr(lt_page_content,"<tr>");
		    sprintf(caLabel,"%sindex.htm",caTempDir);
				iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
				if(iFd >0) {
					write(iFd,lt_page_content,strlen(lt_page_content));
				}
				close(iFd);  
			}
	    	
	    lt_dbfree(dbPtr);
			printf("dev zhuangtai report part2 ok!\n");	   
   }
   

    //����������� ����ģ��������Ӧ�����������
  	if(element[1]=='1'){//ͳ�Ʊ� �����������  ��Ӧ��htmlҳ���chr2
			printf("-------  wangluo chukou flow  ------- \n");//part3 ��������	 	
   	 	lTime1 = nasCvtLongTime(caSdate,"00:00:01");
			lTime2 = nasCvtLongTime(caEdate,"23:59:59");     
	    unsigned long iMaxItem;
	    struct nasFlowCount_s {
				char          		 caItem[16];
				unsigned long long lDbytes;
				unsigned long long lUbytes;
				unsigned long long lTbytes;
			}sCount[35];
      memset((char *)&sCount,0,35*sizeof(struct nasFlowCount_s));

			if(strcmp(caSdate,caEdate)==0){		 
				lStep = 3600;
				if(lTime2>time(0)){
				   lTime2=time(0);
				}
				lTime0 = lTime1; 
	      
				memset(caSdate1,0,sizeof(caSdate1));  
				memset(caSdate2,0,sizeof(caSdate2));
				nasTimeGetDate(caSdate1,lTime1);
				nasTimeGetDate(caSdate2,lTime2);
				printf("1caSdate1:%s\n",caSdate1);
				printf("1caSdate2:%s\n",caSdate2);
				sprintf(sqlBuf,"select sdate,hours,avg(ubytes),avg(dbytes)from msatimereport\
	              where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
	              group by sdate,hours order by sdate asc,hours asc;",caSdate1,caSdate2);
				printf("sql1:%s\n",sqlBuf);
				tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
				if(tempCursor == NULL) {
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
					system(caLabel);/*����Ŀ¼�����ڴ����־*/ 
				   return 0;
				}
				lMaxBytes = 1;
				iMax = 0;    
				tempRow=ltDbFetchRow(tempCursor);
				while(tempRow!=NULL){  
					sprintf(caItem,"%s %s:00",tempRow[0],tempRow[1]); 
					lUbytes=atoll(tempRow[2])/1024;
					lDbytes=atoll(tempRow[3])/1024;
					if(lMaxBytes <= (lUbytes + lDbytes)){
					   lMaxBytes  = (lUbytes + lDbytes);
					}
					sprintf(sCount[iMax].caItem,"%s",caItem);
					sCount[iMax].lUbytes = lUbytes ;
					sCount[iMax].lDbytes = lDbytes ;
					iMax++;
					tempRow=ltDbFetchRow(tempCursor);
				}
				ltDbCloseCursor(tempCursor);   
				iMaxItem = iMax;
				//����ͼ��
				dbPtr=lt_dbinit();
				sprintf(caLabel,"%sdata.ini",caTempDir);
				iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
				if(iFd == (-1)) {
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
					system(caLabel);//����Ŀ¼�����ڴ����־
					ltDbCloseCursor(tempCursor);
					return 0;
				}   
				lt_dbput_rootvars(dbPtr,1,"xunit","Hour");
	          
				tablePtr=lt_dbput_table(dbPtr,"list2");
				for(i=0;i<iMaxItem;i++) {
					lt_dbput_recordvars(tablePtr,4,
						"mytime",LT_TYPE_STRING,sCount[i].caItem,
						"ubyte",LT_TYPE_LONGLONG,sCount[i].lUbytes,
						"dbyte",LT_TYPE_LONGLONG,sCount[i].lDbytes,
						"abyte",LT_TYPE_LONGLONG,sCount[i].lUbytes+sCount[i].lDbytes
					);
					sprintf(caLabel,"%s,%llu,%llu,%llu\r\n",sCount[i].caItem,sCount[i].lUbytes+sCount[i].lDbytes,sCount[i].lDbytes,sCount[i].lUbytes);
					write(iFd, caLabel, strlen(caLabel));	
				}
				close(iFd); 
	      
				sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowplt.pl  %sdata.ini %soutflow1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));
				system(caLabel);	
				lt_dbput_rootvars(dbPtr,1,"file1","outflow1.jpg");
		
				sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowpltline.pl %sdata.ini %soutflow2.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));
				system(caLabel);	
				lt_dbput_rootvars(dbPtr,1,"file2","outflow2.jpg");
			   
			}else{
				lStep = 24 * 3600;
				if(lTime1 == 0) {
					lTime1 = lTime2-31*lStep;  
				}
				if(lTime2>(lTime1+31*lStep)){
					lTime2=lTime1+31*lStep;
				}
				if(lTime2>lTime){
					printf("lTime:%lu",lTime);
					lTime2=lTime;
				}
				lTime0 = lTime1;  
				memset(caSdate1,0,sizeof(caSdate1));  
				memset(caSdate2,0,sizeof(caSdate2));
				nasTimeGetDate(caSdate1,lTime1);
				nasTimeGetDate(caSdate2,lTime2);
				printf("2caSdate1:%s\n",caSdate1);
				printf("2caSdate2:%s\n",caSdate2);
				iMaxItem = 32;
				for(i=0;i<iMaxItem;i++) {
							nasCvtStime(lTime0,caSdate,caTime);
							memset(sCount[i].caItem,0,16);
							lTime0 = lTime0 + lStep;
							sCount[i].lDbytes=0;
							sCount[i].lUbytes=0;
				}
				sprintf(sqlBuf,"select sdate,avg(ubytes),avg(dbytes) from msatimereport\
				 where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
				 group by sdate limit 30 offset 0",caSdate1,caSdate2);
				printf("sqlBuf2%s\n",sqlBuf);
				tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);    
			    if(tempCursor == NULL){ 
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
					system(caLabel);/*����Ŀ¼�����ڴ����־*/ 
			        return 0;
			    }
			    lMaxBytes = 1;
			    iMax = 0;
			    tempRow= ltDbFetchRow(tempCursor);
			    while(tempRow!=NULL){
			    sprintf(caItem,"%s",tempRow[0]);
					lUbytes=atoll(tempRow[1])/1024;
			        lDbytes=atoll(tempRow[2])/1024;
			        if(lMaxBytes <= (lUbytes + lDbytes)) {
			           lMaxBytes = (lUbytes + lDbytes) ;
			        }
			        sprintf(sCount[iMax].caItem,"%s",caItem);
			        sCount[iMax].lUbytes = lUbytes ;
			        sCount[iMax].lDbytes = lDbytes ;
			        iMax++;
			        tempRow= ltDbFetchRow(tempCursor);
			    }
			    ltDbCloseCursor(tempCursor);
			    iMaxItem = iMax;
			    /* ������  */
			    /* ����ͼ��  */
			    memset(caSdate1,0,sizeof(caSdate1));  
					memset(caSdate2,0,sizeof(caSdate2));
			    nasCvtStime(lTime1,caSdate1,caTime1);
			    nasCvtStime(lTime2,caSdate2,caTime2);
			    caTime1[5]=0;
			    caTime2[5]=0;
			    sprintf(caLabel,"%s %s--%s %s",caSdate1,caTime1,caSdate2,caTime2);
			    dbPtr=lt_dbinit();
			    sprintf(caLabel,"%sdata.ini",caTempDir);
			    iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
				if(iFd == (-1)) {
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
					system(caLabel);/*����Ŀ¼�����ڴ����־*/
					ltDbCloseCursor(tempCursor);
					return 0;
				}	
			    lt_dbput_rootvars(dbPtr,1,"lab",caLabel);   
			    lt_dbput_rootvars(dbPtr,1,"reportname",reportname);       
			    lt_dbput_rootvars(dbPtr,1,"xunit","Day");
			         
			    tablePtr=lt_dbput_table(dbPtr,"list2");
			    for(i=0;i<iMaxItem;i++){
			        lt_dbput_recordvars(tablePtr,4,
						"mytime",LT_TYPE_STRING,sCount[i].caItem,
						"ubyte",LT_TYPE_LONGLONG,sCount[i].lUbytes,
						"dbyte",LT_TYPE_LONGLONG,sCount[i].lDbytes,
						"abyte",LT_TYPE_LONGLONG,sCount[i].lUbytes+sCount[i].lDbytes
					);
					sprintf(caLabel,"%s,%llu,%llu,%llu\r\n",sCount[i].caItem,sCount[i].lUbytes+sCount[i].lDbytes,sCount[i].lDbytes,sCount[i].lUbytes);
					write(iFd, caLabel, strlen(caLabel));	
			    }
			    close(iFd); 
				sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowplt.pl  %sdata.ini %soutflow1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));
				system(caLabel);	
				lt_dbput_rootvars(dbPtr,1,"file1","outflow1.jpg");
				sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowpltline.pl  %sdata.ini %soutflow2.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));
				system(caLabel);	
				lt_dbput_rootvars(dbPtr,1,"file2","outflow2.jpg");
			}     
       
			if(element[2]=='0'){//ֱ��ͼ û��ѡ�������ɵ�ͼƬhtml����ע��
				printf("2:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart1","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend1","-->");	 
			}
			
			if(element[3]=='0'){//����ͼ û��ѡ�������ɵ�ͼƬhtml����ע��
				printf("3:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart2","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend2","-->");	 
			} 
		
			if(lang==0){//Ch
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart3.htm",dbPtr->doc,0);
			}else if(lang==1){//Eng
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart3.htm",dbPtr->doc,0);	
			}
   
			if(lt_page_content==NULL){
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
		  		system(caLabel);/*����Ŀ¼�����ڴ����־*/
					return 0;
			}else{    
			    lt_page_content=strstr(lt_page_content,"<tr>");
			    sprintf(caLabel,"%sindex.htm",caTempDir);
					iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
					if(iFd >0) {
						write(iFd,lt_page_content,strlen(lt_page_content));
					}
					close(iFd);  
			}
			
    	lt_dbfree(dbPtr);
   
    	printf("net chukou flow daily report part3 ok\n");	//�������������ر����������
		}
   
     		 
	//������� ����ģ��������Ӧ�����������
		if(element[4]=='1'||checkb[1]=='1'){//�������	4��ͳ�Ʊ� 1��ͳ�Ʊ�
	   	printf("4:\n");//part4 ���񱨸�
		{
			char       oldname[256];
			char       caSrv[64];
			int        srvindex;
			char       srvStr[64];	
			nasTimeGetDate(caSdate1,lTime1);
			nasTimeGetDate(caSdate2,lTime2);
			sprintf(sqlBuf,"select service,sum(ubytes+dbytes)/1024+1 as abyte ,sum(ctime) as arequest,sum(onlinetime) as atime\
	  	                from msasrvreport where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
	  	                group by service order by abyte desc ",caSdate1,caSdate2);	   
			printf("srvsqlBuf:%s\n",sqlBuf);  
			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor == NULL) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
			    system(caLabel);/*����Ŀ¼�����ڴ����־*/
			    return 0;
			}
			sprintf(caLabel,"%sdata.ini",caTempDir);
		    iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
			if(iFd == (-1)) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
				system(caLabel);/*����Ŀ¼�����ڴ����־*/
				ltDbCloseCursor(tempCursor);
				return 0;
			}	
			
			dbPtr=lt_dbinit();
			lt_db_htmlpage(dbPtr,"utf-8");
			tablePtr=lt_dbput_table(dbPtr,"flowlist");
			tempRow= ltDbFetchRow(tempCursor);  
			memset(oldname,0,sizeof(oldname));
			srvindex=1;
			while(tempRow!=NULL){    	       
				sprintf(caSrv,"S%d %s",srvindex,tempRow[0]); 
				sprintf(srvStr,"NO.%d",srvindex);
				lt_dbput_recordvars(tablePtr,5,
					"index",LT_TYPE_STRING,srvStr,  
					"sname",LT_TYPE_STRING,_ltPubInfo->topSrvName[atol(tempRow[0])].srvname,
					"sc",LT_TYPE_LONGLONG,atoll(tempRow[2]),
					"sbyte",LT_TYPE_LONGLONG,atoll(tempRow[1]),
					"st",LT_TYPE_STRING,time2str(atol(tempRow[3])) 
				);    	      
				sprintf(caLabel,"%d,%lld\r\n",srvindex,atoll(tempRow[1]));
				write(iFd, caLabel, strlen(caLabel));	
				if(lMaxBytes<atoll(tempRow[1])){
						lMaxBytes=atoll(tempRow[1]);
				}
				srvindex++;
				tempRow= ltDbFetchRow(tempCursor);								
			}    	   
			ltDbCloseCursor(tempCursor); 
			close(iFd);	
			
			if(element[5]=='0'){//ȫ������
				printf("5:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart5","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend5","-->");	 
			}
			
			if(element[6]=='0'){//�����Ż���
				printf("6:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart6","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend6","-->");	 
			}
		    
			if(element[7]=='0'){//���û���������
				printf("7:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart7","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend7","-->");	 
			}
	    
			if(element[8]=='0'){//���û����ӻ���
				printf("8:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart8","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend8","-->");	 
			}
	    
			if(element[9]=='0'){//�����ڻ���
				printf("9:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart9","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend9","-->");	 
			}
	    
			if(element[10]=='0'){//������������������
				printf("10:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart10","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend10","-->");	 
			}
		    
			if(element[11]=='0'){//���û��������ӻ���
				printf("11:\n");
				lt_dbput_rootvars(dbPtr,1,"hidestart11","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend11","-->");	 
			}	
			sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowplt.pl  %sdata.ini %ssrvreport.gif %llu ",caTempDir,caTempDir,lMaxBytes);	
			system(caLabel);	
			lt_dbput_rootvars(dbPtr,1,"piechart","<img src=\"srvreport.gif\">" );
		 
			
			if(lang==0){//Ch
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart4.htm",dbPtr->doc,0);
			}else if(lang==1){//Eng
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart4.htm",dbPtr->doc,0);
			}	
	
			if(lt_page_content==NULL){
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
	    		system(caLabel);//����Ŀ¼�����ڴ����־
	    		lt_dbfree(dbPtr);
					return 0; 
			}else{
				lt_page_content=strstr(lt_page_content,"<tr>");
				sprintf(caLabel,"%sindex.htm",caTempDir);
				iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
				if(iFd >0) { 
					  write(iFd,lt_page_content,strlen(lt_page_content)); 
				}
				close(iFd);
				lt_dbfree(dbPtr);//����html��ʽ����
			}
		
			printf("srv report daily report part4 ok\n");//������ܱ���������� 
		}
 
	}
	 
		printf("call srvreport function ...........\n");
    printf("caSdate1:%s\n",caSdate1);
    printf("caSdate2:%s\n",caSdate2);
    printf("userid:%d\n",userid);
    printf("gid:%d\n",gid);
    printf("caTempDir:%s\n",caTempDir);
    printf("lang:%d\n",lang);
	 
	if(element[5]=='1'){
		printf("5:\n");//��ر���---- ȫ������
		srvreport(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);
	}
	
	if(element[6]=='1'){
		printf("6:\n");//��ر���---- ���Ż��� 
		srvreport(caSdate1,caSdate2,userid,gid,2,caTempDir,lang);
	}
	 
	if(element[7]=='1'){
		printf("7:\n");//��ر���---- �û���������
		srvreport(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);
	}
	 
	if(element[8]=='1'){
		printf("8:\n");//��ر���---- �û����ӻ���
		srvreport(caSdate1,caSdate2,userid,gid,7,caTempDir,lang);
	}
	 
	if(element[9]=='1'){
		printf("9:\n");//��ر���---- ���ڻ���
		srvreport(caSdate1,caSdate2,userid,gid,4,caTempDir,lang);
	}
	 
	if(element[10]=='1'){
		printf("10:\n");//��ر���---- ����������������
		srvreport(caSdate1,caSdate2,userid,gid,5,caTempDir,lang);
	}
		
	if(element[11]=='1'){
		printf("11:\n");//��ر���---- �����������ӻ���
		srvreport(caSdate1,caSdate2,userid,gid,6,caTempDir,lang);			 
	}
	printf("call srvreport function end...........");


	//��������ܼ� ����ģ��������Ӧ�����������
	if(element[12]=='1'||checkb[2]=='1'){//chr12 ͳ�Ʊ� 1��ͳ�Ʊ�	 	
	  	printf("12:\n");		   	  	//part5  24Сʱ��������
	    {
			struct nasFlowCount_s {
				char          caItem[16];
				unsigned long long lDbytes;
				unsigned long long lUbytes;
				unsigned long long lTbytes;
				unsigned long long lConTime;
			}sCount[35];
			memset((char *)&sCount,0,35*sizeof(struct nasFlowCount_s));
	    	dbPtr=lt_dbinit();
			if(strcmp(caSdate,caEdate)==0){
				lStep = 3600;
				if(lTime1 == 0) {
					lTime1 = lTime - 24*lStep;
				}
				if(lTime2>lTime){
					   lTime2=lTime;
				  }
				lTime0 = lTime1;
				iMaxItem = 25;
				for(i=0;i<iMaxItem;i++){
					nasCvtStime(lTime0,caSdate,caTime);
					memcpy(sCount[i].caItem,caTime,2);
					lTime0 = lTime0 + lStep;
				}
				nasTimeGetDate(caSdate1,lTime1);
				nasTimeGetDate(caSdate2,lTime2);
				nasTimeGetTime(caTime1,lTime1);
				nasTimeGetTime(caTime2,lTime2);
				caTime1[2]=0;
				caTime2[2]=0;
				  
				if(gid==-1){
					sprintf(sqlBuf,"select onlinetime,sum(ubytes),sum(dbytes) from msasrvreport \
						  where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
						  group by sdate order by sdate desc",caSdate1,caSdate2
					);
				}else{
					if(userid!=-1){		   
						sprintf(sqlBuf,"select onlinetime,sum(ubytes),sum(dbytes) from msasrvreport \
						   where userid = %d and substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
							   group by sdate order by sdate desc",userid,caSdate1,caSdate2
						);
					}else{
						sprintf(sqlBuf,"select stime,sum(ubytes),sum(dbytes) from msasrvreport a,msauser b  \
						  where a.userid=b.userid and  b.groupid0 = %d and substring(a.sdate,3,8)>='%s'\
						  and substring(a.sdate,3,8)<='%s'\
						  group by a.sdate order by a.sdate desc ",gid,caSdate1,caSdate2
						);
					 
					}
			   
				}
				printf("sqlBuf3:%s\n",sqlBuf);
				tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
				lt_dbput_rootvars(dbPtr,1,"xunit","Hour");
		
			}else{
				lStep = 24 * 3600;
				if(lTime1 == 0) {
					lTime1 = lTime-31*lStep;           
				}
				if(lTime2>(lTime1+31*lStep)){
					lTime2=lTime1+31*lStep;
				}
				if(lTime2>lTime){
					lTime2=lTime;
				}
				lTime0 = lTime1;
				iMaxItem = 32;
				for(i=0;i<iMaxItem;i++) { 
					nasCvtStime(lTime0,caSdate,caTime);
					memset(sCount[i].caItem,0,16);
					lTime0 = lTime0 + lStep;
				}
				nasTimeGetDate(caSdate1,lTime1); 
				nasTimeGetDate(caSdate2,lTime2); 
				nasTimeGetTime(caTime1,lTime1); 
				nasTimeGetTime(caTime2,lTime2); 
				caTime1[2]=0; 
				caTime2[2]=0;
				  
				if(gid==-1){
					sprintf(sqlBuf,"select sdate,sum(ubytes),sum(dbytes)\
					  from msasrvreport where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
					  group by sdate limit 30 offset 0",caSdate1,caSdate2
					);
		
				}else{
					if(userid!=-1){
						sprintf(sqlBuf,"select sdate,sum(ubytes),sum(dbytes) from msasrvreport\
							 where userid = %d and substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
							 group by sdate order by sdate desc limit 30 offset 0",userid,caSdate1,caSdate2
						);			             
					}else{
						sprintf(sqlBuf,"select sdate,sum(ubytes),sum(dbytes) from msasrvreport a,msauser b\
							where a.userid = b.userid and b.groupid0=%d and substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
							group by sdate order by sdate desc limit 30 offset",gid,caSdate1,caSdate2
						); 
					}
			   
				} 
			   
				printf("sqlBuf4:%s\n",sqlBuf);
				tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
				lt_dbput_rootvars(dbPtr,1,"xunit","Day");
			}
		      
			if(tempCursor == NULL) { 
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir); 
				system(caLabel);/*����Ŀ¼�����ڴ����־*/
		        return 0;
			} 
			lMaxBytes = 1;
			iMax = 0;
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				sprintf(caItem,"%s",tempRow[0]);
				lUbytes=atoll(tempRow[1]);
				lDbytes=atoll(tempRow[2]);
				if(lMaxBytes <= (lUbytes + lDbytes) / 1024) {
				   lMaxBytes = (lUbytes + lDbytes) / 1024;
				}
				sprintf(sCount[iMax].caItem,"%s",caItem);
				sCount[iMax].lUbytes = lUbytes / 1024;
				sCount[iMax].lDbytes = lDbytes / 1024; 
				iMax++;
				tempRow= ltDbFetchRow(tempCursor); 
			} 
	
			ltDbCloseCursor(tempCursor);
			iMaxItem = iMax;
			sprintf(caLabel,"%sdata.ini",caTempDir);
			iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
			if(iFd == (-1)) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
				system(caLabel);/*����Ŀ¼�����ڴ����־*/
				ltDbCloseCursor(tempCursor);
				return 0;
			}
		
			tablePtr=lt_dbput_table(dbPtr,"list2");
			for(i=0;i<iMaxItem;i++) {
		        lt_dbput_recordvars(tablePtr,4,
					"mytime",LT_TYPE_STRING,sCount[i].caItem,
					"ubyte",LT_TYPE_LONGLONG,sCount[i].lUbytes,
					"dbyte",LT_TYPE_LONGLONG,sCount[i].lDbytes,
					"abyte",LT_TYPE_LONGLONG,sCount[i].lUbytes+sCount[i].lDbytes
				);
				sprintf(caLabel,"%s,%llu,%llu,%llu\r\n",sCount[i].caItem,sCount[i].lUbytes+sCount[i].lDbytes,sCount[i].lDbytes,sCount[i].lUbytes);
				write(iFd, caLabel, strlen(caLabel));		
		    }
			close(iFd); 
			sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowplt.pl  %sdata.ini %sflowreports1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));
			system(caLabel);	  
			lt_dbput_rootvars(dbPtr,1,"file1","flowreports1.jpg");
	
			sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/outflowpltline.pl  %sdata.ini %sflowreports2.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));
			system(caLabel);	
			lt_dbput_rootvars(dbPtr,1,"file2","flowreports2.jpg");
			char userNumber[128];
			userNumber[0]='\0';
			sprintf(userNumber,"%d",inttopusernum);
			lt_dbput_rootvars(dbPtr,1,"topusernum",userNumber);
	   
			if(element[13]=='0'){
				printf("13:\n");//ֱ��ͼ
				lt_dbput_rootvars(dbPtr,1,"hidestart13","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend13","-->");	 
			}
		    if(element[14]=='0'){
		  	    printf("14:\n");//����ͼ
				lt_dbput_rootvars(dbPtr,1,"hidestart14","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend14","-->");	 
		    }
		    if(element[15]=='0'){
				printf("15:\n");//�������
				lt_dbput_rootvars(dbPtr,1,"hidestart15","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend15","-->");	 
		    }
		  
		  
		   //����������������
		    if(element[16]=='0'){
				printf("16:\n");//�û�����������
				lt_dbput_rootvars(dbPtr,1,"hidestart16","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend16","-->");	 
		    }
		    if(element[17]=='0'){
				printf("17:\n");//�û�����������
				lt_dbput_rootvars(dbPtr,1,"hidestart17","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend17","-->");	 
		    }
		    if(element[18]=='0'){
				printf("18:\n");//�û�����������
				lt_dbput_rootvars(dbPtr,1,"hidestart18","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend18","-->");	 
		    }
		    if(element[19]=='0'){
				printf("19:\n");//���Ż���
				lt_dbput_rootvars(dbPtr,1,"hidestart19","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend19","-->");	 
		    }
		    if(element[20]=='0'){
				printf("20:\n");//������Ա����
				lt_dbput_rootvars(dbPtr,1,"hidestart20","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend20","-->");	 
		    }
		    if(element[21]=='0'){
				printf("21:\n");//�������ڻ���
				lt_dbput_rootvars(dbPtr,1,"hidestart21","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend21","-->");	 
		    }
		  
	 
			if(lang==0){//Ch
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart5.htm",dbPtr->doc,0);
			}else if(lang==1){//Eng
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart5.htm",dbPtr->doc,0);
			}
	
			if(lt_page_content==NULL){
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
					system(caLabel);/*����Ŀ¼�����ڴ����־*/
	    		lt_dbfree(dbPtr);
					return 0;
			}else{
			    lt_page_content=strstr(lt_page_content,"<tr>"); /*����html��ʽ����*/
			    sprintf(caLabel,"%sindex.htm",caTempDir);
					iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
					if(iFd >0) {
		          write(iFd,lt_page_content,strlen(lt_page_content));
					}
					close(iFd);
					lt_dbfree(dbPtr);
			}
	
		}			  
	}
	 
	 
    printf("call connectflow function ...........\n");
    printf("caSdate1:%s\n",caSdate1);
    printf("caSdate2:%s\n",caSdate2);
    printf("userid:%d\n",userid);
    printf("gid:%d\n",gid);
    printf("caTempDir:%s\n",caTempDir);
    printf("lang:%d\n\n",lang);
	 
		 //������������
		if(element[15]=='1'){
			printf("15:\n");//��ر���---- ������������-�������
			connectflow(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);			 
		}
		 
		if(element[16]=='1'){
			printf("16:\n");//��ر���---- ������������-�û����������� 
			connectflow(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);			 
		}
		 
		 if(element[17]=='1'){
			printf("17:\n");//��ر���---- ������������-�û����������� 
			connectflow(caSdate1,caSdate2,userid,gid,4,caTempDir,lang);				 
		 }
		 
		 if(element[18]=='1'){
			printf("18:\n");//��ر���---- ������������-�û�����������
			connectflow(caSdate1,caSdate2,userid,gid,5,caTempDir,lang);				 
		 }
		 
		 if(element[19]=='1'){
			printf("19:\n");//��ر���---- ������������-���Ż���
			connectflow(caSdate1,caSdate2,userid,gid,6,caTempDir,lang);					 
		 }
		 
		 if(element[20]=='1'){
			printf("20:\n");//��ر���---- ������������-������Ա����
			connectflow(caSdate1,caSdate2,userid,gid,7,caTempDir,lang);					 
		 }
		 
		 if(element[21]=='1'){
			printf("21:\n");//��ر���---- ������������-�������ڻ���
			connectflow(caSdate1,caSdate2,userid,gid,8,caTempDir,lang);		 
		 }
		   	 
		 printf("call connectflow function end...........");   	 
		   	 

    //��������Ա���� ����ģ��������Ӧ�����������	  
	if(element[22]=='1'||checkb[3]=='1'){//22 ���ŷ�������	 		  
	 	 printf("22:\n"); 			//part7 group report
		{
			int  xgid[100];
			int  xxxi;
			for(xxxi=0;xxxi<100;xxxi++){
				xgid[xxxi]=-1;
			}
			xxxi=0;
			nasTimeGetDate(caSdate1,lTime1);
	    nasTimeGetDate(caSdate2,lTime2);
	    memset(oldgname,0,sizeof(oldgname));
	    memset(egname,0,sizeof(egname));
		 	printf("%s\n",caSdate1);
		 	printf("%s\n",caSdate2); 
		 	
			sprintf(sqlBuf,"select c.id,c.name,sum(a.ubytes+a.dbytes)/1024+1 as mybytes,sum(a.onlinetime) \
				from msasrvreport a,msauser b ,msagroup c where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
				and a.userid = b.userid and  b.groupid0=c.id group by c.id,c.name  \
				order by mybytes desc limit %d offset 0 ",caSdate1,caSdate2,inttopusernum
			);
			
			printf("sqlbuf5:%s\n",sqlBuf);//���ŷ�������
			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor == NULL){
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				return 0;
			}
			sprintf(caLabel,"%sdata.ini",caTempDir);
			iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
			if(iFd == (-1)){
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				ltDbCloseCursor(tempCursor);
		    return 0;
			}	
    
			lMax=0;
			dbPtr=lt_dbinit();
			lt_db_htmlpage(dbPtr,"utf-8");
			tablePtr=lt_dbput_table(dbPtr,"flowlist");
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				xgid[xxxi]=atol(tempRow[0]);
				lt_dbput_recordvars(tablePtr,4,
					"gid",LT_TYPE_STRING,tempRow[0],
					"groupname",LT_TYPE_STRING,tempRow[1],
					"lbyte",LT_TYPE_LONGLONG,atoll(tempRow[2]),
					"ltime",LT_TYPE_STRING,time2str(atol(tempRow[3]))
				);
				sprintf(oldgname,"%s",tempRow[1]);
				if(atoll(tempRow[2])>lMax){
					lMax=atoll(tempRow[2]);
				}
				sprintf(caLabel,"%d,%llu\r\n",xxxi+1,atoll(tempRow[2]));
				write(iFd, caLabel, strlen(caLabel));	
				xxxi++;
				tempRow=ltDbFetchRow(tempCursor);
			}
			ltDbCloseCursor(tempCursor);
			close(iFd);	
    			 
			sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/onlinesrv1.pl  %sdata.ini %sdeppie.gif %llu ",caTempDir,caTempDir,lMax);
			system(caLabel);	
			lt_dbput_rootvars(dbPtr,1,"piechart","<img src=\"deppie.gif\">" );
		
//			if(element[24]=='0'){
//				printf("wu24:\n");//ͼʾ
//				lt_dbput_rootvars(dbPtr,1,"hidestart30","<!--");
//	 			lt_dbput_rootvars(dbPtr,1,"hideend30","-->");	 
//			}
				
			if(element[26]=='0'){
				printf("wu26:\n");//��������ʱ�����
				lt_dbput_rootvars(dbPtr,1,"hidestart26","<!--");
	 			lt_dbput_rootvars(dbPtr,1,"hideend26","-->");	 
			}
	  

			if(lang==0){//Ch
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart7.htm",dbPtr->doc,0);
			}else if(lang==1){//Eng
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart7.htm",dbPtr->doc,0);
			}

			if(lt_page_content==NULL){
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
	    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
	    		lt_dbfree(dbPtr);
					return 0;
			}else{
					lt_page_content=strstr(lt_page_content,"<tr>");
					sprintf(caLabel,"%sindex.htm",caTempDir);
					iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
					if(iFd >0) { 
						write(iFd,lt_page_content,strlen(lt_page_content)); 
					}
					close(iFd);
					lt_dbfree(dbPtr);
			  /*����html��ʽ����*/
			}
	  
			for(xxxi=0;xxxi<100;xxxi++){//ѭ����
				if(xgid[xxxi]==-1){
				   break;
				}  
				
				{
					int  topuser=100;
					unsigned long long *lTop;
					lTop=(unsigned long long *)malloc(sizeof(unsigned long long)*topuser);
					for(iTemp=0;iTemp<topuser;iTemp++){
					   lTop[iTemp]=0;
					}  
					nasTimeGetDate(caSdate1,lTime1);
					nasTimeGetDate(caSdate2,lTime2);		 
					sprintf(sqlBuf,"select a.userid,b.dispname,sum(a.ubytes+a.dbytes)/1024+1 abyte,sum(a.onlinetime),c.name from msasrvreport a,\
					  msauser b,msagroup c where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s' and b.groupid0=%d\
					  and a.userid = b.userid and b.groupid0=c.id  group by a.userid,b.dispname,c.name \
					  order by abyte desc limit %d offset 0 ",caSdate1,caSdate2,xgid[xxxi],topuser
					);
					printf("group user::sql6:%s\n",sqlBuf);
					iTemp=0;
					lMax=0;  
					dbPtr=lt_dbinit();
					lt_db_htmlpage(dbPtr,"utf-8");
					tablePtr=lt_dbput_table(dbPtr,"flowlist");
					tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
					if(tempCursor == NULL) {
						sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
						system(caLabel);/*����Ŀ¼�����ڴ����־*/
						return 0;
					}
					tempRow=ltDbFetchRow(tempCursor);
					while(tempRow!=NULL){  			 
						lt_dbput_recordvars(tablePtr,5,
							"iIndex",LT_TYPE_LONG,iTemp,
							"uname",LT_TYPE_STRING,tempRow[1],
							"lbyte",LT_TYPE_LONGLONG,atoll(tempRow[2]),
							"ltime",LT_TYPE_STRING,time2str(atol(tempRow[3])),
							"groupname",LT_TYPE_STRING,tempRow[4]
						);
						lTop[iTemp]=atoll(tempRow[2]);						  
						if(lTop[iTemp]>lMax){
							lMax=lTop[iTemp];
						}
						iTemp++;
						tempRow= ltDbFetchRow(tempCursor);
					}
					ltDbCloseCursor(tempCursor);
			   
					sprintf(caLabel,"%sdata.ini",caTempDir);////��״ͼ��ʼ
					iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
					if(iFd == (-1)) {
							sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);
							system(caLabel);/*����Ŀ¼�����ڴ����־*/
							ltDbCloseCursor(tempCursor);
							return 0;
					}	

					for(i=0;i<iTemp;i++) {
							ltStrAddF(caTemp,"<value>%llu</value>\n",lTop[i]);
							sprintf(caLabel,"%d,%llu\r\n",i+1,lTop[i]);
					    write(iFd, caLabel, strlen(caLabel));	
					}
					close(iFd);	 
					sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/onlinesrv1.pl  %sdata.ini %sggg%dflowreport.gif %llu ",caTempDir,caTempDir,xgid[xxxi],lMax);					
					system(caLabel);				
					sprintf(caLabel,"<img src=\"ggg%dflowreport.gif\"  >",xgid[xxxi]);	
					lt_dbput_rootvars(dbPtr,1,"piechart",caLabel); //��״ͼ����
					/*-------------------------------------------------------------------------------------------------------------*/
					sprintf(caLabel,"%sdata.ini",caTempDir);//ֱ��ͼ��ʼ
					iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
					if(iFd == (-1)) {
						sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);
						system(caLabel);//����Ŀ¼�����ڴ����־ 
						ltDbCloseCursor(tempCursor); 
						return 0;
					}
	        
					for(i=0;i<iTemp;i++) {
					  sprintf(caLabel,"%d,%llu\r\n",i+1,lTop[i]);
					  write(iFd, caLabel, strlen(caLabel));	
					}
					  
					close(iFd);					 
					sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/onlinesrv-bar.pl  %sdata.ini %sggg%duserreport1.jpg %llu ",caTempDir,caTempDir,xgid[xxxi],(unsigned long long)(lMax+1));			 
					system(caLabel);	
				 
					sprintf(caTempFile,"ggg%duserreport1.jpg",xgid[xxxi]);		  
					lt_dbput_rootvars(dbPtr,1,"file",caTempFile);//ֱ��ͼ����
				
					if(element[24]=='0'){
						printf("24:\n");
						lt_dbput_rootvars(dbPtr,1,"hidestart24","<!--");
						lt_dbput_rootvars(dbPtr,1,"hideend24","-->");	 
					}
					
					if(element[25]=='0'){
						printf("25:\n");
						lt_dbput_rootvars(dbPtr,1,"hidestart25","<!--");
						lt_dbput_rootvars(dbPtr,1,"hideend25","-->");	 
					}
	  

					if(lang==0){//Ch
						lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart_depart.htm",dbPtr->doc,0);						
					}else if(lang==1){//Eng
						lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart_depart.htm",dbPtr->doc,0);
					}

					if(lt_page_content==NULL){
							sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
			    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
							return 0;
					}else{     
							lt_page_content=strstr(lt_page_content,"<!DOCTYPE");
							sprintf(caLabel,"%sggg%d.htm",caTempDir,xgid[xxxi]);
							iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
							if(iFd >0) {
								write(iFd,lt_page_content,strlen(lt_page_content));
							}
							close(iFd);
					}
					lt_dbfree(dbPtr);
				}	  	
			}	  
		} 
	}
	printf("group report daily report part7 ok\n"); 
	 
	if(element[23]=='1'){//�û���������	 	
		printf("23:\n");
		int  topuser=inttopusernum;
		unsigned long long *lTop;
		long lTopId[inttopusernum];			
		lTop=(unsigned long long *)malloc(sizeof(unsigned long long)*topuser);
		for(iTemp=0;iTemp<topuser;iTemp++){
			lTop[iTemp]=0;
		}
		for(iTemp=0;iTemp<inttopusernum;iTemp++){
			lTopId[iTemp]=0;
		}
		nasTimeGetDate(caSdate1,lTime1);
		nasTimeGetDate(caSdate2,lTime2);
		sprintf(sqlBuf,"select a.userid,b.dispname,sum(a.ubytes+a.dbytes)/1024+1 abyte,sum(onlinetime), c.name from msasrvreport a, \
		 msauser b,msagroup c where substring(a.sdate,3,8)>='%s' and substring(a.sdate,3,8)<='%s' and a.userid = b.userid and b.groupid0=c.id  group by a.userid,b.dispname,c.name  \
		 order by abyte desc limit %d offset 0 ",caSdate1,caSdate2,topuser-1
		);
		printf("user report sql7:%s\n",sqlBuf);
		iTemp=0;
		lMax=0;
		dbPtr=lt_dbinit();
		lt_db_htmlpage(dbPtr,"utf-8");
		tablePtr=lt_dbput_table(dbPtr,"flowlist");
		tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
		if(tempCursor == NULL) { 
			sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir); 
			system(caLabel);/*����Ŀ¼�����ڴ����־*/ 
			return 0; 
		}
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){
			lt_dbput_recordvars(tablePtr,5,
				"iIndex",LT_TYPE_LONG,iTemp,
				"uname",LT_TYPE_STRING,tempRow[1],
				"lbyte",LT_TYPE_LONGLONG,atoll(tempRow[2]),
				"ltime",LT_TYPE_STRING,time2str(atol(tempRow[3])),
				"groupname",LT_TYPE_STRING,tempRow[4]);
			lTop[iTemp]=atoll(tempRow[2]);
			lTopId[iTemp]=atol(tempRow[0]);			  
			if(lTop[iTemp]>lMax){
				lMax=lTop[iTemp];
			}
			iTemp++;
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
    
		/*--------------------------------------------------------------------------------------ֱ��ͼ��ʼ*/
		sprintf(caLabel,"%sdata.ini",caTempDir);
		iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
		if(iFd == (-1)) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־ 
				ltDbCloseCursor(tempCursor); 
				return 0;
		}
    
		for(i=0;i<iTemp;i++) {
				sprintf(caLabel,"%d,%llu\r\n",i+1,lTop[i]);
				write(iFd, caLabel, strlen(caLabel));	
		}
		  
		close(iFd);					 
		sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/onlinesrv-bar.pl  %sdata.ini %suserreport1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMax+1));			 
		system(caLabel);	   
		lt_dbput_rootvars(dbPtr,1,"file1","userreport1.jpg");
		/*---------------------------------------------------------------------------------------ֱ��ͼ����*/
		sprintf(caLabel,"%sdata.ini",caTempDir);//��״ͼ��ʼ
		iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
		if(iFd == (-1)) {
			sprintf(caLabel,"echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);
			system(caLabel);/*����Ŀ¼�����ڴ����־*/
			ltDbCloseCursor(tempCursor);
			return 0;
		}	

		for(i=0;i<iTemp;i++) { 
			ltStrAddF(caTemp,"<value>%llu</value>\n",lTop[i]);
			sprintf(caLabel,"%d,%llu\r\n",i+1,lTop[i]);
		    write(iFd, caLabel, strlen(caLabel));	
		}
		close(iFd);	
			 
		sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/onlinesrv1.pl  %sdata.ini %sflowreport.gif %llu ",caTempDir,caTempDir,lMax);
		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"piechart","<img src=\"flowreport.gif\">" );
		

		if(element[24]=='0'){
			printf("24:\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart24","<!--");
			lt_dbput_rootvars(dbPtr,1,"hideend24","-->");	 
		}
		
		if(element[25]=='0'){
			printf("25:\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart25","<!--");
			lt_dbput_rootvars(dbPtr,1,"hideend25","-->");	 
		}
	  
		if(lang==0){//Ch
			lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart6.htm",dbPtr->doc,0);
		}else if(lang==1){//Eng
			lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart6.htm",dbPtr->doc,0);
		}
	
		if(lt_page_content==NULL){
			sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
			system(caLabel);/*����Ŀ¼�����ڴ����־*/
	        return 0;
		}else{
			lt_page_content=strstr(lt_page_content,"<tr>");
			sprintf(caLabel,"%sindex.htm",caTempDir);
			iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
			if(iFd >0) {
			  write(iFd,lt_page_content,strlen(lt_page_content));
			}
		    close(iFd);
		} 
		lt_dbfree(dbPtr);       
	  
	  printf("grouppeople reportpart6 ok\n"); 
	    
    
    
		/*if(element[26]=='1'){//�����ҳ���������
			printf("26:\n");
			char mytabname[32];
			nasTimeGetDate(caSdate1,lTime1);
			nasTimeGetDate(caSdate2,lTime2);				
			dbPtr=lt_dbinit();
			lt_db_htmlpage(dbPtr,"utf-8");   
			for(iTemp=0;iTemp<inttopusernum;iTemp++){	    
				if(lTopId[iTemp]==0){
					 break;	
				}
				sprintf(sqlBuf,"select a.host ,sum(a.bytes)/1024 as abyte,sum(a.ctime) as atime, sum(a.lcount) as acount,a.urlsort,b.dispname,c.name\
				 from msauserhttpreport a,msauser b,msagroup c\
				 where substring(a.sdate,3,8)>='%s' and substring(a.sdate,3,8)<='%s' and a.userid = b.userid and b.groupid0=c.id and a.userid=%ld\
				 group by a.host,a.urlsort,b.dispname,c.name order by abyte desc limit 9 offset 0",caSdate1,caSdate2,lTopId[iTemp]);
				printf("user url sql8:%s\n",sqlBuf);
				tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
				if(tempCursor == NULL) {
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
					system(caLabel);//����Ŀ¼�����ڴ����־
					return 0;
				}
				
				tempRow= ltDbFetchRow(tempCursor);
				if(tempRow){
					sprintf(mytabname,"username%d",iTemp+1);
					lt_dbput_rootvars(dbPtr,1,mytabname,tempRow[5]);
				}
				sprintf(mytabname,"list%d",iTemp+1);
				tablePtr=lt_dbput_table(dbPtr,mytabname);
				i=1;
				while(tempRow!=NULL){
					lt_dbput_recordvars(tablePtr,6,
						"iIndex",LT_TYPE_LONG,i,
						"groupname",LT_TYPE_STRING,tempRow[6],
						"uname",LT_TYPE_STRING,tempRow[5],
						"host",LT_TYPE_STRING,tempRow[0],
						"urlsort",LT_TYPE_STRING,_ltPubInfo->_urlSortlist[atol(tempRow[4])].sortname,
						"contime",LT_TYPE_STRING,time2str(atol(tempRow[2]))
					);
					tempRow= ltDbFetchRow(tempCursor);
					i++;
				}
				ltDbCloseCursor(tempCursor);
			}   
			lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart6-1.htm",dbPtr->doc,0);
				 
			if(lt_page_content==NULL){
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				return 0;
			}else{
				lt_page_content=strstr(lt_page_content,"<tr>");
				sprintf(caLabel,"%sindex.htm",caTempDir);
				iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
				if(iFd >0) {
					write(iFd,lt_page_content,strlen(lt_page_content));
				}
				close(iFd);
			} 
			lt_dbfree(dbPtr); 
		  
		 }*/ 

	
	}
	 
	 

	if(element[26]=='1'){//��������Ա���棺��ر��桪����������ʱ�����
		printf("26:\n");
		usertimereport(caSdate1,caSdate2,caTempDir,gid,lang);				 
	}
	 
	if(element[27]=='1'||element[28]=='1'){ //WEB���桪��ǰ20/30/50�����ʴ������վ��
		printf("27:\n");  
		{ 
			nasTimeGetDate(caSdate1,lTime1);
			nasTimeGetDate(caSdate2,lTime2);
			sprintf(sqlBuf,"select host ,sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from msahttpreport \
			   where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
			   group by host,urlsort order by acount desc limit 50 offset 0",caSdate1,caSdate2
			);
			printf("sql9:%s\n",sqlBuf);
			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor == NULL) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				return 0;
			}
			dbPtr=lt_dbinit();
			lt_db_htmlpage(dbPtr,"utf-8");
			tablePtr=lt_dbput_table(dbPtr,"list1");
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,5,
					"uname",LT_TYPE_STRING,tempRow[0],
					"lbyte",LT_TYPE_LONG,atol(tempRow[1]),
					"ltime",LT_TYPE_STRING,time2str(atol(tempRow[2])),
					"lrequest",LT_TYPE_STRING,tempRow[3],
					"usort",LT_TYPE_STRING,_ltPubInfo->_urlSortlist[atol(tempRow[4])].sortname);
				tempRow= ltDbFetchRow(tempCursor);
			} 
			ltDbCloseCursor(tempCursor);


			sprintf(sqlBuf,"select sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort\
			   from msahttpreport where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
			   group by urlsort order by acount desc ",caSdate1,caSdate2
			);
			printf("sql10:%s\n",sqlBuf);
		  
			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor == NULL) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				return 0;
			}
			tablePtr=lt_dbput_table(dbPtr,"list3");
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,4,
					"lbyte",LT_TYPE_LONG,atol(tempRow[0]),
					"ltime",LT_TYPE_STRING,time2str(atol(tempRow[1])),
					"lrequest",LT_TYPE_STRING,tempRow[2],
					"usort",LT_TYPE_STRING,_ltPubInfo->_urlSortlist[atol(tempRow[3])].sortname);
				tempRow= ltDbFetchRow(tempCursor);
			} 
			ltDbCloseCursor(tempCursor);


			//top30 ����������
		  sprintf(sqlBuf,"select host ,sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from msahttpreport \
		     where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s'\
		     group by host,urlsort order by abyte desc limit 50 offset 0",caSdate1,caSdate2
	    );
			printf("sql11:%s\n",sqlBuf);
			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor == NULL) {
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
					system(caLabel);//����Ŀ¼�����ڴ����־
					return 0;
			}

			tablePtr=lt_dbput_table(dbPtr,"list2");  
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,5,
				"uname",LT_TYPE_STRING,tempRow[0],
				"lbyte",LT_TYPE_LONG,atol(tempRow[1]),
				"ltime",LT_TYPE_STRING,time2str(atol(tempRow[2])),
				"lrequest",LT_TYPE_STRING,tempRow[3],
				"usort",LT_TYPE_STRING,_ltPubInfo->_urlSortlist[atol(tempRow[4])].sortname);
				tempRow= ltDbFetchRow(tempCursor);
			}
			ltDbCloseCursor(tempCursor);
         
			sprintf(sqlBuf,"select sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from msahttpreport \
				   where substring(sdate,3,8)>='%s' and substring(sdate,3,8)<='%s' group by urlsort order by abyte desc ",caSdate1,caSdate2
			);
			printf("sql12:%s\n",sqlBuf);  
			tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor == NULL) {
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				return 0;
			}
			tablePtr=lt_dbput_table(dbPtr,"list4");
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,4,
					"lbyte",LT_TYPE_LONG,atol(tempRow[0]),
					"ltime",LT_TYPE_STRING,time2str(atol(tempRow[1])),
					"lrequest",LT_TYPE_STRING,tempRow[2],
					"usort",LT_TYPE_STRING,_ltPubInfo->_urlSortlist[atol(tempRow[3])].sortname);
				tempRow= ltDbFetchRow(tempCursor);
			} 
			ltDbCloseCursor(tempCursor);
       
			//������
			memset(caSdate1,0,sizeof(caSdate1));
			memset(caSdate2,0,sizeof(caSdate2));
			nasCvtStime(lTime1,caSdate1,caTime1);
			nasCvtStime(lTime2,caSdate2,caTime2);
			caTime1[5]=0;
			caTime2[5]=0;
			sprintf(caLabel,"Web Report:  %s",caSdate1);		   
			lt_dbput_rootvars(dbPtr,1,"lab",caLabel);

			if(element[27]=='0'){
				printf("27:\n");//���ʴ������վ��
				lt_dbput_rootvars(dbPtr,1,"hidestart27","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend27","-->");	 
			}
			
			if(element[28]=='0'){
				printf("28:\n");//�����������վ��
				lt_dbput_rootvars(dbPtr,1,"hidestart28","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend28","-->");	 
			}
			 
			if(element[29]=='0'){
				printf("29:\n");//ȫ������
				lt_dbput_rootvars(dbPtr,1,"hidestart29","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend29","-->");	 
			}
			
			if(element[30]=='0'){
				printf("30:\n");//���Ż���
				lt_dbput_rootvars(dbPtr,1,"hidestart30","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend30","-->");	 
			}
			
			if(element[31]=='0'){
				printf("31:\n");//�û�����
				lt_dbput_rootvars(dbPtr,1,"hidestart31","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend31","-->");	 
			}
			
			if(element[32]=='0'){
				printf("32:\n");//���ڻ���
				lt_dbput_rootvars(dbPtr,1,"hidestart32","<!--");
				lt_dbput_rootvars(dbPtr,1,"hideend32","-->");	 
			}
		  
			if(lang==0){//Ch
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart8.htm",dbPtr->doc,0);
			}else if(lang==1){//Eng
				lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_en/dailyreportpart8.htm",dbPtr->doc,0);
			}

			if(lt_page_content==NULL){
					sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
					system(caLabel);//����Ŀ¼�����ڴ����־
					lt_dbfree(dbPtr);
					return 0;
			}else{
					lt_page_content=strstr(lt_page_content,"<tr>");
					sprintf(caLabel,"%sindex.htm",caTempDir);
					iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
					if(iFd >0) {
						write(iFd,lt_page_content,strlen(lt_page_content));
					}
					close(iFd);
					lt_dbfree(dbPtr);//����html��ʽ����
			}
		}		 
	} 
   
   
    //web������ر���
    if(element[29]=='1'){ 
			printf("29:\n"); //��ر���---- ȫ������
			webreport(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);
    } 
   
		if(element[30]=='1'){ 
			printf("30:\n");//��ر���---- ���Ż���
			webreport(caSdate1,caSdate2,userid,gid,2,caTempDir,lang);		 
		} 

		if(element[31]=='1'){ 
			printf("31:\n");//��ر���---- �û�����
			webreport(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);			 
		} 

		if(element[32]=='1'){ 
			printf("32:\n");//��ر���---- ���ڻ���
			webreport(caSdate1,caSdate2,userid,gid,4,caTempDir,lang);			 
		}

		{
			dbPtr=lt_dbinit();
			lt_db_htmlpage(dbPtr,"utf-8");
			lt_page_content=ltPltFileParse("/app/msa/msa/htmlplt/reportplt/dailyreport_ch/dailyreportpart10.htm",dbPtr->doc,0);
			if(lt_page_content==NULL){
				sprintf(caLabel,"echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
				system(caLabel);//����Ŀ¼�����ڴ����־
				lt_dbfree(dbPtr);
				return 0;
			}else{
				lt_page_content=strstr(lt_page_content,"<tr>");
				sprintf(caLabel,"%sindex.htm",caTempDir);
				iFd = open(caLabel,O_WRONLY | O_NDELAY | O_APPEND | O_CREAT,0666); 
				if(iFd >0) {
					write(iFd,lt_page_content,strlen(lt_page_content));
				}
				close(iFd);
				lt_dbfree(dbPtr);//����html��ʽ����
			}
			 
		}

    chdir(caTempDir);
    sprintf(caLabel,"/app/msa/msa/htmlplt/Scripts/html2mail  %s index.htm %sindex.mht report %s",caTempDir,caTempDir,email);
    system(caLabel);

		system("tar -cvf report.tar *");
		sprintf(caLabel,"/bin/rm  %sproccess.ini",caTempDir);
		system(caLabel);
		sprintf(caLabel,"/bin/rm  %serrmsg.ini",caTempDir);
		system(caLabel);
	  
		printf("dailyReport end...................\n"); 
    return 0;
    
}


/****************************************************************
argv[1]����,argv[2]���� 
1��2�Ǳ����
������argc���ݲ����ĸ�����argv��ʾΪִ�иó��������ݵĲ����б�
�������Ϊ�����ƿ�ִ���ļ�:��������Ϊ��dailyreporttemplate
*****************************************************************/
int main(int argc,char **argv)
{
	
	printf("main start...............................\n");
  int  typ; 
  long tempIndex;
  int  iPid;
  int  pstatus; 
  char caFile[236];
  char caFile2[236];
  char temp[123];
  char *p;
	int  intMaxShmSize;
	int  intShmKey;
  lt_shmHead   *lt_MMHead;
  
  printf("argc:%d\n",argc);
  typ=atoi(argv[1]);
  tempIndex=atol(argv[2]);
	printf("tempIndex:%ld\n",tempIndex); //ģ���ļ�������
  printf("typ:%d\n",typ); //����
  
	if(typ==0){//ÿ�� 
	   printf("every day :: \n");
	   sprintf(caFile,"/datacenter/msa/report/page_data/%ld/info.ini",tempIndex);
	   bcCnfGetValue_s(caFile,"reportname",reportname); 
	}
	
	if(typ==1){//ÿ�� 
	   printf("every week :: \n");
	   sprintf(caFile,"/datacenter/msa/report/page_data/%ld/info.ini",tempIndex);
	   bcCnfGetValue_s(caFile,"reportname",reportname); 
	}
	
	if(typ==2){//���� 
	   printf("liji report:: \n");
	   sprintf(caFile,"/datacenter/msa/report/page_data/%ld/info.ini",tempIndex);
	   sprintf(caFile2,"/datacenter/msa/report/page_data");
	   sprintf(temp,"%ld",tempIndex);
	   printf("temp:%s\n",temp);
	   sprintf(caSdates,"%s", bcCnfGetValueS(caFile2,temp,"sdate"));
	   sprintf(caEdates,"%s", bcCnfGetValueS(caFile2,temp,"edate"));
	   sprintf(reportname,"%s", bcCnfGetValueS(caFile2,temp,"rpname"));

	}
	  printf("caFile:%s\n",caFile);
	
	  memset(topusernum,0,sizeof(topusernum));
	  bcCnfGetValue_s(caFile,"element",element); 
	  bcCnfGetValue_s(caFile,"checkb",checkb); 
	  bcCnfGetValue_s(caFile,"gid",gids);  
	  bcCnfGetValue_s(caFile,"userid",userids);
	  bcCnfGetValue_s(caFile,"email",email);
	  bcCnfGetValue_s(caFile,"language",language);    
    bcCnfGetValue_s(caFile,"topusernum",topusernum);  //��δ����ñ���
    printf("topusernum:%s\n",topusernum);
    inttopusernum=0;
    inttopusernum=atol(topusernum);
    if(inttopusernum>99){//Ĭ��Ϊ100
    	inttopusernum=99;
    }
    
		gid=atol(gids);
		userid=atol(userids);
		lang=atoi(language);
	
		printf("element::%s\n",element);
		printf("checkb::%s\n",checkb);
		printf("gid::%d\n",gid);
		printf("userid::%d\n",userid);
		printf("reportname::%s\n",reportname);
	 	printf("caSdates::%s\n",caSdates);
	 	printf("caEdates::%s\n",caEdates);
		printf("email::%s\n",email);
		printf("inttopusernum:%d\n",inttopusernum);
 	
	 	deployscope=typ;	     
    iPid = fork();  
		if(iPid == 0) {	   
			    /*��ȡ������ڴ���*/
			   	p=bcCnfGetValueS(_pubconfdir,"kernel", "maxshmsize");
					if(p==NULL){
						fprintf(stderr,"Start applicatin error: maxshmsize is NULL!\n");
						_exit(0);
					}
					intMaxShmSize=atol(p);
				
						/*��ȡϵͳshmKey*/
					p=bcCnfGetValueS(_pubconfdir,"kernel", "shmkey");
					if(p==NULL){
						fprintf(stderr,"Start applicatin error: shmkey is NULL!\n");
						_exit(0);
					}
					intShmKey=atol(p);
					
					lt_MMHead=openShmMem(intShmKey,intMaxShmSize);
					if(lt_MMHead==NULL){
						fprintf(stderr,"can open share memory!\n");
						 _exit(0);
					} 
				
				  lt_shmHead   *kernel_MMHead;
          p=bcCnfGetValueS(_pubconfdir,"kernel", "maxkernelshmsize");
          if(p==NULL){
              fprintf(stderr,"Start applicatin error: maxkernelshmsize is NULL!\n");
              return -1;
          }
          intMaxShmSize=atol(p);
          kernel_MMHead=msaopenBigBootMem(intMaxShmSize);
          if(!kernel_MMHead){
              closeShmMem(lt_MMHead);
              return -1;
          }

         	_bcKernelHead=(msaKernelHead *)kernel_MMHead->ShmMemPtr;
         	msaInitPubVar(lt_MMHead,kernel_MMHead);
					dbName=_ltPubInfo->_dbname;
	        dbUser=_ltPubInfo->_dbuser;
	        dbPass=_ltPubInfo->_dbpass; 	  
          G_DbCon=ltDbConnect(dbUser,dbPass,dbName);

					if(G_DbCon!=NULL){
						printf("db connect ok\n");
					}else{
						fprintf(stderr,"db connect error\n");
					}	    
					
			    signal(SIGALRM, catch_alarm);		    
	    		alarm(3600);
			    dailyReport(tempIndex);  
				  ltDbClose(G_DbCon);
	        _exit(0);
    }
    wait(&pstatus);
    
    printf("main end...............................\n");
    return 0;
}
