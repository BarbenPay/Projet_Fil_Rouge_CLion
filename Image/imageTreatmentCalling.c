//
// Created by Jean-Baptiste Salanie on 24/01/2024.
//

#include <printf.h>
#include "imageTreatmentCalling.h"
#include "../Log/logFile.h"


structObject* imageTreatmentCalling(char* pictureAdress)
{
    picture_struct * original_image = pictureStructFromFileAdress(pictureAdress);
    structObject* ObjectArray = encadrement_objet(original_image);
    if (ObjectArray->counter == 0)
    {
        log_file("imageTreatment.c --- L'analyse n'a pas détectée d'objet.\n");
    }
    return ObjectArray;



}
