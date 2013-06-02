/*update log*/
/*2003-11-09*/
/*nassrvrule  add   portstart   portend  prottype  */
/*nassrvruledip del portstart   portend */
/* nasmailfilter add rnum  maction */
/* nasmailrule add rnum */


create database nas;
grant all privileges on nas.*  to nas@localhost identified by 'naspass';

grant all privileges on nas.*  to uuu@172.16.0.92 identified by 'uuu';

drop table nasPortInfo;
create table nasPortInfo (
  id         int   primary key,       /* ��¼��ʶ     */	
	lPortStart int not null,
	lPortEnd   int not null,
	lFlag      int default 0, /* ��tcp�˿��Ƿ񱻼�¼  3��������� 2:��ز���¼  9������ 10 ��ֹ����*/
	lProp      int default 1, /* 1 tcp  2 udp */
	isLocal     int default 0  /*1 local 0 remote 2 both*/  
);

drop table nasNetArea;
create table nasNetArea (
    id           int       primary key,       /* ��¼��ʶ     */
    ipstart      char(16),                    /* ��ʼIP��ַ   */
    ipend        char(16),                    /* ��ֹIP��ַ   */
    netflag      smallint,      	     /* �����ʶ  1--����ip�ﶨ   2mac�ﶨ 3�����ﶨ 5NT����֤   8��������  9--���� 10��ֹ���� */
    ipdesp       char(64),
    snmpnum      int default 0
);

/*insert into nasNetArea values (1,'192.168.0.1','192.168.0.255',1);*/

drop table nasIpHostInfo;
create table nasIpHostInfo (
	lip       int primary key,
	ipadd     char(16),      /*ip��ַ*/
  netflag   smallint       /* �û�ӳ��󶨣�  1--����ip�ﶨ   2mac�ﶨ 5NT����֤   8��������  9--���� 10��ֹ���� */
);
create UNIQUE index nasIpHostInfo_index on nasIpHostInfo (lip);


/*���ڴ��Ӧ��ϵ*/
/*
1 Ĭ����ip��
2 nasIpHostInfo��ϵ�󶨣���˳��� 1 2 3 5 8 9
*/

/* ����Ϣ  */
drop table nasgroup;
create table nasgroup (
    groupid    int    primary key,
    groupname  varchar(48),
    grouphomeurl  varchar(128)
);
create UNIQUE index nasgroup_index on nasgroup (groupname);
insert into nasgroup (groupid,groupname) values (0,'Default-Dpt.');

drop table nasgroupip;
create table nasgroupip (
    groupid    int,
    lip       int(11) unsigned NOT NULL,
	  ipadd     char(16),      
	  lipend       int(11) unsigned NOT NULL,
	  ipaddend     char(16)     
);
//create UNIQUE index nasgroupip_index on nasgroupip (groupid);

drop table naspolicy;
create table naspolicy (
    pid     int  primary key ,   /*policy id*/
    pdesc   varchar(128) default "",  /*����*/
    pname   varchar(48) not null
);

insert into naspolicy (pid,pdesc,pname) values (0,'default policy','default-Policy');


/* �û���Ϣ  */
drop table nasuser;
create table nasuser (
    userid      int   primary key,
    username    varchar(32), /*�û���*/
    password    varchar(32),
    groupid     int default 0,
    dispname    varchar(32),  /*��ʾ������*/
    bindemail   varchar(128), /*�󶨵�email��ַ*/
    bindip      char(16), /*�󶨵�ip��ַ*/
    bindmac     char(32), /*�󶨵�mac��ַ*/
    useflags    smallint default 0,     /*10��ֹ���� 9���� 0����*/      
    ratelimit   int  default 0, /*��������*/
    ratelower   int  default 0, /*��������*/    
    addtime     char(16),     /*���û���Ч����*/
    lasttime    char(16),     /*�û����һ������ʱ��*/
    lAllUpFlow  bigint default 0, 	 /*�ܵ���������*/
    lAllDownFlow  bigint default 0, /*�ܵ���������*/
    lAllTime    int default 0,   /*�ܵ�����ʱ��*/
    lLimitBytes bigint default 0, /*ÿ��������������*/
    lLimitTimes int default 0, /*ÿ����������ʱ��*/
    macbindip   smallint default 0, /*����ip��ַ��mac��ַ����һ�²��ܷ���*/
    onlybindip  smallint default 0, /*�������û���֤��ʽ���û�ֻ���ڸ�ip��ַ���ܵ�½*/
    onlybindmac smallint default 0,/*�������û���֤��ʽ���û�ֻ���ڸ�mac��ַ���ܵ�½*/
    onlylogone  smallint default 0,  /*�������û���֤��ʽ���û�ͬʱֻ�ܵ�½һ��*/
    lCUpFlow    bigint default 0, 	 /*����������������*/
    lCDownFlow  bigint default 0, 	 /*����������������*/
    lCTime      int    default 0,        /*�������ӵļǷ�ʱ��*/
    policyid    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    jftype      int    default 0,  
    accountnum  int    default 0, 
    maxpackage  int    default 0, 
    maxBytes    bigint    default 0,
    formmon     int    default 1, 
    mailmon     int    default 1, 
    aimmon      int    default 1, 
    blockmon    int    default 1,
    policyid2    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid3    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid4    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid5    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid6    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid7    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid8    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid9    int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid10   int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid11   int    default 0, 	/*�û�Ĭ�ϵ�policyid*/
    policyid12   int    default 0,
    accountflag  int    default 0,   /*�û��Ʒ�ʱ��,0ȫ��ʱ��*/
    policyid13   int    default 0 ,  
		policyid14   int    default 0 ,  
		policyid15   int    default 0 ,   
		policyid16   int    default 0 ,  
		policyid17   int    default 0 ,  
		policyid18   int    default 0 ,  
		policyid19   int    default 0 ,  
		policyid20   int    default 0 ,   
		policyid21   int    default 0 ,  
		policyid22   int    default 0 ,   
		policyid23   int    default 0 ,   
		policyid24   int    default 0 ,   
		policyid25   int    default 0 ,   
		policyid26   int    default 0 ,   
		policyid27   int    default 0 ,   
		policyid28   int    default 0 ,   
		policyid29   int    default 0 ,   
		policyid30   int    default 0 ,   
		policyid31   int    default 0 ,   
		policyid32   int    default 0 ,   
		policyid33   int    default 0 ,   
		policyid34   int    default 0 ,   
		policyid35   int    default 0 ,   
		policyid36   int    default 0 ,   
		policyid37   int    default 0 ,   
		policyid38   int    default 0 ,   
		policyid39   int    default 0 ,   
		policyid40   int    default 0 ,   
		policyid41   int    default 0 ,   
		policyid42   int    default 0 ,   
		policyid43   int    default 0 ,   
		policyid44   int    default 0 ,   
		policyid45   int    default 0 ,   
		policyid46   int    default 0 ,   
		policyid47   int    default 0 ,   
		policyid48   int    default 0 ,   
		policyid49   int    default 0 ,   
		policyid50   int    default 0 ,   
		policyid51   int    default 0 ,   
		policyid52   int    default 0 ,   
		policyid53   int    default 0 ,   
		policyid54   int    default 0 ,   
		policyid55   int    default 0 ,   
		policyid56   int    default 0 ,   
		policyid57   int    default 0 ,   
		policyid58   int    default 0 ,   
		policyid59   int    default 0 ,   
		policyid60   int    default 0 ,   
		User_name         char(32)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Org_name          char(60)  default '',
		Country           char(20)  default '',
		Sex               char(10)  default '',
		moreflag          char(32)  default '0000000000',
		maxudp     int default 0,      /* ���udp���� */   
    maxtcp     int default 0,      /*  ���tcp����*/
    maxudpp    int default 0,      /*  ÿ�����udp������*/ 
    maxtcpp    int default 0,      /*  ÿ�����tcp������*/ 
    maxupp     int default 0,      /*  ÿ��up������*/ 
    maxdownp   int default 0,      /*  ÿ��down������*/  
    maxsp      int default 0,       /*  ÿ��128�ֽ�С������*/ 
    maxnc      int default 0,       /*  ÿ������½�������Ŀ*/ 
    userno     varchar(32) default '',        
    machientype varchar(32) default '',       
    scretlevel  varchar(32) default '',        
    measure     varchar(64) default '',       
    remark      varchar(64) default '', 
    post      varchar(32) default '',        
    place     varchar(64) default '',       
    purpose   varchar(32) default '' 
); 
 
/* moreflag  1 noftp 2 nopost 3 nomsn 4 noqq*/  
    
    
create UNIQUE index nasuser_index on nasuser (username);
    
create  index nasuser_index2 on nasuser (bindip);
create  index nasuser_index3 on nasuser (bindmac);
create  index nasuser_index4 on nasuser (groupid);
    
insert into nasuser (userid,username,password,groupid,dispname, 
bindemail,bindip,bindmac,macbindip,addtime,lasttime,useflags,ratelimit,lLimitBytes,lLimitTimes) 
values (1,'Unknown','','0','Unknown','','','',0,'','',10,0,0,0);
    
insert into nasuser (userid,username,password,groupid,dispname, 
bindemail,bindip,bindmac,macbindip,addtime,lasttime,useflags,ratelimit,lLimitBytes,lLimitTimes) 
values (2,'vpnadmin','qoQhDpRa4xOAwkBtuS0mq0','0','admin','','','',0,'','',1,0,0,0);

insert into nasuser (userid,username,password,groupid,dispname, 
bindemail,bindip,bindmac,macbindip,addtime,lasttime,useflags,ratelimit,lLimitBytes,lLimitTimes) 
values (3,'vpnadmin1','qoQhDpRa4xOAwkBtuS0mq0','0','vpnadmin1','','','',0,'','',1,0,0,0);

/* ϵͳschedule  */

drop table nasschedule;
create table nasschedule (
    schid      int   primary key,
    schname    varchar(24) not null, 
    schdesc    varchar(64) default '',
    schtime    char(200) default '0',
    schtime1    char(200) default '0'
);
insert into nasschedule values (1,"WorkDay","WorkDay","000000000000000000000000000000000111111111000000000000000111111111000000000000000111111111000000000000000111111111000000000000000111111111000000000000000000000000000000","000000000000000000000000000000000111111111000000000000000111111111000000000000000111111111000000000000000111111111000000000000000111111111000000000000000000000000000000"); 



/*
0ϵͳ���ࣺ�ֹ�����
0��δ֪����
1��������Э��  http https dns  httpproxy  sock5 ftp  LDAPĿ¼����  Microsoft SQL Server  Windows�ն˷��� SSH Telnet HTTP������
2: �ʼ���      smtp smtps pop3 pop3s
3: ��ý�壺    MMS��ý��  PNM��ý��
4: IM:         AOL|ICQ   ICQ��ʱͨ�� IRC���� MSN Messenger  QQ���� Yahoo Messenger 
5: P2P:        BT  emule  xulei  
6: ��Ϸ��
7�����������
8���������: 
9: 
*/
/*
          ����δ֪����  0  
 ��������Э��            
         
         webЭ��        2 
         ����webЭ��    3  
         Ŀ¼����֤     4  
         ���ݿ����     5       
         �ļ�����       
         			smb�ļ����� 6  
         			FTPЭ��     1     
         �ʼ�����       7
  
         Զ������       8   
   
         ����Э��       9  
   
         ��Ʊ���       10
    
         ��ý��         11
         
         ��ʱͨ��       12        
     
         ����绰       13
         
         [����P2pЭ��] 
	         BTЭ��         14
	         ��¿Э��       15
	         Ѹ��Э��       16
         
         ����P2P        17  
         
         ��Ϸƽ̨       18
         ������Ϸ       19
   
         [�����������]  
	         pplive         20
	         QQlive         21
	         PPStream       22
         
         �����������   23
         
     
         �Զ������     24  
         
         http��Ƶ��  25
         			
         http��Ƶ��  26 --flv
         
         http���������� 27
         
         http��������� 28
         
         80�˿ڵķǱ�׼http 29
         httpӦ����  30
*/
/*ϵͳ�ķ���*/
/* ϵͳ������Ϣ  */
drop table nasservice;
create table nasservice (
    srvid      int   primary key,    /*0 100 200 300.....*/
    srvname    varchar(24) not null, /*������*/
    srvdes     varchar(64) default '',
    srvflag    int default 0,     /*0ϵͳ������ɾ��  1���Խ�����*/      
    srvprot    int default 6,     /*Э�� 0��ʾ����  6 tcp    17 udp*/
    nportL     int default 0,     /*�˿����� */
    nPortU     int default 0,     /*�˿�����*/
    srvDirect  int default 0, 	  /*����0:out  1:in  2��˫��*/
    srvSort    int default 0 	    /*һ�����࣬��������� 0-99 */
);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (1,'AOL|ICQ','AOL|ICQ',0,6,5190,5190,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (2,'DNS��ѯ','������ѯ',0,17,53,53,0,2);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (3,'FTP����','FTPЭ��',0,6,21,21,0,1);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (4,'H.323��Ƶͨ��','H.323Э�� - ����Q.931/H.245/RTP/RTCP/T.120',0,6,1720,1720,0,13);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (5,'HTTP����','��������Э��',0,6,80,80,0,2);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (6,'HTTPS��������','���ܵ���������Э��',0,6,443,443,0,3);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (7,'SMB�ļ�����Э��','SMB�ļ�����Э��',0,17,445,445,2,6);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (8,'squid','squid',0,6,3128,3128,0,9);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (9,'IMAP4�ʼ�����','�����ʼ�����Э��',0,6,143,143,0,7);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (10,'VNCЭ��','VNCЭ��',0,6,5900,5900,0,8);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (11,'IRC����','��������',0,6,2,1,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (12,'LDAPĿ¼����','Lightweight Directory Access Protocol',0,6,389,389,0,4);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (13,'Microsoft SQL Server','Microsoft SQL Server protocol',0,6,1433,1433,0,5);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (14,'MMS��ý��','΢����ý��Э��',0,6,1755,1755,0,11);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (15,'�߷���Ϸƽ̨','�߷���Ϸƽ̨',0,6,5100,5100,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (16,'MSN Messenger','MSN messengerЭ��',0,6,1863,1863,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (17,'Net2Phone','Net2PhoneЭ��',0,17,6801,6801,0,13);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (18,'PNM��ý��','RealNetworks��ý��',0,6,7070,7070,0,11);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (19,'POP3���ʼ�','Post Office Protocol v.3',0,6,110,110,0,7);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (20,'kerberos','kerberos',0,6,88,88,0,4);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (21,'Windows�ն˷���','windown�ն˷���',0,6,3389,3389,0,8);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (22,'SMTP���ʼ�','Simple Mail Transfer Protocol (SMTP)',0,6,25,25,0,7);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (23,'SMTPS���ʼ�','Simple Mail Transfer Protocol',0,6,465,465,0,7);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (24,'SSH','���ܵ�Shell protocol',0,6,22,22,0,8);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (25,'Telnet','Telnet protocol',0,6,23,23,0,8);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (26,'ͬ��˳��������','ͬ��˳��������',0,6,8601,8601,0,10);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (27,'������Ϸ','������Ϸ',0,6,2000,2000,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (28,'QQ����','QQ����',0,17,2,1,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (29,'Yahoo Messenger','Yahoo Messenger',0,6,5050,5050,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (30,'������������','������������',0,17,8001,8001,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (31,'����������Ϸ','����������Ϸ',0,6,8011,8011,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (32,'�߷��Ĺ���Ϸ','�߷��Ĺ���Ϸ',0,6,4200,4200,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (33,'BTЭ��','BTЭ��',0,6,2,1,0,14);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (34,'HTTP������','��������Э��',0,6,80,80,1,2);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (35,'HTTPS������','���ܵ���������Э��',0,6,443,443,1,3);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (36,'POP3������','Post Office Protocol v.3',0,6,110,110,1,7);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (37,'SMTP������','Simple Mail Transfer Protocol (SMTP)',0,6,25,25,1,7);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (38,'eMuleЭ��','eMuleЭ��',0,6,2,1,0,15);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (39,'pplive','pplive',0,6,2,1,0,20);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (40,'QQlive','QQlive',0,6,2,1,0,21);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (41,'Taobao','Taobao',0,6,16000,16000,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (42,'Skype','Skype',0,6,2,1,0,12);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (43,'KaZaA','KaZaA',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (44,'Gnutella','Gnutella',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (45,'WinMX','WinMX',0,6,2,1,0,17);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (46,'���ǻ۹�������','���ǻ۹�������',0,6,22223,22223,0,10);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (47,'����3','����3',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (48,'Ѹ������','Ѹ������',0,6,2,1,0,16);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (49,'�Ʒ���սƽ̨','�Ʒ���սƽ̨',0,6,1201,1203,0,18);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (50,'Socks5����','Socks5',0,6,2,1,0,9);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (51,'HTTP����','HTTP����',0,6,2,1,0,9);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (52,'�߷�������','�߷�������',0,6,4310,4310,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (53,'�߷��й�����','�߷��й�����',0,6,4250,4250,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (54,'�߷���Ϸ����','�߷���Ϸ����',0,6,5005,5005,0,18);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (55,'�ٶ��°�','�ٶ��°�',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (56,'Ares','Ares',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (57,'SoulSeek','SoulSeek',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (58,'appleJuice','appleJuice',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (59,'DirectConnect','DirectConnect',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (60,'xdcc','xdcc',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (61,'waste','waste',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (62,'QQ��������','QQ��������',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (63,'PPStream','PPStream',0,6,2,1,0,22);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (64,'UUSee','UUSee',0,6,2,1,0,23);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (65,'�е��������','�е��������',0,6,2,1,0,23);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (66,'POCO','POCO',0,6,2,1,0,23);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (67,'QVOD','QVOD',0,6,2,1,0,23);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (68,'ƨƨ��','ƨƨ��',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (69,'totolook','totolook',0,6,2,1,0,17);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (70,'PP���ͨ,'PP���ͨ',0,6,2,1,0,17);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (71,'��������,'��������',0,6,2,1,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (72,'����UC,'����UC',0,6,2,1,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (73,'ָ����,'ָ����',0,6,2,1,0,10);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (74,'֤ȯ֮��,'֤ȯ֮��',0,6,2,1,0,10);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (75,'Ǯ��,'Ǯ��',0,6,9000,9000,0,10);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (76,'pcanywhere','pcanywhere',0,6,5631,5632,0,8);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (77,'mysql','mysql',0,6,3306,3306,0,5);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (78,'ORACLE','ORACLE',0,6,1521,1521,0,5);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (79,'sina��Ϸ','sina��Ϸ',0,6,2,1,0,15);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (80,'sohu��Ϸ','sohu��Ϸ',0,6,2,1,0,15);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (81,'QQ��Ϸ','QQ��Ϸ',0,6,2,1,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (82,'��Խ����','��Խ����',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (83,'���³�����ʿ','���³�����ʿ',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (84,'����2','����2',0,17,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (85,'�����⴫','�����⴫',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (86,'������Ե3','������Ե3',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (87,'��;','��;',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (88,'rayfile','rayfile',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (89,'���ܿ�����','���ܿ�����',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (90,'ħ������','ħ������',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (91,'������','������',0,6,2,1,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (92,'��Ѫ����','��Ѫ����',0,6,13000,13000,0,19);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (93,'ʢ����Ϸ','ʢ����Ϸ',0,6,2,1,0,18);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (94,'VS����ƽ̨','VS����ƽ̨',0,6,2,1,0,18);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (95,'GTalk|Jabber','GTalk|Jabber',0,6,5222,5222,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (96,'����','����',0,6,2,1,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (97,'UUCall','UUCall',0,6,2,1,0,13);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (98,'SIPЭ��','SIPЭ��',0,6,2,1,0,13);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (99,'RTP/RTCP����','RTP/RTCP',0,6,2,1,0,13);


insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (100,'http��Ƶ��','http��Ƶ��',0,6,2,1,0,25);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (101,'http��Ƶ��','http��Ƶ��',0,6,2,1,0,26);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (102,'http��FLash��','http��FLash��',0,6,2,1,0,26);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (103,'http����������','http����������',0,6,2,1,0,27);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (104,'http���������','http���������',0,6,2,1,0,28);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (105,'httpӦ�û��ļ���','httpӦ�û��ļ���',0,6,2,1,0,30);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (106,'�Ǳ�׼http��','�Ǳ�׼http��',0,6,2,1,0,29);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (107,'MSN-httpproxy','MSN-httpproxy',0,6,2,1,0,12);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (108,'FTP������','FTP������',0,6,2,1,0,1);

insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (109,'��ͨί�н���,'��ͨί�н���',0,6,2,1,0,10);
insert into nasservice (srvid,srvname,srvdes,srvflag,srvprot,nportL,nPortU,srvDirect,srvSort) values (110,'��֤ͨȯ���','��֤ͨȯ���',0,6,2,1,0,10);


/*������ƹ���*/
drop table nassrvrule;
create table nassrvrule (
    ruleid     int ,   /*����id*/
    ruletype   smallint default 0,  /*3��Ӧ�����û��� 1:Ӧ�����û���  2policy 4 Ӧ����ip��ַ�Σ�   0-4��Ӧ����ȫϵͳ*/
    ruledtype  smallint default 0,  /* �ù����Ŀ���ַ����  0��ȫ����ַ  1����ַ��*/  
    ruleflag   smallint default 1,  /*0������  1������*/
    ruleaction smallint default 0,  /*1����    0���ܾ� */
    ruleschedule  int   default 0,  /*0 ȫ��ʱ��  ������schedule�в���*/
    rulesrv       int   default 0,  /*0 ���з��� 1��srvrulesrv�в��� 2�Զ���*/
    rulename   varchar(32) not null,
    pid        int   default 0,   /*������*/
    portstart  int default 0,   /*��*/
    portend    int default 0,   /*����*/
    prottype   int default 6 ,   /*6 tcp 17 udp*/
    qosid      int default 0 ,   /*qosid 0��cid*/
    logaction  int default 1 ,   /*��¼ƥ�������*/
    conaction  int default 1 ,   /*��¼ƥ�������*/
    ruleurlsort char(100)  default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000', /*100��URL����*/
    rulejr     varchar(365) default '0',
    rulerate   int default 0,    /*rate���ȼ���*/
    ruleurl    char(128)
);


/*������ƹ���ķ�����*/
drop table nassrvrulesrv;
create table nassrvrulesrv (
    ruleid     int ,   /*����id*/
    srvid     int     /*�����id 0����������*/
);

/*������ƹ������Ŀ��ip�εĲ���*/
drop table nassrvruledip;
create table nassrvruledip (
    ruleid     int ,   /*����id*/
    ipstart    char(20),   /*ip�ο�ʼ��ַ*/
    ipend      char(20)   /*ip�ν�����ַ*/
);

/*������ƹ�������û��Ĳ���*/
drop table nasruleuser;
create table nasruleuser (
    ruleid     int ,   /*����id*/
    userid     int     /*�û���id */
);

/*������ƹ�������û��Ĳ���*/
drop table nasrulegroup;
create table nasrulegroup (
    ruleid     int ,   /*����id*/
    groupid     int     /*�û����id */
);


/*������ƹ������ip�εĲ���*/
drop table nasruleip;
create table nasruleip (
    ruleid     int ,   /*����id*/
    ipstart    char(20),   /*ip�ο�ʼ��ַ*/
    ipend      char(20)    /*ip�ν�����ַ*/
);




/*web���ƹ����url*/
drop table nasruleurl;
create table nasruleurl (
    ruleid     int ,   /*����id*/
    caUrl      varchar(64)   /*url�б�*/
);

/*web���ƹ����type*/
drop table nasruletype;
create table nasruletype (
    ruleid     int ,   /*����id*/
    caUrl      varchar(64)   /*url�б�*/
);

/*webpost���ƹ����type*/
drop table nasruleposturl;
create table nasruleposturl (
    ruleid     int ,   /*����id*/
    caUrl      varchar(64)   /*url�б�*/
);



drop table nasurlsort;
CREATE TABLE nasurlsort (
  sortid int(11) NOT NULL default '0',
  sorname varchar(40) NOT NULL default '',
  sortdesc varchar(100) default ''
) ;

/*
����ɫ��
Υ����վ


���й�˾  ���� ��ѧ  ��Ʊ  ����  BT  ����  ���� 
����  ����  ����  FLASH  ����  ����  ���� ��ͨ 
���� manwoman ����  ��̳ ���� ���� ����  ��Ƶ 
ʱ�� ���� ͼ�� ��Ц ���� Ӱ�� ��ʳ ���� ��Ϸ
���� IT  ���� ���� ��װ  ���� ���� ���� ���� 
���� �ֻ� ͼƬ ��Ƹ�˲� �ڿ� ���� ������ ���� 
��վ 
*/



INSERT INTO nasurlsort VALUES (1,'���ﱩ��','���ﱩ��');
INSERT INTO nasurlsort VALUES (2,'����������','����������');
INSERT INTO nasurlsort VALUES (3,'ɫ����վ','ɫ����վ');
INSERT INTO nasurlsort VALUES (4,'�����¶','�����¶');
INSERT INTO nasurlsort VALUES (5,'������ƽ�','������ƽ�');
INSERT INTO nasurlsort VALUES (6,'ǹ֧����','ǹ֧����');
INSERT INTO nasurlsort VALUES (7,'�����������վ','�����������վ');
INSERT INTO nasurlsort VALUES (8,'��Ⱦ����','��Ⱦ����');
INSERT INTO nasurlsort VALUES (9,'����������','����������');
INSERT INTO nasurlsort VALUES (10,'������վ','������վ');
INSERT INTO nasurlsort VALUES (11,'�ڽ�','�ڽ�');
INSERT INTO nasurlsort VALUES (12,'����','����');
INSERT INTO nasurlsort VALUES (13,'����','����');
INSERT INTO nasurlsort VALUES (14,'����','����');
INSERT INTO nasurlsort VALUES (15,'����','����');
INSERT INTO nasurlsort VALUES (16,'����','����');
INSERT INTO nasurlsort VALUES (17,'����','����');
INSERT INTO nasurlsort VALUES (18,'��ͨ','��ͨ');
INSERT INTO nasurlsort VALUES (19,'����','����');
INSERT INTO nasurlsort VALUES (20,'������֪����˾','������֪����˾');
INSERT INTO nasurlsort VALUES (21,'����','����');
INSERT INTO nasurlsort VALUES (22,'����','����');
INSERT INTO nasurlsort VALUES (23,'����','����');
INSERT INTO nasurlsort VALUES (24,'�˲�ְλ','�˲�ְλ');
INSERT INTO nasurlsort VALUES (25,'BT��վ','BT��վ');
INSERT INTO nasurlsort VALUES (26,'IT�ۺ���վ','IT�ۺ���վ');
INSERT INTO nasurlsort VALUES (27,'�ڿ��밲ȫ����','�ڿ��밲ȫ����');
INSERT INTO nasurlsort VALUES (28,'�������������վ','�������������վ');
INSERT INTO nasurlsort VALUES (29,'����վ��','����վ��');
INSERT INTO nasurlsort VALUES (30,'���������','���������');
INSERT INTO nasurlsort VALUES (31,'����','����');
INSERT INTO nasurlsort VALUES (32,'����','����');
INSERT INTO nasurlsort VALUES (33,'ý����վ','ý����վ');
INSERT INTO nasurlsort VALUES (34,'����㲥����','����㲥����');
INSERT INTO nasurlsort VALUES (35,'���ϵ绰','���ϵ绰');
INSERT INTO nasurlsort VALUES (36,'����','����');
INSERT INTO nasurlsort VALUES (37,'�ֻ�','�ֻ�');
INSERT INTO nasurlsort VALUES (38,'��װ','��װ');
INSERT INTO nasurlsort VALUES (39,'����','����');
INSERT INTO nasurlsort VALUES (40,'��Ϸ','��Ϸ');
INSERT INTO nasurlsort VALUES (41,'����','����');
INSERT INTO nasurlsort VALUES (42,'����','����');
INSERT INTO nasurlsort VALUES (43,'Ӱ��','Ӱ��');
INSERT INTO nasurlsort VALUES (44,'����','����');

INSERT INTO nasurlsort VALUES (45,'����','����');
INSERT INTO nasurlsort VALUES (46,'��ʳ','��ʳ');
INSERT INTO nasurlsort VALUES (47,'��ѧ','��ѧ');
INSERT INTO nasurlsort VALUES (48,'ͼ��','ͼ��');
INSERT INTO nasurlsort VALUES (49,'ͼƬ','ͼƬ');
INSERT INTO nasurlsort VALUES (50,'ʱ��','ʱ��');
INSERT INTO nasurlsort VALUES (51,'Flash','Flash');
INSERT INTO nasurlsort VALUES (52,'����Ƶ��','����Ƶ��');
INSERT INTO nasurlsort VALUES (53,'����','����');

INSERT INTO nasurlsort VALUES (54,'��̳','��̳');
INSERT INTO nasurlsort VALUES (55,'����','����');
INSERT INTO nasurlsort VALUES (56,'ͬѧ¼','ͬѧ¼');
INSERT INTO nasurlsort VALUES (57,'����','����');
INSERT INTO nasurlsort VALUES (58,'��Ʊ','��Ʊ');
INSERT INTO nasurlsort VALUES (59,'����','����');
INSERT INTO nasurlsort VALUES (60,'����','����');
INSERT INTO nasurlsort VALUES (61,'��Ц','��Ц');
INSERT INTO nasurlsort VALUES (62,'������Ů','������Ů');

INSERT INTO nasurlsort VALUES (63,'����Ȧ','����Ȧ');
INSERT INTO nasurlsort VALUES (64,'ģ��','ģ��');
INSERT INTO nasurlsort VALUES (65,'����','����');
INSERT INTO nasurlsort VALUES (66,'֤ȯ�������վ','֤ȯ�������վ');
INSERT INTO nasurlsort VALUES (67,'���չ�˾','���չ�˾');
INSERT INTO nasurlsort VALUES (68,'���ز�','���ز�');
INSERT INTO nasurlsort VALUES (69,'������','������');
INSERT INTO nasurlsort VALUES (70,'�������','�������');


INSERT INTO nasurlsort VALUES (71,'�Զ������1','�Զ������1');
INSERT INTO nasurlsort VALUES (72,'�Զ������2','�Զ������2');
INSERT INTO nasurlsort VALUES (73,'�Զ������3','�Զ������3');
INSERT INTO nasurlsort VALUES (74,'�Զ������4','�Զ������4');
INSERT INTO nasurlsort VALUES (75,'�Զ������5','�Զ������5');
INSERT INTO nasurlsort VALUES (76,'�Զ������6','�Զ������6');
INSERT INTO nasurlsort VALUES (77,'�Զ������7','�Զ������7');
INSERT INTO nasurlsort VALUES (78,'�Զ������8','�Զ������8');



/*������ַ*/
drop table nasurls;
create table nasurls (
	urlsort int not null,
	url     varchar(36) 
);



/*http���ʼ�¼*/

drop table nashttplog;
create table nashttplog (
    userid      int,    
    sdate       char(10),
    stime       char(8), 
    conntime    int(10), 
    sip         char(16),
    host        varchar(64),
    uri         varchar(128),
    bytes       bigint,         
    flags       smallint,
    dip         char(16) default '',    
    keyword     char(48) default ''   
);

create index nashttplog_index1 on nashttplog (userid);
create index nashttplog_index2 on nashttplog (sdate);
create index nashttplog_index5 on nashttplog (stime);
create index nashttplog_index3 on nashttplog (sip);
create index nashttplog_index4 on nashttplog (bytes);
create index nashttplog_index6 on nashttplog (dip);


/*http���ʼ�¼*/

drop table nashttpblocklog;
create table nashttpblocklog (
    userid      int,    
    sdate       char(10),
    stime       char(8), 
    sip         char(16),
    dip         char(16) default '',  
    host        varchar(64),
    uri         varchar(128),
    sortid      char(6) default '00000'     
);

create index nashttpblocklog_index1 on nashttpblocklog (userid);
create index nashttpblocklog_index2 on nashttpblocklog (sdate);
create index nashttpblocklog_index3 on nashttpblocklog (sip);
create index nashttpblocklog_index4 on nashttpblocklog (sortid);


/* IP���ʼ�¼  */
drop table nasiplog;
create table nasiplog (
    userid      int,          /* �û���     */
    sdate       char(10),     /* ��ʼʱ��   */
    stime       char(8),      /* ��ʼʱ��   */
    conntime    int default 0,          /* ����ʱ��   */
    sip         char(16) default '',  /* ԴIP       */
    dip         char(16) default '',  /* Ŀ��IP     */
    trantype    smallint default 6,     /* Э�� 6:tcp */
    port        int default 0,          /* �˿ں�     */
    service     smallint default 0,     /* ��������   */
    ubytes      bigint default 0,          /* �����ֽ��� */
    dbytes      bigint default 0,          /* �����ֽ��� */
    flags       smallint default 0,      /* ��¼������� 0--�� 1--ͳ��  */
    localport   int default 0,          /* ���ض˿ں�     */
    trandirect  smallint  default 0,     /*���䷽��*/
    keyword1    varchar(64) default '',
    keyword2    varchar(128) default '',
    keyword3    varchar(48) default '',
    keyword4    int default 0, 
		logid       char(24)  default '',
);

create index nasiplog_index1 on nasiplog (userid);
create index nasiplog_index2 on nasiplog (sdate);
create index nasiplog_index3 on nasiplog (sip);
create index nasiplog_index4 on nasiplog (stime);
create index nasiplog_index5 on nasiplog (dip);
create index nasiplog_index6 on nasiplog (service);
create index nasiplog_index7 on nasiplog (ubytes);
create index nasiplog_index8 on nasiplog (dbytes);


/* IP���ʼ�¼  */
drop table nasipblocklog;
create table nasipblocklog (
    userid      int,          /* �û���     */
    sdate       char(10),     /* ��ʼʱ��   */
    stime       char(8),      /* ��ʼʱ��   */
    sip         char(16) default '',  /* ԴIP*/
    dip         char(16) default '',  /* Ŀ��IP*/
    trantype    smallint default 6,     /* Э�� 6:tcp */
    port        int default 0,          /* �˿ں�     */
    service     smallint default 0,     /* ��������   */
    localport   int default 0,          /* ���ض˿ں�*/
    trandirect  smallint  default 0     /*���䷽��*/
);

create index nasipblocklog_index1 on nasipblocklog (userid);
create index nasipblocklog_index2 on nasipblocklog (sdate);
create index nasipblocklog_index3 on nasipblocklog (sip);


/* ��ص��ʼ����� */
drop table nasmaillog;
create table nasmaillog (
    sid        int      auto_increment  primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(128),        /* �ʼ��ļ���      */
    mailfrom   char(128),       /* ������          */
    mailto     char(128),       /* �ռ���          */
    mailsub    char(128),       /* ����            */
    mailasize  bigint,          /* ����            */
    mailsize   bigint,          /* �ʼ���С ����   */
    flags      int,             /* �ʼ�״̬ 0--����  1--����  2��*/
    mtype      char(64),         /* �ʼ�����        */
    rback      int  default 0,
    dip        char(24) default '0.0.0.0'
);

create index nasmaillog_ind0 on nasmaillog (sid);
create index nasmaillog_ind1 on nasmaillog (userid);
create index nasmaillog_ind2 on nasmaillog (sdate);


drop table nasformlog;
create table nasformlog (
    sid        int      auto_increment  primary key,
    userid     int,
    sdate      varchar(24),
    mailfile   varchar(128),        /* �ʼ��ļ���      */
    mailfrom   varchar(128),       /* ������          */
    mailto     varchar(128),       /* �ռ���          */
    mailsub    varchar(128),       /* ����            */
    mailasize  bigint,          /* ����            */
    mailsize   bigint,          /* �ʼ���С ����   */
    flags      int,             /* �ʼ�״̬ 0--����  1--����  2��*/
    mtype      varchar(64),         /* �ʼ�����        */
    rback      int  default 0,
    dip        char(24) default '0.0.0.0',
    mac        char(13) default ''
);

create index nasformlog_ind0 on nasmaillog (sid);
create index nasformlog_ind1 on nasmaillog (userid);
create index nasformlog_ind2 on nasmaillog (sdate);


/* ��ص��ʼ����� */
drop table nasformlog;
create table nasformlog (
    sid        int      auto_increment  primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(64),        /* �ʼ��ļ���      */
    mailfrom   char(128),       /* ������          */
    mailto     char(128),       /* �ռ���          */
    mailsub    char(128),       /* ����            */
    mailasize  bigint,          /* ����            */
    mailsize   bigint,          /* �ʼ���С ����   */
    flags      int,             /* �ʼ�״̬ 0--����  1--����  2��*/
    mtype      char(64),         /* �ʼ�����        */
    rback      int  default 0,
    dip        char(24) default '0.0.0.0'
);

create index nasformlog_ind0 on nasformlog (sid);
create index nasformlog_ind1 on nasformlog (userid);
create index nasformlog_ind2 on nasformlog (sdate);
create index nasformlog_ind3 on nasformlog (flags);




/* �ʼ���ع�������  */
drop table nasmailrule;
create table nasmailrule (  
    rid        int,             /* ����ID          */
    num        int,             /* ִ�����        */
    rname      varchar(63) not null,     /* ��������        */
    mailfrom   varchar(63) default '',     /* ������          */
    mailto     varchar(63)  default '',     /* �ռ���          */
    mailsub    varchar(63)  default '',     /* ����            */
    mailcont   varchar(63)  default '',     /* ����            */
    mailsize   int default 0,    /* �ʼ���С ����   */
    attname    varchar(63)  default '',     /* ��������        */
    attsize    int default 0,   /* ������С ����   */
    flags      smallint default 0,   /* ��� 0:��������  1:�ܾ����� 2�ȴ���� 3ת��*/
    mail      varchar(63)   default '',    /* ת������        */
    sflags     smallint default 0,   /* ֪ͨ��ʽ 0--��֪ͨ  1--֪ͨ������  2--ָ֪ͨ������  */
    smail      varchar(63)   default '',    /* ָ������       */
    rnum       int   default 0         /*�ռ�����Ŀ*/
);

/* ��ص��ʼ����� */
drop table nasmailauth;
create table nasmailauth (
    sid        int      auto_increment  primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(64),        /* �ʼ��ļ���      */
    intdfile   char(64),        /* �ʼ�ͷ�ļ���      */
    mailfrom   char(128),       /* ������          */
    mailto     char(128),       /* �ռ���          */
    mailsub    char(128),       /* ����            */
    mailasize  bigint,          /* ����            */
    mailsize   bigint,          /* �ʼ���С ����   */
    mtype      char(64)         /* �ʼ�����        */
);
create index nasmailauth_ind1 on nasmailauth (userid);
create index nasmailauth_ind2 on nasmailauth (sdate);


drop table nasdenyuser;
create table nasdenyuser (
    userid     int
);
create index nasdenyuser_ind1 on nasdenyuser (userid);

drop table nasauthuser;
create table nasauthuser (
    userid     int
);
create index nasauthuser_ind1 on nasauthuser (userid);

drop table nasnoauthuser;
create table nasnoauthuser (
    userid     int
);
create index nasnoauthuser_ind1 on nasnoauthuser (userid);

/* ����Ա��Ϣ    */
drop table nasadmuser;
create table nasadmuser (
    name       varchar(32)   primary key,   /* �û���   */
    password   varchar(32),                 /* ����md5(name,password)  */
    lright     varchar(128),               /* Ȩ��  right--> lrightϵͳĿǰ��5��Ȩ�� 123456   */
    email      varchar(64),                 /* ת��E-Mail              */
    lasttime   int,                         /* ���һ�η���ʱ��        */
    allgroup   int,                          /* ���ֲ��� -1 ���в���*/
    bindip  char(32) default '',
    grouplist1 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist2 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist3 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist4 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist5 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
);

insert into nasadmuser values('admin','qoQhDpRa4xOAwkBtuS0mq0','1111111111111111111111111111','',0,999999);

/*update nasadmuser set password='qoQhDpRa4xOAwkBtuS0mq0';*/

/*insert into nasadmuser values('xxxxx','qoQhDpRa4xOAwkBtuS0mq0','1111111111111111111111111111','',0,999999);*/

alter table nasadmuser add verifyCode   char(64)  default '';
alter table nasadmuser add verifyCode   char(64)  default '';
alter table nasadmuser add verifyCode   char(64)  default '';
alter table nasadmuser add verifyCode   char(64)  default '';



/* ��������������¼*/

drop table nasflowlog;
create table nasflowlog (
    rtime       int, 
    smin        int,             
    sdate       char(10),       
    stime       char(8),        
    ubytes      bigint,            
    dbytes      bigint,   
    dev         char(12) default '', 
    httpnum     int default 0, 
    tcpnum      int default 0,
    udpnum      int default 0,
    usernum     int default 0,        
    flags       smallint default 0
);

create index nasflowlog_in1 on nasflowlog (sdate);
create index nasflowlog_in2 on nasflowlog (rtime);


/* IPͳ������  */
drop table nasipreport;
create table nasipreport (
    userid	    int,                  /* �û�ID */
    sdate       char(10),              /* ����   */
    stime       char(2),               /* ʱ��   */
    ip          char(16),              /* IP��ַ */
    ubytes      bigint,                   /* ��������  */
    dbytes      bigint,                   /* ��������  */
    ctime       int                       /* ����ʱ��  */
);

create index nasipreport_index1 on nasipreport (userid);
create index nasipreport_index2 on nasipreport (sdate);
create index nasipreport_index3 on nasipreport (stime);

drop table nassrvreport;
create table nassrvreport (
    userid	    int,                   /* �û�ID */
    sdate       char(10),              /* ����      */
    stime       char(2),               /* ʱ��      */
    service     int,                   /* �������  */
    ubytes      bigint,                /* ��������  */
    dbytes      bigint,                /* ��������  */
    ctime       int,                   /* ���Ӵ���  */
    onlinetime  int default 0          /* ����ʱ��  */
);
create index nassrvreport_index0 on nassrvreport (userid);
create index nassrvreport_index1 on nassrvreport (sdate);
create index nassrvreport_index2 on nassrvreport (stime);

drop table nassrvdreport;
create table nassrvdreport (
    sdate       char(10),              /* ����      */
    stime       char(2),               /* ʱ��      */
    port        int,                   /* �������  */
    trantype    int,                   /* ��������  */
    ubytes      bigint,                /* ��������  */
    dbytes      bigint,                /* ��������  */
    ctime       int                    /* ���Ӵ���  */
);

create index nassrvdreport_index1 on nassrvdreport (sdate);
create index nassrvdreport_index2 on nassrvdreport (stime);



drop table nashttpreport;
create table nashttpreport (
    userid      int,                /* �û�ID  */
    sdate       char(10),           /* ����      */
    stime       char(2),            /* ʱ��      */
    host        varchar(64),        /* ��ַ      */
    bytes       bigint default 0,             /* ����      */
    lcount      int default 0,             /* �������  */
    ctime       int default 0,                 /* ����ʱ��  */
    urlsort     char(6) default '0000'
);

create index nashttpreport_index1 on nashttpreport (userid);
create index nashttpreport_index2 on nashttpreport (sdate);



drop table nasfirewall;
create table nasfirewall (
    fid	        int,                /* ID    */
    fflag       int,		    /*1:���� 0��������*/	
    fnumber     int,        	    /* ���  */
    fname       varchar(30),        /* ����  */
    fdesc       varchar(64),        /* ����  */
    faction     int default 0,      /*0:deny 1:allow*/
    fchains     int,          	    /* 0input 1output 2forward */
    ffragment     int  default 0,   /* Ӧ���� 1:fragment��Ƭ 0:all package -1:����Ƭ��  */
    fstate        char(10) default '1111', /* Ӧ���� 1111:����״̬ 1234new established related invlaid */
    finputdev     char(20)  default '+',   /*�����豸 + eth0 !eth0.....*/
    foutputdev    char(20) default '+',    /*�����豸 + eth0 !eth0.....*/
    fprotocol     int default 0,	   /* ����:�Զ�, 1:icmp  6:tcp 17:udp 0:all*/
    flport        char(30) default '0',      /*local port  0:all 1:fixwd -1:!fixed*/
    frport        char(30) default '0',      /*remote port  0:all 1:fixwd -1:!fixed*/
    ficmptype     int,			     /*-1:all */
    ficmpcode     int,			     /*-1:all */
    ftcpsyn       int   default 0,         /*0:all 1:tcp����� -1:!syn*/
    fladd         char(50) default '0/0',  /*0/0:any*/
    fradd         char(50) default '0/0'   /*0/0:any*/
);

/* ����Ա��Ϣ    */
drop table nasdbuser;
create table nasdbuser (
    name      varchar(32)   primary key,   /* �û���   */
    password  varchar(32),                 /* ����md5(name,password)  */
    ip     varchar(24)              /* ��½��IP */
);

drop table nasuseraccount;
create table nasuseraccount (
    userid    int   ,   	/*ʱ��   */
    sdate     char(10), 
    flow      bigint,
    time      int,
    account   int,
    accountflag  int default 1  /*1 �Ʒ�ʱ��  0�ǼƷ�ʱ��*/
);



drop table nasclientinfo;
create table nasclientinfo (
    gnmkey         char(32)  primary key,   /*�û�key */
    Service_code   char(32)  default '',   /*�û�id */
    Service_name   char(128) default '', 
    Address        char(128) default '',
    Zip            char(32) default '',
    Principal      char(64) default '',     /*������*/    
    Principal_id   char(32) default '',		  /*���������֤*/       
    Principal_tel  char(32) default '',     /*�����˵绰*/
    Principal_email char(32) default '',		  /*������email*/
    yingyearea     int  default 0,		      /*Ӫҵ���*/
    Practitioner_number      int  default 0,		      /*��ҵ����*/
    Ending_number  int  default 0,		      /*������Ŀ*/
    Server_number  int  default 0,		      /*������Ŀ*/
    Infor_man      char(64) default '', 	  /* ��ȫ��*/
    Infor_man_tel  char(64) default '',  	  /*��ȫ�˵绰*/
    Infor_man_id   char(64) default '',		  /*��ȫ�����֤*/
    Infor_man_email   char(64) default '',		  /*��ȫ��email*/   		
    Ip             char(64) default '',		
    Net_type       char(32) default '',	    /*������ʽ*/   
    clienttype     char(32) default '',     /*�ն����� 0δ֪ 1���� 2���� 3��ҵ��λ 4��ҵ��λ 5�������� */
    producer_code  char(32) default '',     /*������Ӫ�̴���*/ 
    Status         char(24) default '1',     /*�ն�״̬*/ 
    Net_monitor_department char(64) default '',
    Net_monitor_man        char(64) default '',     
    Net_monitor_man_tel    char(64) default '',
    usernum        int  default 0,
    startday       char(64) default '',
    endday         char(64) default '',
    lasttime       char(64) default '',
    lastappupdatev int default 0,        
    lasturlupdatev int default 0,         
    updateflag   int  default 0,            /*�Ƿ�������������*/
    lastappeupdate char(64)  default '',     
    lasturleupdate char(64)  default '',
    intervalfig    int default 3600,         /*ͬ������ͨ��ʱ������״̬��*/
    cmdupdateflag  int  default 0,           /*�Ƿ�������*/
    cmdurl         char(128) default '',     /*�����ŵ��ļ�*/
    alarmlog       char(8) default 'N',      /*�ϱ�������־*/
    tdulog         char(8) default 'N',      /*�ϱ����������߼�¼*/
    onlinelog      char(8) default 'N',      /*�ϱ������ؼ�¼*/
    realidentity   char(8) default 'N',      /*�ϱ���ʵ��ݼ�¼*/
    virtualidentity  char(8) default 'N',    /*�ϱ�������ݼ�¼*/
    daystat        char(8) default 'N',      /*�ϱ���ͳ�Ƽ�¼*/ 
    onlinehost     int default 0,
    registname     char(64) default '',
    registuser     char(64) default '',
    registadd      char(128) default '',
    registtel      char(64) default '',
    registmail     char(64) default '',
    Remark         char(254) default '',
    registtime     char(32) default '',
    sessionid      char(32) default '',
    newsystem      char(4) default '1',
    UnitNo         int default 0,
    uploadtype     int default 0,  /*0-1  0��ʱ 1��ʱ*/
    uploadtimeval  int default 3600  /*�ϴ�ʱ����*/
    uploadcmd      char(64) default '',  /*ָ��: Ŀǰ����֧��ip*/
    myService_code   char(32)  default '',
    verifyCode   char(64)  default ''
);
create index nasclientinfo_index1 on nasclientinfo(gnmkey);
create index nasclientinfo_index2 on nasclientinfo(Service_code);


/*insert into nasclientinfo (gnmkey,clientid,clientname,clientadd,zherenren,zherenrenid    
zherenrentel,zherenrenemail,yingyearea,congyenum,termnum,secname,sectel,secid,secemail,
iplist,connecttype,clienttype,producer_code,clientstatus,usernum,startday,endday,lasttime,
lastappupdatev,lasturlupdatev,updateflag,lastappeupdate,lasturleupdate,intervalfig,cmdupdateflag,
cmdurl,alarmlog,tdulog,onlinelog,realidentity,virtualidentity,daystat,onlinehost)
values ('1234-1234-1234-1234','41010110000001','TEST','','','','','','','',100,'','','','',
'','DDN','','','',100,'','','','','','0','','',120,0,'','N','N','N','N','N','N',0,'','','','','');

alter table nasclientinfo add   registname     char(64) default '';
alter table nasclientinfo add   registuser     char(64) default '';
alter table nasclientinfo add   registadd      char(128) default '';
alter table nasclientinfo add   registtel      char(64) default '';
alter table nasclientinfo add   registmail     char(64) default '';

alter table nasclientinfo add   registtime     char(32) default '';
alter table nasclientinfo add   sessionid      char(32) default '';
alter table nasclientinfo add   newsystem      char(4) default '1';
alter table nasclientinfo add   UnitNo         int default 0;
alter table nasclientinfo add   add uploadtype     int default 0;
alter table nasclientinfo add uploadtimeval  int default 3600;
alter table nasclientinfo add uploadcmd      char(64) default '';
    

drop table nasclientip;
create table nasclientip (
    Service_code   char(32)  not null ,  
    cip            char(20)  not null,
    starttime      char(20)  default '', 
    endtime        char(20)  default ''
)

drop table RealIDList;
create table RealIDList (
    User_name  char(32)  default '',
		Sex               char(12)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Org_name          char(128)  default '',
		Country           char(32)  default '',
		Description       char(64)  default '',
		updateflag       int default 0
);

drop table cliRealIDList;
create table cliRealIDList (
    User_name  char(32)  default '',
		Sex               char(12)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Org_name          char(128)  default '',
		Country           char(32)  default '',
		Description       char(64)  default '',
		updateflag       int default 0
);


drop table NetIDBasicList;
create table NetIDBasicList (
    User_name         char(32)  default '',
		Sex               char(12)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Org_name          char(128)  default '',
		Country           char(32)  default '',
		Card              char(32)  default '',
		Dummy_type        char(32)  default '',
		Dummy_code        char(128)  default '',
		updateflag       int default 0
);

drop table cliNetIDBasicList;
create table cliNetIDBasicList (
    User_name         char(32)  default '',
		Sex               char(12)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Org_name          char(128)  default '',
		Country           char(32)  default '',
		Card              char(32)  default '',
		Dummy_type        char(32)  default '',
		Dummy_code        char(128)  default '',
		updateflag       int default 0
);

drop table NetIDTrackList;
create table NetIDTrackList (
    logid             char(32)  default '',
    User_name         char(32)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Dummy_type        char(32)  default '',
		Dummy_code        char(128)  default '',
		Login_time        char(32)  default '',
		Exit_time         char(32)  default '',
		Service_code      char(32)  default '',
		Net_ending_code   char(32)  default '',
		updateflag        int default 0
);


drop table cliNetIDTrackList;
create table cliNetIDTrackList (
    logid             char(32)  default '',
    User_name         char(32)  default '',
		Certificate_type  char(20)  default '',
		Certificate_code  char(20)  default '',
		Dummy_type        char(32)  default '',
		Dummy_code        char(128)  default '',
		Login_time        char(32)  default '',
		Exit_time         char(32)  default '',
		Service_code      char(32)  default '',
		Net_ending_code   char(32)  default '',
		updateflag        int default 0
);


drop table ClientList;
create table ClientList (
    logid            char(32)  default '',
    gnmkey           char(32)  default '',   
    Service_code     char(32)  default '',
		User_name        char(32)  default '',
		Certificate_type char(20)  default '',
		Certificate_code char(20)  default '',
		Online_time      char(32)  default '',
		Offline_time     char(32)  default '',
		Net_ending_name  char(32)  default '',
		Net_ending_ip    char(32)  default '',
		Net_ending_mac   char(32)  default '',
		Org_name         char(128)  default '',
		Country          char(32)  default '',
		area_code        char(12)  default '',
		node             char(64)  default '',
		updateflag       int default 0
);

drop table cliClientList;
create table cliClientList (
    logid            char(32)  default '',
    gnmkey           char(32)  default '',   
    Service_code     char(32)  default '',
		User_name        char(32)  default '',
		Certificate_type char(20)  default '',
		Certificate_code char(20)  default '',
		Online_time      char(32)  default '',
		Offline_time     char(32)  default '',
		Net_ending_name  char(32)  default '',
		Net_ending_ip    char(32)  default '',
		Net_ending_mac   char(32)  default '',
		Org_name         char(128)  default '',
		Country          char(32)  default '',
		userid           int default 0,
		area_code        char(12)  default '',
		node             char(64)  default '',
		updateflag       int default 0
);


drop table ComputerList;
create table ComputerList (
    logid          char(32)  default '',
    gnmkey         char(32)  default '',   
    Service_code   char(32)  default '',
		User_name      char(32)  default '',
		Certificate_type char(20)  default '',
		Certificate_code char(20)  default '',
		Net_ending_ip    char(32)  default '',
		Net_ending_mac   char(32)  default ''
);

drop table AccessList;
create table AccessList(
    gnmkey            char(32) default   '',   
		Service_code      char(32) default   '' ,   
		User_name         char(32)  default '',
		Certificate_type  char(12)  default '',
		Certificate_code  char(24)  default '',
		Net_ending_ip     char(32) default   '' ,
		Net_ending_name   char(32) default   '' ,
		Time              char(32) default   '' ,
    Net_ending_mac    char(32) default   '' ,
		Destination_ip    char(32) default   '' ,
		Port              char(12) default   '' ,
		Service_type      char(32) default   '' ,
		KeyWord1          char(64)  default '',
		KeyWord2          char(32)  default '',
		KeyWord3          char(24)  default '',
		updateflag        int default 0,
		pinyin            char(32)  default ''
);
insert into AccessList values('1234-1234-1234-1234','23010100000001','test1','xue','0','411081197701236858','','','','','','','0005','','','',0);


drop table AlertList;
create table AlertList(
    Matching_id       char(32) default   '' ,   
		Service_code      char(32) default   '' ,   
		Rule_id           char(32) default   '' ,  
		Rule_name         char(101) default   '' ,
		Matching_level    char(32) default   '' ,
		Matching_time     char(32) default   '' ,
		Net_ending_ip     char(32) default   '' ,
		Net_ending_code   char(32) default   '' ,
		Net_ending_mac    char(32) default   '' ,
		Destination_ip    char(32) default   '' ,
		Service_type      char(32) default   '' ,
		KeyWord1          char(64)  default '',
		KeyWord2          char(32)  default '',
		KeyWord3          char(24)  default '',
		Customer_name     char(32)  default '',
		Certificate_type  char(12)  default '',
		Certificate_code  char(24)  default '',
		Org_name          char(128)  default '',
		Country           char(12)  default '',
    updateflag       int default 0
);

drop table cliAlertList;
create table cliAlertList(
    Matching_id       char(32) default   '' ,   
		Service_code      char(32) default   '' ,   
		Rule_id           char(32) default   '' ,  
		Rule_name         char(101) default   '' ,
		Matching_level    char(32) default   '' ,
		Matching_time     char(32) default   '' ,
		Net_ending_ip     char(32) default   '' ,
		Net_ending_code   char(32) default   '' ,
		Net_ending_mac    char(32) default   '' ,
		Destination_ip    char(32) default   '' ,
		Service_type      char(32) default   '' ,
		KeyWord1          char(64)  default '',
		KeyWord2          char(32)  default '',
		KeyWord3          char(24)  default '',
		Customer_name     char(32)  default '',
		Certificate_type  char(12)  default '',
		Certificate_code  char(24)  default '',
		Org_name          char(128)  default '',
		Country           char(12)  default '',
		updateflag       int default 0
);



/**/
/*drop table nasdaystat;*/
/*create table nasdaystat (*/
/*    statday        char(64) default '', */
/*    clientonline   char(32)  default '',   */
/*    clientonlinep  char(12) default ''*/
/*);*/
/**/
/*create index nasdaystat_index1 on nasdaystat(statday);*/
/**/

/*��ƽ��ֵ*/
drop table nasclientdaystat;
create table nasclientdaystat (
    statday        char(32) default '', 
    Service_code       char(32)  default '',   
    hostonline     char(12) default '' 
);
create index nasclientdaystat_index1 on nasclientdaystat(statday);


drop table ClientCmd;
create table ClientCmd (
    cmdno          char(32)  primary key, 
    Service_code   char(32)  default '',
		cmdname        char(32)  default '',
		cmdmethod      char(32)  default '',
		cmdrange       char(20)  default '',
		cmdfile        char(64)  default '',
		cmdtime        char(32)  default '',
		updateflag     int default 0             /*0 not't run  1 run  2run ok  3 err*/
);


drop table ClientCmdVar;
create table ClientCmdVar (
    cmdno          char(32)  default '', 
    cmdvarname     char(32)  default '',
		cmdvartype     char(32)  default '=',
		cmdvarval      char(32)  default ''
);

drop table nasclientpunish;
create table nasclientpunish (
    punishid            char(32) default '',
    Service_code        char(32)  default '',   
    punishdate          char(20) default '',
    punishcon           char(32) default '',
    updateflag          int default 0  
);

drop table nasclientxiaoxi;
create table nasclientxiaoxi (
    xiaoxino            char(32) default '',
    Service_code        char(32)  default '',   
    xiaoxi              char(255) default '',
    xiaoxishijian       char(32) default '', 
    qiaoshou            char(128) default '', 
    qiaoshoushijian     char(32) default '',
    xioaxidirect        int default 0,
    updateflag          int default 0
);

drop table clientxiaoxi;
create table clientxiaoxi (
		Service_code        char(32)  default '',   
    xiaoxi              char(255) default '',
    xiaoxishijian       char(32) default '', 
    qiaoshou            char(128) default '', 
    qiaoshoushijian     char(32) default '',
    xioaxidirect        int default 0,
    updateflag          int default 0
);

drop table nasbkrule;
create table nasbkrule(  
    bid              int,             
    Rule_id          char(21)  not NULL,            
    Rule_name        char(101) default   '' ,          
    matching_level   char(2)   default   '' ,         
    Rule_action      char(2)   default  '',        
    Service_type     char(12)   default   '' ,
    Keyword1         char(64)  default '',
    Keyword2         char(32)  default '',
    Keyword3         char(12)   default '',
    Matching_word    char(2)   default '',
    Set_time         char(32)  default '',
    Validation_time  char(32)  default ''
);

drop table clibkrule;
create table clibkrule(  
    bid              int,             
    Rule_id          char(21)  not NULL,            
    Rule_name        char(101) default   '' ,          
    matching_level   char(2)   default   '' ,         
    Rule_action      char(2)   default  '',        
    Service_type     char(12)   default   '' ,
    Keyword1         char(64)  default '',
    Keyword2         char(32)  default '',
    Keyword3         char(12)   default '',
    Matching_word    char(2)   default '',
    Set_time         char(32)  default '',
    Validation_time  char(32)  default ''
);



drop table nasbkuser;
create table nasbkuser(  
    User_name         char(32)  not NULL,            
    Certificate_type  char(24) default   '' ,          
    Certificate_code  char(24)   default   ''
);


drop table nasbukong;
create table nasbukong(  
    bid        int primary key,             /* ����ID    */
    bnum       char(64) default   '00' ,            /* ���ر�� */
    bman       char(64) default   '00' ,            /*���ع���Ա���*/
    bname      char(63)  default  '00',         /* ���ذ������� */
    bfuzeren      varchar(63)   default '',
    bfuzerentel   varchar(63)   default '',
    bmanager      varchar(63)   default '',
    bmanagertel   varchar(63)   default '',
    endday        varchar(32)   default '04-01-01',
    bnote         varchar(254)  default '',
    battach       varchar(128)  default '',
    bflag         int           default 0  /* 0��û��Ӧ�� 1 �Ѿ�Ӧ��  9999���ڽ���*/
);





drop table nasupdatelist;
create table nasupdatelist(           
    gnmvar              char(12)  default   '0000000000' ,            
    updatedesc          varchar(254) 
);



/*�ն˹����� */
drop table nasclientlevel;
create table nasclientlevel (
    id             int   primary key,          /*�û�key */
    idnum          char(12) default '00',       /*��λ�ı��*/
    pid            int   default 0, 
    name           char(64) default 'δ֪',
    mydesc         char(128) default '',
    level          int   default 0
);
create index nasclientlevel_index1 on nasclientlevel(id);

insert into nasclientlevel values('1','31','0','ShangHai','310000000000','0');   



drop table nassrvhttpblocklog;
create table nassrvhttpblocklog(
    gnmkey      char(32),
    sdate       char(10),
    stime       char(8), 
    sip         char(16),
    dip         char(16) default '',  /* Ŀ��IP     */
    host        varchar(64),
    uri         varchar(128),
    sortid      int default -1    
);

create index nassrvhttpblocklog_index1 on nassrvhttpblocklog(gnmkey);
create index nassrvhttpblocklog_index2 on nassrvhttpblocklog(sdate);
create index nassrvhttpblocklog_index4 on nassrvhttpblocklog(sortid);




drop table nasbukonglog;
create table nasbukonglog(  
    bid        int ,            /* ����ID    */
    alertmsg   char(254) default   '' ,    /* ���ظ澯���� */
    gnmkey     char(32),
    pcname     char(64),
    alerttype  int  default  0 ,        /* �������� 1:mail 2:form 3:ftp 4:msn 5:qq */
    lasttime   int  default  0         /* �������� */
);



/* �ʼ���ع�������  */
drop table nasmailfilter;
create table nasmailfilter (  
    rid        int,             /* ����ID          */
    num        int,             /* ִ�����  ��  ����ID    */
    rname      varchar(63) not null,     /* ��������        */
    mailfrom   varchar(63) default '',     /* ������          */
    mailto     varchar(63)  default '',     /* �ռ���          */
    mailsub    varchar(63)  default '',     /* ����            */
    mailcont   varchar(63)  default '',     /* ����            */
    mailsize   int default 0,    /* �ʼ���С ����   */
    attname    varchar(63)  default '',     /* ��������        */
    attsize    int default 0,   /* ������С ����   */
    flags      smallint default 0,   /* ��� 0:����  1:���� 2web  3mailbk 4webbk */
    sflags     smallint default 0,   	/* ֪ͨ��ʽ 0--��֪ͨ  1--֪ͨ  2--ת��  */
    smail      varchar(63)   default '',    /* ת������        */
    rnum       int   default 0,         /*�ռ�����Ŀ*/
    maction    int   default 1          /*��ض���1�����  0�������*/
);


/* ��ص��ʼ����� */
drop table nasmaillogsrv;
create table nasmaillogsrv(
    bid        int ,            /* ����ID    */
    gnmkey     char(32),
    pcname     char(64),
    sdate      char(24),
    mailfile   char(64),        /* �ʼ��ļ���      */
    alertmsg   char(248),       /* ������          */
    mtype      char(64),         /* �ʼ�����        */
    alerttype  int  default 1,
    sendto     char(64)
);

create index nasmaillogsrv_ind0 on nasmaillogsrv(gnmkey);



/* ��ص��ʼ����� */
drop table nasformlogsrv;
create table nasformlogsrv(
    bid        int ,            /* ����ID    */
    gnmkey     char(32),
    pcname     char(64),
    sdate      char(24),
    mailfile   char(64),        /* �ʼ��ļ���      */
    alertmsg   char(248),       /* ������          */
    mtype      char(64),         /* �ʼ�����        */
    alerttype  int  default 1,
    sendto     char(64)
);

create index nasformlogsrv_ind0 on nasformlogsrv(gnmkey);




drop table nasftprule;
create table nasftprule(  
    rid        int,             /* ����ID          */
    bid        int,              /* ����ID    */
    num        int,             /* ִ�����        */
    rname      varchar(63)  not null,
    xfrom       varchar(63)  default '',
    hostip     varchar(24)  default '',
    flags      smallint default 0,
    sflags     smallint default 0,
    smail      varchar(63)  default '' 
);


drop table nasftprulesrv;
create table nasftprulesrv(  
    bid        int ,            /* ����ID    */
    gnmkey     char(32),
    pcname     char(64),
    sdate      char(24),
    alertmsg   char(248),       /* ������          */
    mtype      char(64),         /* �ʼ�����        */
    alerttype  int  default 1,
    sendto     char(64)
);


drop table nasmsnrule;
create table nasmsnrule(  
    rid        int,             /* ����ID          */
    bid        int,              /* ����ID    */
    num        int,             /* ִ�����        */
    rname      varchar(63)  not null,
    xfrom       varchar(63)  default '',
    flags      smallint default 0,
    sflags     smallint default 0,
    smail      varchar(63)  default '' 
);


drop table nasmsnrulesrv;
create table nasmsnrulesrv( 
    bid        int ,            /* ����ID    */ 
    gnmkey     char(32),
    pcname     char(64),
    sdate      char(24),
    alertmsg   char(248),       /* ������          */
    mtype      char(64),         /* �ʼ�����        */
    alerttype  int  default 1,
    sendto     char(64)
);



drop table nasqqrule;
create table nasqqrule(  
    rid        int,             /* ����ID          */
    bid        int,              /* ����ID    */
    num        int,             /* ִ�����        */
    rname      varchar(63)  not null,
    xfrom       varchar(63)  default '',
    flags      smallint default 0,
    sflags     smallint default 0,
    smail      varchar(63)  default '' 
);


drop table nasetrule;
create table nasetrule(  
    rid        int, 
    bid        int, 
    num        int, 
    rname      varchar(63)  not null,
    xfrom       varchar(63)  default '',
    flags      smallint default 0,
    sflags     smallint default 0,
    smail      varchar(63)  default '' 
);


drop table nasqqrulesrv;
create table nasqqrulesrv(  
     bid        int ,            /* ����ID    */
    gnmkey     char(32),
    pcname     char(64),
    sdate      char(24),
    alertmsg   char(248),       /* ������          */
    mtype      char(64),         /* �ʼ�����        */
    alerttype  int  default 1,
    sendto     char(64)
);




drop table nasonlineclent;
create table nasonlineclent(
    gnmkey         char(32)   primary key,   	/*�û�key */
    clientid       char(128) default '', 
    clientname     char(128), 
    clientuser     char(128),
    clientadd      char(128),
    clienttel      char(128),
    clientright    int default 0, /*0 ���ܸ���*/
    clientflag     int default 0,  /*0 ������ 1*/
    startday       char(64),
    endday         char(64),
    lasttime       char(64),
    lastupdatev    int ,        /*���һ�ΰ汾�������*/
    lastupdateurl  int,         /*���һ�ΰ汾�������*/
    dbupdateflag   int  default 0,  /*�Ƿ���Ҫʡ��*/
    lastruleupdate char(64)  default '',   /*���һ�ι������ʱ��*/
    sysmsg         char(254)  default '��',   /*���һ�ι������ʱ��*/
    usernum        int  default 0,
    myname         char(128)
);
create index nasonlineclent_index1 on nasonlineclent(gnmkey);


/*insert into nasonlineclent values ('1111-1111-1111-1111','610101010000','�����û�[��������]','uuuu','aaaddd','111111',1,0,'2003.10.01','2004.10.30','',800,800,0,'','��ʽʹ������ϵ13701941874',50);*/

/*13903749192 */
/*�������أ���������*/


/* ��ص��ʼ����� */
drop table nasimlog;
create table nasimlog (
    sid        int      auto_increment  primary key,
    userid     int,
    sdate      char(24),
    imsubject  varchar(254),       /* ����            */
    imcon      varchar(254),          /* ����            */
    imfile     char(64),
    imsize     int,          /* �ʼ���С ����   */
    flags      int            /* ״̬   1--Msn  2Yahoo 3AOL 4 QQ */
);

create index nasimlog_ind0 on nasimlog (sid);
create index nasimlog_ind1 on nasimlog (userid);
create index nasimlog_ind2 on nasimlog (sdate);
create index nasimlog_ind3 on nasimlog (flags);

drop table nasadmlog;
create table nasadmlog (
    name       varchar(32),      
    sdate      char(24),
    subject    varchar(254),       /*  */
    loglevel   int                 /*1,2,3,4,5*/
);


/* ����Ԫ�� */
drop table nasband;
create table nasband(
    sid           int      primary key,
    sname         char(128),
    bandlimit     int,
    prio          int
);

create index nasband_ind0 on nasband (sid);

insert into nasband values (0,'No-Limit','0','0');


/*�������*/
drop table nasuserv;
create table nasuserv(  
    userid     int,             /* �û�ID          */
    vtype      int,             /*1 msn 2msn-glist 3:msn-ulist 4:email 5:qq 6:et 7:ftp 8:sina webmail 9:sohu webamil   */
    vname      varchar(64)   default '',
    vdesc      varchar(254)  default '',
    vpass      varchar(63)  default '',
    vid        varchar(63)  default ''
);


drop table nasqos;
create table nasqos(
    sid           int      primary key,
    qosname       char(128) default '',
    qosrate       int default 0,  /*���ش�����ֵ��ֵ*/
    qosceil       int default 0,  /*�ϴ�������ֵ��ֵ*/
    qostype       int default 0, /*���ش���֤*/
    qossfq        int default 0, /*�ϴ�����֤*/
    prio          int default 0,
    qosdefault    int default 0,  /*ϵͳĬ��*/ 
    qoslinktype   int default 0   /*0-3 uflag:  0: ����ͨ�� 1��Ĭ��ͨ��  2�����ͨ��  3������ͨ��*/
);
create index nasqos_ind0 on nasqos (sid);

drop table nasqosrun;
create table nasqosrun(
    cid           int   ,
    sid           int   ,
    qosname       char(128) default '',
    qosrate       int default 0,
    qosceil       int default 0,
    qostype       int default 2, 
    qossfq        int default 1, 
    prio          int default 0,
    qosdefault    int default 0,   
    qoslinktype   int default 1   
);

create index nasqosrun_ind0 on nasqosrun (cid);


drop table nasqosmatch;
create table nasqosmatch(
    sid           int      primary key,
    qossrvname    char(128) default '',
    qosid         int default 0,
    prio          int default 0,
    matchtype     int default 1,  /*1234*/
    sharetype     int default 1   /*0-1*/  
    maxflow       bingint   default 0,
    maxtime       int       default 0,
    maxtcp        int       default 0,
    maxudp        int       default 0,
    moreflag      char(32)  default '0000000000',
    maxpackage int default 0;       
    maxBytes   bigint default 0;     
    maxudpp    int default 0;     
    maxtcpp    int default 0;     
    maxupp     int default 0;      
    maxdownp   int default 0;      
    maxsp      int default 0;       
    maxnc      int default 0; 
    onlybindip int default 0;      
    macbindip  int default 0;       
    onlylogone int default 0; 
);
create index nasqosmatch_ind0 on nasqosmatch (sid);



drop table nasqosmatchup;
create table nasqosmatchup(
    sid           int      primary key,
    qossrvname    char(128) default '',
    qosid         int default 0,
    prio          int default 0,
    matchtype     int default 1,  /*1234*/
    sharetype     int default 1   /*0-1*/
);

create index nasqosmatchup_ind0 on nasqosmatchup (sid);



drop table nasqosmatchsrv;
create table nasqosmatchsrv(
	sid           int,
	dst           char(32)  default '', 
  src           char(32)  default '', 
  dport         int default 0, 
  sport         int default 0 
);


drop table nasqosmatchuser;
create table nasqosmatchuser(
	sid           int,
	userid        int
);

drop table nasqosmatchpolicy;
create table nasqosmatchpolicy(
	sid           int,
	policy        int
);

drop table nasqosmatchgroup;
create table nasqosmatchgroup(
	sid           int,
	groupid       int
);



drop table nasconnectlog;
create table nasconnectlog (
    userid      int,    
    sdate       char(10),
    stime       char(8), 
    sip         char(16),
    dip         char(16) default '', 
    con        varchar(254)  
);

create index nasconnectlog_index1 on nasconnectlog (userid);
create index nasconnectlog_index2 on nasconnectlog (sdate);
create index nasconnectlog_index3 on nasconnectlog (sip);
create index nasconnectlog_index4 on nasconnectlog (stime);


drop table nasuserlog;
create table nasuserlog (
    userid      int,    
    stime       int default 0, 
    sip         int default 0,
    smac        char(13) default '', 
    shost       char(32) default '' 
);

create index nasuserlog_index1 on nasuserlog (userid);


drop table nasAdminArea;
create table nasAdminArea (
    id           int       primary key,      
    ipstart      char(16),                  
    ipend        char(16)
);


drop table nasnowconnect;
create table nasnowconnect (
    nowmin      int,    
    httpnum     int,
    tcpnum      int,
    udpnum      int,
    usernum     int 
);
insert into nasnowconnect values (0,1,1,1,1);
insert into nasnowconnect values (1,1,1,1,1);
insert into nasnowconnect values (2,1,1,1,1);
insert into nasnowconnect values (3,1,1,1,1);
insert into nasnowconnect values (4,1,1,1,1);
insert into nasnowconnect values (5,1,1,1,1);
insert into nasnowconnect values (6,1,1,1,1);
insert into nasnowconnect values (7,1,1,1,1);
insert into nasnowconnect values (8,1,1,1,1);
insert into nasnowconnect values (9,1,1,1,1);
insert into nasnowconnect values (10,1,1,1,1);
insert into nasnowconnect values (11,1,1,1,1);
insert into nasnowconnect values (12,1,1,1,1);
insert into nasnowconnect values (13,1,1,1,1);
insert into nasnowconnect values (14,1,1,1,1);
insert into nasnowconnect values (15,1,1,1,1);
insert into nasnowconnect values (16,1,1,1,1);
insert into nasnowconnect values (17,1,1,1,1);
insert into nasnowconnect values (18,1,1,1,1);
insert into nasnowconnect values (19,1,1,1,1);
insert into nasnowconnect values (20,1,1,1,1);
insert into nasnowconnect values (21,1,1,1,1);
insert into nasnowconnect values (22,1,1,1,1);
insert into nasnowconnect values (23,1,1,1,1);
insert into nasnowconnect values (24,1,1,1,1);
insert into nasnowconnect values (25,1,1,1,1);
insert into nasnowconnect values (26,1,1,1,1);
insert into nasnowconnect values (27,1,1,1,1);
insert into nasnowconnect values (28,1,1,1,1);
insert into nasnowconnect values (29,1,1,1,1);
insert into nasnowconnect values (30,1,1,1,1);
insert into nasnowconnect values (31,1,1,1,1);
insert into nasnowconnect values (32,1,1,1,1);
insert into nasnowconnect values (33,1,1,1,1);
insert into nasnowconnect values (34,1,1,1,1);
insert into nasnowconnect values (35,1,1,1,1);
insert into nasnowconnect values (36,1,1,1,1);
insert into nasnowconnect values (37,1,1,1,1);
insert into nasnowconnect values (38,1,1,1,1);
insert into nasnowconnect values (39,1,1,1,1);
insert into nasnowconnect values (40,1,1,1,1);
insert into nasnowconnect values (41,1,1,1,1);
insert into nasnowconnect values (42,1,1,1,1);
insert into nasnowconnect values (43,1,1,1,1);
insert into nasnowconnect values (44,1,1,1,1);
insert into nasnowconnect values (45,1,1,1,1);
insert into nasnowconnect values (46,1,1,1,1);
insert into nasnowconnect values (47,1,1,1,1);
insert into nasnowconnect values (48,1,1,1,1);
insert into nasnowconnect values (49,1,1,1,1);
insert into nasnowconnect values (50,1,1,1,1);
insert into nasnowconnect values (51,1,1,1,1);
insert into nasnowconnect values (52,1,1,1,1);
insert into nasnowconnect values (53,1,1,1,1);
insert into nasnowconnect values (54,1,1,1,1);
insert into nasnowconnect values (55,1,1,1,1);
insert into nasnowconnect values (56,1,1,1,1);
insert into nasnowconnect values (57,1,1,1,1);
insert into nasnowconnect values (58,1,1,1,1);
insert into nasnowconnect values (59,1,1,1,1);

drop table nasVLanArea;
create table nasVLanArea (
    id           int       primary key,  
    vlanid       smallint default 0, 
    ip           char(16) default '',             
    mask         char(16) default '',   
    dev          char(12) default ''
);



drop table arpreport;
create table arpreport (
    arpip        char(24) default '',
    arpmac       char(24) default '',             
    requestnum   int  default 0,   
    requestlasttime  char(32) default '',
    requestednum   int  default 0,   
    requestedlasttime  char(32) default ''
);


drop table nassearchkey;
create table nassearchkey(
    userid      int,                
    sdate       char(10),          
    stime       char(2),           
    host        varchar(64),        
    searchkey   varchar(128)
);

create index nassearchkey_index1 on nassearchkey(userid);
create index nassearchkey_index2 on nassearchkey(sdate);
