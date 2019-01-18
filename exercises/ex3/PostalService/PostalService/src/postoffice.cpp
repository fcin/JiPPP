#include "postoffice.h"

PostOffice::PostOffice(unsigned int gateCount)
{
	for (unsigned int index = 0; index < gateCount; index++)
	{
		m_Gates.emplace_back(Gate());
	}
}

std::shared_ptr<IClient> PostOffice::getClient(const std::string& identificationNumber)
{
	return std::make_shared<Client>(identificationNumber);
}

void PostOffice::enqueueClient(const std::shared_ptr<IClient>& client)
{
	m_Clients.emplace(client);
}

std::vector<std::string> PostOffice::getStatus()
{
	std::vector<std::string> statuses;
	for (const auto& item : m_Gates)
	{
		statuses.push_back(item.GetClientName());
	}

	return statuses;
}

void PostOffice::gateReady(unsigned gateIndex)
{
	if (gateIndex < 0 || gateIndex >= m_Gates.size())
	{
		throw IncorrectGateException("Incorrect gate");
	}

	m_Gates[gateIndex].TakeClient();
	if (!m_Clients.empty())
	{
		m_Gates[gateIndex].SetClient(m_Clients.top());
		m_Clients.pop();
	}
}

void PostOffice::collectPackages(unsigned gateIndex)
{
	if (gateIndex < 0 || gateIndex >= m_Gates.size())
	{
		throw IncorrectGateException("Incorrect gate");
	}

	auto client = m_Gates[gateIndex].TakeClient();
	client->packagesCollected();
}

std::shared_ptr<IPostOffice> IPostOffice::create(unsigned gate_count)
{
	return std::make_shared<PostOffice>(gate_count);
}
