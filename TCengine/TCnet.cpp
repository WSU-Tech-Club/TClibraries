#include "TCnet.h"

//Class Constructor
//
//Parameters: 
//	verbose - whether or not the object should echo back the results of its actions
//
//Initializes the SDLNet framework`
//also sets port and remoteIP to null type values so the object 
//can tell if they have been set when trying to connect.
TCnetObjTCP::TCnetObjTCP(bool verbose = false)
{
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	port = -1;
	remoteHost = "";

	talkative = verbose;
}

//Class Constructor
//
//same as first constructor except this takes in address and port values
//and sets them.
TCnetObjTCP::TCnetObjTCP(bool verbose, string nRemoteIP, unsigned int nPort)
{
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	setIp(nRemoteIP);
	setPort(port);

	talkative = verbose;
}

//Destructor
TCnetObjTCP::~TCnetObjTCP()
{
	if(myIP != NULL)
		delete myIP;
	if(remoteIP != NULL)
		delete remoteIP;
}

//setIP
//
//Sets the IP address that this object will interact with
//
//Returns: 1 always (kept return type as int to allow for later error checking)
int TCnetObjTCP::setIp( string newIP )
{
	this->remoteHost = newIP;
	if(talkative)
		printf("Remote address set.\n");

	return 1;
}

//setPort
//
//takes in an unsigned int to set the port that this object
//will interface over
//error checks to make sure 
//
//Returns:
//	0 - number passed in is an invalid number for a port
//	1 - port successfuly set to the given number
int TCnetObjTCP::setPort( unsigned int newPort )
{
	if(newPort <= 0 || newPort > 65535)
	{
		printf("ERROR: invalid port number, port not set.\n");
		return 0;
	}
	this->port = newPort;
	if(talkative)
		printf("Port set.\n");
	return 1;
}

//connect
//
//checks first to make sure the remoteIP and port have been set
//then resolves the hostname and opens the socket
//
//Returns:
//	0 - connection failed
//	1 - connection succeeded
int TCnetObjTCP::connect()
{
	if(port == -1)
	{
		printf("ERROR: port not set.\n");
		return 0;
	}
	if(remoteHost == "")
	{
		printf("ERROR: address not set.\n");
		return 0;
	}
	
	if (SDLNet_ResolveHost(remoteIP, this->remoteHost.c_str(), this->port) < 0)
	{
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(sock = SDLNet_TCP_Open(remoteIP)))
	{
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	else
	{
		if(talkative)
		{
			printf("Socket Opened.\n");
		}
	}

}

//send
//
//Parameters:
//	message - the text to send through the connected socket
//
//Returns:
//	0 - message failed to send
//	1 - message sent successfully
int TCnetObjTCP::send( string message )
{
	if(SDLNet_TCP_Send(sock, message.c_str(), message.length() + 1))
	{
		printf("ERROR: message failed to send.\n");
		return 0;
	}
	return 1;
}

//receive
//
//Parameters:
//	wait - whether or not to block while waiting for data
//			true will loop until data is read over the socket
//			false will check to see if there is data and then return data if there is any
//
//Returns:
//	the data read from the socket
string TCnetObjTCP::receive( bool wait )
{
	char buffer[512] = {'\0'};
	while(!SDLNet_TCP_Recv(sock, buffer, 512) || !wait);
	return buffer;
}

