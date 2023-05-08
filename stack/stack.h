#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdio.h>
#define SIZE 4

typedef struct {

	int stack_array[SIZE];
	int stack_top;

/* *** Strukturen *********************************************************** *o/
/**@brief Struktur des Stacks.
 */
    /* hier sollte noch etwas dazu kommen */
} IntStack;

/* *** öffentliche Schnittstelle ******************************************** */
/**@brief Initialisiert einen neuen Stack.
 * @param self  der zu initialisierende Stack
 * @return 0, falls keine Fehler bei der Initialisierung aufgetreten sind,
 *      != 0, ansonsten
 */
extern int stackInit(IntStack *self)
{
	self->stack_top = -1;
	return 0;
}
/**@brief Gibt den Stack und alle assoziierten Strukturen frei.
 * @param self  der Stack
 */
extern void stackRelease(IntStack *self)

{
	self->stack_top = -1;
}
/**@brief Legt einen Wert auf den intstack.
 * @param self  der intstack
 * @param i     der Wert
 */
extern void	stackPush(IntStack *self, int i)
{
	self->stack_top++;
	self->stack_array[self->stack_top] = i;
}

/**@brief Gibt das oberste Element des Stacks zurück.
 * @param self  der Stack
 * @return das oberste Element
 */
extern int stackTop(const IntStack *self)
{
	printf("%i\n", self->stack_array[self->stack_top]);
	return 0;
}
/**@brief Entfernt und liefert das oberste Element des Stacks.
 * @param self  der Stack
 * @return das oberste Element
 */
extern int stackPop(IntStack *self)
{
	if (self->stack_top == -1)
	{
		return -1;
	}
	else
	{
		int i = self->stack_array[self->stack_top];
		self->stack_top--;
		return i;
	}
}
/**@brief Gibt zurück, ob der Stack leer ist.
 * @param self  der Stack
 * @return 0, falls nicht leer,
        != 0, falls leer
 */
extern int stackIsEmpty(const IntStack *self)
{
	return self->stack_top == -1;
}
 /***@brief Gibt den Inhalt des Stacks beginnend mit dem obersten Element auf der
 * Standardausgabe aus.
 * @param self  der Stack
 */
extern void stackPrint(const IntStack *self)
{
	int i = self->stack_top;
	while (i != -1)
	{
		printf("%i\n", self->stack_array[i]);
	}
}
#endif /* STACK_H_INCLUDED */
