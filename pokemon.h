#pragma once
#include "bestiaire.h"
typedef struct Pokemon
{
	const char* nom;
	int xp;
	int evolution;
	int pv;
	int cp;
}Pokemon;


void Powerup(Pokemon& p);
void evolve(Pokemon& p);
void display(const Pokemon p, EspecePokemon bestiaire[150], const char* typesLabel[18]);


