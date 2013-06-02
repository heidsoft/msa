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
#include <iconv.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include "msa.h"

int ltqosdownlink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){

	ltDbHeadPtr dbPtr;
	ltTablePtr tablePtr;
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;
	char 				sqlBuf[1024];
	char        BANDDOWNLINK[24];
	char        myRate[24];
	int         mybrate;
	char        tmpDef[64],tempstr[64];
	int         qosid;

	if(_bcKernelHead->banddownlink<1 ||_bcKernelHead->banduplink<1 ){
		  char    BANDUPLINK[24];
			char    BANDDOWNLINK[24];
		  memset(BANDDOWNLINK,0,sizeof(BANDDOWNLINK));
		 	bcCnfGetValue_s("/etc/msa/msa/qos/settings","BANDDOWNLINK",BANDDOWNLINK);
	    memset(BANDUPLINK,0,sizeof(BANDUPLINK));
			bcCnfGetValue_s("/etc/msa/msa/qos/settings","BANDUPLINK",BANDUPLINK);
			if(strlen(BANDUPLINK)>0 && strlen(BANDDOWNLINK)>0 ){
				_bcKernelHead->banddownlink=atol(BANDDOWNLINK);
				_bcKernelHead->banduplink=atol(BANDUPLINK);
			}
		  if(_bcKernelHead->banddownlink<1 ||_bcKernelHead->banduplink<1 ){
					ltbandlink(confd,ltMsgPk,lt_MMHead);
					return 0;
		  }
	}
	qosid=0;
	if(ltMsgGetVar_s(ltMsgPk,"qosid")!=NULL){
		qosid=atol(ltMsgGetVar_s(ltMsgPk,"qosid"));
	}
	dbPtr=lt_dbinit();
	lt_db_htmlpage(dbPtr,"utf-8");

  if(qosid!=0){

		  sprintf(sqlBuf,"select sid,qosname,qosrated,qosrateu,qosmixu,prio,qosmixd from msaqos where sid=%d",qosid);

			tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor!=NULL){
				tempRow= ltDbFetchRow(tempCursor);
				if(tempRow!=NULL){
					lt_dbput_rootvars(dbPtr,1,"sid",tempRow[0]);
					lt_dbput_rootvars(dbPtr,1,"qosname",tempRow[1]);
				  lt_dbput_rootvars(dbPtr,1,"qosrated",tempRow[2]);
				  lt_dbput_rootvars(dbPtr,1,"qosrateu",tempRow[3]);

				  lt_dbput_rootvars(dbPtr,1,"qosmixd",tempRow[4]);
				  lt_dbput_rootvars(dbPtr,1,"qosmixu",tempRow[6]);
				  
					tempRow= ltDbFetchRow(tempCursor);
				}else{
				  lt_dbput_rootvars(dbPtr,1,"qosname","NewQos");
				  lt_dbput_rootvars(dbPtr,1,"qosrated","0");
				  lt_dbput_rootvars(dbPtr,1,"qosrateu","0");
				  lt_dbput_rootvars(dbPtr,1,"sid","0" );
				  lt_dbput_rootvars(dbPtr,1,"qosmixd","0");
	        lt_dbput_rootvars(dbPtr,1,"qosmixu","0");
			  }
				ltDbCloseCursor(tempCursor);
			}else{
				  lt_dbput_rootvars(dbPtr,1,"qosname","NewQos");
				  lt_dbput_rootvars(dbPtr,1,"qosrated","0");
				  lt_dbput_rootvars(dbPtr,1,"qosrateu","0");
				  lt_dbput_rootvars(dbPtr,1,"sid","0");
				  lt_dbput_rootvars(dbPtr,1,"qosmixd","0");
	        lt_dbput_rootvars(dbPtr,1,"qosmixu","0");
		 }
  }else{
	  lt_dbput_rootvars(dbPtr,1,"qosname","NewQos");
	  lt_dbput_rootvars(dbPtr,1,"qosrated","0");
	  lt_dbput_rootvars(dbPtr,1,"qosrateu","0");
	  lt_dbput_rootvars(dbPtr,1,"sid","0");
	  lt_dbput_rootvars(dbPtr,1,"qosmixd","0");
	  lt_dbput_rootvars(dbPtr,1,"qosmixu","0");
	}

  sprintf(BANDDOWNLINK,"%lu",_bcKernelHead->banddownlink);
  lt_dbput_rootvars(dbPtr,1,"DOWNLINK",BANDDOWNLINK);

  sprintf(BANDDOWNLINK,"%lu",_bcKernelHead->banduplink);
  lt_dbput_rootvars(dbPtr,1,"UPLINK",BANDDOWNLINK);


  tablePtr=lt_dbput_table(dbPtr,"dqoslist");
  sprintf(sqlBuf,"select sid,qosname from msaqos where sid>0 ");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){
			 sprintf(tmpDef,"%s",tempRow[1]);
			lt_dbput_recordvars(tablePtr,2,
				"dsid",LT_TYPE_STRING,tempRow[0],
				"dqosname",LT_TYPE_STRING,tmpDef);
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
	}


  mybrate=0;
  tablePtr=lt_dbput_table(dbPtr,"bqoslist");
  sprintf(sqlBuf,"select sid,qosname,qosmixd,qosrated from msaqos where sid>0 and qosmixd>0 ");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){

			mybrate=mybrate+atol(tempRow[2]);

			sprintf(myRate,"%d",(int)( (atol(tempRow[2])*100)/_bcKernelHead->banddownlink));
			
			memset(tempstr,0,sizeof(tempstr));
      strgb2utf8("����",tempstr,strlen("��֤"));
			lt_dbput_recordvars(tablePtr,5,
				"bqosname",LT_TYPE_STRING,tempRow[1],
				"bqosrated",LT_TYPE_STRING,tempRow[2],
				"brate",LT_TYPE_STRING,myRate,
				"bqosrateu",LT_TYPE_STRING,tempRow[3],
				"btype",LT_TYPE_STRING,tempstr);
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
	}
	if( _bcKernelHead->banddownlink>(mybrate+_bcKernelHead->banddowndef/1000)){
	   sprintf(myRate,"%lu", _bcKernelHead->banddownlink-mybrate );
	   lt_dbput_rootvars(dbPtr,1,"shareqos",myRate);
	   sprintf(myRate,"%d", (int)(((_bcKernelHead->banddownlink-mybrate)*100)/_bcKernelHead->banddownlink)  );
	   lt_dbput_rootvars(dbPtr,1,"sharerate",myRate);
  }else{
		 sprintf(myRate,"%d", _bcKernelHead->banddowndef/1000 );
		 lt_dbput_rootvars(dbPtr,1,"shareqos",myRate);
	   sprintf(myRate,"%d", (int)(((_bcKernelHead->banddowndef/1000)*100)/_bcKernelHead->banddownlink)  );
	   lt_dbput_rootvars(dbPtr,1,"sharerate",myRate);
	}





  tablePtr=lt_dbput_table(dbPtr,"sqoslist");
  sprintf(sqlBuf,"select sid,qosname,qosrated,qosrated from msaqos where sid>0 and qosmixd=0");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){


			sprintf(myRate,"%d",(int)((atol(tempRow[2])*100)/_bcKernelHead->banddownlink) );

			memset(tempstr,0,sizeof(tempstr));
      strgb2utf8("����",tempstr,strlen("����"));
			lt_dbput_recordvars(tablePtr,5,
				"sqosname",LT_TYPE_STRING,tempRow[1],
				"sqosrated",LT_TYPE_STRING,tempRow[2],
				"srate",LT_TYPE_STRING,myRate,
				"sqosrateu",LT_TYPE_STRING,tempRow[3],
				"stype",LT_TYPE_STRING,tempstr);
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
	}


	/*shangchuang*/


  mybrate=0;
  tablePtr=lt_dbput_table(dbPtr,"upbqoslist");
  sprintf(sqlBuf,"select sid,qosname,qosmixu,qosrateu from msaqos where sid>0 and qosmixu>0");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){

			mybrate=mybrate+atol(tempRow[2]);

			sprintf(myRate,"%d",(int)( (atol(tempRow[2])*100)/_bcKernelHead->banduplink) );
			
			memset(tempstr,0,sizeof(tempstr));
      strgb2utf8("��֤",tempstr,strlen("��֤"));
			lt_dbput_recordvars(tablePtr,5,
				"upbqosname",LT_TYPE_STRING,tempRow[1],
				"upbqosrated",LT_TYPE_STRING,tempRow[2],
				"upbrate",LT_TYPE_STRING,myRate,
				"upbqosrateu",LT_TYPE_STRING,tempRow[3],
				"upbtype",LT_TYPE_STRING,tempstr);
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
	}

	if( _bcKernelHead->banduplink >(mybrate+_bcKernelHead->bandupdef/1000)){
	   	sprintf(myRate,"%lu", _bcKernelHead->banduplink-mybrate );
	   	lt_dbput_rootvars(dbPtr,1,"upshareqos",myRate);
			sprintf(myRate,"%d", (int)(((_bcKernelHead->banduplink-mybrate)*100)/_bcKernelHead->banduplink)  );
			lt_dbput_rootvars(dbPtr,1,"upsharerate",myRate);
  }else{
		 sprintf(myRate,"%d", _bcKernelHead->bandupdef/1000 );
		 lt_dbput_rootvars(dbPtr,1,"upshareqos",myRate);
		 sprintf(myRate,"%d", (int)(((_bcKernelHead->bandupdef/1000)*100)/_bcKernelHead->banduplink)  );
		 lt_dbput_rootvars(dbPtr,1,"upsharerate",myRate);
	}






  tablePtr=lt_dbput_table(dbPtr,"upsqoslist");
  sprintf(sqlBuf,"select sid,qosname,qosrateu,qosrateu from msaqos where sid>0 and qosmixu=0 ");
	tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
	if(tempCursor!=NULL){
		tempRow= ltDbFetchRow(tempCursor);
		while(tempRow!=NULL){


			sprintf(myRate,"%d",(int)((atol(tempRow[2])*100)/_bcKernelHead->banduplink) );
			memset(tempstr,0,sizeof(tempstr));
      strgb2utf8("����",tempstr,strlen("����"));

			lt_dbput_recordvars(tablePtr,5,
				"upsqosname",LT_TYPE_STRING,tempRow[1],
				"upsqosrated",LT_TYPE_STRING,tempRow[2],
				"upsrate",LT_TYPE_STRING,myRate,
				"upsqosrateu",LT_TYPE_STRING,tempRow[3],
				"upstype",LT_TYPE_STRING,tempstr);
			tempRow= ltDbFetchRow(tempCursor);
		}
		ltDbCloseCursor(tempCursor);
	}

  lt_dbput_html(confd,ltMsgPk,dbPtr->doc,"/app/msa/msa/htmlplt/manager/bandconf.html",dbPtr->head,0);
	ltMsgFree(ltMsgPk);
	lt_dbfree(dbPtr);
	return 0;
}

int ltupdateqos(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){


	char 				sqlBuf[1024];
	char        *qosname;
	char        *qosrated;
	char        *prio;
	char        *qosmixd;
	char        *qosrateu;
	char        *qosmixu;
	long 				lCount;
	int         qosid;
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;

  qosid=atol(ltMsgGetVar_s(ltMsgPk,"qosid"));

  qosname=ltMsgGetVar_s(ltMsgPk,"qosname");
	if(qosname==NULL){
		qosname="";
	}

	qosrated=ltMsgGetVar_s(ltMsgPk,"qosrated");
	if(qosrated==NULL){
		qosrated="0";
	}

	prio=ltMsgGetVar_s(ltMsgPk,"prio");
	if(prio==NULL){
		prio="0";
	}

	qosmixd=ltMsgGetVar_s(ltMsgPk,"qosmixd");
	if(qosmixd==NULL){
		qosmixd="0";
	}

	qosrateu=ltMsgGetVar_s(ltMsgPk,"qosrateu");
	if(qosrateu==NULL){
		qosrateu="0";
	}

	qosmixu=ltMsgGetVar_s(ltMsgPk,"qosmixu");
	if(qosmixu==NULL){
		qosmixu="0";
	}
	if(ltStrIsDigital(qosrated)==0){
				ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
					"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >������ֵ���ԣ� </body></html>");
				return 0;
	}
	if(ltStrIsDigital(qosrateu)==0){
				ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
					"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >������ֵ���ԣ� </body></html>");
				return 0;
	}
	if(atol(qosrated)<2){
				ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
					"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >������ֵ̫�ͣ��������1K�� </body></html>");
				return 0;
	}
	if(atol(qosrateu)<2){
				ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
					"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >������ֵ̫�ͣ��������1K�� </body></html>");
				return 0;
	}

	if(qosid>0){


		sprintf(sqlBuf,"update msaqos set qosname='%s',qosrated=%s, qosrateu=%s, qosmixd=%s,qosmixu=%s,prio=%s where sid=%d",
			qosname,qosrated,qosrateu,qosmixd,qosmixu,prio,qosid);
		printf("%s  \n",sqlBuf);
	  ltDbExecSql(G_DbCon,sqlBuf);
		ltqosdownlink(confd,ltMsgPk,lt_MMHead);
	  return 0;
	}
	qosid=1;
	while(1){
			sprintf(sqlBuf,"select count(*) from msaqos where sid=%d ",qosid);
			lCount=0;
			tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
			if(tempCursor!=NULL){
							tempRow= ltDbFetchRow(tempCursor);
							if(tempRow!=NULL){
								lCount=atol(tempRow[0]);
							}
							ltDbCloseCursor(tempCursor);
			}
			if(lCount == 0) {
					break;
			}else{
		  		qosid++;
		  }
		  if(qosid>998){
		  	ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
					"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >ͨ������ϵͳ���ƣ� </body></html>");
				return 0;
		  }
	}


	sprintf(sqlBuf,"insert into msaqos values (%d,0,'%s',%s,%s,%s,%s,%s)",
			qosid,qosname,qosrated,qosrateu,qosmixd,qosmixu,prio);

	printf("sql;%s\n",sqlBuf);
	ltDbExecSql(G_DbCon,sqlBuf);

  ltqosdownlink(confd,ltMsgPk,lt_MMHead);
	return 0;
}





int lteditqos(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead){

	char 				sqlBuf[1024];
	int         qosid;
	char        *edittype;
	ltDbCursor *tempCursor;
	LT_DBROW tempRow;

	qosid=atol(ltMsgGetVar_s(ltMsgPk,"qosid"));
	edittype=ltMsgGetVar_s(ltMsgPk,"edittype");

	if(qosid==0){
		   ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
			"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >Error: this qos rule can't be chanage!</body></html>");
				ltMsgFree(ltMsgPk);

		    return 0;
	}

	if( strcmp(edittype,"setdef")==0){
	  ltqosdownlink(confd,ltMsgPk,lt_MMHead);
	  return 0;
	}else if( strcmp(edittype,"Del")==0){
		int lCount;
		lCount=0;
		sprintf(sqlBuf,"select count(*) from nassrvrule where qosid=%d ",qosid);
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
				if(tempCursor!=NULL){
						tempRow= ltDbFetchRow(tempCursor);
						if(tempRow!=NULL){
							lCount=atol(tempRow[0]);
						}
						ltDbCloseCursor(tempCursor);
				}
		if(lCount>0){
			 ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
			"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >����: ��ͨ���Ѿ�Ӧ���ڹ��򣬲���ɾ��!</body></html>");
				ltMsgFree(ltMsgPk);
		    return 0;
		}
		
		lCount=0;
		sprintf(sqlBuf,"select count(*) from msauserpolicy where ratelimit=%d ",qosid);
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
				if(tempCursor!=NULL){
						tempRow= ltDbFetchRow(tempCursor);
						if(tempRow!=NULL){
							lCount=atol(tempRow[0]);
						}
						ltDbCloseCursor(tempCursor);
				}
		if(lCount>0){
			 ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
			"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >����: ��ͨ���Ѿ�Ӧ�����������ԣ�����ɾ��!</body></html>");
				ltMsgFree(ltMsgPk);
		    return 0;
		}
		
		lCount=0;
		sprintf(sqlBuf,"select count(*) from msauser where ratelimit=%d ",qosid);
		tempCursor=ltDbOpenCursor(G_DbCon,sqlBuf);
				if(tempCursor!=NULL){
						tempRow= ltDbFetchRow(tempCursor);
						if(tempRow!=NULL){
							lCount=atol(tempRow[0]);
						}
						ltDbCloseCursor(tempCursor);
				}
		if(lCount>0){
			 ltMsgPk->msgpktype=1;
				lt_TcpResponse(confd,ltMsgPk,2,"lthead",LT_TYPE_STRING,"Content-type: text/html; charset=uft-8\n",
			"lthtml",LT_TYPE_STRING,"<html><body bgcolor=\"#cccccc\" >����: ��ͨ���Ѿ�Ӧ�����û�������ɾ��!</body></html>");
				ltMsgFree(ltMsgPk);
		    return 0;
		}
		
		sprintf(sqlBuf,"delete from msaqos where sid=%d ",qosid);
	  ltDbExecSql(G_DbCon,sqlBuf);
		ltqosdownlink(confd,ltMsgPk,lt_MMHead);
	  return 0;
	}else if( strcmp(edittype,"APP")==0){
			ltqosdownlink(confd,ltMsgPk,lt_MMHead);
			return 0;
	}


	if(_bcKernelHead->banddownlink<1){
		ltbandlink(confd,ltMsgPk,lt_MMHead);
		return 0;
	}

	ltqosdownlink(confd,ltMsgPk,lt_MMHead);
	return 0;


}
