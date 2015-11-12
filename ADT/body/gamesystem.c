void gamesystem_start()
{
	bool finish = false;
	do {
		gamesystem_show_menu();
		int pilihan;
		read_with_limit(1, MENU_MAX, &pilihan);
		gamesystem_do_action(pilihan);
	} while (!finish);
}

void gamesystem_show_menu()
{
	
}

void gamesystem_do_action(int pilihan)
{
	switch (pilihan)
	{
		case 1:

	}
}
