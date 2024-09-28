#include <stdio.h>
#include <string.h>  // Pour utiliser strcmp

#define MAX_LIVRES 100

int main() {
    char titres[MAX_LIVRES][50];
    char auteurs[MAX_LIVRES][50];
    float prix[MAX_LIVRES];
    int quantite[MAX_LIVRES];
    int totalLivres = 0;
    int choix;

    do {
        // Affichage du menu
        printf("\n--- Menu Gestion de Stock ---\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre par titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Ajouter un livre
                if (totalLivres < MAX_LIVRES) {
                    printf("Entrez le titre du livre: ");
                    scanf(" %[^\n]s", titres[totalLivres]);

                    printf("Entrez l'auteur du livre: ");
                    scanf(" %[^\n]s", auteurs[totalLivres]);

                    printf("Entrez le prix du livre: ");
                    scanf("%f", &prix[totalLivres]);

                    printf("Entrez la quantité du livre: ");
                    scanf("%d", &quantite[totalLivres]);

                    totalLivres++;
                } else {
                    printf("Stock plein, impossible d'ajouter plus de livres.\n");
                }
                break;

            case 2:
                // Afficher tous les livres
                if (totalLivres == 0) {
                    printf("Aucun livre en stock.\n");
                } else {
                    for (int i = 0; i < totalLivres; i++) {
                        printf("Livre %d: Titre: %s, Auteur: %s, Prix: %.2f, Quantité: %d\n",
                               i + 1, titres[i], auteurs[i], prix[i], quantite[i]);
                    }
                }
                break;

            case 3: {
                // // Rechercher un livre par son titre et afficher les détails si trouvé
                char titreRecherche[50];
                printf("Entrez le titre du livre à rechercher: ");
                scanf(" %[^\n]s", titreRecherche);

                int trouve = 0;
                for (int i = 0; i < totalLivres; i++) {
                    if (strcmp(titres[i], titreRecherche) == 0) { 
                       //
                        printf("Livre trouvé: Titre: %s, Auteur: %s, Prix: %.2f, Quantité: %d\n",
                               titres[i], auteurs[i], prix[i], quantite[i]);
                        trouve = 1;
                    }
                }

                if (!trouve) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 4: {
                // Mettre à jour la quantité d'un livre
                char titreRecherche[50];
                printf("Entrez le titre du livre pour mettre à jour la quantité: ");
                scanf(" %[^\n]s", titreRecherche);

                int trouve = 0;
                for (int i = 0; i < totalLivres; i++) {
                    if (strcmp(titres[i], titreRecherche) == 0) {
                        printf("Entrez la nouvelle quantité: ");
                        scanf("%d", &quantite[i]);
                        printf("Quantité mise à jour.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 5: {
                // n supprimer  livre
                char titreRecherche[50];
                printf("Entrez le titre du livre à supprimer: ");
                scanf(" %[^\n]s", titreRecherche);

                int trouve = 0;
                for (int i = 0; i < totalLivres; i++) {
                    if (strcmp(titres[i], titreRecherche) == 0) {
                        // Décalage des livres suivants pour supprimer
                        for (int k = i; k < totalLivres - 1; k++) {
                            strcpy(titres[k], titres[k + 1]);
                            strcpy(auteurs[k], auteurs[k + 1]);
                            prix[k] = prix[k + 1];
                            quantite[k] = quantite[k + 1];
                        }
                        totalLivres--;
                        printf("Livre supprimé.\n");
                        trouve = 1;
                        break;
                    }
                }

                if (!trouve) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 6: {
                //  n afficher  nombre total dial livres en stock
                int totalQuantite = 0;
                for (int i = 0; i < totalLivres; i++) {
                    totalQuantite += quantite[i];
                }
                printf("Nombre total de livres en stock: %d\n", totalQuantite);
                break;
            }

            case 7:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }




    } while (choix != 7);





    return 0;
}
