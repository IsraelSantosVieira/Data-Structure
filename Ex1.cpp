#include <iostream>
using namespace std;
typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
	private:
		int capacidade;
		Dado *dados;
		int tamanho;
		int posTopo;
	public:
		pilhav(int cap = 100);
        ~pilhav();
		void empilha(Dado valor);
		Dado desempilha();
		Dado espia(); // acessa elemento do topo, mas não retira
		void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
		void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav(int cap) : capacidade(cap){
	dados = new Dado[capacidade];
	posTopo = -1;
	tamanho = 0;
}

pilhav::~pilhav(){
	delete[] dados;
}

void pilhav::empilha(Dado valor){
	dados[posTopo + 1] = valor;
	posTopo++;
	tamanho++;
}

Dado pilhav::desempilha(){
	posTopo--;
	tamanho--;
	return dados[posTopo+1];
}

Dado pilhav::espia(){
	return dados[posTopo]; 
}

void pilhav::depura(){
	for(int i = 0; i < tamanho; i++){
		cout << dados[i] << ' ';
	}
}

void pilhav::info(){
	cout << tamanho << ' ' << posTopo << endl;
}

int main(){
	pilhav pilha(20);
	Dado value;
	for(int i = 0; i < 5; i++){
		cin >> value;
		pilha.empilha(value);
	}
	for(int i = 0; i < 3; i++){
		cout << pilha.desempilha() << ' ';
	}
	cout << endl;
	for(int i = 0; i < 4; i++){
		cin >> value;
		pilha.empilha(value);
	}
	for(int i = 0; i < 3; i++){
		cout << pilha.desempilha() << ' ';
	}
	cout << endl << pilha.espia() << endl;
	pilha.depura();
	cout << endl;
	pilha.info();
	
	return 0;
}
