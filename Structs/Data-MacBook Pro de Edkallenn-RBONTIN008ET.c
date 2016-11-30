#include<stdio.h>
#include<stdlib.h>   //comentado por causa do compilador do MacBook
#include<string.h>
//#define INT_DECIMAL_STRING_SIZE(int_type) ((CHAR_BIT*sizeof(int_type)-1)*10/33+3)

struct data{
    int dia, mes, ano;  //estrutura data
};
typedef struct data Data; //sinonimo

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
            if ((d.dia == 29 && d.mes == 2) && ((d.ano % 4) == 0)){ //verifica se o d.ano e bissexto
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
/*
char* data_to_string(Data d){
    char* dt1, dt2, dt3, barra, temp1, temp2, temp3, temp4;
    int d1,m1,a1;
    barra = "/";
    d1 = d.dia;
    m1 = d.mes;
    a1 = d.ano;
    dt1 = int_to_string(d1);
    dt2 = int_to_string(m1);
    dt3 = int_to_string(a1);
    temp1 = strcat(dt1,barra);
    temp2 = strcat(temp1,dt2);
    temp3 = strcat(temp2,barra);
    temp4 = strcat(temp3,dt3);
    return temp4;
}
*/

//prototipos
int verifica_data(Data);
Data get_data();
void imprime_data();
//char* int_to_string(int x);
void adiciona_um_dia(Data *d);

int main(){
    Data aniversario={7,7,1980}, outra_data;
    outra_data = get_data();
    if (verifica_data(aniversario)) {
        imprime_data(aniversario); printf("\n");
        adiciona_um_dia(&aniversario); printf("Aniv. Com um dia a mais: ");
        imprime_data(aniversario);    printf("\n");
    } else {
        printf("A data abaixo é invalida: ");
        imprime_data(aniversario); printf("\n");
    }
    if (verifica_data(outra_data)) {
        imprime_data(outra_data); printf("\n");
        adiciona_um_dia(&outra_data); printf("Com um dia a mais: ");
        imprime_data(outra_data); printf("\n");
    } else {
        printf("A data fornecida e` invalida\n");
    }
    printf("\n");
    int dia = outra_data.dia;
   // printf("%s\n", data_to_string(aniversario));
    //system("read"); //codigo feito no MacBook Pro => funciona no Linux.
    system("pause");
    return 0;
}

/*
char* int_to_string(int x) {
  int i = x;
  char buf[80];
  char *p = &buf[sizeof buf - 1];
  *p = '\0';
  if (i >= 0) {
    i = -i;
  }
  do {
    p--;
    *p = (char) ('0' - i % 10);
    i /= 10;
  } while (i);
  if (x < 0) {
    p--;
    *p = '-';
  }
  size_t len = (size_t) (&buf[sizeof buf] - p);
  char *s = (char *)malloc(len);
  if (s) {
    memcpy(s, p, len);
  }
  return s;
}
*/
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
