#include <stdio.h>
#include <string.h>
#include <conio.h>

#define messages_max_len 100
static int messages_len = 0;
static int message_num = 0;
char *messages[messages_max_len];

void messageAdd(char *msg)
{
	if (messages_len == 0)
		memset(messages, 0, sizeof(messages));

	messages[messages_len++] = msg;
	if (messages_len == messages_max_len)
		messages_len = 0;
}

char *messageGet(void)
{
	char *msg = messages[message_num++];
	return msg;
}

void main()
{
	messageAdd("Text 1");
	messageAdd("Text 2");
	messageAdd("Text 3");

	char *msg;
	while ((msg = messageGet()) != NULL)
		printf("%s\n", msg);

	(void)_getch();
}
