#include <iostream>
#include <string>

typedef std::string TDado; // tipo do dado que será armazenado na pilha

class Noh {
    friend class Fila;
    public:
        Noh(const TDado& d, Noh* p = NULL) : dado(d), prox(p) {}
    private:
        TDado dado;
        Noh* prox;
};

class Fila {
    public:
        Fila();
        ~Fila();
        void Inserir(TDado d); // insere no final da fila
        TDado Remover(); // remove e retorna o primeiro elemento da fila
        bool Vazia();
    private:
        int tamanho;
        Noh* primeiro;
        Noh* ultimo;
};

using namespace std;

Fila::Fila() : tamanho(0), primeiro(NULL), ultimo(NULL) {
}

Fila::~Fila() {
    while (primeiro != NULL)
        Remover();
}

void Fila::Inserir(TDado d) {
    Noh* temp = new Noh(d);
    if (ultimo != NULL)
        ultimo->prox = temp;
    ultimo = temp;
    if (Vazia())
        primeiro = temp;
    ++tamanho;
}

TDado Fila::Remover() {
    TDado removido;
    Noh* temp;
    removido = primeiro->dado;
    temp = primeiro;
    primeiro = primeiro->prox;
    if (Vazia())
        ultimo = NULL;
    delete temp;
    --tamanho;
    return removido;
}

bool Fila::Vazia() {
    return primeiro == NULL;
}

int main() {
    Fila filaPrioritaria;
    Fila filaNormal;
    string comando;
    string cliente;
    
    cin >> comando;
    int iter = 0;
    
    while(comando != "fim"){
        if(comando == "normal"){
            cin >> cliente;
            filaNormal.Inserir(cliente);
        }
        else if(comando == "prioridade"){
            cin >> cliente;
            filaPrioritaria.Inserir(cliente);
        }
        else if(comando == "atender"){
            if(filaPrioritaria.Vazia() and filaNormal.Vazia())
                cout << "AGUARDE" << endl;
            else if(filaPrioritaria.Vazia()){
                cout << filaNormal.Remover() << endl;
                iter = 0;
            }
            else if(!filaPrioritaria.Vazia() and iter < 3){
                cout << filaPrioritaria.Remover() << endl;
                iter++;
            }
            else if(!filaNormal.Vazia() and iter >= 3){
                cout << filaNormal.Remover() << endl;
                iter = 0;
            }
            else{
                cout << filaPrioritaria.Remover() << endl;
            }
        }
        
        cin >> comando;
    }
    return 0;
}
