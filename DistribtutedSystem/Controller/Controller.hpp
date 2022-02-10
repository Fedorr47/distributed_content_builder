//
//  Controller.hpp
//  distributed_content_builder
//
//  Created by Евгений Курятов on 02.02.2022.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>

#include "IController.hpp"

class Controller : public IController {
public:
    Controller(ILogger *logger, INetwork* network);
    std::vector<IRemoteAgent*> GetAvailableAgents();
    void BuildContent(IContent* content);
};

#endif /* Controller_hpp */
