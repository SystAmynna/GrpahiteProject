//
// Created by SystAmynna on 14/12/2025.
//

#include <engine.h>
#include <logger.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace logger;

void logger::log(Level level, const char * message) {
    // convertir le message en std::string et appeler l'autre fonction log
    log(level, std::string(message));
}

void logger::log(Level level, const std::string& message) {

    // Si le mode debug est désactivé, ignorer les messages DEBUG
    if (!Engine::debug && level == DEBUG) {
        return; // Ne pas logguer les messages DEBUG si le mode debug est désactivé
    }

    std::string now = WHITE + ITALIC + "(" + getCurrentTimestamp() + ") " + RESET;


    // Définir le préfixe en fonction du niveau de log
    std::string prefix = now;
    // Choix du préfixe selon le niveau
    switch (level) {
        case INFO:
            prefix += BOLD + BLUE + "[" + CYAN + "INFO" + BLUE + "]: " + RESET + GREEN;
            break;
        case WARNING:
            prefix += BOLD + YELLOW + "[WARNING]: " + RESET + YELLOW;
            break;
        case ERROR:
            prefix += BOLD + RED + "[ERROR]: " + RESET + RED;
            break;
        case DEBUG:
            prefix += BOLD + MAGENTA + "[DEBUG]: " + RESET + PINK;
            break;
        default:
            prefix = "";
    }

    // Afficher le message avec le préfixe et réinitialiser le style
    std::cout << prefix << message << RESET << std::endl;

}

std::string logger::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm* tm = std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(tm, "%d/%m/%Y %H:%M:%S");  // Format : JJ/MM/AAAA HH:MM:SS
    return oss.str();
}