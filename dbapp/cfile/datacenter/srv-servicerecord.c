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

/////////////////////////////////////////
int msalocalStore(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	  ltDbCursor *tempCursor;
    LT_DBROW tempRow;
	  stralloc strTemp;
    strTemp.s=0;	
	  char *gid;
    char caTmpp[2048],sqlBuf[1024],strBuf[1024];
    int intGid,glevel=0,lNum=0;
    long lCount=0;
    
		memset(caTmpp,0,sizeof(caTmpp));
		memset(sqlBuf,0,sizeof(sqlBuf));
		memset(strBuf,0,sizeof(strBuf));

    gid=ltMsgGetVar_s(ltMsgPk,"groupid");
    intGid=atol(gid);

	  /*��ȡ���Ź�����*/	  
	  sprintf(strBuf,"select level from msagroup where id=%d",intGid);
	  tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
		if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			if(tempRow!=NULL){
				glevel=atol(tempRow[0]);
			}
		}
	  ltDbCloseCursor(tempCursor);   

  /*�����¼��Ŀ*/
  memset(sqlBuf,0,sizeof(sqlBuf));
  sprintf(sqlBuf,"select count(*) from msauser a left join msagroup b on (a.groupid%d=b.id) where a.groupid%d=%d",glevel,glevel,intGid);
  tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		if(tempRow!=NULL){
			lCount=atol(tempRow[0]);
			lCount++;
		}
	}
	ltDbCloseCursor(tempCursor);
 

	/*ѡ���ź������û�json����*/
	 memset(sqlBuf,0,sizeof(sqlBuf));
	 sprintf(sqlBuf,"select a.userid,a.dispname from msauser a left join msagroup b on (a.groupid%d=b.id) where a.groupid%d=%d",glevel,glevel,intGid);
   sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
   stralloc_cats(&strTemp,caTmpp);  
   tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
   if(tempCursor!=NULL){
		    tempRow= ltDbFetchRow(tempCursor);
	    	while(tempRow!=NULL){  
	        lNum++;						
	             if(lNum==1){              	
	             	  sprintf(caTmpp,"{\"uid\":\"%s\",\"uname\":\"%s\"}","-1","All USER");
						      stralloc_cats(&strTemp,caTmpp); 
						      
						      sprintf(caTmpp,",{\"uid\":\"%s\",\"uname\":\"%s\"}",tempRow[0],tempRow[1]);				       
							    stralloc_cats(&strTemp,caTmpp);
					}else{					    
						      sprintf(caTmpp,",{\"uid\":\"%s\",\"uname\":\"%s\"}",tempRow[0],tempRow[1]);
							    stralloc_cats(&strTemp,caTmpp);
	
				  }       
			    tempRow= ltDbFetchRow(tempCursor);
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


/*���ܣ�������ܼ�¼��̬����ҳ��Ͷ�̬ˢ���û�      ��Ҫ������ groupid*/
int ltshowservicequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
  ltTablePtr  tablePtr;
  ltDbCursor *tempCursor;
  LT_DBROW tempRow;
  ltDbHeadPtr dbPtr;
	char *gid;
  int iii;
  
  char strBuf[512];
  int Num=0;

  gid=ltMsgGetVar_s(ltMsgPk,"groupid");
       
	dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8");
	
	memset(strBuf,0,sizeof(strBuf));
  Num=0;
  sprintf(strBuf,"select distinct sdate from msasrvreport");
	tablePtr=lt_dbput_table(dbPtr,"datelist");
	tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
	if(tempCursor!=NULL){
    tempRow=ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){//�����м�¼			
			Num++;	
			/*char tempDate[32];
			char ToDate[32];		
			memset(tempDate,0,sizeof(tempDate));
			memset(ToDate,0,sizeof(ToDate));
			sprintf(tempDate,"%s",tempRow[0]);
			ToDate[0]=tempDate[0];
			ToDate[1]=tempDate[1];
			ToDate[2]=tempDate[2];
			ToDate[3]=tempDate[3];
			ToDate[4]='-';
			ToDate[5]=tempDate[4];
			ToDate[6]=tempDate[5];
			ToDate[7]='-';
			ToDate[8]=tempDate[6];
			ToDate[9]=tempDate[7];
			ToDate[10]='\0';*/
			if(Num==1){
       lt_dbput_recordvars(tablePtr,3,
       "dayname",LT_TYPE_STRING,tempRow[0],        
       "strdate",LT_TYPE_STRING,tempRow[0]);
			}else{
       lt_dbput_recordvars(tablePtr,3,
       "dayname",LT_TYPE_STRING,tempRow[0],        
       "strdate",LT_TYPE_STRING,tempRow[0]);
			}    				              
    tempRow=ltDbFetchRow(tempCursor);	
		}		
	}
	ltDbCloseCursor(tempCursor); 
	
	tablePtr=lt_dbput_table(dbPtr,"srvlist");	
	for(iii=0;iii<25;iii++){
			lt_dbput_recordvars(tablePtr,2,
				"srvid",LT_TYPE_LONG,iii,
				"srvname",LT_TYPE_STRING,_ltPubInfo->topSrvName[iii].srvname);
	}
	
	
	lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/datacenter/msaservicehead.htm",dbPtr->head,0);	
	ltMsgFree(ltMsgPk);
	lt_dbfree(dbPtr);
	return 0;
}

/*����:������ܼ�¼������ѯ,����,ɾ������:*/
int ltservicequeryhttpa(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
    long lRowNum,lStartRec,lCount,lSumRec,lNum;
    int  iAction=0;   
    int  intGid,glevel=0;	 
    char sqlBuf[1024],strBuf[1024];
    char caWhere[512],delWhere[512];   
    char *caUser=NULL; 
    char *caService=NULL;
    char *caDtype=NULL; 
    char *caDdd=NULL;
    char *caUnit=NULL;
    char *caBef=NULL;
    char *caSdate=NULL;
    char *caBtype=NULL;
    char *caBbyte=NULL; 
    char *caOrder=NULL;
    char *caOrderby=NULL;
    char *m_action=NULL;
    char *gid=NULL;
    char caTmpp[2048];
    ltDbCursor *tempCursor;
    LT_DBROW tempRow;
    stralloc strTemp;
    strTemp.s=0;

    m_action=ltMsgGetVar_s(ltMsgPk,"action");
    if(m_action==NULL){
     iAction=0;
    }else{
      iAction=atol(m_action);
    }
    caUser=ltMsgGetVar_s(ltMsgPk,"user"); 
    caService=ltMsgGetVar_s(ltMsgPk,"service");
    caDtype=ltMsgGetVar_s(ltMsgPk,"dtype");  
    caDdd=ltMsgGetVar_s(ltMsgPk,"ddd");
    caUnit=ltMsgGetVar_s(ltMsgPk,"unit");  // �졣�ܡ���
    caBef=ltMsgGetVar_s(ltMsgPk,"bef"); //���� ��ǰ
    
    caSdate=ltMsgGetVar_s(ltMsgPk,"sdate");
    
    caBtype=ltMsgGetVar_s(ltMsgPk,"btype");   //������Χ
    caBbyte=ltMsgGetVar_s(ltMsgPk,"bbyte");   //�ֽ�
    
    caOrder=ltMsgGetVar_s(ltMsgPk,"osort");   // ����ʽ
    caOrderby=ltMsgGetVar_s(ltMsgPk,"orderby");   //�� ��
    
    gid=ltMsgGetVar_s(ltMsgPk,"groupid");
	  intGid=atol(gid);
		/*��ȡ���Ź�����*/	  
		sprintf(strBuf,"select level from msagroup where id=%d",intGid);
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
			if(tempCursor!=NULL){
				tempRow= ltDbFetchRow(tempCursor);
				if(tempRow!=NULL){
					glevel=atol(tempRow[0]);
				}
			}
			ltDbCloseCursor(tempCursor); 
			
  
			lRowNum=100; 
			lSumRec=0;
			lCount=0; 
			lStartRec=0;
			lNum=0; 
			  	
			if(ltMsgGetVar_s(ltMsgPk,"limit")){ 
				lRowNum=atol(ltMsgGetVar_s(ltMsgPk,"limit"));
				}
			if(ltMsgGetVar_s(ltMsgPk,"start")){
				 lStartRec=atol(ltMsgGetVar_s(ltMsgPk,"start"));
				 }
		
		
			memset(caWhere,0,sizeof(caWhere));
			memset(delWhere,0,sizeof(delWhere));
	
		 if(strcmp(gid,"-1")){//������-1
			   if(strcmp(caUser,"-1")==0){
			       sprintf(caWhere,"a.groupid%d=%d",glevel,intGid);//�������������û�
			       sprintf(delWhere,"a.groupid%d=%d",glevel,intGid);
				 }else{
					   sprintf(caWhere,"b.userid=%s and a.groupid%d=%d",caUser,glevel,intGid);//msasearchkey  Ϊb��
						 sprintf(delWhere,"userid = %s",caUser); 
				 }
			}
		 if(strcmp(gid,"-1")==0){
			  if(strcmp(caUser,"-1")==0){
			       sprintf(caWhere,"%s","2=2");
			       sprintf(delWhere,"%s","2=2");
				}
		 }   
     if(caService!=NULL){
	    if(strlen(caService)>0) {
	          if( strcmp(caService,"-1")){
			        	sprintf(caWhere,"%s and (b.service='%s')",caWhere,caService);
			        	sprintf(delWhere,"%s and (service ='%s')",delWhere,caService);
				}
	    }
    }     
    if(strcmp(caDtype,"unit2") == 0){ /* ʱ�䷶Χ  */
printf("1.........\n");
    	if((caSdate!=NULL)){ 
printf("2.........\n");   		
		        if(strlen(caSdate)>0) {
printf("3.........\n");
		            if(strlen(caSdate)==10) {
printf("4.........\n");
		            	sprintf(caWhere,"%s and (b.sdate = '%s')",caWhere,caSdate);
		            	sprintf(delWhere,"%s and (sdate = '%s')",delWhere,caSdate);
		             }            
		        }
			}
    }
printf("caSdate:%s\n",caSdate);
printf("caWhere:%s\n",caWhere);
    if(strcmp(caBtype,"unit2") == 0)  { /* ������Χ  */
    	  sprintf(caWhere,"%s and (b.dbytes > '%s')",caWhere,caBbyte);
    	  sprintf(delWhere,"%s and (dbytes > '%s')",delWhere,caBbyte);
    }       
    if(iAction==2){/*del*/   	 
				if(strlen(delWhere)>0){
				     sprintf(sqlBuf,"delete from msasrvreport where %s ",delWhere);
				     ltDbExecSql(G_DbCon,sqlBuf);
		         }
		    
			  ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");		
				ltMsgFree(ltMsgPk);
				return 0;
    	
    }else if(iAction==1){/*export*/	    		
	    int  lTime;
	    char sDate[36];
	    char caLine[8012];		
	    memset(sDate,0,sizeof(sDate));
	    lTime = time(0);
			nasTimeFormat(sDate,lTime);		 			 			
			if(strlen(caWhere)>0){
				  if(caOrder!=NULL){
					    if( strlen(caOrder)>0 ) {
					    	if(strcmp(caOrder,"nosort")!=0) {
							        if(strcmp(caOrder,"date")==0) {
							            sprintf(caWhere,"%s order by b.sdate ",caWhere);
							        }else if(strcmp(caOrder,"userss") == 0) {
							            sprintf(caWhere,"%s order by b.userid ",caWhere);
							        }else if(strcmp(caOrder,"service") == 0) {
							            sprintf(caWhere,"%s order by b.service ",caWhere);
							        }else if(strcmp(caOrder,"bytes") == 0) {
							            sprintf(caWhere,"%s order by b.dbytes ",caWhere);
							        } 
					        
						          if(strlen(caOrderby)) {
						            if(caOrderby[0] == '1') {   
			            	    	 if(strcmp(caOrder,"date")==0){
							            		ltStrAddF(caWhere," desc");
												   }else if(strcmp(caOrder,"service")==0){
												   	  ltStrAddF(caWhere," desc");
												   }else if(strcmp(caOrder,"dbytes")==0){
												   	  ltStrAddF(caWhere," desc");
												   }else{
												   	  ltStrAddF(caWhere," desc");
												   }
						            }else{
					                 if(strcmp(caOrder,"date")==0) {
									            ltStrAddF(caWhere," asc");
												   }else if(strcmp(caOrder,"service")==0){
												   	  ltStrAddF(caWhere," asc");
												   }else if(strcmp(caOrder,"dbytes")==0){
												   	  ltStrAddF(caWhere," asc");
												   }else{
												   	  ltStrAddF(caWhere," asc");
												   }          
						            } 
						          }
					         }
					    }   
			     }	
         }

       sprintf(sqlBuf,"select a.userid,a.dispname,a.bindip,c.name,b.sdate,b.ubytes,b.dbytes,b.ctime,b.onlinetime from msasrvreport b left join msauser a on b.userid=a.userid left join msagroup c on a.groupid%d=c.id where %s limit %lu offset %lu",glevel,caWhere,lRowNum,lStartRec);
       ltMsgPk->msgpktype=2;
		   lt_TcpResponse(confd,ltMsgPk,2,"filename",LT_TYPE_STRING,"srvexport.csv","contenttype","Application/MS-DOWNLOAD");		
		   tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
			   if(tempCursor!=NULL){
				    tempRow= ltDbFetchRow(tempCursor);
			       	while(tempRow!=NULL){
							sprintf(caLine,"%s,%d,%s,%s,%s,%s,%d,%d,%d,%d\r\n",tempRow[3],atoi(tempRow[0]),tempRow[1],tempRow[2],tempRow[3],tempRow[4],atoi(tempRow[5]),atoi(tempRow[6]),atoi(tempRow[7]),atoi(tempRow[8]));	  
							write(confd,caLine,strlen(caLine));									
							tempRow= ltDbFetchRow(tempCursor);
							}
			     ltDbCloseCursor(tempCursor);
			   }
			  ltMsgFree(ltMsgPk);			  				
		  return 0;
    }
  sprintf(strBuf,"select count(*) from msasrvreport b left join msauser a on a.userid=b.userid where %s",caWhere);
printf("111strBuf:%s\n",strBuf);
  tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		if(tempRow!=NULL){
			lCount=atol(tempRow[0]);
		}
	}
	ltDbCloseCursor(tempCursor);
 
     if(caOrder!=NULL){
	    if( strlen(caOrder)>0 ) {
	    	if(strcmp(caOrder,"nosort")!=0) {
			    if(strcmp(caOrder,"date")==0) {
			           sprintf(caWhere,"%s order by b.sdate ",caWhere);
			    }else if(strcmp(caOrder,"service") == 0){
						     sprintf(caWhere,"%s order by b.service ",caWhere);
					}else if(strcmp(caOrder,"bytes") == 0){
			           sprintf(caWhere,"%s order by b.dbytes ",caWhere);
			    }else if(strcmp(caOrder,"userss") == 0){
						     sprintf(caWhere,"%s order by b.userid ",caWhere);
					}
					
	        if(strlen(caOrderby)){
		            if(caOrderby[0] == '1') {   
		            	  if(strcmp(caOrder,"date")==0) {
						            ltStrAddF(caWhere," desc");
									  }else if(strcmp(caOrder,"service")==0){
									   	       ltStrAddF(caWhere," desc");
									  }else if(strcmp(caOrder,"dbytes")==0){
									   	        ltStrAddF(caWhere," desc");
									  }else{
									   	       ltStrAddF(caWhere," desc");
									  }
		            }else{
	                  if(strcmp(caOrder,"date")==0) {
					            ltStrAddF(caWhere," asc");
								    }else if(strcmp(caOrder,"service")==0){
								   	         ltStrAddF(caWhere," asc");
								    }else if(strcmp(caOrder,"dbytes")==0){
								   	         ltStrAddF(caWhere," asc");
								    }else{
								   	        ltStrAddF(caWhere," asc");
								   	}          
		            } 
				 }
	      }
	     }   
    }	
//jsonƴ��
  sprintf(sqlBuf,"select a.dispname,b.sdate,b.ubytes,b.dbytes,b.ctime,b.onlinetime,b.service,a.userid,c.name from msasrvreport b left join msauser a on a.userid=b.userid left join msagroup c on a.groupid%d=c.id where %s limit %lu offset %lu",glevel,caWhere,lRowNum,lStartRec);
printf("222sqlBuf:%s\n",sqlBuf);
	sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
	stralloc_cats(&strTemp,caTmpp);
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
   if(tempCursor!=NULL){
	     tempRow= ltDbFetchRow(tempCursor);
       	while(tempRow!=NULL){
					  lNum++;
						if(lNum==1){
							        char sTime[32];
							        memset(sTime,0,sizeof(sTime));
							  	    sprintf(sTime,"%ld",atol(tempRow[5])/3600);
									    sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])/60);
									    sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])%60);
								      sprintf(caTmpp,"{\"mygroup\":\"%s\",\"uname\":\"%s\",\"mydate\":\"%s\",\"sflow\":\"%lld\",\"xflow\":\"%lld\",\"counts\":\"%ld\",\"times\":\"%s\",\"myservice\":\"%s\",\"uid\":\"%ld\"}",
								      				tempRow[8],//GroupName
															tempRow[0],//dispname
															tempRow[1],//sdate
															atoll(tempRow[2])/1024,//ubytes
															atoll(tempRow[3])/1024,//dbytes
															atol(tempRow[4]),//ctime
															sTime,//onlinetime
															_ltPubInfo->topSrvName[atol(tempRow[6])].srvname,//service
															atol(tempRow[7])//userid
									);											  
								 stralloc_cats(&strTemp,caTmpp);								
						}else{
							        char sTime[32];
								      memset(sTime,0,sizeof(sTime));
								  	  sprintf(sTime,"%ld",atol(tempRow[5])/3600);
									    sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])/60);
									    sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])%60);
							        sprintf(caTmpp,",{\"mygroup\":\"%s\",\"uname\":\"%s\",\"mydate\":\"%s\",\"sflow\":\"%lld\",\"xflow\":\"%lld\",\"counts\":\"%ld\",\"times\":\"%s\",\"myservice\":\"%s\",\"uid\":\"%ld\"}",
                            tempRow[8],//GroupName
														tempRow[0],//dispname
														tempRow[1],//sdate
														atoll(tempRow[2])/1024,//ubytes
														atoll(tempRow[3])/1024,//dbytes
														atol(tempRow[4]),//ctime
														sTime,//onlinetime
														_ltPubInfo->topSrvName[atol(tempRow[6])].srvname,//service
														atol(tempRow[7])//userid
									);						  
								  stralloc_cats(&strTemp,caTmpp);	
						 }
						tempRow= ltDbFetchRow(tempCursor);
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


/*���ܣ�HTTP���ܼ�¼��̬����ҳ��Ͷ�̬ˢ���û�  ������groupid*/
int ltwebshowwebsitequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
  ltDbHeadPtr dbPtr;
	ltTablePtr tablePtr;
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	
	char sqlBuf[2048];
	char *gid;
  int Num=0;
  
  gid=ltMsgGetVar_s(ltMsgPk,"groupid");
   
	dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8");
	
	memset(sqlBuf,0,sizeof(sqlBuf));
  Num=0;
  sprintf(sqlBuf,"select distinct sdate from msauserhttpreport");
	tablePtr=lt_dbput_table(dbPtr,"datelist");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
    tempRow=ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){//�����м�¼			
			Num++;	
			/*char tempDate[32];
			char ToDate[32];		
			memset(tempDate,0,sizeof(tempDate));
			memset(ToDate,0,sizeof(ToDate));
			sprintf(tempDate,"%s",tempRow[0]);
			ToDate[0]=tempDate[0];
			ToDate[1]=tempDate[1];
			ToDate[2]=tempDate[2];
			ToDate[3]=tempDate[3];
			ToDate[4]='-';
			ToDate[5]=tempDate[4];
			ToDate[6]=tempDate[5];
			ToDate[7]='-';
			ToDate[8]=tempDate[6];
			ToDate[9]=tempDate[7];
			ToDate[10]='\0';*/
			if(Num==1){
       lt_dbput_recordvars(tablePtr,2,
       "dayname",LT_TYPE_STRING,tempRow[0],        
       "strdate",LT_TYPE_STRING,tempRow[0]);
			}else{
       lt_dbput_recordvars(tablePtr,2,
       "dayname",LT_TYPE_STRING,tempRow[0],        
       "strdate",LT_TYPE_STRING,tempRow[0]);
			}    				              
    tempRow=ltDbFetchRow(tempCursor);	
		}		
	}
	ltDbCloseCursor(tempCursor);
	
			
	tablePtr=lt_dbput_table(dbPtr,"srvlist");
	sprintf(sqlBuf,"select sortid,sorname from nasurlsort order by sortid");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){
			lt_dbput_recordvars(tablePtr,2,
				"srvid",LT_TYPE_STRING,tempRow[0],
				"srvname",LT_TYPE_STRING,tempRow[1]);
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
	}
	
	
	
	lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/datacenter/msawebsitehead.htm",dbPtr->head,0);
	ltMsgFree(ltMsgPk);
	lt_dbfree(dbPtr);
	return 0;

}

/*���ã�ʵ�� HTTP����������������ѯ��ɾ�� */
int ltwebsitequeryhttpa(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
    ltDbCursor *tempCursor;
    long lRowNum,lStartRec,lCount,lSumRec,lNum;
    int  iAction=0;
    
    LT_DBROW tempRow;
    char sqlBuf[1024],strBuf[1024];
    char delWhere[512];//ɾ������
    char caWhere[512];
    
    char *caDtype=NULL; 
    char *caHost=NULL;
    char *caSdate=NULL;
    char *caOrder=NULL;
    char *caOrderby=NULL;
    char *m_action=NULL;
    char *caUser=NULL;  
    char *service=NULL;
    char *caBtype=NULL;//������Χ
    char *caBbyte=NULL;//�ֽ�
    char *gid=NULL;
    int intGid,glevel=0;	
    char caTmpp[2048];
    
    stralloc strTemp;
    strTemp.s=0;
    
    m_action=ltMsgGetVar_s(ltMsgPk,"action");
    if(m_action==NULL){
      iAction=0;
    }else{
      iAction=atol(m_action);
    }
    
    caUser=ltMsgGetVar_s(ltMsgPk,"user"); //uid
   
    caHost=ltMsgGetVar_s(ltMsgPk,"host");//host�ؼ���
     
    service=ltMsgGetVar_s(ltMsgPk,"service");//url����
    
    caDtype=ltMsgGetVar_s(ltMsgPk,"dtype");
    
    caSdate=ltMsgGetVar_s(ltMsgPk,"sdate");
    
    caBtype=ltMsgGetVar_s(ltMsgPk,"btype");
    caBbyte=ltMsgGetVar_s(ltMsgPk,"bbyte");
    
    caOrder=ltMsgGetVar_s(ltMsgPk,"osort");   // ����ʽ
    caOrderby=ltMsgGetVar_s(ltMsgPk,"orderby");   //�� ��   
    gid=ltMsgGetVar_s(ltMsgPk,"groupid");
    intGid=atol(gid);

    /*��ȡ���Ź�����*/	  
		sprintf(strBuf,"select level from msagroup where id=%d",intGid);
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
		if(tempCursor!=NULL){
			tempRow=ltDbFetchRow(tempCursor);
			if(tempRow!=NULL){
				glevel=atol(tempRow[0]);
			}
	  }
		ltDbCloseCursor(tempCursor); 
  
		lRowNum=100; /*ÿҳ������*/
		lSumRec=0;/*������*/
		lCount=0; //
		lStartRec=0;//
		lNum=0; /*��ҳʣ�������*/

			
		if(ltMsgGetVar_s(ltMsgPk,"limit")){ lRowNum=atol(ltMsgGetVar_s(ltMsgPk,"limit"));}//�൱�ڽ���λ��
		if(ltMsgGetVar_s(ltMsgPk,"start")){ lStartRec=atol(ltMsgGetVar_s(ltMsgPk,"start"));}//�൱����ʼλ��

		memset(caWhere,0,sizeof(caWhere));
		memset(delWhere,0,sizeof(delWhere));
    
		if(strcmp(gid,"-1")==0){
			if(strcmp(caUser,"-1")==0){
	       sprintf(caWhere,"%s","2=2");//��ѯ�����û�
	       sprintf(delWhere,"%s","2=2");//
			}
		}	
	  if(strcmp(gid,"-1")){//������-1
	   	if(strcmp(caUser,"-1")==0){
	       sprintf(caWhere,"a.groupid%d=%d",glevel,intGid);//�������������û�
	       sprintf(delWhere,"a.groupid%d=%d",glevel,intGid);
			}else{
			    sprintf(caWhere,"b.userid=%s and a.groupid%d=%d",caUser,glevel,intGid);//msasearchkey  Ϊb��
				sprintf(delWhere,"userid = %s",caUser); 
			}
	  }     

    if(caHost!=NULL){
	    if(strlen(caHost)>0) {
	        sprintf(caWhere,"%s and (b.host like '%c%s%c') ",caWhere,'%',caHost,'%');
	        sprintf(delWhere,"%s and (host like '%c%s%c') ",delWhere,'%',caHost,'%');
	    }
    }  
    if(service!=NULL){
	    if(strcmp(service,"-1") ){
	        sprintf(caWhere,"%s and (b.urlsort = '%s') ",caWhere,service);
	        sprintf(delWhere,"%s and (urlsort ='%s') ",delWhere,service);
	    }
    }  
    if(strcmp(caDtype,"unit2") == 0){ /* ʱ�䷶Χ  */
    	if((caSdate!=NULL)){    		
		        if(strlen(caSdate)>0) {
		            if(strlen(caSdate)==10) {
		            	sprintf(caWhere,"%s and (b.sdate = '%s')",caWhere,caSdate);
		            	sprintf(delWhere,"%s and (sdate = '%s')",delWhere,caSdate);
		             }            
		        }
			}
    } 
    if(strcmp(caBtype,"unit2")==0){ //������Χ
    	  sprintf(caWhere,"%s and (b.bytes >%ld)",caWhere,atol(caBbyte));
    	  sprintf(delWhere,"%s and (bytes >%ld)",delWhere,atol(caBbyte));
    }  
    if(iAction==2){/*del*/    	 
				if( strlen(delWhere)>0){
				    sprintf(sqlBuf,"delete from msauserhttpreport where %s ",delWhere);
				    ltDbExecSql(G_DbCon,sqlBuf);
		    }
		    
			  ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");		
				ltMsgFree(ltMsgPk);
				return 0;
    }else if(iAction==1){/*export*/			    
			    int  lTime;
			    char sDate[36];
			    char caLine[8012];
			    memset(sDate,0,sizeof(sDate));
			    lTime = time(0);
				  nasTimeFormat(sDate,lTime);	
				  if(caOrder!=NULL){
				    if( strlen(caOrder)>0 ) {
				    	if(strcmp(caOrder,"nosort")!=0) {
				        if(strcmp(caOrder,"sdate")==0) {//����������
				            sprintf(caWhere,"%s order by b.sdate ",caWhere);
				        }else if(strcmp(caOrder,"userid") == 0) {//���û�id����
				            sprintf(caWhere,"%s order by b.userid ",caWhere);
				        }else if(strcmp(caOrder,"host") == 0) {//��վ��
				            sprintf(caWhere,"%s order by b.host ",caWhere);
				        }else if(strcmp(caOrder,"bytes") == 0) {//������
				            sprintf(caWhere,"%s order by b.bytes ",caWhere);
				        }else if(strcmp(caOrder,"lcount") == 0) {//��������
				            sprintf(caWhere,"%s order by b.lcount ",caWhere);
				        }else if(strcmp(caOrder,"ctime") == 0) {//������ʱ��
				            sprintf(caWhere,"%s order by b.ctime ",caWhere);
				        }
				        if(strlen(caOrderby)) {
						           if(caOrderby[0] == '1') {   
						            	 if(strcmp(caOrder,"sdate")==0) {
										            	 ltStrAddF(caWhere," desc");
printf("caWhere1:%s\n",caWhere);										            	 
												   }else if(strcmp(caOrder,"userid")==0){
												   	       ltStrAddF(caWhere," desc");
												   }else if(strcmp(caOrder,"host")==0){
												   	        ltStrAddF(caWhere," desc");
												   }else if(strcmp(caOrder,"bytes")==0){
												   	        ltStrAddF(caWhere," desc");
												   }else if(strcmp(caOrder,"lcount")==0){
												   	        ltStrAddF(caWhere," desc");
												   }else if(strcmp(caOrder,"ctime")==0){
												   	        ltStrAddF(caWhere," desc");
												   }
						           }else{
						            	 if(strcmp(caOrder,"sdate")==0) {
										               ltStrAddF(caWhere," asc");
printf("caWhere2:%s\n",caWhere);		
												   }else if(strcmp(caOrder,"userid")==0){
												   	       ltStrAddF(caWhere," asc");
												   }else if(strcmp(caOrder,"host")==0){
												   	        ltStrAddF(caWhere," asc");
												   }else if(strcmp(caOrder,"bytes")==0){
												   	        ltStrAddF(caWhere," asc");
												   }else if(strcmp(caOrder,"lcount")==0){
												   	        ltStrAddF(caWhere," asc");
												   }else if(strcmp(caOrder,"ctime")==0){
												   	        ltStrAddF(caWhere," asc");
												   }           
						            } 
						    	}     
				       }
				     }   
			    }		
		sprintf(sqlBuf,"select a.dispname,b.host,b.sdate,b.bytes,b.lcount,b.ctime,b.urlsort,c.name from msauserhttpreport b left join msauser a on a.userid=b.userid left join msagroup c on a.groupid%d=c.id where %s limit %lu offset %lu",glevel,caWhere,lRowNum,lStartRec);	
printf("sqlBuf:%s\n",sqlBuf);		
    ltMsgPk->msgpktype=2;
		lt_TcpResponse(confd,ltMsgPk,2,"filename",LT_TYPE_STRING,"webexport.csv","contenttype","Application/MS-DOWNLOAD");			
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
			   if(tempCursor!=NULL){
							tempRow= ltDbFetchRow(tempCursor);
			       	while(tempRow!=NULL){
								sprintf(caLine,"%s,%s,%s,%s,%s,%s,%s\r\n",tempRow[6],tempRow[0],tempRow[1],tempRow[2],tempRow[3],tempRow[4],_ltPubInfo->_urlSortlist[atol(tempRow[6])].sortname);			
								write(confd,caLine,strlen(caLine));										
								tempRow= ltDbFetchRow(tempCursor);
							}
			     ltDbCloseCursor(tempCursor);
			   }		
				return 0;    	   	
    }


    sprintf(strBuf,"select count(*) from msauserhttpreport b left join msauser a on a.userid=b.userid left join msagroup c on a.groupid%d=c.id where %s",glevel,caWhere);
  
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
		if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			if(tempRow!=NULL){
				lCount=atol(tempRow[0]);
			}
		}
		ltDbCloseCursor(tempCursor);
	
	  if(caOrder!=NULL){
				    if( strlen(caOrder)>0 ) {
				    			if(strcmp(caOrder,"nosort")!=0) {
								        if(strcmp(caOrder,"sdate")==0) {//����������
								            sprintf(caWhere,"%s order by b.sdate ",caWhere);
								        }else if(strcmp(caOrder,"userid") == 0) {//���û�id����
								            sprintf(caWhere,"%s order by b.userid ",caWhere);
								        }else if(strcmp(caOrder,"host") == 0) {//��վ��
								            sprintf(caWhere,"%s order by b.host ",caWhere);
								        }else if(strcmp(caOrder,"bytes") == 0) {//������
								            sprintf(caWhere,"%s order by b.bytes ",caWhere);
								        }else if(strcmp(caOrder,"lcount") == 0) {//��������
								            sprintf(caWhere,"%s order by b.lcount ",caWhere);
								        }else if(strcmp(caOrder,"ctime") == 0) {//������ʱ��
								            sprintf(caWhere,"%s order by b.ctime ",caWhere);
								        }
				        
				          if(strlen(caOrderby)) {
						            if(caOrderby[0] == '1') {   
						            	   if(strcmp(caOrder,"sdate")==0) {
										            		 ltStrAddF(caWhere," desc");							            		 
													   }else if(strcmp(caOrder,"userid")==0){
													   	       ltStrAddF(caWhere," desc");
													   }else if(strcmp(caOrder,"host")==0){
													   	        ltStrAddF(caWhere," desc");
													   }else if(strcmp(caOrder,"bytes")==0){
													   	        ltStrAddF(caWhere," desc");
													   }else if(strcmp(caOrder,"lcount")==0){
													   	        ltStrAddF(caWhere," desc");
													   }else if(strcmp(caOrder,"ctime")==0){
													   	        ltStrAddF(caWhere," desc");
													   }
						            }else{
				            	       if(strcmp(caOrder,"date")==0) {
								            				  ltStrAddF(caWhere," asc");
													   }else if(strcmp(caOrder,"userid")==0){
													   	        ltStrAddF(caWhere," asc");
													   }else if(strcmp(caOrder,"host")==0){
													   	        ltStrAddF(caWhere," asc");
													   }else if(strcmp(caOrder,"bytes")==0){
													   	        ltStrAddF(caWhere," asc");
													   }else if(strcmp(caOrder,"lcount")==0){
													   	        ltStrAddF(caWhere," asc");
													   }else if(strcmp(caOrder,"ctime")==0){
													   	        ltStrAddF(caWhere," asc");
													   }
						            	           
						            } 
						        }
				    		}
				   	}   
		}	


//json����
	sprintf(sqlBuf,"select a.dispname,b.sdate,b.host,b.bytes,b.lcount,b.ctime,b.urlsort,a.userid,c.name,nasurlsort.sorname from msauserhttpreport b,msauser a,msagroup c,nasurlsort where a.userid =b.userid and a.groupid%d=c.id and b.urlsort=nasurlsort.sortid and %s limit %lu offset %lu",glevel,caWhere,lRowNum,lStartRec);
	sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
	stralloc_cats(&strTemp,caTmpp);
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	lNum=0;	
printf("sqlBuf:%s\n",sqlBuf);	
   if(tempCursor!=NULL){
	     tempRow= ltDbFetchRow(tempCursor);
       	while(tempRow!=NULL){
					  lNum++;
						if(lNum==1){
							  char sTime[32];
							    memset(sTime,0,sizeof(sTime));
							  	sprintf(sTime,"%ld",atol(tempRow[5])/3600);
									sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])/60);
									sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])%60);
									sprintf(caTmpp,"{\"mygroup\":\"%s\",\"uname\":\"%s\",\"mydate\":\"%s\",\"myurl\":\"%s\",\"flow\":\"%lld\",\"counts\":\"%ld\",\"times\":\"%s\",\"sorts\":\"%s\",\"uid\":\"%ld\",\"sorname\":\"%s\"}",
											tempRow[8],//GroupName
											tempRow[0],// a.dispname
											tempRow[1],//b.sdate
											tempRow[2],//b.host
											atoll(tempRow[3])/1024,//b.bytes
											atol(tempRow[4]),//b.lcount
											sTime,//b.ctime
											_ltPubInfo->_urlSortlist[atol(tempRow[6])].sortname,//b.urlsort
											atol(tempRow[7]),//a.userid
											tempRow[9]);
								      stralloc_cats(&strTemp,caTmpp);
								
						}else{
							   char sTime[32];
							    memset(sTime,0,sizeof(sTime));
							  	sprintf(sTime,"%ld",atol(tempRow[5])/3600);
									sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])/60);
									sprintf(sTime,"%s:%ld",sTime,atol(tempRow[5])%60);
								  sprintf(caTmpp,",{\"mygroup\":\"%s\",\"uname\":\"%s\",\"mydate\":\"%s\",\"myurl\":\"%s\",\"flow\":\"%lld\",\"counts\":\"%ld\",\"times\":\"%s\",\"sorts\":\"%s\",\"uid\":\"%ld\",\"sorname\":\"%s\"}",
											tempRow[8],//GroupName
											tempRow[0],//uname
											tempRow[1],//mydate
											tempRow[2],//myurl
											atoll(tempRow[3])/1024,//flow
											atol(tempRow[4]),//counts
											sTime,//times
											_ltPubInfo->_urlSortlist[atol(tempRow[6])].sortname,
											atol(tempRow[7]),//a.userid
											tempRow[9]);
								   		stralloc_cats(&strTemp,caTmpp);
		
						 }
						tempRow= ltDbFetchRow(tempCursor);
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
/*�ļ������¼�ڵ�����*/
int ltmsafiletranquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){ 
	ltTablePtr  tablePtr;
  ltDbCursor *tempCursor;
  LT_DBROW tempRow;
  ltDbHeadPtr dbPtr;
  
  char strBuf[512];
	char *gid;
  char *sFlag;
  char fWhere[128];
  int Num=0;
  
  gid=ltMsgGetVar_s(ltMsgPk,"groupid");
  sFlag=ltMsgGetVar_s(ltMsgPk,"trantype");
  	
  dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8");
  
  if(sFlag){
  	sprintf(fWhere,"tse%s",sFlag);
  	lt_dbput_rootvars(dbPtr,1,fWhere," selected ");
  }
  
  memset(strBuf,0,sizeof(strBuf));
  Num=0;
  sprintf(strBuf,"select tablename,sdate from msafileloglist where tabtype=%s",sFlag);
	tablePtr=lt_dbput_table(dbPtr,"datelist");
	tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
	if(tempCursor!=NULL){
    tempRow=ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){//�����м�¼			
			Num++;	
			char tempDate[32];
			char ToDate[32];		
			memset(tempDate,0,sizeof(tempDate));
			memset(ToDate,0,sizeof(ToDate));
			sprintf(tempDate,"%s",tempRow[1]);
			ToDate[0]=tempDate[0];
			ToDate[1]=tempDate[1];
			ToDate[2]=tempDate[2];
			ToDate[3]=tempDate[3];
			ToDate[4]='-';
			ToDate[5]=tempDate[4];
			ToDate[6]=tempDate[5];
			ToDate[7]='-';
			ToDate[8]=tempDate[6];
			ToDate[9]=tempDate[7];
			ToDate[10]='\0';
			if(Num==1){
       lt_dbput_recordvars(tablePtr,3,
       "dayname",LT_TYPE_STRING,tempRow[1],        
       "strdate",LT_TYPE_STRING,ToDate);
			}else{
       lt_dbput_recordvars(tablePtr,3,
       "dayname",LT_TYPE_STRING,tempRow[1],        
       "strdate",LT_TYPE_STRING,ToDate);
			}    				              
    tempRow=ltDbFetchRow(tempCursor);	
		}		
	}
	ltDbCloseCursor(tempCursor); 

	lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/datacenter/msafiletransearch.htm",dbPtr->head,0);
	ltMsgFree(ltMsgPk);
	lt_dbfree(dbPtr);
	
	return 0;
}

/*�ļ������¼��ѯ��������ɾ��*/
int ltmsafilequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
    ltDbCursor *tempCursor;
    LT_DBROW tempRow;
    long lRowNum,lStartRec,lCount,lSumRec,lNum;
    int  iAction=0;
    
    char sqlBuf[1024],strBuf[1024];
    char delWhere[512];//ɾ������
    char caWhere[512];
    
    char *caSdate=NULL;
    char *caHost=NULL;
    char *caOrder=NULL;
    char *caOrderby=NULL;
    char *m_action=NULL;
    char *caUser=NULL;  
    char *flag=NULL;
    char *gid=NULL;
    int intGid,glevel=0;	
    char caTmpp[2048];
    char tabname[256];//�ļ������¼����
    
    stralloc strTemp;
    strTemp.s=0;
    
    m_action=ltMsgGetVar_s(ltMsgPk,"action");
    if(m_action==NULL){
     iAction=0;
    }else{
      iAction=atol(m_action);
    } 
	  caUser=ltMsgGetVar_s(ltMsgPk,"user"); //uid    
    flag=ltMsgGetVar_s(ltMsgPk,"flag");//����
    caHost=ltMsgGetVar_s(ltMsgPk,"host");//host�ؼ���
    caSdate=ltMsgGetVar_s(ltMsgPk,"sdate");
    caOrder=ltMsgGetVar_s(ltMsgPk,"osort");// ����ʽ
    caOrderby=ltMsgGetVar_s(ltMsgPk,"orderby");//�� ��  
    gid=ltMsgGetVar_s(ltMsgPk,"groupid");
    intGid=atol(gid);  

		if(ltMsgGetVar_s(ltMsgPk,"limit")){ 
			lRowNum=atol(ltMsgGetVar_s(ltMsgPk,"limit"));
			}
		if(ltMsgGetVar_s(ltMsgPk,"start")){ 
			lStartRec=atol(ltMsgGetVar_s(ltMsgPk,"start"));
			}
	
		lRowNum=100; /*ÿҳ������*/
		lSumRec=0;/*������*/
		lCount=0; 
		lStartRec=0;
		lNum=0; /*��ҳʣ�������*/
					
		memset(caWhere,0,sizeof(caWhere));
		memset(delWhere,0,sizeof(delWhere));

		/*��ȡ���Ź�����*/	  
		sprintf(strBuf,"select level from msagroup where id=%d",intGid);
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
		if(tempCursor!=NULL){
				tempRow= ltDbFetchRow(tempCursor);
				if(tempRow!=NULL){
					glevel=atol(tempRow[0]);
				}
		}
		ltDbCloseCursor(tempCursor);

		/*�жϴ����Ƿ����ļ������¼��*/
		memset(strBuf,0,sizeof(strBuf));
		sprintf(strBuf,"select tablename,sdate from msafileloglist where tabtype=%s",flag);
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
			if(tempCursor!=NULL){
				tempRow=ltDbFetchRow(tempCursor);
				if(tempRow!=NULL){//�����м�¼		    
				    sprintf(tabname,"%s%s",tempRow[0],tempRow[1]);
				}		
			}
		ltDbCloseCursor(tempCursor); 
		printf("@@@:%s\n",tabname);

				if(strlen(tabname)==0){	  
					  return 0;  
				}

        if(strcmp(gid,"-1")==0){
					if(strcmp(caUser,"-1")==0){
					       sprintf(caWhere,"%s","2=2");//��ѯ�����û�
					       sprintf(delWhere,"%s","2=2");//
						}
				}
				 
				if(strcmp(gid,"-1")){//������-1
					   if(strcmp(caUser,"-1")==0){
					       sprintf(caWhere,"a.groupid%d=%d",glevel,intGid);//�������������û�
					       sprintf(delWhere,"a.groupid%d=%d",glevel,intGid);
						}else{
							    sprintf(caWhere,"b.userid=%s and a.groupid%d=%d",caUser,glevel,intGid);//msasearchkey  Ϊb��
								  sprintf(delWhere,"userid =%s",caUser); 
							}
					}
				
				 if(flag!=NULL){//�������ʹ���
			    if(strcmp(flag,"-1") ){
			        sprintf(caWhere,"%s and (b.tantype = '%s') ",caWhere,flag);
			        sprintf(delWhere,"%s and (tantype='%s') ",delWhere,flag);
			    }
		     }
		
		     if(caHost!=NULL){//�ؼ��ִ���
			    if(strlen(caHost)>0) {
			        sprintf(caWhere,"%s and (b.contenttype like '%c%s%c') ",caWhere,'%',caHost,'%');
			        sprintf(delWhere,"%s and (contenttype like '%c%s%c') ",delWhere,'%',caHost,'%');
			    }
		     }
    
    
    
    if(iAction==2){/*del*/    	 
				if( strlen(delWhere)>0){
				    sprintf(sqlBuf,"delete from %s where %s ",tabname,delWhere);
				    ltDbExecSql(G_DbCon,sqlBuf);
		        }
			  ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");		
				ltMsgFree(ltMsgPk);
				return 0;
    }else if(iAction==1){/*export*/	
			    char caLine[8012];	
				  if(caOrder!=NULL){
				    if( strlen(caOrder)>0 ) {
				    	if(strcmp(caOrder,"nosort")!=0){
				        if(strcmp(caOrder,"sdate")==0){//����������
				            sprintf(caWhere,"%s order by b.stime ",caWhere);
				        }else if(strcmp(caOrder,"filename") == 0){//���û�id����
				            sprintf(caWhere,"%s order by b.filename ",caWhere);
				        }
				        
			          if(strlen(caOrderby)){
				            if(caOrderby[0] == '1') {   
		            	     if(strcmp(caOrder,"date")==0) {
						                   ltStrAddF(caWhere," desc");
										   }else if(strcmp(caOrder,"filename")==0){
										   	       ltStrAddF(caWhere," desc");
										   }
				            }else{
		            	     if(strcmp(caOrder,"date")==0) {
						                   ltStrAddF(caWhere," asc");
										   }else if(strcmp(caOrder,"filename")==0){
										   	       ltStrAddF(caWhere," asc");
										   }         
				            } 
					      }
						        
				      }
			      }   
		      }	
			    
					memset(sqlBuf,0,sizeof(sqlBuf));			    
			    sprintf(sqlBuf,"select a.dispname,b.tantype,b.stime,b.filename,b.fileurl,b.contenttype from %s b left join msauser a on a.userid=b.userid where %s limit %lu offset %lu",tabname,caWhere,lRowNum,lStartRec);		
			
			    ltMsgPk->msgpktype=2;
					lt_TcpResponse(confd,ltMsgPk,2,"filename",LT_TYPE_STRING,"filetranexport.csv","contenttype","Application/MS-DOWNLOAD");			
					tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
				  if(tempCursor!=NULL){
								tempRow= ltDbFetchRow(tempCursor);
				       	while(tempRow!=NULL){
									sprintf(caLine,"%s,%s,%s,%s,%s,%s\r\n",tempRow[0],tempRow[1],tempRow[2],tempRow[3],tempRow[4],tempRow[5]);			
									write(confd,caLine,strlen(caLine));										
									tempRow= ltDbFetchRow(tempCursor);
								}
				     ltDbCloseCursor(tempCursor);
				  }		
			return 0;    	   	
    }
    
    memset(strBuf,0,sizeof(strBuf));
    sprintf(strBuf,"select count(*) from %s b left join msauser a on a.userid=b.userid where %s",tabname,caWhere);
    tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
	  if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			if(tempRow!=NULL){
				lCount=atol(tempRow[0]);
			}
	  }
    ltDbCloseCursor(tempCursor);
    
    //����
     if(caOrder!=NULL){
				    if( strlen(caOrder)>0 ) {
				    	if(strcmp(caOrder,"nosort")!=0) {
					        if(strcmp(caOrder,"sdate")==0){//����������
					            sprintf(caWhere,"%s order by b.stime ",caWhere);
					        }else if(strcmp(caOrder,"filename") == 0) {//���û�id����
					            sprintf(caWhere,"%s order by b.filename ",caWhere);
					        }
				        
				          if(strlen(caOrderby)) {
						            if(caOrderby[0] == '1') {   
						            	     if(strcmp(caOrder,"date")==0) {
										                   ltStrAddF(caWhere,"desc");
														   }else if(strcmp(caOrder,"filename")==0){
														   	       ltStrAddF(caWhere,"desc");
														   }
						            }else{
						            	     if(strcmp(caOrder,"date")==0) {
										                   ltStrAddF(caWhere," asc");
														   }else if(strcmp(caOrder,"filename")==0){
														   	       ltStrAddF(caWhere," asc");
														   }
						            	           
						            } 
						        }    
				    	}
				   	}   
		}	
    
    //json����
		memset(sqlBuf,0,sizeof(sqlBuf));
		sprintf(sqlBuf,"select a.dispname,b.tantype,b.stime,b.filename,b.fileurl,b.contenttype,a.userid from %s b left join msauser a on a.userid=b.userid where %s limit %lu offset %lu",tabname,caWhere,lRowNum,lStartRec);
		sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
		stralloc_cats(&strTemp,caTmpp);
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
		lNum=0;
    if(tempCursor!=NULL){
	     tempRow= ltDbFetchRow(tempCursor);
       	while(tempRow!=NULL){
					  lNum++;
						if(lNum==1){
									sprintf(caTmpp,"{\"uname\":\"%s\",\"mytantype\":\"%s\",\"mystime\":\"%s\",\"myfilename\":\"%s\",\"myfileurl\":\"%s\",\"mycontenttype\":\"%s\",\"userid\":\"%s\"}",
											tempRow[0],
											tempRow[1],
											tempRow[2],
											tempRow[3],
											tempRow[4],
											tempRow[5],
											tempRow[6]);
								   stralloc_cats(&strTemp,caTmpp);								
						}else{
								sprintf(caTmpp,",{\"uname\":\"%s\",\"mytantype\":\"%s\",\"mystime\":\"%s\",\"myfilename\":\"%s\",\"myfileurl\":\"%s\",\"mycontenttype\":\"%s\",\"userid\":\"%s\"}",
											tempRow[0],
											tempRow[1],
											tempRow[2],
											tempRow[3],
											tempRow[4],
											tempRow[5],
											tempRow[6]);
								   stralloc_cats(&strTemp,caTmpp);		
						 }
						tempRow= ltDbFetchRow(tempCursor);
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


/*MSN,QQ��¼�ڵ����ӵ��ú���*/
int ltimshowwebquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead)
{
  ltTablePtr  tablePtr;
  ltDbCursor *tempCursor;
  LT_DBROW tempRow;
  ltDbHeadPtr dbPtr;
  
  char strBuf[512];
	char *gid;
  char *sFlag;
  char fWhere[128];
  int Num=0;
  
  
  gid=ltMsgGetVar_s(ltMsgPk,"groupid");
  sFlag=ltMsgGetVar_s(ltMsgPk,"flag"); 
  
  dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8"); 
	
	if(sFlag){
  	sprintf(fWhere,"tse%s",sFlag);
  	lt_dbput_rootvars(dbPtr,1,fWhere," selected ");
  }
  
  memset(strBuf,0,sizeof(strBuf));
  Num=0;
  sprintf(strBuf,"select sdate,tabname from msaloglist where tabtype=%s",sFlag);
	tablePtr=lt_dbput_table(dbPtr,"datelist");
	tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
	if(tempCursor!=NULL){
    tempRow=ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){//�����м�¼			
			Num++;	
			char tempDate[32];
			char ToDate[32];		
			memset(tempDate,0,sizeof(tempDate));
			memset(ToDate,0,sizeof(ToDate));
			sprintf(tempDate,"%s",tempRow[0]);
			ToDate[0]=tempDate[0];
			ToDate[1]=tempDate[1];
			ToDate[2]=tempDate[2];
			ToDate[3]=tempDate[3];
			ToDate[4]='-';
			ToDate[5]=tempDate[4];
			ToDate[6]=tempDate[5];
			ToDate[7]='-';
			ToDate[8]=tempDate[6];
			ToDate[9]=tempDate[7];
			ToDate[10]='\0';
			if(Num==1){
       lt_dbput_recordvars(tablePtr,3,
       "dayname",LT_TYPE_STRING,tempRow[0],        
       "strdate",LT_TYPE_STRING,ToDate);
			}else{
       lt_dbput_recordvars(tablePtr,3,
       "dayname",LT_TYPE_STRING,tempRow[0],        
       "strdate",LT_TYPE_STRING,ToDate);
			}    				              
    tempRow=ltDbFetchRow(tempCursor);	
		}		
	}
	ltDbCloseCursor(tempCursor); 
	
	lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/datacenter/msaimsearb.htm",dbPtr->head,0);
	ltMsgFree(ltMsgPk);
	lt_dbfree(dbPtr);
	
  return 0;
}

/*MSN,qq��¼���ݲ�ѯ ���� ɾ��*/
int ltwebqueryima(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){ 
    ltDbCursor *tempCursor;
    LT_DBROW tempRow;
    long lRowNum,lStartRec,lCount,lSumRec,lNum;
    int  iAction=0;
    
    char strBuf[1024];
    char delWhere[512];//ɾ������
    char caWhere[512];//,xDate[30];
    
    char *caDtype=NULL; 
    char *caSdate=NULL;
    char *caHost=NULL;
    char *caOrder=NULL;
    char *caOrderby=NULL;
    char *m_action=NULL;
    char *caUser=NULL;  
    char *flag=NULL;//���ͱ��
    char *gid=NULL;
    int intGid,glevel=0;	
    char caTmpp[2048];
    char tabname[256];//ͨ�ż�¼����
    
    stralloc strTemp;
    strTemp.s=0;
    
    m_action=ltMsgGetVar_s(ltMsgPk,"action");
    if(m_action==NULL){
      iAction=0;
    }else{
      iAction=atol(m_action);
    }
    
    caUser=ltMsgGetVar_s(ltMsgPk,"user"); //uid
    flag=ltMsgGetVar_s(ltMsgPk,"flag");//url����
    caHost=ltMsgGetVar_s(ltMsgPk,"host");//host�ؼ���
    caDtype=ltMsgGetVar_s(ltMsgPk,"dtype");
    caSdate=ltMsgGetVar_s(ltMsgPk,"sdate");
    caOrder=ltMsgGetVar_s(ltMsgPk,"osort");   // ����ʽ
    caOrderby=ltMsgGetVar_s(ltMsgPk,"orderby");   //�� ��
    gid=ltMsgGetVar_s(ltMsgPk,"groupid");
    intGid=atol(gid);
	  
		if(ltMsgGetVar_s(ltMsgPk,"limit")){ 
			lRowNum=atol(ltMsgGetVar_s(ltMsgPk,"limit"));
			}
		if(ltMsgGetVar_s(ltMsgPk,"start")){ 
			lStartRec=atol(ltMsgGetVar_s(ltMsgPk,"start"));
			}
	
		lRowNum=100; /*ÿҳ������*/
		lSumRec=0;/*������*/
		lCount=0; 
		lStartRec=0;
		lNum=0; /*��ҳʣ�������*/
					
		memset(caWhere,0,sizeof(caWhere));
		memset(delWhere,0,sizeof(delWhere));		
		/*��ȡ���Ź�����*/	  
		sprintf(strBuf,"select level from msagroup where id=%d",intGid);
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
		if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			if(tempRow!=NULL){
				glevel=atol(tempRow[0]);
			}
		}
		ltDbCloseCursor(tempCursor);  

		/*�жϴ����Ƿ����ļ������¼��*/
		memset(strBuf,0,sizeof(strBuf));
		sprintf(strBuf,"select tabname,sdate from msaloglist where sdate='%ld' and tabtype=%s",atol(caSdate),flag);		
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
			if(tempCursor!=NULL){
				tempRow=ltDbFetchRow(tempCursor);
				if(tempRow!=NULL){//�����м�¼		    
				    sprintf(tabname,"%s%s",tempRow[0],tempRow[1]);
				}		
			}
		ltDbCloseCursor(tempCursor); 		
		if(strlen(tabname)==0){	  
					  return 0;  
		}
		
    if(strcmp(gid,"-1")==0){
			if(strcmp(caUser,"-1")==0){
			       sprintf(caWhere,"%s","2=2");//��ѯ�����û�
			       sprintf(delWhere,"%s","2=2");//
				}
		}
		
		if(strcmp(gid,"-1")){//������-1
			  if(strcmp(caUser,"-1")==0){
			       sprintf(caWhere,"a.groupid%d=%d",glevel,intGid);//�������������û�
			       sprintf(delWhere,"a.groupid%d=%d",glevel,intGid);
				}else{
					   sprintf(caWhere,"b.userid=%s and a.groupid%d=%d",caUser,glevel,intGid);//��ѯ�����û�
						 sprintf(delWhere,"userid = %s",caUser); 
				}
		}        
		if(flag!=NULL){//�������ʹ���
	    if(strcmp(flag,"-1") ){
	        sprintf(caWhere,"%s and (b.flags = '%s') ",caWhere,flag);
	        sprintf(delWhere,"%s and (flags='%s') ",delWhere,flag);
	    }
	  }
    if(caHost!=NULL){//�ؼ��ִ���
	    if(strlen(caHost)>0) {
	        sprintf(caWhere,"%s and (b.imcon like '%c%s%c') ",caWhere,'%',caHost,'%');
	        sprintf(delWhere,"%s and (imcon like '%c%s%c') ",delWhere,'%',caHost,'%');
	    }
    }
       
    if(iAction==2){/*del*/  	 
				if(strlen(delWhere)>0){
				    sprintf(strBuf,"delete from %s where %s ",tabname,delWhere);
				    ltDbExecSql(G_DbCon,strBuf);
		    }
			  ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=utf-8\n","lthtml",LT_TYPE_STRING,"0");		
				ltMsgFree(ltMsgPk);
				return 0;
    }else if(iAction==1){/*export*/		    
			    char caUrl1[200];//
			    int  lTime;
			    char sDate[36];
			    char caLine[8012];			
			    memset(sDate,0,sizeof(sDate));
			    lTime = time(0);
				  nasTimeFormat(sDate,lTime);  
			 
					if(caOrder!=NULL){
					    if(strlen(caOrder)>0){
							    	if(strcmp(caOrder,"nosort")!=0) {
									        if(strcmp(caOrder,"date")==0) {
									            sprintf(caWhere,"%s order by b.sdate ",caWhere);
									        }else if(strcmp(caOrder,"user") == 0) {
									            sprintf(caWhere,"%s order by b.userid ",caWhere);
									        }
									        if(strlen(caOrderby)) {
									            if(caOrderby[0] == '1') {   				            	  
													       ltStrAddF(caWhere," desc");								         
									            }else{
									              ltStrAddF(caWhere," asc");				               
									            } 
									        }
							    }
					   }   
		 			}	
		 
		 
			sprintf(strBuf,"select a.dispname,b.sdate,b.stime,b.imfrom,b.imto,b.imcon,b.flags,c.name from %s b left join msauser a on a.userid=b.userid  left join msagroup c on a.groupid%d=c.id where %s limit %lu offset %lu",tabname,glevel,caWhere,lRowNum,lStartRec);

			ltMsgPk->msgpktype=2;
			lt_TcpResponse(confd,ltMsgPk,2,"filename",LT_TYPE_STRING,"imexport.csv","contenttype","Application/MS-DOWNLOAD");
			tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
			if(tempCursor!=NULL){
				 tempRow=ltDbFetchRow(tempCursor);
			   while(tempRow!=NULL){
					  if(atol(tempRow[6])==1){
							sprintf(caUrl1,"Msn");
						}else if(atol(tempRow[6])==2){
							sprintf(caUrl1,"Yahoo");
						}else if(atol(tempRow[6])==3){
							sprintf(caUrl1,"QQ");
						}else if(atol(tempRow[6])==4){
							sprintf(caUrl1,"TaoBao");
						}else if(atol(tempRow[6])==5){
							sprintf(caUrl1,"FeiXin");
						}else if(atol(tempRow[6])==6){
							sprintf(caUrl1,"Skype");
						}else {
							sprintf(caUrl1,"???");
						}				
					  sprintf(caLine,"%s,%s,%s,%s,%s,%s,%s,%s\r\n",
					    tempRow[7],//GroupName
							tempRow[0],//dispname
							tempRow[2],//sdate
							tempRow[3],//stime
							tempRow[4],//imfrom
							tempRow[5],//imto
							tempRow[6],//imcon
							caUrl1);
					 write(confd,caLine,strlen(caLine));	
					 tempRow= ltDbFetchRow(tempCursor);
				}
			     ltDbCloseCursor(tempCursor);
			}
		  ltMsgFree(ltMsgPk);
			return 0;
    	
    }
  	sprintf(strBuf,"select count(*) from msaimlog b left join msauser a on a.userid=b.userid left join msagroup c on a.groupid%d=c.id where %s",glevel,caWhere);
		tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
		if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			if(tempRow!=NULL){
				lCount=atol(tempRow[0]);
			}
		}
		ltDbCloseCursor(tempCursor);   

    if(caOrder!=NULL){
			    if(strlen(caOrder)>0){
					    	if(strcmp(caOrder,"nosort")!=0) {
								        if(strcmp(caOrder,"date")==0){
								            sprintf(caWhere,"%s order by b.sdate ",caWhere);
								        }else if(strcmp(caOrder,"user") == 0) {
								            sprintf(caWhere,"%s order by b.userid ",caWhere);
								        }
								        if(strlen(caOrderby)) {
								            if(caOrderby[0] == '1'){   				            	  
												       ltStrAddF(caWhere," desc");							         
								            }else{
								              ltStrAddF(caWhere," asc");				               
								            } 
											  }
					        }
			   }   
    }	    	
	 sprintf(strBuf,"select a.dispname,b.sdate,b.stime,b.imfrom,b.imto,b.imcon,b.flags,a.userid,c.name from %s b  left join msauser a on (a.userid =b.userid) left join msagroup c on a.groupid%d=c.id where %s limit %lu offset %lu",tabname,glevel,caWhere,lRowNum,lStartRec);
   sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
   stralloc_cats(&strTemp,caTmpp);  
   tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
   if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
    	while(tempRow!=NULL){
        char caUrl[32];     
        lNum++;						
				if(atol(tempRow[6])==1){
					sprintf(caUrl,"Msn");
				}else if(atol(tempRow[6])==2){
					sprintf(caUrl,"Yahoo");
				}else if(atol(tempRow[6])==3){
					sprintf(caUrl,"QQ");
				}else if(atol(tempRow[6])==4){
					sprintf(caUrl,"TaoBao");
				}else if(atol(tempRow[6])==5){
					sprintf(caUrl,"FeiXin");
				}else if(atol(tempRow[6])==6){
					sprintf(caUrl,"Skype");
				}else {
					sprintf(caUrl,"???");
				}	
				
        if(lNum==1){ 
					  sprintf(caTmpp,"{\"mygroup\":\"%s\",\"uid\":\"%s\",\"uname\":\"%s\",\"mysdate\":\"%s\",\"mystime\":\"%s\",\"myimfrom\":\"%s\",\"myimto\":\"%s\",\"myimcon\":\"%s\",\"myflags\":\"%s\"}",
					     tempRow[8],tempRow[7],tempRow[0],tempRow[1], tempRow[2],tempRow[3],tempRow[4],tempRow[5],caUrl);
						   stralloc_cats(&strTemp,caTmpp);
				}else{					    
					  sprintf(caTmpp,",{\"mygroup\":\"%s\",\"uid\":\"%s\",\"uname\":\"%s\",\"mysdate\":\"%s\",\"mystime\":\"%s\",\"myimfrom\":\"%s\",\"myimto\":\"%s\",\"myimcon\":\"%s\",\"myflags\":\"%s\"}",
					     tempRow[8],tempRow[7],tempRow[0],tempRow[1], tempRow[2],tempRow[3],tempRow[4],tempRow[5],caUrl);
						   stralloc_cats(&strTemp,caTmpp);
			  }       
		    tempRow= ltDbFetchRow(tempCursor);
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
*ĳ�û���������ݹ켣
*/ 
int msaUserAvclog(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	  //���ݴ��Ĳ����ж�ɾ���Լ�ִ��ɾ��
	  char *myuser_id;
	  char *mySdate;
    ltDbHeadPtr dbPtr;
    dbPtr=lt_dbinit();
    LT_DBROW   tempRow;
    myuser_id=ltMsgGetVar_s(ltMsgPk,"AvcmyUser_id");
    mySdate=ltMsgGetVar_s(ltMsgPk,"AvcmymySdate");
    dbPtr=lt_dbinit();
    lt_db_htmlpage(dbPtr,"utf-8");
   
    char strBuf[1024];
    ltDbCursor *tempCursor;
    char caTmpp[512];
    long lRowNum,lStartRec,lSumRec,lCount,lNum;
    int k;
  
	  char *caRule_id;    //��������Id
    char *caanjian_id;  //����Id
    char *caRule_name;  //������������
    char *caRule_type;//��������
    char *caKeyWord1;
    char *caKeyWord2;
    char *caKeyWord3;
    char *caRule_endtime;//���򴥷�����ʱ��
    char *caRule_areacode;//�����������
    char *caupdateflag;//���±��
	 
    stralloc strTemp;
    
    caRule_id=ltMsgGetVar_s(ltMsgPk,"Rule_id");  
    caanjian_id=ltMsgGetVar_s(ltMsgPk,"anjian_id");  
    caRule_name=ltMsgGetVar_s(ltMsgPk,"Rule_name"); 
    caRule_type=ltMsgGetVar_s(ltMsgPk,"Rule_type");  
    caKeyWord1=ltMsgGetVar_s(ltMsgPk,"KeyWord1");  
    caKeyWord2=ltMsgGetVar_s(ltMsgPk,"KeyWord2");  
    caKeyWord3=ltMsgGetVar_s(ltMsgPk,"KeyWord3"); 
    caRule_endtime=ltMsgGetVar_s(ltMsgPk,"Rule_endtime");
    caRule_areacode=ltMsgGetVar_s(ltMsgPk,"Rule_areacode");  
    caupdateflag=ltMsgGetVar_s(ltMsgPk,"updateflag");  
		
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
    sprintf(strBuf,"select count(*) from msavclog%ld where userid='%s'",atol(mySdate),myuser_id);
    tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
    if(tempCursor!=NULL)
    {
		  tempRow= ltDbFetchRow(tempCursor);
		  if(tempRow!=NULL)
		  {
			  lCount=atol(tempRow[0]);
		  }
    }
	  ltDbCloseCursor(tempCursor);
	  strTemp.s=0;
	  sprintf(caTmpp,"{\"totalCount\":\"%ld\",\"Results\":[",lCount);
	  stralloc_cats(&strTemp,caTmpp);
	  k=0;
	  sprintf(strBuf,"select a.userid,b.dispname,a.sdate,a.stime,a.vctype,a.vccon,a.vcaction,a.vcatt from msavclog%ld a,msauser b where a.userid=b.userid and a.userid='%s' limit %lu offset %lu ",atol(mySdate),myuser_id,lRowNum,lStartRec);
	  tempCursor=ltDbOpenCursor(G_DbCon,strBuf);
  	if(tempCursor!=NULL){
     tempRow=ltDbFetchRow(tempCursor);
     while(tempRow!=NULL){                
        if(k==0){
          sprintf(caTmpp,"{\"userid\":\"%s\",\"username\":\"%s\",\"sdate\":\"%s\",\"stime\":\"%s\",\"vctype\":\"%s\",\"vccon\":\"%s\",\"vcaction\":\"%s\",\"vcatt\":\"%s\"}",tempRow[0],tempRow[1],tempRow[2],tempRow[3],tempRow[4],tempRow[5],tempRow[6],tempRow[7]);
          stralloc_cats(&strTemp,caTmpp);     
				}else{
			    sprintf(caTmpp,",{\"userid\":\"%s\",\"username\":\"%s\",\"sdate\":\"%s\",\"stime\":\"%s\",\"vctype\":\"%s\",\"vccon\":\"%s\",\"vcaction\":\"%s\",\"vcatt\":\"%s\"}",tempRow[0],tempRow[1],tempRow[2],tempRow[3],tempRow[4],tempRow[5],tempRow[6],tempRow[7]);
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
//�û����ڵ�����
/*int ltuserTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){//�û�����
	  char *uid;
	  char *gid;
	  char *level;
		ltDbHeadPtr dbPtr;
		
		//��¼����
		gid=ltMsgGetVar_s(ltMsgPk,"gid");
		level=ltMsgGetVar_s(ltMsgPk,"level");
		uid=ltMsgGetVar_s(ltMsgPk,"uid");
		if(!gid){
			gid=0;
		}
		if(!level){
			level=0;
		}
		if(!uid){
			uid=0;
		}
		
		dbPtr=lt_dbinit();
		lt_db_htmlpage(dbPtr,"utf-8");
		  
	  lt_dbput_rootvars(dbPtr,1,"gid",gid);  
	  lt_dbput_rootvars(dbPtr,1,"level",level);
	  lt_dbput_rootvars(dbPtr,1,"uid",uid);  
	  
    ltMsgPk->msgpktype=1;
		lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/datacenter/grouptree.htm",dbPtr->head,0);
		ltMsgFree(ltMsgPk);
		lt_dbfree(dbPtr);
		return 0;
}*/
//�û�������
int msaUserTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	char sqlBuf[512];
	char tmpstr[512];
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	char *level;
	char *gid;
	stralloc strTemp;

	int iHead;
	memset(tmpstr,0,sizeof(tmpstr));
	level=0;
	gid=0;
	iHead=1;
	strTemp.s=0;
	if(ltMsgGetVar_s(ltMsgPk,"gid")!=NULL){
		gid=ltMsgGetVar_s(ltMsgPk,"gid");
	}
	if(ltMsgGetVar_s(ltMsgPk,"level")!=NULL){
		level=ltMsgGetVar_s(ltMsgPk,"level");
	}
	stralloc_cats(&strTemp,"[");
 	sprintf(sqlBuf,"select userid,dispname from msauser where groupid%s=%s order by userid asc",level,gid);
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
			/*�ж���û���ӽڵ�*/
			if(iHead==1){
				sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[1],tempRow[1]);
				iHead=0;
			}else{
			  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[1],tempRow[1]);
		  }
		  stralloc_cats(&strTemp,tmpstr);
			stralloc_cats(&strTemp,",leaf: true}");
			tempRow= ltDbFetchRow(tempCursor);
			}
		ltDbCloseCursor(tempCursor);
	}
	stralloc_cats(&strTemp,"]");
  stralloc_0(&strTemp);

	ltMsgPk->msgpktype=1;
	lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,strTemp.s);
	ltMsgFree(ltMsgPk);
	return 0;
}
//����������
/*int ltdateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){//��������
	  ltDbHeadPtr dbPtr;
		dbPtr=lt_dbinit();
		lt_db_htmlpage(dbPtr,"utf-8");  
	  
    ltMsgPk->msgpktype=1;
		lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/datacenter/datetree.htm",dbPtr->head,0);
		ltMsgFree(ltMsgPk);
		lt_dbfree(dbPtr);
		return 0;
}*/
//��������������������������
/*int msaDateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	char sqlBuf[512];
	char tmpstr[512];
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	stralloc strTemp;

	int iHead;
	memset(tmpstr,0,sizeof(tmpstr));
	iHead=1;
	strTemp.s=0;
	stralloc_cats(&strTemp,"[");
 	sprintf(sqlBuf,"select distinct sdate from msauserhttpreport union all select distinct sdate from msasrvreport union all select distinct sdate from msaloglist union all select distinct sdate from msafileloglist order by sdate");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			char myday[8];
      char *tabDate=NULL;
			char dateDesc[10];
			while(tempRow!=NULL){
	      tabDate=tempRow[0];
	      myday[0]=tabDate[0];
	      myday[1]=tabDate[1];
	      myday[2]=tabDate[2];
	      myday[3]=tabDate[3];
	      myday[4]=tabDate[4];
	      myday[5]=tabDate[5];
	      myday[6]=tabDate[6];
	      myday[7]=tabDate[7];
	      myday[8]='\0';
			  sprintf(dateDesc,"%c%c%c%c-%c%c-%c%c",myday[0],myday[1],myday[2],myday[3],myday[4],myday[5],myday[6],myday[7]);
				//�ж���û���ӽڵ�
				if(iHead==1){
					sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[0],dateDesc);
					iHead=0;
				}else{
				  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[0],dateDesc);
			  }
			  stralloc_cats(&strTemp,tmpstr);
				stralloc_cats(&strTemp,",leaf: true}");
				tempRow= ltDbFetchRow(tempCursor);
			}
			ltDbCloseCursor(tempCursor);
	}
	stralloc_cats(&strTemp,"]");
  stralloc_0(&strTemp);

	ltMsgPk->msgpktype=1;
	lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,strTemp.s);
	ltMsgFree(ltMsgPk);
	return 0;
}*/

//��������������������������
int msaDateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	char sqlBuf[512];
	char tmpstr[512];
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	stralloc strTemp;

	int iHead;
	memset(tmpstr,0,sizeof(tmpstr));
	iHead=1;
	strTemp.s=0;
	stralloc_cats(&strTemp,"[");
 	sprintf(sqlBuf,"select distinct sdate from msauserhttpreport union all select distinct sdate from msasrvreport union all select distinct sdate from msaloglist union all select distinct sdate from msafileloglist order by sdate");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			char myday[8];
      char *tabDate=NULL;
			char dateDesc[10];
			while(tempRow!=NULL){
	      tabDate=tempRow[0];
	      myday[0]=tabDate[0];
	      myday[1]=tabDate[1];
	      myday[2]=tabDate[2];
	      myday[3]=tabDate[3];
	      myday[4]=tabDate[4];
	      myday[5]=tabDate[5];
	      myday[6]=tabDate[6];
	      myday[7]=tabDate[7];
	      myday[8]='\0';
			  sprintf(dateDesc,"%c%c%c%c-%c%c-%c%c",myday[0],myday[1],myday[2],myday[3],myday[4],myday[5],myday[6],myday[7]);
				/*�ж���û���ӽڵ�*/
				if(iHead==1){
					if(myday[4]=='-'){
						sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[0],tempRow[0]);
					}else{
						sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s'",dateDesc,dateDesc,dateDesc);
					}
					iHead=0;
				}else{
					if(myday[4]=='-'){
						sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[0],tempRow[0]);
					}else{
						sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",dateDesc,dateDesc,dateDesc);
					}
				  //sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[0],dateDesc);
			  }
			  stralloc_cats(&strTemp,tmpstr);
				stralloc_cats(&strTemp,",leaf: true}");
				tempRow= ltDbFetchRow(tempCursor);
			}
			ltDbCloseCursor(tempCursor);
	}
	stralloc_cats(&strTemp,"]");
  stralloc_0(&strTemp);

	ltMsgPk->msgpktype=1;
	lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,strTemp.s);
	ltMsgFree(ltMsgPk);
	return 0;
}
