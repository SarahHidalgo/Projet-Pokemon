#pragma once
#include "bestiaire.h"
#include "pokemon.h"
#include "typespokemon.h"


typedef struct Ressource
{
	int poussieres;
	int nbbonbonsdispo;

} Ressource;

typedef struct Pokedex
{
	Pokemon* mesPokemons;
	int nb;
	int capacity;

}Pokedex;

Pokedex* initPokedex(const int size);
void insertPokemon(Pokedex* monPokedex, Pokemon p);
void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150],const char* typesLabel[18]);
Pokemon genererPokemon(EspecePokemon bestiaire[150], const char* typesLabel[18]);
