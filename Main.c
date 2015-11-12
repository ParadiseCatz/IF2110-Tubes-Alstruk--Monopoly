void welcome_screen()
{
	printf("Halo\n");
}

void start_menu()
{
	printf("Menu:\n");
	printf("1. New Game\n");
	printf("2. Load Game:\n");
	printf("Pilihan: ");
	int x;
	read_with_limit(1, 2, &x);
	if (x == 1)
	{
		printf("Num of Player?");
		read_with_limit(1, PLAYER_MAX, &x);
		NewGame(x);
		game_system_start();
	}
	else
	{
		printf("Slot Number?");
		read_with_limit(1, SAVE_SLOT_MAX, &x);
		NewGame(x);
		game_system_start();
	}
}

int main(int argc, char const *argv[])
{
	welcome_screen();
	start_menu();
	return 0;
}
