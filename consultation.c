#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "patient.h"
#include "consultation.h"


//creation d'une consultation
Consulter *CreerConsultation(Consultation c){
    Consulter *nouveau = (Consulter*)malloc(sizeof(Consulter));
    if(nouveau == NULL){
        printf("Erreur de malloc");
        exit(1);
    }
    nouveau->donne.numero = c.numero;
//      Date(jour, mois, annee)
    nouveau->donne.date.jour = c.date.jour ;
    nouveau->donne.date.mois= c.date.mois;
    nouveau->donne.date.annee= c.date.annee;
    //
    strcpy(nouveau->donne.diagnostic, c.diagnostic);
    strcpy(nouveau->donne.traitement, c.traitement);

    nouveau->gauche= NULL;
    nouveau->droit =NULL;

    return nouveau;
}

void SaisirConsultation (Data *tete,Consultation *c){
    int id;

    if(tete == NULL){
        printf("\n\nAucun patient enregistrer !!\n");
    }

    else{
        printf("\n\n**********************************************************\n");
        printf("\t ENRREGISTREMENT DES CONSULTATION D'UN PATIENT \n");
        printf("**************************************************************\n");

        printf("\nEntrer l'identifiant  du patient : ");
        scanf("%d",&id);

        while(tete != NULL){
            if(tete->donne.id == id){
                printf("\nNumero de la consultation du patient :");
                scanf("%d", c->numero);
                printf("------|\n");
                printf("\tDATE\n ");
                printf("-------\n");
                printf("Jour :");
                scanf("%d", &c->date.jour);
                printf("Mois :");
                scanf("%d", &c->date.mois);
                printf("Annee :");
                scanf("%d", &c->date.annee);
                printf("Diagnostic :");
                scanf("%99s", c->diagnostic);
                printf("Traitement :");
                scanf("%99s", c->traitement);

                break;
            }
            tete=tete->suivant;
        }
        printf("Aucun patient avec l'id : %d", id);
    }
}


