//GLADIATOR
//Ahmet O�uz Ergin
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<math.h>
#include<windows.h>
#define SIZE 8
//
// lvl money hunger respect HP ATK DEF CRT
//  0    1     2       3     4  5   6   7

//
//gold -->  hafif a��r  silah z�rh iksir
//            0     1     2    3     4

void opening(char name[], int* namesize, double power[], double gold[],double enemy[])
{
	FILE* namehero;
	FILE* hero;
	FILE* shopp;
	FILE* enemi;
	char choice;

	//welcome user
	printf("- Y - Yeni oyun\n- K - Kay�tl� oyun: ");
	do {
		scanf(" %c", &choice);
		if ((choice != 'K' && choice != 'Y' && choice != 'y' && choice != 'k'))
			do
			{
				printf("Ge�ersiz se�im, tekrar gir: ");
				scanf(" %c", &choice);
			} while (choice != 'K' && choice != 'Y' && choice != 'y' && choice != 'k');
			if (choice == 'y' || choice == 'Y')
			{
				printf("Yeni oyuna ba�lamak istedi�ine emin misin?\n");
				printf("- E - Evet\n");
				printf("- H - Hay�r: ");
				scanf(" %c", &choice);
			}
			if (choice == 'E' || choice == 'e')
				choice = 'y';
			else
				choice = 'k';
	} while (choice != 'K' && choice != 'Y' && choice != 'y' && choice != 'k');

	//new game opening
	if (choice == 'Y' || choice == 'y')
	{
		//opening
		{
			printf("\n******************************************************************");
			printf("\nBu an yeni bir hikayenin ba�lang�c� de�il, bir kahraman�n do�u�u!");
			printf("\nL�tfen oyuncu ad�n�z� girin: ");
		}

		//get the name
		{
			*namesize = 0;
			scanf(" %c", &name[*namesize]);
			*namesize = 1;
			while (name[*namesize - 1] != '\n')
			{
				scanf("%c", &name[*namesize]);
				(*namesize)++;
			}
			name[*namesize - 1] = '\0';

			namehero = fopen("name.txt", "w");
			fprintf(namehero, "%s", name);
			fclose(namehero);
		}

		//display messages
		{
			printf("\nHo�geldin %s. Bir gladyat�r olarak se�eneklerinin ne kadar �nemli oldu�unu unutma.\n", name);
			printf("Can puan�na, a�l���na ve sayg�nl���na dikkat ederek hayatta kalmaya �al��.\n");
			printf("Can, Atak, Defans, Kritik gibi �zelliklerin bulunmakta ve level atlad�k�a bunlar� artt�rabilirsin.\nBir gladyat�r olarak arena'da sava�.\n");
			printf("Kasabada istedi�ini yapmakta �zg�rs�n.\nAkl�n�n kar��t��� yerde bilgi se�ene�ini kullanarak neler yapabilece�ini ��renebilirsin...");
			Sleep(7000);
		}

		//assign character points
		{
			hero = fopen("hero.txt", "w");
			//            lvl money hunger res HP ATK DEF CRT
			fprintf(hero, "0 1000 70 50 30 3 10 10");
			fclose(hero);
			hero = fopen("hero.txt", "r");
			for (int i = 0; i < SIZE; i++)
				fscanf(hero, "%lf", &power[i]);
			fclose(hero);
		}

		//assign gold to shop
		{
			shopp = fopen("shop.txt", "w");
			fprintf(shopp, "100 100 100 100 100 2000");
			fclose(shopp);

			shopp = fopen("shop.txt", "r");
			fscanf(shopp, "%lf%lf%lf%lf%lf%lf", &gold[0], &gold[1], &gold[2], &gold[3], &gold[4], &gold[5]);
			fclose(shopp);
		}

		//assign arena enemy statistics
		{
			enemi = fopen("enemy.txt", "w");
			fprintf(enemi, "25 3 10 10");
			fclose(enemi);

			enemi = fopen("enemy.txt", "r");
			for (int i = 0; i < 4; i++)
				fscanf(enemi, " %lf", &enemy[i]);
			fclose(enemi);
		}
	}

	//load game
	else
	{
		namehero = fopen("name.txt", "r");
		if (namehero == NULL)
			printf("Kay�tl� veri bulunmamakta.");
		else
		{
			//get name
			{
				*namesize = 0;
				while (fscanf(namehero, "%c", &name[*namesize]) != EOF)
					(*namesize)++;
				name[*namesize] = '\0';
				fclose(namehero);
			}

			//get statistics
			{
				hero = fopen("hero.txt", "r");
				for (int i = 0; i < SIZE; i++)
					fscanf(hero, "%lf", &power[i]);
				fclose(hero);

				//for (int i = 0; i < SIZE; i++)
					//printf("%.0f", power[i]);
			}

			//get price of shops
			{
				shopp = fopen("shop.txt", "r");
				for (int i = 0; i < 6; i++)
					fscanf(shopp, "%lf", &gold[i]);
				fclose(shopp);
			}

			//get the enemy of arena statistics
			{
				enemi = fopen("enemy.txt", "r");
				for (int i = 0; i < 4; i++)
					fscanf(enemi, "%lf", &enemy[i]);
				fclose(enemi);
			}
		}
	}
	printf("\n\n");
}

void displaygate(void)
{
	printf("                                         *                        \n");
	printf("                                        ***                       \n");
	printf("                     *                *******                *    \n");
	printf("                    ***             ***********             ***   \n");
	printf("                   *****          ***************          *****  \n");
	printf("                  *******       *******************       ******* \n");
	printf("                 *************************************************\n");
	printf("                ****************|                 |****************\n");
	printf("                ****************|                 |****************\n");
	printf("                ****************|                 |****************\n");
	printf("                ****************|                 |****************\n");
	printf("                ****************|                 |****************\n");
	printf("                ****************|                 |****************\n");
	printf("                ****************|                 |****************\n\n");
	Sleep(500);
}

void displaytree(char name[])
{
	printf("                  *                                                    *        \n");
	printf("                * * *                                                * * *      \n");
	printf("               * o * *                                              * * o *     \n");
	printf("              * * * * *                                            * * * * *    \n");
	printf("             * * * O * *                                          * O * * / *   \n");
	printf("               * * * *                                              * * * *     \n");
	printf("             * * * * 0 *                                          * / * * 0 *   \n");
	printf("            * * o * * * *                                        * * o * * * *  \n");
	printf("           * O * * * O * *                                      * O * * * O * * \n");
	printf("          * * * * 0 * * * *                                    * * * * 0 * * * *\n");
	printf("                #####                                                #####\n");
	printf("                #####                                                #####\n");
	printf("                #####                                                #####\n");
	printf("                #####                                                #####\n");
	printf("\n                            Kasabaya ho�geldin gladyat�r %s\n\n", name);
	Sleep(250);
}

void savegame(double power[], double gold[], double enemy[])
{
	FILE* hero;
	FILE* shopp;
	FILE* enemi;

	//decrease hunger
	if (power[2] != 0)
		power[2] -= 5;

	//save game
	hero = fopen("hero.txt", "w");
	for (int r = 0; r < SIZE; r++)
		fprintf(hero, "%f ", power[r]);
	fclose(hero);

	shopp = fopen("shop.txt", "w");
	for (int i = 0; i < 6; i++)
		fprintf(shopp, "%f ", gold[i]);
	fclose(shopp);

	enemi = fopen("enemy.txt", "w");
	for (int i = 0; i < 4; i++)
		fprintf(enemi, "%f ", enemy[i]);
	fclose(enemi);

	printf("\nBilgilerin g�venli bir �ekilde kaydedildi.\n");
	printf("\n\n");
}

void arena(char name[], double power[], double gold[], double enemy[])
{
	int pos,heroo,enemyy,flag=1;
	char choice;
	heroo = power[4], enemyy = enemy[0];

	displaygate();

	//display the enterance and get the choice
	{	
		printf("                                 Sava� zaman� %s\n", name);
		printf("                            ***************************\n\n");
		Sleep(500);
		printf("                %s                    VS                D��man\n", name);
		printf("   *******************************************************************************\n");
		printf("     Can    Atak     Defans    Kritik    ||     Can    Atak     Defans    Kritik\n");
		printf("%8.f%7.f%10.f%10.f%16.f%7.f%10.f%10.f\n", power[4], power[5], power[6], power[7], enemy[0], enemy[1], enemy[2], enemy[3]);
		printf("   *******************************************************************************\n");
		Sleep(500);
		printf("\n- S - Sava�\n");
		printf("- K - Ka�\n");
		printf("- B - Bilgi\n");
		do {
			printf("Se�imini yap: ");
			scanf(" %c", &choice);
			if (choice != 's' && choice != 'S' && choice != 'k' && choice != 'K' && choice != 'b' && choice != 'B')
				printf("ge�ersiz, ");
		} while (choice != 's' && choice != 'S' && choice != 'k' && choice != 'K' && choice != 'b' && choice != 'B');
	}

	//check the respect and hunger
	if (power[3] < 70)
	{
		printf("\nArenada sava�abilmek i�in sayg� toplaman laz�m.");
		Sleep(3000);
	}
	else
	{
		if( power[2]<50)
			printf("\nArenada sava�abilmek i�in karn�n� doyurman gerekir.");
		else
		{

			if (choice == 'b' || choice == 'B')
			{
				printf("\nArenada sava�arak level atlay�p g��lenirsin.\n");
				printf("Kazand�k�a level atlars�n, g��lenir ve alt�n kazan�rs�n.\n");
				printf("Ayn� zamanda gittik�e d��man�n g�c� de artar.\n");
				printf("3 farkl� sald�r� 3 t�r� vard�r.\n");
				printf("H�zl� sald�r�da sald�rma �ans�n daha y�ksektir ama hasar, atak puan�n kadard�r.\n");
				printf("Normal sald�r�da sald�rma �ans�n daha d���k ama hasar biraz daha fazlad�r.\n");
				printf("G��l� sald�r�da sald�rma �ans�n d���k ama hasar�n daha fazlad�r.\n\n");
				printf("- S - Sava�\n");
				printf("- K - Ka�\n");
				do {
					printf("Se�imini yap: ");
					scanf(" %c", &choice);
					if (choice != 's' && choice != 'S' && choice != 'K' && choice != 'k')
						printf("Ge�ersiz se�im, ");
				} while (choice != 's' && choice != 'S' && choice != 'K' && choice != 'k');

			}

			if (choice == 'k' || choice == 'K');

			else if (choice == 's' || choice == 'S')
			{
				printf("\n\n                               ");
				printf("********************\n");

				while (heroo > 0 && enemyy > 0)
				{
					//display hps
					{
						printf("                     Senin can�n: %d     ||     D��man�n can�: %d\n", heroo, enemyy);
						printf("                -------------------------------------------------------\n");
					}
					

					//hero turn
					if (flag == 1)
					{
						//generate random number
						{
							pos = rand() % ((100 + 1) - 1) + 1;
							//pos = 90;
						}

						//display and get the type of the attack
						{
							printf("     H - H�zl� sald�r�(%%80) || N - Normal sald�r�(%%60) || G -G��l� sald�r�(%%40)\n\n");
							printf("                                       <<<>>>\n");
							do {
								printf("                                       Sald�r: ");
								scanf(" %c", &choice);
							} while (choice != 'h' && choice != 'H' && choice != 'n' && choice != 'N' && choice != 'G' && choice != 'g');
							printf("                                       <<<>>>");
							Sleep(500);
						}

						//attack
						{
							if (choice == 'h' || choice == 'H')
							{
								//decrease enemy hp and display the message
								{
									if (pos / 10 <= 8)
									{
										printf("\n\n                               ");

										if (power[5] + ceil(power[7] / 10) >= ceil(enemy[2] / 10))
										{                                               // 3              
											printf("Rakibe verilen hasar: %.f\n\n\n", power[5] + ceil(power[7] / 10) - ceil(enemy[2] / 10));
											enemyy -= power[5] + ceil(power[7] / 10) - ceil(enemy[2] / 10);
										}
										else
										{
											printf("Rakibe verilen hasar: %.f\n\n\n", 0);
										}
									}
									else
									{
										printf("\n\n                                        ");
										printf("BLOK\n\n\n");
									}
								}
							}

							else if (choice == 'n' || choice == 'N')
							{
								//decrease enemy hp and display the message
								{
									if (pos / 10 <= 5)
									{
										printf("\n\n                               ");
										if (power[5] + ceil(power[7] / 10) + ceil(power[5] / 3) >= ceil(enemy[2] / 10))
										{
											printf("Rakibe verilen hasar: %.f\n\n\n", power[5] + ceil(power[7] / 10) + ceil(power[5] / 3) - ceil(enemy[2] / 10));
											enemyy -= power[5] + ceil(power[7] / 10) + ceil(power[5] / 3) - ceil(enemy[2] / 10);
										}
										else
										{
											printf("Rakibe verilen hasar: %.f\n\n\n", 0);
										}
									}
									else
									{
										printf("\n\n                                        ");
										printf("BLOK\n\n\n");

									}
								}

							}

							else if (choice == 'g' || choice == 'G')
							{
								//decrease enemy hp and display the message
								{
									if (pos / 10 <= 3)
									{
										printf("\n\n                               ");
										if (power[5] + ceil(power[7] / 10) + ceil(power[5] / 3) + ceil(power[5] / 3) >= ceil(enemy[2] / 10))
										{
											printf("Rakibe verilen hasar: %.f\n\n\n", power[5] + ceil(power[7] / 10) + ceil(power[5] / 3) + ceil(power[5] / 3) - ceil(enemy[2] / 10));
											enemyy -= power[5] + ceil(power[7] / 10) + ceil(power[5] / 3) + ceil(power[5] / 3) - ceil(enemy[2] / 10);
										}
										else
										{
											printf("Rakibe verilen hasar: %.f\n\n\n", 0);
										}
									}
									else
									{
										printf("\n\n                                        ");
										printf("BLOK\n\n\n");
									}
								}

							}
						}

						flag = 2;
					}

					//check the hp of enemy \\ enemy attack
					if (enemyy > 0)
					{
						//enemy turn
						if (flag == 2)
						{
							//generate random number
							{
								pos = rand() % ((100 + 1) - 1) + 1;
								//pos = 90;
							}

							//message
							{
								Sleep(500);
								printf("\n                                   S�ra rakibinde \n");
								Sleep(500);
							}

							//display the attack messeage and decrease the hp
							{
								if (pos / 10 <= 7)
								{
									printf("\n                                   ");

									if (enemy[1] + ceil(enemy[3] / 10) >= ceil(power[6] / 10))
									{
										printf("Al�nan hasar: %.f\n", enemy[1] + ceil(enemy[3] / 10) - ceil(power[6] / 10));
										heroo -= enemy[1] + ceil(enemy[3] / 10) - ceil(power[6] / 10);
										Sleep(500);
									}
									else
									{
										printf("Al�nan hasar: %.f\n", 0);
										Sleep(500);
									}
								}
								else
								{
									printf("\n\n                                        ");
									printf("BLOK\n");
									Sleep(500);
								}
								printf("                                      <<<<>>>>\n\n\n");
							}
							flag = 1;
						}
					}
				}

				//if hero lose
				if (heroo <= 0)
				{
					//display the message 
					{
						printf("                                     -----------\n");
						printf("                                      Kaybettin.\n");
						printf("                             Yeterince g��lenip tekrar gel.");
						Sleep(3000);
					}

					//decrease hunger
					{
						power[2] -= 10;
					}
				}
				//if hero win
				else
				{
					//display the message
					{
						printf("                                   ---------------\n");
						printf("                                     Kazand�n. !!!\n");
						Sleep(500);
						printf("                                 %.f Alt�n kazand�n\n", gold[5]);
						printf("                             Kasabadaki sayg�nl���n artt�.\n");
						Sleep(500);

						//decrease hunger
						{
							power[2] -= 5;
						}

						//increase statistics
						{
							//gold
							power[1] += gold[5];
							gold[5] += int(gold[5] * 30 / 100);

							//lvl
							power[0] += 5;
							if (int(power[0]) % 10 == 0)
							{
								printf("                            Tebrikler lvl atlad�n. !!!\n");
								do {
									printf("           Hangi �zelli�ini y�kseltmek istiyorsun A - Atak, D - Defans: ");
									scanf(" %c", &choice);
								} while (choice != 'a' && choice != 'A' && choice != 'd' && choice != 'D');

									printf("G�c�n ba�ar�yla artt�.\n");
								if (choice == 'a' || choice == 'A')
								{
									power[5] += int(power[5]*1/7);
									power[7] += int(power[7] * 1 / 7);
								}
								else
								{
									power[4] += int(power[4] * 1 / 7);
									power[6] += int(power[6] * 1 / 7);
								}
								Sleep(500);
							}


							//enemy
							for (int i = 0; i < 4; i++)
								enemy[i] += int(enemy[i] * 40 / 100) + 20;
						}
					}
				}
			}

		}
	}
	printf("\n\n\n\n");
	displaytree(name);

	//save the game
	savegame(power, gold, enemy);
}

void displaycasino(char name[])
{
	printf("\n\n");
	printf("          ********************************************************************************************\n");
	printf("       **************************************************************************************************\n");
	printf("     ****    $$$$$            $$$$             $$$$$       $$$$$$$$     $$$$       $$$       $$$$$$    ****\n");
	printf("    ***    $$$$$$$$$         $$  $$           $$$   $       $$$$$$      $$$$$      $$$     $$$$$$$$$$    ***\n");
	printf("   **     $$$    $$$$       $$    $$         $$$             $$$$       $$$ $$$    $$$    $$$      $$$     **\n");
	printf("  *      $$$               $$$$$$$$$$       $$$$$$$$$$$       $$        $$$  $$$   $$$    $$        $$       *\n");
	printf("  *      $$$              $$$$$$$$$$$$       $$$$$$$$$$$      $$        $$$   $$$  $$$    $$        $$       *\n");
	printf("  **      $$$    $$$$    $$          $$            $$$$      $$$$       $$$    $$$ $$$    $$$      $$$     **\n");
	printf("   ***     $$$$$$$$$    $$            $$       $   $$$      $$$$$$      $$$     $$$$$$     $$$$$$$$$$    ***\n");
	printf("     ****    $$$$$     $$              $$       $$$$$      $$$$$$$$     $$$      $$$$$       $$$$$$    ****\n");
	printf("       **************************************************************************************************\n");
	printf("          ********************************************************************************************\n");
	printf("\n                                                     CASINO                                  \n");
}

void casino(double power[], char  name[])
{
	int bah, status = 1, ran;
	char choice, ch='�';


	//get first choice
	{
		displaycasino(name);
		printf("\nCasino' ya ho�geldin %s.\n", name);
		printf("�uanki alt�n�n: %.f\n", power[1]);
		printf("$ R $ Rulet\n");
		printf("$ � $ iddaa\n");
		printf("$ 2 $ 21(Blackjack)\n");
		printf("- B - Bilgi\n");
		printf("- � - ��k��\n");
		do {
			printf("Se�imini yap: ");
			scanf(" %c", &choice);
		} while (choice != 'r' && choice != 'R' && choice != '2' && choice != 'i' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�' && choice != '�');
		printf("\n\n");
	}

	while (choice != '�' && choice != '�')
	{
		if (choice == 'b' || choice == 'B')
		{
			printf("Oyun oynayabilmek i�in sayg�nl���n�n olmas� gerekir.\n");
			printf("Risk alarak alt�n kazanabilirsin.\n");
			printf("Farkl� oyunlar var.\n");
			printf("Rulette �ans�n %%50 dir.\n");
			printf("�ddia da risk oranlar� ve kazan�lar farkl�d�r.\n");
			printf("Blackjack oynarken elindeki kartlar� 21'e en yak�n yapmaya �al���rs�n.\n");
			printf("E�er 21 olursa elindeki kartlar kesin olarak kazan�rs�n.\n");
			printf("10 a kadar say�lar verilir her el.\n");
			printf("E�er elindeki kartlar�n say�s� 21 e yak�n de�ilse\n ve risk almak istersen kart �ekebilirsin ama 21' i ge�erse kurpiyer kazan�r.\n");
			printf("Kurpiyerde ayn� �ekilde 21' i gerse kaybeder.\n");
			printf("Ama kurpiyer en az 17 olmas� laz�md�r. Oyun sonunda kurpiyer elini a�ar.");
		}
		
		else if (choice=='2')
		{
			//check the respect point and hunger
			if (power[3] < 60)
				printf("Oyun oynayabilmek i�in sayg�n biri olman laz�m.");
			else
			{
				//decrease hunger
				if (power[2] < 10)
					printf("A�l�ktan �l�yorsun!");
				else
				{
					if (power[2] < 3)
						power[2] = 0;
					else
						power[2] -= 3;
					
					printf("Sahip oldu�un alt�n miktar� %.f\n", power[1]);
					do {
						printf("Ne kadar alt�n koyuyorsun: ");
						status = scanf("%d", &bah);
						if (bah > power[1])
							printf("Burda �akallara yer yok aslan�m, ");
						if (bah <= 0)
							printf("Ge�ersiz, ");
					} while ((bah <= 0 || bah > power[1]) && status != 0);
					
					if (status == 0)
					{
						printf("Karakter girdin..\n\n");
						choice = '�';
					}
					else
					{
						int kurpi, player, sumplayer = 0, sumkurpi = 0;
						printf("\nKa��tlar da��t�ld�.\n");
						printf("Sana gelen kartlar: \n");
						printf("-------------------\n");
						printf("    ");

						for (int i = 1; i <= 2; i++)
						{
							player = rand() % ((10 + 1) - 1) + 1;
							if (i == 1)
								printf("%d + ", player);
							else
								printf("%d = ", player);
							sumplayer += player;
						}
						printf("%d", sumplayer);
						Sleep(500);

						if (sumplayer == 21)
						{
							printf("\n\n       $$$$$$$$$$");
							printf("\n      $ Blakjack $");
							printf("\n       $$$$$$$$$$");
							printf("\n\n%d kadar alt�n kazand�n.\n", bah);
							power[1] += bah;
							printf("Sayg�nl�k 10 puan artt�.\n");

							if (power[3] > 90)
								power[3] = 100;
							else
								power[3] += 10;
						}
						
						else
						{
							printf("\n-------------------\n");
							printf("\n- i - iste\n");
							printf("- k - kal\n");
							do {
								printf("Se�imini yap: ");
								scanf(" %c", &ch);
								if (ch != 'i' && ch != '�' && ch != 'k' && ch != 'K')
									printf("Ge�ersiz, ");
							} while (ch != 'i' && ch != '�' && ch != 'k' && ch != 'K');

							while (ch != 'k' && ch != 'K'&&sumplayer<22)
							{
								player = rand() % ((10 + 1) - 1) + 1;
								printf("-------------------\n");
								printf("    %d + %d = ", sumplayer,player);
								sumplayer += player;
								printf("%d\n", sumplayer);
								printf("-------------------\n");

								//batt�
								if (sumplayer > 21)
								{
									printf("Kaybettin.\nElin 21' i ge�ti\n");
									power[1] -= bah;

									printf("Sayg�nl�k 3 puan azald�.\n");

									if (power[3] < 3)
										power[3] = 0;
									else
										power[3] -= 3;
									Sleep(500);
								}
								else
								{
									//update
									{
										printf("\n- i - iste\n");
										printf("- k - kal\n");
										do {
											printf("Se�imini yap: ");
											scanf(" %c", &ch);
											if (ch != 'i' && ch != '�' && ch != 'k' && ch != 'K')
												printf("Ge�ersiz, ");
										} while (ch != 'i' && ch != '�' && ch != 'k' && ch != 'K');
									}
								}
							}
							
							if (sumplayer > 21);
							else
							{
								printf("\nS�ra kurpiyede\n");
								printf("Kurpiyere gelen kartlar:\n");
								printf("-------------------\n");
								Sleep(500);
								printf("    ");
								for (int i = 1; i <= 2; i++)
								{
									kurpi = rand() % ((10 + 1) - 1) + 1;
									if (i == 1)
										printf("%d + ", kurpi);
									else
										printf("%d = ", kurpi);
									sumkurpi += kurpi;
								}
								printf("%d", sumkurpi);
								printf("\n-------------------\n");

								while (sumkurpi < 17)
								{
									printf("\nKurpiyenin eli 17' nin alt�nda olu�u i�in kart �ekiyor.\n");
									kurpi = rand() % ((10 + 1) - 1) + 1;
									printf("-------------------\n");
									printf("    %d + %d = ", sumkurpi, kurpi);
									sumkurpi+= kurpi;
									printf("%d\n", sumkurpi);
									printf("-------------------\n");
								}

								//result
								if (sumkurpi > 21)
								{
									Sleep(500);
									printf("\nTebrikler !!!\n");
									printf("Kurpiyerin eli 21' i ge�ti.\n");
									printf("%d alt�n kazand�n.\n", bah);
									power[1] += bah;
									printf("Sayg�nl�k 3 puan artt�.\n");

									if (power[3] > 97)
										power[3] = 100;
									else
										power[3] += 3;
								}
								else
									if (sumplayer > sumkurpi)
									{
										Sleep(500);
										printf("\nTebrikler !!!\n");
										printf("Kurpiyeri ge�tin.\n");
										printf("%d alt�n kazand�n.\n", bah);
										power[1] += bah;
										printf("Sayg�nl�k 3 puan artt�.\n");

										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else if(sumkurpi > sumplayer)
									{
										Sleep(500);
										printf("\nKaybettin.\n");
										printf("Kurpiyeri seni ge�ti.\n");
										power[1] -= bah;

										printf("Sayg�nl�k 3 puan azald�.\n");

										if (power[3] < 3)
											power[3] = 0;
										else
											power[3] -= 3;
									}

									else if (sumkurpi == sumplayer)
										printf("\nBerabere.\n");
							}
						}
					}
				}
			}
		}

		else if (choice == 'i' || choice == '�')
		{
			//check the respect point and money
			if (power[3] < 60 || power[1] == 0)
				printf("Burda oyun oynayabilmek i�in kumarhanenin sayg�s�n� kazanman gerekir.\n");
			else
			{
				//decrease hunger
				if (power[2] < 10)
					printf("A�l�ktan �l�yorsun!");
				else
				{
					if (power[2] < 3)
						power[2] = 0;
					else
						power[2] -= 3;

					//get the choice
					{
						printf("$ F $ Fenerbah�e\n");
						printf("$ G $ Galatasaray\n");
						printf("$ B $ Be�ikta�\n");
						printf("$ K $ Ke�i�ren\n");
						printf("- � - Bilgi\n");
						printf("- � - ��k��\n");
						do {
							printf("Se�imini gir: ");
							scanf(" %c", &ch);
							if (ch != 'k' && ch != 'K' && ch != 'f' && ch != 'F' && ch != 'g' && ch != 'G' && ch != 'b' && ch != 'B' && ch != 'i' && ch != '�' && ch != '�' && ch != '�')
								printf("Ge�ersiz, ");
							printf("\n");
						} while (ch != 'k' && ch != 'K' && ch != 'f' && ch != 'F' && ch != 'g' && ch != 'G' && ch != 'b' && ch != 'B' && ch != 'i' && ch != '�' && ch != '�' && ch != '�');

						if (ch == 'i' || ch == '�')
						{
							printf("Tak�mlar�n kazanma oranlar� ve dolay�s�yla da kazan� oranlar�n farkl�d�r.\n");
							printf("Fenerbah�e'nin kazanma oran� %%80 dir\n\n");
							printf("Kar oran� bahse koydu�un paran�n %%20' si dir.\n");
							printf("----------------------------------------------\n");
							printf("Galatasaray'�n kazanma oran� %%60 t�r.\n");
							printf("Kar oran� bahse koydu�un paran�n %%40' � d�r.\n");
							printf("----------------------------------------------\n");
							printf("Be�ikta�' �n kazanma oran� %%40 d�r.\n");
							printf("Kar oran� koydu�un paran�n %%160' si dir\n");
							printf("----------------------------------------------\n");
							printf("Ke�i�reng�c�' n�n kazanma oran� %%30 dur.\n");
							printf("Kar oran� %%200' d�r.");
						}

						else if (ch != '�' && ch != '�')
						{
							if (ch == 'f' || choice == 'F')
							{
								printf("\n�uanki alt�n�n: %.f\n", power[1]);
								printf("Fenerbah�e'ye ne kadar yat�rmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Ge�ersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda �akall�k i�e yaramaz aslan�m, tekrar gir: ");
								} while (status != 0 && bah <= 0 || bah > power[1]);

								if (status == 0)
									printf("Karakter girdin.\n\n");
								else
								{
									Sleep(1000);
									//generate random number and check 

									ran = rand() % ((10 + 1) - 1) + 1;
									if (ran > 2)
									{
										printf("\nTebrikler !!!\n");
										printf("Fenerbah�e kazand�.\n");
										printf("%d alt�n kazand�n.\n", int(ceil((double)bah * 20 / 100)));
										power[1] += int(ceil((double)bah * 20 / 100));
										printf("Sayg�nl���n 3 artt�.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else
									{
										printf("\nFenerbah�e kaybetti.\n");
										printf("Sayg�nl���n 3 azald�.\n");
										power[1] -= bah;
										if (power[3] < 3)
											power[3] = 0;
										else
											power[3] -= 3;
									}
								}
							}

							else if (ch == 'g' || choice == 'G')
							{
								printf("\n�uanki alt�n�n: %.f\n", power[1]);
								printf("Galatasaray'a ne kadar yat�rmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Ge�ersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda �akall�k i�e yaramaz aslan�m, tekrar gir: ");
								} while (status != 0 && bah <= 0 || bah > power[1]);

								if (status == 0)
									printf("Karakter girdin.\n\n");
								else
								{
									Sleep(1000);
									//generate random number and check 

									ran = rand() % ((10 + 1) - 1) + 1;
									if (ran > 4)
									{
										printf("\nTebrikler !!!\n");
										printf("Galatasaray kazand�.\n");
										printf("%d alt�n kazand�n.\n", int(ceil((double)bah * 40 / 100)));
										power[1] += int(ceil((double)bah * 40 / 100));
										printf("Sayg�nl���n 3 artt�.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else
									{
										printf("Galatasaray kaybetti.\n");
										printf("Sayg�nl���n 3 azald�.\n");
										power[1] -= bah;
										if (power[3] < 3)
											power[3] = 0;
										else
											power[3] -= 3;
									}
								}
							}

							else if (ch == 'b' || choice == 'B')
							{
								printf("\n�uanki alt�n�n: %.f\n", power[1]);
								printf("Be�ikta�'a ne kadar yat�rmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Ge�ersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda �akall�k i�e yaramaz aslan�m, tekrar gir: ");
								} while (status != 0 && bah <= 0 || bah > power[1]);

								if (status == 0)
									printf("Karakter girdin.\n\n");
								else
								{
									Sleep(1000);
									//generate random number and check 

									ran = rand() % ((10 + 1) - 1) + 1;
									if (ran > 6)
									{
										printf("\nTebrikler !!!\n");
										printf("Be�ikta� kazand�.\n");
										printf("%d alt�n kazand�n.\n", int(ceil((double)bah * 160 / 100)));
										power[1] += int(ceil((double)bah * 160 / 100));
										printf("Sayg�nl���n 3 artt�.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else
									{
										printf("\nBe�ikta� kaybetti.\n");
										printf("Sayg�nl���n 3 azald�.\n");
										power[1] -= bah;
										if (power[3] < 3)
											power[3] = 0;
										else
											power[3] -= 3;
									}
								}
							}

							else if (ch == 'k' || choice == 'K')
							{
								printf("\n�uanki alt�n�n: %.f\n", power[1]);
								printf("Ke�i�ren'a ne kadar yat�rmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Ge�ersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda �akall�k i�e yaramaz aslan�m, tekrar gir: ");
								} while (status != 0 && bah <= 0 || bah > power[1]);

								if (status == 0)
									printf("Karakter girdin.\n\n");
								else
								{
									//generate random number and check 
									ran = rand() % ((10 + 1) - 1) + 1;
									if (ran > 7)
									{
										printf("\nTebrikler !!!\n");
										printf("Ke�i�ren kazand�.\n");
										printf("%d alt�n kazand�n.\n", int(ceil((double)bah * 200 / 100)));
										power[1] += int(ceil((double)bah * 200 / 100));
										printf("Sayg�nl���n 3 artt�.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}
									else
									{
										printf("\nKe�i�ren kaybetti.\n");
										printf("Sayg�nl���n 3 azald�.\n");
										power[1] -= bah;
										if (power[3] < 3)
											power[3] = 0;
										else
											power[3] -= 3;
									}
								}
							}
						}
						else;
					}
				}
			}
		}

		else if (choice == 'R' || choice == 'r')
		{
			//check the respect point and money
			if (power[3] < 60 || power[1] == 0)
				printf("Burda oyun oynayabilmek i�in kumarhanenin sayg�s�n� kazanman gerekir.\n");
			else
			{
				//decrease hunger
				if (power[2] < 10)
					printf("A�l�ktan �l�yorsun!");
				else
				{
					if (power[2] < 3)
						power[2] = 0;
					else
						power[2] -= 3;

					//get choice
					{
						printf("$ K $ K�rm�z�\n");
						printf("$ S $ Siyah\n");
						printf("- � - ��k��\n");
						do {
							printf("Se�imini yap:");
							scanf(" %c", &ch);
							if (ch != 'k' && ch != 'K' && ch != 's' && ch != 'S' && ch != '�' && ch != '�')
								printf("Ge�ersiz, ");
						} while (ch != 'k' && ch != 'K' && ch != 's' && ch != 'S' && ch != '�' && ch != '�');
					}
				}

				if (ch != '�' && ch != '�')
				{
					//get the money and check it
					printf("\n�uanki alt�n�n: %.f\n", power[1]);
					do
					{
						printf("Ne kadar para koyuyorsun: ");
						status = scanf("%d", &bah);
						if (bah <= 0)
							printf("Ge�ersiz miktar, ");
						if (bah > power[1])
							printf("Kurnazl�k yapma, ");
					} while (bah <= 0 || bah > power[1] && status != 0);

					//check the bet
					if (status == 0)
						printf("Karakter girdin!");
					else
					{
						ran = rand() % ((10 + 1) - 1) + 1;

						//display the output
						{
							Sleep(1000);
							if (ch == 'k' || ch == 'K')
								if (ran % 2 == 0)
								{
									printf("\nTebrikler!!\n");
									printf("%d alt�n kazand�n.\n", bah);
									power[1] += bah;
									printf("Sayg� puan�n 3 artt�.\n");
									if (power[3] > 97)
										power[3] = 100;
									else
										power[3] += 3;
								}
								else
								{
									printf("\nKaybettin\n");
									printf("Siyah ��kt�.\n");
									printf("Sayg� puan�n 3 azald�.\n");
									power[1] -= bah;
									if (power[3] >= 3)
										power[3] -= 3;
									else
										power[3] = 0;
								}
							else
								if (ran % 2 == 0)
								{
									printf("\nKaybettin.\n");
									printf("K�rm�z� ��kt�.\n");
									printf("Sayg� puan�n 3 azald�.\n");
									power[1] -= bah;
									if (power[3] >= 3)
										power[3] -= 3;
									else
										power[3] = 0;
								}
								else
								{
									printf("\nTebrikler!!\n");
									printf("%d alt�n kazand�n.\n", bah);
									power[1] += bah;
									printf("Sayg� puan�n 3 artt�.\n");
									if (power[3] > 97)
										power[3] = 100;
									else
										power[3] += 3;
								}
						}
					}
				}
				else;
			}
		}

		//update
		if (status != 0)
		{
			printf("\n\n>>>>>>>>>>>>>");
			printf("\n�uanki alt�n�n: %.f", power[1]);
			printf("\n$ R $ Rulet\n");
			printf("$ � $ �ddaa\n");
			printf("$ 2 $ 21(Blackjack)\n");
			printf("- B - Bilgi\n");
			printf("- � - ��k��\n");
			do {
				printf("Se�imini yap: ");
				scanf(" %c", &choice);
				if (choice != 'r' && choice != 'R' && choice != '2' && choice != 'i' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�' && choice != '�')
					printf("Ge�ersiz, ");
			} while (choice != 'r' && choice != 'R' && choice != '2' && choice != 'i' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�' && choice != '�');
			printf("\n\n");
		}
	}
	displaytree(name);
}

void towninformation(void)
{
	printf("\nBurda �e�itli se�eneklere sahipsin ihtiyac�na g�re gitmen gereken yere git.\n");
	printf("Arena - Sava�arak level atlayabilirsin b�ylelikle g�c�n� artt�rabilirsin.\n");
	printf("Yemekhane - Ac�kt���n zaman beslenmen gerekiyor yoksa yapabilece�in �eyler s�n�rlan�r.\n");
	printf("Ayr�ca yemekhanede ziyafet vererek sayg�nl���n� artt�rabilirsin.\n");
	printf("D�kkan - Z�rh ve k�l�� alarak g��lenebilece�in yer.\n");
	printf("Spor - Kaslar�n� zorlayarak g�c�n� artt�rabilirsin. Dikkat et fazla y�klenme.\n");
	printf("G�revler - Para kazanmak i�in e�lenceli se�enekler var.\n");
	printf("Casino - �e�itli oyunlarla paran� katlayabilirsin.\n");
	printf("Kasabadan at�lmak istemiyorsan sayg�nl���nda dikkat et. Pek misafirperver de�il burdakiler.\n");
	printf("Can�na ve parana dikkat et, �akallar�n oldu�u bu kasabada dar sokaklardan ge�erken g�t� kolla..\n");
	printf("OYUNU KAYDETMEY� UNUTMA !!!!!!\n\n");
}

void duties(double power[], char  name[])
{
	char choice;
	int password[2][5], pw, status = 1, turn, pww, digit, r;

	//get choice
	{
		printf("\n\n\n");
		printf("**********************************\n");
		printf("Yeralt�na ho�geldin %s.\n", name);
		printf("- K - Kasa �ifresi k�rma\n");
		printf("- � - �stihbarat sald�r�s�\n");
		printf("- B - Bilgi\n");
		printf("- � - ��k��\n");
		do
		{
			printf("Se�imini yap: ");
			scanf(" %c", &choice);
			if (choice != 'k' && choice != 'K' && choice != 'i' && choice != '�' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�')
				printf("Ge�ersiz, ");
		} while (choice != 'k' && choice != 'K' && choice != 'i' && choice != '�' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�');
	}

	while (choice != '�' && choice != '�')
	{

		if (choice == 'b' || choice == 'B')
		{
			printf("\n\nBurda g�revleri yaparak alt�n kazanabilirsin.\n");
			printf("�uanki alt�n�n: %.f\n", power[1]);
			printf("Kasa �ifresi i�in 5 basamakl� bir �ifreyi deneyerek k�rmaya �al���rs�n.\n");
			printf("�stihbarat sald�r�s�nda kral�n telefon konu�mas�nda ge�en kelimeleri kodlara g�re ��z�mleyip satars�n.\n\n");
		}

		else if (choice == 'i' || choice == '�')
		{
			int word[10];

			//decrease hunger
			{
				if (power[2] > 10)
					power[2] -= 10;
				else
					power[2] = 0;
			}

			printf("\nBurda sana verilen tabloya g�re �ifrelenmi� olan konu�man�n harlerini yazman laz�m.\n");
			printf("��te tablo\n------------>\n");
			//small letters
			{
				r = int('a');
				for (int c = 1; c <= 6; c++)
				{
					for (int i = 0; i <= 4; i++)
					{
						if (r <= int('z'))
							printf("%c = %3d || ", char(r), r);
						r++;
					}
					printf("\n");
				}
				printf("\n");
			}

			//generate random numbers , display , get, check the input
			{
				for (int z = 0; z < 10; z++)
					word[z] = rand() % ((122 + 1) - 97) + 97;

				{
					printf("\nAralar�nda bo�luk b�rakarak say�lara kar��l�k gelen harfleri yaz.\n               ");
					printf("\n              ");
					for (int z = 0; z < 7; z++)
						printf("%3d ", int(word[z]));
					printf("\n               ");

					char wo[10];
					for (int z = 0; z < 7; z++)
						scanf(" %c", &wo[z]);


					int sum = 0;
					for (int z = 0; z < 7; z++)
						if (word[z] == int(wo[z]))
							sum++;

					if (sum == 7)
					{
						printf("\nKablolardan �ald���n s�zc�kleri ba�ar�yla ilettin.\n");

						if (power[0] > 0 && power[0] <= 30)
						{
							printf("�d�l olarak 2000 alt�n kazand�n.\n\n");
							power[1] += 2000;
						}
						else if (power[0] > 30 && power[0] <= 50)
						{
							printf("�d�l olarak 5000 alt�n kazand�n.\n\n");
							power[1] += 5000;
						}
						else if (power[0] > 50 && power[0] <= 70)
						{
							printf("�d�l olarak 10000 alt�n kazand�n.\n\n");
							power[1] += 10000;
						}
						else
						{
							printf("�d�l olarak 20000 alt�n kazand�n.\n\n");
							power[1] += 20000;
						}						
					}
					else
						printf("\n�ald���n kelimeleri do�ru iletemedin.\n\n");
				}
			}
		}

		else if (choice == 'k' || choice == 'K')
		{
			//decrease hunger
			{
				if (power[2] > 5)
					power[2] -= 5;
				else
					power[2] = 5;
			}

			//generate the random password
			{
				for (int i = 0; i < 5; i++)
					password[0][i] = rand() % ((9 + 1) - 1) + 1;
			}

			//get the guess
			{
				printf("\n------------\n");
				do {
					printf("�ifreyi gir: ");
					status = scanf("%d", &pw);

					if (status == 0)
						digit = 5;
					else
					{
						//count the digits
						{
							digit = 0;
							pww = pw;

							while (pww != 0)
							{
								pww /= 10;
								digit++;
							}
						}
					}

					if (digit != 5)
						printf("%d haneli girdin, 5 haneli ", digit);
				} while (digit != 5);

				if (status == 0)
					pw = -1;
				else
					for (int i = 4; i >= 0; i--)
					{
						password[1][i] = pw % 10;
						pw /= 10;
					}
				turn = 1;
			}

			//display the message
			{
				while (!(password[0][0] == password[1][0] && password[0][1] == password[1][1] && password[0][2] == password[1][2] && password[0][3] == password[1][3] && password[0][4] == password[1][4] || password[1][4] == -1 || turn == 8 || status == 0))
				{
					//display message 
					{
						printf("\n %d deneme hakk�n kald�.\n", 8 - turn);
						turn++;

						printf("  ");
						for (int i = 0; i < 5; i++)
							if (password[0][i] == password[1][i])
								printf("%d  ", password[1][i]);
							else printf("   ");

						printf("\n  -  -  -  -  -");
					}

					//update
					{
						printf("\n\n");
						do {
							printf("�ifreyi gir: ");
							status = scanf("%d", &pw);

							if (status == 0)
								digit = 5;
							else
							{
								//count the digits
								{
									digit = 0;
									pww = pw;

									while (pww != 0)
									{
										pww /= 10;
										digit++;
									}
								}
							}

							if (digit != 5)
								printf("%d haneli girdin, 5 haneli ", digit);
						} while (digit != 5);

						if (status == 0)
							pw = -1;
						else
							for (int i = 4; i >= 0; i--)
							{
								password[1][i] = pw % 10;
								pw /= 10;
							}
					}
				}
				if (password[0][0] == password[1][0] && password[0][1] == password[1][1] && password[0][2] == password[1][2] && password[0][3] == password[1][3] && password[0][4] == password[1][4])
				{
					printf("\n\n>>>>>>>>>>>>>>>>>>>\nTebrikler �ifreyi ��zmeyi ba�ard�n.\n20000 alt�n kazand�n.\nSayg�nl���n 10 artt�\n>>>>>>>>>>>>>>>>>>>\n\n");
					power[1] += 20000;
					if (power[3] <= 90)
						power[3] += 10;
					else
						power[3] = 100;
				}

				else if (turn == 8)
				{
					printf("\nKasay� patlatamad�n.\n");
					printf("Polisler yakalad� kasabaya paketlediler.\n");
					printf("Sayg�nl���n 5 azald�.\n\n");
					if (power[3] > 5)
						power[3] -= 5;
					else
						power[3] = 0;
				}

				else if (status == 0)
				{
					printf("\nKarakter girdin..");
					printf("\nKasay� patlatamad�n.\n");
					printf("Polisler yakalad� kasabaya paketlediler.\n");
					printf("Sayg�nl���n 15 azald�.\n\n");
					if (power[3] > 5)
						power[3] -= 5;
					else
						power[3] = 0;
				}

				else if (password[1][4] == -1)
				{
					printf("\nKasay� b�rak�p t�yd�n.\n");
					printf("Bu davran���ndan dolay� sayg�nl���n� 15 kaybettin.\n\n");
					if (power[3] > 10)
						power[3] -= 15;
					else
						power[3] = 0;
				}
			}
		}

		//update
		printf("\n**********************************\n");
		printf("- K - Kasa �ifresi k�rma\n");
		printf("- � - �stihbarat sald�r�s�\n");
		printf("- B - Bilgi\n");
		printf("- � - ��k��\n");
		do
		{
			printf("Se�imini yap: ");
			scanf(" %c", &choice);
			if (choice != 'k' && choice != 'K' && choice != 'i' && choice != '�' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�')
				printf("Ge�ersiz, ");
		} while (choice != 'k' && choice != 'K' && choice != 'i' && choice != '�' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�');
	}
	printf("\n\n");
	displaytree(name);
}

void spor(double power[], char name[], double gold[])
{
	int possib;
	char ch;

	//get choice and step into while loop
	printf("\n\n**********\n");
	printf("A�l�k: %.0f\nAlt�n: %.f\n", power[2], power[1]);
	printf("- H - Hafif antreman %.f alt�n\n", gold[0]);
	printf("- A - A��r antreman %.f alt�n\n", gold[1]);
	printf("- i - Bilgi\n");
	printf("- � - ��k\n");
	do {
		printf("Se�imini yap: ");
		scanf(" %c", &ch);
		if (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '�' && ch != '�' && ch != '�')
			printf("Ge�ersiz, ");
	} while (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '�' && ch != '�' && ch != '�');

	//check respect
	if (power[3] < 20)
	{
		printf("Sayg�s�zl���n l�zumu yok!\n\n\n");
		displaytree(name);
	}
	else
	{
		while (ch != '�' && ch != '�')
		{
			//perform
			if (ch == 'i' || ch == '�')
			{
				printf("\nA�l�k: %f.0\n", power[2]);
				printf("Spor yaparak g�c�n� artt�rabilirsin.\n");
				printf("Hafif antreman g�c�n� 1 artt�r�rken a��r antreman 2 artt�r�r.\n");
				printf("A��r antremanda sakatlanma �ans�n daha y�ksektir.\n");
				printf("Spor yaparken fazla enerji t�ketirsin, a�l���na dikkat et bay�lma.\n\n");
			}
			else
			{
				//a�l�k varsa d�n
				if (power[2] < 20)
				{
					power[3] -= 10;
					ch = '�';
					printf("�ekerin d��t�. Kasabaya zar zor d�nd�n. Sayg�nl�k 10 puan azald�.\n\n\n");
				}

				else
				{
					possib = rand() % ((10 + 1) - 1) + 1;

					//a��r antreman
					if (ch == 'a' || ch == 'A')
					{
						if (power[1] < round(gold[1]))
							printf("\nYeterli alt�n�n yok!\n\n");
						else
						{
							power[2] -= 15;
							power[1] -= round(gold[1]);
				
							if (possib == 3 || possib == 5 || possib == 7 || possib == 9)
							{
								printf("\nFazla y�klendin, geli�me g�steremedin.\n\n");
								Sleep(1000);
							}
							else
							{
								if (possib >= 0 && possib <= 2)
								{
									power[4] += round(power[4] * 10 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nToplam can %.0f puan artt�.\n", round(power[5] * 10 / 100 + 2));
								}
								else if (possib <= 4)
								{
									power[5] += round(power[5] * 10 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nAtak %.0f puan artt�.\n", round(power[5] * 10 / 100 + 2));
								}
								else if (possib <= 8)
								{
									power[6] += round(power[6] * 10 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nDefans %.0f puan artt�.\n", round(power[5] * 10 / 100 + 2));
								}
								else if (possib <= 10)
								{
									power[7] += round(power[7] * 10 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nKritik %.0f puan artt�.\n", round(power[7] * 10 / 100 + 2));
								}
								Sleep(1000);

								//increase price
								gold[1] += gold[1] * 7 / 100;
							}
						}
					}

					//hafif antreman
					else
					{
						if (power[1] < round(gold[0]))
							printf("\nYeterli alt�n�n yok!\n\n");
						else
						{
							power[2] -= 10;
							power[1] -= round(gold[0]);
							if (possib == 7 || possib == 9)
							{
								printf("\nFazla y�klendin, geli�me g�steremedin.\n\n");
								Sleep(1000);
							}
							else
							{
								if (possib >= 0 && possib <= 2)
								{
									power[4] += round(power[4] * 6 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nToplam can %.0f puan artt�.\n", round(power[5] * 6 / 100 + 2));
								}
								else if (possib <= 4)
								{
									power[5] += round(power[5] * 6 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nAtak %.0f puan artt�.\n", round(power[5] * 6 / 100 + 2));
								}
								else if (possib <= 7)
								{
									power[6] += round(power[6] * 6 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nDefans %.0f puan artt�.\n", round(power[5] * 6 / 100 + 2));
								}
								else if (possib <= 10)
								{
									power[7] += round(power[5] * 6 / 100 + 2);
									printf("\nBa�ar�yla tamamlad�n.");
									printf("\nKritik %.0f puan artt�.\n", round(power[5] * 6 / 100 + 2));
								}
								Sleep(1000);

								//increase price
								gold[0] += gold[0] *7 / 100;
							}
						}
					}
				}
			}

			if (ch != '�')
			{
				//update
				printf("\n\n**********\n");
				printf("A�l�k: %.0f\nAlt�n: %.f\n", power[2], power[1]);
				printf("- H - Hafif antreman %.f alt�n\n", gold[0]);
				printf("- A - A��r antreman %.f alt�n\n", gold[1]);
				printf("- i - Bilgi\n");
				printf("- � - ��k\n");
				do {
					printf("Se�imini yap: ");
					scanf(" %c", &ch);
					if (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '�' && ch != '�' && ch != '�')
						printf("Ge�ersiz, ");
				} while (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '�' && ch != '�' && ch != '�');
			}
		}
		printf("\n\n");
	}
	displaytree(name);
}

void store(double power[], double gold[], char name[])
{
	char choice;

	//check the respect
	if (power[3] < 50)
	{
		printf("\n\nAnla��lan bu d�kkan sayg�s�zlara herhangi bir �ey satm�yor..\n");
	}
	else
	{
		//get choice
		{
			printf("\n\n************************");
			printf("\nD�kkana ho� geldin.");
			printf("\nAlt�n: %.f", power[1]);
			printf("\n- K - K�l�� - %.f alt�n", gold[2]);
			printf("\n- Z - Z�rh - %.f alt�n", gold[3]);
			printf("\n- � - �ksir - %.f alt�n", gold[4]);
			printf("\n- � - ��k��");
			printf("\n- B - Bilgi\n");
			do {
				printf("Se�imini yap: ");
				scanf(" %c", &choice);
				if (choice != '�' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�')
					printf("Ge�ersiz, ");
			} while (choice != '�' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�');
		}

		while (choice != '�' && choice != '�')
		{
			if (choice == 'b' || choice == 'B')
			{
				printf("\n****************************************");
				printf("\nD�kkandan al��veri� yaparak g��lenirsin.\n");
				printf("K�l�� atak puan�n� ve kriti�ini, z�rh defans�n� ve can�n� artt�r�r.\n");
				printf("Bu kasabadaki iksirlere g�veniyor musun?\n\n");
			}

			else if (choice == 'i' || choice == '�')
			{
				if (power[1] < round(gold[4]))
					printf("\nYeterli alt�na sahip de�ilsin.\n");
				else
				{

					//decrease hunger
					if (power[2] < 10)
						power[2] = 0;
					else
						power[2] -= 10;

					//decrease gold
					power[1] -= round(gold[4]);

					//increase statistics
					{
						int possib;

						//generate the possibility
						possib = rand() % ((10 + 1) - 1) + 1;
						
						if (possib <= 3)
						{
							//def
							power[4] += power[4] * 8 / 100 + 2;
							power[6] += power[6] * 8 / 100 + 2;
							
							printf("\n�anl� ��kt�n, iksir g�c�n� artt�rd�.");

							//increase price
							gold[4] += gold[4] * 7 / 100;
						}

						else if (possib <= 6)
						{
							//atk
							power[5] += power[5] * 8 / 100 + 2;
							power[7] += power[7] * 7 / 100 + 2;

							//display the message
							printf("\n�anl� ��kt�n, iksir g�c�n� artt�rd�.");
							Sleep(500);

							//increase price
							gold[4] += gold[4] * 7 / 100;
						}
						
						else
						{
							printf("\nZehirlendin.\nK�p�rd���n i�in sayg�n d��t�.");
							Sleep(500);

							//decrease respect
							if (power[3] < 10)
								power[3] = 0;
							else
								power[3] -= 3;
						}
					}
				}
			}

			else if (choice == 'z' || choice == 'Z')
			{
				if (power[1] < round(gold[3]))
					printf("\nYeterli alt�na sahip de�ilsin.\n");
				else
				{

					//decrease hunger
					if (power[2] < 10)
						power[2] = 0;
					else
						power[2] -= 10;

					//decrease gold	
					power[1] -= round(gold[3]);

					//increase statistics
					power[4] += power[4] * 7 / 100 + 2;
					power[6] += power[6] * 7 / 100 + 2;

					//increase price
					gold[3] += gold[3] * 9 / 100;

					//display the message
					printf("\nYeni z�rh� ald�n.\n");
					printf("G�c�n artt�.");
					Sleep(500);
				}
			}

			else if (choice == 'k' || choice == 'K')
			{
				if (power[1] < round(gold[2]))
					printf("\nYeterli alt�na sahip de�ilsin.\n");
				else
				{

					//decrease hunger
					if (power[2] < 10)
						power[2] = 0;
					else
						power[2] -= 10;

					//decrease gold
					power[1] -= round(gold[2]);

					//increase statistics
					power[5] += power[5] * 7 / 100 + 2;
					power[7] += power[7] * 7 / 100 + 2;

					//increase price
					gold[2] += gold[2] * 9 / 100;

					//display the message
					printf("\nYeni k�l�c� ald�n.\n");
					printf("G�c�n artt�.");
					Sleep(500);
				}
			}

			//update
			{
				printf("\n\n************************");
				printf("\nAlt�n: %.f", power[1]);
				printf("\n- K - K�l�� - %.f alt�n", gold[2]);
				printf("\n- Z - Z�rh - %.f alt�n", gold[3]);
				printf("\n- � - �ksir - %.f alt�n", gold[4]);
				printf("\n- � - ��k��");
				printf("\n- B - Bilgi\n");
				do {
					printf("Se�imini yap: ");
					scanf(" %c", &choice);
					if (choice != '�' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�')
						printf("Ge�ersiz, ");
				} while (choice != '�' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '�' && choice != '�');
			}
		}

	}
	printf("\n\n");
	displaytree(name);
}

void townstat(double power[])
{
	printf("            *****************************************************************\n");
	printf("            *Level   Alt�n   A�l�k   Sayg�   Can     Atak    Defans   Kritik*\n");
	printf("            *-----   -----   -----   -----   -----   -----   ------   ------*\n");
	printf("            *%5d%8.f%8.f%8.f%8.f%8.f%9.f%9.f*\n", int(power[0] / 10), power[1], power[2], power[3], power[4], power[5], power[6], power[7]);
	printf("            *****************************************************************\n");
}

void food(double power[], char name[])
{
	char choice;

	printf("\n\nYemekhaneye ho�geldin.\n");
	//get choice
	{
		printf("- Z - Ziyafet\n");
		printf("- P - Patates\n");
		printf("- E - Ev yemekleri\n");
		printf("- M - Mantar\n");
		printf("- � - ��k��\n");
		printf("- i - Bilgi\n");
		do {
			printf("Hangi men�y� istiyorsun: ");
			scanf(" %c", &choice);
			if (choice != '�' && choice != '�' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '�' && choice != 'z' && choice != 'Z')
				printf("Ge�ersiz, ");
		} while (choice != '�' && choice != '�' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '�' && choice != 'z' && choice != 'Z');
	}

	while (choice != '�' && choice != '�')
	{
		if (choice == 'i' || choice == '�')
		{
			printf("\nZiyafet �ekmek sayg�nl���n� 40 artt�r, karn�n� tamamen doyurur. 100 alt�n\n");
			printf("Patates her zamanki gibi en lezettli yemek, a�l���n�n yar�s�n� giderir. 50 alt�n\n");
			printf("Ev yemekleri �e�itli olmasada karn�n� biraz doyurabilirsin. 30 alt�n\n");
			printf("Mantar� se�iyorsan �ans�n� denemek zorundas�n. Kimse sonu�lar�n� bilmiyor. 20 alt�n\n\n");
		}

		else if (choice == 'p' || choice == 'P')
		{
			//gold
			if (power[1] < 50)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz �al��.\n\n");
			}
			else
			{

				power[1] -= 50;

				//hunger
				{
					if (power[2] >= 50)
						power[2] = 100;
					else
						power[2] += 50;
				}

				//message
				{
					printf("\n*****************************\n");
					printf("Patates k�zarmas� gibisi yok.\n");
					printf("A�l�k %.f'e y�kseldi.\n\n", power[2]);
				}
			}
		}

		else if (choice == 'e' || choice == 'E')
		{
			//gold
			if (power[1] < 30)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz �al��.\n\n");
			}
			else
			{
				power[1] -= 30;

				//hunger
				{
					if (power[2] >= 70)
						power[2] = 100;
					else
						power[2] += 30;
				}

				//message
				printf("\n*********************\nAfiyet olsun.");
				printf("\nA�l�k %.f'e y�kseldi.\n\n", power[2]);
			}
		}

		else if (choice == 'z' || choice == 'Z')
		{
			//gold
			if (power[1] < 100)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz �al��.\n\n");
			}
			else
			{
				power[1] -= 100;

				//hunger
				power[2] = 100;

				//respect
				{
					if (power[3] >= 50)
						power[3] = 100;
					else
						power[3] += 50;
				}

				//messages
				{
					printf("\n**************************************");
					printf("\nKral bile b�yle bi ziyafet �ekmemi�ti.\n");
					printf("Sayg�n���n %.f'e y�kseldi\n", power[3]);
					printf("Karn�n tamamen doydu.\n\n");
				}
			}
		}

		else if (choice == 'm' || choice == 'M')
		{
			int possib;
			//gold
			if (power[1] < 10)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz �al��.\n\n");
			}
			else
			{
				power[1] -= 10;

				//poisoned
				possib = rand() % ((10 + 1) - 1) + 1;
				if (possib == 1 || possib == 9 || possib == 4 || possib == 6)
				{
					printf("\n***********************************************");
					printf("\n Zehirlenerek kustun. Seni kasabaya g�t�rd�ler.\n Sayg�nl���n %d puan d��t�.\n\n", possib);
					choice = '�';
					if (power[3] > possib)
						power[3] -= possib;
					else
						power[3] = 0;
				}

				else
				{
					//hunger
					{
						if (power[2] >= 80)
							power[2] = 100;
						else
							power[2] += 20;
					}

					//message
					printf("\n********************");
					printf("\nA�l�k %.f'e y�kseldi.\n\n", power[2]);
				}
			}
		}

		//update
		if (choice != '�')
		{
			{
				printf("- Z - Ziyafet\n");
				printf("- P - Patates\n");
				printf("- E - Ev yemekleri\n");
				printf("- M - Mantar\n");
				printf("- � - ��k��\n");
				printf("- i - Bilgi\n");
				do {
					printf("Hangi men�y� istiyorsun: ");
					scanf(" %c", &choice);
					if (choice != '�' && choice != '�' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '�' && choice != 'z' && choice != 'Z')
						printf("Ge�ersiz, ");
				} while (choice != '�' && choice != '�' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '�' && choice != 'z' && choice != 'Z');
			}
		}
	}
	printf("\n\n");
	displaytree(name);
}

void townmenu(double power[], char name[], double gold[],double enemy[])
{
	char choice = 'A';
	while (choice != '�' && choice != '�') // it mans �.
	{
		//display the statistics of character 
		townstat(power);

		//display and get choice
		{
			printf("- A - Arena\n");
			printf("- Y - Yemekhane\n");
			printf("- D - D�kkan\n");
			printf("- S - Spor\n");
			printf("- G - G�rev\n");
			printf("- C - $ CASINO $\n");
			printf("- K - Kaydet\n");
			printf("- � - ��k��\n");
			printf("- i - Bilgi\n");
			do {
				printf("Se�imini gir: ");
				scanf(" %c", &choice);
				if (choice != 'A' && choice != 'a' && choice != 'y' && choice != 'Y' && choice != 'd' && choice != 'D' && choice != 's' && choice != 'S' && choice != 'G' && choice != 'g' && choice != 'c' && choice != 'C' && choice != 'K' && choice != 'k' && choice != '�' && choice != '�' && choice != 'i' && choice != '�')
					printf("Ge�ersiz se�im, ");
			} while (choice != 'A' && choice != 'a' && choice != 'y' && choice != 'Y' && choice != 'd' && choice != 'D' && choice != 's' && choice != 'S' && choice != 'G' && choice != 'g' && choice != 'c' && choice != 'C' && choice != 'K' && choice != 'k' && choice != '�' && choice != '�' && choice != 'i' && choice != '�');
		}

		if (choice == 'i' || choice == '�')
			towninformation();

		else if (choice == 'k' || choice == 'K')
			savegame(power, gold, enemy);

		else if (choice == 's' || choice == 'S')
			spor(power, name, gold);

		else if (choice == 'y' || choice == 'Y')
			food(power, name);
		else if (choice == 'a' || choice == 'A')
			arena(name, power, gold, enemy);

		else if (choice == 'D' || choice == 'd')
			store(power, gold, name);
		else if (choice == 'G' || choice == 'g')
			duties(power, name);
		else if (choice == 'c' || choice == 'C')
			casino(power, name);
	}
}

int main(void)
{
	//declare variables 
	double power[SIZE], gold[6],enemy[4];
	int namesize;
	char name[10];

	//include turkish characters and generate random characters
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	//creating new game or loading game
	opening(name, &namesize, power, gold, enemy);

	//display trees
	displaytree(name);

	//town menu and while loop
	townmenu(power, name, gold, enemy);

	return(0);
}