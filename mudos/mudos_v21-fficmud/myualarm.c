/*
   Alex Unleashed (Tyrael @ FFIC-MUDLIB) <xelaco@yahoo.com>
   Implementacion de ualarm() para OSes que no la soportan directamente.
*/

#include <stdio.h>
#include <sys/time.h>

unsigned int ualarm(register unsigned int useconds, register unsigned int interval)
{
	static int called_before = 0;
	struct itimerval temporizador, old;

	temporizador.it_value.tv_sec = (long) useconds / 1000000L;
	temporizador.it_value.tv_usec = (long) useconds % 1000000L;
	temporizador.it_interval.tv_sec = (long) interval / 1000000L;
	temporizador.it_interval.tv_usec = (long) interval % 1000000L;

	if (setitimer(ITIMER_REAL, &temporizador, &old) == -1) {
		perror("ualarm: setitimer");
		return 0;
	}
	if (!called_before) {
		called_before = 1;
		return 0;
	}
	return old.it_value.tv_sec * 1000000L +
		old.it_value.tv_usec;
}
