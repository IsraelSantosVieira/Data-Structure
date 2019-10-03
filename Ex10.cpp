#include <iostream>

using namespace std;

class noh {
    friend class fila;
    private:
        int dado; // poderia ser outro tipo de variável
        noh* prox;
};

// fila dinamicamente encadeada
class fila {
    private:
        noh* primeiro;
        noh* ultimo;
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
        int espia(); // espia o primeiro elemento da fila
        bool vazia();
        void limpaFila(); // limpa a fila
};

fila::fila() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

fila::~fila() { // idêntica à limpaFila, mas sem impressão
    while (primeiro != NULL) {
        desenfileira();
    }
}

void fila::enfileira(int d) {
    // primeiro criamos o novo nó
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = NULL;
    if (ultimo != NULL) {
        ultimo->prox = temp;
    }
    ultimo = temp;
    if (vazia()) {
        primeiro = temp;
    }    
    tamanho++; 
}

int fila::desenfileira() {
    int removido;
    noh* temp;
    removido = primeiro->dado;
    temp = primeiro;
    primeiro = primeiro->prox;
    if (vazia()){
        ultimo = NULL;
    }
    delete temp;
    tamanho--;
    return removido;    
}

int fila::espia(){
    return primeiro->dado;
}

void fila::limpaFila(){
    while (primeiro != NULL) {
        desenfileira();
    }
}
    
bool fila::vazia() {
    return (primeiro == NULL);
}


int main() {
    fila fila1;
    fila fila2;
    fila filaResult;
    int tamFila1;
    int tamFila2;
    int card;
    
    cin >> tamFila1;
    
    for(int i = 0; i < tamFila1; i++){
        cin >> card;
        fila1.enfileira(card);
    }
    
    cin >> tamFila2;
    
    for(int i = 0; i < tamFila2; i++){
        cin >> card;
        fila2.enfileira(card);
    }
    
    int ultimoInserido = -1;
    bool check = false;
    
    while(!fila1.vazia() and !fila2.vazia()){
        int dado = fila1.espia();
        int dado2 = fila2.espia();
        
        if(dado < dado2){
            filaResult.enfileira(dado);
            fila1.desenfileira();
            ultimoInserido = dado;
        }
        else if(dado > dado2){
            filaResult.enfileira(dado2);
            fila2.desenfileira();
            ultimoInserido = dado2;
        }
        else{
            fila2.desenfileira();
        }
        check = true;
    }
    
    if(!fila1.vazia()){
        while(!fila1.vazia()){
            int dado = fila1.desenfileira();
            if(!check){
                filaResult.enfileira(dado);
                ultimoInserido = dado;
                check = true;
            }
            else if(dado != ultimoInserido){
                filaResult.enfileira(dado);
                ultimoInserido = dado;
            }
        }
    }
    else if(!fila2.vazia()){
        while(!fila2.vazia()){
            int dado = fila2.desenfileira();
            if(!check){
                filaResult.enfileira(dado);
                ultimoInserido = dado;
                check = true;
            }
            else if(dado != ultimoInserido){
                filaResult.enfileira(dado);
                ultimoInserido = dado;
            }
        }
    }
    
    while(!filaResult.vazia()){
        cout << filaResult.desenfileira() << ' ';
    }
    
    return 0;
}
