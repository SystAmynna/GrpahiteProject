//
// Created by SystAmynna on 04/01/2026.
//


#include <graphics/graphic.h>
#include <logger.h>

using namespace graphics;

bool graphics::init() {

    // Initialisation de GLFW
    if (!glfwInit()) {
        logger::log(logger::ERROR, "Échec de l'initialisation de GLFW.");
        return false;
    }

    // Version d'OpenGL 4.6
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    // Profil core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Compatibilité MacOS
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Création de la fenêtre
    window = glfwCreateWindow(SRC_WIDTH, SRC_HEIGHT, SRC_TITLE.c_str(), nullptr, nullptr);
    if (!window) {
        logger::log(logger::ERROR, "Echec de la création de la fenêtre GLFW");
        glfwTerminate();
        return false;
    }

    // Contexte de la fenêtre
    glfwMakeContextCurrent(window);

    // Callback du rescale de la fenêtre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // Callback des erreurs
    glfwSetErrorCallback(error_callback);

    // Initialisation GLAD
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        logger::log(logger::ERROR, "Échec de l'initialisation de GLAD");
        return false;
    }

    // V-Sync
    if (!vsync_enabled) glfwSwapInterval(0);


    // Initialisation réussie
    return true;

}

void graphics::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void graphics::error_callback(int error, const char *description) {
    // Construction du message d'erreur
    std::string message = logger::UNDERLINE + "GLFW Error " + std::to_string(error) + logger::RESET + logger::RED + ": " + description;
    // Log de l'erreur
    logger::log(logger::ERROR, message);
}


void graphics::end() {

    glfwDestroyWindow(window);
    glfwTerminate();

}

void graphics::render() {
    // Couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap des buffers
    glfwSwapBuffers(window);
}


