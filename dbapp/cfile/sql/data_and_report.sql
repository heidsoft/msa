��
msasearchkey
msahttplog
msahttpreport
msasrvreport

caSdate=1292515200
caEdate=1293551999

drop table msasrvreport;
create table msasrvreport (
    userid            int,              /* �û�ID */
    sdate       char(10),              /* ����      */
    service     int,                   /* �������  */
    ubytes      bigint,                /* ��������  */
    dbytes      bigint,                /* ��������  */
    ctime       int,                   /* ���Ӵ���  */
    onlinetime  int default 0          /* ����ʱ��  */

);
create index msasrvreport_index0 on nassrvreport (userid);
create index msasrvreport_index1 on nassrvreport (sdate);

 

drop table msahttpreport;
create table msahttpreport (
    userid      int,                /* �û�ID  */
    sdate       char(10),           /* ���� */
    host        varchar(64),        /* ��ַ */
    bytes       bigint default 0,             /* ����      */
    lcount      int default 0,             /* �������  */
    ctime       int default 0,                 /* ����ʱ��  */
    urlsort     char(6) default '0000'

);
create index msahttpreport_index1 on nashttpreport (userid);
create index msahttpreport_index2 on nashttpreport (sdate);

drop table msasrvreport;
create table msasrvreport (
    userid      int,    
    sdate       char(10),             
    service     int,                   
    ubytes      bigint,              
    dbytes      bigint,                
    ctime       int,                  
    onlinetime  int default 0          
);
create index msasrvreport_index0 on msasrvreport (userid);
create index msasrvreport_index1 on msasrvreport (sdate);

 

drop table msahttpreport;
create table msahttpreport (
    userid      int,               
    sdate       char(10),         
    host        varchar(64),     
    bytes       bigint default 0,          
    lcount      int default 0,        
    ctime       int default 0,        
    urlsort     char(6) default '0000'
);
create index msahttpreport_index1 on msahttpreport (userid);
create index msahttpreport_index2 on msahttpreport (sdate);


 

drop table msafileloglist;

�ñ�����Ԥ�Ȳ鿴���캬�б�
create table msafileloglist (    a��
    sdate      varchar(12), 
    tabname    varchar(64)
);

 sdatte:����
 tabname:����

drop table msafilelog20101022;

�ñ�Ϊϵͳ���ɣ�ÿ�춼�����һ�ű�
create table msafilelog20101022 (  b��
    userid     int,
    tantype    int,   
    stime      varchar(8),//ʱ��
    filename   varchar(64),//�ļ���
    fileurl    varchar(128),//�����������·��
    contenttype   varchar(64)   //����
);

create index msafilelog20101022_ind1 on msaimlog (userid);

1:ftp�ϴ�
2:ftp����
3:msn file
4:qq file
5:upload ��
6:smtp file
7:pop3 file
8:http download


insert into msasearchkey values(1,1282515211,'host1','searchkey1');
insert into msasearchkey values(2,1272515222,'host2','searchkey2');
insert into msasearchkey values(3,1262515233,'host3','searchkey3');
insert into msasearchkey values(4,1252515244,'host4','searchkey4');
insert into msasearchkey values(5,1293551999,'host5','searchkey5');
insert into msasearchkey values(1,1294479200,'host5','searchkey5');

insert into msasearchkey values(1,1294479200,'1','1');
insert into msasearchkey values(2,1293579200,'2','2');
insert into msasearchkey values(3,1293579400,'4','4');


insert into msasearchkey values(4,1293579422,'4','4');
insert into msasearchkey values(5,1293579400,'5','5');
insert into msasearchkey values(6,1293579466,'6','6');


insert into msasrvreport values(1,'2010-11-20','1',512,555,200,77);
insert into msasrvreport values(2,'2010-09-20','2',512,555,200,66);
insert into msasrvreport values(3,'2010-06-20','3',512,555,200,33);
insert into msasrvreport values(4,'2010-10-20','4',512,555,200,55);
insert into msasrvreport values(5,'2010-08-20','5',512,555,200,33);
insert into msasrvreport values(6,'2010-12-20','6',512,555,200,66);

insert into msahttpreport values(1,'2010-12-23','www.baidu.com',52,5565,2020,'0000');
insert into msahttpreport values(2,'2010-01-25','www.sina.com',5120,5455,2040,'0000');
insert into msahttpreport values(3,'2010-07-27','www.google.com',5192,5655,2400,'5555');
insert into msahttpreport value0000'2010-02-22','www.heidsoft.com',5142,7555,2050,'0000');
insert into msahttpreport values(5,'2010-02-20','www.liubin.com',5612,5855,2050,'2222');
insert into msahttpreport values(6,'2010-12-20','www.yongy.com',5132,5455,2600,'2323');


insert into msaimlog values(1,0,'2010-12-23','13:22:44','from','to','hello',1);
insert into msaimlog values(2,1,'2010-01-25','13:33:55','from','to','hao do you',2);
insert into msaimlog values(3,2,'2010-07-27','14:22:00','from','to','good',4);
insert into msaimlog values(4,3,'2010-02-22','15:44:33','from','to','nice to ment',3);
insert into msaimlog values(5,4,'2010-02-20','16:55:22','from','to','girl and boy',5);
insert into msaimlog values(6,5,'2010-12-20','17:33:33','from','to','sorry',6);


insert into msafileloglist values('10-10-22','msafilelog20101022');
insert into msafileloglist values('2011-01-12','msafilelog20110112');
insert into msafileloglist values('2011-01-13','msafilelog20110113');

drop table msafilelog20110112;
drop table msafilelog20110113;

create table msafileloglist( 
    sdate      varchar(12), 
    tabname    varchar(64)
);

create table msafilelog20110113(
    userid     int,
    tantype    int,   
    stime      varchar(8),
    filename   varchar(64),
    fileurl    varchar(128),
    contenttype   varchar(64)
);
create index msafilelog20110113_ind1 on msaimlog (userid);

drop index msafilelog20110113_ind1;


insert into msafilelog20110112 values(1,0,'13:01:12','ftpfile','datacenter','hello,good');
insert into msafilelog20110112 values(2,1,'14:04:12','qq','datacenter','how,good');
insert into msafilelog20110112 values(3,2,'15:08:12','msn','datacenter','ni hao,good');
insert into msafilelog20110112 values(4,3,'16:01:12','http','datacenter','nice,good');
insert into msafilelog20110112 values(5,4,'17:33:12','erjinzhi','datacenter','girl,good');
insert into msafilelog20110112 values(6,5,'11:45:12','upload','datacenter','boy,good');

insert into msafilelog20110113 values(1,0,'13:01:12','ftpfile','datacenter','hello,good');
insert into msafilelog20110113 values(2,1,'14:04:12','qq','datacenter','how,good');
insert into msafilelog20110113 values(3,2,'15:08:12','msn','datacenter','ni hao,good');
insert into msafilelog20110113 values(4,3,'16:01:12','http','datacenter','nice,good');
insert into msafilelog20110113 values(5,4,'17:33:12','erjinzhi','datacenter','girl,good');
insert into msafilelog20110113 values(6,5,'11:45:12','upload','datacenter','boy,good');



insert into msauser(userid,username,dispname,Certificate_type,Certificate_code,sex,password,bindemail,bindip,bindmac,ratelimit,ratetype,addtime,groupid0,groupid1,groupid2,groupid3,groupid4,moreflag,policyid,locktime)values(2,'1','1',111,'',0,'1','','','',0,0,1293084632,1,0,0,0,0,'','',1293033600)


�ʼ���
���շ��͵��ʼ�
���ս��յ��ʼ�
���մ��������ʼ�
���մ���1M���ʼ�
���շ��ϱ������Ե��ʼ�
���շ��Ϲؼ��ֱ������ʼ�
ȫ���ʼ�����

drop table msamailloglist;
create table msamailloglist (
    sdate      varchar(12), 
    tabname    varchar(64)
);



insert into msamailloglist values('2011-01-13','msamaillog20110113');
insert into msamailloglist values('2011-01-14','msamaillog20110114');



drop table msamaillog20101022;
create table msamaillog20101022 (
    sid        int    primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(128),        /* �ʼ��ļ���      */
    mailfrom   char(128),        /* ������          */
    mailto     char(128),        /* �ռ���          */
    mailsub    char(128),        /* ����            */
    mailasize  bigint,           /* ����            */
    mailsize   bigint,           /* �ʼ���С ����   */
    flags      int,              /* �ʼ�״̬ 0--pop3  1-smtp*/
    mtype      char(64),         /* �ʼ�����        */
    rback      int  default 0,   /* key*/
    dip        char(24) default '0.0.0.0'
);

create index msamaillog20101022_ind0 on msamaillog20101022 (sid);
create index msamaillog20101022_ind1 on msamaillog20101022 (userid);
create index msamaillog20101022_ind2 on msamaillog20101022 (sdate);

insert into msamaillog20110113 values(1,1,'2011-01-13 13:01:12','mailname1','from1','to1','hello1',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110113 values(2,2,'2011-01-13 14:01:12','mailname2','from2','to2','hello2',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110113 values(3,3,'2011-01-13 15:01:12','mailname3','from3','to3','hello3',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110113 values(4,4,'2011-01-13 16:01:12','mailname4','from4','to4','hello4',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110113 values(5,5,'2011-01-13 17:01:12','mailname5','from5','to5','hello5',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110113 values(6,6,'2011-01-13 18:01:12','mailname6','from6','to6','hello6',999,888,0,'mytpye',0,'192.168.0.60');

insert into msamaillog20110114 values(1,1,'2011-01-14 13:01:12','mailname1','from1','to1','hello1',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110114 values(2,2,'2011-01-14 14:01:12','mailname2','from2','to2','hello2',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110114 values(3,3,'2011-01-14 15:01:12','mailname3','from3','to3','hello3',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110114 values(4,4,'2011-01-14 16:01:12','mailname4','from4','to4','hello4',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110114 values(5,5,'2011-01-14 17:01:12','mailname5','from5','to5','hello5',999,888,0,'mytpye',0,'192.168.0.60');
insert into msamaillog20110114 values(6,6,'2011-01-14 18:01:12','mailname6','from6','to6','hello6',999,888,0,'mytpye',0,'192.168.0.60');


web�ʼ�
���յ��ʼ�
���մ��������ʼ�
���մ���1M���ʼ�
�ʼ�����


drop table msawebmailloglist;
create table msawebmailloglist (
    sdate      varchar(12), 
    tabname    varchar(64)
);

insert into msawebmailloglist values('2011-02-11','msawebmaillog20110111');
insert into msawebmailloglist values('2011-02-10','msawebmaillog20110110');

drop table msawebmaillog20110211;
create table msawebmaillog20110211 (
    sid        int    primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(128),        /* �ʼ��ļ���      */
    mailfrom   char(128),        /* ������          */
    mailto     char(128),        /* �ռ���          */
    mailsub    char(128),        /* ����            */
    mailasize  bigint,           /* ����            */
    mailsize   bigint,           /* �ʼ���С ����   */
    flags      int,              /* �ʼ�״̬ 0--pop3  1-smtp*/
    mtype      char(64),         /* �ʼ�����        */
    rback      int  default 0,   /* key*/
    dip        char(24) default '0.0.0.0'
);

create index msawebmaillog20110211_ind0 on msawebmaillog20110211 (sid);
create index msawebmaillog20110211_ind1 on msawebmaillog20110211 (userid);
create index msawebmaillog20110211_ind2 on msawebmaillog20110211 (sdate);


 
/* �ʼ���ع�������  */
drop table msamailfilter;
create table msamailfilter (  
    rid        int,             /* ����ID          */
    num        int,             /* ִ�����  ��  ����ID    */
    rname      varchar(63) not null,       /* ��������        */
    mailfrom   varchar(63) default '',     /* ������          */
    mailto     varchar(63)  default '',    /* �ռ���          */
    mailsub    varchar(63)  default '',    /* ����            */
    mailcont   varchar(63)  default '',    /* ����            */
    mailsize   int default 0,              /* �ʼ���С ����   */
    attname    varchar(63)  default '',    /* ��������        */
    attsize    int default 0,              /* ������С ����   */
    flags      smallint default 0,         /* ��� 0:����  1:���� */
    sflags     smallint default 0,               /* ֪ͨ��ʽ 0--��֪ͨ  1--֪ͨ  2--ת��  */
    smail      varchar(63)   default '',   /* ת������        */
    rnum       int   default 0,            /*�ռ�����Ŀ*/
    maction    int   default 1             /*��ض���1�����  0�������*/
);


insert into msamaillog20110117 values(1,1,'2011-01-17','mailname1','from1','to1','hello1',999,888,1,'mytpye',0,'192.168.0.60');
insert into msamaillog20110117 values(2,2,'2011-01-17','mailname2','from2','to2','hello2',999,888,0,'mytpye',1,'192.168.0.60');
insert into msamaillog20110117 values(3,3,'2011-01-17','mailname3','from3','to3','hello3',999,888,1,'mytpye',1,'192.168.0.60');
insert into msamaillog20110117 values(4,4,'2011-01-17','mailname4','from4','to4','hello4',999,888,0,'mytpye',1,'192.168.0.60');
insert into msamaillog20110117 values(5,5,'2011-01-17','mailname5','from5','to5','hello5',999,888,1,'mytpye',0,'192.168.0.60');
insert into msamaillog20110117 values(6,6,'2011-01-17','mailname6','from6','to6','hello6',999,888,1,'mytpye',0,'192.168.0.60');
insert into msamaillog20110117 values(7,7,'2011-01-17','/datacenter/msa/mailmon/212500000','from7','to7','hello7',999,888,1,'mytpye',0,'192.168.0.60');
insert into msamaillog20110117 values(8,8,'2011-01-17','/datacenter/msa/mailmon','from8','to8','hello8',999,888,0,'mytpye',1,'192.168.0.60');
insert into msamaillog20110117 values(9,9,'2011-01-17','/datacenter/msa/mailmon','from9','to9','hello9',999,888,1,'mytpye',1,'192.168.0.60');

drop table msamaillog20110117;
create table msamaillog20110117 (
    sid        int    primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(128),
    mailfrom   char(128),  
    mailto     char(128), 
    mailsub    char(128), 
    mailasize  bigint,  
    mailsize   bigint,  
    flags      int,  
    mtype      char(64),  
    rback      int  default 0, 
    dip        char(24) default '0.0.0.0'
);

create index msamaillog20110117_ind0 on msamaillog20110117 (sid);
create index msamaillog20110117_ind1 on msamaillog20110117 (userid);
create index msamaillog20110117_ind2 on msamaillog20110117 (sdate);


create table msamaillog20110114 (
    sid        int    primary key,
    userid     int,
    sdate      char(24),
    mailfile   char(128),
    mailfrom   char(128),  
    mailto     char(128), 
    mailsub    char(128), 
    mailasize  bigint,  
    mailsize   bigint,  
    flags      int,  
    mtype      char(64),  
    rback      int  default 0, 
    dip        char(24) default '0.0.0.0'
);

create index msamaillog20110114_ind0 on msamaillog20110114 (sid);
create index msamaillog20110114_ind1 on msamaillog20110114 (userid);
create index msamaillog20110114_ind2 on msamaillog20110114 (sdate);


drop table msamailfilter;
create table msamailfilter (  
    rid        int,  
    num        int,     
    rname      varchar(63) not null,  
    mailfrom   varchar(63) default '',  
    mailto     varchar(63)  default '', 
    mailsub    varchar(63)  default '',  
    mailcont   varchar(63)  default '',  
    mailsize   int default 0,        
    attname    varchar(63)  default '', 
    attsize    int default 0,        
    flags      smallint default 0,   
    sflags     smallint default 0,   
    smail      varchar(63)   default '', 
    rnum       int   default 0,       
    maction    int   default 1  
);




////////////////////////����
�������ݣ�
�����������������񱨱�ķ���Ϊһ�����񣬷�����Ϣ��_ltPubInfo->msaTopSrv   
       topSrvName[MAX_TOP_SRVNUM]�ж�ȡ

���ӳ������ʱ������ݣ����ڴ�pub->_AllInfo�з��Ӷ������������д�����ݿ�
drop table msatimereport;
create table msatimereport (
sdate       char(10),              --����  
hours       int,                   --hours
mintue      int,                   --mintue
ubytes      bigint,                --����������
dbytes      bigint                 --����������
);

insert into msatimereport values('2011-07-19',10,59,2048,3048);
insert into msatimereport values('2011-07-13',9,59,2048,2048);
insert into msatimereport values('2011-07-14',8,59,2048,3048);
insert into msatimereport values('2011-07-15',7,59,2048,1048);
insert into msatimereport values('2011-07-16',6,59,3048,3048);
insert into msatimereport values('2011-07-17',5,59,2048,1024);
insert into msatimereport values('2011-07-18',4,59,1024,3048);
 
Сʱ���񱨱����ݣ����ڴ�pub->_AllInfo��ÿСʱ�������������д�����ݿ�
drop table msatimesrvreport;
create table msatimesrvreport (
	  sdate       char(10),               /* ����      */
    hours       int,                   /* �û�ID */
    service     int,                   /* �������  */
    ubytes      bigint,                 /* ��������  */
    dbytes      bigint,                 /* ��������  */
    onlinetime  int default 0           /* ����ʱ��  */

);


��Ա�������ߺ�����������ʱ�����ݣ�nasOnlineUserInfo������д������12������Ӧ�ò��ּƷ�״̬
drop table msaAccountReport;
create table msaAccountReport (
userid           int,                     /* �û�ID */
sdate            char(10),                /* ����      */
ubytes           bigint,                  /* ��������  */
dbytes           bigint,                  /* ��������  */
ctime            int,                     /* ���Ӵ���  */
onlinetime       int default 0,           /* ����ʱ��  */
Online_time      bigint   default  0,
Offline_time     bigint   default  0,
Net_ending_ip    bigint   default  0,
Net_ending_mac   char(15)  default  '',
account          float
);
create index msaAccountReport_index0 on msaAccountReport (userid);




��Ա�������ڱ������ݣ�nasOnlineUserInfo������д������12������Ӧ�ò��ּƷ�״̬
drop table msasrvreport;
create table msasrvreport (
    userid      int,                   /* �û�ID */
    sdate       char(10),              /* ����      */
    service     int,                   /* �������  */
    ubytes      bigint,                /* ��������  */
    dbytes      bigint,                /* ��������  */
    ctime       int,                   /* ���Ӵ���  */
    onlinetime  int default 0          /* ����ʱ��  */
);
create index msasrvreport_index0 on msasrvreport (userid);
create index msasrvreport_index1 on msasrvreport (sdate);


��վ���ʱ������ݣ���httpbuffer��д�룬��ʱдһ�Σ������Գ�ʱʱ��Ϊ׼
drop table msahttpreport;
create table msahttpreport (
    sdate       char(10),             /* ����      */
    host        varchar(64),          /* ��ַ      */
    bytes       bigint default 0,     /* ����      */
    lcount      int default 0,        /* �������  */
    ctime       int default 0,        /* ����ʱ��  */
    urlsort     int default 0
);
create index msahttpreport_index2 on msahttpreport(sdate);

insert into msahttpreport values('2011-07-19','192.168.0.60',1159,121,3148,8);
insert into msahttpreport values('2011-07-18','192.168.0.61',1259,122,3248,7);
insert into msahttpreport values('2011-07-17','192.168.0.62',1359,123,3348,6);
insert into msahttpreport values('2011-07-16','192.168.0.63',1459,124,3448,5);
insert into msahttpreport values('2011-07-15','192.168.0.64',1559,125,3548,4);
insert into msahttpreport values('2011-07-14','192.168.0.65',1659,126,3648,3);
insert into msahttpreport values('2011-07-13','192.168.0.66',1759,127,3748,2);
insert into msahttpreport values('2011-07-12','192.168.0.67',1859,128,3848,1);

 
�û���վ���ʱ������ݣ���userhttpbuffer��д�룬��ʱдһ�Σ�������Ƚ��Ӵ����ݱ�������Ҫ�٣����б�Ҫ����ѡ�񲻼�¼
drop table msauserhttpreport;
create table msauserhttpreport (
    userid      int,                /* �û�ID */
    sdate       char(10),           /* ����      */
    host        varchar(64),        /* ��ַ      */
    bytes       bigint default 0,   /* ����      */
    lcount      int default 0,      /* �������  */
    ctime       int default 0,      /* ����ʱ��  */
    urlsort     int default 0
);
create index msauserhttpreport_index2 on msauserhttpreport(sdate);

insert into msauserhttpreport values(1,'2011-07-19','192.168.0.60',1159,121,3148,8);
insert into msauserhttpreport values(2,'2011-07-18','192.168.0.61',1259,122,3248,7);
insert into msauserhttpreport values(3,'2011-07-17','192.168.0.62',1359,123,3348,6);
insert into msauserhttpreport values(4,'2011-07-16','192.168.0.63',1459,124,3448,5);
insert into msauserhttpreport values(5,'2011-07-15','192.168.0.64',1559,125,3548,4);
insert into msauserhttpreport values(6,'2011-07-14','192.168.0.65',1659,126,3648,3);
insert into msauserhttpreport values(7,'2011-07-13','192.168.0.66',1759,127,3748,2);
insert into msauserhttpreport values(8,'2011-07-12','192.168.0.67',1859,128,3848,1);

Ŀ��ip����ͳ�����ݣ�nasDipBuffer������д������12������Ӧ�ò��ּƷ�״̬
drop table msaDipReport;
create table msaDipReport (
sdate       char(10),             /* ����      */
dip         bigint,               /* ��������  */
bytes       bigint,               /* ����  */
ctime       int,                  /* ���Ӵ���  */
onlinetime  int default 0         /* ����ʱ��  */
);
create index msaClientList_index0 on msaDipReport (dip);







