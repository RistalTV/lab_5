#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "output.h"
#define MAX_ELLEMENT 200


int cE(void);
void topaddlist(void);
void printCat(void);
void loadinfile(int countStr,char cat[1],char name[30],char cost_higt[4],char cost_loW[4]);

struct mak{
        char cat[1];
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
};

int addeleminlist(void){
    int elemCount=cE (),i=1;
    char kat,kat1;
    char cat[1];
    char name[30];
    char cost_higt[4];
    char cost_loW[4];
    do{
        topaddlist();
        printf("==                   �� ����� ������ �ᥣ� %-4d ����⮢                    ==\n",elemCount);
        printf("================================================================================\n");
        printf("1)  == ������ ��� ��⥣�ਨ(������ '!', �⮡� 㢨���� ���� ��⥣�਩):");
        scanf ("%s",&kat);
        if (kat == '!')
         {
          printCat ();
          printf("1)  == ������ ��� ��⥣�ਨ(������ '!', �⮡� 㢨���� ���� ��⥣�਩):");
          scanf ("%s",&kat);
         }
        else
         {
          cat[0]=kat;
         }
        system ("cls");
        topaddlist();
        printf("1)  == ������ ��� ��⥣�ਨ:  %c\n",cat[0]);
        printf("2)  == ������ �������� �����: ");scanf ("%30s",name);
        system ("cls");
        topaddlist();
        printf("1)  == ������ ��� ��⥣�ਨ:  %c\n",cat[0]);
        printf("2)  == ������ �������� �����: %-30s\n",name);
        printf("3)  == ������ ������� 業� �����: ");scanf ("%4s",cost_loW);
        system ("cls");
        topaddlist();
        printf("1)  == ������ ��� ��⥣�ਨ:  %c\n",cat[0]);
        printf("2)  == ������ �������� �����: %-30s\n",name);
        printf("3)  == ������ ������� 業� �����: %-4s ��.\n",cost_loW);
        printf("4)  == ������ ������� 業� �����(�᫨ ����,�᫨ ���� � ������ '0' ��� 'n')\n");
        printf("4)  == ������ ������� 業� �����: ");scanf ("%4s",cost_higt);
        if ((cost_higt[0] == 'n')||(cost_higt[0] == 'N')){cost_higt[0]='0';}
        system ("cls");
        topaddlist();
        printf("1)  == ������ ��� ��⥣�ਨ:  %c\n",cat[0]);
        printf("2)  == ������ �������� �����: %-30s\n",name);
        printf("3)  == ������ ������� 業� �����: %-4s ��.\n",cost_loW);
        printf("4)  == ������ ������� 業� �����: %-4s ��.\n",cost_higt);
        printf("================================================================================\n");
        printf("==      �������� ����� � ᯨ᮪((�� ������) - ��, (0 ��� n) - ���)?     ==\n");
        printf("================================================================================\n");
        printf("                 ������ ������� ��� �த�������: ");scanf ("%1s",&kat);
        printf("================================================================================\n");
        if ((kat=='0')&&(kat=='n')&&(kat=='N'))
         {
            printf("================================================================================\n");
            printf("==   �த������ ���������� ����⮢((�� ������) - ��, (0 ��� n) - ���)?  ==\n");
            printf("================================================================================\n");
            printf("                 ������ ������� ��� �த�������: ");scanf ("%1s",&kat1);
            printf("================================================================================\n");
            if (( kat1 != '0' )||( kat1 != 'n' )||( kat1 != 'N')){ i  =  1; }
            if (( kat1 == '0' )||( kat1 == 'n' )||( kat1 == 'N')){ i  =  0;return 1; }
         }
        if ((kat!='0')&&(kat!='n')&&(kat!='N'))
         {
            elemCount=cE ();
            loadinfile(elemCount,cat,name,cost_higt,cost_loW);
            printf("================================================================================\n");
            printf("==   �த������ ���������� ����⮢((�� ������) - ��, (0 ��� n) - ���)?  ==\n");
            printf("================================================================================\n");
            printf("                 ������ ������� ��� �த�������: ");scanf ("%1s",&kat1);
            printf("================================================================================\n");
            if (( kat1 != '0' )||( kat1 != 'n' )||( kat1 != 'N')){ i  =  1; }
            if (( kat1 == '0' )||( kat1 == 'n' )||( kat1 == 'N')){ i  =  0;return 1; }
         }
        elemCount=cE ();
      }while (i!=0);
    return 1;
}

int cE(void){
    char * filename = "C:/projects/lab_5/mak.txt";
    char k='"';
    int  elemCount=0;
    FILE* f = fopen(filename, "r+");
    while(k != EOF)                                 //���뢠�� ������⢮ ��ப
    {                                               //
        k = (char)fgetc(f);                         //��� ᨬ��� ��� seechar ����祭�� �� 䠩��
        if (k == '\n'){elemCount++;}                //�饬 '|' � �ਡ���塞 � ��६����� 1
    }
   fclose(f);
    return elemCount;
}

void loadinfile(int countStr,char cat[1],char name[30],char cost_higt[4],char cost_loW[4])
{
    int end=0;
    char * filename = "C:/projects/lab_5/mak.txt";
    struct mak names[MAX_ELLEMENT];
    int i=0,i1=0,i2=0;
    char k='0';
    int elemCountStr=0,countElem=0;
    char cat1[1],name1[30],cost_higt1[4],cost_loW1[4];
//===================================================================
//===       ���࠭�� ���� ��室��襣��� � �����                ===
//===================================================================
    for(i=0;i!=MAX_ELLEMENT;i++){                                    //==
        for(i2 = 0; i2 <  1; i2++){names[i].cat[i2]       = '\0';}//==
        for(i2 = 0; i2 < 30; i2++){names[i].name[i2]      = '\0';}//==
        for(i2 = 0; i2 <  4; i2++){names[i].cost_loW[i2]  = '\0';}//==
        for(i2 = 0; i2 <  4; i2++){names[i].cost_higt[i2] = '\0';}//==
    }                                                            //==
//===================================================================
    i=0;i2=0;
//=============================================================================
//===     ����ᥭ�� �������� ���祭�� � ��᫥���� ������� ��������       ===
//=============================================================================
                            names[countStr].cat[0]       = cat[0];         //==
    for(i = 0; i < 30; i++){names[countStr].name[i]      = name[i];      } //==
    for(i = 0; i <  4; i++){names[countStr].cost_loW[i]  = cost_loW[i];  } //==
    for(i = 0; i <  4; i++){names[countStr].cost_higt[i] = cost_higt[i]; } //==
//=============================================================================

//=============================================================================
//===     ���뢠��� �� 䠩�� ���祭�� � �������� ��������               ===
//=============================================================================
    FILE* fil = fopen(filename, "a+");
    i=0;
    while (k != EOF)
     {
      fscanf(fil,"%c",&k);
        if(k=='"'){break;}
                if (k != '|')
         {
            if (k != '\n')
             {
              switch (elemCountStr)
               {
                case (0) : names[countElem].cat[i]       =  k;i++;if(i>=1) {i=0;} break;
                case (1) : names[countElem].name[i]      =  k;i++;if(i>=30){i=0;} break;
                case (2) : names[countElem].cost_loW[i]  =  k;i++;if(i>=4) {i=0;} break;
                case (3) : names[countElem].cost_higt[i] =  k;i++;if(i>=4) {i=0;} break;
               }
             }else{end++;}
         }
        if(k=='|')
           {
            i=0;
            elemCountStr++;
            if (elemCountStr>3)
             {
              elemCountStr=0;
              countElem++;
             }
           }
        if (end>countElem){break;}
     }
   fclose(fil);                                                            //==
//=============================================================================
   /*
   FILE* f = fopen(filename, "w");
   for(i1=0;i1<countStr;i1++)
    {
       cat[0]=names[i1].cat[0];                                         //����㦠��
       for(i = 0; i < 30; i++){name[i]      = names[i1].name[i];}       //�� ������஢ �������
       for(i = 0; i <  4; i++){cost_loW[i]  = names[i1].cost_loW[i];}   //� ���ᨢ�
       for(i = 0; i <  4; i++){cost_higt[i] = names[i1].cost_higt[i];}  //
       for(i2=0;i2<countStr;i2++)
         {
           fprintf (f,"%-1s",cat);
           fprintf (f,"|");
           fprintf (f,"%-30s",name);
           fprintf (f,"|");
           fprintf (f,"%-4s",cost_loW);
           fprintf (f,"|");
           fprintf (f,"%-4s",cost_higt);
           fprintf (f,"\n");
         }
       fprintf (f,"/");
    }
   fclose(f);*/

//=============================================================================
//===     ����ᥭ�� ������஢ �������� � 䠩�                            ===
//=============================================================================
   countStr++;
   FILE* file = fopen (filename,"wb");
   i=0;end=0;i1=0;i2=0;
    while(i!=countStr){
        fprintf (file,"|");
        cat1[0]=names[i].cat[0];
        fprintf (file,"%-1s",cat1);
        fprintf (file,"|");
        for (i1=0;i1<30;i1++){name1[i1]          = names[i].name[i1];}
        fprintf (file,"%-30s",name1);
        fprintf (file,"|");
        for (i1=0;i1<30;i1++){cost_loW1[i1]      = names[i].cost_loW[i1];}
        fprintf (file,"%-4s",cost_loW1);
        fprintf (file,"|");
        for (i1=0;i1<30;i1++){cost_higt1[i1]     = names[i].cost_higt[i1];}
        fprintf (file,"%-4s",cost_higt1);
        fprintf (file,"|\n");
             i++;
        }
    fclose (file);
}
