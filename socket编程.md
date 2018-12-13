# socket 编程

##  winsocket2 函数库

### 语法
```
SOCKET WSAAPI socket(
  int af,
  int type,
  int protocol
);
```

### 参数

- ```af``` 地址簇规范
当前支持的值是AF_INET或AF_INET6，它们是IPv4和IPv6的Internet地址系列格式。( ```The values currently supported are AF_INET or AF_INET6, which are the Internet address family formats for IPv4 and IPv6.``` ),	
 常用的地址簇：
 
|AF|Meaning|
|:---|---|
|**AF_UNSPEC** `0`|The address family is unspecified. |
|**AF_INET** `2`|The Internet Protocol version 4 (IPv4) address family. |
|**AF_INET6** 23|The Internet Protocol version 6 (IPv6) address family. |

- `type` 新套接字的类型规范。

windows socket 2支持的`type`参数(部分)

|Type|Meaning|
|---|---|
|**SOCK_STREAM** `1`|一种套接字类型，提供带有OOB数据传输机制的顺序，可靠，双向，基于连接的字节流。 此套接字类型使用传输控制协议（TCP）作为Internet地址系列（AF_INET或AF_INET6）。|
|**SOCK_DGRAM** `2`|一种支持数据报的套接字类型，它是固定（通常很小）最大长度的无连接，不可靠的缓冲区。 此套接字类型使用用户数据报协议（UDP）作为Internet地址系列（AF_INET或AF_INET6）。|
|**SOCK_RAW**  `3`|一种套接字类型，提供允许应用程序操作下一个上层协议头的原始套接字。 要操作IPv4标头，必须在套接字上设置IP_HDRINCL套接字选项。 要操作IPv6标头，必须在套接字上设置IPV6_HDRINCL套接字选项。|


- ```protocol```协议

如果指定值0，则调用者不希望指定协议，服务提供者将选择要使用的协议。 

[common values for the protocol](https://docs.microsoft.com/en-us/windows/desktop/api/winsock2/nf-winsock2-socket)

### 返回值（Return Value）

如果没有错误发生，socket返回一个新套接字的描述符；如果发生错误，将返回```INVALID_SOCKET```，通过调用　```WSAGetLastError```，可以得到具体的错误代码。


demo实例

```
	#pragma comment(lib,"Ws2_32.lib")  //link Ws2_32.lib
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#include <stdio.h>
	#include <stdlib.h>   // Needed for _wtoi
	int main(){
		WSADATA wsaData = {0};
		SOCKET sock = INVALID_SOCKET;
		int iFamily = AF_UNSPEC;
        int iType = 0;
        int iProtocol = 0;
	    iFamily = _wtoi(argv[1]);
	    iType = _wtoi(argv[2]);
	    iProtocol = _wtoi(argv[3]);
		int iReturn=0;
		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
	        wprintf(L"WSAStartup failed: %d\n", iResult);
	        return 1;
	    }
	    socket=socket(iFamily,iType,iProtocol);
	    if (sock == INVALID_SOCKET) 
	        wprintf(L"socket function failed with error = %d\n", WSAGetLastError() );
	    else {
	        wprintf(L"socket function succeeded\n");
			// Close the socket to release the resources associated
	      // Normally an application calls shutdown() before closesocket 
	      //   to  disables sends or receives on a socket first
	     // This isn't needed in this simple sample
	      iResult = closesocket(sock);
		  if (iResult == SOCKET_ERROR) {
	           wprintf(L"closesocket failed with error = %d\n", WSAGetLastError() );
	           WSACleanup();
	           return 1;
		    }    
	    }
		WSACleanup();	
}

```

## sockaddr

> sockaddr结构取决于所选的协议。 除sin * _family参数外，sockaddr内容以网络字节顺序表示。

下面的sockaddr结构和sockaddr_in结构与IPv4一起使用。 其他协议使用类似的结构。

```
struct sockaddr {
        ushort  sa_family;
        char    sa_data[14];
};

struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};

```

下面的sockaddr_in6和sockaddr_in6_old结构与IPv6一起使用。

```

struct sockaddr_in6 {
        short   sin6_family;
        u_short sin6_port;
        u_long  sin6_flowinfo;
        struct  in6_addr sin6_addr;
        u_long  sin6_scope_id;
};

typedef struct sockaddr_in6 SOCKADDR_IN6;
typedef struct sockaddr_in6 *PSOCKADDR_IN6;
typedef struct sockaddr_in6 FAR *LPSOCKADDR_IN6;


struct sockaddr_in6_old {
        short   sin6_family;        
        u_short sin6_port;          
        u_long  sin6_flowinfo;      
        struct  in6_addr sin6_addr;  
};

```

实例代码
```

// Declare variables
SOCKET ListenSocket;
struct sockaddr_in saServer;
hostent* localHost;
char* localIP;

// Create a listening socket
ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

// Get the local host information
localHost = gethostbyname("");
localIP = inet_ntoa (*(struct in_addr *)*localHost->h_addr_list);

// Set up the sockaddr structure
saServer.sin_family = AF_INET;
saServer.sin_addr.s_addr = inet_addr(localIP);
saServer.sin_port = htons(5150);

// Bind the listening socket using the
// information in the sockaddr structure
bind( ListenSocket,(SOCKADDR*) &saServer, sizeof(saServer) );

```

## bind function

bind 函数将本地地址和一个套接字相关联

### 语法
```
int bind(
  SOCKET         s,
  const sockaddr *addr,
  int            namelen
);

```
### 参数

- `s` 
一个未绑定的socket

- `addr`

一个指向要分配给绑定套接字的sockaddr结构的指针。
- `namelen`

name参数指向的值的长度（以字节为单位）。

### 返回值

如果没有错误发生，返回0,否则返回SOCKET_ERROR,同样调用WSAGetLastError可以得到具体错误代码。



## listen function

### 语法
 
```
int WSAAPI listen(
  SOCKET s,
  int    backlog
);
```

### 参数

- ```s```

 一个绑定的，未连接（unconnected)套接字

- ```blacklog``` 

挂起连接队列的最大长度。 如果设置为SOMAXCONN，则负责套接字的底层服务提供程序会将backlog设置为最大合理值。 如果设置为SOMAXCONN_HINT（N）（其中N是数字），则积压值将为N，调整为在范围（200,65535）内。 请注意，SOMAXCONN_HINT可用于将积压设置为比SOMAXCONN更大的值。
SOMAXCONN_HINT仅受Microsoft TCP / IP服务提供商支持。 没有标准条款来获取实际的积压值。

### 返回值

如果没有错误发生，listen 返回 0,否则，将返回```SOCKET_ERROR```, 同样调用　WSAGETLastError可以得到错误码。

```
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int wmain()
{

    //----------------------
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = 0;

    SOCKET ListenSocket = INVALID_SOCKET;
    sockaddr_in service;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup() failed with error: %d\n", iResult);
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for incoming connection requests.
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //获取一个新的socket实例
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    service.sin_port = htons(27015);

    iResult = bind(ListenSocket, (SOCKADDR *) & service, sizeof (service));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"bind function failed with error %d\n", WSAGetLastError());
        iResult = closesocket(ListenSocket);
        if (iResult == SOCKET_ERROR)
            wprintf(L"closesocket function failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // Listen for incoming connection requests 
    // on the created socket
    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
        wprintf(L"listen function failed with error: %d\n", WSAGetLastError());

    wprintf(L"Listening on socket...\n");

    iResult = closesocket(ListenSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket function failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    WSACleanup();
    return 0;
}


```


## accept function 

### 语法

```
SOCKET WSAAPI accept(
  SOCKET   s,
  sockaddr *addr,
  int      *addrlen
);
```

### 参数
- ```s```
socket

- ```addr```

- ```addrlen```

### 返回值

没有错误发生，accept返回一个SOCKET对象（新套接字对象），此返回值是进行实际连接的套接字的句柄。否则返回```INVALID_SOCKET```, 可调用WSAGetLastError.

## connect function

> connect 建立和一个特定的socket的连接

### 语法

```
int WSAAPI connect(
  SOCKET         s,
  const sockaddr *name,
  int            namelen
);
```

### 参数

- ```s```
- ```name```
- ```namelen``` 

### 返回值

如果没有错误发生返回0;否则返回SOCKET_ERROR,可调用WSAGetLastError

```
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int wmain()
{
    //----------------------
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup function failed with error: %d\n", iResult);
        return 1;
    }
    //----------------------
    // Create a SOCKET for connecting to server
    SOCKET ConnectSocket;
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port of the server to be connected to.
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientService.sin_port = htons(27015);

    //----------------------
    // Connect to server.
    iResult = connect(ConnectSocket, (SOCKADDR *) & clientService, sizeof (clientService));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"connect function failed with error: %ld\n", WSAGetLastError());
        iResult = closesocket(ConnectSocket);
        if (iResult == SOCKET_ERROR)
            wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    wprintf(L"Connected to server.\n");

    iResult = closesocket(ConnectSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    WSACleanup();
    return 0;
}

```

## timeval structure

### 语法：
```
typedef struct timeval {
  long tv_sec;
  long tv_usec;
} TIMEVAL, *PTIMEVAL, *LPTIMEVAL;
```
### 成员
- `tv_sec`
时间间隔，以秒为单位。
- `tv_usec`
时间间隔，以微秒为单位。此值与tv_sec成员结合使用，表示不是秒的倍数的时间间隔值。


## select function 

> 使用Select就可以完成非阻塞（所谓非阻塞方式non-block，就是进程或线程执行此函数时不必非要等待事件的发生，一旦执行肯定返回，以返回值的不同来反映函数的执行情况，如果事件发生则与阻塞方式相同，若事件没有发生则返回一个代码来告知事件未发生，而进程或线程继续执行，所以效率较高）方式工作的程序，它能够监视我们需要监视的文件描述符的变化情况——读写或是异常。
> select 函数的性能比较差、linux 下`epoll`的性能比较优秀

### 语法

```
int WSAAPI select(
  int           nfds,
  fd_set        *readfds,
  fd_set        *writefds,
  fd_set        *exceptfds,
  const timeval *timeout
);

```

### 参数

- `nfds`
Ignored. The nfds parameter is included only for compatibility with Berkeley sockets.

- `readfds`
指向要检查可读性的一组套接字的可选指针。
fd_set *readfds是指向fd_set结构的指针，这个集合中应该包括文件描述符，我们是要监视这些文件描述符的读变化的，即我们关心是否可以从这些文件中读取数据了，如果这个集合中有一个文件可读，select就会返回一个大于0的值，表示有文件可读；如果没有可读的文件，则根据timeout参数再判断是否超时，若超出timeout的时间，select返回0，若发生错误返回负值。可以传入NULL值，表示不关心任何文件的读变化。

- `writefds`
指向要检查可写性的一组套接字的可选指针。
与readfds唯一不同的是关心写变化

- `exceptfds`
指向要检查错误的一组套接字的可选指针。
同上面的意图，用来监视文件错我异常文件。
- `timeouot`
select以等待的最长时间，以TIMEVAL结构的形式提供。对于阻塞操作，将timeout参数设置为null。
struct timeval* timeout是select的超时时间，这个参数至关重要，它可以使select处于三种状态，第一，若将NULL以形参传入，即不传入时间结构，就是将select置于阻塞状态，一定等到监视文件描述符集合中某个文件描述符发生变化为止；第二，若将时间值设为0秒0毫秒，就变成一个纯粹的非阻塞函数，不管文件描述符是否有变化，都立刻返回继续执行，文件无变化返回0，有变化返回一个正值；第三，timeout的值大于0，这就是等待的超时时间，即 select在timeout时间内阻塞，超时时间之内有事件到来就返回了，否则在超时后不管怎样一定返回，返回值同上述。


### 返回值

select函数返回已准备好并包含在fd_set结构中的套接字句柄总数，如果时间限制已过期则返回零，如果发生错误则返回SOCKET_ERROR。如果返回值为SOCKET_ERROR，则可以使用WSAGetLastError检索特定的错误代码。

## fd_set struct

### 语法
```
typedef struct fd_set {
  u_int  fd_count;
  SOCKET fd_array[FD_SETSIZE];
} fd_set, FD_SET, *PFD_SET, *LPFD_SET;
```

### 成员

- `fd_count`
套接字的数量
- fd_array
套接字数组
  
  struct fd_set ，可以理解为一个集合，实际上是一个位图，每一个特定为来标志相应大小文件描述符，这个集合中存放的是文件描述符(file descriptor)，即文件句柄(也就是位图上的每一位都能与一个打开的文件句柄(文件描述符)建立联系，这个工作由程序员来完成)，这可以是我们所说的普通意义的文件，当然Unix下任何设备、管道、FIFO等都是文件形式，全部包括在内，所以毫无疑问一个socket就是一个文件，socket句柄就是一个文件描述符。fd_set集合可以通过一些宏由人为来操作，程序员通过操作4类宏，来完成最fd_set的操作：

1. **FD_ZERO(fd_set *)**  清空一个文件描述符集合；
2. **FD_SET(int ,fd_set *)**将一个文件描述符添加到一个指定的文件描述符集合中；
3. **FD_CLR(int ,fd_set*)**       将一个给定的文件描述符从集合中删除；
4. **FD_ISSET(int ,fd_set* )**检查集合中指定的文件描述符是否可以读写。

深入的理解select模型的关键点在于理解fd_set，为了说明方便，我们取fd_set长度为1个字节，fd_set中的每一个bit可以对应一个文件描述符fd。则1字节长的fd_set最大可以对应8个fd。

（1）执行fd_set set；FD_ZERO(&set)；则set用位表示为 0000,0000 。

（2）若fd = 5 ，则执行 FD_SET(fd,&set)后，set变为 0001，0000 （第5位置为1）

（3）若再加入fd=2 ，fd=1，则set变为 0001.0011

（4）执行select(6,&set,0,0,0)阻塞等待

（5）若fd=1,fd=2上都发生可读事件，则select返回，此时set变为0000，0011。没有可读事件发生时 fd = 5 被清空。

> select function部分和fd_set部分参考了　select函数详解及实例分析
>作者：eten 
>来源：CSDN 
>原文：>https://blog.csdn.net/leo115/article/details/8097143 
