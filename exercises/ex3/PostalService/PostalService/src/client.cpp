#include "client.h"

Client::Client(const std::string& id) : m_Id(id) {}

std::string Client::getIdNumber()
{
	return m_Id;
}

std::string Client::getFullName()
{
	return m_FullName;
}

void Client::setFullName(const std::string& fullName)
{
	m_FullName = fullName;
}

int Client::getPriority()
{
	return m_Priority;
}

void Client::updatePriority(int priority)
{
	m_Priority = priority;
}

const std::string& Client::getBiometricData()
{
	return m_BiometricData;
}

void Client::updateBiometricData(const std::string& biometricData)
{

}

bool Client::verifyBiometricData(const std::string& biometricData, double threshold)
{
	return false;
}

void Client::newPackage(const std::string& packageId)
{
	if (m_Packages.find(packageId) != m_Packages.end())
		throw new PackageExistsException("Package already exists");

	m_Packages.insert(packageId);
}

std::vector<std::string> Client::awaitingPackages()
{
	std::vector<std::string> packages;
	for (auto package : m_Packages)
	{
		packages.push_back(package);
	}

	return packages;
}

void Client::packagesCollected()
{
	m_Packages.clear();
}