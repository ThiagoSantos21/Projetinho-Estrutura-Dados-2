// Thiago Lima Santos 21012009
// Wirrley Ferreira Santos 21008641
// Joao Vitor de Faria e Souza 20017026
// Thiago Travaglia 21001152
// Guilherme Coutinho 21010202

#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

typedef struct petshop{
    char registro[20];
    char nome[20]; // Campo com repetições
    int idade; // Campo com repetições
    char sexo;//Campo com 2 repetições
    //Sexo pode ser:
    //M - Masculino
    //F - Feminino  
    char especie[20];//Campo com 4 repetições
    /*Raças disponíveis:
    Cachorro
    Coelho
    Gato
    Passaro*/

};

typedef struct indices{
    char string[20];
    int pos;
    indices *prox;
};

void carregarLista(petshop lista[],int *tam);
int buscarRA(petshop lista[],int tam,char x[]);
void imprimirLista(petshop lista[],int tam);
void carregarIndices(petshop lista[],indices indiceR[],indices**indiceA,int tam);
void quickSort(indices indiceR[],int ini,int fim);
void bubbleSort(indices **indiceA,int tam);
int menu();

int main(){

    int op,tam,a;
    char x[20];
    petshop lista[80];

    //Indice do Registro
    indices indiceR[80];

    //Indice do Alfabeto
    indices *indiceA;
    
    carregarLista(lista,&tam);
    carregarIndices(lista,indiceR,&indiceA,tam);

    quickSort(indiceR,0,tam-1);
    bubbleSort(&indiceA,tam-1);

    printf("\n");

    do{
        op = menu();

        switch(op){
            case 1:
                printf("\nDigite o registro do animal : ");
                scanf("%s",&x);

                a = buscarRA(lista,tam,x);

                if(a != -1) 
                    printf("%s %s %d %c %s\n\n",lista[a].registro,lista[a].nome,lista[a].idade,lista[a].sexo,lista[a].especie);
                else
                    printf("Registro nao encontrado\n\n");
                break;
            
            case 2:
                imprimirLista(lista,tam);
                break;
        }
    }while(op !=0);

    for(int i = 0;i<tam;i++){
        printf("%s %d\n",indiceR[i].string,indiceR[i].pos);
    }

    printf("\n");

    for(int i = 0;i<tam;i++){
        printf("%s %d\n",indiceA->string,indiceA->pos);
        indiceA = indiceA->prox;
    }

}

void carregarLista(petshop lista[],int *tam){
    
    (*tam)=80;
    petshop base[] = {
    {"07","Theo",3,'M',"Gato"},
    {"54","Negao",4,'M',"Passaro"},
    {"01","Thor",1,'F',"Coelho"},
    {"42","Aloha",7,'F',"Gato"},
    {"04","Toddy",12,'M',"Cachorro"},
    {"06","Bob",7,'M',"Passaro"},
    {"11","Max",6,'F',"Gato"},
    {"08","Lucky",3,'M',"Coelho"},
    {"09","Zeca",1,'F',"Gato"},
    {"10","Fred",5,'F',"Cachorro"},
    {"12","Pingo",6,'F',"Passaro"},
    {"68","Nescau",4,'M',"Gato"},
    {"24","Mingau",4,'M',"Coelho"},
    {"13","Boris",7,'M',"Gato"},
    {"15","Nina",4,'M',"Gato"},
    {"43","Java",3,'F',"Passaro"},
    {"16","Mel",3,'M',"Coelho"},
    {"17","Luna",2,'F',"Cachorro"},
    {"77","Caroline",4,'F',"Cachorro"},
    {"18","Tom",1,'M',"Gato"},
    {"19","Amora",11,'F',"Passaro"},
    {"20","Fred",3,'M',"Coelho"},
    {"14","Bidu",8,'M',"Gato"},
    {"21","Pipoca",4,'M',"Cachorro"},
    {"22","Chico",7,'M',"Passaro"},
    {"23","Pandora",5,'F',"Gato"},
    {"28","Maya",4,'F',"Cachorro"},
    {"25","Jade",1,'F',"Passaro"},
    {"26","Sofia",4,'F',"Coelho"},
    {"27","Luke",5,'M',"Cachorro"},
    {"45","Miudo",6,'M',"Cachorro"},
    {"62","Shrek",2,'M',"Passaro"},
    {"36","Floquinho",6,'M',"Cachorro"},
    {"29","Lili",2,'F',"Coelho"},
    {"30","Aurora",4,'F',"Passaro"},
    {"31","Frederico",5,'M',"Gato"},
    {"32","Perola",5,'F',"Coelho"},
    {"33","Sushi",7,'F',"Gato"},
    {"34","Pantera",4,'M',"Passaro"},
    {"05","Simba",6,'M',"Gato"},
    {"37","Alice",7,'F',"Cachorro"},
    {"38","Jack",9,'M',"Coelho"},
    {"50","Zica",6,'M',"Cachorro"},
    {"64","Pet",3,'F',"Gato"},
    {"39","Belinha",1,'F',"Passaro"},
    {"40","Chelsea",4,'F',"Gato"},
    {"41","Nino",5,'F',"Coelho"},
    {"03","Ozzy",4,'M',"Passaro"},
    {"44","Xarope",2,'M',"Cachorro"},
    {"70","Cake",4,'F',"Gato"    },
    {"46","Magrela",1,'F',"Passaro"},
    {"47","Viva",4,'F',"Coelho"},
    {"55","Chuvisco",5,'M',"Gato"},
    {"48","Vida",4,'F',"Gato"},
    {"49","Maluca",7,'F',"Coelho"},
    {"80","Tommy",8,'M',"Passaro"},
    {"59","Kiko",3,'M',"Gato"},
    {"65","Vareta",2,'F',"Cachorro"},
    {"51","Fumaca",5,'F',"Coelho"},
    {"53","Branquinha",3,'F',"Cachorro"},
    {"56","Esguicho",4,'M',"Passaro"},
    {"79","Winry",2,'F',"Cachorro"},
    {"52","Kitten",1,'F',"Gato"},
    {"57","Bolinha",2,'M',"Gato"},
    {"58","Godofredo" ,4,'M',"Cachorro"},
    {"69","Oreo",2,'M',"Gato"},
    {"60","Chaves",5,'M',"Coelho"},
    {"63","Espanador",5,'M',"Passaro"},
    {"66","Farofa",1,'F',"Cachorro"},
    {"61","Ketchup",6,'F',"Coelho"},
    {"72","Mirtilo",3,'F',"Gato"},
    {"74","Taylor",7,'F',"Passaro"},
    {"75","Tom",8,'M',"Coelho"},
    {"02","Bruce",3,'F',"Cachorro"},
    {"76","Hello Kitty",2,'F',"Gato"},
    {"78","Edward",5,'M',"Coelho"},  
    {"71","Chocolate",6,'M',"Passaro"},
    {"35","Chocolate",2,'M',"Coelho"},
    {"67","Leite" ,9,'M',"Cachorro"},
    {"73","Cafe",5,'M',"Passaro"},
    };

    for(int i=0;i<(*tam);i++){
        lista[i] = base[i];
    }
}

void bubbleSort(indices **indiceA,int tam){

    int teste = 1;
    indices *aux,*aux2,*aux3;
    int i,j;

    aux = (indices*) malloc (sizeof(indices));
    aux2= (indices*) malloc (sizeof(indices));
    aux3= (indices*) malloc (sizeof(indices));

    for(i=0;i<tam && teste;i++){
        teste=0;
        aux = (*indiceA);
        aux2 = aux->prox;
        for(j=0; j<tam-i;j++){
            if((strcmp(aux->string,aux2->string))>0){
                teste = 1;
                strcpy(aux3->string,aux->string);
                strcpy(aux->string,aux2->string);
                strcpy(aux2->string,aux3->string);
                aux3->pos = aux->pos;
                aux->pos = aux2->pos;
                aux2->pos = aux3->pos;
            }
            aux = aux->prox;
            aux2 = aux2->prox;
            if(aux == NULL)
                break;
        }
    }
}

void quickSort(indices indiceR[],int ini,int fim){

    int flag = 1,i,j;
    char aux[20];
    int aux2;

    if(ini<fim){
        i=ini;
        j=fim;
    
        while(i!=j){
            if((strcmp(indiceR[i].string,indiceR[j].string))>0){
                strcpy(aux,indiceR[i].string);
                strcpy(indiceR[i].string,indiceR[j].string);
                strcpy(indiceR[j].string,aux);
                aux2 = indiceR[i].pos;
                indiceR[i].pos = indiceR[j].pos;
                indiceR[j].pos = aux2;
                flag = flag * (-1);
            }

            if(flag==1)
                j--;
            else
                i++;
        }

        quickSort(indiceR,ini,j-1);
        quickSort(indiceR,i+1,fim);
        
    }

}

void carregarIndices(petshop lista[],indices indiceR[],indices**indiceA,int tam){

    for(int i = 0;i<tam;i++){
        strcpy(indiceR[i].string,lista[i].registro);
        indiceR[i].pos=i;
    }

    for(int i = 0;i<tam;i++){
        indices* aux = (indices*) malloc (sizeof(indices)); 
        if (aux) {  
            strcpy(aux->string,lista[i].nome);
            aux->pos = i;
            aux->prox = NULL;
            if (!(*indiceA)) { 
                (*indiceA) = aux;
                (*indiceA)->prox = NULL;
            } 
            else {
                aux->prox = (*indiceA); 
                (*indiceA) = aux;
            }
        }
        else 
            printf("Heap Overflow\n");
    }
    
}

int menu(){

    int op;
    while(op!=0){
        
        printf("======PETSHOP======\n\n");
        printf("1 - Buscar um animal\n");
        printf("2 - Imprimir animais\n");
        printf("0 - Sair\n");
        printf("Opcao : ");
        scanf("%d",&op);
        fflush(stdin);

        if(op < 0 || op > 2)
            printf("Opcao invalida\n");
        else
            return op;
    }
}

int buscarRA (petshop lista[],int tam,char x[]){

    for(int i=0;i<tam;i++)
        if((strcmp(lista[i].registro,x))==0) return i;
    return -1;
    
}

void imprimirLista(petshop lista[],int tam){
    
    int maiornome = 0;
    int maiorespecie = 0;
    int ra,espaco;

    for(int i=0;i<tam;i++){
        if(maiornome < strlen(lista[i].nome))
            maiornome = strlen(lista[i].nome);
    }

    for(int i=0;i<tam;i++){
        if(maiorespecie < strlen(lista[i].especie))
            maiorespecie = strlen(lista[i].especie);
    }

    printf("\nRA|Nome       |Idade|Raca                 |Sexo|Especie |\n");
    for(int i=0;i<tam;i++){

        if(i == 80)
            return;
        
        //Impressão do Registro
        ra = stoi(lista[i].registro);

        if(ra < 10)
            printf("0");
        printf("%s|",lista[i].registro);

        //Impressão do nome
        espaco = maiornome - strlen(lista[i].nome);
        printf("%s",lista[i].nome);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|");

        //Impressão da idade
        printf("%d",lista[i].idade);
        if(lista[i].idade < 10)
            printf("    |");
        else
            printf("   |");

        //Impressão do Sexo
        printf("%c   |",lista[i].sexo);

        //Impressão da Especie
        espaco = maiorespecie - strlen(lista[i].especie);
        printf("%s",lista[i].especie);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|\n\n");
    }
}
