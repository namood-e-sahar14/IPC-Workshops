
/*
	==================================================
	Workshop #5 (Part-1):
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
};

struct GameInfo
{
	int num_of_moves;
	int path_length;
	int bombs[path_length_max];
	int treasures[path_length_max];
	
};

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
	scanf("%c",&player_info.char_symbol);

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
			printf("    Value must be between %d and %d\n", player_info.num_of_lives,(int) (0.75 * game_info.path_length));
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

	int i,j;
	for (i = 0; i < game_info.path_length / divider; i++) 
	{
	printf("   Positions [%2d-%2d]: ", (divider * i + 1), divider * (i + 1));
	for (j = 0; j < divider; j++) {
		scanf("%d", &game_info.bombs[i * divider + j]);
	}
}
	/*int range_start_bomb = 0;
	for (int i = 0; i < (game_info.path_length / path_length_criteria); i++)
	{
		printf("   Positions [%d - %d]: ", range_start_bomb + 1, range_start_bomb + 5);
		scanf("%d %d %d %d %d",
			&game_info.bombs[range_start_bomb], 
			&game_info.bombs[range_start_bomb + 1],
			&game_info.bombs[range_start_bomb + 2],
			&game_info.bombs[range_start_bomb+ 3],
			&game_info.bombs[range_start_bomb + 4]);

		range_start_bomb = range_start_bomb + 5;
	}*/
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
	//int range_start_treasures = 0;
	//for (int i = 0; i < (game_info.path_length / path_length_criteria); i++)
	//{
	//	printf("   Position [%d - %d]: ", range_start_treasures + 1, range_start_treasures + 5);
	//	scanf("%d %d %d %d %d",
	//		&game_info.treasures[range_start_treasures], 
	//		&game_info.treasures[range_start_treasures + 1],
	//		&game_info.treasures[range_start_treasures + 2],
	//		&game_info.treasures[range_start_treasures + 3],
	//		&game_info.treasures[range_start_treasures + 4]);

	//	range_start_treasures = range_start_treasures + 5;
	//}
	printf("TREASURE placement set\n");
	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n",player_info.char_symbol);
	printf("   Lives      : %d\n",player_info.num_of_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\nGame:\n");
	printf("   Path Length: %d\n",game_info.path_length);
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



	return 0;
}


