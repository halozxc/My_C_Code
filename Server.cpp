//
// Server.cpp
//
// Extremely simple, stream server example.
// Works in conjunction with Client.cpp.
//
// The program sets itself up as a server using the TCP
// protoocl. It waits for data from a client, displays
// the incoming data, sends a message back to the client
// and then exits.
//
// Compile and link with wsock32.lib
// #pragma comment(lib,"wsock32.lib")
//
// Pass the port number that the server should bind() to
// on the command line. Any port number not already in use
// can be specified.
//
// Example: Server 2020
//

#include <stdio.h>
#include <winsock.h>

// Function prototype
void StreamServer(short nPort);

// Helper macro for displaying errors
#define PRINTERROR(s)	\
		fprintf(stderr,"\n%: %d\n", s, WSAGetLastError())

////////////////////////////////////////////////////////////
struct head
{
	char filename[250];
	unsigned filelen;
} forsend;
FILE * fp;
int blocksize=1460;//每次传送数据块的长度
////////////////////////////////////////////////////////////

void main(int argc, char **argv)
{
	WORD wVersionRequested = MAKEWORD(1,1);
	WSADATA wsaData;
	int nRet;
	short nPort;
    
	//
	// Check for port argument
	//

    //argc=2;
	//argv[1]="2222";

	if (argc != 2)
	{
		fprintf(stderr,"\nSyntax: server PortNumber\n");
		return;
	}

	nPort = atoi(argv[1]);

	//
	// Initialize WinSock and check version
	//
	nRet = WSAStartup(wVersionRequested, &wsaData);
	if (wsaData.wVersion != wVersionRequested)
	{	
		fprintf(stderr,"\n Wrong version\n");
		return;
	}
	//
	// Do the stuff a stream server does
	//
	StreamServer(nPort);
	//
	// Release WinSock
	//
	WSACleanup();
}

////////////////////////////////////////////////////////////

void StreamServer(short nPort)
{
	//
	// Create a TCP/IP stream socket to "listen" with
	//
	SOCKET	listenSocket;

	listenSocket = socket(AF_INET,			// Address family
						  SOCK_STREAM,		// Socket type
						  IPPROTO_TCP);		// Protocol
	if (listenSocket == INVALID_SOCKET)
	{
		PRINTERROR("socket()");
		return;
	}
	//
	// Fill in the address structure
	//
	SOCKADDR_IN saServer;		

	saServer.sin_family = AF_INET;
	saServer.sin_addr.s_addr = INADDR_ANY;	// Let WinSock supply address
	saServer.sin_port = htons(nPort);		// Use port from command line
	//
	// bind the name to the socket
	//
	int nRet;
	nRet = bind(listenSocket,				// Socket 
				(LPSOCKADDR)&saServer,		// Our address
				sizeof(struct sockaddr));	// Size of address structure
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("bind()");
		closesocket(listenSocket);
		return;
	}

	//
	// This isn't normally done or required, but in this 
	// example we're printing out where the server is waiting
	// so that you can connect the example client.
	//
	int nLen;
	nLen = sizeof(SOCKADDR);
	char szBuf[20000];
    
	nRet = gethostname(szBuf, sizeof(szBuf));
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("gethostname()");
		closesocket(listenSocket);
		return;
	}

	//
	// Show the server name and port number
	//
	printf("\nServer named %s waiting on port %d\n",
			szBuf, nPort);

	//
	// Set the socket to listen
	//

	printf("\nlisten()");
	nRet = listen(listenSocket,					// Bound socket
				  SOMAXCONN);					// Number of connection request queue
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("listen()");
		closesocket(listenSocket);
		return;
	}

	//
	// Wait for an incoming request
	//
	SOCKET	remoteSocket;

	printf("\nBlocking at accept()");
	remoteSocket = accept(listenSocket,			// Listening socket
						  NULL,					// Optional client address
						  NULL);
	if (remoteSocket == INVALID_SOCKET)
	{
		PRINTERROR("accept()");
		closesocket(listenSocket);
		return;
	}

	//
	// We're connected to a client
	// New socket descriptor returned already
	// has clients address

	//
	// Receive data from the client
	//
	memset(szBuf, 0, sizeof(szBuf));
    nRet = recv(remoteSocket,					// Connected client
				(char *)&forsend,							// Receive buffer
				sizeof(forsend),					// Lenght of buffer
				0);								// Flags
	if (nRet == INVALID_SOCKET)
	{
		PRINTERROR("recv()");
		closesocket(listenSocket);
		closesocket(remoteSocket);
		return;
	}


	///////////////////
    //strcpy(forsend.filename,"new_f");
	///////////////////
	fp=fopen(forsend.filename,"wb");
	if(!fp) 
	{
		strcpy(forsend.filename,"newfile");
		fp=fopen(forsend.filename,"wb");
	}
    if(!fp) 
		{
		printf("Cant't create a new file!");
		closesocket(listenSocket);
		closesocket(remoteSocket);
		return;
	}
    printf("\nNow Begin to receive file:%s, length:%d bytes.\n",forsend.filename,forsend.filelen);
   
	int total=0; //接收记数
    while (total<forsend.filelen)
	{

		nRet = recv(remoteSocket,					// Connected client
				szBuf,							// Receive buffer
				1000,					// Lenght of buffer
				0);								// Flags
		if (nRet == SOCKET_ERROR)
		{
			PRINTERROR("recv() ");
			closesocket(listenSocket);
			closesocket(remoteSocket);
			return;
		}
		else
		
		{
			total+=nRet;
			fwrite(szBuf,nRet,1,fp);
			//if (!nRet) break;
		}
	};

	fclose(fp);
	printf("\nFile %s received!\n", forsend.filename);


	//
	// Close BOTH sockets before exiting
	//
	closesocket(remoteSocket);
	closesocket(listenSocket);
	return;
}

