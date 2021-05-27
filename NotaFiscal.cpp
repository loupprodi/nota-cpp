#include <iostream>
#include <string>
using namespace std;

class Peca
{
	public:
		Peca(string numeroPeca, string descricaoPeca, int quantidadeComprada, double precoUnitario){
			this->numeroPeca = numeroPeca;
			this->descricaoPeca = descricaoPeca;
			this->quantidadeComprada = quantidadeComprada;
			this->precoUnitario = precoUnitario;
		}		
		string getNumeroPeca(){
			return numeroPeca;
		}
		void setNumeroPeca(string numeroPeca){
			this->numeroPeca = numeroPeca;
		}
		string getDescricaoPeca(){
			return descricaoPeca;
		}
		void setDescricaoPeca(string descricaoPeca){
			this->descricaoPeca = descricaoPeca;
		}
		int getQuantidadeComprada(){
			return quantidadeComprada;
		}
		void setQuantidadeComprada(int quantidadeComprada){
			this->quantidadeComprada = quantidadeComprada;
		}
		double getPrecoUnitario(){
			return precoUnitario;
		}
		void setPrecoUnitario(double precoUnitario){
			this->precoUnitario = precoUnitario;
		}
	private:
		string numeroPeca;
		string descricaoPeca;
		int quantidadeComprada;
		double precoUnitario;
};

class NotaFiscal
{
	public:		
		NotaFiscal(){
			quantidadePecas=0;
		}
		void addPeca(Peca p1){
			if(quantidadePecas<5){
				listaPecas[quantidadePecas]=&p1;
				quantidadePecas++;
			}
			else
				cout<<"Nota Fiscal cheia"<<endl;
		}
		double getTotalNota(){
			double total=0;
			for(int i=0;i<quantidadePecas;i++){
				total=total + (listaPecas[i]->getPrecoUnitario()*listaPecas[i]->getQuantidadeComprada());
			}
			return total;				
		}
		void exibeNota(){
			for(int i=0;i<quantidadePecas;i++){
				cout<<listaPecas[i]->getNumeroPeca()<<" "<<listaPecas[i]->getDescricaoPeca()<<" ";
				cout<<listaPecas[i]->getPrecoUnitario()<<" "<<listaPecas[i]->getQuantidadeComprada()<<endl;
			}
			cout<<"Total da Nota: "<<getTotalNota()<<endl;
		}
		void removeUltimaPeca(){
			if(quantidadePecas>0)
				quantidadePecas--;
		}
	private:
		int quantidadePecas;
		Peca* listaPecas[5];
};

int main()
{
	NotaFiscal n1= NotaFiscal();
	Peca p1 = Peca("1234", "Parafuso", 5, 6.50);
	Peca p2 = Peca("1235", "Porca", 5, 2);
	Peca p3 = Peca("1236", "Prego", 10, 0.5);
	Peca p4 = Peca("1237", "Arruela", 10, 0.75);
	Peca p5 = Peca("1238", "Bucha", 5, 2.20);
	Peca p6 = Peca("1239", "Broca", 1, 20);
	n1.addPeca(p1);
	n1.addPeca(p2);
	n1.addPeca(p3);
	n1.addPeca(p4);
	n1.addPeca(p5);
	n1.addPeca(p6);
	n1.exibeNota();
	n1.removeUltimaPeca();
	n1.addPeca(p6);
	n1.exibeNota();
	return 0;
}