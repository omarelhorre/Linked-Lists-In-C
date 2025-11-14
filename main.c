//Friday Nov 24 2:16AM
//Creation lib.h
//Listes Chainee
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nom[50];
    float prix;
    int qte;
    noeud* suivant;
}noeud;

typedef struct
{
    noeud* debut;
    noeud* fin;
    int ref;
}liste;
void verifyListeAllocation(liste* li)
{
    if(li==NULL){
        perror("erreur");
        exit(EXIT_FAILURE);
    }
}
void verifyNoeudAllocation(noeud* E)
{
    if(E==NULL){
        perror("erreur");
        exit(EXIT_FAILURE);
    }
}
verifyListContents(liste* li){
    if(li->debut==NULL){
        printf("liste vide\n" "Retour Au Menu Principale...\n");
    }

}
liste* creer_liste_produits(void)
{
    liste* li = (liste *)malloc(sizeof(liste));
    verifyListeAllocation(li);
    li->debut = 0;
    li->fin = 0;
    li->ref = 0;
    return(li);
}
noeud* creer_produit(void)
{
    noeud* E1;
    E1 = malloc(sizeof(noeud));
    verifyNoeudAllocation(E1);
    E1->qte = 0;
    E1->prix = 0;
    E1->nom[0] = '\0'; //on initialise comme ca?
    E1->suivant = NULL;
    return (E1);
}
noeud* saisirProduit(void)
{
    noeud* E1;
    E1= creer_produit();
    printf("entrer la designation de votre produit : ");
    scanf("%s",E1->nom);
    printf("entrer le prix de votre produit : ");
    scanf("%d",E1->prix);
    printf("entrer la quantite disponible : ");
    scanf("%d",E1->qte);
    E1->suivant = NULL;
    return(E1);

}
void ajouter_produit_liste_fin(liste* li)
{
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
void ajouter_produit_liste_debut(liste* li)
{
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
void ajouter_produit_liste_milieu(liste* li)
{
    noeud* E;
    E = saisirProduit();
    int mileu = (li->ref)/2;
    noeud* courant ;
    //cas d'une liste vide
    if(li->debut == NULL){
        printf("la liste est vide, insertion au debut"); //on refait la verification est ce que c normal?
        ajouter_produit_liste_debut(li);
    }
    else{
        courant = li->debut; //ici courant stock l'adresse de debut
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
void affiherListeProduit(liste* li)
{
    verifyListContents(li);
    noeud* ptr;
    ptr = li->debut;
    while(ptr !=NULL){
        printf("Le nom du produit est : %s\nPrix : %f\nQuantite: %d\n",ptr->nom,ptr->prix,ptr->qte);
        ptr = ptr->suivant;
    }

}

void enregistrer_liste_produits(FILE* myFile,liste* li)
{
    myFile = fopen("produits.txt","a+");
    noeud* ptr;
    ptr = li->debut;
    verifyListContents(li);
    while(ptr->suivant != NULL){
        fprintf(myFile,"%s %f %d",ptr->nom,ptr->prix,ptr->qte);
    }
    fclose(myFile);
}

void trier_liste_produits(liste* li)

{
    verifyListContents(li);
    noeud* i;
    noeud* j;
    noeud*tmp;

    for( i=(li->debut) ; i!=NULL; i=i->suivant)
    {
    
        for(j=(i->suivant) ; i!=NULL; j=j->suivant)
        {
            if(j->prix < i->prix)
        {
            //echange mots
            strcpy((j->nom),(tmp->nom)); 
            strcpy((i->nom),(j->nom));
            strcpy((tmp->nom),(i->nom));

            //echange prix
            tmp->prix = j->prix;
            j->prix = i->prix;
            i->prix = tmp->prix;

            //echange Qte
            tmp->qte = j->qte;
            j->qte = i->qte;
            i->qte = tmp->qte;
        }
        }
        
    }
}

noeud* trouver_produit_cher(liste*li)
{
verifyListContents(li);
float max;
noeud* i;
noeud* cou;
max = li->debut->prix;
for(i = li->debut; i!=NULL; i = i->suivant )
{
    if(i->prix > max)
    {
        max = i->prix;
        cou = i;
    }
}
printf("l'element ayant le plus grand prix est \nNom : %s\nPrix : %f\nQuantite : %d",cou->nom,cou->prix,cou->qte);
return cou;
}

void lireDepuisFichier(FILE *file)
{
    noeud* buffer = (noeud*) malloc(sizeof(noeud));
    buffer->suivant = NULL;
    while(fscanf(file,"%s %f %d",buffer->nom, buffer->prix,buffer->qte) == 3)
    {
        printf("Designation : %s | Prix : %f | Stock : %d",buffer->nom, buffer->prix,buffer->qte);
    }
}
void main(void)
{
    liste* list;
    list = creer_liste_produits();
    FILE* myFile;
    printf(
    "-----------------------------------------------------\n"
    "Bienvenue dans programme de gestion de produits\n"
    "-----------------------------------------------------\n"
    "0. AFficher la liste de produits a partir de la liste\n"
    "-----------------------------------------------------\n"
    "1. Ajouter produit au debut \n"
    "-----------------------------------------------------\n"
    "2. Ajouter produit au milieu \n"
    "-----------------------------------------------------\n"
    "3. Ajouter produit a la fin \n"
    "-----------------------------------------------------\n"
    "4.Trier liste produits \n"
    "-----------------------------------------------------\n"
    "5. Afficher produit plus cher \n"
    "-----------------------------------------------------\n"
    "6. Enregistrer liste produits \n"
    "-----------------------------------------------------\n"
    "7. Charger depuis fichier \n"
    "-----------------------------------------------------\n"
    "Entrer n'importe quelle valeur pour quitter le programme \n"
    "-----------------------------------------------------\n"
);
int n;
char ans;
//choix de l'utilisateur
do
{
printf("Effectuer un choix : ");
scanf("%c",&ans);
}while (ans<0 || ans> 9);

printf(
    "-----------------------------------------------------\n"
    "Choix effectue"
    "-----------------------------------------------------\n");
switch (ans)
{
case 0:
    affiherListeProduit(list);
    break;
case 1:
    ajouter_produit_liste_debut(list);
    break;
case 2:
    ajouter_produit_liste_milieu(list);
case 3:
    ajouter_produit_liste_fin(list);
case 4:
    trier_liste_produits(list);
case 5:
trouver_produit_cher(list);
case 6:
enregistrer_liste_produits(myFile,list);
case 7:
lireDepuisFichier(myFile);
default:
exit(1);
    break;
}
}
