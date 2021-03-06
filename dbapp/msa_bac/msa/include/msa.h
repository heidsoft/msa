#ifndef __MSADEF__
#define __MSADEF__


#include <netinet/ether.h>
#include "pubfun.h"


/*部门层次级别*/
#define _MAX_GROUPLEVEL   5
/*全部部门总数*/
#define _MAX_ALLGRPNUM     1000
#define _MAX_ALLPOLICY     128
#define _MAXSNMPNUM        7
#define _MAX_BIGAREANUM    100
#define _MAXSNMPNUM        7
#define _MAXNETAREANUM     1000
#define _MAXVPATHNUM       4
#define _MAX_QOSSTATIC_CHANEL    1000
#define NAS_MAXURLLIST_NUM       200000
#define NAS_MAXURLSORT_NUM       100
#define _MAX_SRVRULE_NUM    64

/*系统函数参数*/
#define NAS_MAX_COREFUNNUM    200
#define NAS_MAX_FUNNUM        200
#define NAS_DEFAULT_FUNTIME   200

/*管理员参数*/
#define MAX_ADMIN_SESSION            300
#define MAX_ADMIN_TIMEOUT            7200
#define MAX_ADMIN_TRYTIMEOUT         120
#define MAX_ADMIN_MAXRIGHT           100


/*自定义字符串*/
#define MAX_SYSTEM_MSG               1000
/*最长256*/
#define MAX_LANG_LIST_CONSIZE        256

#define MAX_SRVNAME_SIZE    32
#define MAX_TOPSRVNAME_SIZE    64
#define MAX_TOP_SRVNUM      35
#define MAX_SYS_SRVNUM      500
#define MAX_PORTNUM         65536
#define NAS_MAX_HOURMIN     5  

#define _pubconfdir   "/etc/msa/msa"
#define _datacenterdir   "/datacenter/msa"
#define _proccessdir   "/datacenter/proccess"
#define _TMPDIR   "/datacenter/tmp"

#define NAS_PROTOCOL_TCP 6    /*tcp协议*/
#define NAS_PROTOCOL_UDP 17   /*udp协议*/ 

#define MSA_SERVICE_UNKNOWN    0    /* 其它服务             */
#define MSA_SERVICE_HTTP       5    /* Web服务              */
#define MSA_SERVICE_SMTP       22    /* SMTP服务            */
#define MSA_SERVICE_POP3       19    /* POP服务             */
#define MSA_SERVICE_HTTPSRV    34    /* 本地Web服务      */
#define MSA_SERVICE_SMTPSRV    37    /* 本地SMTP服务     */
#define MSA_SERVICE_POP3SRV    36    /* 本地POP服务      */

#define MSA_SERVICE_MSN        16    /* msn服务          */
#define MSA_SERVICE_YAHOO      29    /* msn服务          */
#define MSA_SERVICE_ICQ        1    /* msn服务           */
#define MSA_SERVICE_FTP        3     /* ftp服务          */
#define MSA_SERVICE_BT         33    /* BT服务           */
#define MSA_SERVICE_QQ         28    /* QQ服务           */
#define MSA_SERVICE_SMB        7    /* QQ服务            */
#define MSA_SERVICE_EMULE      38    /* EMule服务        */
#define MSA_SERVICE_PPLIVE     39    /* pplive服务       */
#define MSA_SERVICE_QQLIVE     40    /* qqlive服务       */

#define MSA_SERVICE_KaZaA      43    /* EMule服务        */
#define MSA_SERVICE_Gnutella   44    /* Gnutella服务       */
#define MSA_SERVICE_WinMX      45    /* WinMX服务       */
#define MSA_SERVICE_XunLei     48    /* 迅雷下载         */
#define MSA_SERVICE_HaoFang    49    /* 浩方对战平台     */
#define MSA_SERVICE_Socks5     50    /* Socks5代理       */
#define MSA_SERVICE_HTTPPROXY  51    /* http代理         */
#define MSA_SERVICE_BF4G       32    /* 边锋4国大战      */
#define MSA_SERVICE_BF5Z       52    /* 边锋5子大战      */
#define MSA_SERVICE_BFZGXQ     53    /* 边锋中国象棋     */
#define MSA_SERVICE_BFXZ       54    /* 边锋游戏下载     */
#define MSA_SERVICE_BAIDU_XB   55    /* 下吧             */
#define MSA_SERVICE_Ares       56    /* Ares             */
#define MSA_SERVICE_SoulSeek   57    /* SoulSeek         */
#define MSA_SERVICE_appleJuice 58    /* appleJuice       */
#define MSA_SERVICE_DirectConnect 59 /* DirectConnect    */
#define MSA_SERVICE_xdcc       60    /* xdcc        */
#define MSA_SERVICE_waste      61    /* waste       */
#define MSA_SERVICE_qqcyclone  62    /* qqcyclone   */
#define MSA_SERVICE_PPStream   63    /* PPStream    */
#define MSA_SERVICE_UUSee      64    /* UUSee       */
#define MSA_SERVICE_feidian    65    /* feidian     */
#define MSA_SERVICE_POCO       66    /* POCO        */
#define MSA_SERVICE_QVOD       67    /* QVOD        */

#define MSA_SERVICE_POPO       71    /* popo        */
#define MSA_SERVICE_UC         72    /* UC          */
#define MSA_SERVICE_PPG        68    /* 屁屁狗      */
#define MSA_SERVICE_totolook   69    /* totolook    */
#define MSA_SERVICE_PPT        70    /* PP点点通    */

#define MSA_SERVICE_SINAGAME   79    /* sina游戏    */
#define MSA_SERVICE_SOHUGAME   80    /* sohu游戏    */

#define MSA_SERVICE_HTTPS      6     /* https    */
#define MSA_SERVICE_QQGAME     81    /* qq游戏   */
#define MSA_SERVICE_UUCALL     97    /* uucall   */
#define MSA_SERVICE_SIP        98    /* SIP协议  */
#define MSA_SERVICE_RTP        99    /* RTP/RTCP */
#define MSA_SERVICE_IRC        11    /* IRC */
#define MSA_SERVICE_Telnet     25    /* telnet */
#define MSA_SERVICE_FeiXin     96    /* 飞信2008 */
#define MSA_SERVICE_sdo        93    /* 盛大 */
#define MSA_SERVICE_BF         15    /* 边锋 */
#define MSA_SERVICE_LZ         27    /* 联众 */
#define MSA_SERVICE_Jabber     95    /* JABBER */


#define MSA_SERVICE_warcraft   90    /* warcraft */
#define MSA_SERVICE_cf         82    /* 穿越火线 */
#define MSA_SERVICE_dnf        83    /* 地下城与勇士 */
#define MSA_SERVICE_tx2        84    /* 天下2 */
#define MSA_SERVICE_mir3       47    /* 传奇3 */
#define MSA_SERVICE_mirs       85    /* 传奇外传 */
#define MSA_SERVICE_jx3        86    /* 剑侠情缘3 */

#define MSA_SERVICE_popkart    89    /* 跑跑卡丁车 */
#define MSA_SERVICE_bnb        91    /* 泡泡堂 */
#define MSA_SERVICE_zt         87    /* 征途 */
#define MSA_SERVICE_rxjh       92    /* 热血江湖 */

#define MSA_SERVICE_MSNPROXY   107   /* MSNPROXY */

/*注册函数库*/
typedef struct corefunList_s{
	char strFunName[64]; /*函数名称*/
  int (*op)();
} corefunList;



typedef struct funList_s{
	unsigned int lFunCode;  /*代码*/
	unsigned int funFlag;   /*0 直接调用 1 dll动态调用 2java类 3应用程序调用*/
	char strNode[32]; /*函数说明*/
	char strFunName[64]; /*函数名称*/
	char strFunUrl[128]; /*dll调用的url*/
	unsigned int  maxruntime;    /*该函数最大处理时间*/
	unsigned int  activeflag;    /*激活相关性 0与激活无关 1与激活相关 */
	unsigned int  rightflag;    /*权限相关性  0与权限无关 1与权限相关  */
  int (*op)();
} funList;

corefunList  _ltcorefunList[NAS_MAX_COREFUNNUM];
funList      _ltfunList[NAS_MAX_FUNNUM];
int          _maxfuntonnum;

typedef struct nasAdmSession_s {
	unsigned long  lSip;       /* 源IP地址     */
	unsigned long  lSid;       /* session id  4位数字  */
	char           lright[MAX_ADMIN_MAXRIGHT+1];     /* 权限       */
	char           caname[64];     /* 权限       */
  char           allgroup[_MAX_ALLGRPNUM];   /* 管理部门   */
  unsigned int   trytimes;
	unsigned long  lasttime;   /*最后一次登陆时间 */
} nasAdmSession;

/*
0:chinese
1:en
*/
typedef struct conListType_s {
    char            conStr[MAX_LANG_LIST_CONSIZE];
} conListType;


typedef struct nasPortInfo_s {
    unsigned long  nPort;             /* 端口 */
    int		   udpLog;       /* 该udp端口是否被记录  3：仅仅监控 2监控并记录 9：免监控 10 禁止访问 */
    int		   tcpLog;       /* 该tcp端口是否被记录  3：仅仅监控 2监控并记录 9：免监控 10 禁止访问   */
    int      isTcplocal;      /* 1 local  0 remote*/
    int      isUdplocal;      /* 1 local  0 remote*/
    int		  srvTcpIn;     /* tcp inbound的service号*/
    int		  srvTcpOut;    /* tcp outbound的service号*/
    int		  srvUdpReceive;    /* udp Receive的service号*/
    int		  srvUdpSend;       /* udp Send的service号*/
} nasPortInfo;

typedef struct msaTopSrv_s {
	char          srvname[MAX_TOPSRVNAME_SIZE];
}msaTopSrv;

typedef struct msaService_s {
    char            srvName[MAX_SRVNAME_SIZE];     /*名字*/
    unsigned char   srvFlag; 	       /*0 系统；1 用户自建*/
    unsigned char   srvProt;         /* 协议6 tcp    17 udp */
    unsigned short  nPortL;          /* 端口号下限    */
    unsigned short  nPortU;          /* 端口号上限    */
    unsigned char   srvDirect;       /* 0:out  1:in   */
    unsigned char   topSrv;        
} msaService;

typedef struct nasFlowInfo_s {
    unsigned long long   srvflow[MAX_TOP_SRVNUM]; 
}nasFlowInfo;

typedef struct nasAllInfo_s {
	  unsigned long   udpconnect; 
    unsigned long   tcpconnect;
    nasFlowInfo  nowFlowInfo;
    nasFlowInfo  hourFlowInfo;  
    nasFlowInfo  dayFlowInfo; 
} nasAllInfo;

typedef struct nasVPathInfo_s { 
    nasFlowInfo  nowFlowInfo;  
    nasFlowInfo  hourFlowInfo;  
    nasFlowInfo  dayFlowInfo; 
} nasVPathInfo;


typedef struct nasQosPathInfo_s {   /*   max static qos    */ 
    uint16       sid;
    char         qosname[64];
    uint32       qosrated;
    uint32       qosrateu;
    uint32       qosmixd;
    uint32       qosmixu;
    nasFlowInfo  nowFlowInfo;  
    nasFlowInfo  hourFlowInfo;  
    nasFlowInfo  dayFlowInfo; 
} nasQosPathInfo;

typedef struct nasGroupInfo_s {  /*   maxgroup 1000    */   
	  unsigned short groupid;  
	  unsigned short pid; 
	  char         name[64];
	  char         mydesc[128]; 
	  unsigned char level;
    nasFlowInfo  nowFlowInfo;  
    nasFlowInfo  hourFlowInfo;  
    nasFlowInfo  dayFlowInfo; 
} nasGroupInfo;

typedef struct nasPolicyInfo_s {   /*   maxpolicy    */ 
	  unsigned int pid;
	  char         pname[48];
	  char         pdesc[64];
    nasFlowInfo  nowFlowInfo;  
    nasFlowInfo  hourFlowInfo;  
    nasFlowInfo  dayFlowInfo; 
} nasPolicyInfo;



typedef struct _snmpgroup{
	char snmpcommunity[32];
	char snmpsip[32];
	char snmpoid[128];
	char snmpv[12];
} SNMPGROUP;

typedef struct _NetArea_s {
	unsigned int ipstart;
	unsigned int ipend;
	int  netflag;
	int  snmpnum;
	char homeurl[255];
	unsigned int groupid;
	unsigned int policyid;
} _pNetArea;

typedef struct nasIpHostInfo_s { /* IP地址的信息    */
    unsigned long   lIp;       /* IP地址    */
    unsigned long   netAreaIndex;       /* last time    */
} nasIpHostInfo;


typedef struct _IpHostInfoHead_s {
	  unsigned int       maxiphost;
	  unsigned int       lIpHostNum;
	  unsigned int       onlineIpHostptr;  /*从头开始的偏移量*/
    unsigned int       onlineIpHostsize;  /*从头开始的偏移量*/
} IpHostInfoHead;

typedef struct nasDbUserInfo_s {     /*用户信息*/
    int32    userid;
    char     username[32];         /*帐号名*/
    char     dispname[32];         /*姓名*/
    unsigned char  Certificate_type;
    char     Certificate_code[24]; 
    unsigned char  sex;
		char     password[32];        
    uint32   groupid[_MAX_GROUPLEVEL];
    char     bindemail[64];
    uint32   bindip; 
    unsigned char  bindmac[6];     /*MAC地址*/
    unsigned char  useflags;
    uint32   ratelimit;  
    unsigned char  ratetype;      /*0共享  1独享*/
    unsigned char  topSrvNameList[MAX_TOP_SRVNUM]; 
    uint32   addtime; 
    uint32   locktime; 
    uint32   lasttime; 
    uint64   lLimitBytes;                  
    uint32   lLimitTimes; 
    uint64   lAllUpFlow;           /*总的上行流量*/
    uint64   lAllDownFlow;         /*总的下行流量*/
    uint32   lAllTime;             /*总的上网时间*/
    uint64   lLimitBytesw;         /*每星期最大的上网流量*/
    uint32   lLimitTimesw;         /*每星期最大的上网时间*/
    uint64   lAllUpFloww;          /*星期的上行流量*/
    uint64   lAllDownFloww;        /*星期总的下行流量*/       
    uint32   lAllTimew;            /*星期总的上网时间*/
    uint64   lLimitBytesm;         /*每月最大的上网流量*/
    uint32   lLimitTimesm;         /*每月最大的上网时间*/           
    uint64   lAllUpFlowm;          /*月总的上行流量*/
    uint64   lAllDownFlowm;        /*月总的下行流量*/   
    uint32   lAllTimem;    	       /*月总的上网时间*/    
    char     moreflag[32];        
    char     policyid[128];               
    uint32   jftype;
    uint32   accountnum;
    uint32   maxpackage;
    uint32   maxBytes;
    uint32   maxudp;               /* 最多udp连接 */ 
    uint32   maxtcp;               /*  最多tcp连接*/
    uint32   maxudpp;              /*  每分最多udp包速率*/
    uint32   maxtcpp;              /*  每分最多tcp包速率*/
    uint32   maxupp;               /*  每分up包速率*/ 
    uint32   maxdownp;             /*  每分down包速率*/  
    uint32   maxsp;                /*  每分128字节小包速率*/ 
    uint32   maxnc;                /*  每分最多新建连接数目*/  
}nasDbUserInfo;

/*
名字的hash索引
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_dbusernamehead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                locksemid;
    int                nownum;
} shm_hash_link_dbusernamehead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_dbusernameindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_dbusernameindex;

typedef struct msaDbUserName_s { 
	  int32    userid;
    char     username[32];         /*帐号名*/
} msaDbUserName;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_onlineusername {
    int             next;
    msaDbUserName   item;
} shm_hash_link_onlineusername;



/*
IP的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_dbuseriphead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                locksemid;
    int                nownum;
} shm_hash_link_dbuseriphead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_dbuseripindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_dbuseripindex;

typedef struct msaDbUserIp_s { 
	  int32    userid;
    int32    ipadd;         /*ipadd*/
} msaDbUserIp;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_onlineuserip {
    int             next;
    msaDbUserIp    item;
} shm_hash_link_onlineuserip;


/*
mac的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_dbusermachead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                locksemid;
    int                nownum;
} shm_hash_link_dbusermachead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_dbusermacindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_dbusermacindex;

typedef struct msaDbUserMac_s { 
	  int32    userid;
    unsigned char  caMac[6];
} msaDbUserMac;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_onlineusermac {
    int             next;
    msaDbUserMac    item;
} shm_hash_link_onlineusermac;


typedef struct _dbUserInfoHead {
    unsigned int    bufptr;
    unsigned int    bufsize;
    unsigned int    bufnum;
} dbUserInfoHead;

 
typedef struct nasOnlieUserInfo_s {     /*用户信息*/
    int32    userid;
    uint32   onlineip;
    unsigned char  onlinemac[6];
    uint32   nowmaxpackage;     /*当前每分数据包*/
    uint64   nowmaxbytes;       /*当前每分流量*/
    uint32   nowmaxudpp;        /*当前每分最多udp包速率*/ 
    uint32   nowmaxtcpp;        /*  当前每分最多tcp包速率*/ 
    uint32   nowmaxupp;         /*  每分up包速率*/ 
    uint32   nowmaxdownp;       /*  每分down包速率*/ 
    uint32   nowmaxsp;          /*  每分128字节小包速率*/ 
    uint32   nowmaxnc;          /*  每分最多新建连接数目*/
    uint32   udpconnect; 
    uint32   tcpconnect; 
    char     nowminute;
	  char     nowhour;
	  int      nowday;
	  nasFlowInfo  nowFlowInfo;  
    nasFlowInfo  hourFlowInfo;  
    nasFlowInfo  dayFlowInfo; 
    uint32   lStartTime;     	/* 本次连接时间开始   */
    uint32   lLastTime;     	/*    */
    int      natflag;
    unsigned short    ident;
    int      natnums;
    int      natcheckm;
    char     firsthomeurl;
    uint32   lLastUpdateTime; /* 上次数据更新时间*/
    unsigned char  nowFlag[6]; /**/
}nasOnlineUserInfo;

/*
mac的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_onlineuserhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                locksemid;
    int                nownum;
} shm_hash_link_onlineuserhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_onlineuserindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_onlineuserindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_onlineuser {
    int             next;
    nasOnlineUserInfo    item;
} shm_hash_link_onlineuser;



typedef struct nasUrlListTmp_s {
	char     url[128];
	unsigned char sort; 
} nasUrlListTmp;

typedef struct nasUrlList_s {
	uint32   urlstart;
	unsigned char urllen;
	unsigned char sort; 
	unsigned short cService; 
} nasUrlList;
/*
mac的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_urlhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    int                locksemid;
    uint32             nownum;
    uint32             urlcontentHead;
    uint32             urlcontentSize;
    uint32             urlcontentNowSize;
} shm_hash_link_urlhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_urlindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_urlindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_url {
    int             next;
    nasUrlList      item;
} shm_hash_link_url;


typedef struct nasTcpBuffer_s {
    uint32         lId;              /* 用户Id  0--没用         */
    unsigned long  lSip;             /* 源IP地址     */
    unsigned long  lDip;             /* 目标IP地址   */
    unsigned short nSport;           /* 源端口号     */
    unsigned short nDport;           /* 目标端口号   */
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后修改时间 */
    uint64	       lBytes[2];        /* 0-上行字节数  1-下行字节数 */
    unsigned char  cType;            /* 协议         */
    unsigned short cService;         /* 服务         */
    int            nUrl;             /* 访问userhttpBuffer的指针   */
    unsigned char  caMac[6];         /* 源Mac地址    */
    unsigned char  cUseFlags;        /* 使用标识 0--没内容 1--有内容 2--已处理 3--已保存   */
    unsigned char  cFlags;           /* 标识 0--正常 1--数据  */
    unsigned long  lCount;           /* 记数器 */
    unsigned char  cDirect;          /* 传输方向*/
    char           keyword1[64];
    char           keyword2[128];
    char           keyword3[32];
    unsigned int   keyword4;
    unsigned long  fdCount;        
    unsigned long  seq;
    char           cMatchRule;       
    char           procdev;           /*dev 1-3  */
    unsigned int   ssnid[2];
} nasTcpBuffer;

/*
mac的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_TcpBufferhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    int                locksemid;
    uint32             nownum;
} shm_hash_link_TcpBufferhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_TcpBufferindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_TcpBufferindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_TcpBuffer {
    int             next;
    nasTcpBuffer    item;
} shm_hash_link_TcpBuffer;


typedef struct nasHttpBuffer_s {
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后访问时间     */
    uint64	       lBytes;           /* 流量         */
    char           caHost[64];
    unsigned long  lCount;           /* 次数         */
    unsigned long  lTime;            /*      */
    unsigned char  cUrlSort[5];         /*      */
} nasHttpBuffer;
/*
mac的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_HttpBufferhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    int                locksemid;
    uint32             nownum;
} shm_hash_link_HttpBufferhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_HttpBufferindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_HttpBufferindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_HttpBuffer {
    int             next;
    nasHttpBuffer   item;
} shm_hash_link_HttpBuffer;


typedef struct nasDipBuffer_s {
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后访问时间     */
    uint64	       lBytes;           /* 流量         */
    uint32         ldip;
    unsigned long  lCount;           /* 次数         */
    unsigned long  lTime;            /*      */
    unsigned short cService;         /* 服务         */
} nasDipBuffer;
/*
mac的hash索引 
hash 基于分离链解决冲突的链表
freecon 单链表解决办法,最后一个的标记为next=-1
*/
typedef struct _shm_hash_link_DipBufferhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    int                locksemid;
    uint32             nownum;
} shm_hash_link_DipBufferhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_DipBufferindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_DipBufferindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_DipBuffer {
    int             next;
    nasDipBuffer    item;
} shm_hash_link_DipBuffer;


typedef struct nas2SrvInfo_s {
    unsigned long  lDip;             /* 目标IP地址   */
    unsigned short nDport;           /* 目标端口号   */
    unsigned char  cType;            /* 协议         */
    unsigned long  lLastTime;        /* 最后修改时间 */
    unsigned short cService;         /* 服务         */
} nas2SrvInfo;

typedef struct _shm_hash_link_2SrvInfohead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    int                locksemid;
    uint32             nownum;
} shm_hash_link_2SrvInfohead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_2SrvInfoindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_2SrvInfoindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_2SrvInfo {
    int             next;
    nas2SrvInfo     item;
} shm_hash_link_2SrvInfo;

typedef struct nasUrlSort_s {
	int           sortid;
	char          sortname[48];
}nasUrlSort;

#define NAS_MAXSCH_NUM       20
typedef struct nasschtime_s {
	int           schid;
	char          ruleschtime[400];
}nasschtime;

#define NAS_MAXJJR_NUM       20
typedef struct nasjjrtime_s {
	int           jjrid;
	char          jjrtime[370];
}nasjjrtime;

/*服务限制规则,处理方法是遍例*/
/*
优先级是：
处理方式是如果找到规则就结束
*/

typedef struct msasrvrulehead_s {
	  unsigned int       srvruleptr;  /*从头开始的偏移量*/
    unsigned int       srvrulesize;  /*从头开始的偏移量*/
    unsigned int       lMaxServiceRuleDIp;
    unsigned int       srvruledipptr;  /*从头开始的偏移量*/
    unsigned int       srvruledipsize;  /*从头开始的偏移量*/
    unsigned int       lMaxRuleIp;
    unsigned int       srvruleipptr;  /*从头开始的偏移量*/
    unsigned int       srvruleipsize;  /*从头开始的偏移量*/
    unsigned int       lMaxWebRule;
    unsigned int       webruleptr;  /*从头开始的偏移量*/
    unsigned int       webrulesize;  /*从头开始的偏移量*/
    unsigned int       lMaxWebPostRule;
    unsigned int       webpostruleptr;  /*从头开始的偏移量*/
    unsigned int       webpostrulesize;  /*从头开始的偏移量*/
    unsigned int       lMaxWebTypeRule;
    unsigned int       webtyperuleptr;  /*从头开始的偏移量*/
    unsigned int       webtyperulesize;  /*从头开始的偏移量*/
    unsigned int       webruleurlsize;  /*从头开始的偏移量*/
}msasrvrulehead;


typedef struct nasSrvRule_s {
    unsigned long   ruleid;          /* 规则编号 */
    char            rulename[32];
    char	    			ruleaction;      /*0拒绝    1：允许*/
    int    					qosid;
    unsigned long   ruleschedule;    /*该规则的schedule*/
    char            ruleurlsort[101];
    unsigned long   rulejrid;        /*该规则的schedule*/
    char            ruleurl[128];    /*url*/
    int    					logaction;
    int    					conaction;
    uint32   				srvlist[MAX_SYS_SRVNUM]; /*服务的array 索引开始位置*/
    uint32    		  pid[_MAX_ALLPOLICY];     /*系统的策略id*/
    uint32   				userlistptr;             /*用户array的索引开始位置*/
    long   					grouplist[_MAX_ALLGRPNUM];  /*用户组array的索引开始位置*/
    long   					ipStart;         /*ip地址段array的索引开始位置*/
    long   					ipEnd;
    unsigned long   urlStart;	       /*url列表 array的索引开始位置*/
    unsigned long   urlEnd;
    unsigned long   postStart;	     /*post列表 array的索引开始位置*/
    unsigned long   postEnd;    
    unsigned long   typeStart;	     /*type列表 array的索引开始位置*/
    unsigned long   typeEnd; 
    long   					dipStart;	       /*目标ip地址段array的索引开始位置*/
    long   					dipEnd;   
    unsigned int    urlcheck;
    nasFlowInfo  nowFlowInfo;  
    nasFlowInfo     hourFlowInfo;  
    nasFlowInfo     dayFlowInfo;           
} nasSrvRule;


/*服务控制规则的目标ip地址组，处理方法是array 遍例*/
typedef struct nasSrvRuleDIp_s {
    long   	    ruleid;       /* 规则编号 */
    unsigned long   ipstart;      /*ip段开始地址*/
    unsigned long   ipend;        /*ip段结束地址*/
} nasSrvRuleDIp;

/*web控制规则的ip地址组，处理方法是array 遍例*/
typedef struct nasRuleUrl_s {
    long   	    ruleid;       /* 规则编号 */
    char        caUrl[64];      /*url列表*/
} nasRuleUrl;

/*web控制规则的ip地址组，处理方法是array 遍例*/
typedef struct nasRulePost_s {
    long   	    ruleid;       /* 规则编号 */
    char        caUrl[64];      /*url列表*/
} nasRulePost;

/*web控制规则的ip地址组，处理方法是array 遍例*/
typedef struct nasRuleType_s {
    long   	    ruleid;       /* 规则编号 */
    char        caUrl[64];      /*url列表*/
} nasRuleType;


/*控制规则的ip地址组，处理方法是array 遍例*/
typedef struct nasRuleIp_s {
    long   	    ruleid;       /* 规则编号 */
    unsigned long   ipstart;      /*ip段开始地址*/
    unsigned long   ipend;        /*ip段结束地址*/
} nasRuleIp;

typedef struct msaPubInfo_s {
	  unsigned int  lRunning;
	  char          updateflag[32];     /*更新位标志 */
	  char          _dbname[128];
	  char          _dbuser[128];
	  char          _dbpass[128];
	  int           sysActive;
	  int           maxfuntonnum;
	  int           msaGeneralHour;
	  nasAdmSession      admSession[MAX_ADMIN_SESSION];
	  conListType        pubMsgStr[MAX_SYSTEM_MSG];
	  int                defaultLan;    /*默认语言*/ 
	  msaTopSrv          topSrvName[MAX_TOP_SRVNUM]; 
	  unsigned int       lServiceNum;
	  msaService         ltService[MAX_SYS_SRVNUM]; /*0:unknown 1-400:sys  401-499:user*/
	  nasUrlSort         _urlSortlist[NAS_MAXURLSORT_NUM]; 
	  nasschtime         _schtimelist[NAS_MAXSCH_NUM];
	  nasjjrtime         _jjrtimelist[NAS_MAXJJR_NUM];
	  nasPortInfo        ltPortInfo[MAX_PORTNUM];
	  _pNetArea          ltNetArea[_MAXNETAREANUM];  /*全部网络对象 */
	  _pNetArea          NetAreaCkeck[_MAXNETAREANUM];   /*大网络对象  */ 
	  SNMPGROUP          ltSnmpGroup[_MAXSNMPNUM];
	  nasAllInfo         _AllInfo;
	  nasVPathInfo			 _VPathList[_MAXVPATHNUM];
	  nasQosPathInfo		 _QosList[_MAX_QOSSTATIC_CHANEL];
	  nasGroupInfo	     _GroupList[_MAX_ALLGRPNUM];
	  nasPolicyInfo	     _PolicyList[_MAX_ALLPOLICY];
	  nasSrvRule         _Srvrulelist[_MAX_SRVRULE_NUM];
    IpHostInfoHead     _iphostinfohaed;
    dbUserInfoHead     _dbUserInfoHead;
    shm_hash_link_dbusernamehead  _dbusernamehead; 
    shm_hash_link_dbuseriphead    _dbuseriphead; 
    shm_hash_link_dbusermachead   _dbusermachead; 
    shm_hash_link_onlineuserhead  _onlineuserhead;
    shm_hash_link_urlhead         _urlhashhead;
    shm_hash_link_TcpBufferhead   _tcpsessionhead;
    shm_hash_link_HttpBufferhead  _httpbufferhead;
    shm_hash_link_DipBufferhead   _dipbufferhead;
    shm_hash_link_2SrvInfohead    _2SrvInfohead; 
    msasrvrulehead                _srvrulehead;
}msaPubInfo;

/*
*/
msaPubInfo  *_ltPubInfo;
ltDbConn     *G_DbCon; /*各个包处理进程的数据库连接*/

typedef struct msasDir_s {
    char   caDirName[128];
    char   caDirPath[256];
    int    dirTime;    
} msasDir;

typedef struct jiffy_counts_t {
	unsigned long long usr,nic,sys,idle,iowait,irq,softirq,steal;
	unsigned long long total;
	unsigned long long busy;
} jiffy_counts_t;


lt_shmHead *msacreateShmMem(unsigned int intShmKey,unsigned int intMaxShmSize);
lt_shmHead *msaopenShmMem(unsigned int intShmKey,unsigned int intMaxShmSize);
int msacloseShmMem(lt_shmHead *lt_MMHead);

/*nasPubUtil.c*/
unsigned int get3wordsHash(unsigned int a, unsigned int b, unsigned int c);
unsigned int getMacHash(unsigned char *caMac);
unsigned int  msa_ssn_hash(unsigned int sip, unsigned int  dip,unsigned short  sport,unsigned short dport,int  protocol);
unsigned int getStringHash(unsigned char *caStr,unsigned int strLen);
int msaInitPubInfo(lt_shmHead *lt_MMHead);
int ltWebMsgErr(char *errorMsg,int confd,ltMsgHead *ltMsgPk);
int msaInitPubVar(lt_shmHead *lt_MMHead);
int logWrite(ltMsgHead *ltMsgPk,char *msg,int msgtype);
int nasTimeFormat(char *pFormat,long lTime);
int checkRight(int confd,ltMsgHead *ltMsgPk,int right);
int strgb2utf8(const char *cpInput,char *cpOut,int iInputLen);
int pubGetName(char *caKey,int start,int end,char *caGetName);
int dirtimecmp(msasDir* a,msasDir* b);
msasDir* mydirlist(char* dir,int* len);
int nasTimeGetDate(char *cDate,long lTime);
unsigned long nasCvtLongTime(char *caSdate,char *caTime);
int nasTimeLongFormat(char *pFormat,long lTime);
int nasCvtStime(unsigned long lTime,char *caDate,char *caTime);
char *nasCvtMac(unsigned char *caMac,char *caMacStr);
int nasCvtMacI(unsigned char *caMacStr,unsigned char *caMac);
int msaReportList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaDataCenetrDownLoad(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int sysHasBeenActive();
int  ReadCpu(char *cpuName);
int readDisk(char * DiskInfo);
int ReadEth0Mac(char *strHadd);
void striptrailingwhitespace(stralloc *sa);

/*msaService.c*/
int msaInitPortInfo(lt_shmHead *lt_MMHead);
int nasInitTopService(lt_shmHead *lt_MMHead);
int msaInitServiceArray(lt_shmHead *lt_MMHead);

/*msaIpHost.c*/
int nasInitIpHostInfo(lt_shmHead *lt_MMHead);


/*dbUserLib.c*/
int msaInitDbUserList(msaPubInfo  *ltPubInfo);
int msaHashInsertDbUser(msaPubInfo  *ltPubInfo, nasDbUserInfo *item);
int msaHashDelDbUser(msaPubInfo  *ltPubInfo, nasDbUserInfo *item);
nasDbUserInfo *msaLookUpDbUserById(msaPubInfo  *ltPubInfo,unsigned int userid );
nasDbUserInfo *msaLookUpDbUserByIp(msaPubInfo  *ltPubInfo,unsigned int ipadd );
nasDbUserInfo *msaLookUpDbUserByName(msaPubInfo  *ltPubInfo,char *username );
nasDbUserInfo *msaLookUpDbUserByMac(msaPubInfo  *ltPubInfo,char *caMac );
unsigned int msaGetFreeUserid(msaPubInfo  *ltPubInfo);

/*OlineUserLib.c*/
int msaInitOnlineUserHash(msaPubInfo  *ltPubInfo);
nasOnlineUserInfo *msaHashInsertOnlineUser(msaPubInfo  *ltPubInfo, nasOnlineUserInfo *item);
nasOnlineUserInfo *msaHashLookUpOnlineUser(msaPubInfo  *ltPubInfo,unsigned int ipadd);
int msaDeleteOnlineUser(msaPubInfo  *ltPubInfo,unsigned int ipadd);

/*msaUrllist.c*/
nasUrlList *msaHashLookUpUrl(msaPubInfo  *ltPubInfo,char *strurl);
int nasInitUrlList(lt_shmHead *lt_MMHead);

/*msaTcpSession.c*/
int msaInitTcpBufferHash(msaPubInfo  *ltPubInfo);
nasTcpBuffer *msaHashInsertTcpBuffer(msaPubInfo  *ltPubInfo,unsigned int ssnhash, nasTcpBuffer *item);
nasTcpBuffer *msaHashLookUpTcpSession(msaPubInfo  *ltPubInfo,unsigned int ssnhash, nasTcpBuffer *item);
int msaDeleteTcpSession(msaPubInfo  *ltPubInfo,unsigned int ssnhash, nasTcpBuffer *item);


/*msaHttpBuffer.c*/
int msaInitHttpBufferHash(msaPubInfo  *ltPubInfo);
nasHttpBuffer *msaHashInsertHttpBuffer(msaPubInfo  *ltPubInfo,nasHttpBuffer *item);
nasHttpBuffer *msaHashLookUpHttpBuffer(msaPubInfo  *ltPubInfo,char *caHost);
int msaDeleteHttpBuffer(msaPubInfo  *ltPubInfo, char *caHost);

/*msaDipBuffer.c*/
int msaInitDipBufferHash(msaPubInfo  *ltPubInfo);
nasDipBuffer *msaHashInsertDipBuffer(msaPubInfo  *ltPubInfo,nasDipBuffer *item);
nasDipBuffer *msaHashLookUpDipBuffer(msaPubInfo  *ltPubInfo,unsigned int ldip);
int msaDeleteDipBuffer(msaPubInfo  *ltPubInfo, unsigned int ldip);

/*msa2SrvInfo.c*/
int msaInit2SrvInfoHash(msaPubInfo  *ltPubInfo);
nas2SrvInfo *msaHashInsert2SrvInfo(msaPubInfo  *ltPubInfo,nas2SrvInfo *item);
nas2SrvInfo *msaHashLookUp2SrvInfo(msaPubInfo  *ltPubInfo,unsigned int lDip,unsigned int nDport,unsigned int cType);
int msaDelete2SrvInfo(msaPubInfo  *ltPubInfo, unsigned int lDip,unsigned int nDport,unsigned int cType);



/*srv-admin.c*/
int msaShowAdminLogon(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdminLogon(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdminLogout(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowTopview(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-group.c*/
int msalooparea(stralloc *strTemp,int level,int pid);
int msaGroupTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-manager.c*/
int msaAdminUserList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdminAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdmuserList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaCheckOutAdmin(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdmlog(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaSysReset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaSysShutdown(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ltnetareaaction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltnetarealist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowArea(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ltportinfolist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltportinfoaction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltapplyportinfo(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*srv-users.c*/
int msaShowAddClient(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaTerminfoAdd(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowClientList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaClientList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPolicyTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaServiceTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaTermInfoView(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaTerminfoUp(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*srv-data.c*/
int msaShowAccessList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowAccessSearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAccessList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaBackListDownLoadCSV(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltmsasearchkeyquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//关键字检索
int msaipbacksearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//保存与导出数据
int msaNewSearchList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//gird数据载入和删除
int ltshowservicequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//服务访问记录汇总节点链接
int ltwebshowwebsitequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//HTTP服务汇总节点链接
void striptrailingwhitespace(stralloc *sa);//删除空白符号
int ltimshowwebquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//QQ/msn
int ltmsasearchkeyhttpa(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//关键字列表表单提交
unsigned long msaCvtLongTime(char *caSdate,char *caTime);//时间转换
int msaCvtStime(unsigned long lTime,char *caDate,char *caTime);

#endif


