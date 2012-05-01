#ifndef TCnetObjTCP_H
#define TCnetObjTCP_H
#include <string>
#ifdef WIN32
#include "SDL_net.h"
#else
#include "SDL/SDL_net.h"
#endif

using std::string;

class TCnetObjTCP
{
private:
	unsigned int port;
	IPaddress *myIP, *remoteIP;
	string remoteIPv4;
	TCPsocket sock;
	
	bool talkative;

public:
	TCnetObjTCP(bool verbose);
	TCnetObjTCP(bool verbose, string nRemoteIP, unsigned int nPort);
	~TCnetObjTCP();

	int setIp(string newIP);
	int setPort(unsigned int newPort);

	int connect();

	void send(string message);
	string receive();


};
#endif