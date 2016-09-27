#include <stdio.h>
#include <time.h>

void delay(int milliseconds);

enum States { 
	VERDE,
	AMARILLO,
	ROJO,
	ROJO_AMARILLO
};

#define	DELAY_VERDE	3000
#define	DELAY_AMARILLO 500
#define	DELAY_ROJO 3000
#define	DELAY_ROJOAMARILLO 500

void pasarAVerde()
{
    printf("VERDE\n"); 
	
}

void pasarAAmarillo()
{
    printf("AMARILLO\n");        
	
}

void pasarARojo()
{
	printf("ROJO\n");        
	
}

void pasarARojoAmarillo()
{
	printf("ROJO_AMARILLO\n");
	
}

int main()
{
	enum States state = VERDE;
	
	while(1) {
		switch(state) {
			case VERDE:
				pasarAVerde();
				delay(DELAY_VERDE);
				state = AMARILLO;
				break;
			case AMARILLO:				
				pasarAAmarillo();
				delay(DELAY_AMARILLO);
				state = ROJO;
				break;
			case ROJO:		
				pasarARojo();
				delay(DELAY_ROJO);
				state = ROJO_AMARILLO;
				break;
			case ROJO_AMARILLO:
				pasarARojoAmarillo();
				delay(DELAY_ROJOAMARILLO);
				state = VERDE;
				break;
		}
	}
	return 0;
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
