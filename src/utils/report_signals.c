#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "utils.h"

void handler(int sig)
{
	char	*message = NULL;

	switch(sig)
	{
		case SIGSEGV:
			message = "Segfault (SIGSEGV)";
			break ;
		case SIGABRT:
			message = "Sigabort (SIGABRT)";
			break ;
		case SIGBUS:
			message = "Bus error (SIGBUS)";
			break ;
		case SIGILL:
			message = "Illegal instruction (SIGILL)";
			break ; 
		default:
			message = "Crash signal (Unspecified, please report this)";
			break ;
	}
	(void)sig;
	TEST_FAIL_MESSAGE(message);
}

void	catch_signals(void)
{
	struct sigaction sa;
	sigset_t	set;

	memset(&sa, 0, sizeof(sigaction));
  	sigemptyset(&set);

	sigaddset(&set, SIGSEGV);
	sa.sa_mask = set;
	sa.sa_flags = SA_RESTART;

  	sa.sa_handler = handler;
 	sigaction(SIGSEGV, &sa, NULL);
 	sigaction(SIGABRT, &sa, NULL);
	sigaction(SIGBUS, &sa, NULL);
	sigaction(SIGILL, &sa, NULL);
}
