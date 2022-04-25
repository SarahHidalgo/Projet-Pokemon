#include "pokemon.h"
#include "typespokemon.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include "utils.h"
#include "historique.h"
#include "combat.h"
#include <iostream>
using namespace std;


void printMenu() {
    cout << endl << endl;;
    cout << " 1 - Index des Pokemons" << endl;
    cout << " 2 - Mon Pokedex" << endl;
    cout << " 3 - Attraper un Pokemon" << endl;
    cout << " 4 - Power-up et Evolution" << endl;
    cout << " 5 - Combat" << endl;
    cout << " 6 - Quitter" << endl;
}

void Bestiaire(EspecePokemon bestiaire[]) {
    int newchoice = 0;
    cout << "Choisir l'action à l'action : " << endl;
    cout << "1 - Bestiaire par ordre naturel " << endl;
    cout << "2 - Bestiaire par ordre alphabetique" << endl;
    cout << "3 - Retour au menu principal" << endl;

    do {
        cin >> newchoice;
        if (newchoice != 1 && newchoice != 2 && newchoice != 3) {
            cout << "mauvais choix, saisir 1, 2 ou 3" << endl;
            cout << "saisir 1 ou 2" << endl;
            cin >> newchoice;

        }
    } while (newchoice != 1 && newchoice != 2 && newchoice != 3);

    if (newchoice == 1) {
        initBestiaire(bestiaire);
    }
    else if (newchoice == 2) {
        triBestiaire(bestiaire);
    }
    displayBestiaire(bestiaire);
} 

void powerupAndEvolution(Pokedex*pokedex,EspecePokemon bestiaire[150], Ressource & Ressources, Historique *historique,Evolution *evolution) 
{
    int newchoice = 0;
    int idPokemon = -1;

    do
    {
        cout << "Choisir l'identifiant du pokemon à faire évoluer ou progresser." << endl;
        cin >> idPokemon;
    } while (idPokemon < 0);

    cout << "Choisir l'action à réaliser : " << endl;
    cout << " 1 - Powerup" << endl;
    cout << " 2 - Evolution" << endl;
    cout << " 3 - Retour au menu principal" << endl;


    do {
        cin >> newchoice;
        if (newchoice != 1 && newchoice != 2 && newchoice != 3) {
            cout << "mauvais choix, saisir 1, 2 ou 3";
        }
    } while (newchoice != 1 && newchoice != 2 && newchoice != 3);

    Pokemon* p = &(pokedex->mesPokemons[idPokemon]);

    if (newchoice == 1) 
    {
        if (Ressources.candies >= 10 && Ressources.stardust >= 500)
        {
            Ressources.candies = Ressources.candies - 10;
            Ressources.stardust = Ressources.stardust - 500;
            Powerup(p);
        }
        else
        {
            cout << "Power-up impossible : 10 bonbons et 500 poussières sont nécessaires ";
        }
    }
    else if (newchoice == 2)
    {
        int i = 0;
        while (i < 150 && strcmp(p->nom, bestiaire[i].nom) != 0) 
        {
            i++;
        }

        // identifier le nom de l'espece vers laquelle le pokemon evolue
        const char* Evolution = bestiaire[i].evolvesTo;

        // connaitre le nombre de bonbons nécessaires pour cette évolution
        int BonbonsNecessaires = bestiaire[i].nbBonbonsPourEvoluer;

        if (Evolution == nullptr) {
            cout << "Evolution impossible: le pokemon est deja dans sa derniere evolution !";
        }
        else {
            if (Ressources.candies < BonbonsNecessaires) 
            {
                cout << "Evolution impossible : " << BonbonsNecessaires << " bonbons sont nécessaires ";
            }
            else 
            {
                Ressources.candies = Ressources.candies - BonbonsNecessaires; // mise à jour du nombre de bonbons en possession
                insertionliste(evolution,historique, p, bestiaire); // insertion du maillon du pokemon evolue dans la liste chainees
                evolve(p, Evolution); 
            }
        }

    }
}

int main(int argc, const char* argv[]) 
{

    EspecePokemon bestiaire[150]; /* tableau de 150 EspecePokemon*/
    initBestiaire(bestiaire); /*on initialise le tableau bestiaire*/
    
    // Initialisation des ressources
    Ressource Ressources{};
    Ressources.candies = 250;
    Ressources.stardust = 1200;

    CombatHash* hashtable = initCombatHash(); //initialisation de hashtable

    // Initialisation de la liste chainee :

    Historique* histo = (Historique*)malloc(sizeof(struct Historique));
    Evolution* evolution = (Evolution*)malloc(sizeof(struct Evolution));

    //initialisation du premier maillon (qui est vide/nul?)
    evolution->from = nullptr;
    evolution->to = nullptr;
    evolution->nextEvol = NULL;
    histo->debut = evolution; // on "accroche historique au maillon initialise
    histo->nombre = 0;

    
    const char* typesLabel[18] = { "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock",
         "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic",
         "Ice", "Dragon", "Dark", "Fairy" };
   
    Pokedex* pokedex = initPokedex(4);
    Pokemon a;
    a.nom = "Bulbasaur";
    a.xp = 1;
    a.cp = 4;
    a.evolution = 0;
    a.pv = 23;

    Pokemon b;
    b.nom = "Charmander";
    b.xp = 0;
    b.cp = 123;
    b.evolution = 2;
    b.pv = 134;

    Pokemon c;
    c.nom = "Zubat";
    c.xp = 40;
    c.cp = 300;
    c.evolution = 1;
    c.pv = 223;

    Pokemon d;
    d.nom = "Paras";
    d.xp = 0;
    d.cp = 23;
    d.evolution = 1;
    d.pv = 90;

    Pokemon e;
    e.nom = "Arkanine";
    e.xp = 0;
    e.cp = 23;
    e.evolution = 2;
    e.pv = 290;

    insertPokemon(pokedex, a);
    insertPokemon(pokedex, b);
    insertPokemon(pokedex, c);
    insertPokemon(pokedex, d);
    insertPokemon(pokedex, e);
    displayPokedex(pokedex, bestiaire, typesLabel, Ressources);
    cout << "***************************************************" << endl << endl << endl;
   
    int choice = 6;
   
    cout << "                                   .::.                            " << endl;
    cout << "                                 .;:**'                            " << endl;
    cout << "                                 `                                 " << endl;
    cout << "     .:XHHHHk.              db.   .;;.     dH  MX                  " << endl;
    cout << "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN       " << endl;
    cout << "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM  " << endl;
    cout << "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP  " << endl;
    cout << "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM   " << endl;
    cout << "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP   " << endl;
    cout << "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM    " << endl;
    cout << "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP    " << endl;
    cout << "         'MMM.                                             IMX     " << endl;
    cout << "          ~M!M                                             IMP     " << endl << endl;
    cout << "                            - TSE EDITION -                        " << endl;
    
    printMenu();

    do {
        cin >> choice;
        switch (choice) {
        case 1:
            Bestiaire(bestiaire);
            break;
        case 2:
            displayPokedex(pokedex, bestiaire, typesLabel, Ressources);
            break;
        case 3:
            int newchoice;
            do
            {
                Pokemon p = genererPokemon(bestiaire, typesLabel);
                cout << endl << endl;;
                cout << " Que voulez-vous faire ? " << endl;
                cout << " 1 - Essayer de capturer le pokemon" << endl;
                cout << " 2 - Ne pas attraper le pokemon" << endl;

                do
                {
                    cin >> newchoice;
                    if (newchoice != 1 && newchoice != 2)
                    {
                        cout << "Mauvais choix, saisir 1 ou 2" << endl;
                        cin >> newchoice;
                    }
                } while (newchoice != 1 && newchoice != 2);

                if (newchoice == 1)
                {
                    int tirage = random_at_most(100);
                    if (tirage > 60)
                    {
                        insertPokemon(pokedex, p);
                        cout << "Vous avez attraper le pokemon " << endl;
                        Ressources.candies += 3000; // remettre 3 après le test
                        Ressources.stardust += 100;
                    }
                    else
                    {
                        cout << "Vous n'avez pas reussi a attraper le pokemon" << endl;
                    }
                }
                else if (newchoice == 2)
                {
                    cout << " Que voules-vous faire ?" << endl;
                    cout << "1 - Attraper un autre pokemon " << endl;
                    cout << "2 - Revenir au menu principal " << endl;
                    cin >> newchoice;
                    if (newchoice == 2)
                    {
                        newchoice = 3;
                    }
                }

            } while (newchoice != 3);
            displayPokedex(pokedex, bestiaire, typesLabel, Ressources);
            break;
        case 4:
            int choice;
            displayPokedex(pokedex, bestiaire, typesLabel, Ressources);
            cout << "-----------------------" << endl;
            powerupAndEvolution(pokedex, bestiaire, Ressources,histo,evolution);
            afficherListe(histo);
            break;
        case 5:
            displayPokedex(pokedex, bestiaire, typesLabel, Ressources);
            combat(hashtable,pokedex,bestiaire);
            break;
        case 6:
            std::cout << "Good bye, we will ctach 'em all later!\n";
            return 0;
        default:
            cout << "Veuillez saisir une entrée entre 1 et 6.";
            break;
        }
        printMenu();
    } while (choice != 6);

    std::cout << "Good bye, we will catch 'em all later!\n";
    return 0;
}
