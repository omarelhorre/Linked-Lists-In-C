#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definition des structures
typedef struct noeud{
    struct noeud* precedent;
    char nom[50];
    float prix;
    int quantite;
    struct noeud* suivant;
}noeud;

typedef struct list{
    noeud* debut;
    noeud* fin;
    int nef;
}list;

noeud* creer_produit(void){
    noeud* E = malloc(sizeof(noeud));
    if(E==NULL) exit(EXIT_FAILURE);
    E->nom[0] = '\0';
    E->prix = 0;
    E->suivant = NULL;
    E->quantite = 0;
    E->precedent= NULL;
    return(E);
}

list* creer_liste_produits(void){
    list *li = malloc(sizeof(list));
    if(li==NULL) exit(EXIT_FAILURE);
    li->debut = NULL;
    li->fin = NULL;
    li->nef = 0;
    return li;
}
noeud* saisir_produit(void)
{
    noeud* E1 = creer_produit();
    printf("entrer le nom du produit : ");
    scanf("%s",E1->nom);
    printf("entrer le prix : ");
    scanf("%f",&E1->prix);
    printf("entrer le stock : ");
    scanf("%d",&E1->quantite);
    return E1;

}
void ajouter_produit_liste_debut(list* li){
    noeud* ptr = saisir_produit();
    if(li->fin == NULL)
    {
        printf("liste vide");
        li->debut = li->fin = ptr;
    }
    else
    {
         ptr->suivant = li->debut;
         li->debut->precedent = ptr;
         li->debut = ptr;
        }
    li->nef++;
}

void ajouter_produit_liste_fin(list* li){
    noeud* ptr = saisir_produit();
    if(li->fin == NULL)
    {
        printf("liste vide, Insertion au debut");
        li->debut = li->fin = ptr;
    }
    else
    {
         ptr->precedent = li->fin;
         li->fin->suivant = ptr;
         li->fin = ptr;
        }
    li->nef++;
    printf("Donnes inseres avec succes\n"
    "Retour au menu principale : ");
}

int ajouter_produit_liste_milieu(list* li){
    int milieu;
    /* if(li->fin == NULL)
    {
        printf("Insertion au milieu impossible, veuillez remplir la liste d'abord : \n ");
        ajouter_produit_liste_debut(li);

    }
    else{ */
    milieu = (li->nef / 2);
    noeud* courant;
    courant = li->debut;
    if(li->nef < 2){
        printf("aucun element ou un seul existe dans la liste\n\n");
        ajouter_produit_liste_fin(li); //comme debut comme fin?
        return 0;
    }
    noeud* ptr = saisir_produit();
    for (int i=0; i<milieu-1; i++){
        courant = courant->suivant;
    }
    ptr->suivant = courant->suivant;
    ptr->precedent = courant;
    courant->suivant->precedent = ptr;
    courant->suivant = ptr;
   // }
    li->nef ++;
    return 1;
}
void afficher_liste_produits(list* li){
    noeud* ptr;
    ptr = li->debut;
    if(ptr==NULL){
        printf("liste vide retour au menu princiapal");
    }
    printf("NULL");
    while(ptr != NULL){
    printf("Nom : %s | prix : %f | stock : %d\n",ptr->nom,ptr->prix,ptr->quantite);
    ptr = ptr->suivant;}
    printf("NULL");

}

void afficher_liste_produits_inv(list* li){
    noeud* ptr;
    ptr = li->fin;
    if(ptr==NULL){
        printf("liste vide retour au menu princiapal");
    }
    printf("NULL");
    while(ptr != NULL){
    printf("Nom : %s | prix : %f | stock : %d\n",ptr->nom,ptr->prix,ptr->quantite);
    ptr = ptr->precedent;}
    printf("NULL");
    
}
