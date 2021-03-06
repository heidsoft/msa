
#ifndef __MSADEF__
#define __MSADEF__


#include <netinet/ether.h>
#include "pubfun.h"


/*部门层次级别*/
#define _MAX_GROUPLEVEL    5
/*全部部门总数*/
#define _MAX_ALLGRPNUM     1000
#define _MAX_ALLPOLICY     128
#define _MAXSNMPNUM        7
#define _MAX_BIGAREANUM    100
#define _MAXNETAREANUM     1000
#define _MAXVPATHNUM       6
#define _MAXDEVNUM         12
#define _MAX_QOSSTATIC_CHANEL    1000
#define NAS_MAXURLLIST_NUM       200000
//#define NAS_MAXURLSORT_NUM       100
#define _MAX_SRVRULE_NUM    64
#define _MAX_USERPOLICY_NUM    64
#define _MAX_CONTENTTYPE_NUM   750
#define NAS_MAXTOPURLSORT_NUM  24

#define MAX_FIREWALL_NUM		64

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

#define MAX_SRVNAME_SIZE    64
#define MAX_TOPSRVNAME_SIZE    64
#define MAX_TOP_SRVNUM      35
#define MAX_SYS_SRVNUM      500
#define MAX_SYS_SRVNUM_SYS  469
#define MAX_PORTNUM         65536
#define NAS_MAX_HOURMIN     5  

#define _pubconfdir   "/etc/msa/msa"
#define _SERVICE   "/etc/msa/msa"
#define _datacenterdir   "/datacenter/msa"
#define _proccessdir   "/datacenter/proccess"
#define _msahtmldir    "/app/msa/msa/htmlplt"
#define _TMPDIR   "/datacenter/tmp"

#define _MSA_MAIL_BOUND   "----MSAMAILFILEBAOCHUANG----"
#define _MSA_FORM_BOUND   "----MSAFORMFILEBAOCHUANG----"

#define NAS_PROTOCOL_TCP 6    /*tcp协议*/
#define NAS_PROTOCOL_UDP 17   /*udp协议*/ 

#define NAS_NETWORK_NOMAL          0    /* 正常  */
#define NAS_NETWORK_IPBASE         1    /* 基于IP地址  */
#define NAS_NETWORK_MACBASE        2    /* 基于mac地址 */
#define NAS_NETWORK_HOSTBASE       3    /* 基于主机名称*/
#define NAS_NETWORK_PPPOEBASE      4    /* 基于PPPOE验证*/
#define NAS_NETWORK_NOAUTHCLIENT   8    /* 客户端免限制免验证 */
#define NAS_NETWORK_NOAUTHSERVER   9   /* 服务器免限制免验证 */

#define NAS_NETWORK_NTAUTH         21    /* 域验证  */
#define NAS_NETWORK_NTAUTHHEAD     22    /* 心跳机制域验证  */

#define NAS_NETWORK_LOCALAUTH      23    /* 本机web验证*/
#define NAS_NETWORK_LOCALAUTHHEAD  24    /* 心跳机制本机web验证*/
#define NAS_NETWORK_LOCALAUTHCLIENT  25  /* client验证*/


#define NAS_NETWORK_LDAPAUTHBASE        26    /* 基于LDAP验证同步*/
#define NAS_NETWORK_LDAPAUTHBASEHEAD    27    /* 心跳机制基于LDAP验证同步web*/
#define NAS_NETWORK_LDAPAUTHBASECLIENT  28    /* client基于LDAP验证同步*/
#define NAS_NETWORK_RADUSAUTHBASE       29    /* 基于RADUS验证同步*/
#define NAS_NETWORK_RADUSAUTHBASEHEAD   30    /* 基于RADUS验证同步web*/
#define NAS_NETWORK_RADUSAUTHBASECLIENT 31    /* 基于RADUS验证同步client*/


#define NAS_NETWORK_IPCLIENT       41    /* IP客户端锁定*/
#define NAS_NETWORK_MACCLIENT      42    /* MAC客户端锁定 */
#define NAS_NETWORK_HOSTCLIENT     43    /* 主机名客户端锁定 */

#define NAS_NETWORK_OUT            90    /* 外部地址特殊功能服务器，如代理服务器等*/

#define NAS_NETWORK_NOMON          99    /* 免监控     */
#define NAS_NETWORK_NOACCESS       100    /* 禁止网络访问*/

#define NAS_NETWORK_LOCAL	  		1
#define NAS_NETWORK_EXTERNAL	  2
#define NAS_SYS_ERROR         -1 /*系统出现的错误*/
#define NAS_GET_USER		      1  /*得到用户*/

#define   NAS_CONTENT_HEAD     9
#define   NAS_CONTENT_GET      10
#define   NAS_CONTENT_POST     11
#define   NAS_CONTENT_POSTCHECKFILE     12
#define   NAS_CONTENT_POSTPRE  110
#define   NAS_CONTENT_MSNMSG   12
#define   NAS_CONTENT_QQ       13
#define   NAS_CONTENT_XunLei   14
#define   NAS_CONTENT_HTTPPROXY   15
#define   NAS_CONTENT_SMTP     21
#define   NAS_CONTENT_POP3     23

#define MSA_SERVICE_UNKNOWN    0     /* 其它服务             */
#define MSA_SERVICE_HTTP       50    /* Web服务              */
#define MSA_SERVICE_HTTPMUTI   130    /* HTTP多进程下载              */
#define MSA_SERVICE_HTTPERROR  131    /* 非标准http数据访问              */

#define MSA_SERVICE_HTTPCOM   47    /* com  */
#define MSA_SERVICE_HTTPCN    48    /* cn   */
#define MSA_SERVICE_HTTPNET   49    /* .net */

#define MSA_SERVICE_HTTPMAIL   6    /* 邮箱网站              */
#define MSA_SERVICE_POSTMAIL   51    /* webmail提交              */
#define MSA_SERVICE_HTTPCHAT   16    /* 聊天、交友网站              */
#define MSA_SERVICE_POSTCHAT   53    /* 聊天、交友网站提交              */
#define MSA_SERVICE_HTTPBBS    17    /* 论坛、社区网站网站              */
#define MSA_SERVICE_POSTBBS    52    /* 论坛、社区网站提交              */

#define MSA_SERVICE_CONFLV     100    /* 在线FLV播放*/
#define MSA_SERVICE_CONMP3     101    /* mp3*/
#define MSA_SERVICE_CONAVI     102    /* HTTP-AVI下载*/

#define MSA_SERVICE_CONRM      103    /* rm */
#define MSA_SERVICE_CONMP4     104    /* mp4*/
#define MSA_SERVICE_CON3gp     105    /* 3gp*/

#define MSA_SERVICE_AUDIO     109    /* HTTP音频文件数据流*/
#define MSA_SERVICE_VEDIO     110    /* HTTP视频文件数据流*/




#define MSA_SERVICE_CONJS      111    /* HTTP-javascript数据*/
#define MSA_SERVICE_CONXML     112    /* HTTP-xml*/
#define MSA_SERVICE_octeo      116    /* 其他应用数据流或下载*/

#define MSA_SERVICE_CONRAR     117    /* rar*/
#define MSA_SERVICE_CONZIP     118    /* zip数据*/
#define MSA_SERVICE_CONTGZ     119    /* TGZ压缩包*/
#define MSA_SERVICE_CONPDF     120    /* pdf */
#define MSA_SERVICE_CONO2003   121    /* HTTP-word等office2003文件下载*/
#define MSA_SERVICE_CONO2007   122    /* HTTP-word等office2010文件下载*/
#define MSA_SERVICE_CONEXE     123    /* exe*/
#define MSA_SERVICE_octe       129    /* HTT其他二进制流下载*/



#define MSA_SERVICE_CONBMP     132    /* bmp*/
#define MSA_SERVICE_CONGIF     133    /* GIF图片*/
#define MSA_SERVICE_CONJPG     134    /* JPEG图片*/
#define MSA_SERVICE_CONPNG     135    /* PNG图片*/
#define MSA_SERVICE_CONFLASH   136    /* flash*/
#define MSA_SERVICE_CONIMAGE     140    /* 其他HTTP-Image流*/


#define MSA_SERVICE_SMTP       290    /* SMTP服务            */
#define MSA_SERVICE_POP3       291    /* POP服务             */
#define MSA_SERVICE_HTTPSRV    250    /* 本地Web服务      */
#define MSA_SERVICE_SMTPSRV    251    /* 本地SMTP服务     */
#define MSA_SERVICE_POP3SRV    252    /* 本地POP服务      */
#define MSA_SERVICE_HTTPSSRV   253    /* 本地POP服务      */
//
#define MSA_SERVICE_MSN        170    /* msn服务          */
#define MSA_SERVICE_MSNFILE    171    /* msn发文件        */
#define MSA_SERVICE_MSNYC      172    /* msn远程协助      */
#define MSA_SERVICE_MSNYP      173    /* msn音视频        */

#define MSA_SERVICE_YAHOO      176    /* yahoo服务          */
#define MSA_SERVICE_ICQ        186    /* icq服务           */

#define MSA_SERVICE_FTP        240    /* ftp服务          */
#define MSA_SERVICE_FTPDATA    241    /* ftp服务          */
#define MSA_SERVICE_UPDATA     242    /* ftp服务          */
#define MSA_SERVICE_DOWNDATA   243    /* ftp服务          */

#define MSA_SERVICE_BT         211    /* BT服务           */

#define MSA_SERVICE_QQ         162    /* QQ服务           */
#define MSA_SERVICE_QQTCP      163    /* QQ-tcp服务       */
#define MSA_SERVICE_QQHTTPS    164    /* QQ-https服务     */
#define MSA_SERVICE_QQSP       165    /* qq视频会话       */
#define MSA_SERVICE_QQYP       166    /* qq视频会话       */
#define MSA_SERVICE_QQWJ       167    /* qq传文件         */
#define MSA_SERVICE_QQYC       168    /* qq远程协助       */
#define MSA_SERVICE_QQDX       169    /* qq发短信         */

#define MSA_SERVICE_UC         181    /* UC          */
#define MSA_SERVICE_POPO       180    /* popo        */

#define MSA_SERVICE_WWWJCS     178    /* 旺旺文件传输 */

#define MSA_SERVICE_STUN       200    /* stun         */


#define MSA_SERVICE_SMB        263    /* smb            */
#define MSA_SERVICE_EMULE      212    /* EMule服务        */
#define MSA_SERVICE_PPLIVE     222    /* pplive服务       */
#define MSA_SERVICE_QQLIVE     223    /* qqlive服务       */
//

#define MSA_SERVICE_WinMX      216    /* WinMX服务       */
#define MSA_SERVICE_XunLei     210    /* 迅雷下载         */
#define MSA_SERVICE_HaoFang    377    /* 浩方对战平台     */
#define MSA_SERVICE_Socks5     312    /* Socks5代理       */
#define MSA_SERVICE_HTTPPROXY  311    /* http代理         */
//#define MSA_SERVICE_BF4G       32    /* 边锋4国大战      */
//#define MSA_SERVICE_BF5Z       52    /* 边锋5子大战      */
//#define MSA_SERVICE_BFZGXQ     53    /* 边锋中国象棋     */
//#define MSA_SERVICE_BFXZ       54    /* 边锋游戏下载     */
#define MSA_SERVICE_BAIDU_XB   215    /* 下吧             */
//#define MSA_SERVICE_Ares       56    /* Ares             */
//#define MSA_SERVICE_SoulSeek   57    /* SoulSeek         */
//#define MSA_SERVICE_appleJuice 58    /* appleJuice       */
//#define MSA_SERVICE_DirectConnect 59 /* DirectConnect    */
//#define MSA_SERVICE_xdcc       60    /* xdcc        */
//#define MSA_SERVICE_waste      61    /* waste       */
#define MSA_SERVICE_qqcyclone  214    /* qqcyclone   */
#define MSA_SERVICE_PPStream   224    /* PPStream    */
#define MSA_SERVICE_UUSee      225    /* UUSee       */
#define MSA_SERVICE_QVOD       227    /* QVOD        */
//
#define MSA_SERVICE_PPG        229    /* 屁屁狗      */
//#define MSA_SERVICE_totolook   69    /* totolook    */
//#define MSA_SERVICE_PPT        70    /* PP点点通    */
//
//#define MSA_SERVICE_SINAGAME   79    /* sina游戏    */
//#define MSA_SERVICE_SOHUGAME   80    /* sohu游戏    */
//
#define MSA_SERVICE_HTTPS      160     /* https    */
#define MSA_SERVICE_QQGAME     375    /* qq游戏   */
#define MSA_SERVICE_UUCALL     202    /* uucall   */
#define MSA_SERVICE_SIP        196    /* SIP协议  */
#define MSA_SERVICE_RTP        197    /* RTP/RTCP */
#define MSA_SERVICE_RSTP       199    /* RSTP */
//#define MSA_SERVICE_IRC        11    /* IRC */
#define MSA_SERVICE_Telnet     302    /* telnet */
#define MSA_SERVICE_FeiXin     182    /* 飞信2008 */
//#define MSA_SERVICE_sdo        93    /* 盛大 */
//#define MSA_SERVICE_BF         15    /* 边锋 */
#define MSA_SERVICE_LZ         374    /* 联众 */
//#define MSA_SERVICE_Jabber     95    /* JABBER */
//
//
#define MSA_SERVICE_warcraft   394    /* warcraft */
#define MSA_SERVICE_cf         387    /* 穿越火线 */
#define MSA_SERVICE_dnf        388    /* 地下城与勇士 */
#define MSA_SERVICE_tx2        389    /* 天下2 */
#define MSA_SERVICE_mir3       386    /* 传奇3 */
#define MSA_SERVICE_mirs       390    /* 传奇外传 */
#define MSA_SERVICE_jx3        391    /* 剑侠情缘3 */
//
#define MSA_SERVICE_popkart    393    /* 跑跑卡丁车 */
#define MSA_SERVICE_bnb        395    /* 泡泡堂 */
#define MSA_SERVICE_zt         392    /* 征途 */
#define MSA_SERVICE_rxjh       396    /* 热血江湖 */
//
//#define MSA_SERVICE_MSNPROXY   107   /* MSNPROXY */

#define MSA_SERVICE_POSTRAR       60    /* HTTP-RAR文件上传 */
#define MSA_SERVICE_POSTZIP       61    /* HTTP-Zip文件上传 */
#define MSA_SERVICE_POSTTGZ       62    /* HTTP-TGZ文件上传 */
#define MSA_SERVICE_POSTWORD      63    /* HTTP-WORD文件上传 */
#define MSA_SERVICE_POSTExcel     64    /* HTTP-Excel文件上传 */
#define MSA_SERVICE_POSTPDF       65    /* HTTP-PDF文件上传 */
#define MSA_SERVICE_POSTPPT       66    /* HTTP-PPT文件上传 */
#define MSA_SERVICE_POSTTXT       67    /* HTTP-TXT文件上传 */
#define MSA_SERVICE_POSTExe       68    /* HTTP-Exe文件上传 */
#define MSA_SERVICE_POSTJPG       69    /* HTTP-JPG文件上传 */
#define MSA_SERVICE_POSTGif       70    /* HTTP-Gif文件上传 */
#define MSA_SERVICE_NOEXTPOSTFILE       74    /* HTTP-无拓展名名文件上传 */
#define MSA_SERVICE_OTHERPOSTFILE       75    /* HTTP其他文件上传 */

#define MSA_SERVICE_HTWTJY       330    /* 海通委托交易*/
#define MSA_SERVICE_DZH          321    /* 大智慧股票软件 */



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
	char           lright[MAX_ADMIN_MAXRIGHT];     /* 权限       */
	char           caname[64];     /* 权限       */
  char           allgroup[_MAX_ALLGRPNUM+1];   /* 管理部门   */
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
    short    srcTcpInList[8]; //后续服务检查列表，做进一步的检查
    short    srvTcpOutList[8];
    short    srvUdpReceiveList[8];
    short    srvUdpSendList[8];
} nasPortInfo;

typedef struct msaTopSrv_s {
	char          srvname[MAX_TOPSRVNAME_SIZE];
}msaTopSrv;

typedef struct msaService_s {
	  short           srvid;     /*名字*/
    char            srvName[MAX_SRVNAME_SIZE];     /*名字*/
    char            descName[MAX_TOPSRVNAME_SIZE];     /*名字*/
    unsigned char   srvFlag; 	       /*0 系统；1 用户自建*/
    unsigned char   srvProt;         /* 协议6 tcp    17 udp */
    unsigned short  nPortL;          /* 端口号下限    */
    unsigned short  nPortU;          /* 端口号上限    */
    unsigned char   srvDirect;       /* 0:out  1:in   */
    unsigned char   topSrv;
    unsigned char   syssrvcheck;     /*是否需要系统特征检查 */    
    unsigned char   denytype;        /*是否需要系统特征检查 */  
    unsigned char   level;           /*level：系统危害的程度*/  
    unsigned char   httpload;        /*0 非httpload；1 httpload  2:both */
    char            srvcon[512];     //协议列表特征,祥见协议特征列表，对自定义协议适用
} msaService;


typedef struct nasFlowInfo_s {
	  unsigned long long   allflow[2]; 
    unsigned long long   srvflow[MAX_TOP_SRVNUM]; 
}nasFlowInfo;

typedef struct nasFlowHourInfo_s {
	  unsigned long long   allflow[2]; 
    unsigned long long   srvflow[MAX_TOP_SRVNUM]; 
    unsigned long srvtime[MAX_TOP_SRVNUM]; 
    unsigned long srvlasttime[MAX_TOP_SRVNUM]; 
}nasFlowHourInfo;

typedef struct nasFlowDayInfo_s {
	  unsigned long long   allflow[2]; 
	  unsigned int  alltime;
	  unsigned int  alllasttime;
    unsigned long long   srvflow[MAX_TOP_SRVNUM]; 
    unsigned long srvtime[MAX_TOP_SRVNUM]; 
    unsigned long srvlasttime[MAX_TOP_SRVNUM]; 
}nasFlowDayInfo;

typedef struct nasAllInfo_s { 
	  unsigned long   udpconnect; 
    unsigned long   tcpconnect;
    nasFlowInfo     nowFlowInfo;
    nasFlowHourInfo hourFlowInfo;
    nasFlowDayInfo  dayFlowInfo; 
}nasAllInfo;

typedef struct nasVPathInfo_s { 
	  char            vPathName[128];
    nasFlowInfo     nowFlowInfo;  
    nasFlowDayInfo  dayFlowInfo; 
} nasVPathInfo;


typedef struct nasQosPathInfo_s {   /*   max static qos    */ 
    uint16       sid;
    char         qosname[64];
    uint32       qosrated;
    uint32       qosrateu;
    uint32       qosmixd;
    uint32       qosmixu;
    nasFlowInfo  nowFlowInfo;  
    nasFlowDayInfo  dayFlowInfo; 
} nasQosPathInfo;

typedef struct nasGroupInfo_s {  /*   maxgroup 1000    */   
	  unsigned short groupid;  
	  unsigned short pid; 
	  char         name[64];
	  char         mydesc[128]; 
	  unsigned char level;
    nasFlowInfo  nowFlowInfo;  
    nasFlowDayInfo  dayFlowInfo; 
} nasGroupInfo;

typedef struct nasPolicyInfo_s {   /*   maxpolicy    */ 
	  unsigned int pid;
	  char         pname[48];
	  char         pdesc[64];
} nasPolicyInfo;


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

#define MSA_DBUSER_FLAG_FORMNOMON      0
#define MSA_DBUSER_FLAG_MAILNOMON      1
#define MSA_DBUSER_FLAG_IMNOMON        2
#define MSA_DBUSER_FLAG_BLOCKNOMON     3
#define MSA_DBUSER_FLAG_REPORTNOMON    4
#define MSA_DBUSER_FLAG_SEARCHNOMON    5
#define MSA_DBUSER_FLAG_FILENOMON      6
#define MSA_DBUSER_FLAG_VCNOMON        7

#define MSA_DBUSER_FLAG_ONLYIP         8
#define MSA_DBUSER_FLAG_IPMAC          9
#define MSA_DBUSER_FLAG_ONLEONE        10
#define MSA_DBUSER_FLAG_NOFTPFILE      11
#define MSA_DBUSER_FLAG_NOFORMFILE     12
#define MSA_DBUSER_FLAG_NOMSNFILE      13
#define MSA_DBUSER_FLAG_NOQQFILE       14


typedef struct nasDbUserInfo_s {     /*用户信息*/
    int32    userid;
    int      onlineindex;
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
    uint64   lAllUpFlow;           /*day总的上行流量*/
    uint64   lAllDownFlow;         /*day总的下行流量*/
    uint32   lAllTime;             /*day总的上网时间*/
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
    char     policyid[_MAX_ALLPOLICY];               
    uint32   jftype;
    float    accountnum;
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
    int    					ratelimit;
    char            ratetype;   
    char            topSrvNameList[MAX_TOP_SRVNUM];
    unsigned long long   lLimitBytes;   
    unsigned int    lLimitTimes;
    unsigned long long   lLimitBytesw;   
    unsigned int    lLimitTimesw;
    unsigned long long   lLimitBytesm;   
    unsigned int    lLimitTimesm;
    char            moreflag[32]; 
    char            jftype;
    float    				accountnum;
    unsigned int    maxpackage;
    unsigned long long   maxBytes;
    unsigned int    maxudp;
    unsigned int    maxtcp;
    unsigned int    maxudpp;
    unsigned int    maxtcpp;
    unsigned int    maxupp;
    unsigned int    maxdownp;
    unsigned int    maxsp;
    unsigned int    maxnc;
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
	  nasFlowInfo  nowFlowInfo;  
    nasFlowDayInfo  dayFlowInfo; 
    uint32   lStartTime;     	/* 本次连接时间开始   */
    int      natflag;
    unsigned short    ident;
    int      natnums;
    int      natcheckm;
    char     firsthomeurl;
    uint32   lLastUpdateTime; /* 上次数据更新时间*/
    unsigned long   allconnect; //本次上线连接次数
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
	unsigned short cService; 
} nasUrlListTmp;

typedef struct nasUrlList_s {
	uint32   urlstart;
	unsigned char urllen;
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

#define MSA_TCPSESSION_TIMEOUT       300   
typedef struct nasTcpBuffer_s {
    uint32         lId;              /* 用户Id  0--没用         */
    int            dipBufIndex;      /* 访问dipBufferindex      */
    int            nUrl;             /* 访问userhttpBuffer的指针    */
    char           cMatchRule;       
    char           vlink;          
    unsigned int   ssnid[2];
    unsigned long  lSip;             /* 源IP地址     */
    unsigned long  lDip;             /* 目标IP地址   */
    unsigned short nSport;           /* 源端口号     */
    unsigned short nDport;           /* 目标端口号   */
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后修改时间 */
    uint64	       lBytes[2];        /* 0-上行字节数  1-下行字节数 */
    unsigned char  cType;            /* 协议         */
    unsigned short cService;         /* 服务         */
    unsigned char  caMac[6];         /* 源Mac地址    */
    unsigned long  lCount;           /* 数据包记数器 */
    unsigned char  cFlags;           /* 标识 0--实际数据还没有出现 1--出现头数据  2--出现内容数据  cFlags=*/
    unsigned char  cDirect;          /* 传输方向*/
    char           keyword[128];     /* 128keyword */
    int            keywordi;         /* keyword */
    unsigned long  fdindex;        
    unsigned long  seq;
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
    char           caHost[64];
    unsigned long  lIp;              /* ipadd     */
    uint64	       lBytes;           /* 流量         */
    unsigned long  lCount;           /* 次数         */
    unsigned long  lTime;            /*      */
    unsigned short intUrlService;         /*      */
} nasHttpBuffer;
/*
cUrlSort
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


typedef struct nasUserHttpBuffer_s {
	  unsigned long  userid;           /* userid     */
	  int            nUrl;             /* 访问httpBuffer的指针   */
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后访问时间     */
    uint64	       lBytes;           /* 流量         */
    unsigned long  lCount;           /* 次数         */
    unsigned long  lTime;            /*              */
} nasUserHttpBuffer;

typedef struct _shm_hash_link_UserHttpBufferhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
} shm_hash_link_UserHttpBufferhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_UserHttpBufferindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_UserHttpBufferindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_UserHttpBuffer {
    int                 next;
    nasUserHttpBuffer   item;
} shm_hash_link_UserHttpBuffer;


typedef struct nasDipBuffer_s {
    unsigned long  lStartTime;       /* 起始时间  0代表系统dip，不能从列表中删除  */
    unsigned long  lLastTime;        /* 最后访问时间  */
    uint64	       lBytes;           /* 流量          */
    uint32         ldip;
    unsigned long  lCount;           /* 次数          */
    unsigned long  lTime;            /*               */
    unsigned short cService;         /* 服务          */
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


//typedef struct nasTopUrlSort_s {
//	int           topsortid;
//	char          topsortname[48];
//	char          topsortdesc[250];
//}nasTopUrlSort;
//
//typedef struct nasUrlSort_s {
//	int           sortid;
//	char          sortname[48];
//	char          sortdesc[250];
//	int           toptype;
//}nasUrlSort;


#define NAS_MAXSCH_NUM       20
typedef struct nasschtime_s {
	int           schid;
	char          schname[25];
  char          schdesc[64];
	char          schtime[400];
}nasschtime;

#define NAS_MAXJJR_NUM       20
typedef struct nasjjrtime_s {
	int           jjrid;
	char          jjrname[25];
  char          jjrdesc[64];
	char          jjrtime[370];
}nasjjrtime;


/*服务限制规则,处理方法是遍例*/
/*
优先级是：
处理方式是如果找到规则就结束
*/

typedef struct msasrvrulehead_s {
    unsigned int       lMaxServiceRuleDIp;
    unsigned int       srvruledipptr;  /*从头开始的偏移量*/
    unsigned int       srvruledipsize;  /*从头开始的偏移量*/
    unsigned int       lMaxRuleIp;
    unsigned int       srvruleipptr;  /*从头开始的偏移量*/
    unsigned int       srvruleipsize;  /*从头开始的偏移量*/
    unsigned int       lMaxWebRule;
    unsigned int       webruleptr;  /*从头开始的偏移量*/
    unsigned int       webrulesize;  /*从头开始的偏移量*/
//    unsigned int       lMaxWebPostRule;
//    unsigned int       webpostruleptr;  /*从头开始的偏移量*/
//    unsigned int       webpostrulesize;  /*从头开始的偏移量*/
//    unsigned int       lMaxWebTypeRule;
//    unsigned int       webtyperuleptr;  /*从头开始的偏移量*/
//    unsigned int       webtyperulesize;  /*从头开始的偏移量*/
    unsigned int       userlistptr;     /*从头开始的偏移量*/
    unsigned int       userlistsize;     /*从头开始的偏移量*/
}msasrvrulehead;


typedef struct msaUserPolicy_s {
	  unsigned int    useflag;          /* 0 or 1 */
    unsigned int    sid;          /* 规则编号 */
    char            policyname[64];
    float	    			prio;      
    int    					ratelimit;
    char            ratetype;   
    char            topSrvNameList[MAX_TOP_SRVNUM];
    unsigned long long   lLimitBytes;   
    unsigned int    lLimitTimes;
    unsigned long long   lLimitBytesw;   
    unsigned int    lLimitTimesw;
    unsigned long long   lLimitBytesm;   
    unsigned int    lLimitTimesm;
    char            moreflag[32]; 
    char            jftype;
    float    				accountnum;
    unsigned int    maxpackage;
    unsigned long long   maxBytes;
    unsigned int    maxudp;
    unsigned int    maxtcp;
    unsigned int    maxudpp;
    unsigned int    maxtcpp;
    unsigned int    maxupp;
    unsigned int    maxdownp;
    unsigned int    maxsp;
    unsigned int    maxnc;
    char    		    pid[_MAX_ALLPOLICY];     /*系统的策略id*/
    char   					grouplist[_MAX_ALLGRPNUM];  /*用户组array的索引开始位置*/      
} msaUserPolicy;

typedef struct nasSrvRule_s {
    unsigned long   ruleid;          /* 规则编号 */
    char            rulename[32];
    char	    			ruleaction;      /*0拒绝    1：允许*/
    int    					qosid;
    unsigned long   ruleschedule;    /*该规则的schedule*/
//    char            ruleurlsort[101];
    unsigned long   rulejrid;        /*该规则的schedule*/
    char            ruleurl[128];    /*url*/
    int    					logaction;
    int    					conaction;
    char    				srvlist[MAX_SYS_SRVNUM]; /*服务的array 索引开始位置*/
    char    		    pid[_MAX_ALLPOLICY];     /*系统的策略id*/
    unsigned long   userlistptr;             /*用户array的索引开始位置*/
    char   					grouplist[_MAX_ALLGRPNUM];  /*用户组array的索引开始位置*/
    long   					ipStart;         /*ip地址段array的索引开始位置*/
    long   					ipEnd;
    unsigned long   urlStart;	       /*url列表 array的索引开始位置*/
    unsigned long   urlEnd;
//    unsigned long   postStart;	     /*post列表 array的索引开始位置*/
//    unsigned long   postEnd;    
//    unsigned long   typeStart;	     /*type列表 array的索引开始位置*/
//    unsigned long   typeEnd; 
    long   					dipStart;	       /*目标ip地址段array的索引开始位置*/
    long   					dipEnd;   
    nasFlowInfo     nowFlowInfo;  
    nasFlowDayInfo     dayFlowInfo;
//    char   					contenttypelist[_MAX_CONTENTTYPE_NUM];  /*contenttype*/         
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
    long   	    ruleflag;     /*0:匹配webGET动作  1:匹配webPOST动作 2:全部*/
    char        caUrl[64];    /*url列表*/
} nasRuleUrl;

///*web控制规则的ip地址组，处理方法是array 遍例*/
//typedef struct nasRulePost_s {
//    long   	    ruleid;       /* 规则编号 */
//    char        caUrl[64];      /*url列表*/
//} nasRulePost;
//
///*web控制规则的ip地址组，处理方法是array 遍例*/
//typedef struct nasRuleType_s {
//    long   	    ruleid;       /* 规则编号 */
//    char        caUrl[64];      /*url列表*/
//} nasRuleType;


/*控制规则的ip地址组，处理方法是array 遍例*/
typedef struct nasRuleIp_s {
    long   	    ruleid;       /* 规则编号 */
    unsigned long   ipstart;      /*ip段开始地址*/
    unsigned long   ipend;        /*ip段结束地址*/
} nasRuleIp;

#define _MAXSNMPBUF   5000
#define _MAX_SNMP_NUM    6
typedef struct _snmpgroup{
	char snmpcommunity[32];
	char snmpsip[32];
	char snmpoid[128];
	char snmpv[12];
} SNMPGROUP;

typedef struct _snmpinfo{
	char mac[6];
	unsigned int  snmpsip;
} SNMPINFO;

typedef struct _snmpinfohead{
	unsigned int  snmpnum;
	unsigned int  lastsnmptime;
	SNMPINFO      _SNMPINFO[_MAXSNMPBUF];
} SNMPINFOHEAD;

#define _MAXVIDNUM   5000
typedef struct _vidinfohead{
	unsigned int  stringhash;
	unsigned int  vidtype;  //1QQ;2MSN 3FTP 4POP3 5SMTP收件人 
	char          vid[32];
} VIDINFOHEAD;



typedef struct msaOption_s {
////////////////////////////////监视内容参数 	
   unsigned int ipmon;
   unsigned int httpmon;
   unsigned int ipreportmon;
   unsigned int httpreportmon;
   unsigned int smtpmon;
   unsigned int formmon;
   unsigned int pop3mon;
   unsigned int blockmon;
   unsigned int immon;
   unsigned int filemon;
   unsigned int searchmon;
   unsigned int usermon; //虚拟身份
/////////////////////////////////记录保存参数    
   unsigned int nomondisk;
   unsigned int recordkeepday;
   unsigned int mailkeepday;
   unsigned int aimkeepday;
   unsigned int formkeepday;
   unsigned int historykeepday;
   unsigned int vidkeepday;
   unsigned int userkeepday;
   unsigned int loglevel; //记录级别
/////////////////////////////////功能参数    
   unsigned int supportEmail;//邮件数据包重组
   unsigned int supportForm;//表单数据包重组
   unsigned int onlineusertype;//无法同时在线踢出前一用户
   unsigned int noautoadduser;//默认禁止自动添加用户
   unsigned int attprev;//启动附件预览和内容检索
   unsigned int nopicblock;//不阻断辅助图片或者辅助脚本
   int          defaultuserflag;//用户超量时默认状态为免监控99或禁止访问100
/////////////////////////////////系统参数   
   unsigned int maxuseronlietime;//允许用户最长在线时间/秒
   unsigned int maxusertimeout;//在线用户超时时间/秒
   unsigned int userproccesstime;//在线用户进程检查时间间隔
   unsigned int maxtcpsessiontimeout;//连接超时时间/秒
   unsigned int tcpproccesstime;//连接进程检查时间间隔
   float    flowrate;//流量费率
   float    timerate;//时间费率
/////////////////////////////////snmp参数    
   unsigned int snmpebable;
   unsigned int snmptimeout;//snmp最小刷新时间间隔
   SNMPGROUP gnmsnmpgroup[_MAX_SNMP_NUM]; 
/////////////////////////////////验证与阻断服务参数       
   unsigned int authport;//内置验证服务端口
   char     strAuthIP[32];//验证服务ip
   char     strAuthUrl[256];//第三方验证服务url
   char     denyUrl[256];   //第三方拒绝访问页面地址
   unsigned int supportTCP;//发送tcp阻断包
   unsigned int supportUDP;//发送udp阻断包
////////////////////////////////////
   int     mailloglevel;   
   int     formloglevel; 
} msaOption;

typedef struct msaSec_s {
////////////////////////////////监视内容参数 	
   unsigned int noping;
   unsigned int adminpasssec;  //1强化密码
   unsigned int userpasssec;   //1强化用户密码
   unsigned int authserver;
   unsigned int sshserver;
} msaSec;

typedef struct nasPPOESession_s {
	  char            ppoename[32];
    unsigned char   mac[6];         /* MAC地址 */
    unsigned long   ip; 
    unsigned long   sTime; 
} nasPPOESession;

/* 邮件监控过滤规则  */
typedef struct nasMailFilter_s {
    char   caRname[64];
    char   caFrom[64];
    char   caTo[64];
    char   caSub[64];
    char   caCont[64];
    char   caAtt[64];
    int    lSize;
    int    lAsize;
    short  nFlags;      /* 类别 0:SMTP  1:POP3 2 web*/
    short  nSflags;     /* 通知方式 0--不通知  1--通知  2--转发  */
    char   caSmail[64]; /* 转发邮箱 */
    int    lRnum;
    int    lMaction;
} nasMailFilter;

/* 邮件监控过滤规则  */
typedef struct nasFormFilter_s {
    char   caRname[64];
    char   caFrom[64];
    char   caHost[64];
    char   caURL[64];
    char   caCon[64];
    char   caAtt[64];
    int    lSize;
    int    lAsize;
    short  nFlags;      /* 类别 0:发送  1:接收 2 web*/
    short  nSflags;     /* 通知方式 0--不通知  1--通知  2--转发  */
    char   caSmail[64]; /* 转发邮箱        */
    int    lMaction;    /*监控动作1：监控  0：不监控*/
} nasFormFilter;


/* 邮件监控过滤规则  */
typedef struct nasFormFilterOne_s {
    char   caRname[64];
    char   caFrom[64];
    char   caHost[64];
    char   caURL[64];
    int    lMaction;
} nasFormFilterOne;

#define _MAX_MAILFILTER_NUM    64
#define _MAX_FORMFILTER_NUM    64
#define _MAX_SYSMAILFILTER_NUM    64
#define _MAX_SYSFORMFILTER_NUM    64
#define _MAX_FORMNOMON_NUM     64

typedef struct FilterListHead_s {
    nasMailFilter _ltMailFilter[_MAX_MAILFILTER_NUM];
    int            nowMailFilterNum;
    nasMailFilter _ltSysMailFilter[_MAX_SYSMAILFILTER_NUM];
    int            nowSysMailFilterNum;
    nasFormFilter _ltFormFilter[_MAX_FORMFILTER_NUM];
    int            nowFormFilterNum;
    nasFormFilter _ltSysFormFilter[_MAX_SYSFORMFILTER_NUM];
    int            nowSysFormFilterNum;
    nasFormFilterOne _ltFormNoMon[_MAX_FORMNOMON_NUM];
    int            nowFormNoMonNum;
} FilterListHead;


#define _MAX_VIDRULE_NUM    1024
typedef struct _nasrulevid {
    int    lIndex;
    char   ruelvid[32];
    int    ruletype;
} nasrulevid;

//  eth0/10     侦听数据y/n	数据抛弃 ---     外网口   ip地址   promisc 选择虚拟链路
//				数据转发-      
//                  		数据镜像-
//				nat内网口--ip
//                                nat外网口--ip
//                                一般通信口--ip

typedef struct msaLinkInfo_s {
	unsigned int useflag;
	char  devname[32];
	unsigned int issniffer;
	unsigned int ispromisc;
	unsigned int devtype;
	char     outdevname[32];
	unsigned int devIp;
	unsigned int vlink;
} msaLinkInfo;


//typedef struct msaContentType_s {
//	unsigned int intins;
//	char  strcontenttype[64];
//	unsigned char  toptype;
//	unsigned short inttype;
//} msaContentType;

//toptype 
//0:未知  1:application 2:text 3:video 4:audio 5:image 
//inttype:分类
//

typedef struct msapkbufhead_s {
	  unsigned int       allheadlen;
    unsigned int       lpkheadNum;
    unsigned int       pkheadptr;   /*从头开始的偏移量*/
    unsigned int       pkheadsize;  /*从头开始的偏移量*/
    uint32             writeindexhead;
    uint32             writeindextail;
    unsigned int       lpkNum;
    unsigned int       pkbufptr;    /*从头开始的偏移量*/
    unsigned int       pkbufsize;    /*从头开始的偏移量*/
    uint32             freebufhead;
    uint32             freebuftail;
    unsigned int       lCmdBufNum;
    unsigned int       cmdheadptr;   /*从头开始的偏移量*/
    unsigned int       cmdheadsize;  /*从头开始的偏移量*/
    uint32             cmdwriteindexhead;
    uint32             cmdwriteindextail;
} msapkbufhead;

#define PKTYPE_SMTP    1
#define PKTYPE_POP3    2
#define PKTYPE_UPLOAD  3
#define PKTYPE_MSN  4
#define PKTYPE_YAHOO  5
#define PKTYPE_FEIXIN 6
#define PKTYPE_TELNET 7

typedef struct _BufferHeadIndex {
	  unsigned long  userid;           /* userid     */
	  unsigned long  lSip;             /* 源IP地址     */
    unsigned long  lDip;             /* 目标IP地址   */
    unsigned short nSport;           /* 源端口号     */
    unsigned short nDport;           /* 目标端口号   */
    unsigned char  cType;            /* 协议         */
    unsigned char  buftype;          /* 协议         */
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后修改时间 */
    int            next; /*-1相当于NULL*/
    int            freenext; /*-1相当于NULL*/
    unsigned long  pknum;    /*数据包数目  */
} BufferHeadIndex;

/*hash内容队列,根据空余插入*/
#define _MAX_PK_MTU    1500
typedef struct _PkBufferIndex {
    int             next;
    unsigned int    pkseq;
    unsigned int    pklen;
    char            pkbuf[_MAX_PK_MTU];
} PkBufferIndex;

#define _MAX_CMD_BUFLEN64     64
#define _MAX_CMD_BUFLEN128    128

//1smtp 2pop3 3qq 4msn 5ftp 6webmail  7飞信 8web账号 9:SMTP收件人
#define CMDTYPE_SMTP      1
#define CMDTYPE_MAILTO    2
#define CMDTYPE_POPUSER   3
#define CMDTYPE_QQLONON   4
#define CMDTYPE_QQLONOFF  5
#define CMDTYPE_TELNETLONON  6
#define CMDTYPE_FTPLONON  7
#define CMDTYPE_FTPLONOFF 8
#define CMDTYPE_HTTPURL   9


typedef struct _CMDHttpInfo {
	  int            nUrl;
	  char           cMatchRule;
	  char           vlink;
    uint64	       lBytes[2];        /* 0-上行字节数  1-下行字节数 */  
    unsigned short cService;         /* 服务         */
    unsigned long  lCount;           /* 数据包记数器 */
    unsigned char  cDirect;          /* 传输方向*/
} CMDHttpInfo;

typedef struct _CMDHeadIndex {
	  unsigned long  userid;           /* userid     */
	  unsigned char  mac[6];           /* mac     */
	  unsigned long  lSip;             /* 源IP地址     */
    unsigned long  lDip;             /* 目标IP地址   */
    unsigned short nSport;           /* 源端口号     */
    unsigned short nDport;           /* 目标端口号   */
    unsigned char  cType;            /* 协议         */
    unsigned char  buftype;          /* 协议         */
    unsigned long  lStartTime;       /* 起始时间     */
    unsigned long  lLastTime;        /* 最后修改时间 */
    char           pkbufkey1[_MAX_CMD_BUFLEN64];
    char           pkbufkey2[_MAX_CMD_BUFLEN64];
    char           pkbufkey3[_MAX_CMD_BUFLEN128];
    int            pkbufkey4;
    int            freenext; /*-1相当于NULL*/
} CMDHeadIndex;

//虚拟身份轨迹列表 pop3
//vctype     int,               /*虚拟身份类型 1smtp 2pop3 3qq 4msn 5ftp 6webmail  7飞信 8web账号…*/
//vccon  pkbufkey1    varchar(48),        /*虚拟身份特征号码*
//vcaction pkbufkey2   int,               /*虚拟身份动作 1logon 2logoff 3sendmsg 4sendfile 5视频 6音频 7应用 …*/
//vcatt pkbufkey3    varchar(128)       /*虚拟身份附加特征*


typedef struct nasMylAdd_s {
	unsigned long myIp;
	int useFlag;
} nasMylAdd;

typedef struct msaAuthInfo_s {
   char         addomain[64];
   unsigned int httpmon;
   unsigned int ipreportmon;
   unsigned int httpreportmon;
} msaAuthInfo;


typedef struct msaPubInfo_s {
	  unsigned int  lRunning;
	  int           timearea;
	  char          updateflag[32];     /*更新位标志 */
	  char          _dbname[128];
	  char          _dbuser[128];
	  char          _dbpass[128];
	  int           sysActive;
	  int           qosenable;
	  int           maxfuntonnum;
	  int           msaGeneralMin;
	  int           msaGeneralHour;
	  int           msaGeneralDay;
	  int           msaScheduleTime;
	  int           msaJJRTime;
	  float         timerate;
	  float         flowrate;
	  unsigned int  maxdiskpnow;
	  unsigned int  maxdiskp;
	  msaOption     _msaOptionHead;
	  msaSec        _msaSecHead;
	  nasrulevid    _nasrulevidhead[_MAX_VIDRULE_NUM];
	  msaLinkInfo   _msaLinkInfo[_MAXDEVNUM];
//	  int                _ContentTypeNum;
//	  msaContentType     _ContentTypeList[_MAX_CONTENTTYPE_NUM];
	  nasPPOESession     ltPPOESession[66000];
	  nasAdmSession      admSession[MAX_ADMIN_SESSION];
	  conListType        pubMsgStr[MAX_SYSTEM_MSG];
	  int                defaultLan;    /*默认语言*/
	  FilterListHead     _FilterListHead;
	  msaTopSrv          topSrvName[MAX_TOP_SRVNUM]; 
	  unsigned int       lServiceNum;
	  msaService         ltService[MAX_SYS_SRVNUM]; /*0:unknown 1-400:sys  401-499:user*/
	  short              srvTcpInConList[64];//后续服务检查列表，做进一步的检查,检查http负载内容
	  short              srvTcpOutConList[64];//后续服务检查列表，做进一步的检查,检查http负载内容
//	  nasUrlSort         _urlSortlist[NAS_MAXURLSORT_NUM];
//	  nasTopUrlSort      _topurlSortlist[NAS_MAXTOPURLSORT_NUM]; 
	  nasschtime         _schtimelist[NAS_MAXSCH_NUM];
	  nasjjrtime         _jjrtimelist[NAS_MAXJJR_NUM];
	  nasPortInfo        ltPortInfo[MAX_PORTNUM];
	  _pNetArea          ltNetArea[_MAXNETAREANUM];  /*全部网络对象 */
	  _pNetArea          NetAreaCkeck[_MAXNETAREANUM];   /*大网络对象  */ 
	  SNMPINFOHEAD       ltSnmpGroup[_MAX_SNMP_NUM];
	  unsigned  int      nowvidnum;
	  VIDINFOHEAD        _vidinfohead[_MAXVIDNUM];
	  unsigned  int      snmplockflag;
	  nasMylAdd          myAdd[20];        /*机器自身的ip地址*/
	  nasAllInfo         _AllInfo;
	  nasVPathInfo			 _VPathList[_MAXVPATHNUM];
	  nasQosPathInfo		 _QosList[_MAX_QOSSTATIC_CHANEL];
	  nasGroupInfo	     _GroupList[_MAX_ALLGRPNUM];
	  nasPolicyInfo	     _PolicyList[_MAX_ALLPOLICY];
	  int                _Srvrulehead[_MAX_SRVRULE_NUM];
	  nasSrvRule         _Srvrulelist[_MAX_SRVRULE_NUM];
	  msaUserPolicy      _userPolicylist[_MAX_USERPOLICY_NUM];
    IpHostInfoHead     _iphostinfohaed;
    dbUserInfoHead     _dbUserInfoHead;
    shm_hash_link_dbusernamehead  _dbusernamehead; 
    shm_hash_link_dbuseriphead    _dbuseriphead; 
    shm_hash_link_dbusermachead   _dbusermachead; 
    shm_hash_link_onlineuserhead  _onlineuserhead;
    shm_hash_link_urlhead         _urlhashhead;
    shm_hash_link_TcpBufferhead   _tcpsessionhead;
    shm_hash_link_UserHttpBufferhead _userhttpbufferhead;
    shm_hash_link_HttpBufferhead  _httpbufferhead;
    shm_hash_link_DipBufferhead   _dipbufferhead;
    shm_hash_link_2SrvInfohead    _2SrvInfohead; 
    msapkbufhead                  _msapkbufhead;
    msasrvrulehead                _srvrulehead;
}msaPubInfo;

#define _MAXPKLEN          1550
typedef struct msaBufferEntry_s {
	unsigned char userflag;
	unsigned int  vlink;
	char          dev[6];
	unsigned int  length;
	unsigned int  ssnid;
	char          pkbuf[_MAXPKLEN];
} msaBufferEntry;

typedef struct msaSSNControl_s {
    unsigned long  lSip;             /* 起始IP    */
    unsigned short nSport;           /* 起始port   */
    unsigned long  lDip;            
    unsigned short nDport;
    unsigned short cProt;             /* 协议*/           
    unsigned char  cFlag;             /* 见上面的宏*/
    unsigned char  cAction;           /* 见上面的宏*/
    unsigned short qoschanel0;
    unsigned short qoschanel1;        /* 协议*/  
    unsigned long  lLastTime;         /* 起始时间 */
    int            direct;            /* 方向 */
} msaSSNControl;

typedef struct _shm_hash_link_Controlhead {
    unsigned int       bufptr;  /*从头开始的偏移量*/
    unsigned int       bufsize;  /*从头开始的偏移量*/ 
    unsigned int       conbufptr;  /*从头开始的偏移量*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;           
    uint32             nownum;
} shm_hash_link_Controlhead;

/*hash index 根据index分布*/
typedef struct _shm_hash_link_Controlindex {
    int           next; /*-1相当于NULL*/
} shm_hash_link_Controlindex;

/*hash内容队列,根据空余插入*/
typedef struct _shm_hash_link_Control {
    int                next;
    msaSSNControl      item;
} shm_hash_link_Control;

#define _MAXPKBUFFERNUM    64
typedef struct msaKernelHead_s {
  unsigned long      banduplink;
  unsigned long      banddownlink;
  int                banddowndef;
  int                bandupdef;
  unsigned int       upbyteleft ; /*max qos chanels */
  unsigned int       downbyteleft ; /*max qos chanels */
  int                baozhengflagUp ; 
  int                baozhengflagDown; 
	msaBufferEntry     _BufferEntry[_MAXPKBUFFERNUM];
	shm_hash_link_Controlhead  _msaControlhead;
} msaKernelHead;


typedef struct nasIpHead_s {
	unsigned long  lSip;       /* 源IP地址     */
	char     caSmac[6];        /* 源MAC地址    */
	unsigned short nSport;     /* 源端口       */
	unsigned long  lDip;       /* 目标IP地址   */
	char     caDmac[6];        /* 目标MAC地址  */
	unsigned short nDport;     /* 目标端口     */
	unsigned short    cTran;            /* 传送方向 0--上行 1--下行    */
	unsigned short    cProp;            /* 协议  6 UDP      17 TCP     */
	unsigned short    pppoesid;
	unsigned short    ident;
	unsigned int      ssnid[2];
	char         *defhomeurl;
	unsigned int defgroupid;
	unsigned int defpolicyid;
	unsigned int snmpindex;
	int          inetflag;
	unsigned int lTime;
	int          vlink;
} nasIpHead;

/*
*/
msaPubInfo  *_ltPubInfo;
ltDbConn     *G_DbCon; /*各个包处理进程的数据库连接*/
msaKernelHead  *_bcKernelHead;
int      controlSocketFd;
int      udpcontrolSocketFd;
char     *G_DevName;
nasIpHostInfo  *_ltHostInfo;
nasPortInfo    *_ltPortInfo;
nasDbUserInfo  *_ltDbUserInfoList;
shm_hash_link_HttpBuffer          *_ltHttpBuffer;
shm_hash_link_UserHttpBuffer      *_ltUserHttpBuffer;

#define MAXSEMNUMS    12
#define MSASEMKEY     770123
#define SYSSEMID    0
#define USERSEMID   1
#define URLSEMID      2
#define TCPBUFSEMID   3
#define HTTPBUFSEMID  4
#define USERHTTPBUFSEMID  5
#define DIPBUFSEMID   6
#define SRVBUFSEMID  7
#define SSNSEMID      8
#define PKHEADSEMID   9
#define PKBUFSEMID    10
#define CMDBUFSEMID   11

int  _Gsemid[MAXSEMNUMS];

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


typedef struct nasPostFileList_s {
    char     pOriginFile[128];   /* 源文件    */
    char     pType[64];          /* 文件类型  */
    char     pOutFile[64];
    unsigned long lSize; 
    struct nasPostFileList_s *psNext;   
} nasPosFileList;

typedef struct nasPostDataHead_s {
    char           caBound[128];     /* caBound    */
    char           caHost[64];    /* 主机名    */
    char           caUrl[128];     /* 访问URL   */
    char           caUser[64];     /* 访问URL   */
    unsigned long  lTime;          /* 时间      */
} nasPostDataHead;

typedef struct nasPostDataContent_s {
    unsigned long  lBytes;         /* 总字节数  */
//    char           *pValue;        /* 数据内容  */
    int            iSum;           /* 附件总数  */
    nasPosFileList  *psFileList;    /* 文件列表  */
} nasPostDataContent;


typedef struct DbMsgHead_s{
	  uint32   lMaxBytes;
    uint32   lBytes;      /*  Message Bytes include the head      */
    char     character[24];
    uint32   lSendTime;   /*  Send Time                           */
    uint8    nVersion;    /*  Message Version                     */
    uint8    cCrypt;      /*  0-- No Crypt 1--DES  0-- baochuang  */
    char     strFile[128];//存储附件的位置
    uint8    lAttNum;   
    uint32   lMsgSize;  
} DbMsgHead;

typedef struct DbMsgAtt_s{
    char           attFileName[64];     //存储附件的名称
    char           attDispName[64];     //存储附件的显示名称
    uint32         lAttSize;   /*  Send Time   */
} DbMsgAtt;

#define DB_MSG_VERSION    1


lt_shmHead *msacreateShmMem(unsigned int intShmKey,unsigned int intMaxShmSize);
lt_shmHead *msaopenShmMem(unsigned int intShmKey,unsigned int intMaxShmSize);
int msacloseShmMem(lt_shmHead *lt_MMHead);

/*nasPubUtil.c*/
unsigned int getUserUrlHash(unsigned int userid, unsigned int  urlhash);
unsigned int get3wordsHash(unsigned int a, unsigned int b, unsigned int c);
unsigned int getMacHash(unsigned char *caMac);
unsigned int  msa_ssn_hash(unsigned int sip, unsigned int  dip,unsigned short  sport,unsigned short dport,int  protocol);
unsigned int getStringHash(unsigned char *caStr,unsigned int strLen);
int msaInitPubInfo(lt_shmHead *lt_MMHead);
int msaInitPubVar(lt_shmHead *lt_MMHead,lt_shmHead *kernel_MMHead);
int ltWebMsgErr(char *errorMsg,int confd,ltMsgHead *ltMsgPk);
int logWrite(ltMsgHead *ltMsgPk,char *msg,int msgtype);
int nasTimeFormat(char *pFormat,long lTime);
int checkRight(int confd,ltMsgHead *ltMsgPk,int right);
int strgb2utf8(char *cpInput,char *cpOut,int iInputLen);
int strutf82gb(char *cpInput,char *cpOut,int iInputLen);
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
lt_shmHead *msaopenBigBootMem(unsigned int intMaxShmSize);
int msacloseBigBootMem(lt_shmHead *lt_MMHead);
int msaDelSemLock(lt_shmHead *lt_MMHead);
int msaCreatSemLock(lt_shmHead *lt_MMHead);
char nasPostX2C(char *what);
int nasTimeGetTime(char *cTime,long lTime);
char *time2str(int itime);
int msaShowIpMap(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);	
int myFastMemmem(unsigned char * a, int alen, unsigned char * b, int blen);
int activesys(char *strCodeInput,char *errmsg);

DbMsgHead *dbMsgInit(unsigned long  lMaxBytes);
int dbMsgAdd_s(DbMsgHead **psMsgHead0,char *pVarName,char *pVarValue);
int dbMsgAdd_v(DbMsgHead **psMsgHead0,char *pVarName,char *pVarValue, unsigned long lLen);
int dbMsgAdd_Att(DbMsgHead **psMsgHead,DbMsgAtt *pAtt,unsigned int attindex);
char *dbMsgGetVar_s(DbMsgHead *psMsgHead,char *pVarName);
char *dbMsgGetVar_v(DbMsgHead *psMsgHead,char *pVarName,unsigned long *lBytes);
DbMsgAtt *dbMsgGet_Att(DbMsgHead *psMsgHead,unsigned int attindex);
void dbMsgFree(DbMsgHead *psMsgHead);
int dbMsgAllRecordPrint(char *dbdatafile,int startp);
char  *dbMsgAllRecordSearch(char *dbdatafile,char *searchCon,int conlen,int *allnum,int *searchnum);
char  *dbMsgPrintMail(char *dbdatafile,int startp,char *strSet);
char  *dbMsgPrintForm(char *dbdatafile,int startp,char *strSet);

int nasMailCtlMailSend(char *pFrom,char *pTo,char *pSub,char *pCon);
int nasMailCtlStrStr(char *pCont,char *pSub);

/*vid*/
int FindVid(VIDINFOHEAD *_vidinfohead,char *strVid);
int nasInitVidList(msaPubInfo *ltPubInfo);

/*msahttputil.c*/
int nasGetHttpHead(char *pIn,int iLen,char *pHost,char *pUrl,int *intRange,char **pCon);
int msaGetConTypeIndex(char *strContype,int intlen);
int nasGetHttpHead1(char *pIn,int iLen,char *strconType,char **pCon);
int nasStrGetVar(char *pIn,int inLen,char *pVar,char *pValue,int outLen);
int nasStrGetUrl(char *pIn,int iLen,char *caUrl,int outlen);
int nasHttpUrlLogFilter(char *pUrl,int loglevel);
int nasHttpHtml(char *pUrl);

/*msaService.c*/
int msaInitPortInfo(msaPubInfo  *ltPubInfo);
int nasInitTopService(msaPubInfo  *ltPubInfo);
int msaInitServiceArray(msaPubInfo  *ltPubInfo);
int  msaGet2Srv(unsigned int  lDip, unsigned short nDport,int  cType,unsigned int lTime);
int msaGetServiceFrom0(unsigned long cProt, unsigned short nPort,unsigned short nLPort,unsigned short nDirect,char *pBuffer,unsigned long lBytes,unsigned int lDip,unsigned int lTime);

int msaGetServiceFromHttp(int oldnType,unsigned long cProt, unsigned short nPort,
unsigned short nLPort,unsigned short nDirect,char *pBuffer,unsigned long lBytes,char *caHost,char *caUrl,
int *intRange,char *strConType,int *iContentFlag,unsigned int *urlHashZhi,char **ppCon);

int nasCheckPostFile(int oldtype,nasTcpBuffer *psTcpBuffer,char  *pBuffer,unsigned long lAck,unsigned long lBytes);

int nasIsLimitSrv(
		nasOnlineUserInfo  *psUserInfo,
		nasDbUserInfo *tmpDbUserInfo,
		nasIpHead    *psIpHead,
		nasTcpBuffer  *psTcpBuffer,
		char           *caHost,
    char           *caUrl,
    unsigned int   iContentFlag);

/*msaIpHost.c*/
int nasInitIpHostInfo(lt_shmHead *lt_MMHead);

/*msaIpArea.c*/
nasOnlineUserInfo *nasCheckNetArea(msaPubInfo *ltPubInfo,nasIpHead *psIpHead,int *iFlag0);
nasOnlineUserInfo  *nasGetBaseUser(nasIpHead *psIpHead,int *iFlag,int getflag,char *caName);
int ltFindHostInfo(unsigned long lip,int *netflag,unsigned int *snmpindex,char **homeurl,unsigned int *groupid,unsigned int *policyid);
int  nasSetMoreFlag(nasOnlineUserInfo  *psUserInfo,nasDbUserInfo *tmpDbUserInfoList);
int ReadIpMacSNMP(char *strHadd,unsigned int lip,unsigned int snmpindex);

/*msacontrol.c*/
int Open_Raw_Socket();
void nasAlertRedirect(const unsigned char *pBuffer,int capLen,char *myurl);
void nasAlertRedirect1(const unsigned char *pBuffer,int capLen);
void nasAutRedirect(const unsigned char *pBuffer,int capLen,char *caHost,char *caUrl,nasIpHead *sIpHead,int caType);
int send_udppacket(char*packet_buf,int packet_buf_size);


/*dbUserLib.c*/
int msaInitDbUserList(msaPubInfo  *ltPubInfo);
int msaHashInsertDbUser(msaPubInfo  *ltPubInfo, nasDbUserInfo *item);
int msaHashDelDbUser(msaPubInfo  *ltPubInfo, nasDbUserInfo *item);
nasDbUserInfo *msaLookUpDbUserById(msaPubInfo  *ltPubInfo,unsigned int userid );
nasDbUserInfo *msaLookUpDbUserByIp(msaPubInfo  *ltPubInfo,unsigned int ipadd );
nasDbUserInfo *msaLookUpDbUserByName(msaPubInfo  *ltPubInfo,char *username );
nasDbUserInfo *msaLookUpDbUserByMac(msaPubInfo  *ltPubInfo,char *caMac );
unsigned int msaGetFreeUserid(msaPubInfo  *ltPubInfo);
int msaHashDelDbUserById(msaPubInfo  *ltPubInfo,unsigned int userid);
nasDbUserInfo *msaNewInsertDbUser(msaPubInfo  *ltPubInfo, nasDbUserInfo *item);

int msaDeleteDbUserName(msaPubInfo  *ltPubInfo,unsigned char *username);
msaDbUserName * msaHashInsertDbUserName(msaPubInfo  *ltPubInfo, msaDbUserName *item);
msaDbUserIp * msaHashInsertDbUserIp(msaPubInfo  *ltPubInfo, msaDbUserIp *item);
int msaDeleteDbUserIp(msaPubInfo  *ltPubInfo,unsigned int ipadd);
msaDbUserMac * msaHashInsertDbUserMac(msaPubInfo  *ltPubInfo, msaDbUserMac *item);
int msaDeleteDbUserMac(msaPubInfo  *ltPubInfo,unsigned char *caMac);


/*OlineUserLib.c*/
int msaInitOnlineUserHash(msaPubInfo  *ltPubInfo);
nasOnlineUserInfo *msaHashInsertOnlineUser(msaPubInfo  *ltPubInfo, nasOnlineUserInfo *item);
nasOnlineUserInfo *msaHashLookUpOnlineUser(msaPubInfo  *ltPubInfo,unsigned int ipadd);
int msaDeleteOnlineUser(msaPubInfo  *ltPubInfo,unsigned int ipadd);
int msaDeleteOnlineUserById(msaPubInfo  *ltPubInfo,unsigned int userid);
int msaUserOffLine(nasOnlineUserInfo *msaOnlineUser,nasDbUserInfo *tmpDbUserInfo,FILE *fp,char *sDate);

/*msaUrllist.c*/
nasUrlList *msaHashLookUpUrlIndex(msaPubInfo  *ltPubInfo,char *strurl,int urlHashIndex);
int nasInitUrlList(lt_shmHead *lt_MMHead);
nasUrlList *msaCheckInsertUrl(msaPubInfo  *ltPubInfo, nasUrlListTmp *item);
int msaReInitUrlHash(msaPubInfo  *ltPubInfo);
nasUrlList *msaCheckInsertUrlLater(msaPubInfo  *ltPubInfo, nasUrlListTmp *item);

/*msaTcpSession.c*/
int msaInitTcpBufferHash(msaPubInfo  *ltPubInfo);
nasTcpBuffer *msaHashInsertTcpBuffer(msaPubInfo  *ltPubInfo,unsigned int ssnhash, nasTcpBuffer *item);
nasTcpBuffer *msaHashLookUpTcpSession(msaPubInfo  *ltPubInfo,unsigned int ssnhash, nasTcpBuffer *item);
int msaDeleteTcpSession(msaPubInfo  *ltPubInfo,unsigned int ssnhash, nasTcpBuffer *item);


/*msaHttpBuffer.c*/
int msaInitUserHttpBufferHash(msaPubInfo  *ltPubInfo);
nasUserHttpBuffer *msaHashInsertUserHttpBuffer(msaPubInfo  *ltPubInfo,nasUserHttpBuffer *item);
nasUserHttpBuffer *msaHashLookUpUserHttpBuffer(msaPubInfo  *ltPubInfo,char *caHost);
int msaDeleteUserHttpBuffer(msaPubInfo  *ltPubInfo, char *caHost);

int msaInitHttpBufferHash(msaPubInfo  *ltPubInfo);
nasHttpBuffer *msaHashInsertHttpBuffer(msaPubInfo  *ltPubInfo,nasHttpBuffer *item);
nasHttpBuffer *msaHashLookUpHttpBuffer(msaPubInfo  *ltPubInfo,char *caHost);
int msaDeleteHttpBuffer(msaPubInfo  *ltPubInfo, char *caHost);
int msaHashLookUpHttpBufferIndex(msaPubInfo  *ltPubInfo,char *caHost,int urlHash);
int msaHashInsertHttpBufferIndex(msaPubInfo  *ltPubInfo,nasHttpBuffer *item,int urlHash);
int msaHashLookUpUserHttpBufferIndex(msaPubInfo  *ltPubInfo,int hostIndex,int userid,int urlHash);
int msaHashInsertUserHttpBufferIndex(msaPubInfo  *ltPubInfo,nasUserHttpBuffer *item,int urlHash);

/*msaDipBuffer.c*/
int msaInitDipBufferHash(msaPubInfo  *ltPubInfo);
nasDipBuffer *msaHashInsertDipBuffer(msaPubInfo  *ltPubInfo,nasDipBuffer *item);
nasDipBuffer *msaHashLookUpDipBuffer(msaPubInfo  *ltPubInfo,unsigned int ldip);
int msaDeleteDipBuffer(msaPubInfo  *ltPubInfo, unsigned int ldip);
int updateDipBuffer(msaPubInfo  *ltPubInfo,unsigned int ldip,unsigned int lTime,unsigned int sLen,unsigned int lCount);
int nasInitIpSrvList(msaPubInfo  *ltPubInfo);

/*msa2SrvInfo.c*/
int msaInit2SrvInfoHash(msaPubInfo  *ltPubInfo);
nas2SrvInfo *msaHashInsert2SrvInfo(msaPubInfo  *ltPubInfo,nas2SrvInfo *item);
nas2SrvInfo *msaHashLookUp2SrvInfo(msaPubInfo  *ltPubInfo,unsigned int lDip,unsigned int nDport,unsigned int cType);
int msaDelete2SrvInfo(msaPubInfo  *ltPubInfo, unsigned int lDip,unsigned int nDport,unsigned int cType);
int msaHashInsert2SrvInfoI(msaPubInfo  *ltPubInfo,nas2SrvInfo *item);

/*msaInitRule.c*/
int nasInitRule(msaPubInfo *ltPubInfo);
int srvRuleDIpFind(nasSrvRuleDIp  *ltSrvRuleDIp,unsigned long  lDip,unsigned long left, unsigned long right);
int ruleIpFind(nasRuleIp  *ltRuleIp,unsigned long  lSip,unsigned long left, unsigned long right);
int ruleUrlFindSMTP(nasRuleUrl  *ltWebRuleUrl,char *caHost,unsigned long left, unsigned long right);
int ruleUrlFind(nasRuleUrl  *ltWebRuleUrl,char *caHost,char *caUrl,unsigned long left, unsigned long right,int contentflag);
//int rulePostFind(nasRulePost  *ltWebRuleUrl,char *caUrl,unsigned long left, unsigned long right);
//int ruleUrlFindType(nasRuleType  *ltWebRuleUrl,char *caUrl,unsigned long left, unsigned long right);
//int ruleUrlFindConType(nasRuleType  *ltWebRuleUrl,char *caConType,unsigned long left, unsigned long right);
int nasHttpImgFilter(char *pUrl);

/*msafilter.c*/
int nasMailFilterInit(msaPubInfo * ltPubInfo);

/*msaPkBuffer.c*/
int msaInitPkBuf(msaPubInfo  *ltPubInfo);
int  msaInsertCMDBuf(msaPubInfo  *ltPubInfo,  unsigned char  *mac,
unsigned long  lSip,unsigned long  lDip,unsigned short nSport,
unsigned short nDport,unsigned char  cType,unsigned char  buftype,
char *pkbufkey1,unsigned int keyLen1,
char *pkbufkey2,unsigned int keyLen2,
char *pkbufkey3,unsigned int keyLen3,
int  pkbufkey4,
unsigned int lTime,unsigned int userid);
int  msaInsertPkBuf(msaPubInfo  *ltPubInfo, 
unsigned long  lSip,unsigned long  lDip,unsigned short nSport,
unsigned short nDport,unsigned char  cType,unsigned char  buftype,unsigned int seq,
char *pkbuf,unsigned int pLen,unsigned int lTime,unsigned int userid);
int  msaUpdatePkBuf(msaPubInfo  *ltPubInfo,unsigned int writeindex,char *pkbuf,unsigned int pLen, unsigned int seq,unsigned int lTime);

/*uplodproclib.c*/
nasPostDataContent *nasReadPostData(char *caFile,char *pOutFile,int *mailflag,nasPostDataContent *psValue,nasPostDataHead *psUploadHead,int *mycharset,DbMsgHead **psMsgHead,char *mailFrom,char *mailTo,char *mailSub);
nasPostDataContent *nasReadPostDataMem(char *msgCon,int msglen,char *pOutFile,int *mailflag,nasPostDataContent *psValue,nasPostDataHead *psUploadHead,int *mycharset,DbMsgHead **psMsgHead,char *mailFrom,char *mailTo,char *mailSub);
int nasPostDataFree(nasPostDataContent *psValue);

/*msaqos.c*/
int msaInitBandList(msaPubInfo  *ltPubInfo,msaKernelHead *bcKernelHead);
int msaSetBand(nasOnlineUserInfo  *ltUserInfo,nasDbUserInfo * tmpDbUserInfoList,int action);

/*msapkprocutil.c*/
int nasUtlDoSmtp(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int sLen,
                unsigned int lTime);
int nasUtlDoPop3(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,unsigned int lTime);                
int nasUtlDoUpload(nasOnlineUserInfo *psUserInfo,
                nasDbUserInfo *dbUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                char     *pHost,
                char     *pUrl,
                unsigned char  *sp,unsigned int   sLen,unsigned int lTime);
                
int nasUtlDoYahoo(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen,unsigned int lTime);

int nasUtlDoFeiXin(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen,unsigned int lTime);
                
int nasUtlDoFtp(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen,unsigned int lTime);        
                
int nasUtlDoFtp226(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen);
                
int nasUtlDoFtpPASV(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen);  
                     
int nasUtlDoMsn(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen,unsigned int lTime);     
                                                    
int nasUtlDoQQUdp(nasOnlineUserInfo *psUserInfo,
                nasTcpBuffer *psTcpBuffer,
                unsigned long lAck,
                unsigned long lBytes,
                char     *pBuffer,
                unsigned char  *sp,unsigned int   sLen,unsigned int lTime);                       
/**/
int msaControlBuffer(msaKernelHead  *kernelPubInfo, msaSSNControl *item,unsigned int ssnindex);

/*srv-admin.c*/
int msaShowAdminLogon(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdminLogon(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAdminLogout(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowTopview(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-group.c*/

int msaGroupAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPolicyTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPolicyAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowClientList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaClientList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-userexport.c*/
int msaAccoutShowPage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAccountExport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupExportShowPage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupSearchList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupDataExport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-userimport.c*/
int userimport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int groupimport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-aduser.c*/
int ltadvarconfig(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltadvarconfigok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltadtree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int  nasinportaduser(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int  nasinportldapuser(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltldaptree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltldapvarconfigok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltldapvarconfig(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-url.c*/
int lturlsortlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int lturlsort(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltupdateurlsort(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltsaveurlsort(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdateType(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltupdateurlType(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdateIP(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdateArea(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdateDNS(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltdisposition(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltsysnet3conf(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltsysnet5conf(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltsysnet6conf(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltsysnetconfok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

	
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
int ltapplynetArea(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ltportinfolist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltportinfoaction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltapplyportinfo(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ltappFunctionok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltappFunction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msamailGroup(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltmailfilteraction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltmailfilterlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowMail(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaformGroup(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltformfilteraction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltformfilterlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowForm(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


int ltschinfolist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltaddsch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltupdatesch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltdelsch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltjjrinfolist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltaddjjr(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltupdatejjr(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltdeljjr(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int lttimesetting(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int lttimeok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int lttimeset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaRout(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltformlevelok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltformlevel(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltmaillevelok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltmaillevel(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//int msaUrlSortList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//int msaUrlSortOK(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msasrvlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltSrvlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltSrvaction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowSrv(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaformOneGroup(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltformOnefilteraction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltformOnefilterlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowFormOne(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-bushu.c*/
int msaEquipment(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaVLanListAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAddVlanAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaApplyAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int vserver(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//加载虚拟服务器页面
int ltVPSok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//配置虚拟服务器
int ddnsset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//加载DDNS服务页面
int ltDDNSok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//配置DDNS服务
int ltappPage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
	
//srv-rule.c

int msaUpPrio(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaDownPrio(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int showServicePolicy(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int showEditRuleSrv(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaEditRuleSrv(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int addRuleSrv(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int showRuleSrv(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int showService(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int addService(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//添加规则
int showEditService(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//添加规则页面
int msaEditSrvRule(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaSrvRuleList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaSrvRulesrvList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaEditWebpost(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaEditWeburl(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaEditip(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ShowSelectUserTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ruleGroupUserlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int serviceUserlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int addruleuser(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ShowUrlSort(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ShowAddress(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int editkeyword(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaltServiceTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//int contentTypeTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//int msaUrlsortLoop(stralloc *strTemp,int srvnum,char urlsort[]);
//int msaUrlsortTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaShowPeopleRecord(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltmsaform(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaIfCreatXlsOK(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);




/*srv-nowview.c*/
int msaNowSrvList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msashowxtzy(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaNowGroupList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAsyncTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaMDip(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaWebListInfo(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAsyncTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


int msaNowSrvruleList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaToSrvRule(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaRuleHtml(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaNowQosList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaQosDetailList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaNowPathList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPathDetail(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPathDetailList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaGroupTreeView(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msa24qushi(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaGroupDetail(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupDetailList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int packagelist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int naspackageok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-nowconnect.c*/
int ltconquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaNowConectInfo(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-nowviwuser.c*/
int msaShowOnlineUser(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaonlineuser(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUsersrvPage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUserSrvList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-userpolicy.c*/
int msaListUserPolicy(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdatePrio(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaAddPrio(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaEditPrio(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int showPolicyApply(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaGroupToPageTreeView(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPiLiangAppPolicy(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaPolicyToPageTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaServiceToPageTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-user.c*/
int msaTermInfoView(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaShowAddClient(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaTerminfoAdd(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaTerminfoUp(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdatePwd(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaUpdateGroup(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaGroupInport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaServiceTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-auth.c*/
int msashowlogonpage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msauserlogonnormal(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msauserchpass(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-qos.c*/
int ltqosdownlink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltupdateqos(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int lteditqos(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltbandlink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltbandlinkok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int ltqoslist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int ltqosupdate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-sysclean.c*/
int sysclean(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaCleanAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaStatusAction(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-firewall.c*/
int showFWrulepg(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int addFWrule(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaFWruleList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int editPWpage(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int appFireWallRule(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-route.c*/
int msaroutsetinglink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaroutseting(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-keyword.c*/
int videntityFilter(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msasecurityset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int Apprules(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);



/*srv-report-pageoption.c*/
/*
MSA:报告中心
				报告模板
						新建报告模板
功能:链接到定义模板页面调用函数
*/
int msareporttemplate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//新建报告模板确认提交函数
int reporttemplate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//到已定义报告模板
int toreporttemplatelist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//查看模板函数
int reporttempledit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//浏览该模板报告
int templatereportlista(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//自动生成的报告列表
int toautoreportlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//每天汇总报告列表
int toreportlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//已定义报告模板 立即生成报告
int reportcreate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//已定义报告模板 立即生成报告 生成报告 返回视图页面
int toreportcreate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//模板修改调用函数
int reporttemplateupdate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//立刻生成报告 报告列表数据载入调用函数
int templatereportlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-report-sortreport.c*/
/*排序报告页面链接函数*/
int msasortreportlink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*排序报告生成函数*/
int msasortreport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-userline.c*/
/*
MSA:报告中心
				用户主线
功能:主线报告创建调用函数
*/
int msaReportUserLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-webline.c*/
/*
MSA:报告中心
				WEB主线
功能:web主线报告创建调用函数
*/
int msaReportWebLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-srvline.c*/
/*
MSA:报告中心
				服务主线
功能:服务主线分析报告创建调用函数
*/
int msaReportSrvLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:报告中心
功能：生成的报告列表显示
*/
int msaReportRecordJson(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:报告中心
功能：生成的报告列表JSONstore构造函数
*/
int msaReportJsonStore(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-flowline.c*/
/*
MSA:报告中心
				流量主线
功能:流量主线分析报告创建调用函数
*/
int msaReportFlowLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-report-linereport.c*/
/*
MSA:报告中心
				系统主线
功能:实现报告创建的函数调用 sysstep1->sysstep5*/
int msaReportSysLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:报告中心 网络风险
功能:实现网络风险报告创建的函数调用 riskstep1->riskstep5
*/
int msaReportRsikLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-data-data.c*/
/*
 MSA:数据中心
     		 服务访问记录搜索
 功能:按条件查询并保存数据|直接导出本段时间所搜数据
 */
int msaipbacksearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
    详细访问记录
        服务阻断记录搜索
功能:记录搜索，数据载入，以及gird表格记录删除功能
*/
int msaNewSearchList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
 MSA:数据中心
     详细访问记录
         服务访问记录
         阻断访问记录
         HTTP访问记录
 功能：页面链接调用函数
 */
int msaShowAccessList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
 MSA:数据中心
     服务访问记录搜索
     服务阻断记录搜索
     http访问记录搜索
 功能:页面链接调用函数
 */
int msaShowAccessSearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
 MSA:数据中心
     详细访问记录
     		 服务访问记
 功能:列表显示本段时间访问记录调用函数
 */
int msaAccessList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
    详细访问记录
        服务访问记录
功能:下载本时段文件
*/
int msaBackListDownLoadCSV(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				搜索关键字
功能:关键字列表查询,导出,删除
*/
int ltmsasearchkeyhttpa(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				搜索关键字
功能:关键列表页面链接函数
*/
int ltmsasearchkeyquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
		即时通信记录
				MSN,Yahoo,QQ,淘宝,飞信,skype
功能:页面链接调用函数
*/
int ltimshowwebquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				即时通信记录
				    MSN,Yahoo,淘宝,飞信,qq,skype
功能:记录数据查询 导出 删除
*/
int ltwebqueryima(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				文件传输记录
功能:文件传输记录各节点链接页面调用函数
*/
int ltmsafiletranquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				文件传输记录
功能:文件传输记录查询，导出，删除
*/
int ltmsafilequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				POP3/SMTP邮件
功能:当日邮件查询 
包括:发送，接收，带附件，大于1M，符合报警策略，符合关键字报警 
条件构造:并将条件打印到页面模板参数
*/
int ltmsadaymailquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				POP3/SMTP邮件
功能:当日邮件grid数据显示json构造函数
*/
int ltmsadaymaillist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
				POP3,SMTP邮件
功能:邮件全文检索				
*/
int ltmsamail(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
功能:用户combox的json构造 
*/
int msalocalStore(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);



/*srv-data-form.c*/
/*
MSA:数据中心
        表单提交内容
功能:当日表单记录查询
*/
int msaformList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
功能:虚拟身份记录页面链接
*/
int ltmsavcloglink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
			虚拟身份记录
功能:记录数据查询 导出 删除
*/
int ltmsavclogquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
			邮件
功能:pop3/smtp邮件记录查询/删除/导出
*/
int ltmsamailquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
邮件和表单内容显示函数
*/
int msaShowContent(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-data-people.c*/
/*
MSA:数据中心
        人员主线
功能:用户树构造函数
*/
int msaUserTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*srv-data-time.c*/
/*
MSA:数据中心
				日期主线
功能:日期树构造
*/
int msaDateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
        日期主线
功能:点击日期连接页面函数
*/

int msaShowTimeRecord(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-data-conkeysech.c*/
/*
MSA:数据中心
        内容关键字搜索
功能:返回搜索主视图页面
*/

int msaSearchKeyWord(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
		内容关键字检索
功能:搜索主视图页面:日期树构建函数
*/
int msaSearchkeyDateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
    设置关键字
功能:返回设置关键视图页面并实现关键字的增删
*/


/*srv-service-tree.c*/
/*
MSA:数据中心
    服务选择功能
    一级服务树
*/
int msaOneServiceTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:数据中心
    服务选择功能
    二级服务树
*/
int msaTwoServiceTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

int msaiplogCv(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaMainSearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int searchshowPG(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int mailJson(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int formJson(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int historySearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaHistoryView(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
int msaNowDayData(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

#endif


