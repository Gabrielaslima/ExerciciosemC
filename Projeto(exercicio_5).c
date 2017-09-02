#include <stdio.h>       

//Declaracao do tipo struct (Global)
struct RgData {
  int dia;
  int mes;
  int ano;
};
struct RgAluno {
  char nome[35];
  float nota [4];
  struct RgData data;
  float media;
};
struct RgAluno *Aluno[5];

void armazena(struct RgAluno *pAluno){
	int x, y, n;
    float soma=0;
    //n = 2;
    
    for (y = 0; y < 2; y++) {
        //Leitura dos campos
        printf("Nome da aluno: ");
        scanf("%s", &(pAluno+y)->nome);
        printf("Data Nascimento (digite dia mes ano): ");
        scanf("%d", &(pAluno+y)->data.dia);
        scanf("%d", &(pAluno+y)->data.mes);
        scanf("%d", &(pAluno+y)->data.ano);              
        soma = 0; // zera somatorio para cada aluno
        printf("Digite as notas...\n");
        for (x = 0; x < 4; x++) {
            printf("Nota[%d]: ", x+1); 
            scanf("%f", &(pAluno+y)->nota[x]);
            soma = soma + (pAluno+y)->nota[x]; //acumula notas
        }
        //calcula media e armazena
        (pAluno+y)->media = (soma / 4);    
    }    
}

void imprime(struct RgAluno *pAluno){
	int y,x;
	for (y = 0; y < 2; y++) {        
        //impressao dos dados do aluno...
        printf("\nNome da aluno: %s", (pAluno+y)->nome);
        printf("\nData de Nasc.: %d/%d/%d", (pAluno+y)->data.dia, (pAluno+y)->data.mes, (pAluno+y)->data.ano);
        for (x = 0; x < 4; x++) {
            printf("\nNota[%d]: %.2f ", x+1, (pAluno+y)->nota[x]);
        }    
        printf("\nMedia do aluno: %.2f\n", (pAluno+y)->media);
    }
}

main () {
	
	struct RgAluno *Aluno[2];
	armazena(&Aluno);
    imprime(&Aluno);
    
        
    
    system("PAUSE");
}
