cmake_minimum_required(VERSION 3.26)
project(project)

# 1. Definir o padrão do C++ (C++17 é geralmente o padrão para LEIC)
set(CMAKE_CXX_STANDARD 14)
set( CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}" )
set( CMAKE_BUILD_TYPE "Release" )

# 2. Incluir as pastas de cabeçalhos (.h)
# Isto permite-te fazer #include "model/Submission.h" sem erros
include_directories(include)



set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP} )

# 4. Criar o executável
add_executable(myProg
        main.cpp
        src/ui/Menu.cpp
        include/logic/Edmonds-Karp.h
)

add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

