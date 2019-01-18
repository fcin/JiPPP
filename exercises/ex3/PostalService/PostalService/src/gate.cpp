#include "gate.h"

Gate::Gate() : m_IsFree(false)
{

}

bool Gate::IsFree() const
{
	return m_IsFree;
}

void Gate::SetClient(std::shared_ptr<IClient> client)
{
	m_Client = client;
	m_IsFree = false;
}

std::shared_ptr<IClient> Gate::TakeClient()
{
	std::shared_ptr<IClient> client = m_Client;
	m_Client = nullptr;
	m_IsFree = true;
	return client;
}

std::string Gate::GetClientName() const
{
	if (m_Client == nullptr)
		return "";

	return m_Client->getFullName();
}