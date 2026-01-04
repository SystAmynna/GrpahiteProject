//
// Created by SystAmynna on 03/01/2026.
//

#include <ClientGameInstance.h>
#include <EngineFactory.h>
#include <logger.h>

#include "graphics/graphic.h"

using namespace Engine;

GameInstance *EngineFactory::create_GameInstance() {
    logger::log(logger::DEBUG, "Création de l'instance de jeu client.");
    GameInstance::setInstance(new ClientGameInstance());
    return GameInstance::get();
}

ClientGameInstance::ClientGameInstance() : GameInstance() {
}


bool ClientGameInstance::initializeEngine() {

    logger::log(logger::DEBUG, "Initialisation du moteur de jeu client.");

    // Initialisation des composants graphiques
    if (!graphics::init()) return false;


    return true;
}

void ClientGameInstance::runEngine() {

    while (isRunning()) {

        logger::log(logger::DEBUG, "Itération de la boucle principale du moteur de jeu client.");
        graphics::render();

        if (glfwWindowShouldClose(graphics::window)) {
            closeEngine();
        }
    }

}

void ClientGameInstance::closeEngine() {
    logger::log(logger::DEBUG, "Fermeture du moteur de jeu client.");

    graphics::end();

    stopRunning();
}
