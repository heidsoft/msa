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
//#include "gd.h"
//#include <gdfontmb.h>

#include "nas.h"   

int sysActiveFlag;

char dbName[64];
char dbUser[64];
char dbPass[64];

char  gids[20];
char  userids[20];  
int  gid;
int  userid;
char element[256];
char checkb[20];
int deployscope;
char reportname[120];
char email[64];
char language[4];
int lang;

char  topusernum[32];
int   inttopusernum;   

char caSdates[32],caEdates[32];
 
static char *time2str(int itime){
	static char caTime[32];
	int ih;
	int im;
	int is;
	int itemp;
	if(itime==0){
		return "00:00:00";
	}
	caTime[0]='\0';
	memset(caTime,0,sizeof(caTime));
	ih=itime/3600;
	itemp=itime%3600;
	im=itemp/60;
	is=itemp%60;
	sprintf(caTime,"%02d:%02d:%02d",ih,im,is);
	return caTime;
}



void catch_alarm(int signum)
{
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
    char *lt_page_content;
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
    int iTemp;
		unsigned long long lMax;
		char  oldgname[128];
		char  egname[128];
		char  G_sdate[32];
    
   

  
    if(deployscope==0){//ÿ�����ɱ��� 
         lTime = time(0)-3600*24 ;
         nasTimeGetDate(caSdate,lTime);
   		   sprintf(G_sdate,"%s",caSdate);
		     sprintf(caEdate,"%s",caSdate);
		 
	 	     sprintf(reportnames,"%s-%s-daily",reportname,G_sdate);	
         lTime = time(0);
		     lTime1 = nasCvtLongTime(caSdate,"00:00:01");
         lTime2 = nasCvtLongTime(caSdate,"23:59:59");
		
	}if(deployscope==1){//ÿ��     
	    lTime = time(0);
    	nasTimeGetDate(caSdate,lTime-3600*24*6); 
    	nasTimeGetDate(caEdate,lTime);
    	sprintf(caSdate,"%s",caSdate);
    	sprintf(caEdate,"%s",caEdate);
    	
    	sprintf(G_sdate,"%s",caEdate);
    	
    	lTime1 = nasCvtLongTime(caSdate,"00:00:01");
      lTime2 = nasCvtLongTime(caEdate,"23:59:59");
    	
		  sprintf(reportnames,"%s-%s-weekly",reportname,G_sdate);	
		
	}if(deployscope==2){//�������� 

		  lTime = time(0);
    	/* nasTimeGetDate(caSdate,lTime); 
    	 sprintf(G_sdate,"%s",caSdate);*/

		  sprintf(caSdate,"%s",caSdates);
      sprintf(caEdate,"%s",caEdates);
	
	    sprintf(reportnames,"%s",reportname);
          
		  lTime1 = nasCvtLongTime(caSdate,"00:00:01");
		  lTime2 = nasCvtLongTime(caEdate,"23:59:59");

		  nasTimeGetDate(caSdate,lTime1); 
		  nasTimeGetDate(caEdate,lTime2);
		  sprintf(G_sdate,"%s",caSdate);
	     
	}

    tempCursor=NULL;
    

  /*  lTime1 = nasCvtLongTime(caSdate,"00:00:01");
    lTime2 = nasCvtLongTime(caSdate,"23:59:59");*/

    
    //sprintf(caTempDir,"/app/ns/conlog/report/instantreport/%s/",caSdate);
   if(deployscope==0){//ÿ�����ɱ��� 
	    //	sprintf(caTempDir,"/app/ns/conlog/report/dailyreport/%s/",G_sdate);
		sprintf(caTempDir,"/app/ns/conlog/report/dailyreport/%ld/",tempIndex);
  
	//strcpy(caTempDir,G_sdate); 
	    
	}if(deployscope==1){//ÿ�� 
		sprintf(caTempDir,"/app/ns/conlog/report/dailyreport/%ld/",tempIndex);
 
		//strcpy(caTempDir,G_sdate); 
		
	}if(deployscope==2){//��������    
	    //sprintf(caTempDir,"/app/ns/conlog/report/instantreport/%lu/",ltStrGetId());
	    sprintf(caTempDir,"/app/ns/conlog/report/instantreport/%ld/",tempIndex);
	}
    
    
  printf("���ɱ���Ŀ¼����:%s  \n",caTempDir);

  if(ltFileIsExist(caTempDir)!=1) {

        if(mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)!=0) {
            /// ���ɸñ���Ŀ¼���� 
            printf("mkdir daily report dir error!\n");
            return 0;
        }

   } 
  

	 ltStrAddF(caTempDir,"%lu/",ltStrGetId());
   mkdir(caTempDir,S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	

	printf("caTempDir:%s\n",caTempDir);

   nasCvtStime(lTime1,caSdate1,caTime1);
 
   caTime1[5]=0;
   
   printf("......lTime1:%ld caSdate1:%s  caTime1:%s\n",lTime1,caSdate1,caTime1);
    
   if(deployscope==1){
   	 nasCvtStime(lTime2,caSdate2,caTime2);
     sprintf(caLabel,"echo 'date=%s %s' > %sinfo.ini",caSdate2,caTime2,caTempDir);
     system(caLabel);/*����Ŀ¼��־*/
   }else if(deployscope==0){
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

    sprintf(caLabel,"echo '1' > %sproccess.ini",caTempDir);
    system(caLabel);/*����Ŀ¼���ڴ����־*/

   if(lang==0){//Ch
		 sprintf(caLabel,"/bin/cp -f /app/ns/html/reportplt/*.gif %s",caTempDir);
		 system(caLabel); 

		 sprintf(caLabel,"/bin/cp -f /app/ns/html/reportplt/*.jpg %s",caTempDir);
		 system(caLabel); 

	}else if(lang==1){//Eng
		 sprintf(caLabel,"/bin/cp -f /app/ns/html/reportplt_en/*.gif %s",caTempDir);
		 system(caLabel); 

		 sprintf(caLabel,"/bin/cp -f /app/ns/html/reportplt_en/*.jpg %s",caTempDir);
		 system(caLabel); 
	}
    
   	
    
    /*part1*/
    dbPtr=lt_dbinit();
    lt_db_htmlpage(dbPtr,"gb2312");
    lt_dbput_rootvars(dbPtr,1,"reportbdate",caSdate);

    if(lang==0){//Ch
		 		lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart1.htm",dbPtr->doc,0);
		}else if(lang==1){//Eng
			  lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart1.htm",dbPtr->doc,0);
		}

    if(lt_page_content==NULL){

			  sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);

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
	    close(iFd);
		  /*����html��ʽ����*/
	  }
	  lt_dbfree(dbPtr);
printf("daily report head ok!\n");
 	                                                                     
	 if(element[0]=='1'){  
	 
	  printf("------- �豸״̬  ------- \n");
			/*part2  �豸״̬����*/
	  if(lang==0){//Ch
				sprintf(caLabel,"/usr/bin/perl  /app/ns/html/reportplt/diskstatus.pl >> %sindex.htm",caTempDir);
	   }else if(lang==1){//Eng
				sprintf(caLabel,"/usr/bin/perl  /app/ns/html/reportplt_en/diskstatus.pl >> %sindex.htm",caTempDir);
	   }
	   system(caLabel);
       printf("daily report part2 ok!\n");	  
	 
     }if(element[1]=='1'){
     	
		 printf("-------  �����������  ------- \n");
		 	/*part3 ��������*/
	{
		//int  accountTimes=1;
	   lTime1 = nasCvtLongTime(caSdate,"00:00:01");
      lTime2 = nasCvtLongTime(caEdate,"23:59:59");     
	  unsigned long iMaxItem;
	  struct nasFlowCount_s {
        char          caItem[16];
        unsigned long long lDbytes;
        unsigned long long lUbytes;
        unsigned long long lTbytes;
    } sCount[35];
    memset((char *)&sCount,0,35*sizeof(struct nasFlowCount_s));

	   printf(" caSdate : %s ; caEdate : %s ;lTime1 : %lu ;lTime2 :%lu \n",caSdate,caEdate,lTime1,lTime2); 

  if(strcmp(caSdate,caEdate)==0){
		 
		    lStep = 3600;
//        if(lTime1 == 0) {
//            lTime1 = lTime2-31*lStep;     
//        }
//        if(lTime2>(lTime1+31*lStep)){
//        	lTime2=lTime1+31*lStep;
//        }
        // lTime2=lTime1+31*lStep;
        if(lTime2>time(0)){
			   lTime2=time(0);
		    }
        lTime0 = lTime1;
    
  sprintf(sqlBuf,"select sdate,substring(stime,1,2),avg(ubytes),avg(dbytes)  from nasflowlog  where  rtime >= %lu and rtime <= %lu  and dev='' group by  sdate, substring(stime,1,2)  order by sdate asc, substring(stime,1,2) asc;",
               lTime1,lTime2);

printf("........%s\n",sqlBuf);

    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
    
    if(tempCursor == NULL) {

		sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
    	system(caLabel);/*����Ŀ¼�����ڴ����־*/ 
        return 0;

    }
    lMaxBytes = 1;

    iMax = 0;

    tempRow= ltDbFetchRow(tempCursor);

    while(tempRow!=NULL){  

        sprintf(caItem,"%s %s:00",tempRow[0],tempRow[1]); 

		    lUbytes=atoll(tempRow[2])/1024;

        lDbytes=atoll(tempRow[3])/1024;

        if(lMaxBytes <= (lUbytes + lDbytes)) {

           lMaxBytes = (lUbytes + lDbytes);

        }

		    sprintf(sCount[iMax].caItem,"%s",caItem);
        sCount[iMax].lUbytes = lUbytes ;
        sCount[iMax].lDbytes = lDbytes ;
        iMax++;

        tempRow= ltDbFetchRow(tempCursor);

    }
  

    ltDbCloseCursor(tempCursor);
     
    iMaxItem = iMax;

/*  ����ͼ��  */
      dbPtr=lt_dbinit();
     sprintf(caLabel,"%sdata.ini",caTempDir);
     iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
	  if(iFd == (-1)) {
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
		    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
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
				"abyte",LT_TYPE_LONGLONG,sCount[i].lUbytes+sCount[i].lDbytes);

		 sprintf(caLabel,"%s,%llu,%llu,%llu\r\n",sCount[i].caItem,sCount[i].lUbytes+sCount[i].lDbytes,sCount[i].lDbytes,sCount[i].lUbytes);
 
		  write(iFd, caLabel, strlen(caLabel));	

      }
        close(iFd); 
		sprintf(caLabel,"/app/ns/bin/cgi/outflowplt.pl  %sdata.ini %soutflow1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));

		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"file1","outflow1.jpg");


		sprintf(caLabel,"/app/ns/bin/cgi/outflowpltline.pl  %sdata.ini %soutflow2.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));

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
        // lTime2=lTime1+31*lStep;
        if(lTime2>lTime){printf("lTime:%lu",lTime);
					lTime2=lTime;
		}
        lTime0 = lTime1;  printf(" caSdate : %s ; caEdate : %s ;lTime1 : %lu ;lTime2 :%lu \n",caSdate,caEdate,lTime1,lTime2); 
        iMaxItem = 32;
        for(i=0;i<iMaxItem;i++) {
	    			nasCvtStime(lTime0,caSdate,caTime);
					memset(sCount[i].caItem,0,16);
					lTime0 = lTime0 + lStep;
				    sCount[i].lDbytes=0;
				    sCount[i].lUbytes=0;
        }
  //printf(" caSdate : %s ; caEdate : %s ;lTime1 : %lu ;lTime2 :%lu \n",caSdate,caEdate,lTime1,lTime2); 
        sprintf(sqlBuf,"select sdate,avg(ubytes),avg(dbytes) from nasflowlog where rtime >= %lu and rtime <= %lu and dev='' group by sdate limit 0,30",lTime1,lTime2);
        tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
   printf("sqlBuf:::: %s\n",sqlBuf);
        
    if(tempCursor == NULL) { 
			sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
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

/*  ����ͼ��  */
    

    nasCvtStime(lTime1,caSdate1,caTime1);
    nasCvtStime(lTime2,caSdate2,caTime2);
    caTime1[5]=0;
    caTime2[5]=0;
    sprintf(caLabel,"%s %s--%s %s",caSdate1,caTime1,caSdate2,caTime2);
   

     dbPtr=lt_dbinit();
     sprintf(caLabel,"%sdata.ini",caTempDir);
     iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
	  if(iFd == (-1)) {
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
		    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
		    		ltDbCloseCursor(tempCursor);

		            return 0;
		}
     

 printf(caLabel,"%s %s--%s %s",caSdate1,caTime1,caSdate2,caTime2);
     lt_dbput_rootvars(dbPtr,1,"lab",caLabel);   
     lt_dbput_rootvars(dbPtr,1,"reportname",reportname);  
     
    lt_dbput_rootvars(dbPtr,1,"xunit","Day");
      
    
    tablePtr=lt_dbput_table(dbPtr,"list2");
    for(i=0;i<iMaxItem;i++) {
        lt_dbput_recordvars(tablePtr,4,
				"mytime",LT_TYPE_STRING,sCount[i].caItem,
				"ubyte",LT_TYPE_LONGLONG,sCount[i].lUbytes,
				"dbyte",LT_TYPE_LONGLONG,sCount[i].lDbytes,
				"abyte",LT_TYPE_LONGLONG,sCount[i].lUbytes+sCount[i].lDbytes);

		 sprintf(caLabel,"%s,%llu,%llu,%llu\r\n",sCount[i].caItem,sCount[i].lUbytes+sCount[i].lDbytes,sCount[i].lDbytes,sCount[i].lUbytes);

		  write(iFd, caLabel, strlen(caLabel));	

      }
        close(iFd); 
		sprintf(caLabel,"/app/ns/bin/cgi/outflowplt.pl  %sdata.ini %soutflow1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));

		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"file1","outflow1.jpg");


		sprintf(caLabel,"/app/ns/bin/cgi/outflowpltline.pl  %sdata.ini %soutflow2.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));

		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"file2","outflow2.jpg");


	}     

    
     if(element[2]=='0'){printf(" wu ֱ��ͼ\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart1","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend1","-->");	 
	 }if(element[3]=='0'){printf(" wu ����ͼ\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart2","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend2","-->");	 
	 } 
 

    if(lang==0){//Ch
		 lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart3.htm",dbPtr->doc,0);
	}else if(lang==1){//Eng
		 lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart3.htm",dbPtr->doc,0);	
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
}
    printf("daily report part3 ok\n");

		 		 
	 }if(element[4]=='1'||checkb[1]=='1'){
	 	
	 	printf("------- �������  ------- \n");
	 	 /*part4 ���񱨸�*/
  {
  	char       oldname[256];
    char       caSrv[64];
    int        srvindex;
	char       srvStr[64];

  	nasTimeGetDate(caSdate1,lTime1);
    nasTimeGetDate(caSdate2,lTime2);
  	sprintf(sqlBuf,"select service,sum(ubytes+dbytes)/1024+1 as abyte ,sum(ctime) as arequest \
 ,sum(onlinetime) as atime 	from nassrvreport where sdate>='%s' and sdate<='%s' group by service order by abyte desc ",caSdate1,caSdate2);
   
   printf("���񱨸� : sqlBuf:%s\n",sqlBuf);
   
   tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
	 if(tempCursor == NULL) {
		      sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);

	    		system(caLabel);/*����Ŀ¼�����ڴ����־*/

	        return 0;
	 }
	 sprintf(caLabel,"%sdata.ini",caTempDir);
     iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
	 if(iFd == (-1)) {
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
		    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
		    		ltDbCloseCursor(tempCursor);

		            return 0;
		}	
		
	dbPtr=lt_dbinit();
    lt_db_htmlpage(dbPtr,"gb2312");
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
								"st",LT_TYPE_STRING,time2str(atol(tempRow[3])) ); 
    	      
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
		
		if(element[5]=='0'){printf(" wu ȫ������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart5","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend5","-->");	 
	    }if(element[6]=='0'){printf(" wu ���Ż���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart6","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend6","-->");	 
	    }if(element[7]=='0'){printf(" wu �û���������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart7","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend7","-->");	 
	    }if(element[8]=='0'){printf(" wu �û����ӻ���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart8","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend8","-->");	 
	    }	if(element[9]=='0'){printf(" wu ���ڻ���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart9","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend9","-->");	 
	    }if(element[10]=='0'){printf(" wu ����������������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart10","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend10","-->");	 
	    }if(element[11]=='0'){printf(" wu �����������ӻ���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart11","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend11","-->");	 
	    }

		sprintf(caLabel,"/app/ns/bin/cgi/onlinesrv1.pl  %sdata.ini %ssrvreport.gif %llu ",caTempDir,caTempDir,lMaxBytes);

		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"piechart","<img src=\"srvreport.gif\">" );
	 
		
    if(lang==0){//Ch
		  lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart4.htm",dbPtr->doc,0);
	 }else if(lang==1){//Eng
		  lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart4.htm",dbPtr->doc,0);
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
	
  }
     printf("daily report part4 ok\n");
				// ������� ��ر���  
	  }if(element[5]=='1'){printf("��ر���---- ȫ������ %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);
	 }if(element[6]=='1'){printf("��ر���---- ���Ż��� %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,2,caTempDir,lang);
	 }if(element[7]=='1'){printf("��ر���---- �û��������� %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);
	 }if(element[8]=='1'){printf("��ر���---- �û����ӻ��� %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,7,caTempDir,lang);
	 }if(element[9]=='1'){printf("��ر���---- ���ڻ��� %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,4,caTempDir,lang);
	 }if(element[10]=='1'){printf("��ر���---- ���������������� %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,5,caTempDir,lang);
	 }if(element[11]=='1'){printf("��ر���---- �����������ӻ��� %s -- %s  \n",caSdate1,caSdate2);
				 srvreport(caSdate1,caSdate2,userid,gid,6,caTempDir,lang);
				 
	 }if(element[12]=='1'||checkb[2]=='1'){
	 	
		   printf("------- ������������/  ��������ܼ�  ------- \n");
		   
	/*part5  24Сʱ��������*/
	{
				struct nasFlowCount_s {
		        char          caItem[16];
		        unsigned long long lDbytes;
		        unsigned long long lUbytes;
		        unsigned long long lTbytes;
		        unsigned long long lConTime;
    		} sCount[35];
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

        for(i=0;i<iMaxItem;i++) {
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
          sprintf(sqlBuf,"select stime,sum(ubytes),sum(dbytes) \
from nassrvreport \
where ((sdate > '%s') or(sdate = '%s' and stime>='%s')) and \
((sdate < '%s') or(sdate = '%s' and stime<='%s')) \
group by stime ",caSdate1,caSdate1,caTime1,caSdate2,caSdate2,caTime2);
	   }else{
				if(userid!=-1){		   
	       sprintf(sqlBuf,"select stime,sum(ubytes),sum(dbytes) \
from nassrvreport \
where  userid = %d and ((sdate > '%s') or(sdate = '%s' and stime>='%s')) and \
((sdate < '%s') or(sdate = '%s' and stime<='%s')) \
group by stime ",userid,caSdate1,caSdate1,caTime1,caSdate2,caSdate2,caTime2);
	     }else{
	     		sprintf(sqlBuf,"select stime,sum(ubytes),sum(dbytes) \
from nassrvreport a,nasuser b  \
where a.userid=b.userid and  b.groupid = %d and ((sdate > '%s') or(sdate = '%s' and stime>='%s')) and \
((sdate < '%s') or(sdate = '%s' and stime<='%s')) \
group by stime ",gid,caSdate1,caSdate1,caTime1,caSdate2,caSdate2,caTime2);
	     
	     }
	   
	    }printf("sqlBuf:%s\n",sqlBuf);
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
	      
	     // sprintf(sqlBuf,"select stime,sum(ubytes),sum(dbytes) from nassrvreport where sdate = '%s' group by stime ",G_sdate);
	     if(gid==-1){
        			sprintf(sqlBuf,"select sdate,sum(ubytes),sum(dbytes) \
from nassrvreport where ((sdate > '%s') or(sdate = '%s' and stime>='%s')) and \
((sdate < '%s') or(sdate = '%s' and stime<='%s')) group by sdate limit 0,30",
				caSdate1,caSdate1,caTime1,caSdate2,caSdate2,caTime2);

       }else{
          if(userid!=-1){
       	     sprintf(sqlBuf,"select sdate,sum(ubytes),sum(dbytes) \
from nassrvreport where userid = %d and ((sdate > '%s') or(sdate = '%s' and stime>='%s')) and \
((sdate < '%s') or(sdate = '%s' and stime<='%s')) \
group by sdate  limit 0,30",userid,caSdate1,caSdate1,caTime1,caSdate2,caSdate2,caTime2);
				}else{
						 sprintf(sqlBuf,"select sdate,sum(ubytes),sum(dbytes) \
from nassrvreport a,nasuser b where a.userid = b.userid and b.groupid=%d and \
((sdate > '%s') or(sdate = '%s' and stime>='%s')) and ((sdate < '%s') or(sdate = '%s' and stime<='%s')) \
group by sdate  limit 0,30",gid,caSdate1,caSdate1,caTime1,caSdate2,caSdate2,caTime2); 
			  }
       
      } 
printf("sqlBuf:%s\n",sqlBuf);
	      tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);

		  lt_dbput_rootvars(dbPtr,1,"xunit","Day");

	}
	      
	      if(tempCursor == NULL) { 
				sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir); 
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
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
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

				"abyte",LT_TYPE_LONGLONG,sCount[i].lUbytes+sCount[i].lDbytes);

				 sprintf(caLabel,"%s,%llu,%llu,%llu\r\n",sCount[i].caItem,sCount[i].lUbytes+sCount[i].lDbytes,sCount[i].lDbytes,sCount[i].lUbytes);

		         write(iFd, caLabel, strlen(caLabel));	

   }
        close(iFd); 
		sprintf(caLabel,"/app/ns/bin/cgi/outflowplt.pl  %sdata.ini %sflowreports1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));

		system(caLabel);	  
		lt_dbput_rootvars(dbPtr,1,"file1","flowreports1.jpg");


		sprintf(caLabel,"/app/ns/bin/cgi/outflowpltline.pl  %sdata.ini %sflowreports2.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMaxBytes+1));

		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"file2","flowreports2.jpg");

   
     if(element[13]=='0'){printf(" wu ֱ��ͼ\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart13","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend13","-->");	 
	 }if(element[14]=='0'){printf(" wu ����ͼ\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart14","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend14","-->");	 
	 }if(element[15]=='0'){printf(" wu �������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart15","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend15","-->");	 
	 }if(element[16]=='0'){printf(" wu Сʱ����\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart16","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend16","-->");	 
	 }if(element[17]=='0'){printf(" wu �û�����������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart17","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend17","-->");	 
	 }if(element[18]=='0'){printf(" wu �û�����������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart18","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend18","-->");	 
	 }if(element[19]=='0'){printf(" wu �û�����������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart19","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend19","-->");	 
	 }if(element[20]=='0'){printf(" wu ���Ż���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart20","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend20","-->");	 
	 }if(element[21]=='0'){printf(" wu ������Ա����\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart21","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend21","-->");	 
	 }if(element[22]=='0'){printf(" wu �������ڻ���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart22","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend22","-->");	 
	 }if(element[23]=='0'){printf(" wu �����������--�������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart23","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend23","-->");	 
	 }if(element[24]=='0'){printf(" wu �����������--��Сʱ����\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart24","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend24","-->");	 
	 }if(element[25]=='0'){printf(" wu �����������--�û����Ӵ�������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart25","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend25","-->");	 
	 }if(element[26]=='0'){printf(" wu �����������--���Ż���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart26","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend26","-->");	 
	 }if(element[27]=='0'){printf(" wu �����������--������Ա����\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart27","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend27","-->");	 
	 }if(element[28]=='0'){printf(" wu �����������--�������ڻ���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart28","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend28","-->");	 
	 }
 
    if(lang==0){//Ch
       lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart5.htm",dbPtr->doc,0);
    }else if(lang==1){//Eng
	  lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart5.htm",dbPtr->doc,0);
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
	
  }
     printf("daily report part5 ok\n");
				  // ��������   ��ر���
	  }if(element[15]=='1'){printf("��ر���---- ������������-������� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);
				 
	 }if(element[16]=='1'){printf("��ر���---- ������������- ��Сʱ����%s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,2,caTempDir,lang);
				 
	 }if(element[17]=='1'){printf("��ر���---- ������������-�û����������� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);
				 
	 }if(element[18]=='1'){printf("��ر���---- ������������-�û����������� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,4,caTempDir,lang);
				 
	 }if(element[19]=='1'){printf("��ر���---- ������������-�û����������� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,5,caTempDir,lang);
				 
	 }if(element[20]=='1'){printf("��ر���---- ������������-���Ż��� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,6,caTempDir,lang);
				 
	 }if(element[21]=='1'){printf("��ر���---- ������������-������Ա���� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,7,caTempDir,lang);
				 
	 }if(element[22]=='1'){printf("��ر���---- ������������-�������ڻ��� %s -- %s  \n",caSdate1,caSdate2);
				 connectflow(caSdate1,caSdate2,userid,gid,8,caTempDir,lang);
				 
	 }
	 if(element[23]=='1'){printf("��ر���----�����������-������� %s -- %s  \n",caSdate1,caSdate2);
				 connectreport(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);
				 
	 }if(element[24]=='1'){printf("��ر���---- �����������-��Сʱ���� %s -- %s  \n",caSdate1,caSdate2);
				 connectreport(caSdate1,caSdate2,userid,gid,2,caTempDir,lang);
				 
	 }if(element[25]=='1'){printf("��ر���---- �����������-�û����Ӵ������� %s -- %s  \n",caSdate1,caSdate2);
				 connectreport(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);
				 
	 }if(element[26]=='1'){printf("��ر���---- �����������-���Ż��� %s -- %s  \n",caSdate1,caSdate2);
				 connectreport(caSdate1,caSdate2,userid,gid,6,caTempDir,lang);
				 
	 }if(element[27]=='1'){printf("��ر���----�����������- ������Ա���� %s -- %s  \n",caSdate1,caSdate2);
				 connectreport(caSdate1,caSdate2,userid,gid,7,caTempDir,lang);
				 
	 }if(element[28]=='1'){
				  printf("��ر���---- �����������- �������ڻ��� %s -- %s  \n",caSdate1,caSdate2);
				 connectreport(caSdate1,caSdate2,userid,gid,8,caTempDir,lang);
	 }
	   
	  
	 if(element[29]=='1'||checkb[3]=='1'){
	 		 
 
 
 printf("------- ���ű���  ------- \n");
 			/*part7 group report*/
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

 printf("%s , %s",caSdate1,caSdate2); 
//	sprintf(sqlBuf,"select c.groupname,c.groupname,sum(a.ubytes+dbytes)/1000+1 as mybytes,sum(a.ctime) \
//from nasipreport a,nasuser b ,nasgroup c where a.sdate = '%s' \
//and a.userid = b.userid and  b.groupid=c.groupid group by c.groupid  \
//order by mybytes desc  ",G_sdate);

	sprintf(sqlBuf,"select c.groupid,c.groupname,sum(a.flow)/1024+1 as mybytes,sum(a.time) \
from nasuseraccount a,nasuser b ,nasgroup c where a.sdate>='%s' and a.sdate<='%s'  \
and a.userid = b.userid and  b.groupid=c.groupid group by c.groupid  \
order by mybytes desc limit 0,%d ",caSdate1,caSdate2,inttopusernum);


  printf("���ŷ�������::sqlbuf:%s\n",sqlBuf);

  tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor == NULL) {

		sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);

    system(caLabel);/*����Ŀ¼�����ڴ����־*/

    return 0;

  }
  
  sprintf(caLabel,"%sdata.ini",caTempDir);

  iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
	if(iFd == (-1)) {
					  sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);

		    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
		    		ltDbCloseCursor(tempCursor);

		        return 0;
	}	

  lMax=0;
    dbPtr=lt_dbinit();
    lt_db_htmlpage(dbPtr,"gb2312");
    tablePtr=lt_dbput_table(dbPtr,"flowlist");
    tempRow= ltDbFetchRow(tempCursor);
    while(tempRow!=NULL){
					xgid[xxxi]=atol(tempRow[0]);
					lt_dbput_recordvars(tablePtr,4,
						"gid",LT_TYPE_STRING,tempRow[0],
						"groupname",LT_TYPE_STRING,tempRow[1],
						"lbyte",LT_TYPE_LONGLONG,atoll(tempRow[2]),
						"ltime",LT_TYPE_STRING,time2str(atol(tempRow[3])));
					sprintf(oldgname,"%s",tempRow[1]);
			    if(atoll(tempRow[2])>lMax){
			    	lMax=atoll(tempRow[2]);
			    }
			    sprintf(caLabel,"%d,%llu\r\n",xxxi+1,atoll(tempRow[2]));
		      write(iFd, caLabel, strlen(caLabel));	
			    xxxi++;
          tempRow= ltDbFetchRow(tempCursor);
    }
    ltDbCloseCursor(tempCursor);
    close(iFd);	
    			 
		sprintf(caLabel,"/app/ns/bin/cgi/onlinesrv1.pl  %sdata.ini %sdeppie.gif %llu ",caTempDir,caTempDir,lMax);
		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"piechart","<img src=\"deppie.gif\">" );
    
    
    /* if(element[33]=='0'){printf(" wu ����ʹ�û���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart33","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend33","-->");	 
	    }*/
		if(element[34]=='0'){printf(" wu ��������ʱ�����\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart34","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend34","-->");	 
	  }
	  
	  if(element[31]=='0'){printf(" wu ͼʾ\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart31","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend31","-->");	 
	 }

    if(lang==0){//Ch
	    lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart7.htm",dbPtr->doc,0);

	  }else if(lang==1){//Eng
		 lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart7.htm",dbPtr->doc,0);

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
	  
	  for(xxxi=0;xxxi<100;xxxi++){
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
				//  			sprintf(sqlBuf,"select a.userid,b.dispname,sum(a.ubytes + a.dbytes)/1024+1 abyte,sum(a.ubytes)/1024+1,sum(a.dbytes)/1024+1, c.groupname from nasipreport a, \
				// nasuser b,nasgroup c where a.sdate = '%s' and a.userid = b.userid and b.groupid=c.groupid  group by a.userid,b.username \
				// order by abyte desc limit 0,%d ",G_sdate,topuser);
				 
				   	sprintf(sqlBuf,"select a.userid,b.dispname,sum(flow)/1024+1 abyte,sum(time), c.groupname from nasuseraccount a, \
 nasuser b,nasgroup c where a.sdate >= '%s' and a.sdate <= '%s' and b.groupid=%d  and a.userid = b.userid and b.groupid=c.groupid  group by a.userid \
 order by abyte desc limit 0,%d ",caSdate1,caSdate2,xgid[xxxi],topuser);
				    printf("�����û�::sql:%s\n",sqlBuf);
					iTemp=0;
				    lMax=0;
				    
				    dbPtr=lt_dbinit();
				    lt_db_htmlpage(dbPtr,"gb2312");
				    tablePtr=lt_dbput_table(dbPtr,"flowlist");
				    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
					      if(tempCursor == NULL) {

							sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);

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

							  
								if(lTop[iTemp]>lMax){
									lMax=lTop[iTemp];
								}
								iTemp++;
				                tempRow= ltDbFetchRow(tempCursor);
				    }
				    ltDbCloseCursor(tempCursor);
				

				    sprintf(caLabel,"%sdata.ini",caTempDir);

				      iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
					  if(iFd == (-1)) {
									sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);

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
						sprintf(caLabel,"/app/ns/bin/cgi/onlinesrv1.pl  %sdata.ini %sggg%dflowreport.gif %llu ",caTempDir,caTempDir,xgid[xxxi],lMax);
						 
						system(caLabel);	
						
						sprintf(caLabel,"<img src=\"ggg%dflowreport.gif\"  >",xgid[xxxi]);
						lt_dbput_rootvars(dbPtr,1,"piechart",caLabel);
 

    
			 	 	 sprintf(caLabel,"%sdata.ini",caTempDir);
					 iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
	         if(iFd == (-1)) {
					     sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);
		    		   system(caLabel);//����Ŀ¼�����ڴ����־ 
		    		   ltDbCloseCursor(tempCursor); 
		           return 0;
		       }

					 for(i=0;i<iTemp;i++) {
		
					  sprintf(caLabel,"%d,%llu\r\n",i+1,lTop[i]);

					  write(iFd, caLabel, strlen(caLabel));	

					 }
  
						  
					 close(iFd);	
						 
					 sprintf(caLabel,"/app/ns/bin/cgi/onlinesrv-bar.pl  %sdata.ini %sggg%duserreport1.jpg %llu ",caTempDir,caTempDir,xgid[xxxi],(unsigned long long)(lMax+1));
						 
					 system(caLabel);	

					 sprintf(caTempFile,"ggg%duserreport1.jpg",xgid[xxxi]);
						  
					 lt_dbput_rootvars(dbPtr,1,"file1",caTempFile);     


					if(lang==0){//Ch
							lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart_depart.htm",dbPtr->doc,0);
						}else if(lang==1){//Eng
							lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart_depart.htm",dbPtr->doc,0);
						}

				    if(lt_page_content==NULL){

							  sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�ޱ�������,�޷����ɱ���",caTempDir);
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

  printf("daily report part7 ok\n");
  
	 }
	 
	 if(element[30]=='1'){
	 	
	 	printf("------- ��Ա����  ------- \n");
	 /*part6 �û�����*/
	 
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
//  			sprintf(sqlBuf,"select a.userid,b.dispname,sum(a.ubytes + a.dbytes)/1024+1 abyte,sum(a.ubytes)/1024+1,sum(a.dbytes)/1024+1, c.groupname from nasipreport a, \
// nasuser b,nasgroup c where a.sdate = '%s' and a.userid = b.userid and b.groupid=c.groupid  group by a.userid,b.username \
// order by abyte desc limit 0,%d ",G_sdate,topuser);
 
   	   sprintf(sqlBuf,"select a.userid,b.dispname,sum(flow)/1024+1 abyte,sum(time), c.groupname from nasuseraccount a, \
 nasuser b,nasgroup c where a.sdate >= '%s' and  a.sdate <= '%s' and a.userid = b.userid and b.groupid=c.groupid  group by a.userid \
 order by abyte desc limit 0,%d ",caSdate1,caSdate2,topuser-1);
       printf("�û����棺��sql:%s\n",sqlBuf);
		   iTemp=0;
       lMax=0;
    
		    dbPtr=lt_dbinit();
		    lt_db_htmlpage(dbPtr,"gb2312");
		    tablePtr=lt_dbput_table(dbPtr,"flowlist");
		    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
	      if(tempCursor == NULL) { 
					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir); 
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
printf("lTopId %d %d %d\n",iTemp,lTopId[iTemp],	atol(tempRow[0]));				  
						if(lTop[iTemp]>lMax){
							lMax=lTop[iTemp];
						}
						iTemp++;
		        tempRow= ltDbFetchRow(tempCursor);
		    }
    ltDbCloseCursor(tempCursor);

  
    sprintf(caLabel,"%sdata.ini",caTempDir);

    iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
	  if(iFd == (-1)) {
					  sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir);

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
			 
		sprintf(caLabel,"/app/ns/bin/cgi/onlinesrv1.pl  %sdata.ini %sflowreport.gif %llu ",caTempDir,caTempDir,lMax);

		system(caLabel);	
		lt_dbput_rootvars(dbPtr,1,"piechart","<img src=\"flowreport.gif\">" );
   

//   {
//    
//    char caLabel[128];
//    char caTemp[8192];
//    int i;
//    sprintf(caLabel,"%sdata.ini",caTempDir);
//    iFd = open(caLabel,O_WRONLY | O_CREAT | O_TRUNC);
//	  if(iFd == (-1)) {
//					sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","�޷����������ļ�",caTempDir); 
//		    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
//		    		ltDbCloseCursor(tempCursor);
//
//		            return 0;
//		}	
//
//		for(i=0;i<iTemp;i++) { 
//        ltStrAddF(caTemp,"<value>%llu</value>\n",lTop[i]);
//
//        sprintf(caLabel,"%d,%llu\r\n",i+1,lTop[i]);
//
//		write(iFd, caLabel, strlen(caLabel));	
// 
//    }
//
//		close(iFd);	
//			 
//		sprintf(caLabel,"/app/ns/bin/cgi/onlinesrv-bar.pl  %sdata.ini %suserreport1.jpg %llu ",caTempDir,caTempDir,(unsigned long long)(lMax+1));
//
//		system(caLabel);	
//		lt_dbput_rootvars(dbPtr,1,"file1","userreport1.jpg"); 
//
//
//	 }

	 if(element[31]=='0'){printf(" wu ͼʾ\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart31","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend31","-->");	 
	 }
	  
	 if(lang==0){//Ch
			lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart6.htm",dbPtr->doc,0);
	 }else if(lang==1){//Eng
		  lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart6.htm",dbPtr->doc,0);
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
    

  printf("daily report part6 ok\n");
  
    if(element[32]=='1'){//�����û���վ����
    	  char mytabname[32];
  			nasTimeGetDate(caSdate1,lTime1);
				nasTimeGetDate(caSdate2,lTime2);
				
				dbPtr=lt_dbinit();
        lt_db_htmlpage(dbPtr,"gb2312");
    
				for(iTemp=0;iTemp<inttopusernum;iTemp++){
		    
			    if(lTopId[iTemp]==0){
			    	 break;	
			    }
			    sprintf(sqlBuf,"select a.host ,sum(a.bytes)/1024 as abyte,sum(a.ctime) as atime, sum(a.lcount) as acount,a.urlsort,b.dispname,c.groupname from nashttpreport a, \
 nasuser b,nasgroup c where sdate >= '%s' and sdate <= '%s' and a.userid = b.userid and b.groupid=c.groupid and a.userid=%d group by a.host order by abyte desc limit 0,9",caSdate1,caSdate2,lTopId[iTemp]);
			    printf("user url����sql:%s\n",sqlBuf);
			    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
			    if(tempCursor == NULL) {
							sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
			    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
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
							"urlsort",LT_TYPE_STRING,_ltPubInfo->urlSortName[atol(tempRow[4])].sortname,
							"contime",LT_TYPE_STRING,time2str(atol(tempRow[2]))
							);
			        tempRow= ltDbFetchRow(tempCursor);
			        i++;
			    }
			    ltDbCloseCursor(tempCursor);
	      }
      
       
			 lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart6-1.htm",dbPtr->doc,0);
			 
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
      
	  } 
	 }
	/* if(element[33]=='1'){/////////////////////////////////////////////////////////////////////////////////////
	 			   printf("��ر���---- ����ʹ�û���  %s -- %s  \n",caSdate1,caSdate2);
				   dailyGroupReports(caSdate1,caSdate2,caTempDir);   //�����⣬����ż����;�ϵ� 
	  }*/
	  if(element[34]=='1'){/////////////////////////////////////////////////////////////////////////////////////
				 //��ر��� 
				 printf("��ر���---- ��������ʱ����� %s -- %s  \n",caSdate1,caSdate2);
		 	      usertimereport(caSdate1,caSdate2,caTempDir,gid,lang);
				 
	 }if(element[35]=='1'||element[36]=='1'){
				    // WEB - ǰ20/30/50�����ʴ������վ��
				    
	
	printf("------- WEB - ǰ50�����ʴ������վ��  ------- \n");		    
	/*PART8 WEB REPORT*/
	{ 
		nasTimeGetDate(caSdate1,lTime1);
		nasTimeGetDate(caSdate2,lTime2);
		sprintf(sqlBuf,"select host ,sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from nashttpreport \
where sdate >= '%s' and sdate <= '%s'  group by host order by acount desc limit 0,50",caSdate1,caSdate2);

  printf("WEB����1����sql:%s\n",sqlBuf);
  
    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor == NULL) {
				sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);

    		system(caLabel);/*����Ŀ¼�����ڴ����־*/

        return 0;
    }
    dbPtr=lt_dbinit();
    lt_db_htmlpage(dbPtr,"gb2312");
    tablePtr=lt_dbput_table(dbPtr,"list1");
    tempRow= ltDbFetchRow(tempCursor);
    while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,5,
				"uname",LT_TYPE_STRING,tempRow[0],
				"lbyte",LT_TYPE_LONG,atol(tempRow[1]),
				"ltime",LT_TYPE_STRING,time2str(atol(tempRow[2])),
				"lrequest",LT_TYPE_STRING,tempRow[3],
				"usort",LT_TYPE_STRING,_ltPubInfo->urlSortName[atol(tempRow[4])].sortname);
        tempRow= ltDbFetchRow(tempCursor);
    } 
    ltDbCloseCursor(tempCursor);


   	sprintf(sqlBuf,"select sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from nashttpreport \
where sdate >= '%s' and sdate <= '%s'  group by urlsort order by acount desc ",caSdate1,caSdate2);

  printf("WEB����3����sql:%s\n",sqlBuf);
  
    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor == NULL) {
				sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);

    		system(caLabel);/*����Ŀ¼�����ڴ����־*/

        return 0;
    }

    tablePtr=lt_dbput_table(dbPtr,"list3");
    tempRow= ltDbFetchRow(tempCursor);
    while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,4,
				"lbyte",LT_TYPE_LONG,atol(tempRow[0]),
				"ltime",LT_TYPE_STRING,time2str(atol(tempRow[1])),
				"lrequest",LT_TYPE_STRING,tempRow[2],
				"usort",LT_TYPE_STRING,_ltPubInfo->urlSortName[atol(tempRow[3])].sortname);
        tempRow= ltDbFetchRow(tempCursor);
    } 
    ltDbCloseCursor(tempCursor);


/*top30 ����������*/
	sprintf(sqlBuf,"select host ,sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from nashttpreport \
where sdate >= '%s' and sdate <= '%s' group by host order by abyte desc limit 0,50",caSdate1,caSdate2);
printf("WEB����2����sql:%s\n",sqlBuf);

    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor == NULL) {
				sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);

    		system(caLabel);/*����Ŀ¼�����ڴ����־*/

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
				"usort",LT_TYPE_STRING,_ltPubInfo->urlSortName[atol(tempRow[4])].sortname);
        tempRow= ltDbFetchRow(tempCursor);
    }
    ltDbCloseCursor(tempCursor);
    
    
    
    sprintf(sqlBuf,"select sum(bytes)/1024 as abyte,sum(ctime) as atime, sum(lcount) as acount,urlsort from nashttpreport \
where sdate >= '%s' and sdate <= '%s'  group by urlsort order by abyte desc ",caSdate1,caSdate2);

    printf("WEB����4����sql:%s\n",sqlBuf);  
    
    tempCursor = ltDbOpenCursor(G_DbCon,sqlBuf);
    if(tempCursor == NULL) {
				sprintf(caLabel,"/bin/echo '%s' > %serrmsg.ini","���ݿ����,�޷����ɱ���",caTempDir);
    		system(caLabel);/*����Ŀ¼�����ڴ����־*/
        return 0;
    }

    tablePtr=lt_dbput_table(dbPtr,"list4");
    tempRow= ltDbFetchRow(tempCursor);
    while(tempRow!=NULL){
				lt_dbput_recordvars(tablePtr,4,
				"lbyte",LT_TYPE_LONG,atol(tempRow[0]),
				"ltime",LT_TYPE_STRING,time2str(atol(tempRow[1])),
				"lrequest",LT_TYPE_STRING,tempRow[2],
				"usort",LT_TYPE_STRING,_ltPubInfo->urlSortName[atol(tempRow[3])].sortname);
        tempRow= ltDbFetchRow(tempCursor);
    } 
    ltDbCloseCursor(tempCursor);
    
    
    
    	/* ������  */
		memset(caSdate1,0,sizeof(caSdate1));
    memset(caSdate2,0,sizeof(caSdate2));
    nasCvtStime(lTime1,caSdate1,caTime1);
    nasCvtStime(lTime2,caSdate2,caTime2);
    caTime1[5]=0;
    caTime2[5]=0;
    sprintf(caLabel,"Web Report:  %s",caSdate1);
   
	 lt_dbput_rootvars(dbPtr,1,"lab",caLabel);

    if(element[35]=='0'){printf(" wu ���ʴ������վ��\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart35","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend35","-->");	 
	 }if(element[36]=='0'){printf(" wu �����������վ��\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart36","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend36","-->");	 
	 }
	  if(element[37]=='0'){printf(" wu ȫ������\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart37","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend37","-->");	 
	 }if(element[38]=='0'){printf(" wu ���Ż���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart38","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend38","-->");	 
	 }if(element[39]=='0'){printf(" wu �û����� \n");
			lt_dbput_rootvars(dbPtr,1,"hidestart39","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend39","-->");	 
	 }if(element[40]=='0'){printf(" wu ���ڻ���\n");
			lt_dbput_rootvars(dbPtr,1,"hidestart40","<!--");
 			lt_dbput_rootvars(dbPtr,1,"hideend40","-->");	 
     }
  
    if(lang==0){//Ch
       lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart8.htm",dbPtr->doc,0);
   }else if(lang==1){//Eng
	   lt_page_content=ltPltFileParse("/app/ns/html/reportplt_en/dailyreportpart8.htm",dbPtr->doc,0);
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
	
  }
     printf("daily report part8 ok\n");
			 

} 
 if(element[37]=='1'){ 
				 //��ر��� 
				  printf("��ر���---- ȫ������ %s -- %s  \n",caSdate1,caSdate2); 
				  webreport(caSdate1,caSdate2,userid,gid,1,caTempDir,lang);
} if(element[38]=='1'){ 
				 //��ر��� 
				 printf("��ر���---- ���Ż��� %s -- %s  \n",caSdate1,caSdate2);
		 	      webreport(caSdate1,caSdate2,userid,gid,2,caTempDir,lang);		 
} if(element[39]=='1'){ 
				 //��ر��� 
				 printf("��ر���---- �û����� %s -- %s  \n",caSdate1,caSdate2);
		 	      webreport(caSdate1,caSdate2,userid,gid,3,caTempDir,lang);			 
} if(element[40]=='1'){ 
				 //��ر��� 
				 printf("��ر���---- ���ڻ��� %s -- %s  \n",caSdate1,caSdate2);
		 	     webreport(caSdate1,caSdate2,userid,gid,4,caTempDir,lang);			 
}

/*PART10*/
{
	dbPtr=lt_dbinit();
  lt_db_htmlpage(dbPtr,"gb2312");
	lt_page_content=ltPltFileParse("/app/ns/html/reportplt/dailyreportpart10.htm",dbPtr->doc,0);

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
	 
}

  chdir(caTempDir);

  //system("/app/ns/java/html2fo/html2fo  index.htm index.fo ");

  //chdir("/app/ns/java/fop-0.20.5");

  //system("/app/ns/java/jdk1.6.0_01/jre/bin/java -classpath /app/ns/java/fop-0.20.5/:/app/ns/java/fop-0.20.5/lib/xml-apis.jar:/app/ns/java/fop-0.20.5/lib/xercesImpl-2.2.1.jar:/app/ns/java/fop-0.20.5/lib/xalan-2.4.1.jar:/app/ns/java/fop-0.20.5/lib/batik.jar:/app/ns/java/fop-0.20.5/lib/avalon-framework-cvs-20020806.jar:/app/ns/java/fop-0.20.5/build/fop.jar   myfop index.fo index.pdf");
 //system(caLabel);
   sprintf(caLabel,"/app/ns/bin/html2mail  %s index.htm %sindex.mht report %s",caTempDir,caTempDir,email);
   printf("change to mht :: %s\n",caLabel);
   system(caLabel);

  system("tar -cvf report.tar *");
  sprintf(caLabel,"/bin/rm  %sproccess.ini",caTempDir);
  system(caLabel);
  sprintf(caLabel,"/bin/rm  %serrmsg.ini",caTempDir);
  system(caLabel);
 
  return 0;
    
}


/*1 ���� 2���� */
/*1��2�Ǳ����*/
int main(int argc,char **argv){
 
  int typ; 
  long tempIndex;
  int iPid;
  int pstatus; 
  
  char caFile[236];
  char caFile2[236];
  char temp[123];
  
  typ=atoi(argv[1]);

  tempIndex=atol(argv[2]);
	  
	if(typ==0){//ÿ�� 
	   printf("ÿ�� :: \n");
	   sprintf(caFile,"/app/ns/conlog/report/page_data/%ld/info.ini",tempIndex);
	   bcCnfGetValue_s(caFile,"reportname",reportname); 

	}if(typ==1){//ÿ�� 
	   printf("ÿ��  :: \n");
	   sprintf(caFile,"/app/ns/conlog/report/page_data/%ld/info.ini",tempIndex);
	   bcCnfGetValue_s(caFile,"reportname",reportname);  

	}
	if(typ==2){//���� 
	   printf("����  :: \n");
	   sprintf(caFile,"/app/ns/conlog/report/page_data/%ld/info.ini",tempIndex);
	   sprintf(caFile2,"/app/ns/conlog/report/page_data");
	   sprintf(temp,"%ld",tempIndex);printf("========%s\n",temp);
	    
	   sprintf(caSdates,"%s", bcCnfGetValueS(caFile2,temp,"sdate"));
	   sprintf(caEdates,"%s", bcCnfGetValueS(caFile2,temp,"edate"));
	   sprintf(reportname,"%s", bcCnfGetValueS(caFile2,temp,"rpname"));

	}
    bcCnfGetValue_s(caFile,"element",element); 
    bcCnfGetValue_s(caFile,"checkb",checkb); 
    bcCnfGetValue_s(caFile,"gid",gids);  
    bcCnfGetValue_s(caFile,"userid",userids);
	  bcCnfGetValue_s(caFile,"email",email);
	  bcCnfGetValue_s(caFile,"language",language);
    
    memset(topusernum,0,sizeof(topusernum));
    bcCnfGetValue_s(caFile,"topusernum",topusernum);  
    inttopusernum=0;
    inttopusernum=atol(topusernum);
    if(inttopusernum>99){
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
 	
 	deployscope=typ;
	 
	 
	  sprintf(dbName,"%s",bcCnfGetValueS("/etc/gnm/conf","db","dbname"));
    sprintf(dbUser,"%s",bcCnfGetValueS("/etc/gnm/conf","db","dbuser"));
    sprintf(dbPass,"%s",bcCnfGetValueS("/etc/gnm/conf","db","dbpass"));
       
    iPid = fork();  
		if(iPid == 0) {
			    char *p;
			    int  intMaxShmSize;
			    int  intShmKey;
			    
			    p=bcCnfGetValueS("/etc/gnm/conf","Shm", "maxshmsize");
					if(p==NULL){
						fprintf(stderr,"Start applicatin error: maxshmsize is NULL!\n");
						 _exit(0);
					}  
					intMaxShmSize=atol(p);
				
					/*��ȡϵͳshmKey*/
					p=bcCnfGetValueS("/etc/gnm/conf","Shm", "shmkey");
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

				initPub(lt_MMHead);
			  G_DbCon=ltDbConnect(dbUser,dbPass,dbName);
		    if (G_DbCon==NULL){
						printf("report:can't open db\n");
						_exit(0);
		    }
		    signal (SIGALRM, catch_alarm);
    		alarm (3600);
		    dailyReport(tempIndex);  
		  
			  ltDbClose(G_DbCon);
         _exit(0);
    }
    wait(&pstatus);
 
    return 0;
}




