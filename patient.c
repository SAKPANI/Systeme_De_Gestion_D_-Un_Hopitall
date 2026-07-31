#include<stdio.h>
#include <stdlib.h>
#include "patient.h"


//Creation d'un patient
Data *CreerPatient(Patient p){
    Data *nouveau=(Data*)malloc(sizeof(Data));
    if(nouveau == NULL){
        printf("Ereur de malloc !");
        exit(1);
    }
    nouveau->donne.id=p.id;
    strcpy(nouveau->donne.nom, p.nom);
    strcpy(nouveau->donne.prenom, p.prenom);
    nouveau->donne.age = p.age;
    strcpy(nouveau->donne.sexe, p.sexe);
    strcpy(nouveau->donne.groupeSanguin, p.groupeSanguin);
    nouveau->suivant =NULL;

    return nouveau;
}

//Ajout d'un patient

//Saisie des donnes
void SaisirInfoPatient(Patient p){
    printf("\n===================================================\n");
    printf("\nSAISIR LES INFORMATION D'UN PATIENT\n");
    printf("\n===================================================\n\n");
    char temp[51];

    printf("Indentifiant du patient :");
    scanf("%d", &p.id);

    printf("Nom du patient :");
    scanf("%s",temp);
    strcpy(p.nom,temp);

    printf("Prenom du patient :");
    scanf("%s", temp);
    strcpy(p.prenom, temp);

    printf("Age du patient :");
    scanf("%d", &p.age);

    printf("Groupe sanguin du patient :");
    scanf("%d", &p.groupeSanguin);

}


//Insertion des donnes dans la liste chainee(tete)
Data *AjouterPatient(Data *tete, Patient p){
    Data *nouveau = CreerPatient(p);

    nouveau->suivant = tete;
    tete =nouveau;

    return tete;
}


//Rechercher un patient dans la liste
void Recherche(Data *tete){
    Patient cherche;
    printf("Indentifiant du patient :");
    scanf("%d", &cherche.id);
    
    Data *courant = tete ;
    while(courant !=NULL){
        if(cherche.id == courant->donne.id){
            cherche=courant->donne;

            printf("---------------------------------------------------\n");
            printf("INFORMATION DU PATIENT TROUVER : ID : \n%d", cherche.id);
            printf("--------------------------------------------------\n");
            printf("\t->Nom: %s\n->Prenom: %s\n->Age : %d\n0->Sexe : %s\n->Groupe Sanguin : %s",
                cherche.nom,
                cherche.prenom,
                cherche.age,
                cherche.sexe,
                cherche.groupeSanguin
            );
            printf("\n-----------------------------------------------------------------------\n\n");
            break;
        }
        else{
            printf("Indentifiant n'existe pas .Voulez-vous tester un autre id?1.oui\n0.Non !!\n");
            int choix;
            int i=2;
            while(i !=0){
                printf("Choisissez :");
                scanf("%d", &choix);
                if(choix == 1){
                    printf("Indentifiant du patient :");
                    scanf("%d", &cherche.id);
                }
                else if(choix == 0){
                    i=0;
                }
            }

        }
        courant = courant->suivant;
    }


}


