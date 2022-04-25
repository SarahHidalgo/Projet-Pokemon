#pragma once
#include "typespokemon.h"
#include "pokemon.h"

typedef struct CombatEspece 
{
	const char* nature;
	const char* strongAgainst[5];
	const char* weakAgainst[5];
	CombatEspece* next;
}CombatEspece;


typedef struct
{	
	CombatEspece* tab[26];
	int size;
}CombatHash;


CombatEspece* get(CombatHash* hashtable,const char* key);
const char* pokemonTypeToString(PokemonType t);
bool contains(CombatHash* hashtable, CombatEspece* c);
void inserthash(CombatEspece* c, CombatHash* hashtable);
CombatHash* initCombatHash();
void combat(CombatHash* hashtable, Pokedex* pokedex, EspecePokemon bestiaire[150]);
