#ifndef CONSULTATION_H
#define CONSULTATION_H

//Gestion des consultation en utilisant lA STRICTURE DE DONNES ABR

//Date de consultation
typedef struct{
    int jour;
    int mois;
    int anne;
}Date;

//Stricture d'une consultation d'un patient
typedef struct{
    int numero;
    char date[20];
    char diagnostic[100];
    char traitement[100];
    Date date;

}Consultation;


typedef struct Tconsulter{
    Consultation donne;
    struct Tconsulter *gauche;
    struct Tconsulter *droit;

}Consulter;

//Creation d'une nouvelle consultation
Consulter *CreerConsultation(Consultation c);

//Rechercher en connaissant le numero de consultation
Consulter *RechercherConsultation(Consulter *racineC, Consultation c );

//Supprimer a partir d'un numero
Consulter *SupprimerConsultation(Consulter *racineC, Consultation c);

//Par cour de la consultation en trie en fonction de la data
void AfficherConsultTrie(Consulter *racineC);
#endif