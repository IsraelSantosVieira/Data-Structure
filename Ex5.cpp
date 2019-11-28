#include <iostream>

typedef int Dado;

class Noh {
    friend class Fila;
    private:
        Dado mDado;
        Noh* mPtProx;
};

class Fila {
    public:
        // Constroi uma fila vazia.
        Fila();
        // Desaloca memória de todos os nós da fila.
        ~Fila();
        // Remove e retorna o primeiro item da fila.
        Dado Remover();
        // Insere um item no final da fila.
        void Inserir(const Dado& d);
        // Retorna o primeiro item da fila sem remover.
        Dado Proximo() const;
        // Remove todos os itens da fila.
        void LimparTudo();
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila está vaiza.
        bool Vazia() const;
    private:
        Noh* mPrimeiro;
        Noh* mUltimo;
        unsigned mTamanho;
};

using namespace std;

Fila::Fila() {
    mPrimeiro = NULL;
    mUltimo = NULL;
    mTamanho = 0;
}

Fila::~Fila() {
    LimparTudo();
}

void Fila::Inserir(const Dado& d) {
    Noh* newValor = new Noh();
    newValor -> mDado = d;
    if(Vazia()){
        mPrimeiro = newValor;
        mUltimo = newValor;
    }
    else{
        newValor -> mPtProx = mUltimo;
        mUltimo = newValor;
    }
    mTamanho++;
}

Dado Fila::Remover() {
    if(Vazia()){
        cerr << "ERRO" << endl;
        return 0;
    }
    
    Noh* auxiliar = mPrimeiro;
    Dado removido = auxiliar -> mDado;
    if(mTamanho == 1){
        delete mPrimeiro;
        mPrimeiro = NULL;
        mUltimo = NULL;
        mTamanho--;
        return removido;
    }
    else{
        Noh* ultimo = mUltimo;
        for(unsigned int i = 0; i < mTamanho - 2; i++){
            ultimo = ultimo -> mPtProx;
        }
        ultimo -> mPtProx = NULL;
        delete mPrimeiro;
        mPrimeiro = ultimo;
        mTamanho--;
        return removido;
    }
}

Dado Fila::Proximo() const {
    return mPrimeiro -> mDado;
}

void Fila::LimparTudo() {
    Noh* iterar = mPrimeiro;
    Noh* proximo = NULL;
    while(iterar != NULL){
        proximo = iterar -> mPtProx;
        delete iterar;
        iterar = proximo;
    }
    mTamanho = 0;
    mPrimeiro = NULL;
    mUltimo = NULL;
}

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

int main() {
    Fila fila;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                fila.Inserir(valor);
                break;
            case 'r': // remover
                cout << fila.Remover() << endl;
                break;
            case 'l': // limpar tudo
                fila.LimparTudo();
                break;
            case 't': // escrever tamanho
                cout << fila.Tamanho() << endl;
                break;
            case 'e': // espiar proximo
                cout << fila.Proximo() << endl;
                break;
            case 'f': // finalizar
                // vai verificar adiante
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    while (not fila.Vazia()) {
        cout << fila.Remover() << ' ';
    }
    cout << endl;
    return 0;
}
