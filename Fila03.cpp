#include <iostream>
#include <string>
using namespace std;

typedef char Dado;

class Noh{
    friend class Pilha;
    private:
        Noh* mPtProximo;
        Dado dado;
};

class Pilha{
    private:
        int mTamanho;
        Noh* mPosTopo;
    public:
        Pilha();
        ~Pilha();
        void empilha(Dado valor);
        Dado desempilha();
        int espia();
        bool Vazia() const;
        void depura();
};

Pilha::Pilha(){
    mTamanho = 0;
    mPosTopo = NULL;
}

Pilha::~Pilha(){
    while(mPosTopo != NULL){
        desempilha();
    }
}

void Pilha::empilha(Dado valor){
    Noh* temp = new Noh;
    temp -> dado = valor;
    temp -> mPtProximo = mPosTopo;
    mPosTopo = temp;
    mTamanho++;
}

Dado Pilha::desempilha(){
    if(mTamanho == 0){
        cout << "ERRO" << endl;
        return -1;
    }
    Dado removido = mPosTopo -> dado;
    Noh* temp = mPosTopo;
    mPosTopo = mPosTopo -> mPtProximo;
    delete temp;
    mTamanho--;
    return removido;
}

int Pilha::espia(){
    return mTamanho;
}

bool Pilha::Vazia() const {
    return (mPosTopo == NULL);
}

int main(){
    Pilha pilha;
    Pilha pilha2;
    string formula;
    bool valida = true;
    int debugIteration = 0;
    
    cin >> formula;
        
    for(unsigned int i = 0; i < formula.size() and valida; i++){
		if(formula[i] == 'A' or formula[i] == 'B' or formula[i] == 'C'){
			if(formula[i] == 'B'){
				debugIteration++;
			}
			else if(debugIteration == 0){
				if(formula[i] == 'A'){
					pilha.empilha('A');
					pilha2.empilha('C');
					pilha2.empilha('C');
				}
				else{
					valida = false;
				}
			}
			else if(debugIteration == 1){
				if(formula[i] == 'C' and !pilha2.Vazia()){
					pilha2.desempilha();
				}
				else{
					valida = false;
				}
			}
			else if(debugIteration == 2){
				if(formula[i] == 'A' and !pilha.Vazia()){
					pilha.desempilha();
				}
				else{
					valida = false;
				}
			}
		}
		else{
			valida = false;
		}
    }
    
    if(valida and pilha.Vazia() and pilha2.Vazia())
        cout << "sim";
    else
        cout << "nao";
        
    cout << " " << pilha.espia() << " ";
    cout << pilha2.espia();
    
    return 0;
}



