/* Classe fila, um fila (FIFO) implementada usando encadeamento
 * 
 * by Joukim, 2017, Estruturas de Dados
 * adaptada por Valéria, 2018
 */

#include <iostream>

using namespace std;

class noh {
	friend class fila;
	private:
		int dado; // poderia ser outro tipo de variável
		noh* prox;
};

// pilha dinamicamente encadeada
class fila {
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanho;
    
	public:
		fila();
		fila(const fila& umaFila);
		~fila();
		void insere(int d) { enfileira(d); }
		void enfileira(int d); // insere no final da fila 
		int desenfileira(); // retorna o primeiro elemento da fila
		int espia(); // espia o primeiro elemento da fila
		bool vazia();
		void imprime();  
		fila operator+(const fila& umaFila) const;
                fila& operator=(const fila& umaFila);
};

fila::fila() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

fila::~fila() { 
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
    
bool fila::vazia() {
    return (primeiro == NULL);
}

void fila::imprime(){
    noh* temp = primeiro;
    while (temp != NULL) {
	cout << temp->dado << " ";
        temp = temp->prox;
    }
    cout << endl;
}

//mesclar filas
fila fila::operator+(const fila& umaLista) const {
	// IMPLEMENTAR
    noh* primeiraFila = primeiro;
    noh* segundaFila = umaLista.primeiro;
    fila novaFila;
    while(primeiraFila != NULL and segundaFila != NULL){
        if(primeiraFila -> dado < segundaFila -> dado){
            novaFila.insere(primeiraFila -> dado);
            primeiraFila = primeiraFila -> prox;
        }
        else{
            novaFila.insere(segundaFila -> dado);
            segundaFila = segundaFila -> prox;
        }
    }
    
    if(primeiraFila != NULL){
        while(primeiraFila != NULL){
            novaFila.insere(primeiraFila -> dado);
            primeiraFila = primeiraFila -> prox;
        }
    }
    else if(segundaFila != NULL){
        while(segundaFila != NULL){
            novaFila.insere(segundaFila -> dado);
            segundaFila = segundaFila -> prox;
        }
    }
    
    return novaFila;

}

// sobrecarga do operador de atribuição
fila& fila::operator=(const fila& umaFila){
	// IMPLEMENTAR
    while (primeiro != NULL) {
        desenfileira();
    }
    
    noh* aux = umaFila.primeiro;
    
    while(aux != NULL){
        insere(aux -> dado);
        aux = aux -> prox;
    }
    
    return *this;
}

// construtor de cópia
fila::fila(const fila& umaFila) {
	// IMPLEMENTAR
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
    noh* aux = umaFila.primeiro;
    
    while(aux != NULL){
        insere(aux -> dado);
        aux = aux -> prox;
    }
}

int main() {
    fila filaA;
    fila filaB;
    string opcao;
    int dado;
    char idFila;
    do {
        cin >> opcao;
        if (opcao == "i") {
            cin >> idFila >> dado;
            if (idFila == 'a')
                filaA.enfileira(dado);
            else
                filaB.enfileira(dado);
        }
 	else if (opcao == "a=b") {
            filaA = filaB;
        }
        else if (opcao == "b=a") {
            filaB = filaA;
        }
        else if (opcao == "s") {
            fila filaM = filaA + filaB;
            filaM.imprime();
        }
        else if (opcao == "e") {
            cin >> idFila;
            if (idFila == 'a')
                filaA.imprime();
            else
                filaB.imprime();
        }
    } while (opcao != "t");
    return 0;
}
