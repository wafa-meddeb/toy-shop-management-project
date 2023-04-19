#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define TAILLE_MAX 100


struct Jouet
{
    int id;
    char nom[30];
    char type[50];
    char age[30];
    int prix;
    char fournisseur[30];
    int stock ;
};


struct Fournisseur
{
    int id;
    char nom[30];
    char addresse_mail[30];
    char addresse[30];
    double num;

};

struct Jouet tab [100]= {{1234,"ballon","sport","5-15",10,"gosport",50},{4562,"poupee","fille","5-10",8,"barbieshop",45}};
struct Fournisseur tab1[100] = {{4325,"gosport","sport@gmail.com","ariana",99784632},{7365,"barbieshop","barbie@hotmail.com","tunis",73546900}};
int indexLastGame=1;

void login_admin()
{
    char mail,password;
    printf("------------------ LOGIN ------------------ \n");
    printf("donner votre adresse mail: \n");
    scanf("%s",&mail);
    fflush(stdin);
    printf("donner votre mot de passe: \n");
    scanf("%s",&password);
    fflush(stdin);

}
void login_client()
{
    char mail,reponse_client,reponse_non_abonne;
    printf("------------------ LOGIN ------------------ \n");
    fflush(stdin);
    do
    {
        printf("vous-etes abonné ou non ? [oui :o/O , non:n/N \n");
        scanf("%c",&reponse_client);
    }
    while (reponse_client!='o' && reponse_client!='O'&& reponse_client!='n'&& reponse_client!='N');
    if (reponse_client=='o'|| reponse_client=='O')
    {
        Visualisation_Jouet( tab);
    }
    else if(reponse_client=='n'||reponse_client=='N')
    {
        printf("voulez-vous vous abonner ?");
        scanf("%s",&reponse_non_abonne);
        if (reponse_non_abonne=='n'||reponse_non_abonne=='N')
            Visualisation_Jouet(tab);
        else
        {
            printf("donner votre adresse mail: \n");
            scanf("%s",&mail);
            Visualisation_Jouet(tab);

        }
    }
}
void login_caissier()
{
    char nom,password;
    int numTel;
    double num_securite_sociale;
    printf("------------------ LOGIN ------------------\n ");
    printf("donner votre nom et prenom: \n");
    scanf("%s",&nom);
    printf("donner votre mots de passe: \n");
    scanf("%s",&password);
    printf("donner votre numero de telephone: \n");
    scanf("%i",&numTel);
    printf("donner votre numero de securite sociale: \n");
    scanf("%ld",&num_securite_sociale);
}
void travail_caissier(struct Jouet tab[])
{
    int choix_caissier;
    char ch ;
    do
    {
        do
        {
            printf("veuillez choisir une option [1-4]:\n");
            printf("1-vendre un jouet\n");
            printf("2-visualiser la facture\n");
            printf("3-visualiser la liste des ventes\n");
            printf("4-quitter l'application \n");
            scanf("%i",&choix_caissier);
            fflush(stdin);
        }
        while (choix_caissier<1 ||choix_caissier>5);

        switch(choix_caissier)
        {
        case 1 :
            vendre_jouet();
            break;
        case 2:
            facture();
            break;
        case 3:
            printf("%s",ch);
            break;
        default : //si choix =4
            exit(0);//permet de fermer l'application
        }
        //system("cls");
    }
    while(choix_caissier!=4);

}



void Visualisation_Jouet(struct Jouet tab[ ])
{
    int i;
    printf("======liste des Jouets=====\n");
    for(i = 0 ; i <= 100 ; i++)
    {
        printf("Jouet[%d] = %i/ %s/ %s/ %s/ %i/ %i/ %s \t\t \n", i,(tab[i].id),(tab[i].nom),(tab[i].type),(tab[i].age),(tab[i].prix),(tab[i].stock),(tab[i].fournisseur));
    }
}

void Visualisation_Fournisseur()
{
    int i;
    printf("======liste des Fournisseurs=====\n");
    for(i = 0 ; i <= 100 ; i++)
    {
        printf("Fournisseur[%d]\t\t", i);
    }
}

void ajout_jouet( )
{
    char nom_jouet,type,plage_d_age,fournisseur ;
    char response;
    int id,stock,nb_jouet=0;
    float prix;

    do
    {
        indexLastGame++;
        printf("saisir les données :\n");
        printf("nom du jouet : \n");
        scanf("%S",&(tab[indexLastGame].nom));
        fflush(stdin);
        printf("id= \n");
        scanf("%d",&(tab[indexLastGame].id));
        fflush(stdin);
        printf("type : \n");
        scanf("%s",&(tab[indexLastGame].type));
        fflush(stdin);
        printf("plage d'age : \n");
        scanf("%s",&(tab[indexLastGame].age));
        fflush(stdin);
        printf("prix : \n");
        scanf("%f",&(tab[indexLastGame].prix));
        fflush(stdin);
        printf("fournisseur : \n");
        scanf("%s",&(tab[indexLastGame].fournisseur));
        fflush(stdin);
        printf("stock : \n");
        scanf("%d",&(tab[indexLastGame].stock));
        fflush(stdin);
        nb_jouet++;
        printf("voulez-vous ajouter un autre jouet ? [O:oui//N:non]\n");
        scanf("%c",&response);
        fflush(stdin);




    }
    while (response!='n' && response!='N') ;
}
void ajout_f()
{
    char nomFournisseur,type,adresseMail,adresse ;
    char responseFournisseur;
    int idFournisseur,stock;
    do
    {
        printf("saisir les données :\n");
        printf("nom du fournisseur : \n");
        scanf("%S",&nomFournisseur);
        fflush(stdin);
        printf("id= \n");
        scanf("%d",&idFournisseur);
        fflush(stdin);
        printf("adresse mail : \n");
        scanf("%s",&adresseMail);
        fflush(stdin);
        printf("adresse : \n");
        scanf("%s",&adresse);
        fflush(stdin);

        printf("voulez-vous ajouter un autre fournisseur ? [O:oui//N:non]\n");
        scanf("%c",&responseFournisseur);
        fflush(stdin);
    }
    while (responseFournisseur!='n' && responseFournisseur!='N') ;
}
void recherche_client(struct Jouet tab[])
{
    char reponse_recherche,type_souhaite,prix_souhaite,jouet_souhaite;
    int reponse_recherche1,i,trouve;
    int TAILLE_MAX=100;
    do
    {
        printf("voulez-vous faire une recherche ?\t");
        scanf("%c",&reponse_recherche);
    }
    while (reponse_recherche!='n' || reponse_recherche!='N' || reponse_recherche!='o' || reponse_recherche!='O');
    if (reponse_recherche=='o' || reponse_recherche=='O')
    {
        do
        {
            printf("veuillez saisir un choix [1-3]");
            printf("1-effectuer une recherche selon le type");
            printf("2-effectuer une recherche selon le prix");
            printf("3-effectuer une recherche selon le nom du jouet");
            scanf("%d",&reponse_recherche1);
        }
        while(reponse_recherche1>4 || reponse_recherche1<1);
        switch(reponse_recherche1)
        {
        case 1:
        {
            printf("donner le type souhaité : ");
            scanf("%s",type_souhaite);
            trouve=1;
            i=0;
            do
            {
                if (tab[i].type==type_souhaite)
                    printf("jouet trouvé : \n",tab[i].type);
                else
                {
                    i++;
                    trouve=0;
                }
            }
            while(trouve==0|| i>=TAILLE_MAX);
        }
        break;
        case 2:
        {
            printf("donner le prix souhaité : ");
            scanf("%s",prix_souhaite);
            trouve=1;
            i=0;
            do
            {
                if (tab[i].prix==prix_souhaite)
                    printf("jouet trouvé : \n",tab[i].prix);
                else
                {
                    i++;
                    trouve=0;
                }
            }
            while(trouve==0|| i>=TAILLE_MAX);
        }
        break;
        case 3:
        {
            printf("donner le nom du jouet souhaité : ");
            scanf("%s",jouet_souhaite);
            trouve=1;
            i=0;
            do
            {
                if (tab[i].nom==jouet_souhaite)
                    printf("jouet trouvé : \n",tab[i].nom);
                else
                {
                    i++;
                    trouve=0;
                }
            }
            while(trouve==0|| i>=TAILLE_MAX);
        }
        break;
        }
    }
}
void facture(struct Jouet tab [])
{
    char id_jouet_vendu,ch=' ';
    int trouve,trouve1,i ;
    int TAILLE_MAX=100;

    printf("veuillez entrer l'id du jouet vendu \t");
    scanf("%s",id_jouet_vendu);
    trouve1=1;
    i=0;
    do
    {
        if (tab[i].id==id_jouet_vendu)
        {
            printf("=====FACTURE=====");
            printf("id jouet  : \n",tab[i].id);
            printf("type jouet: \n",tab[i].type);
            printf("nom du jouet : \n",tab[i].nom);
            printf("plage d'age du jouet : \n",tab[i].age);
            printf("prix du jouet : \n",tab[i].prix);
            printf("fournisseur du jouet : \n",tab[i].fournisseur);
        }
        else
        {
            i++;
            trouve1=0;
        }
    }
    while(trouve==0|| i>=TAILLE_MAX);
    ch=ch+tab[i].nom;

}
/*void Modification_admin(struct Jouet tab[])
{   int id_a_modifier;
    char s;

    printf("donner l'id du jouet a modifier : \n ");
    scanf("%d",id_a_modifier);
    printf("donner la modification a faire\n");
    scanf("%s",s);

}*/
void suppression_jouet( )
{
    int i,id_jouet_a_supprimer,nb_jouet;
    int TAILLE_MAX=100;
    printf("donner l'id du jouet à supprimer");
    scanf("%d",&id_jouet_a_supprimer);
    i=0;
    do
    {
        strcmp(id_jouet_a_supprimer,tab[i].id);
        i++;
    }
    while (strcmp(id_jouet_a_supprimer,tab[i].id)!=id_jouet_a_supprimer && i<TAILLE_MAX);

    if (strcmp(id_jouet_a_supprimer,tab[i].id)==id_jouet_a_supprimer)
    {
        tab[i].id=0;
        strcpy(tab[i].nom,'0');
        strcpy(tab[i].type,'0');
        strcpy(tab[i].age,'0');
        strcpy(tab[i].fournisseur,'0');
        tab[i].stock=0;
    }
    indexLastGame-- ;
}

void suppression_Fournisseur(struct Fournisseur tab1[],int TAILLE_MAX)
{
    int i,id_fournisseur_a_supprimer;
    //int TAILLE_MAX=100;

    printf("donner l'id du jouet à supprimer");
    scanf("%d",&id_fournisseur_a_supprimer);
    i=0;
    do
    {
        strcmp(id_fournisseur_a_supprimer,tab1[i].id);
        i++;
    }
    while (strcmp(id_fournisseur_a_supprimer,tab1[i].id)!=id_fournisseur_a_supprimer && i<=TAILLE_MAX);
    if (strcmp(id_fournisseur_a_supprimer,tab1[i].id)==id_fournisseur_a_supprimer)
    {
        tab1[i].id=0;
        strcpy(tab1[i].nom,'0');
        strcpy(tab1[i].addresse_mail,'0');
        strcpy(tab1[i].addresse,'0');
        tab1[i].num=0;
    }
}
void annulation_commande(struct Jouet tab[],int TAILLE_MAX)
{
    int i=0,id_jouet_annule,trouve4;

    printf("donner l'id du jouet è rendre");
    scanf("%d",&id_jouet_annule);
    while(i<TAILLE_MAX)
    {
        trouve4=1;
        do
        {
            if (tab[i].id==id_jouet_annule)
            {
                printf("jouet annulé : \n",tab[i].id);
                tab[i].stock++;
            }
            else
            {
                i++;
                trouve4=0;
            }
        }
        while(trouve4==0|| i>=TAILLE_MAX);
    }
}
void vendre_jouet(struct Jouet tab[])
{
    int id_jouet,i,trouve5 ;
    int TAILLE_MAX=100;
    printf("donner l'id du jouet vendue: \t");
    scanf("%i",&id_jouet);
    trouve5=0;
    i=0;
    while(i<TAILLE_MAX && trouve5==0)
    {
            if (tab[i].id==id_jouet)
            {
                tab[i].stock--;
                trouve5=1;
                printf(" found =   %i", i);
            }
            else
            {
                i++;
            }
    }
}

void travail_admin()
{
    //int choix,id,stock,i;
    //float prix;
    //char fournisseur,plage_d_age;
    int choice,i,choice1,choice2;
    char response ;
    int TAILLE_MAX=100;
    do
    {
        do
        {
            printf("Veuillez sectionner un choix :[1-3]\n");
            printf("1-traiter les informations des jouets\n");
            printf("2-traiter les informations des fournisseurs\n");
            printf("3-Quitter l'application\n");
            scanf("%d",&choice);
        }
        while(choice<1 || choice>3);

        switch(choice)
        {
        case 1:
            do
            {
                printf("Veuillez sectionner un choix :[1-6]\n");
                printf("1-visualizer la liste des jouets\n");
                printf("2-Ajouter des jouets\n");
                printf("3-Supprimer des jouets\n");
                printf("4-faire des modifications\n");
                printf("5-annuler une commande\n");
                printf("6-Quitter l'application\n");
                do
                {
                    printf("\t\tvotre choix :\t");
                    scanf("%d",&choice1);
                }
                while(choice1<1||choice1>6);

                switch(choice1)
                {
                case 1:
                {

                    printf("========visualisation de la structure=======\n");
                    Visualisation_Jouet(tab);
                }
                break;
                case 2:
                {
                    printf("=======Ajout=======\n");
                    ajout_jouet(tab);
                }
                break;
                case 3:
                {
                    printf("========Suppression=========\n");
                    suppression_jouet();
                }

                case 4:
                {
                    printf("========faire des modifications\n");
                    //modification_admin();
                }
                case 5:
                {
                    annulation_commande(tab,TAILLE_MAX);
                }
                break;
                default : //si choix =6
                    exit(0);//permet de fermer l'application
                }
                //system("cls");
            }
            while((choice1!=6) || ((response=='n') || (response=='N')));
            break;
        case 2:
            do
            {
                printf("Veuillez sectionner un choix :[1-5]\n");
                printf("1-visualizer la liste des fournisseurs\n");
                printf("2-Ajouter des fournisseurs\n");
                printf("3-Supprimer des fournisseurs\n");
                printf("4-modifier les données des fournisseurs\n");
                printf("5-Quitter l'application\n");

                do
                {
                    printf("\t\tvotre choix :\t");
                    scanf("%d",&choice2);
                }
                while(choice2<1||choice2>5);
                switch(choice2)
                {
                case 1:
                    printf("========visualisation de la structure=======\n");
                    Visualisation_Fournisseur();
                    break;
                case 2:
                    printf("=======Ajout=======\n");
                    ajout_f();
                    break;
                case 3:
                    printf("========Suppression=========\n");
                    suppression_Fournisseur(tab1,TAILLE_MAX);
                    break;
                /*case 4 :
                     printf("=======modification Fournisseur=======\n");
                     modification_frournisseur();*/
                default : //si choix =5
                    exit(0);//permet de fermer l'application
                }
                //system("cls");
            }
            while(choice2!=5);

            break;
        default : //si choix =4
            exit(0);//permet de fermer l'application
        }
        // system("cls");

    }
    while(choice!=3);

}
int main()
{
    int choix,TAILLE_MAX ;
    struct Jouet tab [100]= {{1234,'ballon','sport','5-15',10,'gosport',50},{4562,'poupee','fille','5-10',8,'barbieshop',45}};
    struct Fournisseur tab1[100] = {{4325,'gosport','sport@gmail.com','ariana',99784632},{7365,'barbieshop','barbie@hotmail.com','tunis',73546900}};


    do
    {
        printf("Veuillez sectionner un choix :[1-4]\n");
        printf("1-je suis admin\n");
        printf("2-je suis un caissier\n");
        printf("3-je suis un client\n");
        printf("4-Quitter l'application\n");
        do
        {
            printf("\t\t votre choix :\t");
            scanf("%d",&choix);
        }
        while(choix<1||choix>4);
        switch(choix)
        {
        case 1:
        {
            login_admin();
            travail_admin();
        }
        break;

        case 2:
        {
            login_caissier();
            travail_caissier(tab);
        }
        break;

        case 3:
        {
            login_client();
            recherche_client(tab);
        }
        break;
        default : //si choix =4
            exit(0);//permet de fermer l'application
        }
        //system("cls");
    }
    while(choix!=4);

    return 0;
}

