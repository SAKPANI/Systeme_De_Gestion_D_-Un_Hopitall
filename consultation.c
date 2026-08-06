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


//Fonction de saisie des des donnes des consultations
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
                scanf("%d", &c->numero);
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

                printf("\nConsultation Ajouter avec succees\n");

                break;
            }
            tete=tete->suivant;
        }
        printf("Aucun patient avec l'id : %d", id);
    }
}


//Ajout d'une consultation dans l'ABR
Consulter *AjouterConsultation(Consulter *racine, Consultation c){
    if(racine == NULL){
        return CreerConsultation(c);
    }
    else{
        if(c.numero < racine->donne.numero){
            racine->gauche = AjouterConsultation(racine->gauche, c);
        }
        else if(c.numero > racine->donne.numero){
            racine->droit = AjouterConsultation(racine->droit, c);
        }
    }
    return racine;
}


//Recherche d'une consultation a partir de son numero
Consulter *RechercherConsultation(Consulter *racine, Consultation c){
    if(racine == NULL){
        printf("Arbre vide");
        return NULL;
    }
    else{
        if(c.numero == racine->donne.numero){
            return racine;
        }
        else if(c.numero <racine->donne.numero){
            return RechercherConsultation(racine->gauche, c);
        }
        else{
            return RechercherConsultation(racine->droit, c);
        }
    }
}


//Recherche d'un minimum dans un AB
Consulter *minimumABR(Consulter *racine){
    if(racine ==NULL && racine->gauche == NULL){
        return racine;
    }
    else{
        if(racine->gauche !=NULL){
            return minimumABR(racine->gauche);
        }
    }
}


//Suppression d'un ABR
Consulter *SupprimerConsultation(Consulter *racine, Consultation c){
    if(racine == NULL){
        return NULL;
    }
    else{
        printf("\nEntrer le numero de la consultation du psatient :");
        scanf("%d", c.numero);
        if(c.numero == racine->donne.numero){
            return racine;
        }
        else if(c.numero <racine->donne.numero){
            return SupprimerConsultation(racine->gauche, c);
        }
        else if(c.numero > racine->donne.numero){
            return SupprimerConsultation(racine->droit, c);
        }
        else{
            if(racine->gauche == NULL && racine->droit == NULL){
                free(racine);
                return NULL;
            }
            else if(racine->gauche == NULL && racine->droit !=NULL){
                Consulter *temp =racine->droit;
                free(racine);
                return temp;
            }
            else if(racine->gauche != NULL && racine->droit ==NULL){
                Consulter *temp =racine->gauche;
                free(racine);
                return temp;
            }
            else if(racine->gauche != NULL && racine->droit !=NULL){
                Consulter *Succ = minimumABR(racine->droit);
                racine->donne = Succ->donne;
                return SupprimerConsultation(racine->droit, Succ->donne);
            }
        }
    }
    return racine;
}


//Parcours infixe 
void AfficherConsultTrie(Consulter *racine){
    if(racine !=NULL){
        AfficherConsultTrie(racine->gauche);
        printf("%d\n%d/%d/%d\n%s\n%s",racine->donne.numero,
        racine->donne.date.jour,
        racine->donne.date.mois,
        racine->donne.date.annee,
        racine->donne.diagnostic,
        racine->donne.traitement
    );

    }
}

//Liberation de malloc

void LibererABR(Consulter *racine){
    if(racine !=NULL){
        LibererABR(racine->gauche);
        LibererABR(racine->droit);
        free(racine);

    }
}