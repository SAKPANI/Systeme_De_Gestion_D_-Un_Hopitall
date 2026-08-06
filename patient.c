#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"


// Création d'un patient
Data *CreerPatient(Patient p){
    Data *nouveau = (Data*)malloc(sizeof(Data));
    if(nouveau == NULL){
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }

    nouveau->donne.id = p.id;
    strcpy(nouveau->donne.nom, p.nom);
    strcpy(nouveau->donne.prenom, p.prenom);
    nouveau->donne.age = p.age;
    strcpy(nouveau->donne.sexe, p.sexe);
    strcpy(nouveau->donne.groupeSanguin, p.groupeSanguin);

    nouveau->suivant = NULL;

    return nouveau;
}

// Initialisation de la liste


// Saisie des informations
void SaisirInfoPatient(Patient *p){

    printf("\n========================================\n");
    printf(" SAISIE DES INFORMATIONS D'UN PATIENT\n");
    printf("========================================\n");

    printf("Identifiant : ");
    scanf("%d", &p->id);

    printf("Nom : ");
    scanf("%49s", p->nom);

    printf("Prenom : ");
    scanf("%49s", p->prenom);

    printf("Age : ");
    scanf("%d", &p->age);

    printf("Sexe (M/F) : ");
    scanf("%1s", p->sexe);

    printf("Groupe sanguin (A+, O-, B+, ...) : ");
    scanf("%4s", p->groupeSanguin);
}


// Ajouter un patient

Data *AjouterPatient(Data *tete, Patient p){
    Data *nouveau = CreerPatient(p);
    nouveau->suivant = tete;
    return nouveau;
}


Data *ModifierInfoPatient(Data *tete){
    Patient modif;
    if(tete == NULL){
        printf("AUCUN PATIENT A MODIFIER LISTE VIDE ! ");
        return NULL;
    }

    printf("Entrer l'ID du patient:");
    scanf("%d",&modif.id);
    Data *courant= tete;
    while(tete != NULL){
        if(courant->donne.id == modif.id){

            printf("========================================================================\n");
            printf("\t  DU  INFORMATION DU PATIENT TROUVER \n\n|%d\n|%s\n|%s\n",
                courant->donne.id,
                courant->donne.nom,
                courant->donne.prenom
            );
            printf("=========================================================================\n\n");
            printf("VEULLIEZ SAISIR LES MODIFICATION SUR LE PATIENT TROUVE|\n");
            printf("------------------------------------------------\n\n");
            printf("Identifiant : ");
            scanf("%d", &courant->donne.id);

            printf("Nom : ");
            scanf("%49s", courant->donne.nom);

            printf("Prenom : ");
            scanf("%49s", courant->donne.prenom);

            printf("Age : ");
            scanf("%d", &courant->donne.age);

            printf("Sexe (M/F) : ");
            scanf("%1s", courant->donne.sexe);

            printf("Groupe sanguin (A+, O-, B+, ...) : ");
            scanf("%4s", courant->donne.groupeSanguin);

            return tete;
        }
        courant= courant->suivant;
    }
    //printf("l'indentifant :%d n'existe pas dans la liste des patient enregistrer", courant->donne.id);
}
// =============================
// Rechercher un patient
void Recherche(Data *tete){

    int idRecherche;

    printf("\n\n***************************************\n");
    printf("\tRECHERCHE D'UN PATIENT A PARTIR DE SON ID\n");
    printf("*******************************************\n");

    if(tete == NULL){
        printf("\n\nAucun patient enregistrer !! Liste vide\n\n");
    }

    printf("Identifiant du patient : ");
    scanf("%d", &idRecherche);

    Data *courant = tete;

    while(courant != NULL){

        if(courant->donne.id == idRecherche){

            printf("\n========================================\n");
            printf(" PATIENT TROUVE\n");
            printf("========================================\n");

            printf("ID              : %d\n", courant->donne.id);
            printf("Nom             : %s\n", courant->donne.nom);
            printf("Prenom          : %s\n", courant->donne.prenom);
            printf("Age             : %d\n", courant->donne.age);
            printf("Sexe            : %s\n", courant->donne.sexe);
            printf("Groupe sanguin  : %s\n", courant->donne.groupeSanguin);
            printf("========================================\n");

            return;
        }

        courant = courant->suivant;
    }

    printf("\nAucun patient avec l'ID %d.\n", idRecherche);
}


//Suppression des infos d'un patient
Data *SupprimerPatient(Data *tete){
    int id;
    Data *temp;
    printf("\n\n----------------------------------\n");
    printf("\tSUPPRESSION DES DONNES [D'UN PATIENT]\n");
    printf("---------------------------------------\n");

    if(tete == NULL){
        printf("\nAucun element a supprimer !!\n");
    }

    else{
        printf("Entrer l' ID du patient a supprimer :");
        scanf("%d", &id);

        while(tete !=NULL){
            if(tete->donne.id == id){
                temp=tete;
                tete= tete->suivant;
                free(temp);
                printf("Patient supprimer avec succes !!\n");
                return tete;
            }
            else{
                printf("L'ID : %d n'exist pas dans la liste des patient !\n", id);
            }
            tete = tete->suivant;
        }

    }
    return NULL;
}

void LibererData(Data *tete){
    Data *temp;
    while(tete !=NULL){
        temp = tete;
        tete=tete->suivant;
        free(temp);
    }
}


