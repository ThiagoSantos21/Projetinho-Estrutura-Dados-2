//Função 1 – Criar Índice Exaustivo + função QuichSort - PRONTO
//Função 2 – Criar Índice Ordem Alfabética do Nome – usar o método BubbleSort dentro da própria função  - PRONTO
//Função 3 – Criar Índice Secundário por Curso seguindo o Índice da Ordem Alfabética – DEVE ser usado um dos campos que tenham pelo menos 4 categorias. Não usar menos do que isso; - PRONTO
//Função 4 – Busca aluno por RA usando a Busca Binária -> e imprime todos os dados do aluno – usar Índice criado na função1; - PRONTO
//Função 5 – Imprime TODOS os dados de TODOS os Alunos por ordem crescente de RA – usa o Índice criado na função1; - PRONTO
//Função 6 – Imprime TODOS os dados de TODOS os Alunos por ordem Alfabética de Nome– usa o Índice criado na função2; - PRONTO
//Função 7 – Imprime TODOS os dados dos alunos de DETERMINADO CURSO – o curso a ser impresso deve ser pedido para o usuário escolher – usa o Índice criado na função3; - PRONT

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

typedef struct indiceAlfabeto{
    int pos;
    indiceAlfabeto *prox;
};

typedef struct indiceRegistro{
    char string[20];
    int pos;
};



void carregarLista(petshop lista[],int *tam);
int  buscarRA(indiceRegistro indiceR[],int tam);
void imprimirLista(petshop lista[],int tam);
void carregarIndiceA(petshop lista[],indiceAlfabeto**indiceA,int tam,int *pri);
void imprimirIndiceA(petshop lista[],indiceAlfabeto*indiceA,int tam,int pri);
void carregarIndiceEA(petshop lista[],indiceAlfabeto**indiceA,int tam,int *priEA);
void imprimirIndiceEA(petshop lista[],indiceAlfabeto*indiceEA,int tam,int priEA[]);
void carregarIndiceR(petshop lista[],indiceRegistro indiceR[],int tam);
void imprimirIndiceR(petshop lista[],indiceRegistro indiceR[],int tam);
void quickSort(indiceRegistro indiceR[],int ini,int fim);
int  menu();

int main(){

    int op,tam,a;
    petshop lista[80];

    //Indice do Registro
    indiceRegistro indiceR[80];

    //Indice Ordem Alfabeto
    indiceAlfabeto *indiceA;

    //Indice Ordem Alfabetica por especie
    indiceAlfabeto *indiceEA;

    //Variavel PRI do indiceA
    int pri;

    //Variavel PRI do indiceEA
    int priEA[4];
    
    carregarLista(lista,&tam);
    carregarIndiceR(lista,indiceR,tam);
    carregarIndiceA(lista,&indiceA,tam,&pri);
    carregarIndiceEA(lista,&indiceEA,tam,priEA);

    do{
        op = menu();

        switch(op){
            case 1:
                a = buscarRA(indiceR,tam);
                a = indiceR[a].pos;
                if(a != -1){
                    printf("\nAnimal encontrado:\n");
                    printf("Registro: %s\n",lista[a].registro);
                    printf("Nome: %s\n",lista[a].nome);
                    printf("Idade: %d\n",lista[a].idade);
                    printf("Sexo: %c\n",lista[a].sexo);
                    printf("Especie: %s\n",lista[a].especie);
                }
                system("pause");
                system("cls");
                break;
            case 2:
                imprimirLista(lista,tam);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                imprimirIndiceR(lista,indiceR,tam);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 4:
                imprimirIndiceA(lista,indiceA,tam,pri);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                imprimirIndiceEA(lista,indiceEA,tam,priEA);
                printf("\n");
                system("pause");
                system("cls");
                break;

        }
    }while(op !=0);

    /*printf("\n");
    for(int i=0;i<tam;i++){
        printf("%s\n",lista[indiceR[i].pos].registro);
    }

    printf("\n");

    int aux = pri;
    indiceAlfabeto *auxi;

    for(int i=0;i<tam;i++){
        auxi = indiceA;
        if(aux == -1)
            break;
        printf("%s\n",lista[aux].nome);
        for(int j=0;j<aux;j++)
            auxi = auxi->prox;
        aux=auxi->pos;
    }

    printf("\n");

    for(int j=0;j<4;j++){
        aux = priEA[j];
        auxi = indiceEA;

        for(int i=0;i<tam;i++){
            auxi = indiceEA;
            if(aux == -1)
                break;
            printf("%s\n",lista[aux].nome);
            for(int j=0;j<aux;j++)
                auxi = auxi->prox;
            aux=auxi->pos;
        }
        printf("\n");
    }*/

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

void carregarIndiceA(petshop lista[],indiceAlfabeto**indiceA,int tam,int *pri){

    //Criação do Indice Alfabético 
    for(int i = tam-1;i>=0;i--){

        indiceAlfabeto* aux = (indiceAlfabeto*) malloc (sizeof(indiceAlfabeto));
         
        if (aux) {  
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

    //BubbleSort - Ordem alfabética
    int teste = 1;
    int i,j,pos;
    indiceAlfabeto* x = (indiceAlfabeto*) malloc (sizeof(indiceAlfabeto));

    for(i=0;i<tam && teste;i++){
        teste=0;
        x = (*indiceA);
        for(j=0; j<tam-i;j++){
            if(x->prox == NULL){
                break;
            }
            if((strcmp(lista[x->pos].nome,lista[x->prox->pos].nome))>0){
                teste = 1;
                pos = x->pos;
                x->pos = x->prox->pos;
                x->prox->pos = pos;
            }
            x = x->prox;
        }
    }

    //Variável que irá percorrer a lista e fará a troca dos valores das posiçoes
    indiceAlfabeto*a = (*indiceA);

    //Tabela auxiliar -  será usada na organização da tabela
    int auxt[80];

    //Carregar a tabela auxiliar
    for(int i=0;i<tam;i++){
        auxt[i] = a->pos;
        a = a->prox;
    }

    //Salvar o primeiro termo da tabela Invertida
    (*pri) = auxt[0];

    a = (*indiceA);


    //Organizar os termos da tabela
    for(i=0;i<tam;i++){
        for(j=0;j!=auxt[i];j++)
            a = a->prox;
        if(i==79)
            a->pos = -1;

        else{
            a->pos = auxt[i+1];
            a = (*indiceA); 
        }
    }
}

void imprimirIndiceA(petshop lista[],indiceAlfabeto*indiceA,int tam,int pri){

    char especie[20];
    system("cls");
    int pos = pri;
    indiceAlfabeto* aux = indiceA;
    int maiornome = 0;
    int maiorespecie = 0;
    int ra,espaco;

    for(int i=0;i<tam;i++){
        aux = indiceA;
        if(maiornome < strlen(lista[pos].nome))
            maiornome = strlen(lista[pos].nome);
        if(pos == -1)
            break;
        for(int j=0;j<pos;j++)
            aux = aux->prox;
        pos=aux->pos;
                
    }

    pos = pri;

    for(int i=0;i<tam;i++){
        aux = indiceA;
        if(maiorespecie < strlen(lista[pos].especie))
            maiorespecie = strlen(lista[pos].especie);
        if(pos == -1)
            break;
        for(int j=0;j<pos;j++)
            aux = aux->prox;
        pos=aux->pos;  
    }

    pos = pri;

    printf("RA|Nome");
    for(int i=0;i<maiornome-4;i++){
        printf(" ");
    }      
    printf("|Idade|Sexo|Especie |\n");
    for(int i=0;i<tam;i++){
        aux = indiceA;
        if(pos == -1)
            return;
                
        //Impressão do Registro
        printf("%s|",lista[pos].registro);

        //Impressão do nome
        espaco = maiornome - strlen(lista[pos].nome);
        printf("%s",lista[pos].nome);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|");

        //Impressão da idade
        printf("%d",lista[pos].idade);
        if(lista[pos].idade < 10)
            printf("    |");
        else
            printf("   |");

        //Impressão do Sexo
        printf("%c   |",lista[pos].sexo);

        //Impressão da Especie
        espaco = maiorespecie - strlen(lista[pos].especie);
        printf("%s",lista[pos].especie);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|\n");

        for(int j=0;j<pos;j++)
            aux = aux->prox;
        pos=aux->pos;

    }
}

void carregarIndiceEA(petshop lista[],indiceAlfabeto**indiceEA,int tam,int *priEA){

    //Criação do Indice Especie Alfabético 
    for(int i = tam-1;i>=0;i--){

        indiceAlfabeto* aux = (indiceAlfabeto*) malloc (sizeof(indiceAlfabeto));
         
        if (aux) {  
            aux->pos = i;
            aux->prox = NULL;
            if (!(*indiceEA)) { 
                (*indiceEA) = aux;
                (*indiceEA)->prox = NULL;
            } 
            else {
                aux->prox = (*indiceEA); 
                (*indiceEA) = aux;
            }
        }
        else 
            printf("Heap Overflow\n");
    }

    //BubbleSort - Ordem alfabética
    int teste = 1;
    int i,j,pos;
    indiceAlfabeto* x = (indiceAlfabeto*) malloc (sizeof(indiceAlfabeto));

    for(i=0;i<tam && teste;i++){
        teste=0;
        x = (*indiceEA);
        for(j=0; j<tam-i;j++){
            if(x->prox == NULL){
                break;
            }
            if((strcmp(lista[x->pos].nome,lista[x->prox->pos].nome))>0){
                teste = 1;
                pos = x->pos;
                x->pos = x->prox->pos;
                x->prox->pos = pos;
            }
            x = x->prox;
        }
    }

    //Variável que irá percorrer a lista e fará a troca dos valores das posiçoes
    indiceAlfabeto*a = (*indiceEA);

    //Tabela auxiliar -  será usada na organização da tabela
    int auxt[80];

    //Carregar a tabela auxiliar
    for(int i=0;i<tam;i++){
        auxt[i] = a->pos;
        a = a->prox;
    }


    //Inicializando o priEA
    for(i=0;i<4;i++){
        priEA[i] = -1;
    }

    //Salvar os primeiros termos da tabela secundária
    for(i=0,j=0;i<4;i++){
        teste = 0;
        
        while(teste != 1 || j>tam){
            if (i != 0) {
                for(int k=0,l=i;k<i;k++){
                    if(priEA[i] == -1 ){
                        if((strcmp(lista[priEA[k]].especie,lista[auxt[j]].especie)) != 0){
                            l--;
                        }
                    }

                    if(l == 0){
                        priEA[i] = auxt[j];
                        teste = 1;
                    }
                }
            } else {
                priEA[i] = auxt[j];
                teste = 1;
            }
            j++;   
        }
    }

    a = (*indiceEA);


    //Organizar os termos da tabela
    for(i=0;i<4;i++){
        int pos = priEA[i];
        for(j=0;j<tam;j++){
            if((strcmp(lista[pos].especie,lista[auxt[j]].especie)) == 0 && (strcmp(lista[pos].nome,lista[auxt[j]].nome)) != 0 ){
                for(int k = 0;k<pos;k++){
                    a = a->prox;
                }
                pos = auxt[j];
                a->pos = auxt[j];
            }
            a = (*indiceEA);
        }

        for(int k = 0;k<pos;k++){
            a = a->prox;
        }
        a->pos = -1;

        pos = priEA[i];

        for(int m=0;m<tam;m++){
            if(pos == -1)
                break;
            a = (*indiceEA);
            for(int n=0;n<pos;n++)
                a = a->prox;
            pos=a->pos;
        }
    }
}

void imprimirIndiceEA(petshop lista[],indiceAlfabeto*indiceEA,int tam,int priEA[]){

    char especie[20];
    int teste;
    int maiorespecie = strlen(lista[priEA[0]].especie);
    printf("\nDigite a especie (Cachorro,Gato,Coelho,Passaro):\n");
    scanf("%s",&especie);
    system("cls");

    for(int i=0;i<4 && teste;i++){
        int pos = priEA[i];
        if((strcmp(lista[pos].especie,especie)) == 0){
            teste = 1;
            indiceAlfabeto* aux = indiceEA;
            int maiornome = 0;
            int ra,espaco;

            for(int i=0;i<tam;i++){
                aux = indiceEA;
                if(maiornome < strlen(lista[pos].nome))
                    maiornome = strlen(lista[pos].nome);
                if(pos == -1)
                    break;
                for(int j=0;j<pos;j++)
                    aux = aux->prox;
                pos=aux->pos;
                
            }

            pos = priEA[i];

            printf("RA|Nome");
            for(int i=0;i<maiornome-4;i++){
                printf(" ");
            }      
            printf("|Idade|Sexo|Especie |\n");
            for(int i=0;i<tam;i++){
                aux = indiceEA;
                if(pos == -1)
                    return;
                
                //Impressão do Registro
                printf("%s|",lista[pos].registro);

                //Impressão do nome
                espaco = maiornome - strlen(lista[pos].nome);
                printf("%s",lista[pos].nome);
                for(int j=0;j<espaco;j++)
                    printf(" ");
                printf("|");

                //Impressão da idade
                printf("%d",lista[pos].idade);
                if(lista[pos].idade < 10)
                    printf("    |");
                else
                    printf("   |");

                //Impressão do Sexo
                printf("%c   |",lista[pos].sexo);

                //Impressão da Especie
                espaco = maiorespecie - strlen(lista[pos].especie);
                printf("%s",lista[pos].especie);
                for(int j=0;j<espaco;j++)
                    printf(" ");
                printf("|\n");

                for(int j=0;j<pos;j++)
                    aux = aux->prox;
                pos=aux->pos;

            }
        }
    }
    
    if(teste == 1)
        return;
    else
        printf("Especie nao encontrada\n");
    

}
    
void carregarIndiceR(petshop lista[],indiceRegistro indiceR[],int tam){

    for(int i = 0;i<tam;i++){
        strcpy(indiceR[i].string,lista[i].registro);
        indiceR[i].pos=i;
    }

    quickSort(indiceR,0,tam-1);
}

void imprimirIndiceR(petshop lista[],indiceRegistro indiceR[],int tam){

    int maiornome = 0;
    int maiorespecie = 0;
    int ra,espaco;

    system("cls");

    for(int i=0;i<tam;i++){
        if(maiornome < strlen(lista[indiceR[i].pos].nome))
            maiornome = strlen(lista[indiceR[i].pos].nome);
    }

    for(int i=0;i<tam;i++){
        if(maiorespecie < strlen(lista[indiceR[i].pos].especie))
            maiorespecie = strlen(lista[indiceR[i].pos].especie);
    }

    printf("RA|Nome       |Idade|Sexo|Especie |\n");
    for(int i=0;i<tam;i++){

        if(i == 80)
            return;
        
        //Impressão do Registro
        printf("%s|",lista[indiceR[i].pos].registro);

        //Impressão do nome
        espaco = maiornome - strlen(lista[indiceR[i].pos].nome);
        printf("%s",lista[indiceR[i].pos].nome);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|");

        //Impressão da idade
        printf("%d",lista[indiceR[i].pos].idade);
        if(lista[indiceR[i].pos].idade < 10)
            printf("    |");
        else
            printf("   |");

        //Impressão do Sexo
        printf("%c   |",lista[indiceR[i].pos].sexo);

        //Impressão da Especie
        espaco = maiorespecie - strlen(lista[indiceR[i].pos].especie);
        printf("%s",lista[indiceR[i].pos].especie);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|\n");
    }
}

void quickSort(indiceRegistro indiceR[],int ini,int fim){

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

int menu(){

    int op;
    while(op!=0){
        
        printf("======PETSHOP======\n\n");
        printf("1 - Buscar um animal\n");
        printf("2 - Imprimir animais\n");
        printf("3 - Imprimir animais em ordem do registro\n");
        printf("4 - Imprimir animais em ordem alfabetica\n");
        printf("5 - Imprimir animais em ordem alfabetica de apenas uma especie\n");
        printf("0 - Sair\n");
        printf("Opcao : ");
        scanf("%d",&op);
        fflush(stdin);

        if(op < 0 || op > 5)
            printf("Opcao invalida\n");
        else
            return op;
    }
}

int buscarRA (indiceRegistro indiceR[],int tam){

    int sup = tam-1, inf = 0;
    int meio;
    char x[20];
    system("cls");

    printf("Digite o registro: ");
    scanf("%[^\n]",&x);

    while(inf<=sup){
        meio = (sup+inf)/2;
        if((strcmp(indiceR[meio].string,x))==0){
            return meio;
        }
        if((strcmp(indiceR[meio].string,x))<0){
            inf = meio+1;
        }
        else{
            sup = meio-1;
        }
    }
    return -1;
    
}

void imprimirLista(petshop lista[],int tam){
    
    int maiornome = 0;
    int maiorespecie = 0;
    int ra,espaco;

    system("cls");

    for(int i=0;i<tam;i++){
        if(maiornome < strlen(lista[i].nome))
            maiornome = strlen(lista[i].nome);
    }

    for(int i=0;i<tam;i++){
        if(maiorespecie < strlen(lista[i].especie))
            maiorespecie = strlen(lista[i].especie);
    }

    printf("RA|Nome       |Idade|Sexo|Especie |\n");
    for(int i=0;i<tam;i++){

        if(i == 80)
            return;
        
        //Impressão do Registro
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
        printf("|\n");
    }
}
