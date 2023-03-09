#include <stdio.h>
#include <string.h>

#define ASIZE 256

void preBrBc(char *x, int m, int brBc[ASIZE][ASIZE]){
    int a, b, i;

    for(a = 0; a < ASIZE; ++a)
        for(b = 0; b < ASIZE; ++b)
           brBc[a][b]= m + 2;

    for(a = 0; a < ASIZE; ++a)
        brBc[a][x[0]]= m + 1;

    for(i = 0; i < m - 1; ++i)
        brBc[x[i]][x[i+1]]= m + i;

    for(a = 0; a < ASIZE; ++a)
        brBc[x[m - 1]][a] = 1;
}
void BR(char *x, int m, char *y, int n, char z[]){
    int j, brBc[ASIZE][ASIZE];
    char String[] = "J";
    char String2[] = "i";

    preBrBc(x, m, brBc);

    y[n + 1] = '\0';
    j = 0;

    while ( j <= n - m){
        //Comparando a string x com uma sub-string de y e
        //fazendo a troca dos valores caso haja a compatibilidade
        if (memcmp(x, y + j, m) == 0){
            z[j-1]=String[0];
            z[j+m]=String2[0];
        }
        //Atualizando o indice j usando os valores da matriz brBc
        j += brBc[y[j + m]][y[j + m + 1]];
    }
    printf("%s", z);
    printf("\n");
}
int main(){
    char x[] = "oulupukk";
    int qtd;
    scanf("%d\n", &qtd);
    for (int i = 0; i<qtd; i++){
        char y[100];
        scanf("%[^\n]%*c", y);
        int m = strlen(x);
        int n = strlen(y);
        BR(x, m, y, n, y);
    }
    return 0;
}



