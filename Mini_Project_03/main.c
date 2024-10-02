#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char tele[15];
    char mail[60];
} Contact;

int main() {
    Contact c[100]; // Taille fixe du tableau
    int compteur = 0;
    int choix;

    do {
        system("cls");
        system("color 0F");
        printf("============== Menu Principal ==============\n");
        printf("1- Ajouter des Contacts\n");
        printf("2- Affichage des Contacts\n");
        printf("3- Modifier des Contacts\n");
        printf("4- Supprimer des Contacts\n");
        printf("5- Rechercher des Contacts\n");
        printf("6- Statistiques\n");
        printf("7- Quitter\n");
        printf("Taper votre choix : ");
        scanf("%d", &choix);
        getchar(); // Clear the newline character from input buffer

        switch (choix) {
            case 1: {
                int add_choice;
                do {
                    system("cls");
                    printf("============== Menu Ajouter ==============\n");
                    printf("1- Ajouter un Contact\n");
                    printf("2- Ajouter Plusieurs Contacts\n");
                    printf("3- Retour\n");
                    printf("Taper votre choix : ");
                    scanf("%d", &add_choice);
                    getchar(); // Clear the newline character from input buffer

                    switch (add_choice) {
                        case 1: {
                            if (compteur < 100) {
                                printf("Nom : ");
                                fgets(c[compteur].nome, sizeof(c[compteur].nome), stdin);
                                strtok(c[compteur].nome, "\n"); // Remove newline
                                printf("Telephone : ");
                                fgets(c[compteur].tele, sizeof(c[compteur].tele), stdin);
                                strtok(c[compteur].tele, "\n"); // Remove newline
                                printf("Email : ");
                                fgets(c[compteur].mail, sizeof(c[compteur].mail), stdin);
                                strtok(c[compteur].mail, "\n"); // Remove newline
                                compteur++;
                                printf("Contact ajoute avec succes.\n");
                            } else {
                                printf("/_\\ La memoire est pleine !!\n");
                            }
                            break;
                        }
                        case 2: {
                            int n;
                            printf("Combien de contacts voulez-vous ajouter ? ");
                            scanf("%d", &n);
                            getchar(); // Clear the newline character from input buffer
                            for (int i = 0; i < n && compteur < 100; i++) {
                                printf("Contact N°%d\n", compteur + 1);
                                printf("Nom : ");
                                fgets(c[compteur].nome, sizeof(c[compteur].nome), stdin);
                                strtok(c[compteur].nome, "\n");
                                printf("Telephone : ");
                                fgets(c[compteur].tele, sizeof(c[compteur].tele), stdin);
                                strtok(c[compteur].tele, "\n");
                                printf("Email : ");
                                fgets(c[compteur].mail, sizeof(c[compteur].mail), stdin);
                                strtok(c[compteur].mail, "\n");
                                compteur++;
                            }
                            if (compteur >= 100) {
                                printf("/_\\ La memoire est pleine !!\n");
                            }
                            break;
                        }
                        case 3:
                            break; // Retour
                        default:
                            printf("Choix invalide !\n");
                            break;
                    }
                } while (add_choice != 3);
                break;
            }
            case 2: {
                int display_choice;
                do {
                    system("cls");
                    printf("============== Menu Affichage ==============\n");
                    printf("1- Affichage Simple\n");
                    printf("2- Affichage par Ordre Croissant\n");
                    printf("3- Affichage par Ordre Decroissant\n");
                    printf("4- Retour\n");
                    printf("Taper votre choix : ");
                    scanf("%d", &display_choice);
                    getchar(); // Clear the newline character from input buffer

                    switch (display_choice) {
                        case 1: {
                            if (compteur == 0) {
                                printf("Aucun contact a afficher.\n");
                            } else {
                                printf("========= Affichage des Contacts =========\n");
                                printf("| %-25s | %-15s | %-30s |\n", "Nom", "Telephone", "Email");
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                                for (int i = 0; i < compteur; i++) {
                                    printf("| %-25s | %-15s | %-30s |\n", c[i].nome, c[i].tele, c[i].mail);
                                }
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                            }
                            system("pause");
                            break;
                        }
                        case 2:
                        case 3: {
                            // Tri des contacts
                            for (int i = 0; i < compteur - 1; i++) {
                                for (int j = i + 1; j < compteur; j++) {
                                    if ((display_choice == 2 && strcmp(c[i].nome, c[j].nome) > 0) ||
                                        (display_choice == 3 && strcmp(c[i].nome, c[j].nome) < 0)) {
                                        Contact temp = c[i];
                                        c[i] = c[j];
                                        c[j] = temp;
                                    }
                                }
                            }
                            // Affichage après tri
                            printf("========= Affichage des Contacts =========\n");
                            printf("| %-25s | %-15s | %-30s |\n", "Nom", "Telephone", "Email");
                            printf("+---------------------------+-----------------+-------------------------------+\n");
                            for (int i = 0; i < compteur; i++) {
                                printf("| %-25s | %-15s | %-30s |\n", c[i].nome, c[i].tele, c[i].mail);
                            }
                            printf("+---------------------------+-----------------+-------------------------------+\n");
                            system("pause");
                            break;
                        }
                        case 4:
                            break; // Retour
                        default:
                            printf("Choix invalide !\n");
                            break;
                    }
                } while (display_choice != 4);
                break;
            }
            case 3: {
                printf("========= Modification des Contacts =========\n");
                char nom[50];
                printf("Entrez le nom du contact a modifier : ");
                fgets(nom, sizeof(nom), stdin);
                strtok(nom, "\n");

                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(c[i].nome, nom) == 0) {
                        found = 1;
                        printf("Nouveau nom : ");
                        fgets(c[i].nome, sizeof(c[i].nome), stdin);
                        strtok(c[i].nome, "\n");
                        printf("Nouveau telephone : ");
                        fgets(c[i].tele, sizeof(c[i].tele), stdin);
                        strtok(c[i].tele, "\n");
                        printf("Nouveau email : ");
                        fgets(c[i].mail, sizeof(c[i].mail), stdin);
                        strtok(c[i].mail, "\n");
                        printf("Contact modifie avec succes.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Contact non trouve.\n");
                }
                break;
            }
            case 4: {
                printf("========= Supprimer un Contact =========\n");
                char nom[50];
                printf("Entrez le nom du contact a supprimer : ");
                fgets(nom, sizeof(nom), stdin);
                strtok(nom, "\n");

                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(c[i].nome, nom) == 0) {
                        found = 1;
                        for (int j = i; j < compteur - 1; j++) {
                            c[j] = c[j + 1];
                        }
                        compteur--;
                        printf("Contact supprime avec succes.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Contact non trouve.\n");
                }
                break;
            }
            case 5: {
                printf("========= Recherche un Contact =========\n");
                char nom[50];
                printf("Entrez le nom du contact a rechercher : ");
                fgets(nom, sizeof(nom), stdin);
                strtok(nom, "\n");

                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(c[i].nome, nom) == 0) {
                        found = 1;
                        printf("Contact trouve :\n");
                        printf("Nom : %s\n", c[i].nome);
                        printf("Telephone : %s\n", c[i].tele);
                        printf("Email : %s\n", c[i].mail);
                        break;
                    }
                }
                if (!found) {
                    printf("Contact non trouve.\n");
                }
                break;
            }
            case 6:
                printf("Nombre total de contacts : %d\n", compteur);
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }
        system("pause");
    } while (choix != 7);

    return 0;
}
