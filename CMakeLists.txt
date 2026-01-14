cmake_minimum_required(VERSION 4.0) # Version minimale de CMake requise
project(ProjetGraphite) # Nom du projet

set(CMAKE_CXX_STANDARD 20) # Utilisation de la norme C++20
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/builds) # Répertoire de sortie des exécutables

# --- REPERTOIRES ---

set(GLOBAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src) # Répertoire source global
set(ENGINE_DIR ${GLOBAL_SOURCE_DIR}/Engine)     # Répertoire de la bibliothèque logique
set(CLIENT_DIR ${GLOBAL_SOURCE_DIR}/Client)     # Répertoire de l'exécutable graphique
set(SERVER_DIR ${GLOBAL_SOURCE_DIR}/Server)     # Répertoire de l'exécutable headless
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs) # Répertoire des bibliothèques externes

# --- GESTION DES DÉPENDANCES (LIBS) ---
set(GRAPHICS_LIBS glfw glad)  # Libs graphiques uniquement
set(ENGINE_LIBS glm)      # Libs logique

file(GLOB LIBS_SUBDIR LIST_DIRECTORIES true ${LIBS_DIR}/*) # Récupère tous les sous-répertoires dans libs/
foreach (subdir ${LIBS_SUBDIR}) # Parcourt chaque sous-répertoire
    # Récupère le nom du sous-répertoire
    get_filename_component(subdir_name ${subdir} NAME)

    # Vérifie si c'est un répertoire
    if (NOT IS_DIRECTORY ${subdir})
        message(WARNING "${subdir} n'est pas un répertoire. Ignoré.")
        continue()
    endif()

    # Ajoute la bibliothèque en fonction de sa structure
    if (EXISTS ${subdir}/CMakeLists.txt)
        # Si un CMakeLists.txt existe, l'ajoute directement
        add_subdirectory(${subdir} ${CMAKE_BINARY_DIR}/libs/${subdir_name})

    elseif (IS_DIRECTORY ${subdir}/src AND IS_DIRECTORY ${subdir}/include)
        # Si les dossiers src/ et include/ existent, crée une bibliothèque statique
        file(GLOB SUBDIR_SOURCES ${subdir}/src/*.cpp ${subdir}/src/*.c)
        add_library(${subdir_name} STATIC ${SUBDIR_SOURCES})
        target_include_directories(${subdir_name} PUBLIC ${subdir}/include)

    else()
        # Sinon, affiche un avertissement
        message(WARNING "Le répertoire ${subdir} ne contient pas de CMakeLists.txt ni les dossiers src/include. Ignoré.")

    endif()
endforeach()

# --- ENGINE (Bibliothèque Logique) ---
file(GLOB_RECURSE ENGINE_SOURCES ${ENGINE_DIR}/src/*.cpp) # Récupère tous les fichiers sources de Engine
file(GLOB_RECURSE ENGINE_HEADERS ${ENGINE_DIR}/include/*.h ${ENGINE_DIR}/include/*.hpp) # Récupère tous les fichiers headers de Engine
add_library(Engine STATIC ${ENGINE_SOURCES}) # Crée la bibliothèque statique Engine
target_include_directories(Engine PUBLIC ${ENGINE_HEADERS}) # Inclut les headers de Engine
# Lie les bibliothèques logiques nécessaires
foreach(lib ${ENGINE_LIBS})
    if(TARGET ${lib})
        # Lie la bibliothèque si elle a été ajoutée
        target_link_libraries(Engine PUBLIC ${lib})
    endif()
endforeach()

# --- CLIENT (Exécutable Graphique) ---
file(GLOB_RECURSE CLIENT_SOURCES ${CLIENT_DIR}/src/*.cpp) # Récupère tous les fichiers sources de Client
file(GLOB_RECURSE CLIENT_HEADERS ${CLIENT_DIR}/include/*.h ${CLIENT_DIR}/include/*.hpp) # Récupère tous les fichiers headers de Client
add_executable(Client ${CLIENT_SOURCES}) # Crée l'exécutable Client
target_include_directories(Client PRIVATE ${CLIENT_HEADERS}) # Inclut les headers de Client
target_link_libraries(Client PRIVATE Engine) # Lie la bibliothèque Engine
# Lie les bibliothèques graphiques nécessaires
foreach(lib ${GRAPHICS_LIBS})
    if(TARGET ${lib})
        # Lie la bibliothèque si elle a été ajoutée
        target_link_libraries(Client PRIVATE ${lib})
    endif()
endforeach()

# --- SERVER (Exécutable Headless) ---
file(GLOB_RECURSE SERVER_SOURCES ${SERVER_DIR}/src/*.cpp) # Récupère tous les fichiers sources de Server
file(GLOB_RECURSE SERVER_HEADERS ${SERVER_DIR}/include/*.h ${SERVER_DIR}/include/*.hpp) # Récupère tous les fichiers headers de Server
add_executable(Server ${SERVER_SOURCES}) # Crée l'exécutable Server
target_include_directories(Server PRIVATE ${SERVER_HEADERS}) # Inclut les headers de Server
target_link_libraries(Server PRIVATE Engine) # Lie la bibliothèque Engine