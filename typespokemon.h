#pragma once

// le type enuméré décrivant le type de Pokemon parmi les 18 existants
typedef enum PokemonType{
	Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Grass, Water, Electric, Psychic, Ice, Dragon, Dark, Fairy
} PokemonType;


typedef struct EspecePokemon {
	const char* nom;
	const char* evolvesTo;
	int nbBonbonsPourEvoluer;
	PokemonType type;
	bool estEvolue;
} EspecePokemon;
