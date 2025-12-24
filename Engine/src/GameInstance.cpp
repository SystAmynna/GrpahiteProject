//
// Created by SystAmynna on 19/12/2025.
//

#include <GameInstance.h>

#include <GameRunner.h>

/** Utilisation du Namespace Engine */
using namespace Engine;

/** Constructeur privé */
GameInstance::GameInstance() {
    running = true; // Le jeu est en cours d'exécution

}

/** Destructeur */
GameInstance::~GameInstance() = default;

/** Getteur du Singleton GameInstance */
GameInstance* GameInstance::get() {
    if (instance == nullptr) {
        instance = new GameInstance();
    }
    return instance;
}

/** Getteur pour savoir si l'application tourne */
bool GameInstance::isRunning() {
    return running;
}

void GameInstance::addGameRunner(const World *world) {

    // Crée un GameRunner pour le monde donné
    auto runnerPtr = std::make_unique<GameRunner>(world);
    GameRunner* raw = runnerPtr.get();
    // Ajoute le GameRunner à la liste des runners
    GameRunner::addRunner(std::move(runnerPtr));
    // Démarre le GameRunner
    raw->start();

}
