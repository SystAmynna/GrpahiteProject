//
// Created by SystAmynna on 03/01/2026.
//

#ifndef PROJETGRAPHITE_LOGGER_H
#define PROJETGRAPHITE_LOGGER_H

#include <string>


namespace logger {

    // Constantes pour les couleurs et styles ANSI
    inline const std::string RED = "\033[31m";           // Rouge
    inline const std::string GREEN = "\033[32m";         // Vert
    inline const std::string YELLOW = "\033[33m";        // Jaune
    inline const std::string BLUE = "\033[34m";          // Bleu
    inline const std::string MAGENTA = "\033[35m";       // Magenta
    inline const std::string CYAN = "\033[36m";          // Cyan
    inline const std::string WHITE = "\033[37m";         // Blanc
    inline const std::string BLACK = "\033[30m";         // Noir

    inline const std::string PINK = "\033[95m";          // Rose

    inline const std::string BOLD = "\033[1m";           // Gras
    inline const std::string UNDERLINE = "\033[4m";      // Souligné
    inline const std::string CROSSED = "\033[9m";        // Barré
    inline const std::string ITALIC = "\033[3m";         // Italique
    inline const std::string RESET = "\033[0m";          // Réinitialiser

    /** Niveau de log. */
    enum Level {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        NONE
    };

    /** Log un message avec un niveau donné.
     * @param level Niveau du message.
     * @param message Message à logger.
     */
    void log(Level level, const char * message);
    /** Log un message avec un niveau donné.
     * @param level Niveau du message.
     * @param message Message à logger.
     */
    void log(Level level, const std::string& message);

    /** Obtient le timestamp actuel au format JJ/MM/AAAA HH:MM:SS.
     * @return Timestamp actuel sous forme de chaîne de caractères.
     */
    std::string getCurrentTimestamp();



}


#endif //PROJETGRAPHITE_LOGGER_H