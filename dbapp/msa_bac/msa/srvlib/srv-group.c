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


int msalooparea(stralloc *strTemp,int level,int pid){
	
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	ltDbConn *Tmp_DbCon; /*各个包处理进程的数据库连接*/
	char *dbUser;
	char *dbPass;
	char *dbName;
	char sqlBuf[512];
	char tmpstr[512]; 
	int iHead;
	level++;
  dbName=_ltPubInfo->_dbname;
	dbUser=_ltPubInfo->_dbuser;
	dbPass=_ltPubInfo->_dbpass;
	Tmp_DbCon=ltDbConnect(dbUser,dbPass,dbName);
	if (Tmp_DbCon==NULL){
		return -1;
	}
	sprintf(sqlBuf,"select id,pid,name,mydesc,level from msaGroup where level=%d and pid=%d order by id asc ",level,pid );
	tempCursor=ltDbOpenCursor(Tmp_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		if(tempRow==NULL){
			sprintf(tmpstr,"%s",",leaf: true");
			stralloc_cats(strTemp,tmpstr);
			ltDbCloseCursor(tempCursor);
			ltDbClose(Tmp_DbCon);
	    return 0;
		}else{
		  sprintf(tmpstr,"%s",",children: [");
			stralloc_cats(strTemp,tmpstr);
	  }
		iHead=1;
		while(tempRow!=NULL){
			if(iHead==1){
				sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s',level:'%d'",tempRow[0],tempRow[3],tempRow[2],level);
				iHead=0;
			}else{
			  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s',level:'%d'",tempRow[0],tempRow[3],tempRow[2],level);
		  }
			stralloc_cats(strTemp,tmpstr);
			pid=atol(tempRow[0]);
			
			if(level<5){
				msalooparea(strTemp,level,pid);
			}
			stralloc_cats(strTemp,"}");
			tempRow= ltDbFetchRow(tempCursor);

		}
		stralloc_cats(strTemp,"]");
		ltDbCloseCursor(tempCursor);
	}
	ltDbClose(Tmp_DbCon);

	return 0;
}

int msaGroupTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	
	char sqlBuf[512];
	char tmpstr[512];
	char name[32];
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	int level,pid,type;
	stralloc strTemp;

	int iHead;
	memset(tmpstr,0,sizeof(tmpstr));
	type=0;
	pid=0;
	level=0;
	iHead=1;
	strTemp.s=0;
	if(ltMsgGetVar_s(ltMsgPk,"type")!=NULL){
		type=atol(ltMsgGetVar_s(ltMsgPk,"type"));
	}
	if(ltMsgGetVar_s(ltMsgPk,"name")!=NULL){
		sprintf(name,"%s",ltMsgGetVar_s(ltMsgPk,"name"));
	}
	//stralloc_cats(&strTemp,"\xef\xbb\xbf[");
	stralloc_cats(&strTemp,"[");
 	sprintf(sqlBuf,"select id,pid,name,mydesc,level from msaGroup where level=0 and pid=0 order by id asc");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(type==0){
		if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				/*判断有没有子节点*/
				if(iHead==1){
					sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[3],tempRow[2]);
					iHead=0;
				}else{
				  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[3],tempRow[2]);
			  }
			  stralloc_cats(&strTemp,tmpstr);
			  pid=atol(tempRow[0]);
				if(level<5){
					msalooparea(&strTemp,level,pid);
				}
				stralloc_cats(&strTemp,"}");
				tempRow= ltDbFetchRow(tempCursor);
			}
		}
			ltDbCloseCursor(tempCursor);
	}else if(type==2){
		char allgroup[1024],msassessionid[12];
		memset(allgroup,0,sizeof(allgroup));
		memset(msassessionid,0,sizeof(msassessionid));
		ltMsgGetSomeNVar(ltMsgPk,1,"msasessionid",LT_TYPE_STRING, 12, msassessionid);
		sprintf(allgroup,"%s",_ltPubInfo->admSession[atol(msassessionid)].allgroup);
		printf("\n ALLGROUP:%s \n",allgroup);
		if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				/*判断管理员的权限*/
				printf("ALLGROUP:%c \n",allgroup[atol(tempRow[0])]);
				if(allgroup[atol(tempRow[0])]==49){
							if(iHead==1){
								sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s',level:'%d'",tempRow[0],tempRow[3],tempRow[2],level);
								iHead=0;
							}else{
							  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s',level:'%d'",tempRow[0],tempRow[3],tempRow[2],level);
						  }
						  stralloc_cats(&strTemp,tmpstr);		
							pid=atol(tempRow[0]);						
							if(level<5){
								msalooparea(&strTemp,level,pid);
							}
							stralloc_cats(&strTemp,"}");
				}
				tempRow= ltDbFetchRow(tempCursor);
			}
			ltDbCloseCursor(tempCursor);
		}
	}else if(type==1){
				if(tempCursor!=NULL){
						tempRow= ltDbFetchRow(tempCursor);
						while(tempRow!=NULL){
						/*判断有没有子节点*/
						if(iHead==1){
							sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s',checked: false",tempRow[0],tempRow[3],tempRow[2]);
							iHead=0;
						}else{
						  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s',checked: false",tempRow[0],tempRow[3],tempRow[2]);
					  }
					  stralloc_cats(&strTemp,tmpstr);			  
						stralloc_cats(&strTemp,",leaf: true}");	
						tempRow= ltDbFetchRow(tempCursor);
						}
					ltDbCloseCursor(tempCursor);
				}
	}else if(type==3){
						char *dbUser;
						char *dbPass;
						char *dbName;
						char sqlstr[512],groupmanager[1024];
						ltDbConn *Tmp_DbCon;
						dbName=_ltPubInfo->_dbname;
						dbUser=_ltPubInfo->_dbuser;
						dbPass=_ltPubInfo->_dbpass;
						Tmp_DbCon=ltDbConnect(dbUser,dbPass,dbName);
						ltDbCursor *tempCursor1;
						LT_DBROW tempRow1;
						memset(groupmanager,0,sizeof(groupmanager));
						sprintf(sqlstr,"select substr(grouplist1,1,200),substr(grouplist2,1,200),substr(grouplist3,1,200),substr(grouplist4,1,200),substr(grouplist5,1,200) from msaadmuser where name='%s'",name);
						tempCursor1=ltDbOpenCursor(Tmp_DbCon,sqlstr);
						tempRow1= ltDbFetchRow(tempCursor1);
						sprintf(groupmanager,"%s%s%s%s%s",tempRow1[0],tempRow1[1],tempRow1[2],tempRow1[3],tempRow1[4]);
						if(tempCursor!=NULL){
						tempRow= ltDbFetchRow(tempCursor);
						while(tempRow!=NULL){
								if(iHead==1){
									sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[3],tempRow[2]);
									iHead=0;
								}else{
								  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s'",tempRow[0],tempRow[3],tempRow[2]);
							  }
							  stralloc_cats(&strTemp,tmpstr);
							  if(groupmanager[atol(tempRow[0])]==49){
							  	stralloc_cats(&strTemp,",leaf: true,checked: true}");
							  	}else{
							  	stralloc_cats(&strTemp,",leaf: true,checked: false}");
							  	}
								tempRow= ltDbFetchRow(tempCursor);
						}
					ltDbCloseCursor(tempCursor);
					ltDbClose(Tmp_DbCon);
				}
	}else if(type==4){
			if(tempCursor!=NULL){
			tempRow= ltDbFetchRow(tempCursor);
			while(tempRow!=NULL){
				/*判断有没有子节点*/
				if(iHead==1){
					sprintf(tmpstr,"{id: '%s',qtip: '%s',text: '%s',checked:false",tempRow[0],tempRow[3],tempRow[2]);
					iHead=0;
				}else{
				  sprintf(tmpstr,",{id: '%s',qtip: '%s',text: '%s',checked:false",tempRow[0],tempRow[3],tempRow[2]);
			  }
			  stralloc_cats(&strTemp,tmpstr);
			  pid=atol(tempRow[0]);
				if(level<5){
					msalooparea(&strTemp,level,pid);
				}
				stralloc_cats(&strTemp,"}");
				tempRow= ltDbFetchRow(tempCursor);
			}
		}
			ltDbCloseCursor(tempCursor);
	}else if(type==5){
		for(iii=0;iii<_ltPubInfo->_dbUserInfoHead.bufnum;iii++){
	 		 tmpdbuserinfo=msaLookUpDbUserById(_ltPubInfo,iii);
       if(tmpdbuserinfo!=NULL&&tmpdbuserinfo->userid==uid){
    			sprintf(userid,"%d",tmpdbuserinfo->groupid);
    	 }
    }
	}
	stralloc_cats(&strTemp,"]");
  stralloc_0(&strTemp);  

	ltMsgPk->msgpktype=1;
	lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: application/json\n","lthtml",LT_TYPE_STRING,strTemp.s);    
	ltMsgFree(ltMsgPk);
	return 0;
}


int msaGroupAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){
	
	char sqlBuf[1024];
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	int  actiontype;
	
	actiontype=atol(ltMsgGetVar_s(ltMsgPk,"actiontype"));
	if(actiontype==1){/*add*/
	
		long lCount;
		int tttid;
    lCount=0;
    for(tttid=1;tttid<_MAX_ALLGRPNUM;tttid++){
    	
		        sprintf(sqlBuf,"select count(*) from msaGroup where id=%d ",tttid);
						tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
						if(tempCursor){
							tempRow= ltDbFetchRow(tempCursor);
							if(tempRow){
								if( atol(tempRow[0])==0){
									lCount=tttid;
									ltDbCloseCursor(tempCursor);
									break;
								}
							}
							ltDbCloseCursor(tempCursor);
						}
    }
    if(lCount>0){
				sprintf(sqlBuf,"insert into msaGroup values (%ld,%s,'%s','%s',%s)",
					lCount,ltMsgGetVar_s(ltMsgPk,"pid"),ltMsgGetVar_s(ltMsgPk,"name"),ltMsgGetVar_s(ltMsgPk,"mydesc"),
					ltMsgGetVar_s(ltMsgPk,"level"));
				printf("tree:sqlBuf:%s\n",sqlBuf);
				ltDbExecSql(G_DbCon,sqlBuf); 
	  }
	  ltMsgPk->msgpktype=1;
	  sprintf(sqlBuf,"%ld",lCount);
		lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/plain\n","lthtml",LT_TYPE_STRING,sqlBuf);
		ltMsgFree(ltMsgPk);
		return 0;
	}else if (actiontype==2){/*del*/
		int allnum;
		allnum=0;
		/*有子分组就不能删除*/
		sprintf(sqlBuf,"select count(*) from msaGroup where pid=%s ",ltMsgGetVar_s(ltMsgPk,"id"));
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
		if(tempCursor){
				tempRow= ltDbFetchRow(tempCursor);
				if(tempRow){
						allnum= atol(tempRow[0]);
				}
				ltDbCloseCursor(tempCursor);
		}
		if(allnum==0){				
			sprintf(sqlBuf,"delete from msaGroup where id=%s ",ltMsgGetVar_s(ltMsgPk,"id"));		
			ltDbExecSql(G_DbCon,sqlBuf);
			ltMsgPk->msgpktype=1;
			lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/plain\n","lthtml",LT_TYPE_STRING,"0");
			ltMsgFree(ltMsgPk);
			return 0;
		}
		
		ltMsgPk->msgpktype=1;
	  lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/plain\n","lthtml",LT_TYPE_STRING,"1");
	  ltMsgFree(ltMsgPk);
		return 0;

	}else if (actiontype==3){/*update*/
		if(atol(ltMsgGetVar_s(ltMsgPk,"id"))!=0){
			sprintf(sqlBuf,"update msaGroup set name='%s',mydesc='%s' where id=%s ",
			ltMsgGetVar_s(ltMsgPk,"name"),ltMsgGetVar_s(ltMsgPk,"mydesc"),
			ltMsgGetVar_s(ltMsgPk,"id"));		
			//printf("%s\n",sqlBuf);			
			ltDbExecSql(G_DbCon,sqlBuf); 
			ltMsgPk->msgpktype=1;
			lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/plain\n","lthtml",LT_TYPE_STRING,"0");
			ltMsgFree(ltMsgPk);
			return 0;
		}
	}
	return 0;
}
