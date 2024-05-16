#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
	
	//Declaração das variáveis
	char entrada[100];		//Valor do usuário
	char digitos[100];		//Resultado a ser devolvido 
	int contador = 0;		//Contador para escrever a string de resposta
	int decimais, numeroEncontrado, negativo;		//Variáveis para serem usadas em condicionais
	decimais = numeroEncontrado = negativo = 1;
	
	//Recebe a expressao do usuário
	printf("Digite a sentenca a ser processada: \n");
	fgets(entrada, sizeof(entrada), stdin);
	
	//Elimina a quebra de linha no final da string se houver
	int tamanho = strlen(entrada);
	if (entrada[tamanho - 1] == '\n') {
            entrada[tamanho - 1] = '\0';
        }
	
	//Começa a leitura
	for(int i=0;i<strlen(entrada);i++){
		//Verifica se se trata de um dígito(0-9)
		int digito = isdigit(entrada[i]);
		
		if(numeroEncontrado){					//Verifica se a já encontrou um número
			if(digito == 0){
				if(entrada[i] == '+'){			//Ignora o sinal positivo
					numeroEncontrado = 0;
					
				} else if(entrada[i] == '-'){	//Verifica se a expressão é negativa
					negativo = 0;
					numeroEncontrado = 0;
					
				} else if(isspace(entrada[i])){	//Ignora espaços em branco
					
				} else{							//Finaliza o loop se não reconhecer um número
					break;
				}
				
			} else if(digito){					
					digitos[contador] = entrada[i];
					contador++;
					numeroEncontrado = 0;
				}
				
		} else{									//Continua a leitura de um número já encontrado
			if(digito){
				digitos[contador] = entrada[i];
				contador++;
				
			} else if(decimais){				//Verifica se já estão sendo escritos valores decimais
				if(entrada[i] == '.'){
					digitos[contador] = '.';
					contador++;
					decimais = 0;
				} else{	
					break;
				}
					
			} else{								//Encerra o loop caso não consiga fazer a leitura de um número
				break;
			}
		}
	}
	
	digitos[contador] = '\0';					//Adiciona o dígito nulo ao final da string
	
    if (contador == 0) {						//Retorna zero se nenhum valor foi encontrado
        strcpy(digitos, "Resultado: 0.00");
    }

    if (negativo == 0) {						//Imprime o valor encontrado
        printf("Resultado: -%s\n", digitos);
    } else {
        printf("Resultado: %s\n", digitos);
    }
	
	return 0;
}
