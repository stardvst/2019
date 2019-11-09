#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int num_ctrl_c = 0;

void catch_int(int singnum)
{
	sigset_t mask_set;
	sigset_t old_set;

	signal(SIGINT, catch_int);

	sigfillset(&mask_set);
	sigprocmask(SIG_SETMASK, &mask_set, &old_set);

	++num_ctrl_c;

	if (num_ctrl_c >= 5)
	{
		printf("Do you want to exit?");
		fflush(stdout);

		char c;
		scanf("%c", &c);
		if (c == 'y')
		{
			printf("Exiting...\n");
			fflush(stdout);
			exit(0);
		}
		if (c == 'n')
		{
			printf("Continuing...\n");
			fflush(stdout);
			num_ctrl_c = 0;
		}
	}

	sigprocmask(SIG_SETMASK, &mask_set, &old_set);
}

void catch_susp(int signum)
{
	sigset_t mask_set;
	sigset_t old_set;

	signal(SIGTSTP, catch_susp);

	sigfillset(&mask_set);
	sigprocmask(SIG_SETMASK, &mask_set, &old_set);

	printf("# of Ctrl+C: %d", num_ctrl_c);
	fflush(stdout);

	sigprocmask(SIG_SETMASK, &mask_set, NULL);
}

void main()
{
	signal(SIGINT, catch_int);
	signal(SIGTSTP, catch_susp);
	for (; ; )
		pause();
}