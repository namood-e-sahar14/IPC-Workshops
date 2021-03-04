
/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Namood-e-sehar
	ID     :121979207
	Email  :Namood-e-sahar
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#define path_length_min 10
#define path_length_max 70
#define path_length_criteria 5
#define min_num_of_lives 1
#define max_num_of_lives 10

struct PlayerInfo
{
	char char_symbol;
	int num_of_lives;
	int num_of_treasures;
	int	history[path_length_max];
};

struct GameInfo
{
	int num_of_moves;
	int path_length;
	int bombs[path_length_max];
	int treasures[path_length_max];

};

void printGameStatus(struct PlayerInfo p_info, struct GameInfo g_info, int symbol_position);
void printPlayerStatus(struct PlayerInfo p_info, struct GameInfo g_info);

int main()
{
	struct PlayerInfo player_info;
	struct GameInfo game_info;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &player_info.char_symbol);

	int go_num_of_lives = 1;
	while (go_num_of_lives == 1)
	{
		printf("Set the number of lives: ");
		scanf("%d", &player_info.num_of_lives);
		if (player_info.num_of_lives < min_num_of_lives || player_info.num_of_lives > max_num_of_lives)
		{
			printf("     Must be between 1 and 10!\n");
		}
		else if (player_info.num_of_lives >= min_num_of_lives && player_info.num_of_lives <= max_num_of_lives)
		{
			printf("Player configuration set-up is complete\n");
			go_num_of_lives = 0;
		}
	}
	printf("\nGAME Configuration\n");
	printf("------------------\n");

	int go_path_length = 1;
	while (go_path_length == 1)
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game_info.path_length);

		if (game_info.path_length < path_length_min || game_info.path_length > path_length_max || (game_info.path_length % path_length_criteria != 0))
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
		else if (game_info.path_length >= path_length_min && game_info.path_length <= path_length_max && (game_info.path_length % path_length_criteria == 0))
		{
			go_path_length = 0;
		}
	}

	int go_num_of_moves = 1;
	while (go_num_of_moves == 1)
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game_info.num_of_moves);
		if (game_info.num_of_moves < player_info.num_of_lives || game_info.num_of_moves >(int)(0.75 * game_info.path_length))
		{
			printf("    Value must be between %d and %d\n", player_info.num_of_lives, (int)(0.75 * game_info.path_length));
		}
		else if (game_info.num_of_moves >= player_info.num_of_lives && game_info.num_of_moves <= (int)(0.75 * game_info.path_length))
		{
			go_num_of_moves = 0;
		}
	}

	int divider = 5;
	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game_info.path_length);

	int i, j;
	for (i = 0; i < game_info.path_length / divider; i++)
	{
		printf("   Positions [%2d-%2d]: ", (divider * i + 1), divider * (i + 1));
		for (j = 0; j < divider; j++) {
			scanf("%d", &game_info.bombs[i * divider + j]);
		}
	}
	printf("BOMB placement set\n");
	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game_info.path_length);
	for (i = 0; i < game_info.path_length / divider; i++)
	{
		printf("   Positions [%2d-%2d]: ", (divider * i + 1), divider * (i + 1));
		for (j = 0; j < divider; j++) {
			scanf("%d", &game_info.treasures[i * divider + j]);
		}
	}

	printf("TREASURE placement set\n");
	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player_info.char_symbol);
	printf("   Lives      : %d\n", player_info.num_of_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\nGame:\n");
	printf("   Path Length: %d\n", game_info.path_length);
	printf("   Bombs      : ");
	for (i = 0; i < game_info.path_length;i++)
	{
		printf("%d", game_info.bombs[i]);
	}
	printf("\n");
	printf("   Treasure   : ");
	for (i = 0; i < game_info.path_length; i++)
	{
		printf("%d", game_info.treasures[i]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n\n");

	// part 2

	//initialize values

	for (i = 0; i < game_info.path_length; i++)
	{
		player_info.history[i] = 0;
	}
	player_info.num_of_treasures = 0;

	printGameStatus(player_info, game_info, 0);

	printPlayerStatus(player_info, game_info);

	int move, move_go, found, move_position, history_position = 0;

	while (player_info.num_of_lives > 0 && game_info.num_of_moves > 0)
	{
		move_go = 1;
		while (move_go == 1) {
			printf("Next Move [1 - %d]: ", game_info.path_length);
			scanf("%d", &move);


			if (move < 1 || move > game_info.path_length) {
				printf("Out of Range!!!\n");
			}
			else if (move >= 1 && move <= game_info.path_length)
			{
				move_go = 0;
			}
		}

		found = 0;
		for (j = 0; j < game_info.path_length; j++)
		{
			if (player_info.history[j] == move) {
				found = 1;
				break;
			}
		}

		// position for the move
		move_position = move - 1;

		if (found == 1) {

			printf("==============> Dope! You've been here before!\n");

			printGameStatus(player_info, game_info, move);

			printPlayerStatus(player_info, game_info);

			continue;

		}

		if (game_info.bombs[move_position] == 1 && game_info.treasures[move_position] == 1) {
			player_info.num_of_lives--;
			player_info.num_of_treasures++;
			printf("\n==============> [&] !!! BOOOOOM !!! [&]\n\n");
			printf("==============> [&] $$$ Life Insurance Payout!!! [&]\n");
		}
		else if (game_info.bombs[move_position] == 1) {
			player_info.num_of_lives--;
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
		}
		else if (game_info.treasures[move_position] == 1) {
			player_info.num_of_treasures++;
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
		}
		else if (game_info.treasures[move_position] == 0 && game_info.bombs[move_position] == 0) {
			printf("\n==============> [.] ... Nothing found here... [.]\n\n");
		}

		// record the move into history
		player_info.history[history_position] = move;
		history_position++;
		// decrease numbers of moves available
		game_info.num_of_moves--;

		if (player_info.num_of_lives == 0) {
			printf("No more LIVES remaining!\n");
		}
		else if (game_info.num_of_moves == 0) {
			printf("No more MOVES remaining!\n");
		}

		printGameStatus(player_info, game_info, move);

		printPlayerStatus(player_info, game_info);

	}

	printf("\n\n##################\n");
	printf("#   Game Over!   #\n");
	printf("##################");
	printf("\n\n You should play again and try to beat your score!!\n\n");

	return 0;
}

// ==============================================================
// print player status
void printPlayerStatus(struct PlayerInfo p_info, struct GameInfo g_info)
{

	printf("+----------------------------------------------------+\n");
	printf("  Lives: %d  |  Treasures: %d  |  Moves Remaining: %d", p_info.num_of_lives, p_info.num_of_treasures, g_info.num_of_moves);
	printf("\n+----------------------------------------------------+\n");

}

// print game status
void printGameStatus(struct PlayerInfo p_info, struct GameInfo g_info, int symbol_position)
{

	int found, position, j;

	for (j = 1; j <= symbol_position; j++)
	{
		if (j == symbol_position) {
			printf("  %c \n", p_info.char_symbol);
		}
		else {
			printf(" ");
		}
	}

	printf("  ");
	for (position = 0; position < g_info.path_length; position++)
	{
		found = 0;
		for (j = 0; j < g_info.path_length; j++)
		{
			if (p_info.history[j] == position + 1) {
				found = 1;
				break;
			}
		}

		if (found == 1) {
			if (g_info.bombs[position] == 1 && g_info.treasures[position] == 1) {
				printf("&");
			}
			else if (g_info.bombs[position] == 1) {
				printf("!");
			}
			else if (g_info.treasures[position] == 1) {
				printf("$");
			}
			else {
				printf(".");
			}
		}
		else {
			printf("-");
		}
	}
	printf("\n");

	printf("  ");
	for (position = 1; position <= g_info.path_length; position++)
	{
		if (position % 10 == 0) {
			printf("%d", position / 10);
		}
		else {
			printf("|");
		}
	}
	printf("\n");

	printf("  ");

	for (position = 1; position <= g_info.path_length; position++)
	{
		printf("%d", position % 10);
	}
	printf("\n");

}
