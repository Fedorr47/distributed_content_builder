#include "Controller.hpp"

#include <thread>

#include "../Interfaces/IRemoteAgent.hpp"
#include "../Agent/RemoteAgent.hpp"
#include "../Queue/Queue.hpp"
#include "../Network/TestNetwork.hpp"

std::vector<IRemoteAgent*> Controller::GetAvailableAgents()
{
    // TODO: Use Network to get available agents

    int count_ = 3;
    std::vector<IRemoteAgent*> remote_agents;
    for(int i = 0; i < count_; i++){
        remote_agents.push_back(new RemoteAgent(i));
    }

    return remote_agents;
}

void Controller::BuildContent(IContent* content)
{
    std::vector<IRemoteAgent*> agent_list = GetAvailableAgents();
    
    // TODO: move Content splitting to IContent
    
    Queue* queue = new Queue(1, 10, content->GetSize(), logger_);
    TestNetwork* network = new TestNetwork(logger_);
    
    while (!queue->AllTasksComplete()) {
        for (int i = 0; i < agent_list.size(); i++) {
            IRemoteAgent* agent = agent_list[i];
            IRemoteAgent::AgentStatus status = network->CheckAgentStatus(agent);
            switch ( status )
            {
                case IRemoteAgent::AgentStatus::STATE_TASK_COMPLETE:
                    network->CollectTaskResult(agent);
                    queue->AssignTask(agent);
                    break;
                case IRemoteAgent::AgentStatus::STATE_AVAILABLE:
                    queue->AssignTask(agent);
                    break;
                case IRemoteAgent::AgentStatus::STATE_BUSY:
                    continue;
                    break;
                case IRemoteAgent::AgentStatus::STATE_OFFLINE:
                    logger_->LogWarning("Node " + std::to_string(agent->id_) + " is now offline!");
                    break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
