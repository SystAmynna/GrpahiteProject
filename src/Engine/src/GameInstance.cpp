//
// Created by SystAmynna on 19/12/2025.
//

#include <GameInstance.h>

/** Utilisation du Namespace Engine */
using namespace Engine;

GameInstance* GameInstance::instance = nullptr;

/** Constructeur privé */
GameInstance::GameInstance() {
    running = true; // Le jeu est en cours d'exécution

}

/** Destructeur */
GameInstance::~GameInstance() = default;

bool GameInstance::initializeEngine() {
    // Initialisation des composants du moteur
    return true;
}
void GameInstance::runEngine() {

}
void GameInstance::destroyEngine() {
    // Nettoyage des ressources du moteur
}

void GameInstance::closeEngine() {}