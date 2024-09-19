#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

#define MaxAluno 10
#define MaxInstrutor 10
#define MaxCurso 10
#define MaxCidade 10
#define MaxTurma 10
#define MaxMatricula 10


struct Cidade{
	int codigo;
	string nome;
	string uf;
};

struct Curso{
	int codigo;
	string descricao;
	float valor_por_aula;
};

struct Instrutor{
	int codigo;
	string nome;
	string endereco;
	int codigo_cidade;
};

struct Aluno{
	int codigo;
	string nome;
	string endereco;
	int codigo_cidade;
};

struct Turma{
	int codigo;
	int codigo_curso;
	int codigo_instrutor;
	int total_participantes;
	int quant_max_participantes;
};

struct Matricula{
	int codigo;
	int codigo_aluno;
	int codigo_turma;
	int quantidade_aulas;
	float valor_total;
};


// FUNÇÕES CIDADE

void leitura_cidade(struct Cidade v[],int &contCidade){
	int i = 0;
	for(int saida = 1; saida != 0 && i < MaxCidade; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: ";
		cin>>v[i].codigo;
		cin.ignore();
		if(v[i].codigo > 0){
		cout<<"Nome: ";
		getline(cin, v[i].nome);
		cout<<"UF: ";
	    getline(cin, v[i].uf);
		}
		else saida = 0;
	}	
	
	if(i == MaxCidade){
            contCidade = i;
        }else contCidade = i - 1;
}

int busca_cidade (struct Cidade vetor[], int cod, int qtdRegistros){
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetor[m].codigo){
    	return m;

    } else return -1;
}


// FUNÇÕES CURSO

void leitura_curso(struct Curso v[], int &contCurso){
		int i = 0;
		
	for(int saida = 1; saida != 0 && i < MaxCurso; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: ";
		cin>>v[i].codigo;
		cin.ignore();
		if(v[i].codigo > 0){
		cout<<"Descricao: ";
		getline(cin, v[i].descricao);
		cout<<"Valor por Aula: ";
		cin>>v[i].valor_por_aula;
		cin.ignore();
		}
		else saida = 0;
	}	
	if(i == MaxCurso){
            contCurso = i;
        }else contCurso = i - 1;
}

int busca_curso(struct Curso vetor[], int cod, int qtdRegistros){
	 int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetor[m].codigo){
    	return m;

    } else return -1;
	
}

//FUNÇÕES INSTRUTOR

int verifica_instrutor(struct Instrutor vetor[], int cod, int qtdRegistros){
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;

    	for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        	if (cod > vetor[m].codigo)
            	i = m + 1;
       	 	else
            	f = m - 1;
    	}
    	
    	if(f != -1){
    	if (cod == vetor[m].codigo){
    		return 1;

    	}   else return -1;
    } 
    else  return -1;
}

int busca_instrutor(struct Instrutor vetor[], int cod, int qtdRegistros){
	 int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetor[m].codigo){
    	return m;

    } else return -1;
	
}

void leitura_instrutor(struct Instrutor NovoInst[], int &contInstrutorT, struct Instrutor InstCadastrados[], int contInstCadastrados, struct Cidade vetorCidade[], int qtdRegistrosCidade){
	int i=0;
	
	for(int saida = 1; i < MaxInstrutor && saida != 0; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		  for(int x = 1; x != -1;){
			cout<<"Codigo Instrutor: ";
			cin>>NovoInst[i].codigo;
			cin.ignore();
				if(NovoInst[i].codigo > 0){
					
					if( verifica_instrutor(NovoInst, NovoInst[i].codigo, i) != 1 && verifica_instrutor(InstCadastrados, NovoInst[i].codigo, contInstCadastrados) != 1){
						cout<<"Nome: ";
						getline(cin, NovoInst[i].nome);
						cout<<"Endereco: ";
						getline(cin,NovoInst[i].endereco);
			
						for(; x != -1;){
								cout<<"Codigo Cidade: ";
								cin>>NovoInst[i].codigo_cidade;
	
								int resultado = busca_cidade(vetorCidade, NovoInst[i].codigo_cidade, qtdRegistrosCidade);
				
							if(resultado != -1){
								cout<<"Cidade: " << vetorCidade[resultado].nome;
								cout<<"\tUF: " << vetorCidade[resultado].uf << endl;
								x = -1;
						
							}else{ cout<<"\n***Codigo de cidade invalido, digite novamente***\n\n"; }
						}
							
				}else {	cout<<"\n***Esse codigo ja existe. Digite outro codigo***\n\n"; }
				
			}else {  saida = 0;  x = -1;	}
		}

	}				
	if(i == MaxInstrutor){
            contInstrutorT = i;
            
        } else contInstrutorT = i - 1;
        
}

void incluir_instrutor(struct Instrutor S[], int contS, struct Instrutor T[], int contT, struct Instrutor A[], int &contA){
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigo_cidade = S[i].codigo_cidade;
            i++;
            }
        else {
           A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].codigo_cidade = T[j].codigo_cidade;
            j++;
        }
    }
    while (i < contS){
         A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].codigo_cidade = S[i].codigo_cidade;
        i++;
        k++;
    }
    while (j < contT){
         A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].codigo_cidade = T[j].codigo_cidade;
        j++;
        k++;
    }
    contA = k;
}

//FUNÇÕES ALUNO

int verifica_aluno(struct Aluno vetor[], int cod, int qtdRegistros){
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;

    	for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        	if (cod > vetor[m].codigo)
            	i = m + 1;
       	 	else
            	f = m - 1;
    	}
    	
    	if(f != -1){
    	if (cod == vetor[m].codigo){
    		return 1;

    	}   else return -1;
    } 
    else  return -1;
}

int busca_aluno(struct Aluno vetor[], int cod, int qtdRegistros){
	 int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetor[m].codigo){
    	return m;

    } else return -1;
	
}

void leitura_aluno(struct Aluno NovoAluno[], int &contAlunoT, struct Aluno AlunosCadastrados[], int contAlunosCadastrados, struct Cidade vetorCidade[], int qtdRegistrosCidade){	
	int i=0;
	
	for(int saida = 1; i < MaxAluno && saida != 0; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		  for(int x = 1; x != -1;){
			cout<<"Codigo Aluno: ";
			cin>>NovoAluno[i].codigo;
			cin.ignore();
				if(NovoAluno[i].codigo > 0){
					
					if( verifica_aluno(NovoAluno, NovoAluno[i].codigo, i) != 1 && verifica_aluno(AlunosCadastrados, NovoAluno[i].codigo, contAlunosCadastrados) != 1){
						cout<<"Nome: ";
						getline(cin, NovoAluno[i].nome);
						cout<<"Endereco: ";
						getline(cin,NovoAluno[i].endereco);
			
						for(; x != -1;){
								cout<<"Codigo Cidade: ";
								cin>>NovoAluno[i].codigo_cidade;
	
								int resultado = busca_cidade(vetorCidade, NovoAluno[i].codigo_cidade, qtdRegistrosCidade);
				
							if(resultado != -1){
								cout<<"Cidade: " << vetorCidade[resultado].nome;
								cout<<"\tUF: " << vetorCidade[resultado].uf << endl;
								x = -1;
						
							}else{ cout<<"\n***Codigo de cidade invalido, digite novamente***\n\n"; }
						}
							
				}else {	cout<<"\n***Esse codigo ja existe. Digite outro codigo***\n\n"; }
				
			}else {  saida = 0;  x = -1;	}
		}

	}				
	if(i == MaxAluno){
            contAlunoT = i;
            
        } else contAlunoT = i - 1;
        
}

void incluir_aluno(struct Aluno S[], int contS, struct Aluno T[], int contT, struct Aluno A[], int &contA){
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigo_cidade = S[i].codigo_cidade;
            i++;
            }
        else {
           A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].codigo_cidade = T[j].codigo_cidade;
            j++;
        }
    }
    while (i < contS){
         A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].codigo_cidade = S[i].codigo_cidade;
        i++;
        k++;
    }
    while (j < contT){
         A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].codigo_cidade = T[j].codigo_cidade;
        j++;
        k++;
    }
    contA = k;
}

void leitura_exclusao_aluno(int vetor[], int &contExclusao){
	int i = 0;

    for (int saida = 1; i < MaxAluno && saida > 0; i++) {
            	
		cout << "Codigo para exclusao: ";
       	cin >> vetor[i];
        cin.ignore();
        saida= vetor[i];
    }

	if(vetor[MaxAluno-1] != 0){
		if (i == MaxAluno) {
        contExclusao = i;
    	}else
        	contExclusao = i - 1;	
	}else
		contExclusao = i - 1;
}

void excluir_aluno(struct Aluno S[], int contS, int T[], int contT, struct Aluno A[], int &contA){
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;j < contT; i++){
        if (S[i].codigo != T[j]){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigo_cidade = S[i].codigo_cidade;
            k++;
            }
        else {
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
           A[k].nome = S[i].nome;
           A[k].endereco = S[i].endereco;
           A[k].codigo_cidade = S[i].codigo_cidade;
        i++;
        k++;
    }
    contA = k;
}

//FUNÇÕES TURMA

int verifica_turma(struct Turma vetor[], int cod, int qtdRegistros){
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;

    	for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        	if (cod > vetor[m].codigo)
            	i = m + 1;
       	 	else
            	f = m - 1;
    	}
    	
    	if(f != -1){
    	if (cod == vetor[m].codigo){
    		return 1;

    	}   else return -1;
    } 
    else  return -1;
}

int busca_turma(struct Turma vetor[], int cod, int qtdRegistros){
	 int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        if (cod > vetor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetor[m].codigo){
    	return m;

    } else return -1;
	
}

void leitura_turma(struct Turma NovaTurma[], int &contTurmaT, struct Turma TurmasCadastradas[], int contTurmasCadastradas, struct Curso vetorCurso[], int qtdRegistrosCurso, struct Instrutor vetorInstrutor[], int qtdRegistrosInstrutor, struct Cidade vetorCidade[], int qtdRegistrosCidade){
	
	int i=0;
		
	for(int saida = 1; i < MaxTurma && saida != 0; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		  for(int x = 1; x != -1;){
			cout<<"Codigo turma: ";
			cin>>NovaTurma[i].codigo;
			cin.ignore();
			
				if(NovaTurma[i].codigo > 0){
					if(verifica_turma(NovaTurma, NovaTurma[i].codigo, i) != 1 && verifica_turma(TurmasCadastradas, NovaTurma[i].codigo, contTurmasCadastradas) != 1){
						for(; x != -1;){
							cout<<"Codigo Curso: ";
							cin>>NovaTurma[i].codigo_curso;
							
							int resultado = busca_curso(vetorCurso,NovaTurma[i].codigo_curso,qtdRegistrosCurso);
						
							if( resultado != -1 ){
								cout<<"Curso: "<<vetorCurso[resultado].descricao;
							    cout<<" - Valor Por Aula: "<<vetorCurso[resultado].valor_por_aula<<" Reais "<<endl;
                    		    x = -1;
                    		    
							} else { cout<<"\n***Codigo curso invalido, digite novamente***\n\n";	}
						}
			
						for(int x =1 ; x != -1;){
								cout<<"Codigo Instrutor: ";
								cin>>NovaTurma[i].codigo_instrutor;
	
								int resultado = busca_instrutor(vetorInstrutor, NovaTurma[i].codigo_instrutor, qtdRegistrosInstrutor);
				
							if(resultado != -1){
								cout<<"Instrutor: " << vetorInstrutor[resultado].nome;
								
								 resultado = busca_cidade(vetorCidade, vetorInstrutor[resultado].codigo_cidade, qtdRegistrosCidade);
			
								cout<<" - Cidade: " << vetorCidade[resultado].nome << endl;
								x = -1;
						
							}else{ cout<<"\n***Codigo instrutor invalido, digite novamente***\n\n"; }
						}
						
						for(int x =1 ; x != -1;){
						cout<<"Total de participantes: ";
						cin>>NovaTurma[i].total_participantes;
						cout<<"Quantidade maxima de participantes: ";
						cin>>NovaTurma[i].quant_max_participantes;
						
							if(NovaTurma[i].total_participantes <= NovaTurma[i].quant_max_participantes){
								x = -1;
								
							} else cout<<"\n***O total de participantes deve ser menor ou igual a quantidade maxima de participantes***\n\n";
						}
					
				}else {	cout<<"\n***Esse codigo ja existe. Digite outro codigo***\n\n"; }
				
			}else { saida = 0;  x = -1;}
		}

	}				
	if(i == MaxTurma){
            contTurmaT = i;
            
        } else contTurmaT = i - 1;
        
}

void inclusao_turma(struct Turma S[], int contS, struct Turma T[], int contT, struct Turma A[], int &contA){
    int i = 0, j = 0, k = 0;

	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].codigo_curso = S[i].codigo_curso;
            A[k].codigo_instrutor = S[i].codigo_instrutor;
            A[k].total_participantes = S[i].total_participantes;
            A[k].quant_max_participantes = S[i].quant_max_participantes;
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            A[k].codigo_curso = T[j].codigo_curso;
            A[k].codigo_instrutor = T[j].codigo_instrutor;
            A[k].total_participantes = T[j].total_participantes;
            A[k].quant_max_participantes = T[j].quant_max_participantes;
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].codigo_curso = S[i].codigo_curso;
        A[k].codigo_instrutor = S[i].codigo_instrutor;
        A[k].total_participantes = S[i].total_participantes;
        A[k].quant_max_participantes = S[i].quant_max_participantes;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].codigo_curso = T[j].codigo_curso;
        A[k].codigo_instrutor = T[j].codigo_instrutor;
        A[k].total_participantes = T[j].total_participantes;
        A[k].quant_max_participantes = T[j].quant_max_participantes;
        j++;
        k++;
    }
    contA = k;
}

void consultar_turma(int cod, struct Turma vetorTurma[], int qtdRegistrosTurma, struct Curso vetorCurso[], int qtdRegistrosCurso, struct Instrutor vetorInstrutor[], int qtdRegistrosInstrutor, struct Cidade vetorCidade[], int qtdRegistrosCidade){
		int i=0;
		int resultado = 0;
	
	 for (int saida = 1; i < MaxTurma && saida > 0; i++){
		cout<<"\nCodigo turma a ser consultada: ";
		cin>>cod;
		if(cod > 0){
				if(cod == vetorTurma[i].codigo){
							
					resultado = busca_curso(vetorCurso,vetorTurma[i].codigo_curso,qtdRegistrosCurso);
						
						if( resultado != -1 ){
							cout<<"\nCurso: "<<vetorCurso[resultado].descricao;
						}
							resultado = busca_instrutor(vetorInstrutor, vetorTurma[i].codigo_instrutor, qtdRegistrosInstrutor);
				
							if(resultado != -1){
								cout<<"\nInstrutor: " << vetorInstrutor[resultado].nome;
								
								resultado = busca_cidade(vetorCidade, vetorInstrutor[resultado].codigo_cidade, qtdRegistrosCidade);
			
								cout<<"\nCidade: " << vetorCidade[resultado].nome << endl;
							}
							
							cout<<"Total de participantes: " << vetorTurma[i].total_participantes << endl;
					        cout<<"Quantidade maxima de participantes: " << vetorTurma[i].quant_max_participantes << endl;
							
				}else cout<<"\n***Turma nao encontrada***\n\n";
						
		} else saida = 0;
	}	
}

void consultar_turmas_completas(struct Turma vetorTurma[], int qtdRegistrosTurma, struct Curso vetorCurso[], int qtdRegistrosCurso, struct Instrutor vetorInstrutor[], int qtdRegistrosInstrutor, struct Cidade vetorCidade[], int qtdRegistrosCidade){
		int i = 0,  contcompleto =0;
	
	for(int i=0; i < qtdRegistrosTurma; i++){
	
		if(vetorTurma[i].total_participantes == vetorTurma[i].quant_max_participantes){
			contcompleto++;
			cout<<"\n------REGISTRO "<<i+1<<"------\n";
			cout<<" Codigo Turma: "<<vetorTurma[i].codigo<<endl;
			
			int resultado = busca_curso(vetorCurso,vetorTurma[i].codigo_curso,qtdRegistrosCurso);
			
				if( resultado != -1 ){
					cout<<" Curso: "<<vetorCurso[resultado].descricao;
				}
					resultado = busca_instrutor(vetorInstrutor, vetorTurma[i].codigo_instrutor, qtdRegistrosInstrutor);
					
						if(resultado != -1){
							cout<<"\nInstrutor: " << vetorInstrutor[resultado].nome;	
							
							resultado = busca_cidade(vetorCidade, vetorInstrutor[resultado].codigo_cidade, qtdRegistrosInstrutor);
							
							cout<<"\nCidade: " << vetorCidade[resultado].nome << endl;
							}
							
							cout<<"Total de participantes: " << vetorTurma[i].total_participantes << endl;
					        cout<<"Quantidade maxima de participantes: " << vetorTurma[i].quant_max_participantes << endl;
					        
		}
	} 
	if(contcompleto == 0){
		cout<<"\n***Nao existem turmas completas**\n\n";
	}
}

//FUNÇÕES MATRÍCULA

int verifica_matricula(struct Matricula vetor[], int cod, int qtdRegistros){
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;

    	for (; f >= i && cod != vetor[m].codigo; m = (i + f) / 2){
        	if (cod > vetor[m].codigo)
            	i = m + 1;
       	 	else
            	f = m - 1;
    	}
    	
    	if(f != -1){
    	if (cod == vetor[m].codigo){
    		return 1;

    	}   else return -1;
    } 
    else  return -1;
}

void leitura_matricula(struct Matricula NovaMat[], int &contMat, struct Matricula MatCadastradas[],int contMatCadastradas,struct Aluno vetorAluno[], int qtdRegistrosAluno, struct Turma vetorTurma[], int qtdRegistrosTurma, struct Instrutor vetorInstrutor[], int qtdRegistrosInstrutor,struct Cidade vetorCidade[],int qtdRegistrosCidade,struct Curso vetorCurso[],int qtdRegistrosCurso){
	int i = 0;
    int resultado = 0, resultado_aux = 0;
    float valorAula = 0;
    
    	for(int saida = 1; i < MaxMatricula && saida != 0; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		  for(int x = 1; x != -1;){
			cout<<" Codigo matricula: ";
			cin>>NovaMat[i].codigo;
			cin.ignore();

			if(NovaMat[i].codigo > 0){
				if(verifica_matricula(NovaMat, NovaMat[i].codigo, i) != 1 && verifica_matricula(MatCadastradas, NovaMat[i].codigo, contMatCadastradas) != 1){
					for(;x != -1;){
						cout<<" Codigo do Aluno: ";
						cin>>NovaMat[i].codigo_aluno;
        
						resultado = busca_aluno(vetorAluno,NovaMat[i].codigo_aluno,qtdRegistrosAluno);
							
                    	if(resultado != -1){
							cout<<" Aluno: "<<vetorAluno[resultado].nome<<endl;
							resultado = busca_cidade(vetorCidade,vetorAluno[resultado].codigo_cidade,qtdRegistrosCidade);
							cout<<" Cidade: "<< vetorCidade[resultado].nome << "-" << vetorCidade[resultado].uf <<endl;
                    		x=-1;
						} else{ cout<<"\n ***Codigo Aluno Invalido, digite novamente***\n\n"; }
            		}
				
					for(int x = 1; x != -1;){
						cout<<" Codigo da Turma: ";
						cin>>NovaMat[i].codigo_turma;
                
						resultado = busca_turma(vetorTurma,NovaMat[i].codigo_turma,qtdRegistrosTurma);
						
						if(resultado != -1){
							if(vetorTurma[resultado].total_participantes == vetorTurma[resultado].quant_max_participantes){
								cout<<" \n ***Turma Cheia, digite outra turma***\n\n"<<endl;
								
							} 
							else{
								resultado_aux = busca_curso(vetorCurso,vetorTurma[resultado].codigo_curso,qtdRegistrosCurso);
								
								cout<<" Curso: "<<vetorCurso[resultado_aux].descricao<<endl;	
								
								resultado = busca_turma(vetorTurma,vetorTurma[resultado].codigo_instrutor,qtdRegistrosInstrutor);
								
								cout<<" Instrutor: "<<vetorInstrutor[resultado].nome<<endl;	
								
								resultado = busca_turma(vetorTurma,NovaMat[i].codigo_turma,qtdRegistrosTurma);
								
								resultado_aux = busca_curso(vetorCurso,vetorTurma[resultado].codigo_curso,qtdRegistrosCurso);
								
								cout<<" Valor Por Aula: "<<vetorCurso[resultado_aux].valor_por_aula<<endl;
								
								valorAula = vetorCurso[resultado_aux].valor_por_aula;
								
                    			vetorTurma[resultado].total_participantes += 1;
                    			
								x=-1;
							}
							
						} else{ cout<<"\n ***Codigo Turma Invalido***\n"<<endl; }
					}
					cout<<" Quantidade de Aulas: ";
        			cin>>NovaMat[i].quantidade_aulas;
        			
        			NovaMat[i].valor_total = NovaMat[i].quantidade_aulas * valorAula;
        			
					cout<< " Valor total: "<<NovaMat[i].valor_total <<endl;
        	
				}else { cout<<"\n***Esse codigo ja existe. Digite outro codigo***\n\n";  }
				
			}	
			else{ saida = 0; x = -1; }			
		}
	}
	if(i == MaxMatricula){
            contMat = i;
            
        } else contMat = i - 1;
        	
}

void inclusao_matricula(struct Matricula S[], int contS, struct Matricula T[], int contT, struct Matricula A[], int &contA){
    int i = 0, j = 0, k = 0;
	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].codigo_aluno = S[i].codigo_aluno;
            A[k].codigo_turma = S[i].codigo_turma;
            A[k].quantidade_aulas = S[i].quantidade_aulas;
            A[k].valor_total = S[i].valor_total;
            i++;
        }
        else {
            A[k].codigo = T[j].codigo;
            A[k].codigo_aluno = T[j].codigo_aluno;
            A[k].codigo_turma = T[j].codigo_turma;
            A[k].quantidade_aulas = T[j].quantidade_aulas;
            A[k].valor_total = T[j].valor_total;
            j++;
        }
    }

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].codigo_aluno = S[i].codigo_aluno;
        A[k].codigo_turma = S[i].codigo_turma;
        A[k].quantidade_aulas = S[i].quantidade_aulas;
        A[k].valor_total = S[i].valor_total;
        i++;
        k++;
    }
    while (j < contT){
    	A[k].codigo = T[j].codigo;
    	A[k].codigo_aluno = T[j].codigo_aluno;
    	A[k].codigo_turma = T[j].codigo_turma;
        A[k].quantidade_aulas = T[j].quantidade_aulas;
        A[k].valor_total = T[j].valor_total;
        j++;
        k++;
    }
    contA = k;
}


// FUNÇÕES DE MOSTRAR 

void mostrar_cidades(struct Cidade vetor[], int contCidade ){
	cout << " \n----- CIDADES -----" << endl;
    for (int i = 0; i < contCidade; i++) {
        cout << "** Registro " << i + 1 << " **" << endl;
        cout << "Codigo: " << vetor[i].codigo << endl;
        cout << "Nome: " << vetor[i].nome << endl;
        cout << "Uf: " << vetor[i].uf << endl;
        cout << endl;
    }
}

void mostrar_instrutores(struct Instrutor vetor[], int contInstrutor ){
	cout << " \n----- INSTRUTORES -----" << endl;
    for (int i = 0; i < contInstrutor; i++) {
        cout << "** Registro " << i + 1 << " **" << endl;
        cout << "Codigo: " << vetor[i].codigo << endl;
        cout << "Nome: " << vetor[i].nome << endl;
        cout << "Endereco: " << vetor[i].endereco << endl;
        cout << "Codigo da Cidade: " << vetor[i].codigo_cidade << endl;
        cout << endl;
    }
}

void mostrar_alunos(struct Aluno vetor[], int contAluno ){
	cout << " \n----- ALUNOS -----" << endl;
    for (int i = 0; i < contAluno; i++) {
        cout << "** Registro " << i + 1 << " **" << endl;
        cout << "Codigo: " << vetor[i].codigo << endl;
        cout << "Nome: " << vetor[i].nome << endl;
        cout << "Endereco: " << vetor[i].endereco << endl;
        cout << "Codigo da Cidade: " << vetor[i].codigo_cidade << endl;
        cout << endl;
    }
}

void mostrar_cursos(struct Curso vetor[], int contCurso ){
	cout << " \n----- CURSOS -----" << endl;
    for (int i = 0; i < contCurso; i++) {
        cout << "** Registro " << i + 1 << " **" << endl;
        cout << "Codigo: " << vetor[i].codigo << endl;
        cout << "Descricao: " << vetor[i].descricao << endl;
        cout << "Valor por aula: " << vetor[i].valor_por_aula << endl;
        cout << endl;
    }
}
void mostrar_matriculas(struct Matricula A[], int contA,struct Aluno aluno[],int contAluno,struct Turma turma[],int contTurma,struct Instrutor instrutor[],int contInstrutor,struct Curso curso[],int contCurso){
    int resultado =0;
    int resultado_aux=0;
    int i=0;
	cout << "\n\t----Registros Matriculas----" << endl;
    while (i<contA){
       	cout << "\n Codigo Matricula: " << A[i].codigo <<endl;
       	
		resultado = busca_aluno(aluno,A[i].codigo_aluno,contAluno);
		cout << " Aluno: " << aluno[resultado].nome << endl;
		
		resultado=busca_turma(turma,A[i].codigo_turma,contTurma);
		resultado_aux=busca_turma(turma,turma[resultado].codigo_curso,contCurso);
		cout<<" Curso: "<<curso[resultado_aux].descricao << endl;
		resultado=busca_turma(turma,turma[resultado].codigo_instrutor,contInstrutor);
		cout<<" Instrutor: "<<instrutor[resultado].nome << endl;
		cout << " Valor Total: " << A[i].valor_total << endl;
		i++;				
		cout<<"\n\n";		
    }  
}


int main(){
	
int opcao;

	//CIDADE 
	 Cidade cidades[MaxCidade];
	 int contCidade = 0;
	
	//INSTRUTOR
	 Instrutor instrutores[MaxInstrutor];
	 int contInstrutor = 0;
	 
	 Instrutor instrutor_T[MaxInstrutor];
	 int contInst_T = 0;
	 
     Instrutor instrutor_S[MaxInstrutor];
     int contInst_S = 0;
     
     //CURSO
     Curso cursos[MaxCurso];
     int contCurso = 0;
	 
	 //ALUNO
	 Aluno alunos[MaxAluno];
	 int contAluno = 0;
	 
	 Aluno aluno_T[MaxAluno];
	 int contAluno_T = 0;
	 
     Aluno aluno_S[MaxAluno];
     int contAluno_S = 0;
     
     int exclusao_aluno_T[MaxAluno];
     int cont_exclusao_T = 0;
	 
	 //TURMA 
	 Turma turmas[MaxTurma];
	 int contTurma = 0;
	 
	 Turma turma_T[MaxTurma];
	 int contTurma_T = 0;
	 
	 Turma turma_S[MaxTurma];
	 int contTurma_S = 0;
	 
	 //MATRÍCULA
	 Matricula matriculas[MaxMatricula];
	 int contMatricula = 0;
	 
	 Matricula matricula_T[MaxMatricula];
	 int contMatricula_T = 0;
	 
	 Matricula matricula_S[MaxMatricula];
	 int contMatricula_S = 0;
	 

    do {
    	system("cls");
        
       cout<<"\n";
		cout<<"\t_________________________________"<<endl;
		cout<<"\t|-------------MENU--------------|" <<endl;
		cout<<"\t| CIDADE		        |"<<endl;
		cout<<"\t| 1 - Leitura cidade       	|"<<endl;
		cout<<"\t|                               |"<<endl;
		cout<<"\t| CURSO		                |"<<endl;
		cout<<"\t| 2 - Leitura curso        	|"<<endl;
		cout<<"\t|                               |"<<endl;
		cout<<"\t| INSTRUTOR	                |"<<endl;
		cout<<"\t| 3 - Inserir instrutor         |"<<endl;
		cout<<"\t|                               |"<<endl;
		cout<<"\t| ALUNO	     	                |"<<endl;
		cout<<"\t| 4 - Incluir Aluno             |"<<endl;
		cout<<"\t| 5 - Excluir Aluno             |"<<endl;
		cout<<"\t|                               |"<<endl;
		cout<<"\t| TURMAS	                |"<<endl;		
		cout<<"\t| 6 - Incluir turma 	        |"<<endl;
		cout<<"\t| 7 - Consultar turma 	        |"<<endl;
		cout<<"\t| 8 - Mostrar turmas completas  |"<<endl;
		cout<<"\t|                               |"<<endl;
		cout<<"\t| MATRICULAS 	                |"<<endl;
		cout<<"\t| 9 - Incluir matricula         |"<<endl;
		cout<<"\t| 10 - Mostrar Matriculas       |"<<endl;
		cout<<"\t|                               |"<<endl;
		cout<<"\t| 11 - Sair                     |"<<endl;
		cout<<"\t|_______________________________|"<<endl;
		cout<<"\nEscolha uma opcao: ";
		cin>>opcao;

        // Processa a escolha do usuário
        switch(opcao) {
            case 1:
            	system("cls");
            	cout<<"\n\tLEITURA CIDADES" << endl;
                leitura_cidade(cidades, contCidade);
                system("cls");
                mostrar_cidades(cidades, contCidade);
                getch();
               break;
            case 2:
                system("cls");
                cout << "\n\tLEITURA CURSOS" << endl;
                leitura_curso(cursos, contCurso);
                system("cls");
                mostrar_cursos(cursos, contCurso);
                getch();
                break;
            case 3:
            	system("cls");
				cout << "\n\tINCLUSAO DE INSTRUTOR" << endl;
				leitura_instrutor(instrutor_T, contInst_T, instrutores, contInstrutor, cidades, contCidade);
				incluir_instrutor(instrutor_S, contInst_S, instrutor_T, contInst_T, instrutores, contInstrutor);
					
					if(contInstrutor != 0){
           				for(int i = 0; i<contInstrutor; i++){
            		 		instrutor_S[i].codigo  = instrutores[i].codigo;
            		 		instrutor_S[i].nome  = instrutores[i].nome;
            				instrutor_S[i].endereco  = instrutores[i].endereco;
            		 		instrutor_S[i].codigo_cidade  = instrutores[i].codigo_cidade;	
						}	
            		}	
							
					contInst_S = contInstrutor;
					
					system("cls");
					mostrar_instrutores(instrutores,contInstrutor);
					getch();		
							
					break;
            case 4:
            	system("cls");
                cout << "\n\tINCLUSAO DE ALUNO" << endl;
                leitura_aluno(aluno_T, contAluno_T, alunos, contAluno, cidades, contCidade);
				incluir_aluno(aluno_S, contAluno_S, aluno_T, contAluno_T, alunos, contAluno);
					
							
					if(contAluno != 0){
           				for(int i = 0; i<contAluno; i++){
            		 		aluno_S[i].codigo  = alunos[i].codigo;
            		 		aluno_S[i].nome  = alunos[i].nome;
            				aluno_S[i].endereco  = alunos[i].endereco;
            		 		aluno_S[i].codigo_cidade  = alunos[i].codigo_cidade;	
						}	
            		}	
							
					contAluno_S = contAluno;
					
					system("cls");
					mostrar_alunos(alunos,contAluno);
					getch();		
                break;
            case 5:
        	    system("cls");
	            cout << "\n-----EXCLUSAO DE ALUNOS (finalize com 0)-----\n\n";
                
                leitura_exclusao_aluno(exclusao_aluno_T, cont_exclusao_T);
                excluir_aluno(aluno_S, contAluno_S,exclusao_aluno_T,cont_exclusao_T, alunos, contAluno);
                
                for (int i = 0; i < contAluno; i++) {
                        aluno_S[i].codigo = alunos[i].codigo;
                        aluno_S[i].nome = alunos[i].nome;
                        aluno_S[i].endereco = alunos[i].endereco;
                        aluno_S[i].codigo_cidade = alunos[i].codigo_cidade;
                    }
                	
                	contAluno_S = contAluno;
                	
                	system("cls");
                break;
            case 6:
            	system("cls");
                cout << "\n\tINCLUSAO DE TURMA" << endl;
                
                leitura_turma(turma_T, contTurma_T, turmas, contTurma, cursos, contCurso, instrutores, contInstrutor, cidades, contCidade);
                inclusao_turma(turma_S, contTurma_S, turma_T, contTurma_T, turmas, contTurma);
                
                for(int i = 0; i < contTurma; i++){
            			turma_S[i].codigo = turmas[i].codigo;
            			turma_S[i].codigo_curso = turmas[i].codigo_curso;
            			turma_S[i].codigo_instrutor = turmas[i].codigo_instrutor;
            			turma_S[i].total_participantes = turmas[i].total_participantes;
            			turma_S[i].quant_max_participantes = turmas[i].quant_max_participantes;
					}
					
					contTurma_S = contTurma;

					system("cls");
                break;
            case 7:
            	system("cls");
                cout << "\n\tCONSULTAR TURMA" << endl;
                int cod_consulta;
                consultar_turma(cod_consulta, turmas, contTurma, cursos, contCurso, instrutores, contInstrutor, cidades, contCidade);
                getch();
                
                system("cls");
                break;
            case 8:
            	system("cls");
                cout << "\n\tMOSTRAR TURMA(S) COMPLETA(S)" << endl;
                consultar_turmas_completas(turmas, contTurma, cursos, contCurso, instrutores, contInstrutor, cidades, contCidade);
                getch();
                system("cls");
                break;
            case 9:
            	system("cls");
                cout << "\n\tINCLUSAO DE MATRICULA" << endl;
                
                leitura_matricula(matricula_T, contMatricula_T, matriculas, contMatricula, alunos, contAluno, turmas, contTurma, instrutores, contInstrutor, cidades, contCidade, cursos, contCurso);
                inclusao_matricula(matricula_S, contMatricula_S, matricula_T, contMatricula_T, matriculas, contMatricula);
                
                for(int i = 0; i < contMatricula; i++){
            			matricula_S[i].codigo = matriculas[i].codigo;
            			matricula_S[i].codigo_aluno = matriculas[i].codigo_aluno;
            			matricula_S[i].codigo_turma = matriculas[i].codigo_turma;
            			matricula_S[i].quantidade_aulas = matriculas[i].quantidade_aulas;
            			matricula_S[i].valor_total = matriculas[i].valor_total;
					}
					
					contMatricula_S = contMatricula;
				break;
            case 10:
            	system("cls");
            	mostrar_matriculas(matriculas, contMatricula, alunos, contAluno, turmas, contTurma, instrutores, contInstrutor, cursos, contCurso);
            	getch();
            	break;
            case 11:
            	system("cls");
            	cout<<"\n\t.......SAINDO DO PROGRAMA.....";
            	getch();
            	opcao = 0;
            	break;
            default:
                cout << "Opcao invalida. Por favor, escolha uma opcao valida." << endl;
                break;
        }
    } while(opcao != 0);
    
}
	

	

	
	

