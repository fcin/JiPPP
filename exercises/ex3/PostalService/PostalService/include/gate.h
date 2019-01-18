#ifndef GATE_H
#define GATE_H

#include "iclient.h"

class Gate
{
private:
	bool m_IsFree;
	std::shared_ptr<IClient> m_Client;

public:
	Gate();
	bool IsFree() const;
	void SetClient(std::shared_ptr<IClient> client);
	std::shared_ptr<IClient> TakeClient();
	std::string GetClientName() const;
};

#endif
