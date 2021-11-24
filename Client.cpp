//
// Client.cpp
//
// Extremely simple, stream client example.
// Works in conjunction with Server.cpp.
//
// The program attempts to connect to the server and port
// specified on the command line. The Server program prints
// the needed information when it is started. Once connected,
// the program sends data to the server, waits for a response
// and then exits.
//
// Compile and link with wsock32.lib
// #pragma comment(lib,"wsock32.lib")
//
// Pass the server name and port number on the command line. 
//
// Example: Client MyMachineName 2020
//
#include <stdio.h>
#include <winsock.h>

// Function prototype
void StreamClient(char *szServer, short nPort);

// Helper macro for displaying errors
#define PRINTERROR(s)	\
		fprintf(stderr,"\n%: %d\n", s, WSAGetLastError())

////////////////////////////////////////////////////////////
struct head
{
	char filename[250];
	unsigned  filelen;
} forsend;
FILE * fp;
int blocksize=1460;//ÿ�δ������ݿ�ĳ���
////////////////////////////////////////////////////////////
void presend()
{
  char filename[250];
re:
  printf("Input file to be sent:");
  gets(filename);
  fp=fopen(filename,"rb");
  if(!fp) {printf(" File not existing!\n");goto re;}
  strcpy(forsend.filename,filename);
re2:
  printf("Input data block size sent:");
  fflush(stdin);
  scanf("%d",&blocksize);
  if (blocksize<=0)  goto re2;
  fseek(fp,0,SEEK_END);
  forsend.filelen =ftell(fp);
  if (feof(fp)) forsend.filelen =0;
  fseek(fp,0,SEEK_SET);
  printf("Total bytes of the file:%d\n",forsend.filelen);
  printf("Now begin to send file %s...\n",forsend.filename);
}


int main(int argc, char **argv)
{
	WORD wVersionRequested = MAKEWORD(1,1);
	WSADATA wsaData;
	int nRet;
	short nPort;

	//
	// Check for the host and port arguments
	//
	if (argc != 3)
	{
		fprintf(stderr,"\nSyntax: client ServerName PortNumber\n");
		return 0;
	}
	nPort = atoi(argv[2]); 
	//
	// Initialize WinSock and check the version
	//
	nRet = WSAStartup(wVersionRequested, &wsaData);
	if (wsaData.wVersion != wVersionRequested)
	{	
		fprintf(stderr,"\n Wrong version\n");
		return 0;
	}
	//
	presend();
	// Go do the stuff a stream client does
	//
	StreamClient(argv[1], nPort);
	//
	// Release WinSock
	//
	WSACleanup();
}

////////////////////////////////////////////////////////////

void StreamClient(char *szServer, short nPort)
{
	
	printf("\nStream Client connecting to server: %s on port: %d",
				szServer, nPort);

	//
	// Find the server
	//
    LPHOSTENT lpHostEntry;
	lpHostEntry = gethostbyname(szServer);
    if (lpHostEntry == NULL)
    {
        PRINTERROR("gethostbyname()");
        return;
    }
	//
	// Create a TCP/IP stream socket
	//
	SOCKET	theSocket;

	theSocket = socket(AF_INET,				// Address family
					   SOCK_STREAM,			// Socket type
					   IPPROTO_TCP);		// Protocol
	if (theSocket == INVALID_SOCKET)
	{
		PRINTERROR("socket()");
		return;
	}
	//
	// Fill in the address structure
	//
	SOCKADDR_IN saServer;
	saServer.sin_family = AF_INET;
	saServer.sin_addr = *((LPIN_ADDR)*lpHostEntry->h_addr_list);
										// ^ Server's address
	saServer.sin_port = htons(nPort);	// Port number from command line
	//
	// connect to the server
	//
	int nRet;
	nRet = connect(theSocket,				// Socket
				   (LPSOCKADDR)&saServer,	// Server address
				   sizeof(struct sockaddr));// Length of server address structure
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("socket()");
		closesocket(theSocket);
		return;
	}
    //Send file head to the server
    nRet = send(theSocket,				// Connected socket
			   (char *)&forsend,				
			   sizeof(forsend),			// Length of data
			   0);					// Flags
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("send()");
		closesocket(theSocket);
		return;
	}

	//
	// Send data to the server
	//
	char buf[20000];
	int numsent=0; //���ͼ���
	if(blocksize>20000) blocksize=20000;
	
	while (numsent<forsend.filelen)
	{
		for(int i=0;i++;i<100); //delay
        if(blocksize<=forsend.filelen-numsent)
		{fread(buf,blocksize,1,fp);
		 nRet=send(theSocket,buf,blocksize,0);	
		 numsent+=blocksize;
		}
		else 
		{fread(buf,forsend.filelen-numsent,1,fp);
		 nRet=send(theSocket,buf,forsend.filelen-numsent,0);
		 numsent=forsend.filelen;
		}		
			   
		if (nRet == SOCKET_ERROR)
		{
			PRINTERROR("send()");
			closesocket(theSocket);
			return;
		}
	}

	//
    fclose(fp);
	printf("\nFile transfer is over !");
	closesocket(theSocket);
	return;
}

