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

    /** Constructeur privé pour empêcher l'instanciation externe */
    GameInstance();
    /** Destructeur */
    ~GameInstance();


public:

    /** Getteur du Singleton GameInstance */
    static GameInstance* get();

    /** Retourne si l'application est en train de tourner */
    bool isRunning();

    void addGameRunner(const World* world);



};


#endif //PROJETGRAPHITE_GAMEINSTANCE_H
