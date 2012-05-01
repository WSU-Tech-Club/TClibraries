#include "TCnet.h"

TCnetObjTCP::TCnetObjTCP(bool verbose = false)
{
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
	port = -1;
	remoteIPv4 = "";

	talkative = verbose;
}


TCnetObjTCP::~TCnetObjTCP()
{
	if(myIP != NULL)
		delete myIP;
	if(remoteIP != NULL)
		delete remoteIP;
}


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

int TCnetObjTCP::setIp( string newIP )
{
	this->remoteIPv4 = newIP;
	if(talkative)
		printf("Remote address set.\n");

	return 1;
}

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

int TCnetObjTCP::connect()
{
	if(port == -1)
	{
		printf("ERROR: port not set.\n");
		return 0;
	}
	if(remoteIPv4 == "")
	{
		printf("ERROR: address not set.\n");
		return 0;
	}
	
	if (SDLNet_ResolveHost(remoteIP, this->remoteIPv4.c_str(), this->port) < 0)
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

