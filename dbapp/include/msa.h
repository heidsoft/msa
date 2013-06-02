
#ifndef __MSADEF__
#define __MSADEF__


#include <netinet/ether.h>
#include "pubfun.h"


/*���Ų�μ���*/
#define _MAX_GROUPLEVEL    5
/*ȫ����������*/
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

/*ϵͳ��������*/
#define NAS_MAX_COREFUNNUM    200
#define NAS_MAX_FUNNUM        200
#define NAS_DEFAULT_FUNTIME   200

/*����Ա����*/
#define MAX_ADMIN_SESSION            300
#define MAX_ADMIN_TIMEOUT            7200
#define MAX_ADMIN_TRYTIMEOUT         120
#define MAX_ADMIN_MAXRIGHT           100


/*�Զ����ַ���*/
#define MAX_SYSTEM_MSG               1000
/*�256*/
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

#define NAS_PROTOCOL_TCP 6    /*tcpЭ��*/
#define NAS_PROTOCOL_UDP 17   /*udpЭ��*/ 

#define NAS_NETWORK_NOMAL          0    /* ����  */
#define NAS_NETWORK_IPBASE         1    /* ����IP��ַ  */
#define NAS_NETWORK_MACBASE        2    /* ����mac��ַ */
#define NAS_NETWORK_HOSTBASE       3    /* ������������*/
#define NAS_NETWORK_PPPOEBASE      4    /* ����PPPOE��֤*/
#define NAS_NETWORK_NOAUTHCLIENT   8    /* �ͻ�������������֤ */
#define NAS_NETWORK_NOAUTHSERVER   9   /* ����������������֤ */

#define NAS_NETWORK_NTAUTH         21    /* ����֤  */
#define NAS_NETWORK_NTAUTHHEAD     22    /* ������������֤  */

#define NAS_NETWORK_LOCALAUTH      23    /* ����web��֤*/
#define NAS_NETWORK_LOCALAUTHHEAD  24    /* �������Ʊ���web��֤*/
#define NAS_NETWORK_LOCALAUTHCLIENT  25  /* client��֤*/


#define NAS_NETWORK_LDAPAUTHBASE        26    /* ����LDAP��֤ͬ��*/
#define NAS_NETWORK_LDAPAUTHBASEHEAD    27    /* �������ƻ���LDAP��֤ͬ��web*/
#define NAS_NETWORK_LDAPAUTHBASECLIENT  28    /* client����LDAP��֤ͬ��*/
#define NAS_NETWORK_RADUSAUTHBASE       29    /* ����RADUS��֤ͬ��*/
#define NAS_NETWORK_RADUSAUTHBASEHEAD   30    /* ����RADUS��֤ͬ��web*/
#define NAS_NETWORK_RADUSAUTHBASECLIENT 31    /* ����RADUS��֤ͬ��client*/


#define NAS_NETWORK_IPCLIENT       41    /* IP�ͻ�������*/
#define NAS_NETWORK_MACCLIENT      42    /* MAC�ͻ������� */
#define NAS_NETWORK_HOSTCLIENT     43    /* �������ͻ������� */

#define NAS_NETWORK_OUT            90    /* �ⲿ��ַ���⹦�ܷ�������������������*/

#define NAS_NETWORK_NOMON          99    /* ����     */
#define NAS_NETWORK_NOACCESS       100    /* ��ֹ�������*/

#define NAS_NETWORK_LOCAL	  		1
#define NAS_NETWORK_EXTERNAL	  2
#define NAS_SYS_ERROR         -1 /*ϵͳ���ֵĴ���*/
#define NAS_GET_USER		      1  /*�õ��û�*/

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

#define MSA_SERVICE_UNKNOWN    0     /* ��������             */
#define MSA_SERVICE_HTTP       50    /* Web����              */
#define MSA_SERVICE_HTTPMUTI   130    /* HTTP���������              */
#define MSA_SERVICE_HTTPERROR  131    /* �Ǳ�׼http���ݷ���              */

#define MSA_SERVICE_HTTPCOM   47    /* com  */
#define MSA_SERVICE_HTTPCN    48    /* cn   */
#define MSA_SERVICE_HTTPNET   49    /* .net */

#define MSA_SERVICE_HTTPMAIL   6    /* ������վ              */
#define MSA_SERVICE_POSTMAIL   51    /* webmail�ύ              */
#define MSA_SERVICE_HTTPCHAT   16    /* ���졢������վ              */
#define MSA_SERVICE_POSTCHAT   53    /* ���졢������վ�ύ              */
#define MSA_SERVICE_HTTPBBS    17    /* ��̳��������վ��վ              */
#define MSA_SERVICE_POSTBBS    52    /* ��̳��������վ�ύ              */

#define MSA_SERVICE_CONFLV     100    /* ����FLV����*/
#define MSA_SERVICE_CONMP3     101    /* mp3*/
#define MSA_SERVICE_CONAVI     102    /* HTTP-AVI����*/

#define MSA_SERVICE_CONRM      103    /* rm */
#define MSA_SERVICE_CONMP4     104    /* mp4*/
#define MSA_SERVICE_CON3gp     105    /* 3gp*/

#define MSA_SERVICE_AUDIO     109    /* HTTP��Ƶ�ļ�������*/
#define MSA_SERVICE_VEDIO     110    /* HTTP��Ƶ�ļ�������*/




#define MSA_SERVICE_CONJS      111    /* HTTP-javascript����*/
#define MSA_SERVICE_CONXML     112    /* HTTP-xml*/
#define MSA_SERVICE_octeo      116    /* ����Ӧ��������������*/

#define MSA_SERVICE_CONRAR     117    /* rar*/
#define MSA_SERVICE_CONZIP     118    /* zip����*/
#define MSA_SERVICE_CONTGZ     119    /* TGZѹ����*/
#define MSA_SERVICE_CONPDF     120    /* pdf */
#define MSA_SERVICE_CONO2003   121    /* HTTP-word��office2003�ļ�����*/
#define MSA_SERVICE_CONO2007   122    /* HTTP-word��office2010�ļ�����*/
#define MSA_SERVICE_CONEXE     123    /* exe*/
#define MSA_SERVICE_octe       129    /* HTT����������������*/



#define MSA_SERVICE_CONBMP     132    /* bmp*/
#define MSA_SERVICE_CONGIF     133    /* GIFͼƬ*/
#define MSA_SERVICE_CONJPG     134    /* JPEGͼƬ*/
#define MSA_SERVICE_CONPNG     135    /* PNGͼƬ*/
#define MSA_SERVICE_CONFLASH   136    /* flash*/
#define MSA_SERVICE_CONIMAGE     140    /* ����HTTP-Image��*/


#define MSA_SERVICE_SMTP       290    /* SMTP����            */
#define MSA_SERVICE_POP3       291    /* POP����             */
#define MSA_SERVICE_HTTPSRV    250    /* ����Web����      */
#define MSA_SERVICE_SMTPSRV    251    /* ����SMTP����     */
#define MSA_SERVICE_POP3SRV    252    /* ����POP����      */
#define MSA_SERVICE_HTTPSSRV   253    /* ����POP����      */
//
#define MSA_SERVICE_MSN        170    /* msn����          */
#define MSA_SERVICE_MSNFILE    171    /* msn���ļ�        */
#define MSA_SERVICE_MSNYC      172    /* msnԶ��Э��      */
#define MSA_SERVICE_MSNYP      173    /* msn����Ƶ        */

#define MSA_SERVICE_YAHOO      176    /* yahoo����          */
#define MSA_SERVICE_ICQ        186    /* icq����           */

#define MSA_SERVICE_FTP        240    /* ftp����          */
#define MSA_SERVICE_FTPDATA    241    /* ftp����          */
#define MSA_SERVICE_UPDATA     242    /* ftp����          */
#define MSA_SERVICE_DOWNDATA   243    /* ftp����          */

#define MSA_SERVICE_BT         211    /* BT����           */

#define MSA_SERVICE_QQ         162    /* QQ����           */
#define MSA_SERVICE_QQTCP      163    /* QQ-tcp����       */
#define MSA_SERVICE_QQHTTPS    164    /* QQ-https����     */
#define MSA_SERVICE_QQSP       165    /* qq��Ƶ�Ự       */
#define MSA_SERVICE_QQYP       166    /* qq��Ƶ�Ự       */
#define MSA_SERVICE_QQWJ       167    /* qq���ļ�         */
#define MSA_SERVICE_QQYC       168    /* qqԶ��Э��       */
#define MSA_SERVICE_QQDX       169    /* qq������         */

#define MSA_SERVICE_UC         181    /* UC          */
#define MSA_SERVICE_POPO       180    /* popo        */

#define MSA_SERVICE_WWWJCS     178    /* �����ļ����� */

#define MSA_SERVICE_STUN       200    /* stun         */


#define MSA_SERVICE_SMB        263    /* smb            */
#define MSA_SERVICE_EMULE      212    /* EMule����        */
#define MSA_SERVICE_PPLIVE     222    /* pplive����       */
#define MSA_SERVICE_QQLIVE     223    /* qqlive����       */
//

#define MSA_SERVICE_WinMX      216    /* WinMX����       */
#define MSA_SERVICE_XunLei     210    /* Ѹ������         */
#define MSA_SERVICE_HaoFang    377    /* �Ʒ���սƽ̨     */
#define MSA_SERVICE_Socks5     312    /* Socks5����       */
#define MSA_SERVICE_HTTPPROXY  311    /* http����         */
//#define MSA_SERVICE_BF4G       32    /* �߷�4����ս      */
//#define MSA_SERVICE_BF5Z       52    /* �߷�5�Ӵ�ս      */
//#define MSA_SERVICE_BFZGXQ     53    /* �߷��й�����     */
//#define MSA_SERVICE_BFXZ       54    /* �߷���Ϸ����     */
#define MSA_SERVICE_BAIDU_XB   215    /* �°�             */
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
#define MSA_SERVICE_PPG        229    /* ƨƨ��      */
//#define MSA_SERVICE_totolook   69    /* totolook    */
//#define MSA_SERVICE_PPT        70    /* PP���ͨ    */
//
//#define MSA_SERVICE_SINAGAME   79    /* sina��Ϸ    */
//#define MSA_SERVICE_SOHUGAME   80    /* sohu��Ϸ    */
//
#define MSA_SERVICE_HTTPS      160     /* https    */
#define MSA_SERVICE_QQGAME     375    /* qq��Ϸ   */
#define MSA_SERVICE_UUCALL     202    /* uucall   */
#define MSA_SERVICE_SIP        196    /* SIPЭ��  */
#define MSA_SERVICE_RTP        197    /* RTP/RTCP */
#define MSA_SERVICE_RSTP       199    /* RSTP */
//#define MSA_SERVICE_IRC        11    /* IRC */
#define MSA_SERVICE_Telnet     302    /* telnet */
#define MSA_SERVICE_FeiXin     182    /* ����2008 */
//#define MSA_SERVICE_sdo        93    /* ʢ�� */
//#define MSA_SERVICE_BF         15    /* �߷� */
#define MSA_SERVICE_LZ         374    /* ���� */
//#define MSA_SERVICE_Jabber     95    /* JABBER */
//
//
#define MSA_SERVICE_warcraft   394    /* warcraft */
#define MSA_SERVICE_cf         387    /* ��Խ���� */
#define MSA_SERVICE_dnf        388    /* ���³�����ʿ */
#define MSA_SERVICE_tx2        389    /* ����2 */
#define MSA_SERVICE_mir3       386    /* ����3 */
#define MSA_SERVICE_mirs       390    /* �����⴫ */
#define MSA_SERVICE_jx3        391    /* ������Ե3 */
//
#define MSA_SERVICE_popkart    393    /* ���ܿ����� */
#define MSA_SERVICE_bnb        395    /* ������ */
#define MSA_SERVICE_zt         392    /* ��; */
#define MSA_SERVICE_rxjh       396    /* ��Ѫ���� */
//
//#define MSA_SERVICE_MSNPROXY   107   /* MSNPROXY */

#define MSA_SERVICE_POSTRAR       60    /* HTTP-RAR�ļ��ϴ� */
#define MSA_SERVICE_POSTZIP       61    /* HTTP-Zip�ļ��ϴ� */
#define MSA_SERVICE_POSTTGZ       62    /* HTTP-TGZ�ļ��ϴ� */
#define MSA_SERVICE_POSTWORD      63    /* HTTP-WORD�ļ��ϴ� */
#define MSA_SERVICE_POSTExcel     64    /* HTTP-Excel�ļ��ϴ� */
#define MSA_SERVICE_POSTPDF       65    /* HTTP-PDF�ļ��ϴ� */
#define MSA_SERVICE_POSTPPT       66    /* HTTP-PPT�ļ��ϴ� */
#define MSA_SERVICE_POSTTXT       67    /* HTTP-TXT�ļ��ϴ� */
#define MSA_SERVICE_POSTExe       68    /* HTTP-Exe�ļ��ϴ� */
#define MSA_SERVICE_POSTJPG       69    /* HTTP-JPG�ļ��ϴ� */
#define MSA_SERVICE_POSTGif       70    /* HTTP-Gif�ļ��ϴ� */
#define MSA_SERVICE_NOEXTPOSTFILE       74    /* HTTP-����չ�����ļ��ϴ� */
#define MSA_SERVICE_OTHERPOSTFILE       75    /* HTTP�����ļ��ϴ� */

#define MSA_SERVICE_HTWTJY       330    /* ��ͨί�н���*/
#define MSA_SERVICE_DZH          321    /* ���ǻ۹�Ʊ��� */



/*ע�ắ����*/
typedef struct corefunList_s{
	char strFunName[64]; /*��������*/
  int (*op)();
} corefunList;



typedef struct funList_s{
	unsigned int lFunCode;  /*����*/
	unsigned int funFlag;   /*0 ֱ�ӵ��� 1 dll��̬���� 2java�� 3Ӧ�ó������*/
	char strNode[32]; /*����˵��*/
	char strFunName[64]; /*��������*/
	char strFunUrl[128]; /*dll���õ�url*/
	unsigned int  maxruntime;    /*�ú��������ʱ��*/
	unsigned int  activeflag;    /*��������� 0�뼤���޹� 1�뼤����� */
	unsigned int  rightflag;    /*Ȩ�������  0��Ȩ���޹� 1��Ȩ�����  */
  int (*op)();
} funList;

corefunList  _ltcorefunList[NAS_MAX_COREFUNNUM];
funList      _ltfunList[NAS_MAX_FUNNUM];
int          _maxfuntonnum;

typedef struct nasAdmSession_s {
	unsigned long  lSip;       /* ԴIP��ַ     */
	unsigned long  lSid;       /* session id  4λ����  */
	char           lright[MAX_ADMIN_MAXRIGHT];     /* Ȩ��       */
	char           caname[64];     /* Ȩ��       */
  char           allgroup[_MAX_ALLGRPNUM+1];   /* ������   */
  unsigned int   trytimes;
	unsigned long  lasttime;   /*���һ�ε�½ʱ�� */
} nasAdmSession;

/*
0:chinese
1:en
*/
typedef struct conListType_s {
    char            conStr[MAX_LANG_LIST_CONSIZE];
} conListType;


typedef struct nasPortInfo_s {
    unsigned long  nPort;             /* �˿� */
    int		   udpLog;       /* ��udp�˿��Ƿ񱻼�¼  3��������� 2��ز���¼ 9������ 10 ��ֹ���� */
    int		   tcpLog;       /* ��tcp�˿��Ƿ񱻼�¼  3��������� 2��ز���¼ 9������ 10 ��ֹ����   */
    int      isTcplocal;      /* 1 local  0 remote*/
    int      isUdplocal;      /* 1 local  0 remote*/
    short    srcTcpInList[8]; //�����������б�����һ���ļ��
    short    srvTcpOutList[8];
    short    srvUdpReceiveList[8];
    short    srvUdpSendList[8];
} nasPortInfo;

typedef struct msaTopSrv_s {
	char          srvname[MAX_TOPSRVNAME_SIZE];
}msaTopSrv;

typedef struct msaService_s {
	  short           srvid;     /*����*/
    char            srvName[MAX_SRVNAME_SIZE];     /*����*/
    char            descName[MAX_TOPSRVNAME_SIZE];     /*����*/
    unsigned char   srvFlag; 	       /*0 ϵͳ��1 �û��Խ�*/
    unsigned char   srvProt;         /* Э��6 tcp    17 udp */
    unsigned short  nPortL;          /* �˿ں�����    */
    unsigned short  nPortU;          /* �˿ں�����    */
    unsigned char   srvDirect;       /* 0:out  1:in   */
    unsigned char   topSrv;
    unsigned char   syssrvcheck;     /*�Ƿ���Ҫϵͳ������� */    
    unsigned char   denytype;        /*�Ƿ���Ҫϵͳ������� */  
    unsigned char   level;           /*level��ϵͳΣ���ĳ̶�*/  
    unsigned char   httpload;        /*0 ��httpload��1 httpload  2:both */
    char            srvcon[512];     //Э���б�����,���Э�������б����Զ���Э������
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

typedef struct nasIpHostInfo_s { /* IP��ַ����Ϣ    */
    unsigned long   lIp;       /* IP��ַ    */
    unsigned long   netAreaIndex;       /* last time    */
} nasIpHostInfo;


typedef struct _IpHostInfoHead_s {
	  unsigned int       maxiphost;
	  unsigned int       lIpHostNum;
	  unsigned int       onlineIpHostptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       onlineIpHostsize;  /*��ͷ��ʼ��ƫ����*/
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


typedef struct nasDbUserInfo_s {     /*�û���Ϣ*/
    int32    userid;
    int      onlineindex;
    char     username[32];         /*�ʺ���*/
    char     dispname[32];         /*����*/
    unsigned char  Certificate_type;
    char     Certificate_code[24]; 
    unsigned char  sex;
		char     password[32];        
    uint32   groupid[_MAX_GROUPLEVEL];
    char     bindemail[64];
    uint32   bindip; 
    unsigned char  bindmac[6];     /*MAC��ַ*/
    unsigned char  useflags;
    uint32   ratelimit;  
    unsigned char  ratetype;      /*0����  1����*/
    unsigned char  topSrvNameList[MAX_TOP_SRVNUM]; 
    uint32   addtime; 
    uint32   locktime; 
    uint32   lasttime; 
    uint64   lLimitBytes;                  
    uint32   lLimitTimes; 
    uint64   lAllUpFlow;           /*day�ܵ���������*/
    uint64   lAllDownFlow;         /*day�ܵ���������*/
    uint32   lAllTime;             /*day�ܵ�����ʱ��*/
    uint64   lLimitBytesw;         /*ÿ����������������*/
    uint32   lLimitTimesw;         /*ÿ������������ʱ��*/
    uint64   lAllUpFloww;          /*���ڵ���������*/
    uint64   lAllDownFloww;        /*�����ܵ���������*/       
    uint32   lAllTimew;            /*�����ܵ�����ʱ��*/
    uint64   lLimitBytesm;         /*ÿ��������������*/
    uint32   lLimitTimesm;         /*ÿ����������ʱ��*/           
    uint64   lAllUpFlowm;          /*���ܵ���������*/
    uint64   lAllDownFlowm;        /*���ܵ���������*/   
    uint32   lAllTimem;    	       /*���ܵ�����ʱ��*/    
    char     moreflag[32];        
    char     policyid[_MAX_ALLPOLICY];               
    uint32   jftype;
    float    accountnum;
    uint32   maxpackage;
    uint32   maxBytes;
    uint32   maxudp;               /* ���udp���� */ 
    uint32   maxtcp;               /*  ���tcp����*/
    uint32   maxudpp;              /*  ÿ�����udp������*/
    uint32   maxtcpp;              /*  ÿ�����tcp������*/
    uint32   maxupp;               /*  ÿ��up������*/ 
    uint32   maxdownp;             /*  ÿ��down������*/  
    uint32   maxsp;                /*  ÿ��128�ֽ�С������*/ 
    uint32   maxnc;                /*  ÿ������½�������Ŀ*/  
}nasDbUserInfo;

/*
���ֵ�hash����
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_dbusernamehead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                nownum;
} shm_hash_link_dbusernamehead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_dbusernameindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_dbusernameindex;

typedef struct msaDbUserName_s { 
	  int32    userid;
    char     username[32];         /*�ʺ���*/
} msaDbUserName;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_onlineusername {
    int             next;
    msaDbUserName   item;
} shm_hash_link_onlineusername;

/*
IP��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_dbuseriphead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                nownum;
} shm_hash_link_dbuseriphead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_dbuseripindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_dbuseripindex;

typedef struct msaDbUserIp_s { 
	  int32    userid;
    int32    ipadd;         /*ipadd*/
} msaDbUserIp;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_onlineuserip {
    int             next;
    msaDbUserIp    item;
} shm_hash_link_onlineuserip;


/*
mac��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_dbusermachead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                nownum;
} shm_hash_link_dbusermachead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_dbusermacindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_dbusermacindex;

typedef struct msaDbUserMac_s { 
	  int32    userid;
    unsigned char  caMac[6];
} msaDbUserMac;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_onlineusermac {
    int             next;
    msaDbUserMac    item;
} shm_hash_link_onlineusermac;


typedef struct _dbUserInfoHead {
    unsigned int    bufptr;
    unsigned int    bufsize;
    unsigned int    bufnum;
} dbUserInfoHead;

 
typedef struct nasOnlieUserInfo_s {     /*�û���Ϣ*/
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
    uint32   nowmaxpackage;     /*��ǰÿ�����ݰ�*/
    uint64   nowmaxbytes;       /*��ǰÿ������*/
    uint32   nowmaxudpp;        /*��ǰÿ�����udp������*/ 
    uint32   nowmaxtcpp;        /*  ��ǰÿ�����tcp������*/ 
    uint32   nowmaxupp;         /*  ÿ��up������*/ 
    uint32   nowmaxdownp;       /*  ÿ��down������*/ 
    uint32   nowmaxsp;          /*  ÿ��128�ֽ�С������*/ 
    uint32   nowmaxnc;          /*  ÿ������½�������Ŀ*/
    uint32   udpconnect; 
    uint32   tcpconnect; 
    char     nowminute;
	  nasFlowInfo  nowFlowInfo;  
    nasFlowDayInfo  dayFlowInfo; 
    uint32   lStartTime;     	/* ��������ʱ�俪ʼ   */
    int      natflag;
    unsigned short    ident;
    int      natnums;
    int      natcheckm;
    char     firsthomeurl;
    uint32   lLastUpdateTime; /* �ϴ����ݸ���ʱ��*/
    unsigned long   allconnect; //�����������Ӵ���
}nasOnlineUserInfo;

/*
mac��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_onlineuserhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    int                freecontenthead;
    int                freecontenttail;
    int                nownum;
} shm_hash_link_onlineuserhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_onlineuserindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_onlineuserindex;

/*hash���ݶ���,���ݿ������*/
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
mac��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_urlhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
    uint32             urlcontentHead;
    uint32             urlcontentSize;
    uint32             urlcontentNowSize;
} shm_hash_link_urlhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_urlindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_urlindex;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_url {
    int             next;
    nasUrlList      item;
} shm_hash_link_url;

#define MSA_TCPSESSION_TIMEOUT       300   
typedef struct nasTcpBuffer_s {
    uint32         lId;              /* �û�Id  0--û��         */
    int            dipBufIndex;      /* ����dipBufferindex      */
    int            nUrl;             /* ����userhttpBuffer��ָ��    */
    char           cMatchRule;       
    char           vlink;          
    unsigned int   ssnid[2];
    unsigned long  lSip;             /* ԴIP��ַ     */
    unsigned long  lDip;             /* Ŀ��IP��ַ   */
    unsigned short nSport;           /* Դ�˿ں�     */
    unsigned short nDport;           /* Ŀ��˿ں�   */
    unsigned long  lStartTime;       /* ��ʼʱ��     */
    unsigned long  lLastTime;        /* ����޸�ʱ�� */
    uint64	       lBytes[2];        /* 0-�����ֽ���  1-�����ֽ��� */
    unsigned char  cType;            /* Э��         */
    unsigned short cService;         /* ����         */
    unsigned char  caMac[6];         /* ԴMac��ַ    */
    unsigned long  lCount;           /* ���ݰ������� */
    unsigned char  cFlags;           /* ��ʶ 0--ʵ�����ݻ�û�г��� 1--����ͷ����  2--������������  cFlags=*/
    unsigned char  cDirect;          /* ���䷽��*/
    char           keyword[128];     /* 128keyword */
    int            keywordi;         /* keyword */
    unsigned long  fdindex;        
    unsigned long  seq;
} nasTcpBuffer;

/*
mac��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_TcpBufferhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
} shm_hash_link_TcpBufferhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_TcpBufferindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_TcpBufferindex;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_TcpBuffer {
    int             next;
    nasTcpBuffer    item;
} shm_hash_link_TcpBuffer;


typedef struct nasHttpBuffer_s {
    unsigned long  lStartTime;       /* ��ʼʱ��     */
    unsigned long  lLastTime;        /* ������ʱ��     */
    char           caHost[64];
    unsigned long  lIp;              /* ipadd     */
    uint64	       lBytes;           /* ����         */
    unsigned long  lCount;           /* ����         */
    unsigned long  lTime;            /*      */
    unsigned short intUrlService;         /*      */
} nasHttpBuffer;
/*
cUrlSort
mac��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_HttpBufferhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
} shm_hash_link_HttpBufferhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_HttpBufferindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_HttpBufferindex;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_HttpBuffer {
    int             next;
    nasHttpBuffer   item;
} shm_hash_link_HttpBuffer;


typedef struct nasUserHttpBuffer_s {
	  unsigned long  userid;           /* userid     */
	  int            nUrl;             /* ����httpBuffer��ָ��   */
    unsigned long  lStartTime;       /* ��ʼʱ��     */
    unsigned long  lLastTime;        /* ������ʱ��     */
    uint64	       lBytes;           /* ����         */
    unsigned long  lCount;           /* ����         */
    unsigned long  lTime;            /*              */
} nasUserHttpBuffer;

typedef struct _shm_hash_link_UserHttpBufferhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
} shm_hash_link_UserHttpBufferhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_UserHttpBufferindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_UserHttpBufferindex;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_UserHttpBuffer {
    int                 next;
    nasUserHttpBuffer   item;
} shm_hash_link_UserHttpBuffer;


typedef struct nasDipBuffer_s {
    unsigned long  lStartTime;       /* ��ʼʱ��  0����ϵͳdip�����ܴ��б���ɾ��  */
    unsigned long  lLastTime;        /* ������ʱ��  */
    uint64	       lBytes;           /* ����          */
    uint32         ldip;
    unsigned long  lCount;           /* ����          */
    unsigned long  lTime;            /*               */
    unsigned short cService;         /* ����          */
} nasDipBuffer;
/*
mac��hash���� 
hash ���ڷ����������ͻ������
freecon ���������취,���һ���ı��Ϊnext=-1
*/
typedef struct _shm_hash_link_DipBufferhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
} shm_hash_link_DipBufferhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_DipBufferindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_DipBufferindex;

/*hash���ݶ���,���ݿ������*/
typedef struct _shm_hash_link_DipBuffer {
    int             next;
    nasDipBuffer    item;
} shm_hash_link_DipBuffer;


typedef struct nas2SrvInfo_s {
    unsigned long  lDip;             /* Ŀ��IP��ַ   */
    unsigned short nDport;           /* Ŀ��˿ں�   */
    unsigned char  cType;            /* Э��         */
    unsigned long  lLastTime;        /* ����޸�ʱ�� */
    unsigned short cService;         /* ����         */
} nas2SrvInfo;

typedef struct _shm_hash_link_2SrvInfohead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;
    uint32             nownum;
} shm_hash_link_2SrvInfohead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_2SrvInfoindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_2SrvInfoindex;

/*hash���ݶ���,���ݿ������*/
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


/*�������ƹ���,�������Ǳ���*/
/*
���ȼ��ǣ�
����ʽ������ҵ�����ͽ���
*/

typedef struct msasrvrulehead_s {
    unsigned int       lMaxServiceRuleDIp;
    unsigned int       srvruledipptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       srvruledipsize;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       lMaxRuleIp;
    unsigned int       srvruleipptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       srvruleipsize;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       lMaxWebRule;
    unsigned int       webruleptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       webrulesize;  /*��ͷ��ʼ��ƫ����*/
//    unsigned int       lMaxWebPostRule;
//    unsigned int       webpostruleptr;  /*��ͷ��ʼ��ƫ����*/
//    unsigned int       webpostrulesize;  /*��ͷ��ʼ��ƫ����*/
//    unsigned int       lMaxWebTypeRule;
//    unsigned int       webtyperuleptr;  /*��ͷ��ʼ��ƫ����*/
//    unsigned int       webtyperulesize;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       userlistptr;     /*��ͷ��ʼ��ƫ����*/
    unsigned int       userlistsize;     /*��ͷ��ʼ��ƫ����*/
}msasrvrulehead;


typedef struct msaUserPolicy_s {
	  unsigned int    useflag;          /* 0 or 1 */
    unsigned int    sid;          /* ������ */
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
    char    		    pid[_MAX_ALLPOLICY];     /*ϵͳ�Ĳ���id*/
    char   					grouplist[_MAX_ALLGRPNUM];  /*�û���array��������ʼλ��*/      
} msaUserPolicy;

typedef struct nasSrvRule_s {
    unsigned long   ruleid;          /* ������ */
    char            rulename[32];
    char	    			ruleaction;      /*0�ܾ�    1������*/
    int    					qosid;
    unsigned long   ruleschedule;    /*�ù����schedule*/
//    char            ruleurlsort[101];
    unsigned long   rulejrid;        /*�ù����schedule*/
    char            ruleurl[128];    /*url*/
    int    					logaction;
    int    					conaction;
    char    				srvlist[MAX_SYS_SRVNUM]; /*�����array ������ʼλ��*/
    char    		    pid[_MAX_ALLPOLICY];     /*ϵͳ�Ĳ���id*/
    unsigned long   userlistptr;             /*�û�array��������ʼλ��*/
    char   					grouplist[_MAX_ALLGRPNUM];  /*�û���array��������ʼλ��*/
    long   					ipStart;         /*ip��ַ��array��������ʼλ��*/
    long   					ipEnd;
    unsigned long   urlStart;	       /*url�б� array��������ʼλ��*/
    unsigned long   urlEnd;
//    unsigned long   postStart;	     /*post�б� array��������ʼλ��*/
//    unsigned long   postEnd;    
//    unsigned long   typeStart;	     /*type�б� array��������ʼλ��*/
//    unsigned long   typeEnd; 
    long   					dipStart;	       /*Ŀ��ip��ַ��array��������ʼλ��*/
    long   					dipEnd;   
    nasFlowInfo     nowFlowInfo;  
    nasFlowDayInfo     dayFlowInfo;
//    char   					contenttypelist[_MAX_CONTENTTYPE_NUM];  /*contenttype*/         
} nasSrvRule;


/*������ƹ����Ŀ��ip��ַ�飬��������array ����*/
typedef struct nasSrvRuleDIp_s {
    long   	    ruleid;       /* ������ */
    unsigned long   ipstart;      /*ip�ο�ʼ��ַ*/
    unsigned long   ipend;        /*ip�ν�����ַ*/
} nasSrvRuleDIp;

/*web���ƹ����ip��ַ�飬��������array ����*/
typedef struct nasRuleUrl_s {
    long   	    ruleid;       /* ������ */
    long   	    ruleflag;     /*0:ƥ��webGET����  1:ƥ��webPOST���� 2:ȫ��*/
    char        caUrl[64];    /*url�б�*/
} nasRuleUrl;

///*web���ƹ����ip��ַ�飬��������array ����*/
//typedef struct nasRulePost_s {
//    long   	    ruleid;       /* ������ */
//    char        caUrl[64];      /*url�б�*/
//} nasRulePost;
//
///*web���ƹ����ip��ַ�飬��������array ����*/
//typedef struct nasRuleType_s {
//    long   	    ruleid;       /* ������ */
//    char        caUrl[64];      /*url�б�*/
//} nasRuleType;


/*���ƹ����ip��ַ�飬��������array ����*/
typedef struct nasRuleIp_s {
    long   	    ruleid;       /* ������ */
    unsigned long   ipstart;      /*ip�ο�ʼ��ַ*/
    unsigned long   ipend;        /*ip�ν�����ַ*/
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
	unsigned int  vidtype;  //1QQ;2MSN 3FTP 4POP3 5SMTP�ռ��� 
	char          vid[32];
} VIDINFOHEAD;



typedef struct msaOption_s {
////////////////////////////////�������ݲ��� 	
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
   unsigned int usermon; //�������
/////////////////////////////////��¼�������    
   unsigned int nomondisk;
   unsigned int recordkeepday;
   unsigned int mailkeepday;
   unsigned int aimkeepday;
   unsigned int formkeepday;
   unsigned int historykeepday;
   unsigned int vidkeepday;
   unsigned int userkeepday;
   unsigned int loglevel; //��¼����
/////////////////////////////////���ܲ���    
   unsigned int supportEmail;//�ʼ����ݰ�����
   unsigned int supportForm;//�����ݰ�����
   unsigned int onlineusertype;//�޷�ͬʱ�����߳�ǰһ�û�
   unsigned int noautoadduser;//Ĭ�Ͻ�ֹ�Զ�����û�
   unsigned int attprev;//��������Ԥ�������ݼ���
   unsigned int nopicblock;//����ϸ���ͼƬ���߸����ű�
   int          defaultuserflag;//�û�����ʱĬ��״̬Ϊ����99���ֹ����100
/////////////////////////////////ϵͳ����   
   unsigned int maxuseronlietime;//�����û������ʱ��/��
   unsigned int maxusertimeout;//�����û���ʱʱ��/��
   unsigned int userproccesstime;//�����û����̼��ʱ����
   unsigned int maxtcpsessiontimeout;//���ӳ�ʱʱ��/��
   unsigned int tcpproccesstime;//���ӽ��̼��ʱ����
   float    flowrate;//��������
   float    timerate;//ʱ�����
/////////////////////////////////snmp����    
   unsigned int snmpebable;
   unsigned int snmptimeout;//snmp��Сˢ��ʱ����
   SNMPGROUP gnmsnmpgroup[_MAX_SNMP_NUM]; 
/////////////////////////////////��֤����Ϸ������       
   unsigned int authport;//������֤����˿�
   char     strAuthIP[32];//��֤����ip
   char     strAuthUrl[256];//��������֤����url
   char     denyUrl[256];   //�������ܾ�����ҳ���ַ
   unsigned int supportTCP;//����tcp��ϰ�
   unsigned int supportUDP;//����udp��ϰ�
////////////////////////////////////
   int     mailloglevel;   
   int     formloglevel; 
} msaOption;

typedef struct msaSec_s {
////////////////////////////////�������ݲ��� 	
   unsigned int noping;
   unsigned int adminpasssec;  //1ǿ������
   unsigned int userpasssec;   //1ǿ���û�����
   unsigned int authserver;
   unsigned int sshserver;
} msaSec;

typedef struct nasPPOESession_s {
	  char            ppoename[32];
    unsigned char   mac[6];         /* MAC��ַ */
    unsigned long   ip; 
    unsigned long   sTime; 
} nasPPOESession;

/* �ʼ���ع��˹���  */
typedef struct nasMailFilter_s {
    char   caRname[64];
    char   caFrom[64];
    char   caTo[64];
    char   caSub[64];
    char   caCont[64];
    char   caAtt[64];
    int    lSize;
    int    lAsize;
    short  nFlags;      /* ��� 0:SMTP  1:POP3 2 web*/
    short  nSflags;     /* ֪ͨ��ʽ 0--��֪ͨ  1--֪ͨ  2--ת��  */
    char   caSmail[64]; /* ת������ */
    int    lRnum;
    int    lMaction;
} nasMailFilter;

/* �ʼ���ع��˹���  */
typedef struct nasFormFilter_s {
    char   caRname[64];
    char   caFrom[64];
    char   caHost[64];
    char   caURL[64];
    char   caCon[64];
    char   caAtt[64];
    int    lSize;
    int    lAsize;
    short  nFlags;      /* ��� 0:����  1:���� 2 web*/
    short  nSflags;     /* ֪ͨ��ʽ 0--��֪ͨ  1--֪ͨ  2--ת��  */
    char   caSmail[64]; /* ת������        */
    int    lMaction;    /*��ض���1�����  0�������*/
} nasFormFilter;


/* �ʼ���ع��˹���  */
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

//  eth0/10     ��������y/n	�������� ---     ������   ip��ַ   promisc ѡ��������·
//				����ת��-      
//                  		���ݾ���-
//				nat������--ip
//                                nat������--ip
//                                һ��ͨ�ſ�--ip

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
//0:δ֪  1:application 2:text 3:video 4:audio 5:image 
//inttype:����
//

typedef struct msapkbufhead_s {
	  unsigned int       allheadlen;
    unsigned int       lpkheadNum;
    unsigned int       pkheadptr;   /*��ͷ��ʼ��ƫ����*/
    unsigned int       pkheadsize;  /*��ͷ��ʼ��ƫ����*/
    uint32             writeindexhead;
    uint32             writeindextail;
    unsigned int       lpkNum;
    unsigned int       pkbufptr;    /*��ͷ��ʼ��ƫ����*/
    unsigned int       pkbufsize;    /*��ͷ��ʼ��ƫ����*/
    uint32             freebufhead;
    uint32             freebuftail;
    unsigned int       lCmdBufNum;
    unsigned int       cmdheadptr;   /*��ͷ��ʼ��ƫ����*/
    unsigned int       cmdheadsize;  /*��ͷ��ʼ��ƫ����*/
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
	  unsigned long  lSip;             /* ԴIP��ַ     */
    unsigned long  lDip;             /* Ŀ��IP��ַ   */
    unsigned short nSport;           /* Դ�˿ں�     */
    unsigned short nDport;           /* Ŀ��˿ں�   */
    unsigned char  cType;            /* Э��         */
    unsigned char  buftype;          /* Э��         */
    unsigned long  lStartTime;       /* ��ʼʱ��     */
    unsigned long  lLastTime;        /* ����޸�ʱ�� */
    int            next; /*-1�൱��NULL*/
    int            freenext; /*-1�൱��NULL*/
    unsigned long  pknum;    /*���ݰ���Ŀ  */
} BufferHeadIndex;

/*hash���ݶ���,���ݿ������*/
#define _MAX_PK_MTU    1500
typedef struct _PkBufferIndex {
    int             next;
    unsigned int    pkseq;
    unsigned int    pklen;
    char            pkbuf[_MAX_PK_MTU];
} PkBufferIndex;

#define _MAX_CMD_BUFLEN64     64
#define _MAX_CMD_BUFLEN128    128

//1smtp 2pop3 3qq 4msn 5ftp 6webmail  7���� 8web�˺� 9:SMTP�ռ���
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
    uint64	       lBytes[2];        /* 0-�����ֽ���  1-�����ֽ��� */  
    unsigned short cService;         /* ����         */
    unsigned long  lCount;           /* ���ݰ������� */
    unsigned char  cDirect;          /* ���䷽��*/
} CMDHttpInfo;

typedef struct _CMDHeadIndex {
	  unsigned long  userid;           /* userid     */
	  unsigned char  mac[6];           /* mac     */
	  unsigned long  lSip;             /* ԴIP��ַ     */
    unsigned long  lDip;             /* Ŀ��IP��ַ   */
    unsigned short nSport;           /* Դ�˿ں�     */
    unsigned short nDport;           /* Ŀ��˿ں�   */
    unsigned char  cType;            /* Э��         */
    unsigned char  buftype;          /* Э��         */
    unsigned long  lStartTime;       /* ��ʼʱ��     */
    unsigned long  lLastTime;        /* ����޸�ʱ�� */
    char           pkbufkey1[_MAX_CMD_BUFLEN64];
    char           pkbufkey2[_MAX_CMD_BUFLEN64];
    char           pkbufkey3[_MAX_CMD_BUFLEN128];
    int            pkbufkey4;
    int            freenext; /*-1�൱��NULL*/
} CMDHeadIndex;

//������ݹ켣�б� pop3
//vctype     int,               /*����������� 1smtp 2pop3 3qq 4msn 5ftp 6webmail  7���� 8web�˺š�*/
//vccon  pkbufkey1    varchar(48),        /*���������������*
//vcaction pkbufkey2   int,               /*������ݶ��� 1logon 2logoff 3sendmsg 4sendfile 5��Ƶ 6��Ƶ 7Ӧ�� ��*/
//vcatt pkbufkey3    varchar(128)       /*������ݸ�������*


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
	  char          updateflag[32];     /*����λ��־ */
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
	  int                defaultLan;    /*Ĭ������*/
	  FilterListHead     _FilterListHead;
	  msaTopSrv          topSrvName[MAX_TOP_SRVNUM]; 
	  unsigned int       lServiceNum;
	  msaService         ltService[MAX_SYS_SRVNUM]; /*0:unknown 1-400:sys  401-499:user*/
	  short              srvTcpInConList[64];//�����������б�����һ���ļ��,���http��������
	  short              srvTcpOutConList[64];//�����������б�����һ���ļ��,���http��������
//	  nasUrlSort         _urlSortlist[NAS_MAXURLSORT_NUM];
//	  nasTopUrlSort      _topurlSortlist[NAS_MAXTOPURLSORT_NUM]; 
	  nasschtime         _schtimelist[NAS_MAXSCH_NUM];
	  nasjjrtime         _jjrtimelist[NAS_MAXJJR_NUM];
	  nasPortInfo        ltPortInfo[MAX_PORTNUM];
	  _pNetArea          ltNetArea[_MAXNETAREANUM];  /*ȫ��������� */
	  _pNetArea          NetAreaCkeck[_MAXNETAREANUM];   /*���������  */ 
	  SNMPINFOHEAD       ltSnmpGroup[_MAX_SNMP_NUM];
	  unsigned  int      nowvidnum;
	  VIDINFOHEAD        _vidinfohead[_MAXVIDNUM];
	  unsigned  int      snmplockflag;
	  nasMylAdd          myAdd[20];        /*���������ip��ַ*/
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
    unsigned long  lSip;             /* ��ʼIP    */
    unsigned short nSport;           /* ��ʼport   */
    unsigned long  lDip;            
    unsigned short nDport;
    unsigned short cProt;             /* Э��*/           
    unsigned char  cFlag;             /* ������ĺ�*/
    unsigned char  cAction;           /* ������ĺ�*/
    unsigned short qoschanel0;
    unsigned short qoschanel1;        /* Э��*/  
    unsigned long  lLastTime;         /* ��ʼʱ�� */
    int            direct;            /* ���� */
} msaSSNControl;

typedef struct _shm_hash_link_Controlhead {
    unsigned int       bufptr;  /*��ͷ��ʼ��ƫ����*/
    unsigned int       bufsize;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       conbufptr;  /*��ͷ��ʼ��ƫ����*/ 
    unsigned int       bufnum;
    uint32             freecontenthead;
    uint32             freecontenttail;           
    uint32             nownum;
} shm_hash_link_Controlhead;

/*hash index ����index�ֲ�*/
typedef struct _shm_hash_link_Controlindex {
    int           next; /*-1�൱��NULL*/
} shm_hash_link_Controlindex;

/*hash���ݶ���,���ݿ������*/
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
	unsigned long  lSip;       /* ԴIP��ַ     */
	char     caSmac[6];        /* ԴMAC��ַ    */
	unsigned short nSport;     /* Դ�˿�       */
	unsigned long  lDip;       /* Ŀ��IP��ַ   */
	char     caDmac[6];        /* Ŀ��MAC��ַ  */
	unsigned short nDport;     /* Ŀ��˿�     */
	unsigned short    cTran;            /* ���ͷ��� 0--���� 1--����    */
	unsigned short    cProp;            /* Э��  6 UDP      17 TCP     */
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
ltDbConn     *G_DbCon; /*������������̵����ݿ�����*/
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
    char     pOriginFile[128];   /* Դ�ļ�    */
    char     pType[64];          /* �ļ�����  */
    char     pOutFile[64];
    unsigned long lSize; 
    struct nasPostFileList_s *psNext;   
} nasPosFileList;

typedef struct nasPostDataHead_s {
    char           caBound[128];     /* caBound    */
    char           caHost[64];    /* ������    */
    char           caUrl[128];     /* ����URL   */
    char           caUser[64];     /* ����URL   */
    unsigned long  lTime;          /* ʱ��      */
} nasPostDataHead;

typedef struct nasPostDataContent_s {
    unsigned long  lBytes;         /* ���ֽ���  */
//    char           *pValue;        /* ��������  */
    int            iSum;           /* ��������  */
    nasPosFileList  *psFileList;    /* �ļ��б�  */
} nasPostDataContent;


typedef struct DbMsgHead_s{
	  uint32   lMaxBytes;
    uint32   lBytes;      /*  Message Bytes include the head      */
    char     character[24];
    uint32   lSendTime;   /*  Send Time                           */
    uint8    nVersion;    /*  Message Version                     */
    uint8    cCrypt;      /*  0-- No Crypt 1--DES  0-- baochuang  */
    char     strFile[128];//�洢������λ��
    uint8    lAttNum;   
    uint32   lMsgSize;  
} DbMsgHead;

typedef struct DbMsgAtt_s{
    char           attFileName[64];     //�洢����������
    char           attDispName[64];     //�洢��������ʾ����
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
int vserver(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//�������������ҳ��
int ltVPSok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//�������������
int ddnsset(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//����DDNS����ҳ��
int ltDDNSok(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//����DDNS����
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
int addService(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//��ӹ���
int showEditService(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);//��ӹ���ҳ��
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
MSA:��������
				����ģ��
						�½�����ģ��
����:���ӵ�����ģ��ҳ����ú���
*/
int msareporttemplate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�½�����ģ��ȷ���ύ����
int reporttemplate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//���Ѷ��屨��ģ��
int toreporttemplatelist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�鿴ģ�庯��
int reporttempledit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�����ģ�屨��
int templatereportlista(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�Զ����ɵı����б�
int toautoreportlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//ÿ����ܱ����б�
int toreportlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�Ѷ��屨��ģ�� �������ɱ���
int reportcreate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�Ѷ��屨��ģ�� �������ɱ��� ���ɱ��� ������ͼҳ��
int toreportcreate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//ģ���޸ĵ��ú���
int reporttemplateupdate(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
//�������ɱ��� �����б�����������ú���
int templatereportlist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-report-sortreport.c*/
/*���򱨸�ҳ�����Ӻ���*/
int msasortreportlink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*���򱨸����ɺ���*/
int msasortreport(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-userline.c*/
/*
MSA:��������
				�û�����
����:���߱��洴�����ú���
*/
int msaReportUserLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-webline.c*/
/*
MSA:��������
				WEB����
����:web���߱��洴�����ú���
*/
int msaReportWebLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-srvline.c*/
/*
MSA:��������
				��������
����:�������߷������洴�����ú���
*/
int msaReportSrvLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
���ܣ����ɵı����б���ʾ
*/
int msaReportRecordJson(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
���ܣ����ɵı����б�JSONstore���캯��
*/
int msaReportJsonStore(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);


/*srv-report-flowline.c*/
/*
MSA:��������
				��������
����:�������߷������洴�����ú���
*/
int msaReportFlowLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-report-linereport.c*/
/*
MSA:��������
				ϵͳ����
����:ʵ�ֱ��洴���ĺ������� sysstep1->sysstep5*/
int msaReportSysLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:�������� �������
����:ʵ��������ձ��洴���ĺ������� riskstep1->riskstep5
*/
int msaReportRsikLineAjaxSubmit(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-data-data.c*/
/*
 MSA:��������
     		 ������ʼ�¼����
 ����:��������ѯ����������|ֱ�ӵ�������ʱ����������
 */
int msaipbacksearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
    ��ϸ���ʼ�¼
        ������ϼ�¼����
����:��¼�������������룬�Լ�gird����¼ɾ������
*/
int msaNewSearchList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
 MSA:��������
     ��ϸ���ʼ�¼
         ������ʼ�¼
         ��Ϸ��ʼ�¼
         HTTP���ʼ�¼
 ���ܣ�ҳ�����ӵ��ú���
 */
int msaShowAccessList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
 MSA:��������
     ������ʼ�¼����
     ������ϼ�¼����
     http���ʼ�¼����
 ����:ҳ�����ӵ��ú���
 */
int msaShowAccessSearch(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
 MSA:��������
     ��ϸ���ʼ�¼
     		 ������ʼ�
 ����:�б���ʾ����ʱ����ʼ�¼���ú���
 */
int msaAccessList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
    ��ϸ���ʼ�¼
        ������ʼ�¼
����:���ر�ʱ���ļ�
*/
int msaBackListDownLoadCSV(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				�����ؼ���
����:�ؼ����б��ѯ,����,ɾ��
*/
int ltmsasearchkeyhttpa(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				�����ؼ���
����:�ؼ��б�ҳ�����Ӻ���
*/
int ltmsasearchkeyquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
		��ʱͨ�ż�¼
				MSN,Yahoo,QQ,�Ա�,����,skype
����:ҳ�����ӵ��ú���
*/
int ltimshowwebquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				��ʱͨ�ż�¼
				    MSN,Yahoo,�Ա�,����,qq,skype
����:��¼���ݲ�ѯ ���� ɾ��
*/
int ltwebqueryima(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				�ļ������¼
����:�ļ������¼���ڵ�����ҳ����ú���
*/
int ltmsafiletranquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				�ļ������¼
����:�ļ������¼��ѯ��������ɾ��
*/
int ltmsafilequery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				POP3/SMTP�ʼ�
����:�����ʼ���ѯ 
����:���ͣ����գ�������������1M�����ϱ������ԣ����Ϲؼ��ֱ��� 
��������:����������ӡ��ҳ��ģ�����
*/
int ltmsadaymailquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				POP3/SMTP�ʼ�
����:�����ʼ�grid������ʾjson���캯��
*/
int ltmsadaymaillist(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
				POP3,SMTP�ʼ�
����:�ʼ�ȫ�ļ���				
*/
int ltmsamail(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
����:�û�combox��json���� 
*/
int msalocalStore(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);



/*srv-data-form.c*/
/*
MSA:��������
        ���ύ����
����:���ձ���¼��ѯ
*/
int msaformList(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
����:������ݼ�¼ҳ������
*/
int ltmsavcloglink(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
			������ݼ�¼
����:��¼���ݲ�ѯ ���� ɾ��
*/
int ltmsavclogquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
			�ʼ�
����:pop3/smtp�ʼ���¼��ѯ/ɾ��/����
*/
int ltmsamailquery(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
�ʼ��ͱ�������ʾ����
*/
int msaShowContent(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-data-people.c*/
/*
MSA:��������
        ��Ա����
����:�û������캯��
*/
int msaUserTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*srv-data-time.c*/
/*
MSA:��������
				��������
����:����������
*/
int msaDateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
        ��������
����:�����������ҳ�溯��
*/

int msaShowTimeRecord(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);

/*srv-data-conkeysech.c*/
/*
MSA:��������
        ���ݹؼ�������
����:������������ͼҳ��
*/

int msaSearchKeyWord(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
		���ݹؼ��ּ���
����:��������ͼҳ��:��������������
*/
int msaSearchkeyDateTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
    ���ùؼ���
����:�������ùؼ���ͼҳ�沢ʵ�ֹؼ��ֵ���ɾ
*/


/*srv-service-tree.c*/
/*
MSA:��������
    ����ѡ����
    һ��������
*/
int msaOneServiceTree(int confd,ltMsgHead *ltMsgPk,lt_shmHead *lt_MMHead);
/*
MSA:��������
    ����ѡ����
    ����������
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


