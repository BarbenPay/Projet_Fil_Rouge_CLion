cmake_minimum_required(VERSION 3.27)
project(Projet_Fil_Rouge_CLion C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Fil_Rouge_CLion main.c
        Transcription/Découpage/Decoupage.c
        Transcription/Découpage/Decoupage.h
        Log/fichier_Log.c
        Log/fichier_Log.h
        Transcription/Regroupement/Regroupement.c
        Transcription/Regroupement/Regroupement.h
        Transcription/Analyse_Phrase/Analyse.c
        Transcription/Analyse_Phrase/Analyse.h)
