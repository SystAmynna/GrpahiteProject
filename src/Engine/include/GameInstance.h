//
// Created by SystAmynna on 19/12/2025.
//

#ifndef PROJETGRAPHITE_GAMEINSTANCE_H
#define PROJETGRAPHITE_GAMEINSTANCE_H

#include "engine.h"

/**
 * Classe principale du moteur de jeu.
 * Gère le cycle de vie du jeu, les mises à jour et les itérations de boucle.
 */
class Engine::GameInstance {

    /** Instance unique du GameInstance */
    static GameInstance* instance;

    /** Indique si l'application tourne */
    bool running;




public:

    /** Constructeur privé pour empêcher l'instanciation externe */
    GameInstance();
    /** Destructeur */
    virtual ~GameInstance();

    static void setInstance(GameInstance* inst) {
        // Empêche de réassigner l'instance si elle est déjà définie
        if (instance != nullptr) return;
        instance = inst;
    }

    /** Getteur du Singleton GameInstance */
    static GameInstance* get() {
        return instance;
    }

    /** Retourne si l'application est en train de tourner */
    bool isRunning() {
        return running;
    }

    void stopRunning() {
        running = false;
    }


    virtual bool initializeEngine();

    virtual void runEngine();

    virtual void destroyEngine();

    virtual void closeEngine();


};


#endif //PROJETGRAPHITE_GAMEINSTANCE_H
