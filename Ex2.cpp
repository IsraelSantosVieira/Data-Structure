#include <iostream>

typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variÃ¡vel
        Noh* mPtProx;
};

class Pilha {
    public:
        // ConstrÃ³i pilha vazia.
        Pilha();
        // Destrutor que desaloca memÃ³ria.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se nÃ£o for possÃ­vel desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Informa quantos valores existem na pilha.
        unsigned Tamanho() { return mTamanho; }
        // Retorna o valor que estÃ¡ no mPtTopo sem desempilhar.
        Dado Topo() const;
        // Informa se a pilha estÃ¡ Vazia.
        bool Vazia() const;
    private:
        Noh* mPtTopo;
        unsigned mTamanho;
};

using namespace std;

Pilha::Pilha() {
	mPtTopo = NULL;
	mTamanho = 0;
}

Pilha::~Pilha() {
	while(mPtTopo != NULL)
		Desempilhar();
}

Dado Pilha::Desempilhar() {
	if(mTamanho == 0){
		cout << "ERRO" << endl;
		return -1;
	}
	Dado removido = mPtTopo -> mDado;
	Noh* temp = mPtTopo;
	mPtTopo = mPtTopo -> mPtProx;
	delete temp;
	mTamanho--;
	return removido;
}

void Pilha::Empilhar(const Dado& d) {
	Noh* temp = new Noh;
	temp -> mDado = d;
	temp -> mPtProx = mPtTopo;
	mPtTopo = temp;
	mTamanho++;
}

void Pilha::LimparTudo() {
	while(mPtTopo != NULL)
		Desempilhar();
}

Dado Pilha::Topo() const {
	return mPtTopo -> mDado;
}

bool Pilha::Vazia() const {
	return (mTamanho == 0);
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r': // remover
                cout << pilha.Desempilhar() << endl;
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 't': // consultar tamanho
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': // espiar
                cout << pilha.Topo() << endl;
                break;
            case 'f': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando invÃ¡lido\n";
        }
    } while (comando != 'f'); // finalizar execuÃ§Ã£o
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}
