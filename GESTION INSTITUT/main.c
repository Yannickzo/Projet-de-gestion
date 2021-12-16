#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int JJ,AAA;
    char MM;
};

struct Etudiant
{
    char Nom[100];
    char Prenom[60];
    char Religion[60];
    char Lieu_naiss[100];
    char Filiere[50];
    char Nationalite[40];
    int Niveau,Num;
    struct Date Datnaiss;
    struct Date Datinscrip;
};

/*fonction de recherche d'un etudiant*/
    struct Etudiant Etud;
    int rech(int Numrech)
    {
        FILE *F;
        F=fopen("Etudiants.txt","r");
        do
        {
            fscanf(F,"%d;%s;%s;%s;%s;%s;%s,%d",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Religion,&Etud.Lieu_naiss,&Etud.Nationalite,&Etud.Filiere,&Etud.Niveau);
            fflush(stdin);
            if(Etud.Num == Numrech)
            {
                fclose(F);
                return 1;
            }

        }
         while(!feof(F));
         fclose(F);
         return -1;
    }
 /*fonction d'ajout d'un etudiant*/
    void AjouterEtudiant()
    {
        FILE *F;
        int num;
        F=fopen("Etudiants.txt","a");
        printf("\n Entrez le numero du nouveau etudiant : ");
        scanf("%d",&num);
        fflush(stdin);
        while(rech(num)== 1)
        {
            printf("\n ce numero existe deja ");
            printf("\n entrez le numero d'etudiant");
            scanf("%d",&num);
        }
        Etud.Num=num;
        printf("\n entrez le nom : ");
        gets(Etud.Nom);
        fflush(stdin);
        printf("\n entrez le prenom : ");
        gets(Etud.Prenom);
        fflush(stdin);
        printf("\n entrez la religion : ");
        gets(Etud.Religion);
        fflush(stdin);
        printf("\n entrez le lieu de naissance : ");
        gets(Etud.Lieu_naiss);
        fflush(stdin);
        printf("\n entrez la nationalite : ");
        gets(Etud.Nationalite);
        fflush(stdin);
        printf("\n entrez le jour de naissance : ");
        gets(Etud.Datnaiss.JJ);
        fflush(stdin);
        printf("\n entrez le mois de naissance : ");
        gets(Etud.Datnaiss.MM);
        fflush(stdin);
        printf("\n entrez l annee de naissance : ");
        gets(Etud.Datnaiss.AAA);
        fflush(stdin);
        printf("\n entrez le jour d inscription: ");
        gets(Etud.Datinscrip.JJ);
        fflush(stdin);
        printf("\n entrez le mois d'incription : ");
        gets(Etud.Datinscrip.MM);
        fflush(stdin);
        printf("\n entrez l annee d'inscription : ");
        gets(Etud.Datinscrip.AAA);
        fflush(stdin);
        printf("\n entrez la filiere : ");
        gets(Etud.Filiere);
        fflush(stdin);
        printf("\n entrez le niveau : ");
        gets(Etud.Niveau);
        fflush(stdin);
        fprintf(F,"%d;%s;%s;%s;%s;%s;%s;%d\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Religion,Etud.Lieu_naiss,Etud.Nationalite,Etud.Filiere,Etud.Niveau);
        close(F);

    }
/*recherche et affichage*/
void Recherche ()
{
    int NumR;
    printf("entrez le numero de l'etudiant a rechercher :\n");
    scanf("%d",&NumR);
    FILE *F;
    F= fopen("Etudiants.txt","r");
    do
    {
        fscanf(F,"%d;%s;%s;%s;%s;%s;%s;%d\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Religion,&Etud.Lieu_naiss,&Etud.Nationalite,&Etud.Filiere,&Etud.Niveau);
        if(NumR == Etud.Num)
        {
            printf("--------Information sur l'etudiant------------\n\n");
            printf("Numero\t: %d\n",Etud.Num);
            printf("Nom\t: %s\n",Etud.Nom);
            printf("Prenom\t: %s\n",Etud.Prenom);
            printf("Religion\t: %s\n",Etud.Religion);
            printf("Religion\t: %s\n",Etud.Lieu_naiss);
            printf("Nationalite\t: %s\n",Etud.Nationalite);
            printf("Filiere\t: %s\n",Etud.Filiere);
            printf("Niveau\t: %s\n",Etud.Niveau);

        }

    }
    while(!feof(F));
    fclose(F);
/*procedure de suppression*/
void SupprimerEtudiant()
{
    char rep;
    int NumRech;
    printf("entrez le numero de l etudiant a supprimer : ");
    scanf("%d",&NumRech);
    fflush(stdin);
    if (rech(NumRech ==1))
    {
        printf("\n voulez vous vraiment supprimer o/n ?");
        scanf("%c",&rep);
        fflush(stdin);
        if(rep=='o' || rep=='O')
        {
            FILE *Fich, *F;
            F=fopen("Etudiants.txt","r");
            Fich=fopen("TempEtudiant.txt","a");
            do
            {
                fscanf(F,"%d;%s;%s;%s;%s;%s;%s;%d\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Religion,&Etud.Lieu_naiss,&Etud.Nationalite,&Etud.Filiere,&Etud.Niveau);
                if(NumRech !=Etud.Num)
                {
                    fprintf(Fich,"%d;%s;%s;%s;%s;%s;%s;%d\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Religion,Etud.Lieu_naiss,Etud.Nationalite,Etud.Filiere,Etud.Niveau);
                }
            }
            while(!feof(F));
            fclose(Fich);
            fclose(F);
            remove("Etudiants.txt");
            rename("TempEtudiant.txt","Etudiants.txt");
            printf("suppression effectuee avec succes");

        }
    }
    else
    {
        printf("\n ce numero d'etudiant n'existe pas");
    }
}
/*procedure modifier etudiant*/
void ModifierEtudiant()
{
      FILE *F,*Fich;
      int num;
      char rep='n';
      printf("\n entrez le numero de l etudiant a modifier :");
      scanf("%d",&num);
      fflush(stdin);
      if (rech(num)==1)
      {
          printf("\n voulez vous vraiment modifier o/n ?");
          scanf("%c",&rep);
          fflush(stdin);
          printf("%c",rep);
          if(rep== 'o' || rep=='O')
          {
              F=fopen("Etudiant.txt","r");
              Fich=fopen("TempEtudiants.txt","a");
              do
              {
                  fscanf(F,"");
                  if(num==Etud.Num)
                  {
        Etud.Num=num;
        printf("\n entrez le nom : ");
        gets(Etud.Nom);
        fflush(stdin);
        printf("\n entrez le prenom : ");
        gets(Etud.Prenom);
        fflush(stdin);
        printf("\n entrez la religion : ");
        gets(Etud.Religion);
        fflush(stdin);
        printf("\n entrez le lieu de naissance : ");
        gets(Etud.Lieu_naiss);
        fflush(stdin);
        printf("\n entrez le jour de naissance : ");
        gets(Etud.Datnaiss.JJ);
        fflush(stdin);
        printf("\n entrez le mois de naissance : ");
        gets(Etud.Datnaiss.MM);
        fflush(stdin);
        printf("\n entrez l annee de naissance : ");
        gets(Etud.Datnaiss.AAA);
        fflush(stdin);
        printf("\n entrez le jour d inscription: ");
        gets(Etud.Datinscrip.JJ);
        fflush(stdin);
        printf("\n entrez le mois d'incription : ");
        gets(Etud.Datinscrip.MM);
        fflush(stdin);
        printf("\n entrez l annee d'inscription : ");
        gets(Etud.Datinscrip.AAA);
        fflush(stdin);
        printf("\n entrez la filiere : ");
        gets(Etud.Filiere);
        fflush(stdin);
        printf("\n entrez le niveau : ");
        gets(Etud.Niveau);
        printf("\n la modification a reussi ");
          }
          fprintf(Fich,"%d;%s;%s;%s;%s;%s;%s;%d\n",Etud.Num,Etud.Nom,Etud.Prenom,Etud.Religion,Etud.Lieu_naiss,Etud.Nationalite,Etud.Filiere,Etud.Niveau);
      }
      while(!feof(F));
      fclose(F);
      fclose(Fich);
      remove("Etudiants.txt");
      rename("TempEtudiant.txt","Etudiants.txt");
      printf("\n  la modification a reussi succes");

}
else
{
    printf("\n la modification a ete annule \n");
}
      }
else
{
    printf("\n ce numero n'existe pas \n");
}
}
/*procedure affichage*/
void AfficherTout()
{
    FILE *F;
    F=fopen("Etudiants.txt","r");
    printf("la liste des etudiants est: \n\n");
    printf("Numero\t Nom\t Prenom \t Religion \t Lieu de naissance \t Nationnalite \t Filiere \t niveau \n");
    do
        {
            fscanf(F,"%d;%s;%s;%s\n",&Etud.Num,&Etud.Nom,&Etud.Prenom,&Etud.Religion);
            fflush(stdin);
            printf("%d\t",Etud.Num);
            printf("%s\t",Etud.Nom);
            printf("%s\t",Etud.Prenom);
            printf("%s\t",Etud.Religion);
            printf("%s\t",Etud.Lieu_naiss);
            printf("%s\t",Etud.Nationalite);
            printf("%s\t",Etud.Filiere);
            printf("%d\n",Etud.Niveau);
        }
        while(!feof(F));
        fclose(F);
}
/*menu principale*/
void main()
{

   int choix ; char rep ;
   do
   {
       system("cls");
       printf("------------------------menu---------------------------\n");
       printf("1-ajouter un etudiant\n");
       printf("2-rechercher un etudiant\n");
       printf("3-supprimer un etudiant\n");
       printf("4-modifier un etudiant\n");
       printf("5-afficher tous les  etudiant\n");
       printf("6-quitter\n\n");
       do
       {
           printf("\n entrez votre choix : ");
           scanf("%d",&choix);
       }
       while(choix<1 || choix>6);
       switch(choix)
       {
           case 1:AjouterEtudiant();
           break;
           case 2:Recherche();
           break;
           case 3:SupprimerEtudiant();
           break;
           case 4:ModifierEtudiant();
           break;
           case 5:AfficherTout();
           break;
           case 6: break;
       }
        printf("\n voulez vous vous continuer O/N ?");
        scanf("%c",&rep);
        fflush(stdin);
   }
    while(rep=='o' || rep=='O');

}
}




