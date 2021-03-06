#include "ajuda_mushu.h"

void guardarCSV(int histograma[]) {
	FILE *f;
	f = fopen("histograma.csv", "w");
	if (f == NULL) {
		printf("Erro ao criar ficheiro!\n");
		exit(0);
	}
	for (int i = 0; i < HIST_SIZE; i++) {
		fprintf(f, "%d;%d\n", i+1, histograma[i]);
	}
	fclose(f);
}

// Funcao que permite calcular o c
double calculaC(){

	double u =(double) (rand() + 1) / (RAND_MAX + 1.0);
	return -(1.0 / LAMBDA) * log(u);
}

// Funcao que permite calcular o d
double calculaD(){

	double u =(double) (rand() + 1) / (RAND_MAX + 1.0);
	return -Dm * log(u);
}

// Funcao que permite mapear os valores c entrada vem entre ]0,MAX_ATRASO[ e saida [0 HIST_SIZE]
int map(double c_to_map, double max_atraso){
	// printf("%lf -> %d \n", c_to_map,(int)floor(0 + ((HIST_SIZE - 0) / (MAX_ATRASO - 0)) * (c_to_map - 0)));
	if (c_to_map<max_atraso)
	{
		return (int)floor( 0 + ((HIST_SIZE - 0) / (max_atraso - 0)) * (c_to_map - 0));
	}else
		return HIST_SIZE-1;
	
}
int hardenMap(double c_to_map){

	for (size_t i = 0; i < HIST_SIZE-1; i++) {
		// if (i==1) {
		// 	printf("%lf >= %lf &&  %lf < %lf\n",c_to_map,i*DELTA,c_to_map,(i+1)*DELTA);
		// }

		if (c_to_map>=i*DELTA && c_to_map < (i+1)*DELTA)
			return i;
	}
	return HIST_SIZE-1;
}

// Funcao permite imprimir histograma terminal
void imprimeHistograma(int histograma[]){
	for (int i = 0; i < HIST_SIZE; i++) {

		if (i+1 >= 10) {
			printf("%d | %d -> ",i +1, histograma[i]);
		}else
			printf("%d  | %d -> ",i + 1, histograma[i]);
		for (int j = 0; j < histograma[i]/10; j++) {
			printf("#");
		}
		for (size_t j = 0; j < histograma[i]%10; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void limpar(int arrivals){
	// Limpar lista
	for (size_t i = 0; i < arrivals; i++) {
		lista_eventos = remover(lista_eventos);
	}
}
