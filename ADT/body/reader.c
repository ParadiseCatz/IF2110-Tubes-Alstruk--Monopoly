#include "../header/reader.h"
#include "stdio.h"

void read_with_limit(int mins, int maks, int * in)
{
	scanf("%d", in);
	while ( (*in) < mins || (*in) > maks)
	{
		printf("Input salah, silahkan masukan lagi\n");
		scanf("%d", in);
	}
}

void read_user_input(UserAction *userAction, Kata *parameter)
{
	printf("> ");
	Kata input;
	BacaKata(&input);
	if (IsKataSama(input, ConstructKata("roll")))
	{
		BacaKata(&input);
		*userAction = ROLL_DICE;
		return;
	}
	if (IsKataSama(input, ConstructKata("info")))
	{
		BacaKata(parameter);
		*userAction = INFO;
		return;
	}
	if (IsKataSama(input, ConstructKata("buy")))
	{
		*userAction = BUY;
		char dum;
		scanf("%c", &dum);
		if (dum != '\n')
		{
			*userAction = BUY_OFFERED;
			BacaKata(&input);
			BacaKata(parameter);
		}
		return;
	}
	if (IsKataSama(input, ConstructKata("sell")))
	{
		BacaKata(&input);
		if (IsKataSama(input, ConstructKata("bank")))
		{
			*parameter = input;
			*userAction = SELL_BANK;
			return;
		}
		else
		{
			*userAction = SELL;
			BacaKata(parameter);
			return;
		}
		return;
	}
	if (IsKataSama(input, ConstructKata("show")))
	{
		*userAction = SHOW_OFFERED;
		BacaKata(&input);
		return;
	}

	if (IsKataSama(input, ConstructKata("upgrade")))
	{
		*userAction = UPGRADE;
		return;
	}

	if (IsKataSama(input, ConstructKata("board")))
	{
		*userAction = BOARD;
		return;
	}
	if (IsKataSama(input, ConstructKata("leaderboard")))
	{
		*userAction = LEADERBOARD;
		return;
	}

	if (IsKataSama(input, ConstructKata("host")))
	{
		*userAction = HOST;
		BacaKata(parameter);
		return;
	}

	if (IsKataSama(input, ConstructKata("travel")))
	{
		*userAction = TRAVEL;
		BacaKata(parameter);
		return;
	}

	if (IsKataSama(input, ConstructKata("end")))
	{
		*userAction = END_TURN;
		BacaKata(&input);
		return;
	}
	if (IsKataSama(input, ConstructKata("save")))
	{
		*userAction = SAVE;
		BacaKata(parameter);
		return;
	}
	if (IsKataSama(input, ConstructKata("load")))
	{
		*userAction = LOAD;
		BacaKata(parameter);
		return;
	}

	if (IsKataSama(input, ConstructKata("free")))
	{
		BacaKata(&input);
		if (IsKataSama(input, ConstructKata("me")))
		{
			*userAction = FREE_ME;
			return;
		}
	}
	if (IsKataSama(input, ConstructKata("off")))
	{
		*userAction = OFF;
		BacaKata(parameter);
		return;
	}

	if (IsKataSama(input, ConstructKata("protect")))
	{
		*userAction = PROTECT;
		BacaKata(parameter);
		return;
	}

	if (IsKataSama(input, ConstructKata("double")))
	{
		*userAction = DOUBLE_MOVE;
		BacaKata(&input);
		return;
	}

	if (IsKataSama(input, ConstructKata("help")))
	{
		*userAction = HELP;
		return;
	}

	if (IsKataSama(input, ConstructKata("exit")))
	{
		*userAction = EXIT;
		return;
	}

	printf("! Input salah, silahkan ulangi lagi. !\n");
	read_user_input(userAction, parameter);
}
