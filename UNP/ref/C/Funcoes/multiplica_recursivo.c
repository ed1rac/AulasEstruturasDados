#include <stdio.h>

int multiplica(int num1, int num2);

int main(){
    int i,j;
    for (i = 2;i<=12;i++){
        printf("Tabuada de %d\n=====================\n", i);
        for (j = 1;j<=12;j++){
            printf("%d x %d = %d\n", i,j, multiplica(i,j));
        }
        printf("=====================\n");
    }
    return 0;
}

int multiplica(int num1, int num2){
    if (num1 == 0 || num2 == 0) {        
        return 0;
    }
    //caso base, onde a recursão para:
    else if (num2 == 1) {        
        return num1;
    }
    //multiplicando através da soma com recursividade:
    else {        
        return (num1 + multiplica(num1,num2 - 1));        
    }
}