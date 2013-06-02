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


//�������ҳ��
int sysclean(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	ltDbHeadPtr dbPtr;
	char *date=NULL;
	if(ltMsgGetVar_s(ltMsgPk,"date")){
		date=ltMsgGetVar_s(ltMsgPk,"date"); 
	}
	dbPtr=lt_dbinit();
  lt_db_htmlpage(dbPtr,"utf-8");
  lt_dbput_rootvars(dbPtr,1,"date",date);
  lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/manager/sysclean.htm",dbPtr->head,0);
  ltMsgFree(ltMsgPk);
  lt_dbfree(dbPtr);
  return 0;
}



//��������ύ����
int msaCleanAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{     
	                                                            
			long cachr1=0,cachr2=0,cachr3=0,cachr4=0,cachr5=0;
			long cachr6=0,cachr7=0,cachr8=0,cachr9=0,cachr10=0; 
			long cachr11=0,cachr12=0,cachr13=0,cachr14=0,cachr15=0; 
			long cachr16=0,cachr17=0,cachr18=0,cachr19=0,cachr20=0; 
			long cachr21=0,cachr22=0,cachr23=0,cachr24=0,cachr25=0,cachr26=0; 
			char strSql[2048];		                                       
			char *sdate=NULL;
			char caTempDir[512];
			char proIniDir[512];
			char caLabel[1024];
			ltDbCursor *tempCursor;
      LT_DBROW tempRow;  
			
			if(ltMsgGetVar_s(ltMsgPk,"chr1")){
				 cachr1=atol(ltMsgGetVar_s(ltMsgPk,"chr1")); 
			}
			
		  if(ltMsgGetVar_s(ltMsgPk,"chr2")){
				 cachr2=atol(ltMsgGetVar_s(ltMsgPk,"chr2")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr3")){
				 cachr3=atol(ltMsgGetVar_s(ltMsgPk,"chr3")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr4")){
				 cachr4=atol(ltMsgGetVar_s(ltMsgPk,"chr4")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr5")){
				 cachr5=atol(ltMsgGetVar_s(ltMsgPk,"chr5")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr6")){
				 cachr6=atol(ltMsgGetVar_s(ltMsgPk,"chr6")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr7")){
				 cachr7=atol(ltMsgGetVar_s(ltMsgPk,"chr7")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr8")){
				 cachr8=atol(ltMsgGetVar_s(ltMsgPk,"chr8")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr9")){
				 cachr9=atol(ltMsgGetVar_s(ltMsgPk,"chr9")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr10")){
				 cachr10=atol(ltMsgGetVar_s(ltMsgPk,"chr10")); 
			}
			
		  if(ltMsgGetVar_s(ltMsgPk,"chr11")){
				 cachr11=atol(ltMsgGetVar_s(ltMsgPk,"chr11")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr12")){
				 cachr12=atol(ltMsgGetVar_s(ltMsgPk,"chr12")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr13")){
				 cachr13=atol(ltMsgGetVar_s(ltMsgPk,"chr13")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr14")){
				 cachr14=atol(ltMsgGetVar_s(ltMsgPk,"chr14")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr15")){
				 cachr15=atol(ltMsgGetVar_s(ltMsgPk,"chr15")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr16")){
				 cachr16=atol(ltMsgGetVar_s(ltMsgPk,"chr16")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr17")){
				 cachr17=atol(ltMsgGetVar_s(ltMsgPk,"chr17")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr18")){
				 cachr18=atol(ltMsgGetVar_s(ltMsgPk,"chr18")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr19")){
				 cachr19=atol(ltMsgGetVar_s(ltMsgPk,"chr19")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr20")){
				 cachr20=atol(ltMsgGetVar_s(ltMsgPk,"chr20")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr21")){
				 cachr21=atol(ltMsgGetVar_s(ltMsgPk,"chr21")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr22")){
				 cachr22=atol(ltMsgGetVar_s(ltMsgPk,"chr22")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr23")){
				 cachr23=atol(ltMsgGetVar_s(ltMsgPk,"chr23")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr24")){
				 cachr24=atol(ltMsgGetVar_s(ltMsgPk,"chr24")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr25")){
				 cachr25=atol(ltMsgGetVar_s(ltMsgPk,"chr25")); 
			}
			
			if(ltMsgGetVar_s(ltMsgPk,"chr26")){
				 cachr26=atol(ltMsgGetVar_s(ltMsgPk,"chr26")); 
			}
			
			
      if(ltMsgGetVar_s(ltMsgPk,"sdate")){
      	sdate=ltMsgGetVar_s(ltMsgPk,"sdate");
      }
      
			
		  ltMsgPk->msgpktype=1;
		  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\r\n","lthtml",LT_TYPE_STRING,"0");
	    ltMsgFree(ltMsgPk);
	    
	    memset(proIniDir,0,sizeof(proIniDir));
	    sprintf(proIniDir,"/datacenter/msa/process.ini");	 	

			if(cachr1==1){ //��������									
   					if(strlen(sdate)>0){   
   						  //��ϸ���ʼ�¼  Ŀ¼�ļ� 						     
   						  sprintf(caTempDir,"/datacenter/msa/httpsearch"); 
   						  if(ltFileIsExist(caTempDir)==1) {    	
						    	  if(chdir(caTempDir)==0){
						    	 	  sprintf(caLabel,"/bin/rm -rf *");
						    	 	  system(caLabel);									    	 	  
						    	 	  sprintf(caLabel,"echo 'httpsearch'> %s",proIniDir);
							        system(caLabel);
							        sleep(1);
				       
						    	  }  						 																  	    	 
						    } 				
   						    						  		  
   						  sprintf(caTempDir,"/datacenter/msa/ipblocksearch");
   						  if(ltFileIsExist(caTempDir)==1) {    	
						    	  if(chdir(caTempDir)==0){
						    	 	  sprintf(caLabel,"/bin/rm -rf *");
						    	 	  system(caLabel);									    	 	  
						    	 	  sprintf(caLabel,"echo 'ipblocksearch'> %s",proIniDir);
							        system(caLabel);
							        sleep(1);
				       
						    	  }  						 																  	    	 
						    }
   						  
   						  
   						  sprintf(caTempDir,"/datacenter/msa/ipsearch");
						    if(ltFileIsExist(caTempDir)==1) {    	
						    	  if(chdir(caTempDir)==0){
						    	 	  sprintf(caLabel,"/bin/rm -rf *");
						    	 	  system(caLabel);									    	 	  
						    	 	  sprintf(caLabel,"echo 'ipsearch'> %s",proIniDir);
							        system(caLabel);
							        sleep(1);
				       
						    	  }  						 																  	    	 
						    }
						    
						    
                  
   						   
   						 
   						  //ÿ����ʻ��ܼ�¼
   						     /*������ʻ��ܼ�¼*/
   						    memset(strSql,0,sizeof(strSql));
   						    sprintf(strSql,"delete from msasrvreport where sdate<'%s'",sdate);
									ltDbExecSql(G_DbCon,strSql);
							   	sprintf(caLabel,"echo 'msasrvreport'>%s",proIniDir);
									system(caLabel);
									sleep(1);									
								    /*HTTP���ܼ�¼*/  
								  memset(strSql,0,sizeof(strSql));  
								  sprintf(strSql,"delete from msahttpreport where sdate<'%s'",sdate);
									ltDbExecSql(G_DbCon,strSql);
							   	sprintf(caLabel,"echo 'msahttpreport'>%s",proIniDir);
									system(caLabel);
									sleep(1);
   						   
   						   
   						   
   						   
   						   //��ʱͨ��
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"delete from msaimlog where sdate<'%s'",sdate);
								  ltDbExecSql(G_DbCon,strSql);
   					   	  sprintf(caLabel,"echo 'msaimlog'>%s",proIniDir);
								  system(caLabel);
								  sleep(1);
   						      						     						   
   						   
   						   //�ļ�����
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"select tabname from msafileloglist where sdate<'%s'",sdate);
								  tempCursor=ltDbOpenCursor(G_DbCon,strSql);
								  if(tempCursor!=NULL){
										   tempRow=ltDbFetchRow(tempCursor);
										   if(tempRow!=NULL) {
										       memset(strSql,0,sizeof(strSql));              
                           sprintf(strSql,"delete from %s",tempRow[0]);
                           ltDbExecSql(G_DbCon,strSql);
					   					   	 sprintf(caLabel,"echo '%s'> %s",tempRow[0],proIniDir);
													 system(caLabel);
													 sleep(1);
										   }
									}
								  ltDbCloseCursor(tempCursor);				  
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"delete from msafileloglist where sdate<'%s'",sdate);
								  ltDbExecSql(G_DbCon,strSql);
   					   	  sprintf(caLabel,"echo 'msafileloglist'> %s",proIniDir);
								  system(caLabel);
								  sleep(1);
   						   
   						   
   						   
   						   //POP3/SMTP�ʼ�
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"select tabname from msamailloglist where sdate<'%s'",sdate);
								  tempCursor=ltDbOpenCursor(G_DbCon,strSql);
								  if(tempCursor!=NULL){
										   tempRow=ltDbFetchRow(tempCursor);
										    if(tempRow!=NULL) {                
                           sprintf(strSql,"delete from %s",tempRow[0]);
                           ltDbExecSql(G_DbCon,strSql);
					   					   	 sprintf(caLabel,"echo '%s'> %s",tempRow[0],proIniDir);
													 system(caLabel);
													 sleep(1);
										   }
									}
								  ltDbCloseCursor(tempCursor);
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"delete from msamailloglist where sdate<'%s'",sdate);
								  ltDbExecSql(G_DbCon,strSql);
   					   	  sprintf(caLabel,"echo 'msamailloglist'> %s",proIniDir);
								  system(caLabel);
								  sleep(1);
   						   		   
   						   
   						   //WEB�ʼ�
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"select tabname from msawebmailloglist where sdate<'%s'",sdate);
								  tempCursor=ltDbOpenCursor(G_DbCon,strSql);
								  if(tempCursor!=NULL){
										   tempRow=ltDbFetchRow(tempCursor);
										   if(tempRow!=NULL) { 
										   	   memset(strSql,0,sizeof(strSql));               
                           sprintf(strSql,"delete from %s ",tempRow[0]);
                           ltDbExecSql(G_DbCon,strSql);
					   					   	 sprintf(caLabel,"echo '%s'> %s",tempRow[0],proIniDir);
													 system(caLabel);
													 sleep(1);
										   }
									}
								  ltDbCloseCursor(tempCursor);
								  memset(strSql,0,sizeof(strSql));
								  sprintf(strSql,"delete from msawebmailloglist where sdate<'%s'",sdate);
								  printf("mysql:%s\n",strSql);
								  ltDbExecSql(G_DbCon,strSql);
   					   	  sprintf(caLabel,"echo 'msawebmailloglist' > %s",proIniDir);
								  system(caLabel);
								  sleep(1);

	      						   
   						   //�����ؼ��ּ�¼
   						    memset(strSql,0,sizeof(strSql));
						      sprintf(strSql,"truncate msasearchkey");
						      printf("mysql:%s\n",strSql);
								  ltDbExecSql(G_DbCon,strSql);
						   	  sprintf(caLabel,"echo 'msasearchkey' > %s",proIniDir);
								  system(caLabel);
								  sleep(1);

									
								sprintf(caTempDir,"/datacenter/msa/mailmon");
   						  if(ltFileIsExist(caTempDir)==1) {    	
						    	  if(chdir(caTempDir)==0){
						    	 	  sprintf(caLabel,"/bin/rm -rf *");
						    	 	  system(caLabel);									    	 	  
						    	 	  sprintf(caLabel,"echo 'mailmon'> %s",proIniDir);
							        system(caLabel);
							        sleep(1);
				       
						    	  }  						 																  	    	 
						    }
								
								sprintf(caTempDir,"/datacenter/msa/packlist");
   						  if(ltFileIsExist(caTempDir)==1) {    	
						    	  if(chdir(caTempDir)==0){
						    	 	  sprintf(caLabel,"/bin/rm -rf *");
						    	 	  system(caLabel);									    	 	  
						    	 	  sprintf(caLabel,"echo 'packlist'> %s",proIniDir);
							        system(caLabel);
							        sleep(1);
				       
						    	  }  						 																  	    	 
						    }		  							 
								  
								  
								  
								


												  
   					}								        
			} 
			
						
			if(cachr2==1){//�˻�����
				    /*��չ���Ա���*/
				      memset(strSql,0,sizeof(strSql));
				      sprintf(strSql,"truncate msaadminarea");
						  ltDbExecSql(G_DbCon,strSql);
				   	  sprintf(caLabel,"echo 'msaadminarea' > %s",proIniDir);
						  system(caLabel);
									  
					    /*��չ���Ա��Ϣ��*/
					     memset(strSql,0,sizeof(strSql));
				       sprintf(strSql,"delete from msaadmuser where name<>'admin'");
						   ltDbExecSql(G_DbCon,strSql);
				   	   sprintf(caLabel,"echo 'msaadmuser' > %s",proIniDir);
						   system(caLabel);
						
						  /*��ղ�����Ϣ��*/
						   memset(strSql,0,sizeof(strSql));
				       sprintf(strSql,"truncate msagroup");
						   ltDbExecSql(G_DbCon,strSql);
				   	   sprintf(caLabel,"echo 'msagroup' > %s",proIniDir);
						   system(caLabel);
						   
						 /*��ղ���ip��Ϣ��*/
						   memset(strSql,0,sizeof(strSql));
				       sprintf(strSql,"truncate msagroupip");
						   ltDbExecSql(G_DbCon,strSql);
				   	   sprintf(caLabel,"echo 'msagroupip' > %s",proIniDir);
						   system(caLabel);
						 
						 /*��ղ�����Ϣ��*/
						 	 memset(strSql,0,sizeof(strSql));
				       sprintf(strSql,"truncate msapolicy");
						   ltDbExecSql(G_DbCon,strSql);
				   	   sprintf(caLabel,"echo 'msapolicy' > %s",proIniDir);
						   system(caLabel);
	
						   
						 /*��ղ���ip��Ϣ��*/
						   memset(strSql,0,sizeof(strSql));
				       sprintf(strSql,"truncate msapolicyip");
						   ltDbExecSql(G_DbCon,strSql);
				   	   sprintf(caLabel,"echo 'msapolicyip' > %s",proIniDir);
						   system(caLabel);
						 
						 /*����û���Ϣ��*/
						   memset(strSql,0,sizeof(strSql));
				       sprintf(strSql,"truncate msauser");
						   ltDbExecSql(G_DbCon,strSql);
				   	   sprintf(caLabel,"echo 'msauser' > %s",proIniDir);
						   system(caLabel);
						   	    
			}
			
			
			
			if(cachr3==1){//��շ������
				   
				   /*����û�������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate msauserpolicy");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'msauserpolicy' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*���С������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate msaservice");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'msaservice' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   
				   /*��շ��������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nassrvrule");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nassrvrule' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*���ip�����˷���������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nassrvruledip");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nassrvruledip' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*���ip�����˹������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasruleip");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasruleip' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*��ն�URL���˹������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasruleposturl");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasruleposturl' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*��չ���������Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasruletype");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasruletype' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*��չ���URL��Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasruleurl");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasruleurl' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				   
				   /*��չ����û���Ϣ��*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasruleuser");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasruleuser' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
				      
				  		   	  		
			
			}
			

			/***************************��ձ�������**********************/
			if(cachr4==1){//��ձ���ģ��						  
				  /*����Զ����ɵı���dailyreport*/
				  sprintf(caTempDir,"/datacenter/msa/report/dailyreport");
			    if(ltFileIsExist(caTempDir)==1) {    	
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'dailyreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }    	    	     	 
			    }
			}
			 
			 
			if(cachr5==1){
			 	
			 	 /*����ֶ����ɵı���instantreport*/
			    sprintf(caTempDir,"/datacenter/msa/report/instantreport");
			    if(ltFileIsExist(caTempDir)==1) {    	  
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'instantreport' > %s",proIniDir);
				        system(caLabel);
				        sleep(1);	
						 } 	 	    	 
			    }			 
			}   
			    
			 
			if(cachr6==1){			 	  
			 	  /*���ÿ��������ɵı���dailygrpreport*/
			    sprintf(caTempDir,"/datacenter/msa/report/dailygrpreport");
			    if(ltFileIsExist(caTempDir)==1) {    	   	 
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'dailygrpreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 } 	    	 
			    }		 
			 
			}
			    
			 
			if(cachr7==1){
			 	  /*��ճ���������������reportoutflow*/
				 	sprintf(caTempDir,"/datacenter/msa/report/reportoutflow");
			    if(ltFileIsExist(caTempDir)==1) {    		 
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'reportoutflow' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }   	     	 
			    } 
			    
			    memset(strSql,0,sizeof(strSql));
			    sprintf(strSql,"delete from msauserhttpreport where sdate<'%s'",sdate);
					ltDbExecSql(G_DbCon,strSql);
			   	sprintf(caLabel,"/bin/echo 'msauserhttpreport' > %s",caTempDir);
					system(caLabel);
					sleep(1);
			 	
			}	  
				
		 	if(cachr8==1){		 	 	
		 	 	  /*��շ���Э���������srvreport*/
				  sprintf(caTempDir,"/datacenter/msa/report/srvreport");
			    if(ltFileIsExist(caTempDir)==1) {    	
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'srvreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }	    	 	    	 
			    } 
			    
			    memset(strSql,0,sizeof(strSql));
			    sprintf(strSql,"delete from msatimesrvreport where sdate<'%s'",sdate);
					ltDbExecSql(G_DbCon,strSql);
			   	sprintf(caLabel,"/bin/echo 'msatimesrvreport' > %s",caTempDir);
					system(caLabel);	
					sleep(1);
		 	 	
		 	}
				 	
      if(cachr9==1){        	 
        	  /*����û�ʱ���������timereport*/
				 	sprintf(caTempDir,"/datacenter/msa/report/timereport");
			    if(ltFileIsExist(caTempDir)==1) {
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'timereport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }    				    	 		    	 	    	 
			    }  
			    
			      /*msaaccountreport���¼���*/
			    memset(strSql,0,sizeof(strSql));
				  sprintf(strSql,"delete from msaaccountreport where sdate<'%s'",sdate);
					ltDbExecSql(G_DbCon,strSql);
			   	sprintf(caLabel,"echo 'msaaccountreport' > %s",proIniDir);
					system(caLabel);
					sleep(1); 
          
          memset(strSql,0,sizeof(strSql));
          sprintf(strSql,"delete from msatimereport where sdate<'%s'",sdate);
					ltDbExecSql(G_DbCon,strSql);
			   	sprintf(caLabel,"/bin/echo 'msatimereport' > %s",caTempDir);
					system(caLabel);	
					sleep(1); 
        
      }	  	
			 	 
				 	 
			if(cachr10==1){
			  	 /*�������������������*/
			    sprintf(caTempDir,"/datacenter/msa/report/flowreport");
			    if(ltFileIsExist(caTempDir)==1) {
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'flowreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }       	
			    	 		    	 	    	 
			    }
			}  
			   
		    
		  if(cachr11==1){
		    	 /*������������������*/
			    sprintf(caTempDir,"/datacenter/msa/report/connectreport");
			    if(ltFileIsExist(caTempDir)==1) {
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'connectreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }   	
			    	 		    	 	    	 
			    }
			    
			    memset(strSql,0,sizeof(strSql));
			    sprintf(strSql,"delete from msadipreport where sdate<'%s'",sdate);
					ltDbExecSql(G_DbCon,strSql);
			   	sprintf(caLabel,"/bin/echo 'msadipreport' > %s",caTempDir);
					system(caLabel);
					sleep(1);
			    
			    
			    
		  }

			if(cachr12==1){
			  	  /*�����վ��������*/
			    sprintf(caTempDir,"/datacenter/msa/report/webreport");
			    if(ltFileIsExist(caTempDir)==1) {
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'webreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }     	
			    	 		    	 	    	 
			    }
			} 
			  
			  
			if(cachr13==1){
			  	/*����û��Ʒѱ���*/
			    sprintf(caTempDir,"/datacenter/msa/report/jfreport");
			    if(ltFileIsExist(caTempDir)==1) {
			    	 if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);							
								sprintf(caLabel,"echo 'jfreport' > %s",proIniDir);
				        system(caLabel);	
				        sleep(1);
						 }   			    	 		    	 	    	 
			    }
			}
			  
			       
			   
						
									
					



			/********************************************��������***************************************/
			if(cachr15==1){//����Ա������־
				  memset(strSql,0,sizeof(strSql));
				  sprintf(strSql,"delete from msaadmlog where sdate<'%s'",sdate);
					ltDbExecSql(G_DbCon,strSql);
			   	sprintf(caLabel,"echo 'msaadmlog ' > %s",proIniDir);
					system(caLabel);				
			}
			
			if(cachr16==1){//�������
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasNetArea");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasNetArea ' > %s",proIniDir);
				   system(caLabel);			
			}
			
			if(cachr17==1){//�˿�����
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasPortInfo");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasPortInfo ' > %s",proIniDir);
				   system(caLabel);		
			}
			
			
			if(cachr18==1){//ϵͳ����		
				  sprintf(caTempDir,"/etc/msa/msa/option"); 
				  if(ltFileIsExist(caTempDir)==1) {    	
			    	  if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);									    	 	  
			    	 	  sprintf(caLabel,"echo 'option config '> %s",proIniDir);
				        system(caLabel);
				        sleep(2);      
			    	  }  						 																  	    	 
			    } 
				   			
			}
			
			
			if(cachr19==1){//�ʼ�����				
				 sprintf(caTempDir,"/etc/msa/msa/level/maillevel"); 
				  if(ltFileIsExist(caTempDir)==1) {    	
			    	  if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);									    	 	  
			    	 	  sprintf(caLabel,"echo 'maillevel '> %s",proIniDir);
				        system(caLabel);
				        sleep(2);      
			    	  }  						 																  	    	 
			    } 
			    
			      /*����ʼ���ر�*/
				  memset(strSql,0,sizeof(strSql));
				  sprintf(strSql,"truncate msamailfilter");
				  ltDbExecSql(G_DbCon,strSql);
		   	  sprintf(caLabel,"echo 'msamailfilter ' > %s",proIniDir);
				  system(caLabel);
				  sleep(1);
				
							
			}
			
			if(cachr20==1){//������						
					sprintf(caTempDir,"/etc/msa/msa/level/formlevel"); 
				  if(ltFileIsExist(caTempDir)==1) {    	
			    	  if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);									    	 	  
			    	 	  sprintf(caLabel,"echo 'formlevel '> %s",proIniDir);
				        system(caLabel);
				        sleep(2);      
			    	  }  						 																  	    	 
			    }
			    
			    sprintf(caTempDir,"/etc/msa/msa/url"); 
				  if(ltFileIsExist(caTempDir)==1) {    	
			    	  if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);									    	 	  
			    	 	  sprintf(caLabel,"echo 'url config'> %s",proIniDir);
				        system(caLabel);
				        sleep(2);      
			    	  }  						 																  	    	 
			    }
			    
			    //���ύ����
			    memset(strSql,0,sizeof(strSql));
		      sprintf(strSql,"truncate msaformfilter");
		      printf("mysql:%s\n",strSql);
				  ltDbExecSql(G_DbCon,strSql);
		   	  sprintf(caLabel,"echo 'msaformfilter' > %s",proIniDir);
				  system(caLabel);
				  sleep(1);
			}
			
			if(cachr21==1){//URL����
				  /*���nasurls*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasurls");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasurls' > %s",proIniDir);//
				   system(caLabel);
				   sleep(1);
				 
				
				  /*���nasurlsort*/
				   memset(strSql,0,sizeof(strSql));
				   char temp[64];
				   char mytype[64];
				   sprintf(temp,"%s","�Զ������");
	         strgb2utf8(temp,mytype,strlen(temp));
	         int sortid=76;
	         int i=1;
	         for(;sortid<91;sortid++){         	 
	         	 sprintf(strSql,"update nasurlsort set sorname='%s%d',sortdesc='' where sortid=%d",mytype,i,sortid);				   
				     ltDbExecSql(G_DbCon,strSql);
				     i++;
	         }
				   
		   	   sprintf(caLabel,"echo 'nasurlsort' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);	
							
			}
			
			if(cachr22==1){//ʱ�����  nasschedule				
				   /*���nasschedule*/
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasschedule");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasschedule' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
							
			}
			
			
			
			if(cachr23==1){//�������� nasjjr							
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nasjjr");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nasjjr' > %s",proIniDir);
				   system(caLabel);			
				   sleep(1);		
			}
			
			
			if(cachr24==1){//��������nassrv				
				   memset(strSql,0,sizeof(strSql));
		       sprintf(strSql,"truncate nassrv");
				   ltDbExecSql(G_DbCon,strSql);
		   	   sprintf(caLabel,"echo 'nassrv' > %s",proIniDir);
				   system(caLabel);
				   sleep(1);
							
			}
			
			if(cachr25==1){//ʱ����� �����ļ�
					sprintf(caTempDir,"/etc/msa/msa/time"); 
				  if(ltFileIsExist(caTempDir)==1) {    	
			    	  if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);									    	 	  
			    	 	  sprintf(caLabel,"echo 'timeservice'> %s",proIniDir);
				        system(caLabel);
				        sleep(1);      
			    	  }  						 																  	    	 
			    } 
			}
			
		 if(cachr26==1){//ʱ����� �����ļ�
					sprintf(caTempDir,"/etc/msa/msa/dev"); 
				  if(ltFileIsExist(caTempDir)==1) {    	
			    	  if(chdir(caTempDir)==0){
			    	 	  sprintf(caLabel,"/bin/rm -rf *");
			    	 	  system(caLabel);									    	 	  
			    	 	  sprintf(caLabel,"echo 'dev config'> %s",proIniDir);
				        system(caLabel);
				        sleep(1);      
			    	  }  						 																  	    	 
			    } 
			}
			
			
			sprintf(caLabel,"echo '0' > %s",proIniDir);
		  system(caLabel);/*����Ŀ¼��־*/	  
			sleep(1);
			
			
			printf("system clean end.................\n");
			
			
  
		return 0; 
}


//���״̬����ʾ��Ϣ
int msaStatusAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
    FILE *fd=NULL;
		char str[1024];
		fd=fopen("/datacenter/msa/process.ini","r");
    if(fd){
    	fgets(str,256,fd);
    } 
    fclose(fd);	
 	 printf("str:%s\n",str);
 	 ltMsgPk->msgpktype=1;
   lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\r\n","lthtml",LT_TYPE_STRING,str);
   ltMsgFree(ltMsgPk); 
   return 0;
   
}



