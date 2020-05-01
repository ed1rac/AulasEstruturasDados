#include <stdio.h>
#include <stdlib.h>
/*  Função : Jogo da velha - Viviane Mizrahi
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:                                    */
#define PULA printf("\n")

main(){
    const char pt='.';
    unsigned char m[3][3]=
    {{pt, pt, pt}, {pt, pt, pt}, {pt, pt, pt}};
    int lin, col, j=0;

    const int TRUE = 1;
    const char O = 'o', X = 'x';

    printf("Digite as coordenadas na forma lin, col: \n");
    while(TRUE){
        for(lin=0;lin<3;lin++)
        {
            for(col=0;col<3;col++)
                printf("%c ", m[lin][col]);
                PULA;
        }
        //verifica se o primeiro jogador ganhou
        if((m[0][0]==O && m[0][1]==O && m[0][2]==O)||
           (m[1][0]==O && m[1][1]==O && m[1][2]==O)||
           (m[2][0]==O && m[2][1]==O && m[2][2]==O)||
           (m[0][0]==O && m[1][0]==O && m[2][0]==O)||
           (m[0][1]==O && m[1][1]==O && m[2][1]==O)||
           (m[0][2]==O && m[1][2]==O && m[2][2]==O)||
           (m[0][0]==O && m[1][1]==O && m[2][2]==O)||
           (m[0][2]==O && m[1][1]==O && m[2][0]==O))
           {
               printf("\aVocê ganhou, primeiro jogador!!!\n");
               break;
           }
           //verifica se o segundo jogador ganhou
        if((m[0][0]==X && m[0][1]==X && m[0][2]==X)||
           (m[1][0]==X && m[1][1]==X && m[1][2]==X)||
           (m[2][0]==X && m[2][1]==X && m[2][2]==X)||
           (m[0][0]==X && m[1][0]==X && m[2][0]==X)||
           (m[0][1]==X && m[1][1]==X && m[2][1]==X)||
           (m[0][2]==X && m[1][2]==X && m[2][2]==X)||
           (m[0][0]==X && m[1][1]==X && m[2][2]==X)||
           (m[0][2]==X && m[1][1]==X && m[2][0]==X))
           {
               printf("\aVoce ganhou, segundo jogador!!!\n");
               break;
           }
           if (j==9){
               printf("\aEmpatou\n");
               break;
           }
           printf("Coordenadas: ");
           scanf("%d, %d", &lin, &col);

           if(m[lin][col]== '.') //casa livre?
           {
               if(j%2) m[lin][col]=X;
               else m[lin][col]=O;
               j++;
           }
    }
    PULA;
    getchar();
}
