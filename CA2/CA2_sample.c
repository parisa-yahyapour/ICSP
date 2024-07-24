#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define size_of_cards 11
#define type_of_cards 4
#define chossen_cards_size 4
#define game_round_number 6
#define set_round_number 5
#define first_card_type_none 4
#define player1_number 0
#define player2_number 1
#define player3_number 2
#define player4_number 3
#define win_point 6
void shuffle_card(int* card)
{
	int i, r, temp;
	for (temp = 0, i = 0; temp < size_of_cards*type_of_cards; i++, temp++)
		card[temp] = i;
	srand(time(NULL));
	for (i = (size_of_cards*type_of_cards)-1; i > 0; i--) {
		r = rand() % i;
		temp = card[i];
		card[i] = card[r];
		card[r] = temp;
	}
}

void set_bakhshname(int* bakhshname)
{
	int temp;
	printf("set bakhshname by 0 to 3 number:");
	if (scanf("%d", &temp))
	{
		if (temp<4 && temp >= 0)
		{
			*bakhshname = temp;
		}
		else
		{
			printf("wrong input try again\n");
			set_bakhshname(bakhshname);
		}
	}
	else
	{
		printf("wrong input try again\n");
		scanf("%*[^\n]");
		set_bakhshname(bakhshname);
	}
		

}

char find_card_type(int p_chossen_card)
{
	char result = 'f';
	int type = p_chossen_card / 11;
	switch (type)
	{
	case 0:
		result = 'A';
		break;
	case 1:
		result = 'B';
		break;
	case 2:
		result = 'C';
		break;
	case 3:
		result = 'D';
		break;
	default:
		result = ' ';
		break;
	}
	return result;
}

void table(int* p_cards, int* chossen_cards, int team1_score, int team2_score ,int team1_set_score ,int team2_set_score)
{
	int p1_card_number, p2_card_number, p3_card_number, p4_card_number;
	char p1_card_type, p2_card_type, p3_card_type, p4_card_type;
	if (chossen_cards[0]<size_of_cards*type_of_cards && chossen_cards[0] >= 0)
	{
		p1_card_number = (chossen_cards[0] % 11) + 1;
		p1_card_type = find_card_type(chossen_cards[0]);

	}
	else
	{
		p1_card_number = NULL;

		p1_card_type = ' ';


	}
	if (chossen_cards[1] < size_of_cards*type_of_cards && chossen_cards[1] >= 0)
	{
		p2_card_number = (chossen_cards[1] % 11) + 1;
		p2_card_type = find_card_type(chossen_cards[1]);

	}
	else
	{
		p2_card_number = NULL;
		p2_card_type = ' ';

	}
	if (chossen_cards[2]<size_of_cards*type_of_cards && chossen_cards[2] >= 0)
	{
		p3_card_number = (chossen_cards[2] % 11) + 1;
		p3_card_type = find_card_type(chossen_cards[2]);

	}
	else
	{
		p3_card_number = NULL;
		p3_card_type = ' ';

	}
	if (chossen_cards[3]<size_of_cards*type_of_cards && chossen_cards[3] >= 0)
	{
		p4_card_number = (chossen_cards[3] % 11) + 1;
		p4_card_type = find_card_type(chossen_cards[3]);
	}
	else
	{
		p4_card_number = NULL;
		p4_card_type = ' ';
	}
	//system("cls");
	printf("                                    P3                                 ");
	printf("\n");
	printf("   --------------------------------------------------------------------");
	printf("\t\t\tteam1:%d", team1_score);
	printf("\t\tteam1 sets:%d", team1_set_score);
	printf("\n");
	printf("                                    %c%d                                 ", p3_card_type, p3_card_number);
	printf("\n");
	for (int i = 0; i < 7; i++)
	{
		printf("   |                                                                  |");
		printf("\n");
	}
	if (p2_card_number>10)
	{
		if (p4_card_number>10)
		{
			printf(" P2| %c%d                                                          %c%d |P4\n", p2_card_type, p2_card_number, p4_card_type, p4_card_number);
		}
		else
		{
			printf(" P2| %c%d                                                           %c%d |P4\n", p2_card_type, p2_card_number, p4_card_type, p4_card_number);
		}
	}
	else
	{
		if (p4_card_number>10)
		{
			printf(" P2| %c%d                                                           %c%d |P4\n", p2_card_type, p2_card_number, p4_card_type, p4_card_number);
		}
		else
		{
			printf(" P2| %c%d                                                            %c%d |P4\n", p2_card_type, p2_card_number, p4_card_type, p4_card_number);
		}
	}

	for (int i = 0; i < 7; i++)
	{
		printf("   |                                                                  |");
		printf("\n");
	}
	printf("                                    %c%d                                 ", p1_card_type, p1_card_number);
	printf("\n");
	printf("   --------------------------------------------------------------------");
	printf("\t\t\tteam2:%d", team2_score);
	printf("\t\tteam2 sets:%d", team2_set_score);
	printf("\n");
	printf("                                    P1                                 ");
	printf("\n");


}

void make_cards_zero(int* p_card)
{
	for (int i = 0; i < type_of_cards; i++)
	{
		for (int j = 0; j < size_of_cards; j++)
		{
			*((p_card+ i*size_of_cards) + j) = 0;
		}
	}
}

void start_cards_zero(int* p1_cards, int* p2_cards, int* p3_cards, int* p4_cards)
{
		make_cards_zero(p1_cards);
		make_cards_zero(p2_cards);
		make_cards_zero(p3_cards);
		make_cards_zero(p4_cards);
}

void divide_cards(int* cards,int*p_card,int start_point,int round_num)
{
	int row=0, column=0;
	for (int i = start_point; i <start_point+ round_num; i++)
	{
		row = cards[i] / size_of_cards;
		column = cards[i] % size_of_cards;
		*((p_card + row*size_of_cards) + column) = 1;
	}
}

void player1_cards_diplay(int* p_cards)
{
	printf("          ----------------------------------------------------");
	printf("\n");
	printf("          symbol |");
	for (int i = 0; i <type_of_cards; i++)
	{
		for (int j = 0; j < size_of_cards; j++)
		{
			if (*((p_cards + i*size_of_cards) + j) == 1)
			{
				switch (i)
				{
				case 0:
					printf(" A |");
					continue;
				case 1:
					printf(" B |");
					continue;
				case 2:
					printf(" C |");
					continue;
				case 3:
					printf(" D |");
					continue;
				default:
					continue;
				}
			}
		}
	}
	printf("\n");
	printf("          number |");
	for (int i = 0; i <type_of_cards; i++)
	{
		for (int j = 0; j < size_of_cards; j++)
		{
			if (*((p_cards + i*size_of_cards) + j) == 1)
			{
				if (j<9)
				{
					printf(" %d |", j + 1);
				}
				else
				{
					printf(" %d|", j + 1);
				}

			}
		}
	}
	printf("\n");
	printf("          ----------------------------------------------------");
	printf("\n");
    printf("          index  |");
	for (int j = 0; j < size_of_cards; j++)
	{
		if (j<9)
		{
			printf(" %d |", j + 1);
		}
		else
		{
			printf(" %d|", j + 1);
		}
	}
    printf("\n");
    printf("          ----------------------------------------------------");
	printf("\n");
}

void full_cards_divide(int* cards, int*p1_cards, int*p2_cards, int*p3_cards, int*p4_cards, int* bakhshname,  int team1_set_score, int team2_set_score)
{
	int c[4] = { 100, 100, 100, 100 };
	divide_cards(cards, p1_cards, 0, 5);
	divide_cards(cards, p2_cards, 5, 5);
	divide_cards(cards, p3_cards, 10, 5);
	divide_cards(cards, p4_cards, 15, 5);
	table(p1_cards, c, 0, 0, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);
	set_bakhshname(bakhshname);
	divide_cards(cards, p1_cards, 20, 4);
	divide_cards(cards, p2_cards, 24, 4);
	divide_cards(cards, p3_cards, 28, 4);
	divide_cards(cards, p4_cards, 32, 4);
	divide_cards(cards, p1_cards, 36, 2);
	divide_cards(cards, p2_cards, 38, 2);
	divide_cards(cards, p3_cards, 40, 2);
	divide_cards(cards, p4_cards, 42, 2);
}

void show_player_cards(int p_card[type_of_cards][size_of_cards])
{
	int i, j;
	for (i = 0; i < type_of_cards; i++){
		for (j = 0; j < size_of_cards; j++){
			printf("%d ", p_card[i][j]);
		}
		printf("\n");
	}
	printf("----------\n");
}

void first_player_start_act(int* chossen_cards, int* p_cards, int* first_card_type, int* game_number)
{
	int num = 0;
	int limit_input = size_of_cards - *game_number;
	printf("it's your turn\n");
	printf("chose your card by number 1 to %d:",limit_input);
	if (scanf("%d",&num))
	{
		if (num>0 && num<=limit_input)
		{
			int check = 0;
			for (int row = 0; row < type_of_cards; row++)
			{
				for (int column = 0; column < size_of_cards; column++)
				{
					if (*((p_cards + row*size_of_cards) + column) == 1)
					{
						check++;
						if (check==num)
						{
							*((p_cards + row*size_of_cards) + column) = 0;
							chossen_cards[0] = row*size_of_cards + column;
							*first_card_type = row;
						}
					}
					
				}
			}
		}
		else
		{
			printf("wrong input try again\n");
			first_player_start_act(chossen_cards, p_cards, first_card_type, game_number);
		}
	}
	else
	{
		printf("wrong input try again\n");
		scanf("%*[^\n]");
		first_player_start_act(chossen_cards, p_cards, first_card_type, game_number);
	}

}

int able_to_play(int* p_cards, int first_card_type)
{
	int check = 0;
	for (int column = 0; column < size_of_cards; column++)
	{
		if (*((p_cards + first_card_type*size_of_cards) + column) == 1)
			check = 1;
	}
	return check;
}

void first_player_second_act(int* chossen_cards, int* p_cards, int first_card_type, int* game_number)
{
	int num = 0;
	int limit_input = size_of_cards - *game_number;
	printf("it's your turn\n");
	printf("chose your card by number 1 to %d:", limit_input);
	if (scanf("%d", &num))
	{
		if (able_to_play(p_cards, first_card_type))
		{
			if (num>0 && num <= limit_input)
			{
				int check = 0;
				for (int row = 0; row < type_of_cards; row++)
				{
					for (int column = 0; column < size_of_cards; column++)
					{
						if (*((p_cards + row*size_of_cards) + column) == 1)
						{
							check++;
							if (check == num && row == first_card_type)
							{
								*((p_cards + row*size_of_cards) + column) = 0;
								chossen_cards[0] = row*size_of_cards + column;
							}
							else if (check == num && row != first_card_type)
							{
								printf("you can't paly this card\n");
								first_player_second_act(chossen_cards, p_cards, first_card_type, game_number);
							}
						}

					}
				}
			}
			else
			{
				printf("wrong input try again\n");
				scanf("%*[^\n]");
				first_player_second_act(chossen_cards, p_cards, first_card_type, game_number);
			}

		}
		else
		{
			if (num>0 && num <= limit_input)
			{
				int check = 0;
				for (int row = 0; row < type_of_cards; row++)
				{
					for (int column = 0; column < size_of_cards; column++)
					{
						if (*((p_cards + row*size_of_cards) + column) == 1)
						{
							check++;
							if (check == num)
							{
								*((p_cards + row*size_of_cards) + column) = 0;
								chossen_cards[0] = row*size_of_cards + column;
							}
						}

					}
				}
			}
			else
			{
				printf("wrong input try again\n");
				first_player_second_act(chossen_cards, p_cards, first_card_type, game_number);
			}
		}
	}
	else
	{
		printf("wrong input try again\n");
		scanf("%*[^\n]");
		first_player_second_act(chossen_cards, p_cards, first_card_type, game_number);
	}
		
}

void bot_firstplayer_act(int* chossen_cards, int* p_cards, int* first_card_type, int* game_number, int bakhshname,int player_num)
{
	int check = 0;
	for (int column = size_of_cards-1; column >= 0;column--)
	{
		for (int row = 0; row < type_of_cards; row++)
		{
			if (*((p_cards + row*size_of_cards) + column) == 1 && row != bakhshname)
			{
				
				
					*first_card_type = row;
					chossen_cards[player_num] = row*size_of_cards + column;
					*((p_cards + row*size_of_cards) + column) = 0;
					check = 1;
					break;
				
			}

		}
		if (check)
		{
			break;
		}
	}
	if (!check)
	{
		for (int column = size_of_cards-1; column >= 0; column--)
		{
			if (*((p_cards + bakhshname*size_of_cards) + column) == 1)
			{


				*first_card_type = bakhshname;
				chossen_cards[player_num] = bakhshname*size_of_cards + column;
				*((p_cards + bakhshname*size_of_cards) + column) = 0;
				check = 1;
				break;


			}
		}
	}
}

void bot_secondplayer_act(int* chossen_cards, int* p_cards, int first_card_type, int* game_number, int bakhshname, int player_num)
{
	if (able_to_play(p_cards, first_card_type))
	{
		for (int column = size_of_cards - 1; column >= 0; column--)
		{
			if (*((p_cards + first_card_type*size_of_cards) + column) == 1)
			{
				chossen_cards[player_num] = first_card_type*size_of_cards + column;
				*((p_cards + first_card_type*size_of_cards) + column) = 0;
				break;
			}
		}
	}
	else
	{
		if (able_to_play(p_cards, bakhshname))
		{
			for (int column = size_of_cards - 1; column >= 0; column--)
			{
				if (*((p_cards + bakhshname*size_of_cards) + column) == 1)
				{
					chossen_cards[player_num] = bakhshname*size_of_cards + column;
					*((p_cards + bakhshname*size_of_cards) + column) = 0;
					break;
				}
			}
		}
		else
		{
			int check = 0;
			for (int column = 0; column < size_of_cards; column++)
			{
				for (int row = 0; row < type_of_cards; row++)
				{
					if (*((p_cards + row*size_of_cards) + column) == 1)
					{
						chossen_cards[player_num] = row*size_of_cards + column;
						check = 1;
						break;
					}

				}
				if (check)
				{
					break;
				}
			}
		}
	}
}

int winner_check(int* chossen_cards, int first_card_type, int bakhshname,int starter)
{
	int winner = starter;
	int maxi;
	maxi = chossen_cards[starter] % size_of_cards;
	for (int i = 0; i < chossen_cards_size; i++)
	{
		int check1, check2;
		check1 = chossen_cards[i] % size_of_cards;
		check2 = chossen_cards[i] / size_of_cards;
		if (check1 > maxi && check2 == first_card_type)
		{
			maxi = chossen_cards[i] % size_of_cards;
			winner = i;
		}
	}
	if (chossen_cards[winner] / 11 != bakhshname)
	{
		int max_bakhshname;
		int played_bakhshname[4] = {-1, -1, -1, -1 };
		for (int i = 0; i < chossen_cards_size; i++)
		{
			if ((chossen_cards[i] / size_of_cards)==bakhshname)
			{
				played_bakhshname[i] = chossen_cards[i] % size_of_cards;
                winner = i;
			}
		}
		max_bakhshname = played_bakhshname[0];
		for (int i = 0; i < chossen_cards_size; i++)
		{
			if (played_bakhshname[i] > max_bakhshname)
			{
				max_bakhshname = played_bakhshname[i];
				winner = i;
			}
		}
	}
	return winner;
}

void senario1(int* chossen_cards, int*p1_cards, int*p2_cards, int*p3_cards, int*p4_cards, int*first_card_type, int*game_number, int team1_score, int team2_score, int team1_set_score, int team2_set_score, int bakhshname)
{
	// first play
	first_player_start_act(chossen_cards, p1_cards, first_card_type, game_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	// bots play

	bot_secondplayer_act(chossen_cards, p2_cards, *first_card_type, game_number, bakhshname, player2_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	bot_secondplayer_act(chossen_cards, p3_cards, *first_card_type, game_number, bakhshname, player3_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	bot_secondplayer_act(chossen_cards, p4_cards, *first_card_type, game_number, bakhshname, player4_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

}

void senario2(int* chossen_cards, int*p1_cards, int*p2_cards, int*p3_cards, int*p4_cards, int*first_card_type, int*game_number, int team1_score, int team2_score, int team1_set_score, int team2_set_score, int bakhshname)
{
	bot_firstplayer_act(chossen_cards, p2_cards, first_card_type, game_number, bakhshname, player2_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	bot_secondplayer_act(chossen_cards, p3_cards, *first_card_type, game_number, bakhshname, player3_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	bot_secondplayer_act(chossen_cards, p4_cards, *first_card_type, game_number, bakhshname, player4_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	first_player_second_act(chossen_cards, p1_cards, *first_card_type, game_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);
}

void senario3(int* chossen_cards, int*p1_cards, int*p2_cards, int*p3_cards, int*p4_cards, int*first_card_type, int*game_number, int team1_score, int team2_score, int team1_set_score, int team2_set_score, int bakhshname)
{
	bot_firstplayer_act(chossen_cards, p3_cards, first_card_type, game_number, bakhshname, player3_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	bot_secondplayer_act(chossen_cards, p4_cards, *first_card_type, game_number, bakhshname, player4_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	first_player_second_act(chossen_cards, p1_cards, *first_card_type, game_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	bot_secondplayer_act(chossen_cards, p2_cards, *first_card_type, game_number, bakhshname, player2_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();
}

void senario4(int* chossen_cards, int*p1_cards, int*p2_cards, int*p3_cards, int*p4_cards, int*first_card_type, int*game_number, int team1_score, int team2_score, int team1_set_score, int team2_set_score, int bakhshname)
{
	bot_firstplayer_act(chossen_cards, p4_cards, first_card_type, game_number, bakhshname, player4_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	first_player_second_act(chossen_cards, p1_cards, *first_card_type, game_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	bot_secondplayer_act(chossen_cards, p2_cards, *first_card_type, game_number, bakhshname, player2_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();

	bot_secondplayer_act(chossen_cards, p3_cards, *first_card_type, game_number, bakhshname, player3_number);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);

	getch();
}
void bakhshname_game_play()
{
	int bakhshname = 0;
	int first_card_type = first_card_type_none;
	int game_number = 0;
	int team1_score = 0, team2_score = 0;
	int team1_set_score = 0, team2_set_score = 0;
	int winner_check_var = 4;
	int cards[size_of_cards*type_of_cards];
	shuffle_card(cards);
	int p1_cards[type_of_cards][size_of_cards];
	int p2_cards[type_of_cards][size_of_cards];
	int p3_cards[type_of_cards][size_of_cards];
	int p4_cards[type_of_cards][size_of_cards];
	int chossen_cards[chossen_cards_size];
	//begining game
	start_cards_zero(p1_cards, p2_cards, p3_cards, p4_cards);
	full_cards_divide(cards, p1_cards, p2_cards, p3_cards, p4_cards, &bakhshname, team1_set_score, team2_set_score);
	table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
	player1_cards_diplay(p1_cards);
	senario1(chossen_cards, p1_cards, p2_cards, p3_cards, p4_cards, &first_card_type, &game_number, team1_score, team2_score, team1_set_score, team2_set_score, bakhshname);
	// winner check
	winner_check_var = winner_check(chossen_cards, first_card_type, bakhshname, player1_number);
	// pointing
	if (winner_check_var == player1_number || winner_check_var == player3_number)
	{
		team1_score++;
	}
	else
	{
		team2_score++;
	}
	for (int i = 0; i < chossen_cards_size; i++)
	{
		chossen_cards[i] = -1;
	}
	for (int i = 0; i < size_of_cards; i++)
	{
		switch (winner_check_var)
		{
		case player1_number:
			senario1( chossen_cards, p1_cards, p2_cards, p3_cards, p4_cards, &first_card_type, &game_number,  team1_score,  team2_score,  team1_set_score,  team2_set_score, bakhshname);
			winner_check_var = winner_check(chossen_cards, first_card_type, bakhshname, player1_number);
			break;
		case player2_number:
			senario2(chossen_cards, p1_cards, p2_cards, p3_cards, p4_cards, &first_card_type, &game_number, team1_score, team2_score, team1_set_score, team2_set_score, bakhshname);
			winner_check_var = winner_check(chossen_cards, first_card_type, bakhshname, player2_number);
			break;
		case player3_number:
			senario3(chossen_cards, p1_cards, p2_cards, p3_cards, p4_cards, &first_card_type, &game_number, team1_score, team2_score, team1_set_score, team2_set_score, bakhshname);
			winner_check_var = winner_check(chossen_cards, first_card_type, bakhshname, player3_number);
			break;
		case player4_number:
			senario4(chossen_cards, p1_cards, p2_cards, p3_cards, p4_cards, &first_card_type, &game_number, team1_score, team2_score, team1_set_score, team2_set_score, bakhshname);
			winner_check_var = winner_check(chossen_cards, first_card_type, bakhshname, player4_number);
			break;
		default:
			break;
		}
		
		// pointing
		if (winner_check_var == player1_number || winner_check_var == player3_number)
		{
			team1_score++;
		}
		else
		{
			team2_score++;
		}

		// winning check 
		if (team1_score==win_point)
		{
			printf("time 1 has won\n");
			getch();
			break;
		}
		else if (team2_score == win_point)
		{
			printf("time 2 has won\n");
			getch();
			break;
		}
		for (int j = 0; j < chossen_cards_size; j++)
		{
			chossen_cards[j] = -1;
		}
		table(p1_cards, chossen_cards, team1_score, team2_score, team1_set_score, team2_set_score);
		player1_cards_diplay(p1_cards);
	}
}
int main()
{
	bakhshname_game_play();
}