#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 500

char *lerDados(char *s) {
	
    fgets(s, TAM, stdin); // a função strcspn retorna o número de caracteres em s antes do primeiro caractere "\n" encontrado.
    s[strcspn(s, "\n")] = '\0'; // Substitui o caractere '\n' na string por '\0'
    return s;
}

void liberarMemoria(char *s) {
	
     if (s != NULL) { 
        free(s); //verifica se o ponteiro "s" não é nulo antes de chamar a função "free" para liberar a memória alocada para a variável apontada por "s". 
    }
}

char *vaiDeMao(char *string) {
                                                  
    char *plot = (char *) calloc(TAM, sizeof(char));
    int i = 0, j = 0, n = strlen(string);   
    
    while (i < n - 1) {
        if (string[i] == 'a' && i + 1 < n && strncmp(&string[i], "ao", 2) == 0) {
            plot[j++] = 't';
            plot[j++] = 's';
            plot[j++] = 'e';
            i += 2;
        } else if (string[i] == 'o' && i + 1 < n && strncmp(&string[i], "oa", 2) == 0) {
            plot[j++] = 't';
            plot[j++] = 'u';
            plot[j++] = 'n';
            plot[j++] = 'g';
            i += 2;
        }
        else {
            plot[j++] = string[i++];
        }
    }
    //Verifica o último caractere
    if (i == n-1) {
        plot[j++] = string[i];
    }

    plot[j] = '\0'; // Adiciona o caractere nulo ao final do novo vetor
   
    return plot;
}

char *vaiDeBem(char *string) {
                                                  
    char *plot = (char *) calloc(TAM, sizeof(char));
    int i = 0, j = 0, n = strlen(string);
    
    while (i < n - 1) {
        if (string[i] == 't' && i + 2 < n && strncmp(&string[i], "tse", 3) == 0) {
            plot[j++] = 'a';
            plot[j++] = 'o';
            i += 3; // pula a substring "tse"
        } else if (string[i] == 't' && i + 3 < n && strncmp(&string[i], "tung", 4) == 0) {
            plot[j++] = 'o';
            plot[j++] = 'a';
            i += 4; // pula a substring "tung"
        } else {
            plot[j++] = string[i++];
        }
    }
    //Verifica o último caractere
    if (i == n-1) {
        plot[j++] = string[i];
    }
    
    plot[j] = '\0'; // Adiciona o caractere nulo ao final do novo vetor
   
    return plot;
}

char *chinaDividida(char *string) {
	
	char *plot = (char *) calloc (TAM , sizeof(char));
	char *primeira_metade = (char *) calloc (TAM , sizeof(char));
	char *segunda_metade = (char *) calloc (TAM , sizeof(char));
	int i, n = strlen(string), cont_t = 0, cont_c = 0, meio = 0;
	
	for (i = 0; i < n; i++) {
		
		if (string[i] == 'c' || string[i] == 'C') { // conta a quantidade de letras 'c'
                cont_c++;
    	} else if (string[i] == 't' || string[i] == 'T') { // conta a quantidade de letras 't' 
                cont_t++;
		}		
	}
	
	meio = n / 2;
    strncpy(primeira_metade, string, meio); // copia metade dos carecteres
    strncpy(segunda_metade, string + meio, n - meio); // copia o restante dos carecteres
    primeira_metade[meio] = '\0';
    segunda_metade[n - meio] = '\0';
    
    if (cont_c > cont_t) {
        strcpy(plot, "China");
        strcat(plot, primeira_metade);
        strcat(plot, "Taiwan");
        strcat(plot, segunda_metade);
        strcat(plot, "China");
    } else if (cont_t > cont_c) {
    	strcpy(plot, "Taiwan");
        strcat(plot, primeira_metade);
        strcat(plot, "China");
        strcat(plot, segunda_metade);
        strcat(plot, "Taiwan");
	} else {
        strcpy(plot, string);
    }
    
    free(primeira_metade); //Liberando a memória alocada para primeira_metade
    free(segunda_metade); //Liberando a memória alocada para segunda_metade
    return plot;
}

char *chinaUnida(char *string) {
    
    char *plot = (char *) calloc(TAM, sizeof(char));
    int i = 0, j = 0, n = strlen(string);

    while (i < n - 1) {
        if (string[i] == 'C' && i + 5 <= n && strncmp(&string[i], "China", 5) == 0) {
            i += 5; // pula a palavra "China"
        } else if (string[i] == 'T' && i + 6 <= n && strncmp(&string[i], "Taiwan", 6) == 0) {
            i += 6; // pula a palavra "Taiwan"
        } else {
            plot[j++] = string[i++]; // copia o caractere para o novo buffer e incrementa i
        }
    }
    
    //Verifica o último caractere
    if (i == n-1) {
        plot[j++] = string[i];
    }

    plot[j] = '\0'; // adiciona o caractere nulo ao final do novo vetor
    return plot;
}

char *espelhoTai(char *string) {  
	
	char *plot = (char *) calloc (TAM , sizeof(char));
	int i, n = strlen(string);
	
	for (i = 0; i < n; i++) {
		
        if (string[i] >= 'a' && string[i] <= 'z') { // somar as letras "a" e "z" e subtrair a posição do vetor (string[i])
            plot[i] = 'a' + 'z' - string[i];
        } else if (string[i] >= 'A' && string[i] <= 'Z') { // somar as letras "A" e "Z" e subtrair a posição do vetor (string[i])
            plot[i] = 'A' + 'Z' - string[i];
        } else { // os caracteres que não são letras permanecem inalterados.                                                     
			plot[i] = string[i];
		}
    }
    
    plot[i] = '\0'; // adiciona o caractere nulo ao final do novo vetor
	return plot; 	
}

char *inversaoDupla(char *string) {
	
    char *plot = (char *) calloc(TAM, sizeof(char));
    int i, n = strlen(string);
	
    for (i = 0; i < n-1; i += 2) {	
		plot[i] = string[i + 1];
        plot[i + 1] = string[i];
	}
	
	if(i + 1 == n){
        plot[n-1] = string[n-1];
	}

	return plot; 	
}

char *quaseJuncao(char *string) {
	
    return inversaoDupla(chinaDividida(vaiDeMao(string)));;
}

char *quaseDisjuncao(char *string) {
	
    return vaiDeBem(chinaUnida(inversaoDupla(string)));;
}

char *criptografarDados(char *s){
	
	char *cript = (char *) calloc (TAM , sizeof(char));
	char *quebra = (char *) calloc (TAM , sizeof(char));
	char *mensagem = (char *) calloc (TAM , sizeof(char));
	strcpy(mensagem, "");
	int cont = 1, cont_esp=0, i=0;
	
	do {
		
		if (s[i] == ' '){ // conta quantos espaços em branco tem e os acumula na variável cont_esp                                                 
			cont_esp++; // a função strtok quebra a string utilzando o delimitador espaço em branco " "                                                        
		}                                                                      
	                                                                           
		i++;                                                                                            
                                                                                                           		
	} while (s[i] != '\0');                                                   
	                                                                           
	quebra = strtok(s, " "); // a função strtok retorna um ponteiro para o início da substring se não for encontrado nenhuma substring o strtok retorna NULL                                                      
	i = 0; // a função strtok usa a posição a partir do fim do último pedaço da string encontrado como início para a próxima busca                                                              
	
	do {                                                                      
	                                                                           
		switch (cont)                                                          
		{                                                                      
		                                                          
			case 1:                                                            
				cript = vaiDeMao(quebra);                                     
				strcat(cript, " ");                                            
				strcat(mensagem, cript);                                       
				i++;                                                           
				cont++;                                                        
				quebra = strtok(NULL, " ");                                   
				break;                                                         
				
			case 2:
				cript = chinaDividida(quebra);
				strcat(cript, " ");
				strcat(mensagem, cript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 3:
				cript = espelhoTai(quebra);
				strcat(cript, " ");
				strcat(mensagem, cript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 4:
				cript = inversaoDupla(quebra);
				strcat(cript, " ");
				strcat(mensagem, cript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 5:
				cript = quaseJuncao(quebra);
				strcat(cript, " ");
				strcat(mensagem, cript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 6:
				cont=1;
				break;
		}
		
	} while (i <= cont_esp);

	return mensagem;	
}

char *descriptografarDados(char *s){
	
	char *descript = (char *) calloc (TAM , sizeof(char));
	char *quebra = (char *) calloc (TAM , sizeof(char));
	char *mensagem = (char *) calloc (TAM , sizeof(char));
	strcpy(mensagem, "");
	int cont = 1, cont_esp = 0, i = 0;
	
	do {
		if (s[i] == ' '){ // conta quantos espaços em branco tem e os acumula na variável cont_esp
			cont_esp++; // a função strtok quebra a string utilzando o delimitador espaço em branco " "                                                       
		}                                                                      
		i++;                                                         
		                                                                 
	} while (s[i] != '\0');                                
	                                                       
	quebra = strtok(s, " "); // a função strtok retorna um ponteiro para o início da substring se não for encontrado nenhuma substring o strtok retorna NULL                          
	i = 0; // a função strtok usa a posição a partir do fim do último pedaço da string encontrado como início para a próxima busca                                                 // 
	
	do {                                                   
	                                                       
		switch (cont)                                      
		{                                                  
			
			case 1:                                                           
				descript = vaiDeBem(quebra);                              
				strcat(descript, " ");                                         
				strcat(mensagem, descript);                                  
				i++;                                                           
				cont++;                                                       
				quebra = strtok(NULL, " ");                                   
				break;                                                         
				
			case 2:
				descript = chinaUnida(quebra);
				strcat(descript, " ");
				strcat(mensagem, descript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 3:
				descript = espelhoTai(quebra);
				strcat(descript, " ");
				strcat(mensagem, descript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 4:
				descript = inversaoDupla(quebra);
				strcat(descript, " ");
				strcat(mensagem, descript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 5:
				descript = quaseDisjuncao(quebra);
				strcat(descript, " ");
				strcat(mensagem, descript);
				i++;
				cont++;
				quebra = strtok(NULL, " ");
				break;
				
			case 6:
				cont=1;
				break;
		}
	
	} while (i < cont_esp);

	return mensagem;
}

int main(int argc, char *argv[]){
	
	char *str = (char *) calloc (TAM , sizeof(char));
	char *cript = (char *) calloc (TAM , sizeof(char));
	char *descript = (char *) calloc (TAM , sizeof(char));
	
	printf("\n  Mensagem a ser criptografada: ");
	str = lerDados(str);
	
	cript = criptografarDados(str);
	printf("\n  Mensagem criptografada: %s\n", cript);
	
	descript = descriptografarDados(cript);
	printf("\n  Mensagem descriptografada: %s\n", descript);
	
	liberarMemoria(str);
	liberarMemoria(cript);
	liberarMemoria(descript);
	
	return 0;
}