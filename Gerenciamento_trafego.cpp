#include <iostream>
#include <cstring>

#define max 1000

using namespace std;

void fflush_stdin(){//limpar o buffer do teclado
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
}

typedef struct{
	string nome;
	bool tipo;//false - carga| true- passeio
	string federacao;
	int n_passageiros;
	int ano;
	int faixaetaria[50];	
}carro;

int main(){
	
	carro rodovia[max];
	int qtd_carros = 0, i, j, x, finder, l, k, variavel, comp, intvec[max], v1, v2, v3, v4;
	char escolha, auxiliar;
	string alter, vef, vec[max], auxer;
	float f;
	bool flag;
	
	while(1){
		system("cls");
		cout << "1)Cadastrar veiculo\n";
		cout << "2)Alterar veiculo\n";
		cout << "3)Excluir veiculo\n";
		cout << "4)Informativo sobre percentual\n";
		cout << "5)Relatorios\n";
		cout << "0)Fechar programa\n";
		cout << "Opcao: ";
		cin >> escolha;
		
		if(escolha == '0'){
			return 0;
		}
		
		if(escolha == '1'){
			system("cls");
			while(1){
				flag = false;
				cout << "Nome do veiculo: ";
				cin.ignore();
				getline(cin, auxer);
				for(i = 0; i < qtd_carros; i++){
					if(auxer == rodovia[i].nome){
						cout << "Nome ja cadastrado, diferencie usando letras ou numeros\n";
						flag = true;
						system("pause");
					}
				}
				if(flag){
					break;
				}
				rodovia[qtd_carros].nome = auxer;
				cout << "Tipo do veiculo(0 - carga|1 - passeio): ";
				cin >> auxiliar;
				if(auxiliar == '0'){
					rodovia[qtd_carros].tipo = false;
				}
				else if(auxiliar == '1'){
					rodovia[qtd_carros].tipo = true;
				}
				else{
					system("cls");
					cout << "Caractere invalido!";
					system("pause");
					break;
				}
				cout << "Estado da Federacao de origem: ";
				cin.ignore();
				getline(cin, rodovia[i].federacao);
				cout << "Ano de fabricacao do veiculo(apenas numeros): ";
				cin >> rodovia[qtd_carros].ano;
				cout << "Quantidade de passageiros(apenas numeros): ";
				cin >> rodovia[qtd_carros].n_passageiros;
				if(rodovia[qtd_carros].tipo){
					cout << "Defina a faixa etaria dos passageiros(1-crianca|2-adolescente|3-adulto|4-idoso)\n";
					for(i = 0; i < rodovia[qtd_carros].n_passageiros; i++){
						cout << "Passageiro " << i + 1 << ": ";
						cin >> rodovia[qtd_carros].faixaetaria[i];
					}
				}
				system("cls");
				qtd_carros++;
				cout << "Cadastro realizado com sucesso\n";
				system("pause");
				break;
				fflush_stdin();
			}
		}
		if(escolha == '2'){
			cout << "Qual veiculo deseja alterar? ";
			cin >> alter;
			flag = false;
			for(i = 0; i < qtd_carros; i++){
				if(alter == rodovia[i].nome){
					flag = true;
					system("cls");
					cout << "Veiculo: " << rodovia[i].nome << "\n";
					cout << "1)Alterar nome do cadastro\n";
					cout << "2)Alterar tipo do veiculo\n";
					cout << "3)Alterar estado da federacao\n";
					cout << "4)Alterar ano de fabricacao\n";
					cout << "5)Alterar quantidade de passsageiros\n";
					cout << "0)Voltar\n";
					cout << "Opcao: ";
					cin >> escolha;
					if(escolha == '0'){
						break;
					}
					if(escolha == '1'){
						cout << "Insira o novo nome: ";
						flag = false;
						cin.ignore();
						getline(cin, auxer);
						for(j = 0; j < qtd_carros; j++){
							if(auxer == rodovia[j].nome){
								cout << "Nome ja cadastrado, diferencie usando letras ou numeros\n";
								flag = true;
								system("pause");
							}
						}
						if(flag){
							break;
						}
					}
					
					if(escolha == '2'){
						system("cls");
						cout << "Tipo do veiculo(0 - carga|1 - passeio): ";
						cin >> auxiliar;
						if(auxiliar == '0'){
							rodovia[i].tipo = false;
							break;
						}
						else if(auxiliar == '1'){
							rodovia[i].tipo = true;
							cout << "Atual quantidade de passageiros(ultima registrada eh " << rodovia[i].n_passageiros <<"): ";
							cin >> rodovia[i].n_passageiros;
							cout << "Defina a faixa etaria dos passageiros(1-crianca|2-adolescente|3-adulto|4-idoso)\n";
							for(j = 0; j < rodovia[i].n_passageiros; j++){
								cout << "Passageiro " << j + 1 << ": ";
								cin >> rodovia[i].faixaetaria[j];
							}
							break;
						}
						else{
							system("cls");
							cout << "Caractere invalido!\n";
							system("pause");
							break;
						}
					}
					if(escolha == '3'){
						cout << "Estado da Federacao de origem: ";
						cin.ignore();
						getline(cin, rodovia[i].federacao);
						break;
					}
					if(escolha == '4'){
						cout << "Ano de fabricacao do veiculo(apenas numeros): ";
						cin >> rodovia[i].ano;
						break;
					}
					if(escolha == '5'){
						cout << "Quantidade de passageiros(apenas numeros): ";
						cin >> rodovia[i].n_passageiros;
						cout << "Defina a faixa etaria dos passageiros(1-crianca|2-adolescente|3-adulto|4-idoso)\n";
						for(j = 0; j < rodovia[j].n_passageiros; j++){
							cout << "Passageiro " << j + 1 << ": ";
							cin >> rodovia[i].faixaetaria[j];
						}
						break;
					}
				}
			}
			if(!flag){
				cout << "Carro nao encontrado!\n";
				system("pause");
			}
			fflush_stdin();
		}
		if(escolha == '3'){
			system("cls");
			cout << "Qual carro deseja excluir?";
			cin >> alter;
			for(i = 0; i < qtd_carros; i++){
				if(alter == rodovia[i].nome){
					for(j = i; j < (qtd_carros - 1); j++){
						rodovia[j] = rodovia[j+1];
					}
					qtd_carros--;
					cout << "Carro excluido!\n";
					system("pause");
					break;
				}
			}
			cout << "Carro nao encontrado\n";
			system("pause");			
		}
		if(escolha == '4'){
			x = 0;
			for(i = 0; i < qtd_carros; i++){
				if(rodovia[i].tipo){
					x++;
				}
			}
			system("cls");
			f = (float(qtd_carros - x) / qtd_carros) * 100.0;
			cout.precision(2);
			cout << fixed;
			cout << "Veiculos de carga: " << f << "\n";
			f = ((float(x)/ qtd_carros) * 100.0 );
			cout.precision(2);
			cout << fixed;
			cout << "Veiculos de passeio: " << f << "\n";
			system("pause");
		}
		if(escolha == '5'){
			system("cls");
			fflush_stdin();
			cout << "a)Listagem de todos os veiculos cadastrados\n";
			cout << "b)Listagem de veiculos por estados de origem\n";
			cout << "c)Quantidade de veiculos por estado de origem\n";
			cout << "d)Quantidade de veiculos por ano de fabricacao\n";
			cout << "e)Quantidade de usuarios que trafegam pela rodovia, por faixa etaria\n";
			cin >> escolha;
			if(escolha == 'a'){
				fflush_stdin();
				for(i = 0; i < qtd_carros; i++){
					cout << rodovia[i].nome << "\n";
				}
				system("pause");
			}
			if(escolha == 'b'){
				cout << "Escolha o estado de origem: ";
				cin >> alter;
				for(i = 0; i < qtd_carros; i++){
					if(alter == rodovia[i].federacao){
						cout << rodovia[i].nome << "\n";
					}
				}
				system("pause");
			}
			if(escolha == 'c'){
				for(i = 0; i < max; i++){
					vec[i] = '0';
				}
				variavel = qtd_carros;
				l = 0;
				x = 0;
				finder = 0;
				for(i = 0; i < qtd_carros; i++){
					vef = rodovia[i].federacao;
					for(j = i; j < qtd_carros; j++){
						if((vef == rodovia[j].federacao) && (finder == 0)){
							for(k = 0; k < qtd_carros; k++){
								if(vec[k] == vef){
									finder = 1;
									variavel = variavel - 1;
								}
							}
							if(finder == 0){
								x++;
							}
						}
					}
					vec[l] = vef;
					l++;
					if(x != 0){
						cout << "Federacao: " << vef << " Veiculos: " << x << "\n";
					}					
					x = 0;
					finder = 0;
				}
				system("pause");
			}
			if(escolha == 'd'){
				for(i = 0; i < max; i++){
					intvec[i] = 0;
				}
				variavel = qtd_carros;
				l = 0;
				x = 0;
				finder = 0;
				for(i = 0; i < qtd_carros; i++){
					comp = rodovia[i].ano;
					for(j = i; j < qtd_carros; j++){
						if((comp == rodovia[j].ano) && (finder == 0)){
							for(k = 0; k < qtd_carros; k++){
								if(intvec[k] == comp){
									finder = 1;
									variavel = variavel - 1;
								}
							}
							if(finder == 0){
								x++;
							}
						}
					}
					intvec[l] = comp;
					l++;
					if(x != 0){
						cout << "Federacao: " << comp << " Veiculos: " << x << "\n";
					}					
					x = 0;
					finder = 0;
				}
				system("pause");
			}
			if(escolha == 'e'){
				v1 = 0;
				v2 = 0;
				v3 = 0;
				v4 = 0;
				for(i = 0; i < qtd_carros; i++){
					for(j = 0; j <= rodovia[i].n_passageiros; j++){
						if(rodovia[i].faixaetaria[j] == 1){
							v1++;
						}
						if(rodovia[i].faixaetaria[j] == 2){
							v2++;
						}
						if(rodovia[i].faixaetaria[j] == 3){
							v3++;
						}
						if(rodovia[i].faixaetaria[j] == 4){
							v4++;
						}
					}
				}
				cout << "Crianca: " << v1 << "\n";
				cout << "Adolescente: " << v2 << "\n";
				cout << "Adulto: " << v3 << "\n";
				cout << "Idoso: " << v4 << "\n";
				system("pause");
			}
		}	
	}
		
	return 0;
}
