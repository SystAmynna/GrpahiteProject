//
// Created by SystAmynna on 20/12/2025.
//

#include <GameRunner.h>

using namespace Engine;

GameRunner::GameRunner(const World *world) {
    this->world = const_cast<World*>(world);
    running = false;
    active = false;

    thread = std::thread(&GameRunner::runnerLoop, this);
}

GameRunner::~GameRunner() {
    stop();
}

bool GameRunner::isRunning() {
    return running;
}

bool GameRunner::isActive() {
    return active;
}

void GameRunner::start() {
    running = true;
    active = true;
}

void GameRunner::pause() {
    active = false;
}

void GameRunner::resume() {
    active = true;
}

void GameRunner::stop() {
    running = false;
    if (thread.joinable()) {
        thread.join();
    }
}

void GameRunner::runnerLoop() {
    while (running) {

        if (!active) continue;

        // UPDATE


        // LOOP ITERATION
        onLoopIteration();


    }
}

const void GameRunner::addRunner(std::unique_ptr<GameRunner> runner) {
    RUNNERS.push_back(std::move(runner));
}


