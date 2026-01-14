//
// Created by SystAmynna on 04/01/2026.
//

#ifndef PROJETGRAPHITE_GRAPHIC_H
#define PROJETGRAPHITE_GRAPHIC_H

#include <core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace graphics {

    /** Pointeur vers la fenêtre GLFW. */
    inline GLFWwindow* window;

    /** Largeur de la fenêtre. */
    constexpr unsigned int SRC_WIDTH = 800;
    /** Hauteur de la fenêtre. */
    constexpr unsigned int SRC_HEIGHT = 600;

    /** Titre de la fenêtre. */
    const std::string SRC_TITLE = core::name + " - " + core::version;

    /** V-Sync activé ou non. */
    inline bool vsync_enabled = false;

    /** Frames par secondes actuelles. */
    inline double fps;


    bool init();

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    void error_callback(int error, const char* description);

    /** Fermeture des fonctions graphiques. */
    void end();

    void render();




}




#endif //PROJETGRAPHITE_GRAPHIC_H