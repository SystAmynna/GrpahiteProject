//
// Created by SystAmynna on 20/12/2025.
//

#ifndef PROJETGRAPHITE_WORLDRUNNER_H
#define PROJETGRAPHITE_WORLDRUNNER_H

#include "engine.h"
#include <thread>
#include <vector>

using runner_list = std::vector<std::unique_ptr<Engine::GameRunner>>;

class Engine::GameRunner {

    static runner_list RUNNERS;


    bool running;
    std::atomic<bool> active;

    std::thread thread;

    World* world;
    // TODO : Entity Manager


    void runnerLoop();

    void onUpdate();

    void onLoopIteration();

public:
    GameRunner(const World *world);
    ~GameRunner();

    bool isRunning();
    bool isActive();

    void start();
    void pause();
    void resume();
    void stop();

    static const void addRunner(std::unique_ptr<GameRunner> runner);

};



#endif //PROJETGRAPHITE_WORLDRUNNER_H