//GESTION DES RENDEZ VOUS AVEC UN TABLEAU DYNAMIQUE
//------------------------------------------------------

#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#define MAX_RDV[100];

//Strucure de la date
typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

// Structure de l'heur
typedef struct{
    int heur;
    int minute;
    int seconde;
}Temp;

//Strucutre d'un rendevous
typedef struct{
    int idPatient;
    Date date;
    Temp heur;
}Rendezvous;

//Ajout d'un nouveau rendezvous
Rendezvous *AjouterRDV(Rendezvous *rvd, Rendezvous info);

//Nombre de rendevous

int NombreRvd(Rendezvous *rvd);

//Supprimer un rendevous en fonction de son id 
Rendezvous *SupprimerRvd(Rendezvous *rvd);

//Rechercher un rendevous connaissant l'identifiant
void RechercherRvd(Rendezvous *rvd);

//Trie par date
void TrieParDate(Rendezvous *rvd);

//Trie par heur
void TrieParHeur(Rendezvous *rvd);

#endif

