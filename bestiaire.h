#pragma once
#include "typespokemon.h"

void initBestiaire(EspecePokemon bestiaire[]);
void displayBestiaire(EspecePokemon bestiaire[]);
void triBestiaire(EspecePokemon bestiaire[]);
// rechercher l'esp�ce d'un pokemon, � partir de son nom, dans le bestiaire
EspecePokemon entierBestiaire(EspecePokemon bestiaire[], const char* nom);

