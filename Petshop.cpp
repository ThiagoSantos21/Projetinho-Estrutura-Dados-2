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
    char nome[20];
    int idade;
    char raca[30];
    char sexo;
    /* Sexo pode ser :
        M: Masculino
        F: Feminino
    */
    char especie[20];
    /* Espécie disponíveis :
        Cachorro
        Gato
        Coelho
        Lagarto
    */
};

void carregar(petshop lista[],int *tam);
int buscar(petshop lista[],int tam,char x[]);
void imprimir(petshop lista[],int tam);

int menu();

int main(){

    int op,tam,a;
    char x[20];
    petshop lista[80];

    carregar(lista,&tam);

    do{
        op = menu();
        fflush(stdin);

        switch(op){
            case 1:
                printf("\nDigite o registro do animal : ");
                scanf("%s",&x);

                a = buscar(lista,tam,x);

                if(a != -1) 
                    printf("%s %s %d %s %c %s\n\n",lista[a].registro,lista[a].nome,lista[a].idade,lista[a].raca,lista[a].sexo,lista[a].especie);
                else
                    printf("Registro nao encontrado\n\n");
                break;
            
            case 2:
                imprimir(lista,tam);
                break;
        }
    }while(op !=0);

}

void carregar(petshop lista[],int *tam){
    
    (*tam)=80;
    petshop base[] = {

    {"7" ,"Theo"       ,3,"Bengal"               ,'M',"Gato"    },
    {"54","Negao"      ,4,"Vira-Lata"            ,'M',"Cachorro"},
    {"1" ,"Thor"       ,1,"Beagle"               ,'F',"Cachorro"},
    {"42","Aloha"      ,7,"Vira-Lata"            ,'F',"Gato"    },
    {"4" ,"Toddy"      ,12,"Beagle"              ,'M',"Cachorro"},
    {"6" ,"Bob"        ,7,"Yorkshire"            ,'M',"Cachorro"},
    {"11","Max"        ,6,"Beagle"               ,'F',"Gato"    },
    {"8" ,"Lucky"      ,3,"Pelo curto brasileiro",'M',"Gato"    },
    {"9" ,"Zeca"       ,1,"Pelo curto brasileiro",'F',"Gato"    },
    {"10","Fred"       ,5,"Chihuahua"            ,'F',"Cachorro"},
    {"12","Pingo"      ,6,"Pit bull"             ,'F',"Cachorro"},
    {"68","Nescau"     ,4,"Balines"              ,'M',"Gato"    },
    {"24","Mingau"     ,4,"Vira-Lata"            ,'M',"Gato"    },
    {"13","Boris"      ,7,"Balines"              ,'M',"Gato"    },
    {"15","Nina"       ,4,"Bengal"               ,'M',"Gato"    },
    {"43","Java"       ,3,"Vira-Lata"            ,'F',"Cachorro"},
    {"16","Mel"        ,3,"Balines"              ,'M',"Gato"    },
    {"17","Luna"       ,2,"Vira-Lata"            ,'M',"Cachorro"},
    {"77","Caroline"   ,4,"Maltes"               ,'F',"Cachorro"},
    {"18","Tom"        ,1,"Vira-Lata"            ,'M',"Gato"    },
    {"19","Amora"      ,11,"Maltes"              ,'F',"Cachorro"},
    {"20","Fred"       ,3,"Beagle"               ,'M',"Cachorro"},
    {"14","Bidu"       ,8,"Pelo curto brasileiro",'F',"Gato"    },
    {"21","Pipoca"     ,4,"Vira-Lata"            ,'M',"Cachorro"},
    {"22","Chico"      ,7,"Pelo curto brasileiro",'M',"Gato"    },
    {"23","Pandora"    ,5,"Balines"              ,'M',"Gato"    },
    {"28","Maya"       ,4,"Pit bull"             ,'M',"Cachorro"},
    {"25","Jade"       ,1,"Pelo curto brasileiro",'F',"Gato"    },
    {"26","Sofia"      ,4,"Beagle"               ,'F',"Cachorro"},
    {"27","Luke"       ,5,"Maltes"               ,'F',"Cachorro"},
    {"45","Miudo"      ,6,"Beagle"               ,'M',"Cachorro"},
    {"62","Shrek"      ,2,"Beagle"               ,'M',"Cachorro"},
    {"36","Floquinho"  ,6,"Pit bull"             ,'F',"Cachorro"},
    {"29","Lili"       ,2,"Yorkshire"            ,'M',"Cachorro"},
    {"30","Aurora"     ,4,"Balines"              ,'M',"Gato"    },
    {"31","Frederico"  ,5,"Vira-Lata"            ,'M',"Gato"    },
    {"32","Perola"     ,5,"Chihuahua"            ,'F',"Cachorro"},
    {"33","Sushi"      ,7,"Vira-Lata"            ,'F',"Gato"    },
    {"34","Pantera"    ,4,"Beagle"               ,'M',"Cachorro"},
    {"5","Simba"       ,6,"Balines"              ,'F',"Gato"    },
    {"37","Alice"      ,7,"Yorkshire"            ,'M',"Cachorro"},
    {"38","Jack"       ,9,"Balines"              ,'M',"Gato"    },
    {"50","Zica"       ,6,"Maltes"               ,'M',"Cachorro"},
    {"64","Pet"        ,3,"Bengal"               ,'F',"Gato"    },
    {"39","Belinha"    ,1,"Bengal"               ,'M',"Gato"    },
    {"40","Chelsea"    ,4,"Pelo curto brasileiro",'F',"Gato"    },
    {"41","Nino"       ,5,"Vira-Lata"            ,'F',"Cachorro"},
    {"3" ,"Ozzy"       ,4,"Pit bull"             ,'F',"Cachorro"},
    {"44","Xarope"     ,2,"Maltes"               ,'F',"Cachorro"},
    {"70","Cake"       ,4,"Pelo curto brasileiro",'F',"Gato"    },
    {"46","Magrela"    ,1,"Balines"              ,'M',"Gato"    },
    {"47","Viva"       ,4,"Yorkshire"            ,'F',"Cachorro"},
    {"55","Chuvisco"   ,5,"Pelo curto brasileiro",'M',"Gato"    },
    {"48","Vida"       ,4,"Bengal"               ,'M',"Gato"    },
    {"49","Maluca"     ,7,"Vira-Lata"            ,'M',"Cachorro"},
    {"80","Tommy"      ,8,"Beagle"               ,'M',"Cachorro"},
    {"59","Kiko"       ,3,"Vira-Lata"            ,'M',"Gato"    },
    {"65","Vareta"     ,2,"Chihuahua"            ,'F',"Cachorro"},
    {"51","Fumaca"     ,5,"Chihuahua"            ,'F',"Cachorro"},
    {"53","Branquinha" ,3,"Vira-Lata"            ,'M',"Cachorro"},
    {"56","Esguicho"   ,4,"Yorkshire"            ,'M',"Cachorro"},
    {"79","Winry"      ,2,"Chihuahua"            ,'F',"Cachorro"},
    {"52","Kitten"     ,1,"Vira-Lata"            ,'F',"Gato"    },
    {"57","Bolinha"    ,2,"Bengal"               ,'M',"Gato"    },
    {"58","Godofredo"  ,4,"Vira-Lata"            ,'M',"Cachorro"},
    {"69","Oreo"       ,2,"Vira-Lata"            ,'M',"Gato"    },
    {"60","Chaves"     ,5,"Vira-Lata"            ,'M',"Cachorro"},
    {"63","Espanador"  ,5,"Vira-Lata"            ,'M',"Cachorro"},
    {"66","Farofa"     ,1,"Vira-Lata"            ,'F',"Cachorro"},
    {"61","Ketchup"    ,6,"Maltes"               ,'F',"Cachorro"},
    {"72","Mirtilo"    ,3,"Bengal"               ,'F',"Gato"    },
    {"74","Taylor"     ,7,"Balines"              ,'F',"Gato"    },
    {"75","Tom"        ,8,"Yorkshire"            ,'M',"Cachorro"},
    {"2" ,"Bruce"      ,3,"Chihuahua"            ,'F',"Cachorro"},
    {"76","Hello Kitty",2,"Bengal"               ,'F',"Gato"    },
    {"78","Edward"     ,5,"Pit bull"             ,'M',"Cachorro"},  
    {"71","Chocolate"  ,6,"Vira-Lata"            ,'M',"Cachorro"},
    {"35","Chocolate"  ,2,"Vira-Lata"            ,'M',"Cachorro"},
    {"67","Leite"      ,9,"Pit Bull"             ,'M',"Cachorro"},
    {"73","Cafe"       ,5,"Vira-Lata"            ,'M',"Gato    "},
    };

    for(int i=0;i<(*tam);i++){
        lista[i] = base[i];
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

        if(op < 0 || op > 2)
            printf("Opcao invalida\n");
        else
            return op;
    }
}

int buscar (petshop lista[],int tam,char x[]){

    for(int i=0;i<tam;i++)
        if((strcmp(lista[i].registro,x))==0) return i;
    return -1;
}

void imprimir(petshop lista[],int tam){
    
    int maiornome = 0;
    int maiorraca = 0;
    int maiorespecie = 0;
    int ra,espaco;

    for(int i=0;i<tam;i++){
        if(maiornome < strlen(lista[i].nome))
            maiornome = strlen(lista[i].nome);
    }

    for(int i=0;i<tam;i++){
        if(maiorraca < strlen(lista[i].raca))
            maiorraca = strlen(lista[i].raca);
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

        //Impressão da Raça
        espaco = maiorraca - strlen(lista[i].raca);
        printf("%s",lista[i].raca);
        for(int j=0;j<espaco;j++)
            printf(" ");
        printf("|");

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