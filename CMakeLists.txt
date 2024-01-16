cmake_minimum_required(VERSION 3.27)
project(Projet_Fil_Rouge_CLion C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Fil_Rouge_CLion main.c
        Découpage/Decoupage.c
        Découpage/Decoupage.h
        Image/scan_image.c
        Image/header.h
        Log/fichier_Log.c
        Log/fichier_Log.h
        Regroupement/Regroupement.c
        Regroupement/Regroupement.h
        Analyse_Phrase/Analyse.c
        Analyse_Phrase/Analyse.h


        Image/image.c
        Image/image.h
        Menu/menu.c
        Menu/menu.h

)
