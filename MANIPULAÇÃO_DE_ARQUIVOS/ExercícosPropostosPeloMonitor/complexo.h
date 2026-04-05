struct complexo{
	double R;
	double I;
};


void imprComplexo(struct complexo * C);

struct complexo * lerComplexo();

struct complexo * Soma(struct complexo * A, struct complexo * B);

struct complexo * Subtracao (struct complexo * A, struct complexo * B);

struct complexo * Multiplicacao (struct complexo * A, struct complexo * B);

double Modulo (struct complexo * C);

struct complexo * Conjugado (struct complexo * C);

double raizQuadrada(double X);

double raizR(double X, double max, double min, double mid);
