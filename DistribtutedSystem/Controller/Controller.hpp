#pragma once

#include "../Interfaces/IController.hpp"
#include "../Interfaces/ILogger.hpp"

struct Controller : IController
{
	Controller(ILogger* logger) :
		IController()
	{
		logger_ = logger;
	}

	~Controller() {}

	std::vector<IRemoteAgent*> GetAvailableAgents() override;
	void BuildContent(IContent* content) override;

private:
	Controller(const Controller& other) = delete;
};