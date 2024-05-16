#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
	
	//Declara��o das vari�veis
	char entrada[100];		//Valor do usu�rio
	char digitos[100];		//Resultado a ser devolvido 
	int contador = 0;		//Contador para escrever a string de resposta
	int decimais, numeroEncontrado, negativo;		//Vari�veis para serem usadas em condicionais
	decimais = numeroEncontrado = negativo = 1;
	
	//Recebe a expressao do usu�rio
	printf("Digite a sentenca a ser processada: \n");
	fgets(entrada, sizeof(entrada), stdin);
	
	//Elimina a quebra de linha no final da string se houver
	int tamanho = strlen(entrada);
	if (entrada[tamanho - 1] == '\n') {
            entrada[tamanho - 1] = '\0';
        }
	
	//Come�a a leitura
	for(int i=0;i<strlen(entrada);i++){
		//Verifica se se trata de um d�gito(0-9)
		int digito = isdigit(entrada[i]);
		
		if(numeroEncontrado){					//Verifica se a j� encontrou um n�mero
			if(digito == 0){
				if(entrada[i] == '+'){			//Ignora o sinal positivo
					numeroEncontrado = 0;
					
				} else if(entrada[i] == '-'){	//Verifica se a express�o � negativa
					negativo = 0;
					numeroEncontrado = 0;
					
				} else if(isspace(entrada[i])){	//Ignora espa�os em branco
					
				} else{							//Finaliza o loop se n�o reconhecer um n�mero
					break;
				}
				
			} else if(digito){					
					digitos[contador] = entrada[i];
					contador++;
					numeroEncontrado = 0;
				}
				
		} else{									//Continua a leitura de um n�mero j� encontrado
			if(digito){
				digitos[contador] = entrada[i];
				contador++;
				
			} else if(decimais){				//Verifica se j� est�o sendo escritos valores decimais
				if(entrada[i] == '.'){
					digitos[contador] = '.';
					contador++;
					decimais = 0;
				} else{	
					break;
				}
					
			} else{								//Encerra o loop caso n�o consiga fazer a leitura de um n�mero
				break;
			}
		}
	}
	
	digitos[contador] = '\0';					//Adiciona o d�gito nulo ao final da string
	
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
