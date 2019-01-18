#ifndef CLIENT_H
#define CLIENT_H

#include "iclient.h"
#include "exceptions.h"
#include <unordered_set>

class Client : public IClient
{
private:
	const std::string& m_Id;
	std::string m_FullName;
	int m_Priority;
	std::unordered_set<std::string> m_Packages;
	std::string m_BiometricData;

public:
	Client(const std::string& id);
	std::string getIdNumber() override;
	std::string getFullName() override;
	void setFullName(const std::string& fullName) override;
	int getPriority() override;
	void updatePriority(int priority) override;
	const std::string& getBiometricData() override;
	void updateBiometricData(const std::string& biometricData) override;
	bool verifyBiometricData(const std::string& biometricData, double threshold) override;
	void newPackage(const std::string& packageId) override;
	std::vector<std::string> awaitingPackages() override;
	void packagesCollected() override;
};

#endif