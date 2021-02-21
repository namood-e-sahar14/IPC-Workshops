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
	int history[path_length_max];
};

struct GameInfo
{
	int num_of_moves;
	int path_length;
	int bombs[path_length_max];
	int treasures[path_length_max];
};

void printPlayerStatus(struct PlayerInfo p_info, struct GameInfo g_info)

{

	int move, move_go, move_position;
	while (p_info.num_of_lives > 0 && g_info.num_of_moves > 0)
	{
		move_go = 1;
		while (move_go == 1) {
			printf("Next Move [1 - %d]", g_info.path_length);
			scanf("%d", &move);


			if (move < 1 || move > g_info.path_length) {
				printf("Out of Range!!!");
			}
			else (move > 1 || move < g_info.path_length)
			{
				move_go = 0; // bhai i want to code here if move == previous move then display the message
				//printf("=============> Dope! You've been here before");
			}
		}       move_position = move - 1;
		if (g_info.bombs[move_position] == 1 && g_info.treasures[move_position] == 1) {
			p_info.num_of_lives--;
			p_info.num_of_treasures++;
			printf("==============> [&] !!! BOOOOOM !!! [&]");
			printf("==============> [&] $$$ Life Insurance Payout!!! [&]");
		}
		else if (g_info.bombs[move_position] == 1) {
			p_info.num_of_lives--;
			printf("===============> [!] !!! BOOOOOM !!! [!]");
		}
		else if (g_info.treasures[move_position] == 1) {
			p_info.num_of_treasures++;
			printf("===============> [$] $$$ Found Treasure! $$$ [$]");
		}
		else (g_info.treasures[move_position] == 0 && g_info.bombs[move_position] == 0); {
			printf("===============> [.] ... Nothing found here... [.]");
		}
	}       g_info.num_of_moves--;
	printf("\n+----------------------------------------------------------+\n");
	printf("  Lives: %2d  |  Treasures: %2d  |  Moves Remaining: %2d\n", p_info.num_of_lives, g_info.treasures, move - g_info.num_of_moves);
	printf("\n+----------------------------------------------------------+");

	if (p_info.num_of_lives == 0) {
		printf("No more LIVES remaining!");
	}
	else if (g_info.num_of_moves == 0) {
		printf("No more MOVES remaining!");
	}
	printf("\n\n##################\n");
	printf("#   Game Over!   #\n");
	printf("##################");
	printf("\n\n You should play again and try to beat your score!!");

	printf("\n+----------------------------------------------------------+\n");
	printf("  Lives: %2d  |  Treasures: %2d  |  Moves Remaining: %2d\n", p_info.num_of_lives, g_info.treasures, move - g_info.num_of_moves);
	printf("\n+----------------------------------------------------------+");
}
void printGameStatus(struct PlayerInfo p_info, struct GameInfo g_info)
{
	int found, position, j;
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

	for (position = 1; position <= g_info.path_length; position++)
	{
		printf("%d", position % 10);
	}
	printf("\n");

}
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
	printf("====================================");
	printf("\n\n");


	//part 2

	for (i = 0; i < game_info.path_length; i++)
	{
		player_info.history[i] = 0;
	}

	// ==============================================================

	
	printPlayerStatus(struct PlayerInfo p_info, struct GameInfo g_info);

// print player status

	printGameStatus(struct PlayerInfo p_info, struct GameInfo g_info);

	
return 0;
}
