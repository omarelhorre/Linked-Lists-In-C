//Friday Nov 24 2:16AM
//Creation lib.h
//Listes Chainee
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nom[50];
    float prix;
    int qte;
    noeud* suivant;
}noeud;

typedef struct{
    noeud* debut;
    noeud* fin;
    int ref;
}liste;

void verifyListeAllocation(liste* li){
    if(li==NULL){
        perror("erreur");
        exit(EXIT_FAILURE);
    }
}
void verifyNoeudAllocation(noeud* li){
    if(li==NULL){
        perror("erreur");
        exit(EXIT_FAILURE);
    }
}
liste* creer_liste_produits(void){
    liste* li = (liste *)malloc(sizeof(liste));
    verifyListeAllocation(li);
    li->debut = 0;
    li->fin = 0;
    li->ref = 0;
    return(li);
}
noeud* creer_produit(void){
    noeud* E1;
    E1 = malloc(sizeof(noeud));
    verifyNoeudAllocation(E1);
    E1->qte = 0;
    E1->prix = 0;
    E1->nom[0] = '\0'; //on initialise comme ca?
    E1->suivant = NULL;
    return (E1);
}
noeud* saisirProduit(void){
    noeud* E1;
    E1= creer_produit();
    printf("entrer la designation de votre produit : ");
    scanf("%s",E1->nom);
    printf("entrer le prix de votre produit : ");
    scanf("%d",E1->prix);
    printf("entrer la quantite disponible : ");
    scanf("%d",E1->qte);
    return(E1);

}
void ajouter_produit_liste_fin(liste* li){
    noeud* E;
    E = saisirProduit();
    //cas d'une liste vide
    if(li->debut == NULL){
        li->debut = E;
        li->fin = E;

    }
    else{
        li->fin->suivant = E;
        li->fin = E;
    }
    //ajouter le nombre d'elements
    (li->ref)++;

}
void ajouter_produit_liste_debut(liste* li){
    noeud* E;
    E = saisirProduit();
    //cas d'une liste vide
    if(li->debut == NULL){
        li->debut = E;
        li->fin = E;
    }
    else{
        E->suivant = li->debut;
        li->debut = E;
    }
    //ajouter le nombre d'elements
    (li->ref)++;

}
void ajouter_produit_liste_milieu(liste* li){
    noeud* E;
    E = saisirProduit();
    int mileu = (li->ref)/2;
    noeud* courant = malloc(sizeof(int)); //dans la seance du tp on a pas allouer mais normallement on doit allouer non?
    //cas d'une liste vide
    if(li->debut == NULL){
        printf("la liste est vide, insertion au debut"); //on refait la verification est ce que c normal?
        ajouter_produit_liste_debut(li);
    }
    else{
        for(int i = 0; i<mileu-1 ; i++) {
            courant = courant->suivant;
        }
        E->suivant = courant->suivant;
        courant->suivant = E;
    }
    if(E->suivant == NULL){
        printf("l'element est insere a la fin!\n");
        li->fin = E;
    }
    //augmenter le nombre d'elements
    (li->ref)++;

}
