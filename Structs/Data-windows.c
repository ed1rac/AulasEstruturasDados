#include <stdio.h>
#include <stdlib.h>   //comentado por causa do compilador do MacBook
#include <string.h>
//#define INT_DECIMAL_STRING_SIZE(int_type) ((CHAR_BIT*sizeof(int_type)-1)*10/33+3)

struct data{
    int dia, mes, ano;  //estrutura data
};
typedef struct data Data; //sinonimo
//prototipos
int verifica_data(Data);
Data get_data();
void imprime_data(Data d);
void adiciona_um_dia(Data *d);
Data adiciona_um_dia_novo(Data d);
Data adiciona_dias(Data d, int x);
Data adiciona_um_dia_novo(Data d);

int main(){
    Data aniversario={7,7,1980}, outra_data;
    outra_data = get_data();
 /*   if (verifica_data(aniversario)) {
        imprime_data(aniversario); printf("\n");
        adiciona_um_dia(&aniversario); printf("Aniv. Com um dia a mais: ");
        imprime_data(aniversario);    printf("\n");
    } else {
        printf("A data abaixo é invalida: ");
        imprime_data(aniversario); printf("\n");
    }*/
    if (verifica_data(outra_data)) {
        imprime_data(outra_data); printf("\n");
       // adiciona_um_dia(&outra_data); printf("Com um dia a mais: ");
        //imprime_data(outra_data); printf("\n");
    } else {
        printf("A data fornecida e` invalida\n");
    }
    printf("\n");
   // int dia = outra_data.dia;
   // printf("%s\n", data_to_string(aniversario));
   outra_data =  adiciona_dias(outra_data, 10);
   printf("\nOutra data com 10 dias a mais: ");
   imprime_data(outra_data);printf("\n" );
    system("pause"); //codigo feito no MacBook Pro => funciona no Linux.
    return 0;
}

void adiciona_um_dia(Data *d){
    switch (d->mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        {
            if ((d->dia >= 1) && (d->dia <= 30)){
                d->dia = d->dia + 1;;
            }
            if((d->dia == 31)&&(d->mes!=12)){
                d->mes = d->mes +1;
                d->dia=1;
            }
            if((d->dia==31)&&(d->mes==12)){
                d->ano = d->ano +1;
                d->dia=1;
                d->mes=1;
            }
            break;            
        }
        case 4: case 6: case 9: case 11: case 2:
        {
            if((d->dia >= 1)&&(d->dia<28)&&((d->ano % 4) != 0)){
                d->dia++;
            }
    
            if((d->dia == 29 && d->mes == 2) && ((d->ano % 4) == 0)){
                d->mes++;d->dia=1;
            }
            if((d->dia==28)&&(d->mes==2)&&((d->ano % 4) != 0)){
                d->dia=01;d->mes++;
            }
            break;
        }
            
        
    } 
}

Data adiciona_dias(Data d, int x){
    int i;
    for (i = 1;i<=x ;i++ ) {
        d = adiciona_um_dia_novo(d);       
    }
    return d;
}

Data adiciona_um_dia_novo(Data d){
    switch (d.mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        {
            if ((d.dia >= 1) && (d.dia <= 30)){
                d.dia = d.dia + 1;;
            }
            if((d.dia == 31)&&(d.mes!=12)){
                d.mes = d.mes +1;
                d.dia=1;
            }
            if((d.dia==31)&&(d.mes==12)){
                d.ano = d.ano +1;
                d.dia=1;
                d.mes=1;
            }
            if((d.dia==31)&&(d.mes!=12)){
                //d.ano = d.ano +1;
                d.dia=1;
                d.mes=d.mes+1;
            }
            return d;
            break;            
        }
        case 4: case 6: case 9: case 11: case 2:
        {
            if((d.dia >= 1)&&(d.dia<28)&&((d.ano % 4) != 0)){
                d.dia++;
            }
    
            if((d.dia == 29 && d.mes == 2) && ((d.ano % 4) == 0)){
                d.mes++;d.dia=1;
            }
            if((d.dia==28)&&(d.mes==2)&&((d.ano % 4) != 0)){
                d.dia=01;d.mes++;
            }
            return d;
            break;
        }
            
        
    } 
}


void imprime_data(Data d){
    printf("%0d/%0d/%d", d.dia, d.mes, d.ano);
}

Data get_data(){
    Data data;
    printf("Digite uma data no formato 'dd/mm/aaaa'\n");
    scanf("%d/%d/%d", &data.dia,&data.mes,&data.ano);
    return data;
}

int verifica_data(Data d){
    if ((d.dia >= 1 && d.dia <= 31) && (d.mes >= 1 && d.mes <= 12) && (d.ano >= 1900 && d.ano <= 2100)){
            if ((d.dia == 29 && d.mes == 2) && ((d.ano % 4) == 0) && ((d.ano % 100)!=0) || ((d.ano % 400) ==0)){ //verifica se o d.ano e bissexto
                return 1;
            }
            if (d.dia <= 28 && d.mes == 2){ //verifica o d.mes de feveireiro
                return 1;
            }
            if ((d.dia <= 30) && (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11)){ //verifica os d.meses de 30 d.dias
                return 1;
            }
            if ((d.dia <=31) && (d.mes == 1 || d.mes == 3 || d.mes == 5 || d.mes == 7 || d.mes ==8 || d.mes == 10 || d.mes == 12)){ //verifica os d.meses de 31 d.dias
                return 1;
            }
            else{
                return 0;
            }
      }
       else{
           return 0;
        }
}