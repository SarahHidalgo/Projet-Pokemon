#include "pokemon.h"
#include "typespokemon.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include "utils.h"
#include "historique.h"
#include "combat.h"
#include <iostream>
using namespace std;


int hashf(const char* str, CombatHash *combathash) 
// renvoie un entier pour avoir une position dans le tableau (entre 0 et 25 ici)
{
	unsigned long hash = 5381;
	int c;
	while (c = *str++) 
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return hash%combathash->size;
}

CombatEspece* get(CombatHash* hashtable, const char* key) 
{
	int hasht = hashf(key, hashtable); //position dans hashtable auquel se trouve key
	CombatEspece* combatespece = hashtable->tab[hasht];// on associe combatespece a sa place dans hastable
	while (combatespece!=nullptr && strcmp(combatespece->nature, key) != 0 )
		// on cherche le combatespece dont sa nature est = key en parcourant la liste chainée
	{
		combatespece = combatespece->next;
	}
	return combatespece;
    
   

}

bool contains(CombatHash* hashtable, CombatEspece* c) 
{
	CombatEspece* element = get(hashtable, c->nature);
	return (element != nullptr);
}

/* Quick factorization of the code that checks whether a string
 belongs to a static table of 5 strings (possibly null strings).*/
bool tableContains(const char* tab[5], const char* val) {

    for (int i = 0; i < 5; i++) {
        if (tab[i] != nullptr && strcmp(tab[i], val) == 0) {
            return true;
        }
    }
    return false;
}

void inserthash(CombatEspece* c, CombatHash* hashtable) 
{
	if (!contains(hashtable,c)) // on verifie si le combatespece se situe deja dans hastable
	{
		int pos = hashf(c->nature, hashtable); //position dans hashtable auquel se trouve la nature de c
		CombatEspece* nouveau = hashtable->tab[pos];// on associe nouveau à sa place dans hastable
		if (nouveau == nullptr) 
		{
			hashtable->tab[pos] = c; //si la place est libre, on y met c 
		}
		else 
		{
			while (nouveau->next != nullptr) //tant que la place n'est pas libre
			{
				nouveau = nouveau->next;
			}
			nouveau->next = c;
		}
	}
	else
	{
		cout << " Cet element est deja present " << endl;
	}
	
}


const char* pokemonTypeToString(PokemonType t)
{
	if(t == Normal) {
		return "Normal";
	} 
	else if(t == Fighting) {
		return "Fighting";
	} 
	else if(t == Flying) {
		return "Flying";
	} 
	else if(t == Poison) {
		return "Poison";
	} 
	else if(t == Ground) {
		return "Ground";
	} 
	else if(t == Rock) {
		return "Rock";
	} 
	else if(t == Bug) {
			return "Bug";
	} 
	else if(t == Ghost) {
			return "Ghost";
	} 
	else if(t == Steel) {
			return "Steel";
	} 
	else if(t == Fire) {
			return "Fire";
	}
	else if(t == Grass) {
			return "Grass";
	} 
	else if(t == Water) {
			return "Water";
	} 
	else if(t == Electric) {
			return "Electric";
	} 
	else if(t == Psychic) {
			return "Psychic";
	} 
	else if(t == Ice) {
			return "Ice";
	} 
	else if(t == Dragon) {
			return "Dragon";
	} 
	else if(t == Dark) {
			return "Dark";
	} 
	else{
		return "Fairy";
	}
}

CombatHash* initCombatHash()
{
	CombatHash* hashtable = new CombatHash;
	hashtable->size = 18;
	// Initialisation
	for (int k = 0; k < 26; k++)
	{
		hashtable->tab[k] = nullptr;
	}

	// Insertions successives
	int i = -1;
	CombatEspece* bug = new CombatEspece;
	bug->nature = "Bug";
	bug->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		bug->strongAgainst[i] = nullptr;
		bug->weakAgainst[i] = nullptr;
	}
	bug->strongAgainst[0] = "Dark";
	bug->strongAgainst[1] = "Grass";
	bug->strongAgainst[2] = "Psychic";
	bug->weakAgainst[0] = "Fire";
	bug->weakAgainst[1] = "Flying";
	bug->weakAgainst[2] = "Rock";
	inserthash(bug, hashtable);

	CombatEspece* dark = new CombatEspece;
	dark->nature = "Dark";
	dark->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		dark->strongAgainst[i] = nullptr;
		dark->weakAgainst[i] = nullptr;
	}
	dark->strongAgainst[0] = "Ghost";
	dark->strongAgainst[1] = "Psychic";
	dark->weakAgainst[0] = "Bug";
	dark->weakAgainst[1] = "Fairy";
	dark->weakAgainst[2] = "Fight";
	inserthash(dark, hashtable);

	CombatEspece* dragon = new CombatEspece;
	dragon->nature = "Dragon";
	dragon->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		dragon->strongAgainst[i] = nullptr;
		dragon->weakAgainst[i] = nullptr;
	}
	dragon->strongAgainst[0] = "Dragon";
	dragon->weakAgainst[0] = "Dragon";
	dragon->weakAgainst[1] = "Fairy";
	dragon->weakAgainst[2] = "Ice";
	inserthash(dragon, hashtable);

	CombatEspece* electric = new CombatEspece;
	electric->nature = "Electric";
	electric->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		electric->strongAgainst[i] = nullptr;
		electric->weakAgainst[i] = nullptr;
	}
	electric->strongAgainst[0] = "Flying";
	electric->strongAgainst[1] = "Water";
	electric->weakAgainst[0] = "Ground";
	inserthash(electric, hashtable);

	CombatEspece* fairy = new CombatEspece;
	fairy->nature = "Fairy";
	fairy->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		fairy->strongAgainst[i] = nullptr;
		fairy->weakAgainst[i] = nullptr;
	}
	fairy->strongAgainst[0] = "Dark";
	fairy->strongAgainst[1] = "Dragon";
	fairy->strongAgainst[2] = "Fight";
	fairy->weakAgainst[0] = "Poison";
	fairy->weakAgainst[1] = "Steel";
	inserthash(fairy, hashtable);

	CombatEspece* fighting = new CombatEspece;
	fighting->nature = "Fighting";
	fighting->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		fighting->strongAgainst[i] = nullptr;
		fighting->weakAgainst[i] = nullptr;
	}
	fighting->strongAgainst[0] = "Dark";
	fighting->strongAgainst[1] = "Ice";
	fighting->strongAgainst[2] = "Normal";
	fighting->strongAgainst[3] = "Rock";
	fighting->strongAgainst[4] = "Steel";
	fighting->weakAgainst[0] = "Fairly";
	fighting->weakAgainst[1] = "Flying";
	fighting->weakAgainst[2] = "Psychic";
	inserthash(fighting, hashtable);

	CombatEspece* fire = new CombatEspece;
	fire->nature = "Fire";
	fire->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		fire->strongAgainst[i] = nullptr;
		fire->weakAgainst[i] = nullptr;
	}
	fire->strongAgainst[0] = "Bug";
	fire->strongAgainst[1] = "Grass";
	fire->strongAgainst[2] = "Ice";
	fire->strongAgainst[3] = "Steel";
	fire->weakAgainst[0] = "Ground";
	fire->weakAgainst[1] = "Rock";
	fire->weakAgainst[2] = "Water";
	inserthash(fire, hashtable);

	CombatEspece* flying = new CombatEspece;
	flying->nature = "Flying";
	flying->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		flying->strongAgainst[i] = nullptr;
		flying->weakAgainst[i] = nullptr;
	}
	flying->strongAgainst[0] = "Bug";
	flying->strongAgainst[1] = "Fight";
	flying->strongAgainst[2] = "Grass";
	flying->weakAgainst[0] = "Electric";
	flying->weakAgainst[1] = "Ice";
	flying->weakAgainst[2] = "Rock";
	inserthash(flying, hashtable);

	CombatEspece* ghost = new CombatEspece;
	ghost->nature = "Ghost";
	ghost->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		ghost->strongAgainst[i] = nullptr;
		ghost->weakAgainst[i] = nullptr;
	}
	ghost->strongAgainst[0] = "Ghost";
	ghost->strongAgainst[1] = "Psychic";
	ghost->weakAgainst[0] = "Dark";
	ghost->weakAgainst[1] = "Ghost";
	inserthash(ghost, hashtable);

	CombatEspece* grass = new CombatEspece;
	grass->nature = "Grass";
	grass->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		grass->strongAgainst[i] = nullptr;
		grass->weakAgainst[i] = nullptr;
	}
	grass->strongAgainst[0] = "Ground";
	grass->strongAgainst[1] = "Rock";
	grass->strongAgainst[2] = "Water";
	grass->weakAgainst[0] = "Bug";
	grass->weakAgainst[1] = "Fire";
	grass->weakAgainst[2] = "Flying";
	grass->weakAgainst[3] = "Ice";
	grass->weakAgainst[4] = "Poison";
	inserthash(grass, hashtable);

	CombatEspece* ground = new CombatEspece;
	ground->nature = "Ground";
	ground->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		ground->strongAgainst[i] = nullptr;
		ground->weakAgainst[i] = nullptr;
	}
	ground->strongAgainst[0] = "Electric";
	ground->strongAgainst[1] = "Fire";
	ground->strongAgainst[2] = "Poison";
	ground->strongAgainst[3] = "Rock";
	ground->strongAgainst[4] = "Steel";
	ground->weakAgainst[0] = "Grass";
	ground->weakAgainst[1] = "Ice";
	ground->weakAgainst[2] = "Water";
	inserthash(ground, hashtable);

	CombatEspece* ice = new CombatEspece;
	ice->nature = "Ice";
	ice->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		ice->strongAgainst[i] = nullptr;
		ice->weakAgainst[i] = nullptr;
	}
	ice->strongAgainst[0] = "Dragon";
	ice->strongAgainst[1] = "Flying";
	ice->strongAgainst[2] = "Grass";
	ice->strongAgainst[3] = "Ground";
	ice->weakAgainst[0] = "Fight";
	ice->weakAgainst[1] = "Fire";
	ice->weakAgainst[2] = "Rock";
	ice->weakAgainst[3] = "Steel";
	inserthash(ice, hashtable);

	CombatEspece* normal = new CombatEspece;
	normal->nature = "Normal";
	normal->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		normal->strongAgainst[i] = nullptr;
		normal->weakAgainst[i] = nullptr;
	}
	normal->weakAgainst[0] = "Fight";
	inserthash(normal, hashtable); // correction ici.

	CombatEspece* poison = new CombatEspece;
	poison->nature = "Poison";
	poison->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		poison->strongAgainst[i] = nullptr;
		poison->weakAgainst[i] = nullptr;
	}
	poison->strongAgainst[0] = "Fairy";
	poison->strongAgainst[1] = "Grass";
	poison->weakAgainst[0] = "Ground";
	poison->weakAgainst[1] = "Psychic";
	inserthash(poison, hashtable);

	CombatEspece* psychic = new CombatEspece;
	psychic->nature = "Psychic";
	psychic->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		psychic->strongAgainst[i] = nullptr;
		psychic->weakAgainst[i] = nullptr;
	}
	psychic->strongAgainst[0] = "Fight";
	psychic->strongAgainst[1] = "Poison";
	psychic->weakAgainst[0] = "Bug";
	psychic->weakAgainst[1] = "Dark";
	psychic->weakAgainst[2] = "Ghost";
	inserthash(psychic, hashtable);

	CombatEspece* rock = new CombatEspece;
	rock->nature = "Rock";
	rock->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		rock->strongAgainst[i] = nullptr;
		rock->weakAgainst[i] = nullptr;
	}
	rock->strongAgainst[0] = "Bug";
	rock->strongAgainst[1] = "Fire";
	rock->strongAgainst[2] = "Flying";
	rock->strongAgainst[3] = "Ice";
	rock->weakAgainst[0] = "Fight";
	rock->weakAgainst[1] = "Grass";
	rock->weakAgainst[2] = "Ground";
	rock->weakAgainst[3] = "Steel";
	rock->weakAgainst[4] = "Water";
	inserthash(rock, hashtable);

	CombatEspece* steel = new CombatEspece;
	steel->nature = "Steel";
	steel->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		steel->strongAgainst[i] = nullptr;
		steel->weakAgainst[i] = nullptr;
	}
	steel->strongAgainst[0] = "Fairy";
	steel->strongAgainst[1] = "Ice";
	steel->strongAgainst[2] = "Rock";
	steel->weakAgainst[0] = "Fight";
	steel->weakAgainst[1] = "Fire";
	steel->weakAgainst[2] = "Ground";
	inserthash(steel, hashtable);

	CombatEspece* water = new CombatEspece;
	water->nature = "Water";
	water->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		water->strongAgainst[i] = nullptr;
		water->weakAgainst[i] = nullptr;
	}
	water->strongAgainst[0] = "Fire";
	water->strongAgainst[1] = "Ground";
	water->strongAgainst[2] = "Rock";
	water->weakAgainst[0] = "Electric";
	water->weakAgainst[1] = "Grass";
	inserthash(water, hashtable);

	return hashtable;
}

void combat(CombatHash* hashtable, Pokedex* pokedex, EspecePokemon bestiaire[150])
{
    int A = -1;
    while (A < 0) 
    {
        cout << "Quel est le premier pokemon que vous voulez faire combattre ? (donnez le numero) " << endl;
        cin >> A;
    }
    int B = -1;
    while (B < 0)
    {
        cout << "Quel est le deuxieme pokemon que vous voulez faire combattre ? (donnez le numero) " << endl;
        cin >> B;
    }
   
    //pointeur vers le pokemon que l'on souhaite modifier.
    Pokemon* a = &(pokedex->mesPokemons[A]);
    Pokemon* b = &(pokedex->mesPokemons[B]);

    cout << "Début du combat entre " << a->nom << " et " << b->nom << " ! " << endl;

    // déterminer qui est fort/faible contre qui
    EspecePokemon eA = entierBestiaire(bestiaire, a->nom);
    EspecePokemon eB = entierBestiaire(bestiaire, b->nom);

    const char* natureA = pokemonTypeToString(eA.type);
    const char* natureB = pokemonTypeToString(eB.type);

    CombatEspece* cbtEA = get(hashtable, natureA);
    CombatEspece* cbtEB = get(hashtable, natureB);

    const bool aStrongVersusB = tableContains(cbtEA->strongAgainst, natureB);
    const bool bStrongVersusA = tableContains(cbtEB->strongAgainst, natureA);

    if (aStrongVersusB) 
    {
        cout << a->nom << " est fort contre " << b->nom << endl;
    }

    if (bStrongVersusA) 
    {
        cout << b->nom << " est fort contre " << a->nom << endl;
    }

    // tirage au sort pour savoir qui commence entre les deux pokemons
    bool aAttacks = true;
    if (random_at_most(100) % 2 == 0) 
    {
        aAttacks = false;
    }

    if (aAttacks) 
    {
        cout << endl << a->nom << " commence !" << endl;
    }
    else 
    {
        cout << endl << b->nom << " commence !" << endl;
    }

    const int baseDamage = 30;
    while (a->pv > 0 && b->pv > 0) 
    {
        if (aAttacks) 
        {
            int damage = (int)(baseDamage + (baseDamage * aStrongVersusB * 2));
            b->pv = b->pv - damage;
            cout <<endl<< a->nom << " inflige " << damage << " points de dommage a " << b->nom << endl;
        }
        else 
        {
            int damage = (int)(baseDamage + (baseDamage * bStrongVersusA * 2));
            a->pv = a->pv - damage;
            cout <<endl<< b->nom << " inflige " << damage << " points de dommage a " << a->nom << endl;
        }
        aAttacks = !aAttacks; //on echange le pokemon qui fait l'attaque
    }

	if (a->pv == 0)
	{
		cout << "le pokemon "<< a->nom<<" ne possede plus de PV " << endl;
	}

	if (b->pv == 0)
	{
		cout << "le pokemon "<<b->nom<<" ne possede plus de PV " << endl;
	}

    if (a->pv < 0) 
    {
        cout << endl << b->nom << " gagne le combat contre  " << a->nom << endl;
        a->pv = 0; // les PVs du perdant ont pu passés en négatif.
    }
    else 
    {
        cout << endl << a->nom << " gagne le combat contre  "<< b->nom << endl;
        b->pv = 0; // les PVs du perdant ont pu passés en négatif.
    }

}

