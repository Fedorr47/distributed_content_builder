//
//  IController.h
//  distributed_content_builder
//
//  Created by Евгений Курятов on 02.02.2022.
//

#ifndef IController_h
#define IController_h

#include <vector>

#include "..\Interfaces\IContent.hpp"
#include "..\Interfaces\IRemoteAgent.hpp"
#include "..\Interfaces\ILogger.hpp"

class IController {
public:
    IController() {}
    ILogger* logger_{nullptr};
public:
    virtual std::vector<IRemoteAgent*> GetAvailableAgents() = 0;
    virtual void BuildContent(IContent* content) = 0;
};

#endif /* IController_h */
