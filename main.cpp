#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <queue>
#include <iostream>
#include <list>
#include<locale.h>
#include<limits.h>
#include <math.h>

using namespace std;

const int tam = 32;

int G[tam][tam] = {
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
};

int v[tam];

char *num_letra(int num) {
  switch(num) {
    case 0: return "baja california sur";
    case 1: return "baja california";
    case 2: return "sonnara";
    case 3: return "chihuahua";
    case 4: return "sinaloa";
    case 5: return "coahuila";
    case 6: return "durango";
    case 7: return "nuevo le?o";
    case 8: return "tamaulipas";
    case 9: return "nagarit";
    case 10: return "zacatec";
    case 11: return "san luis patosi";
    case 12: return "aguascalientes";
    case 13: return "jalisco";
    case 14: return "guanajuato";
    case 15: return "queretaro";
    case 16: return "hidalgo";
    case 17: return "veracruz";
    case 18: return "colima";
    case 19: return "michoacan";
    case 20: return "estado de m?xico";
    case 21: return "distrito federal ( mexico city)";
    case 22: return "Tlaxcala";
    case 23: return "Guerrero";
    case 24: return "Morelos";
    case 25: return "Puebla";
    case 26: return "Daxaca";
    case 27: return "Tabasco";
    case 28: return "Chiap";
    case 29: return "Campec";
    case 30: return "Yucat?n";
    case 31: return "Quintana Roo";
    default: return "";
  }
}

void buscaEmProfundidade(int vertice) {
  v[vertice] = 1;
  printf("\n%1d - %s", vertice, num_letra(vertice));
  for (int column = 0; column < tam; column++) {
    if (G[vertice][column]== 1) {
      if (v[column] == 0) {
        buscaEmProfundidade(column);
      }
    }
  }
}

int buscaEmProfundidadeComDestino(int origem, int destino) {
  if (origem == destino) {
    printf("\n%1d - %s", destino,num_letra(destino));
    return destino;
  } else {
    int column;
    int encontrado = 0;

    v[origem] = 1;
    printf("\n%1d - %s", origem, num_letra(origem));

    for (column = 0; column < tam; column++) {
        if (G[origem][column]== 1) {
          if (v[column] == 0) {
              if (buscaEmProfundidadeComDestino(column, destino) == destino) {
                return destino;
              }
          }
      }
    }
  }
}

void buscaEmLargura(int vertice) {
  int i;
  int no;

  v[vertice] = 1;
  queue<int> fila;
  fila.push(vertice);
  while (!fila.empty()) {
    no = fila.front();
    fila.pop();
    printf("\n%1d - %s ", no, num_letra(no));
    for (int i = vertice; i< tam; i++) {

      if (G[no][i] == 0) {
        if (v[i] == 0) {
          fila.push(i);
          v[i] = 1;
        }
      }
    }
  }
}

void buscaEmLarguraComDestino(int origem, int destino) {
  int i;
  int no;
  int destinoEncontrado;

  if (origem == destino) {
    printf("\n%1d - %s ", no, num_letra(no));
  } else {

    v[origem] = 1;
    queue<int> fila;
    fila.push(origem);

    while (!fila.empty()) {
      no = fila.front();

      if (no == destino) {
        printf("\n%1d - %s ", no, num_letra(no));
        break;
      }

      fila.pop();
      printf("\n%1d - %s ", no, num_letra(no));
      for (i = origem; i < tam; i++) {

        if (G[no][i] == 0) {
          if (v[i] == 0) {
            fila.push(i);
            v[i] = 1;
          }
        }
      }
    }
  }
}

void zeraVetorVisitados() {
  for (int count=0; count<tam; count++) {
    v[count] = 0;
  }
}

void printLegenda() {
  system("cls");
  printf("Legendas dos estados do M?xico\n");
  printf("0 = baja california sur\t");
  printf("1 = baja california\t");
  printf("2 = sonnara\t");
  printf("3 = chihuahua\t");
  printf("4 = sinalua\t");
  printf("5 = coahuila\t");
  printf("6 = durango\t");
  printf("7 = nuevo le?o\t");
  printf("8 = tamaulipas\t");
  printf("9 = nagarit\t");
  printf("10 = zacatecas");
  printf("11 = san luis patosi\t");
  printf("12 = aguascalientes\t");
  printf("13 = jalisco\t");
  printf("14 = guanajuato\t");
  printf("15 = queretaro\t");
  printf("16 = hidalgo\t");
  printf("17 = veracruz\t");
  printf("18 = colima\t");
  printf("19 = michoacan\t");
  printf("20 = estado de m?xico\t");
  printf("21 = distrito federal ( mexico city)\t");
  printf("22 = Tlaxcala\t");
  printf("23 = Guerrero\t");
  printf("24 = Morelos\t");
  printf("25 = Puebla\t");
  printf("26 = Daxaca\t");
  printf("27 = Tabasco\t");
  printf("28 = Chiapas");
  printf("29 = Campeche");
  printf("30 = Yucat?n\t");
  printf("31 = Quintana Roo\t");
}

void escolhaUmaBusca() {
  zeraVetorVisitados();
  fflush(stdin);
  system("cls");
  printf("1 - Busca em profundidade\n");
  printf("2 - Busca em largura\n");
  printf("0 - Voltar ao menu principal");
}

int menuBuscaComDestino() {
  int opc;
  fflush(stdin);
  system("cls");
  printf("\n1 - Busca com destino ");
  printf("\n2 - Lista todos os estados usando a busca escolhida\n");
  scanf("%d", &opc);

  return opc;
}

void obtemOrigemDestino(int *origem, int *destino) {
  fflush(stdin);
  printLegenda();

  printf("\n\nDe acordo com os c?digos de estados acima digite as informa??es a seguir");

  printf("\nC?digo do estado de origem: ");
  scanf("%d", &*origem);
  fflush(stdin);

  printf("\nC?digo do estado de destino: ");
  scanf("%d", &*destino);
}

int grafo_pesos[tam][tam] = {
  0, 558, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  558, 0, 436, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 436, 0, 711, 782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 711, 0, 764, 620, 635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 782, 764, 0, 0, 550, 0, 0, 450, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 620, 0, 0, 456, 500, 0, 0, 552, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 635, 550, 456, 0, 0, 0, 335, 325, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 500, 0, 0, 256, 0, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 450, 0, 335, 0, 0, 0, 200, 0, 0, 187, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 552, 325, 0, 0, 200, 0, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 345, 0, 0, 0, 0, 0, 0, 0, 90, 175, 442, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 145, 0, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 187, 0, 0, 136, 0, 215, 0, 0, 0, 207, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 215, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0, 80, 0, 124, 0, 0, 95, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 175, 0, 0, 0, 124, 0, 345, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 315, 0, 0, 442, 0, 0, 0, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 234, 278, 456, 783, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 154, 0, 95, 0, 0, 345, 0, 329, 0, 0, 456, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87, 125, 0, 0, 329, 0, 50, 67, 60, 45, 98, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 456, 60, 0, 0, 0, 0, 0, 236, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0, 98, 0, 0, 0, 0, 0, 345, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 278, 0, 0, 0, 0, 0, 236, 0, 345, 0, 0, 578, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 256, 135, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0, 0, 0, 0, 0, 578, 256, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 135, 0, 0, 245, 167,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245, 0, 128,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 167, 128, 0,
};

void dijkstra(int origem, int destino) {
  int dist[tam], custo [tam][tam], ant[tam];
  int i, j, count, mindist, prox;
  
  for (i = 0; i < tam; i++) {
    for(j = 0; j < tam; j++) {
      if (grafo_pesos[i][j] == 0) {
        custo[i][j] = 10000;
      } else {
        custo[i][j] = grafo_pesos[i][j];
      }
    }
  }
  
  for (i = 0; i < tam; i++) {
    dist[i] = custo[origem][i];
    ant[i] = origem;
  }
  
  dist[origem] = 0;
  v[origem] = 1;
  count = 1;
  
  while (count < tam -1) {
    mindist = 10000;
    for (i = 0;i < tam; i++) {
      if (dist[i] < mindist && !v[i]) {
        mindist = dist[i];
        prox = i;
      }
    }
    
    v[prox] = 1;
    
    for (i =0; i < tam; i++) {
      if (!v[i]) {
        if ((mindist + custo[prox][i]) < dist[i]) {
          dist[i] = mindist + custo[prox][i];
          ant[i] = prox;
        }
      }
    }
    
    count++;
    
  }
  
  for (i = 0; i< tam; i++) {
    if (i != origem) {
      printf("o custo dos n? ? %d\n", dist[i]);
      printf("O caminho ?: %s", num_letra(i));
      j = i;
      do {
        j = ant[j];
        printf("<-%s", num_letra(j));
        
      } while(j != origem);
    }
    
    printf("\n");
    if (i == destino) break;
  }
  
  
} 

void obras() {
  system("cls");
  int origem;
  int destino;

  obtemOrigemDestino(&origem, &destino);
  if (G[origem][destino] == 1) {
    G[origem][destino] = 0;
    G[destino][origem] = 0;
    grafo_pesos[origem][destino] = 0;
    grafo_pesos[destino][origem] = 0;
    printf("\nRodovia colocada em obra com sucesso");
  } else {
    printf("\nRodovia n?o existe ou j? se encontra em obras");
  }

  printf("\nPressione enter para prosseguir");
  getch();
}

void menu() {
  fflush(stdin);
  system("cls");
  printf("1 - Mostrar legenda de cidades.\n");
  printf("2 - Realize uma busca\n");
  printf("3 - Marque uma obra\n");
  printf("4 - Busca com algoritmo Dijkstra\n");
  printf("0 - Encerre o programa");

}


int main() {
  int escolhaMenu = 10;
  int escolhaBuscas = 10;
  setlocale(LC_ALL, "Portuguese");

  while(escolhaMenu != 0) {
    menu();

    printf("\n");
    scanf("%d",&escolhaMenu);

    if (escolhaMenu == 1) {
      printLegenda();
      getch();
    }

    if (escolhaMenu == 2) {
      while (escolhaBuscas != 0) {
        zeraVetorVisitados();
         escolhaUmaBusca();
          printf("\n");
          scanf("%d", &escolhaBuscas);

          if (escolhaBuscas == 1) {
            int opcBuscaDestino = menuBuscaComDestino();

            if (opcBuscaDestino == 1) {
              int origem = 0;
              int destino = 0;
              obtemOrigemDestino(&origem, &destino);

              buscaEmProfundidadeComDestino(origem, destino);
            } else {
              buscaEmProfundidade(0);
            }
            printf("\nAperte enter para continuar.");
            getch();
          }

          if (escolhaBuscas == 2) {
            int opcBuscaDestino = menuBuscaComDestino();

            if (opcBuscaDestino == 1) {
              int origem;
              int destino;
              obtemOrigemDestino(&origem, &destino);
              buscaEmLarguraComDestino(origem, destino);
            } else {
              buscaEmLargura(0);
            }
            printf("\nAperte enter para continuar.");
            getch();
          }
      }

      escolhaBuscas = 10;
    }

    if (escolhaMenu == 4) {
      zeraVetorVisitados();
      int origem;
      int destino;
      obtemOrigemDestino(&origem, &destino);
      dijkstra(origem, destino);
      getch();
    }

    if (escolhaMenu == 3) {
      obras();
    }
  }
}
