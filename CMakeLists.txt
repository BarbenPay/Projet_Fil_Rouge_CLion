cmake_minimum_required(VERSION 3.27)

project(Projet_Fil_Rouge_CLion C)

set(CMAKE_C_STANDARD 11)

set(LIBJPEG_DIR ${CMAKE_SOURCE_DIR}/JPEG_Library)

include_directories(${LIBJPEG_DIR}/include)

add_executable(Projet_Fil_Rouge_CLion main.c
        Découpage/Decoupage.c
        Découpage/Decoupage.h
        Log/fichier_Log.c
        Log/fichier_Log.h
        Regroupement/Regroupement.c
        Regroupement/Regroupement.h
        Analyse_Phrase/Analyse.c
        Analyse_Phrase/Analyse.h
        Image/traitement_image.c
        Image/traitement_image.h
        Menu/menu.c
        Menu/menu.h
        Image/analyse_image.c
        Image/analyse_image.h


)

link_directories(/JPEG_Library/jpeg/9f/lib)

target_link_libraries(Projet_Fil_Rouge_CLion PRIVATE ${LIBJPEG_DIR}/lib/libjpeg.a)
