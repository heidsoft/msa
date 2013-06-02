create database msa;

drop table msaAdminArea;
create table msaAdminArea (
    id           int       primary key,      
    ipstart      varchar(16),                  
    ipend        varchar(16)
);

drop table msaadmuser;
create table msaadmuser (
    name       varchar(32)   primary key,  
    password   varchar(32),    
    lright     varchar(128), 
    email      varchar(64),  
    lasttime   int,     
    bindip    varchar(32) default '',
    grouplist1 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist2 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist3 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist4 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    grouplist5 char(201) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
);

insert into msaadmuser values('admin','qoQhDpRa4xOAwkBtuS0mq0','1111111111111111111111111111','',0,'');

drop table msaadmlog;
create table msaadmlog (
    name       varchar(32),      
    sdate      varchar(24),
    subject    varchar(254),       /*  */
    loglevel   int                 /*1,2,3,4,5*/
);

drop table msaGroup;
create table msaGroup (
    id             int   primary key, 
    pid            int   default 0, 
    name           varchar(64) default 'DefaultGroup',
    mydesc         varchar(128) default '',
    level          int   default 0
);
create index msagroup_index1 on msaGroup(id);
create index msagroup_index2 on msaGroup(pid);
create index msagroup_index3 on msaGroup(name);

insert into msaGroup values('0','0','Ĭ�ϲ���','Ĭ�ϲ���','0');   

drop table msaGroupip;
create table msaGroupip (
    groupid    int,
    lip        bigint default 0 ,   
	  lipend     bigint default 0 
);

drop table msaPolicy;
create table naspolicy (
    pid     int  primary key ,   /*policy id*/
    pname   varchar(48) not null,
    pdesc   varchar(64) default "",  /*desc*/
);
insert into msaPolicy (pid,pname,pdesc) values (0,'default-Policy','default policy');

drop table msaPolicyip;
create table msaPolicyip (
    pid    int,
    lip        bigint default 0 ,   
	  lipend     bigint default 0 
);


drop table msaUser;
create table msaUser (
    userid      int   primary key,
    username    varchar(32), /*�û���*/
    dispname    varchar(32),  /*��ʾ������*/
    Certificate_type  smallint default 0,
		Certificate_code  varchar(24)  default '',
		sex               smallint default 0,
    password    varchar(32),
    groupid0    int default 0,      /*gid */
    groupid1    int default 0,      /*gid */
    groupid2    int default 0,      /*gid */
    groupid3    int default 0,      /*gid */
    groupid4    int default 0,      /*gid */
    bindemail   varchar(64), /*�󶨵�email��ַ*/
    bindip      varchar(16), /*�󶨵�ip��ַ*/
    bindmac     varchar(32), /*�󶨵�mac��ַ*/
    useflags    smallint default 0,     /*10��ֹ���� 9���� 0����*/      
    ratelimit   int  default 0, /*��������*/
    ratelower   int  default 0, /*��������*/ 
    addtime     bigint default 0,     /*���û���Ч����*/   
    locktime    bigint default 0,     /*���û���Ч����*/
    lasttime    bigint default 0,     /*�û����һ������ʱ��*/
    lAllUpFlow  bigint default 0, 	 /*�ܵ���������*/
    lAllDownFlow  bigint default 0, /*�ܵ���������*/
    lAllTime    int default 0,   /*�ܵ�����ʱ��*/
    lLimitBytes  bigint default 0, /*ÿ��������������*/
    lLimitTimes  int default 0, /*ÿ����������ʱ��*/
    lLimitBytess bigint default 0, /*ÿ��������������*/
    lLimitTimess int default 0, /*ÿ����������ʱ��*
    lLimitBytesm bigint default 0, /*ÿ��������������*/
    lLimitTimesm int default 0, /*ÿ����������ʱ��*
    moreflag     varchar(32) default '00000000000000000000000000000000',
    policyid     varchar(128) default '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000',
    jftype      int    default 0,  
    accountnum  int    default 0, 
    maxpackage  int    default 0, 
    maxBytes    bigint    default 0,
		maxudp     int default 0,      /* ���udp���� */   
    maxtcp     int default 0,      /*  ���tcp����*/
    maxudpp    int default 0,      /*  ÿ�����udp������*/ 
    maxtcpp    int default 0,      /*  ÿ�����tcp������*/ 
    maxupp     int default 0,      /*  ÿ��up������*/ 
    maxdownp   int default 0,      /*  ÿ��down������*/  
    maxsp      int default 0,       /*  ÿ��128�ֽ�С������*/ 
    maxnc      int default 0       /*  ÿ������½�������Ŀ*/ 
); 
 
/* moreflag  1 noftp 2 nopost 3 nomsn 4 noqq*/  
    
    
create UNIQUE index nasuser_index on nasuser (username);
    
create  index nasuser_index2 on nasuser (bindip);
create  index nasuser_index3 on nasuser (bindmac);
create  index nasuser_index4 on nasuser (groupid);


\d msaadminarea;
\d msaadmlog;
\d msaadmuser;
\d msagroup;
\d msagroupip;
\d msapolicy;
\d msapolicyip;
\d msauser
select *from msaadminarea;
select *from msaadmlog;
select *from msaadmuser;
select *from msagroup;
select *from msagroupip;
select *from msapolicy;
select *from msapolicyip;
select *from msauser;