//
// Created by SystAmynna on 03/01/2026.
//

#include <engine.h>
#include <EngineFactory.h>
#include "GameInstance.h"

using namespace Engine;

int main() {

    // Création de l'instance de jeu via la factory
    GameInstance* gameInstance = EngineFactory::create_GameInstance();

    // Initialisation
    gameInstance->initializeEngine();
    // Lancement de la boucle principale du jeu
    gameInstance->runEngine();
    // Destruction et nettoyage
    gameInstance->destroyEngine();

    return 0;
}
