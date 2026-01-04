//
// Created by SystAmynna on 19/12/2025.
//

#ifndef PROJETGRAPHITE_ENGINE_H
#define PROJETGRAPHITE_ENGINE_H


namespace Engine {

    // Factory pour créer les instances des classes principales de l'engine
    class EngineFactory;

    // Instance principale du moteur de jeu (singleton)
    class GameInstance;

    // Classe principale du jeu
    class Game;


    unsigned int const NOMINAL_UPS = 80;

    inline bool debug = true;




}


#endif //PROJETGRAPHITE_ENGINE_H