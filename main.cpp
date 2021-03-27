#include <stdio.h>
#include <queue>

using namespace std;

const int tam = 11;

// Matriz de ajacencia de 4 linhas 4 colunas
int G[tam][tam] = {
//  A  B  C  D  E  F  G  H  I  J  K
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

// Vetores visitados
int v[tam];

char num_letra(int num) {
  switch(num) {
    case 0: return 'A';
    case 1: return 'B';
    case 2: return 'C';
    case 3: return 'D';
    case 4: return 'E';
    case 5: return 'F';
    case 6: return 'G';
    case 7: return 'H';
    case 8: return 'I';
    case 9: return 'J';
    case 10: return 'K';
    default: return ' ';
  }
}

// Busca em profundidade
void DFS(int vertice) {
  v[vertice] = 1;
  printf(" %c ", num_letra(vertice));
  for (int column = vertice; column < tam; column++) {
    if (G[vertice][column]==0) {
      if (v[column] == 0) {
        DFS(column);
      }
    }
  }
}

void BFS(int vertice) {
  int i;
  int no;

  v[vertice] = 1;
  queue<int> fila;
  fila.push(vertice);
  while (!fila.empty()) {
    no = fila.front();
    fila.pop();
    printf(" %1c ", num_letra(no));
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

void zeraVetorVisitados() {
  for (int count=0; count<tam; count++) {
    v[count] = 0;
  }
}


int main() {
  const int raiz = 0;
  printf("Busca em profundidade");
  zeraVetorVisitados();
  DFS(raiz);

  printf("\n\n\nBusca em largura");
  zeraVetorVisitados();
  BFS(raiz);
}