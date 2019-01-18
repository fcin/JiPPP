#ifndef POSTOFFICE_H
#define POSTOFFICE_H

#include "ipostoffice.h"
#include "client.h"
#include "gate.h"
#include "exceptions.h"
#include <queue>

class ClientCompare
{
public:
	bool operator() (std::shared_ptr<IClient>& client1, std::shared_ptr<IClient>& client2) {
		return client1->getPriority() < client2->getPriority();
	}
};

class PostOffice : public IPostOffice
{
private:
	std::vector<Gate> m_Gates;
	std::priority_queue<std::shared_ptr<IClient>, std::vector<std::shared_ptr<IClient>>, ClientCompare> m_Clients;

public:
	PostOffice(unsigned int gateCount);
	std::shared_ptr<IClient> getClient(const std::string& identificationNumber) override;
	void enqueueClient(const std::shared_ptr<IClient>& client) override;
	std::vector<std::string> getStatus() override;
	void gateReady(unsigned gateIndex) override;
	void collectPackages(unsigned gateIndex) override;

};
#endif