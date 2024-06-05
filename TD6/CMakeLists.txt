# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.5)

# La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(IMAC_project)

# On indique que l'on veut créer un exécutable "td6" compilé à partir du fichier main.cpp
add_executable(td6 main.cpp)