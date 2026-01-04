//
// Created by SystAmynna on 03/01/2026.
//

#ifndef PROJETGRAPHITE_CLIENTGAMEINSTANCE_H
#define PROJETGRAPHITE_CLIENTGAMEINSTANCE_H

#include <GameInstance.h>

class ClientGameInstance : public Engine::GameInstance {



public:
    ClientGameInstance();


    bool initializeEngine() override;

    void runEngine() override;


    void closeEngine() override;

};



#endif //PROJETGRAPHITE_CLIENTGAMEINSTANCE_H