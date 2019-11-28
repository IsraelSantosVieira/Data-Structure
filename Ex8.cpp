/* Classe fila em pilhas, uma fila implementada usando simulação em pilha 
 * 
 * by Joukim, 2017, Estruturas de Dados
 * 
 */

#include <iostream>

using namespace std;

class noh {
friend class pilha;
private:
    int dado; // poderia ser outro tipo de variável
    noh* prox;
};

// pilha dinamicamente encadeada
class pilha {
private:
    noh* topo;
    int tamanho;
    
public:
    pilha();
    ~pilha();
    void push(int d) { empilha(d); }
    void empilha(int d);
    int pop() { return desempilha(); } 
    int desempilha(); // retorna o topo da pilha
    int espia(); // espia o topo da pilha
    bool vazia();
    void limpaPilha(); //limpa a pilha    
};


pilha::pilha() {
    tamanho = 0;
    topo = NULL;
}

pilha::~pilha() { // idêntica à limpaPilha, mas sem impressão
    while (topo != NULL) {
        desempilha();
    }
}

void pilha::empilha(int d) {
    // primeiro criamos o novo nó
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = topo;
    topo = temp;
    tamanho++;    
}

int pilha::desempilha() {
    int removido;
    noh* temp;
    removido = topo->dado;
    temp = topo;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return removido;    
}

int pilha::espia(){
    return topo->dado;
}

void pilha::limpaPilha(){
    while (topo != NULL) {
        cout << desempilha() << endl;
    }
}
    
bool pilha::vazia() {
    return (topo == NULL);
}


// fila implementada em pilha
class fila {
private:
    pilha p1;
    pilha p2;
    int tamanho;    
public:
    fila();
    ~fila();
    void enqueue(int d) { enfileira(d); }
    void insere(int d) { enfileira(d); }
    void enfileira(int d); // insere no final da fila
    int dequeue() { return desenfileira(); } 
    int retira() { return desenfileira(); } 
    int desenfileira(); // retorna o primeiro elemento da fila
    bool vazia();
    void limpaFila(); //limpa a pilha  
    int getTamanho();  
};


fila::fila() {
    tamanho = 0;
}

fila::~fila() { // idêntica à limpaFila, mas sem impressão
    while (tamanho != 0) {
        desenfileira();
    }
}

void fila::enfileira(int d) {
/* perdida nos mares do sul */
    p1.empilha(d);
    tamanho++;
}


int fila::desenfileira() {
/* perdida nos mares do norte */
    if(p2.vazia()){
        for(int i = 0; !p1.vazia(); i++){
            p2.empilha(p1.desempilha());
        }
    }
    
    int dado = p2.desempilha();
    tamanho--;
    return dado;
}


void fila::limpaFila(){
    while (tamanho != 0) {
        cout << desenfileira() << endl;
    }
}
    
bool fila::vazia() {
    return (tamanho == 0);
}
  
int fila::getTamanho() {
    return tamanho;
}
    
int main() {
    fila f1;
    
    int num;
    int valor;
    
    // enfileira num elemntos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cin >> valor;
        f1.enfileira(valor);
    }
    
    // desenfileira num elementos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cout << f1.desenfileira() << " ";
    }
    cout << endl;
    
    // enfileira num elemntos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cin >> valor;
        f1.enfileira(valor);
    }

    // desenfileira num elementos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cout << f1.desenfileira() << " ";
    }
    cout << endl;
    
    // desenfileira num elementos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cout << f1.desenfileira() << " ";
    }
    cout << endl;    

    // imprime o tamanho
    cout << f1.getTamanho() << endl;

    return 0;
}
