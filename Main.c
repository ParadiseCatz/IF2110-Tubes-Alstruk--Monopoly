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
	int pilihan;
	read_with_limit(1, 2, &pilihan);
	if (pilihan == 1)
	{
		printf("Num of Player? ");
		read_with_limit(1, PLAYER_MAX, &pilihan);
		NewGame(pilihan);
		gamesystem_start();
	}
	else
	{
		printf("Slot Number? ");
		read_with_limit(1, SAVE_SLOT_MAX, &pilihan);
		LoadGame(pilihan);
		gamesystem_start();
	}
}

int main(int argc, char const *argv[])
{
	welcome_screen();
	start_menu();
	return 0;
}
