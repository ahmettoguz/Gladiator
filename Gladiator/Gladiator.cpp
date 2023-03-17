//GLADIATOR
//Ahmet Oðuz Ergin
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
//gold -->  hafif aðýr  silah zýrh iksir
//            0     1     2    3     4

void opening(char name[], int* namesize, double power[], double gold[],double enemy[])
{
	FILE* namehero;
	FILE* hero;
	FILE* shopp;
	FILE* enemi;
	char choice;

	//welcome user
	printf("- Y - Yeni oyun\n- K - Kayýtlý oyun: ");
	do {
		scanf(" %c", &choice);
		if ((choice != 'K' && choice != 'Y' && choice != 'y' && choice != 'k'))
			do
			{
				printf("Geçersiz seçim, tekrar gir: ");
				scanf(" %c", &choice);
			} while (choice != 'K' && choice != 'Y' && choice != 'y' && choice != 'k');
			if (choice == 'y' || choice == 'Y')
			{
				printf("Yeni oyuna baþlamak istediðine emin misin?\n");
				printf("- E - Evet\n");
				printf("- H - Hayýr: ");
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
			printf("\nBu an yeni bir hikayenin baþlangýcý deðil, bir kahramanýn doðuþu!");
			printf("\nLütfen oyuncu adýnýzý girin: ");
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
			printf("\nHoþgeldin %s. Bir gladyatör olarak seçeneklerinin ne kadar önemli olduðunu unutma.\n", name);
			printf("Can puanýna, açlýðýna ve saygýnlýðýna dikkat ederek hayatta kalmaya çalýþ.\n");
			printf("Can, Atak, Defans, Kritik gibi özelliklerin bulunmakta ve level atladýkça bunlarý arttýrabilirsin.\nBir gladyatör olarak arena'da savaþ.\n");
			printf("Kasabada istediðini yapmakta özgürsün.\nAklýnýn karýþtýðý yerde bilgi seçeneðini kullanarak neler yapabileceðini öðrenebilirsin...");
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
			printf("Kayýtlý veri bulunmamakta.");
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
	printf("\n                            Kasabaya hoþgeldin gladyatör %s\n\n", name);
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

	printf("\nBilgilerin güvenli bir þekilde kaydedildi.\n");
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
		printf("                                 Savaþ zamaný %s\n", name);
		printf("                            ***************************\n\n");
		Sleep(500);
		printf("                %s                    VS                Düþman\n", name);
		printf("   *******************************************************************************\n");
		printf("     Can    Atak     Defans    Kritik    ||     Can    Atak     Defans    Kritik\n");
		printf("%8.f%7.f%10.f%10.f%16.f%7.f%10.f%10.f\n", power[4], power[5], power[6], power[7], enemy[0], enemy[1], enemy[2], enemy[3]);
		printf("   *******************************************************************************\n");
		Sleep(500);
		printf("\n- S - Savaþ\n");
		printf("- K - Kaç\n");
		printf("- B - Bilgi\n");
		do {
			printf("Seçimini yap: ");
			scanf(" %c", &choice);
			if (choice != 's' && choice != 'S' && choice != 'k' && choice != 'K' && choice != 'b' && choice != 'B')
				printf("geçersiz, ");
		} while (choice != 's' && choice != 'S' && choice != 'k' && choice != 'K' && choice != 'b' && choice != 'B');
	}

	//check the respect and hunger
	if (power[3] < 70)
	{
		printf("\nArenada savaþabilmek için saygý toplaman lazým.");
		Sleep(3000);
	}
	else
	{
		if( power[2]<50)
			printf("\nArenada savaþabilmek için karnýný doyurman gerekir.");
		else
		{

			if (choice == 'b' || choice == 'B')
			{
				printf("\nArenada savaþarak level atlayýp güçlenirsin.\n");
				printf("Kazandýkça level atlarsýn, güçlenir ve altýn kazanýrsýn.\n");
				printf("Ayný zamanda gittikçe düþmanýn gücü de artar.\n");
				printf("3 farklý saldýrý 3 türü vardýr.\n");
				printf("Hýzlý saldýrýda saldýrma þansýn daha yüksektir ama hasar, atak puanýn kadardýr.\n");
				printf("Normal saldýrýda saldýrma þansýn daha düþük ama hasar biraz daha fazladýr.\n");
				printf("Güçlü saldýrýda saldýrma þansýn düþük ama hasarýn daha fazladýr.\n\n");
				printf("- S - Savaþ\n");
				printf("- K - Kaç\n");
				do {
					printf("Seçimini yap: ");
					scanf(" %c", &choice);
					if (choice != 's' && choice != 'S' && choice != 'K' && choice != 'k')
						printf("Geçersiz seçim, ");
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
						printf("                     Senin canýn: %d     ||     Düþmanýn caný: %d\n", heroo, enemyy);
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
							printf("     H - Hýzlý saldýrý(%%80) || N - Normal saldýrý(%%60) || G -Güçlü saldýrý(%%40)\n\n");
							printf("                                       <<<>>>\n");
							do {
								printf("                                       Saldýr: ");
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
								printf("\n                                   Sýra rakibinde \n");
								Sleep(500);
							}

							//display the attack messeage and decrease the hp
							{
								if (pos / 10 <= 7)
								{
									printf("\n                                   ");

									if (enemy[1] + ceil(enemy[3] / 10) >= ceil(power[6] / 10))
									{
										printf("Alýnan hasar: %.f\n", enemy[1] + ceil(enemy[3] / 10) - ceil(power[6] / 10));
										heroo -= enemy[1] + ceil(enemy[3] / 10) - ceil(power[6] / 10);
										Sleep(500);
									}
									else
									{
										printf("Alýnan hasar: %.f\n", 0);
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
						printf("                             Yeterince güçlenip tekrar gel.");
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
						printf("                                     Kazandýn. !!!\n");
						Sleep(500);
						printf("                                 %.f Altýn kazandýn\n", gold[5]);
						printf("                             Kasabadaki saygýnlýðýn arttý.\n");
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
								printf("                            Tebrikler lvl atladýn. !!!\n");
								do {
									printf("           Hangi özelliðini yükseltmek istiyorsun A - Atak, D - Defans: ");
									scanf(" %c", &choice);
								} while (choice != 'a' && choice != 'A' && choice != 'd' && choice != 'D');

									printf("Gücün baþarýyla arttý.\n");
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
	char choice, ch='€';


	//get first choice
	{
		displaycasino(name);
		printf("\nCasino' ya hoþgeldin %s.\n", name);
		printf("Þuanki altýnýn: %.f\n", power[1]);
		printf("$ R $ Rulet\n");
		printf("$ Ý $ iddaa\n");
		printf("$ 2 $ 21(Blackjack)\n");
		printf("- B - Bilgi\n");
		printf("- Ç - Çýkýþ\n");
		do {
			printf("Seçimini yap: ");
			scanf(" %c", &choice);
		} while (choice != 'r' && choice != 'R' && choice != '2' && choice != 'i' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€' && choice != '˜');
		printf("\n\n");
	}

	while (choice != '‡' && choice != '€')
	{
		if (choice == 'b' || choice == 'B')
		{
			printf("Oyun oynayabilmek için saygýnlýðýnýn olmasý gerekir.\n");
			printf("Risk alarak altýn kazanabilirsin.\n");
			printf("Farklý oyunlar var.\n");
			printf("Rulette þansýn %%50 dir.\n");
			printf("Ýddia da risk oranlarý ve kazançlar farklýdýr.\n");
			printf("Blackjack oynarken elindeki kartlarý 21'e en yakýn yapmaya çalýþýrsýn.\n");
			printf("Eðer 21 olursa elindeki kartlar kesin olarak kazanýrsýn.\n");
			printf("10 a kadar sayýlar verilir her el.\n");
			printf("Eðer elindeki kartlarýn sayýsý 21 e yakýn deðilse\n ve risk almak istersen kart çekebilirsin ama 21' i geçerse kurpiyer kazanýr.\n");
			printf("Kurpiyerde ayný þekilde 21' i gerse kaybeder.\n");
			printf("Ama kurpiyer en az 17 olmasý lazýmdýr. Oyun sonunda kurpiyer elini açar.");
		}
		
		else if (choice=='2')
		{
			//check the respect point and hunger
			if (power[3] < 60)
				printf("Oyun oynayabilmek için saygýn biri olman lazým.");
			else
			{
				//decrease hunger
				if (power[2] < 10)
					printf("Açlýktan ölüyorsun!");
				else
				{
					if (power[2] < 3)
						power[2] = 0;
					else
						power[2] -= 3;
					
					printf("Sahip olduðun altýn miktarý %.f\n", power[1]);
					do {
						printf("Ne kadar altýn koyuyorsun: ");
						status = scanf("%d", &bah);
						if (bah > power[1])
							printf("Burda çakallara yer yok aslaným, ");
						if (bah <= 0)
							printf("Geçersiz, ");
					} while ((bah <= 0 || bah > power[1]) && status != 0);
					
					if (status == 0)
					{
						printf("Karakter girdin..\n\n");
						choice = '‡';
					}
					else
					{
						int kurpi, player, sumplayer = 0, sumkurpi = 0;
						printf("\nKaðýtlar daðýtýldý.\n");
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
							printf("\n\n%d kadar altýn kazandýn.\n", bah);
							power[1] += bah;
							printf("Saygýnlýk 10 puan arttý.\n");

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
								printf("Seçimini yap: ");
								scanf(" %c", &ch);
								if (ch != 'i' && ch != '˜' && ch != 'k' && ch != 'K')
									printf("Geçersiz, ");
							} while (ch != 'i' && ch != '˜' && ch != 'k' && ch != 'K');

							while (ch != 'k' && ch != 'K'&&sumplayer<22)
							{
								player = rand() % ((10 + 1) - 1) + 1;
								printf("-------------------\n");
								printf("    %d + %d = ", sumplayer,player);
								sumplayer += player;
								printf("%d\n", sumplayer);
								printf("-------------------\n");

								//battý
								if (sumplayer > 21)
								{
									printf("Kaybettin.\nElin 21' i geçti\n");
									power[1] -= bah;

									printf("Saygýnlýk 3 puan azaldý.\n");

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
											printf("Seçimini yap: ");
											scanf(" %c", &ch);
											if (ch != 'i' && ch != '˜' && ch != 'k' && ch != 'K')
												printf("Geçersiz, ");
										} while (ch != 'i' && ch != '˜' && ch != 'k' && ch != 'K');
									}
								}
							}
							
							if (sumplayer > 21);
							else
							{
								printf("\nSýra kurpiyede\n");
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
									printf("\nKurpiyenin eli 17' nin altýnda oluðu için kart çekiyor.\n");
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
									printf("Kurpiyerin eli 21' i geçti.\n");
									printf("%d altýn kazandýn.\n", bah);
									power[1] += bah;
									printf("Saygýnlýk 3 puan arttý.\n");

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
										printf("Kurpiyeri geçtin.\n");
										printf("%d altýn kazandýn.\n", bah);
										power[1] += bah;
										printf("Saygýnlýk 3 puan arttý.\n");

										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else if(sumkurpi > sumplayer)
									{
										Sleep(500);
										printf("\nKaybettin.\n");
										printf("Kurpiyeri seni geçti.\n");
										power[1] -= bah;

										printf("Saygýnlýk 3 puan azaldý.\n");

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

		else if (choice == 'i' || choice == '˜')
		{
			//check the respect point and money
			if (power[3] < 60 || power[1] == 0)
				printf("Burda oyun oynayabilmek için kumarhanenin saygýsýný kazanman gerekir.\n");
			else
			{
				//decrease hunger
				if (power[2] < 10)
					printf("Açlýktan ölüyorsun!");
				else
				{
					if (power[2] < 3)
						power[2] = 0;
					else
						power[2] -= 3;

					//get the choice
					{
						printf("$ F $ Fenerbahçe\n");
						printf("$ G $ Galatasaray\n");
						printf("$ B $ Beþiktaþ\n");
						printf("$ K $ Keçiören\n");
						printf("- Ý - Bilgi\n");
						printf("- Ç - Çýkýþ\n");
						do {
							printf("Seçimini gir: ");
							scanf(" %c", &ch);
							if (ch != 'k' && ch != 'K' && ch != 'f' && ch != 'F' && ch != 'g' && ch != 'G' && ch != 'b' && ch != 'B' && ch != 'i' && ch != '˜' && ch != '‡' && ch != '€')
								printf("Geçersiz, ");
							printf("\n");
						} while (ch != 'k' && ch != 'K' && ch != 'f' && ch != 'F' && ch != 'g' && ch != 'G' && ch != 'b' && ch != 'B' && ch != 'i' && ch != '˜' && ch != '‡' && ch != '€');

						if (ch == 'i' || ch == '˜')
						{
							printf("Takýmlarýn kazanma oranlarý ve dolayýsýyla da kazanç oranlarýn farklýdýr.\n");
							printf("Fenerbahçe'nin kazanma oraný %%80 dir\n\n");
							printf("Kar oraný bahse koyduðun paranýn %%20' si dir.\n");
							printf("----------------------------------------------\n");
							printf("Galatasaray'ýn kazanma oraný %%60 týr.\n");
							printf("Kar oraný bahse koyduðun paranýn %%40' ý dýr.\n");
							printf("----------------------------------------------\n");
							printf("Beþiktaþ' ýn kazanma oraný %%40 dýr.\n");
							printf("Kar oraný koyduðun paranýn %%160' si dir\n");
							printf("----------------------------------------------\n");
							printf("Keçiörengücü' nün kazanma oraný %%30 dur.\n");
							printf("Kar oraný %%200' dür.");
						}

						else if (ch != '‡' && ch != '€')
						{
							if (ch == 'f' || choice == 'F')
							{
								printf("\nÞuanki altýnýn: %.f\n", power[1]);
								printf("Fenerbahçe'ye ne kadar yatýrmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Geçersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda çakallýk iþe yaramaz aslaným, tekrar gir: ");
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
										printf("Fenerbahçe kazandý.\n");
										printf("%d altýn kazandýn.\n", int(ceil((double)bah * 20 / 100)));
										power[1] += int(ceil((double)bah * 20 / 100));
										printf("Saygýnlýðýn 3 arttý.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else
									{
										printf("\nFenerbahçe kaybetti.\n");
										printf("Saygýnlýðýn 3 azaldý.\n");
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
								printf("\nÞuanki altýnýn: %.f\n", power[1]);
								printf("Galatasaray'a ne kadar yatýrmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Geçersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda çakallýk iþe yaramaz aslaným, tekrar gir: ");
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
										printf("Galatasaray kazandý.\n");
										printf("%d altýn kazandýn.\n", int(ceil((double)bah * 40 / 100)));
										power[1] += int(ceil((double)bah * 40 / 100));
										printf("Saygýnlýðýn 3 arttý.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else
									{
										printf("Galatasaray kaybetti.\n");
										printf("Saygýnlýðýn 3 azaldý.\n");
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
								printf("\nÞuanki altýnýn: %.f\n", power[1]);
								printf("Beþiktaþ'a ne kadar yatýrmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Geçersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda çakallýk iþe yaramaz aslaným, tekrar gir: ");
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
										printf("Beþiktaþ kazandý.\n");
										printf("%d altýn kazandýn.\n", int(ceil((double)bah * 160 / 100)));
										power[1] += int(ceil((double)bah * 160 / 100));
										printf("Saygýnlýðýn 3 arttý.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}

									else
									{
										printf("\nBeþiktaþ kaybetti.\n");
										printf("Saygýnlýðýn 3 azaldý.\n");
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
								printf("\nÞuanki altýnýn: %.f\n", power[1]);
								printf("Keçiören'a ne kadar yatýrmak istersin: ");
								do {
									status = scanf("%d", &bah);
									if (bah <= 0 && status != 0)
										printf("Geçersiz miktar, tekrar gir: ");
									else if (bah > power[1] && status != 0)
										printf("Burda çakallýk iþe yaramaz aslaným, tekrar gir: ");
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
										printf("Keçiören kazandý.\n");
										printf("%d altýn kazandýn.\n", int(ceil((double)bah * 200 / 100)));
										power[1] += int(ceil((double)bah * 200 / 100));
										printf("Saygýnlýðýn 3 arttý.\n");
										if (power[3] > 97)
											power[3] = 100;
										else
											power[3] += 3;
									}
									else
									{
										printf("\nKeçiören kaybetti.\n");
										printf("Saygýnlýðýn 3 azaldý.\n");
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
				printf("Burda oyun oynayabilmek için kumarhanenin saygýsýný kazanman gerekir.\n");
			else
			{
				//decrease hunger
				if (power[2] < 10)
					printf("Açlýktan ölüyorsun!");
				else
				{
					if (power[2] < 3)
						power[2] = 0;
					else
						power[2] -= 3;

					//get choice
					{
						printf("$ K $ Kýrmýzý\n");
						printf("$ S $ Siyah\n");
						printf("- Ç - Çýkýþ\n");
						do {
							printf("Seçimini yap:");
							scanf(" %c", &ch);
							if (ch != 'k' && ch != 'K' && ch != 's' && ch != 'S' && ch != '‡' && ch != '€')
								printf("Geçersiz, ");
						} while (ch != 'k' && ch != 'K' && ch != 's' && ch != 'S' && ch != '‡' && ch != '€');
					}
				}

				if (ch != '‡' && ch != '€')
				{
					//get the money and check it
					printf("\nÞuanki altýnýn: %.f\n", power[1]);
					do
					{
						printf("Ne kadar para koyuyorsun: ");
						status = scanf("%d", &bah);
						if (bah <= 0)
							printf("Geçersiz miktar, ");
						if (bah > power[1])
							printf("Kurnazlýk yapma, ");
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
									printf("%d altýn kazandýn.\n", bah);
									power[1] += bah;
									printf("Saygý puanýn 3 arttý.\n");
									if (power[3] > 97)
										power[3] = 100;
									else
										power[3] += 3;
								}
								else
								{
									printf("\nKaybettin\n");
									printf("Siyah çýktý.\n");
									printf("Saygý puanýn 3 azaldý.\n");
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
									printf("Kýrmýzý çýktý.\n");
									printf("Saygý puanýn 3 azaldý.\n");
									power[1] -= bah;
									if (power[3] >= 3)
										power[3] -= 3;
									else
										power[3] = 0;
								}
								else
								{
									printf("\nTebrikler!!\n");
									printf("%d altýn kazandýn.\n", bah);
									power[1] += bah;
									printf("Saygý puanýn 3 arttý.\n");
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
			printf("\nÞuanki altýnýn: %.f", power[1]);
			printf("\n$ R $ Rulet\n");
			printf("$ Ý $ Ýddaa\n");
			printf("$ 2 $ 21(Blackjack)\n");
			printf("- B - Bilgi\n");
			printf("- Ç - Çýkýþ\n");
			do {
				printf("Seçimini yap: ");
				scanf(" %c", &choice);
				if (choice != 'r' && choice != 'R' && choice != '2' && choice != 'i' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€' && choice != '˜')
					printf("Geçersiz, ");
			} while (choice != 'r' && choice != 'R' && choice != '2' && choice != 'i' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€' && choice != '˜');
			printf("\n\n");
		}
	}
	displaytree(name);
}

void towninformation(void)
{
	printf("\nBurda çeþitli seçeneklere sahipsin ihtiyacýna göre gitmen gereken yere git.\n");
	printf("Arena - Savaþarak level atlayabilirsin böylelikle gücünü arttýrabilirsin.\n");
	printf("Yemekhane - Acýktýðýn zaman beslenmen gerekiyor yoksa yapabileceðin þeyler sýnýrlanýr.\n");
	printf("Ayrýca yemekhanede ziyafet vererek saygýnlýðýný arttýrabilirsin.\n");
	printf("Dükkan - Zýrh ve kýlýç alarak güçlenebileceðin yer.\n");
	printf("Spor - Kaslarýný zorlayarak gücünü arttýrabilirsin. Dikkat et fazla yüklenme.\n");
	printf("Görevler - Para kazanmak için eðlenceli seçenekler var.\n");
	printf("Casino - Çeþitli oyunlarla paraný katlayabilirsin.\n");
	printf("Kasabadan atýlmak istemiyorsan saygýnlýðýnda dikkat et. Pek misafirperver deðil burdakiler.\n");
	printf("Canýna ve parana dikkat et, çakallarýn olduðu bu kasabada dar sokaklardan geçerken götü kolla..\n");
	printf("OYUNU KAYDETMEYÝ UNUTMA !!!!!!\n\n");
}

void duties(double power[], char  name[])
{
	char choice;
	int password[2][5], pw, status = 1, turn, pww, digit, r;

	//get choice
	{
		printf("\n\n\n");
		printf("**********************************\n");
		printf("Yeraltýna hoþgeldin %s.\n", name);
		printf("- K - Kasa þifresi kýrma\n");
		printf("- Ý - Ýstihbarat saldýrýsý\n");
		printf("- B - Bilgi\n");
		printf("- Ç - Çýkýþ\n");
		do
		{
			printf("Seçimini yap: ");
			scanf(" %c", &choice);
			if (choice != 'k' && choice != 'K' && choice != 'i' && choice != '˜' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€')
				printf("Geçersiz, ");
		} while (choice != 'k' && choice != 'K' && choice != 'i' && choice != '˜' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€');
	}

	while (choice != '‡' && choice != '€')
	{

		if (choice == 'b' || choice == 'B')
		{
			printf("\n\nBurda görevleri yaparak altýn kazanabilirsin.\n");
			printf("Þuanki altýnýn: %.f\n", power[1]);
			printf("Kasa þifresi için 5 basamaklý bir þifreyi deneyerek kýrmaya çalýþýrsýn.\n");
			printf("Ýstihbarat saldýrýsýnda kralýn telefon konuþmasýnda geçen kelimeleri kodlara göre çözümleyip satarsýn.\n\n");
		}

		else if (choice == 'i' || choice == '˜')
		{
			int word[10];

			//decrease hunger
			{
				if (power[2] > 10)
					power[2] -= 10;
				else
					power[2] = 0;
			}

			printf("\nBurda sana verilen tabloya göre þifrelenmiþ olan konuþmanýn harlerini yazman lazým.\n");
			printf("Ýþte tablo\n------------>\n");
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
					printf("\nAralarýnda boþluk býrakarak sayýlara karþýlýk gelen harfleri yaz.\n               ");
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
						printf("\nKablolardan çaldýðýn sözcükleri baþarýyla ilettin.\n");

						if (power[0] > 0 && power[0] <= 30)
						{
							printf("Ödül olarak 2000 altýn kazandýn.\n\n");
							power[1] += 2000;
						}
						else if (power[0] > 30 && power[0] <= 50)
						{
							printf("Ödül olarak 5000 altýn kazandýn.\n\n");
							power[1] += 5000;
						}
						else if (power[0] > 50 && power[0] <= 70)
						{
							printf("Ödül olarak 10000 altýn kazandýn.\n\n");
							power[1] += 10000;
						}
						else
						{
							printf("Ödül olarak 20000 altýn kazandýn.\n\n");
							power[1] += 20000;
						}						
					}
					else
						printf("\nÇaldýðýn kelimeleri doðru iletemedin.\n\n");
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
					printf("Þifreyi gir: ");
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
						printf("\n %d deneme hakkýn kaldý.\n", 8 - turn);
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
							printf("Þifreyi gir: ");
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
					printf("\n\n>>>>>>>>>>>>>>>>>>>\nTebrikler þifreyi çözmeyi baþardýn.\n20000 altýn kazandýn.\nSaygýnlýðýn 10 arttý\n>>>>>>>>>>>>>>>>>>>\n\n");
					power[1] += 20000;
					if (power[3] <= 90)
						power[3] += 10;
					else
						power[3] = 100;
				}

				else if (turn == 8)
				{
					printf("\nKasayý patlatamadýn.\n");
					printf("Polisler yakaladý kasabaya paketlediler.\n");
					printf("Saygýnlýðýn 5 azaldý.\n\n");
					if (power[3] > 5)
						power[3] -= 5;
					else
						power[3] = 0;
				}

				else if (status == 0)
				{
					printf("\nKarakter girdin..");
					printf("\nKasayý patlatamadýn.\n");
					printf("Polisler yakaladý kasabaya paketlediler.\n");
					printf("Saygýnlýðýn 15 azaldý.\n\n");
					if (power[3] > 5)
						power[3] -= 5;
					else
						power[3] = 0;
				}

				else if (password[1][4] == -1)
				{
					printf("\nKasayý býrakýp tüydün.\n");
					printf("Bu davranýþýndan dolayý saygýnlýðýný 15 kaybettin.\n\n");
					if (power[3] > 10)
						power[3] -= 15;
					else
						power[3] = 0;
				}
			}
		}

		//update
		printf("\n**********************************\n");
		printf("- K - Kasa þifresi kýrma\n");
		printf("- Ý - Ýstihbarat saldýrýsý\n");
		printf("- B - Bilgi\n");
		printf("- Ç - Çýkýþ\n");
		do
		{
			printf("Seçimini yap: ");
			scanf(" %c", &choice);
			if (choice != 'k' && choice != 'K' && choice != 'i' && choice != '˜' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€')
				printf("Geçersiz, ");
		} while (choice != 'k' && choice != 'K' && choice != 'i' && choice != '˜' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€');
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
	printf("Açlýk: %.0f\nAltýn: %.f\n", power[2], power[1]);
	printf("- H - Hafif antreman %.f altýn\n", gold[0]);
	printf("- A - Aðýr antreman %.f altýn\n", gold[1]);
	printf("- i - Bilgi\n");
	printf("- Ç - Çýk\n");
	do {
		printf("Seçimini yap: ");
		scanf(" %c", &ch);
		if (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '˜' && ch != '‡' && ch != '€')
			printf("Geçersiz, ");
	} while (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '˜' && ch != '‡' && ch != '€');

	//check respect
	if (power[3] < 20)
	{
		printf("Saygýsýzlýðýn lüzumu yok!\n\n\n");
		displaytree(name);
	}
	else
	{
		while (ch != '‡' && ch != '€')
		{
			//perform
			if (ch == 'i' || ch == '˜')
			{
				printf("\nAçlýk: %f.0\n", power[2]);
				printf("Spor yaparak gücünü arttýrabilirsin.\n");
				printf("Hafif antreman gücünü 1 arttýrýrken aðýr antreman 2 arttýrýr.\n");
				printf("Aðýr antremanda sakatlanma þansýn daha yüksektir.\n");
				printf("Spor yaparken fazla enerji tüketirsin, açlýðýna dikkat et bayýlma.\n\n");
			}
			else
			{
				//açlýk varsa dön
				if (power[2] < 20)
				{
					power[3] -= 10;
					ch = '€';
					printf("Þekerin düþtü. Kasabaya zar zor döndün. Saygýnlýk 10 puan azaldý.\n\n\n");
				}

				else
				{
					possib = rand() % ((10 + 1) - 1) + 1;

					//aðýr antreman
					if (ch == 'a' || ch == 'A')
					{
						if (power[1] < round(gold[1]))
							printf("\nYeterli altýnýn yok!\n\n");
						else
						{
							power[2] -= 15;
							power[1] -= round(gold[1]);
				
							if (possib == 3 || possib == 5 || possib == 7 || possib == 9)
							{
								printf("\nFazla yüklendin, geliþme gösteremedin.\n\n");
								Sleep(1000);
							}
							else
							{
								if (possib >= 0 && possib <= 2)
								{
									power[4] += round(power[4] * 10 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nToplam can %.0f puan arttý.\n", round(power[5] * 10 / 100 + 2));
								}
								else if (possib <= 4)
								{
									power[5] += round(power[5] * 10 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nAtak %.0f puan arttý.\n", round(power[5] * 10 / 100 + 2));
								}
								else if (possib <= 8)
								{
									power[6] += round(power[6] * 10 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nDefans %.0f puan arttý.\n", round(power[5] * 10 / 100 + 2));
								}
								else if (possib <= 10)
								{
									power[7] += round(power[7] * 10 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nKritik %.0f puan arttý.\n", round(power[7] * 10 / 100 + 2));
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
							printf("\nYeterli altýnýn yok!\n\n");
						else
						{
							power[2] -= 10;
							power[1] -= round(gold[0]);
							if (possib == 7 || possib == 9)
							{
								printf("\nFazla yüklendin, geliþme gösteremedin.\n\n");
								Sleep(1000);
							}
							else
							{
								if (possib >= 0 && possib <= 2)
								{
									power[4] += round(power[4] * 6 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nToplam can %.0f puan arttý.\n", round(power[5] * 6 / 100 + 2));
								}
								else if (possib <= 4)
								{
									power[5] += round(power[5] * 6 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nAtak %.0f puan arttý.\n", round(power[5] * 6 / 100 + 2));
								}
								else if (possib <= 7)
								{
									power[6] += round(power[6] * 6 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nDefans %.0f puan arttý.\n", round(power[5] * 6 / 100 + 2));
								}
								else if (possib <= 10)
								{
									power[7] += round(power[5] * 6 / 100 + 2);
									printf("\nBaþarýyla tamamladýn.");
									printf("\nKritik %.0f puan arttý.\n", round(power[5] * 6 / 100 + 2));
								}
								Sleep(1000);

								//increase price
								gold[0] += gold[0] *7 / 100;
							}
						}
					}
				}
			}

			if (ch != '€')
			{
				//update
				printf("\n\n**********\n");
				printf("Açlýk: %.0f\nAltýn: %.f\n", power[2], power[1]);
				printf("- H - Hafif antreman %.f altýn\n", gold[0]);
				printf("- A - Aðýr antreman %.f altýn\n", gold[1]);
				printf("- i - Bilgi\n");
				printf("- Ç - Çýk\n");
				do {
					printf("Seçimini yap: ");
					scanf(" %c", &ch);
					if (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != 'Ý' && ch != '‡' && ch != '€')
						printf("Geçersiz, ");
				} while (ch != 'h' && ch != 'H' && ch != 'a' && ch != 'A' && ch != 'i' && ch != '˜' && ch != '‡' && ch != '€');
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
		printf("\n\nAnlaþýlan bu dükkan saygýsýzlara herhangi bir þey satmýyor..\n");
	}
	else
	{
		//get choice
		{
			printf("\n\n************************");
			printf("\nDükkana hoþ geldin.");
			printf("\nAltýn: %.f", power[1]);
			printf("\n- K - Kýlýç - %.f altýn", gold[2]);
			printf("\n- Z - Zýrh - %.f altýn", gold[3]);
			printf("\n- Ý - Ýksir - %.f altýn", gold[4]);
			printf("\n- Ç - Çýkýþ");
			printf("\n- B - Bilgi\n");
			do {
				printf("Seçimini yap: ");
				scanf(" %c", &choice);
				if (choice != '˜' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€')
					printf("Geçersiz, ");
			} while (choice != '˜' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€');
		}

		while (choice != '‡' && choice != '€')
		{
			if (choice == 'b' || choice == 'B')
			{
				printf("\n****************************************");
				printf("\nDükkandan alýþveriþ yaparak güçlenirsin.\n");
				printf("Kýlýç atak puanýný ve kritiðini, zýrh defansýný ve canýný arttýrýr.\n");
				printf("Bu kasabadaki iksirlere güveniyor musun?\n\n");
			}

			else if (choice == 'i' || choice == '˜')
			{
				if (power[1] < round(gold[4]))
					printf("\nYeterli altýna sahip deðilsin.\n");
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
							
							printf("\nÞanlý çýktýn, iksir gücünü arttýrdý.");

							//increase price
							gold[4] += gold[4] * 7 / 100;
						}

						else if (possib <= 6)
						{
							//atk
							power[5] += power[5] * 8 / 100 + 2;
							power[7] += power[7] * 7 / 100 + 2;

							//display the message
							printf("\nÞanlý çýktýn, iksir gücünü arttýrdý.");
							Sleep(500);

							//increase price
							gold[4] += gold[4] * 7 / 100;
						}
						
						else
						{
							printf("\nZehirlendin.\nKöpürdüðün için saygýn düþtü.");
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
					printf("\nYeterli altýna sahip deðilsin.\n");
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
					printf("\nYeni zýrhý aldýn.\n");
					printf("Gücün arttý.");
					Sleep(500);
				}
			}

			else if (choice == 'k' || choice == 'K')
			{
				if (power[1] < round(gold[2]))
					printf("\nYeterli altýna sahip deðilsin.\n");
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
					printf("\nYeni kýlýcý aldýn.\n");
					printf("Gücün arttý.");
					Sleep(500);
				}
			}

			//update
			{
				printf("\n\n************************");
				printf("\nAltýn: %.f", power[1]);
				printf("\n- K - Kýlýç - %.f altýn", gold[2]);
				printf("\n- Z - Zýrh - %.f altýn", gold[3]);
				printf("\n- Ý - Ýksir - %.f altýn", gold[4]);
				printf("\n- Ç - Çýkýþ");
				printf("\n- B - Bilgi\n");
				do {
					printf("Seçimini yap: ");
					scanf(" %c", &choice);
					if (choice != '˜' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€')
						printf("Geçersiz, ");
				} while (choice != '˜' && choice != 'i' && choice != 'k' && choice != 'K' && choice != 'z' && choice != 'Z' && choice != 'b' && choice != 'B' && choice != '‡' && choice != '€');
			}
		}

	}
	printf("\n\n");
	displaytree(name);
}

void townstat(double power[])
{
	printf("            *****************************************************************\n");
	printf("            *Level   Altýn   Açlýk   Saygý   Can     Atak    Defans   Kritik*\n");
	printf("            *-----   -----   -----   -----   -----   -----   ------   ------*\n");
	printf("            *%5d%8.f%8.f%8.f%8.f%8.f%9.f%9.f*\n", int(power[0] / 10), power[1], power[2], power[3], power[4], power[5], power[6], power[7]);
	printf("            *****************************************************************\n");
}

void food(double power[], char name[])
{
	char choice;

	printf("\n\nYemekhaneye hoþgeldin.\n");
	//get choice
	{
		printf("- Z - Ziyafet\n");
		printf("- P - Patates\n");
		printf("- E - Ev yemekleri\n");
		printf("- M - Mantar\n");
		printf("- Ç - Çýkýþ\n");
		printf("- i - Bilgi\n");
		do {
			printf("Hangi menüyü istiyorsun: ");
			scanf(" %c", &choice);
			if (choice != '‡' && choice != '€' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '˜' && choice != 'z' && choice != 'Z')
				printf("Geçersiz, ");
		} while (choice != '‡' && choice != '€' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '˜' && choice != 'z' && choice != 'Z');
	}

	while (choice != '‡' && choice != '€')
	{
		if (choice == 'i' || choice == '˜')
		{
			printf("\nZiyafet çekmek saygýnlýðýný 40 arttýr, karnýný tamamen doyurur. 100 altýn\n");
			printf("Patates her zamanki gibi en lezettli yemek, açlýðýnýn yarýsýný giderir. 50 altýn\n");
			printf("Ev yemekleri çeþitli olmasada karnýný biraz doyurabilirsin. 30 altýn\n");
			printf("Mantarý seçiyorsan þansýný denemek zorundasýn. Kimse sonuçlarýný bilmiyor. 20 altýn\n\n");
		}

		else if (choice == 'p' || choice == 'P')
		{
			//gold
			if (power[1] < 50)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz çalýþ.\n\n");
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
					printf("Patates kýzarmasý gibisi yok.\n");
					printf("Açlýk %.f'e yükseldi.\n\n", power[2]);
				}
			}
		}

		else if (choice == 'e' || choice == 'E')
		{
			//gold
			if (power[1] < 30)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz çalýþ.\n\n");
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
				printf("\nAçlýk %.f'e yükseldi.\n\n", power[2]);
			}
		}

		else if (choice == 'z' || choice == 'Z')
		{
			//gold
			if (power[1] < 100)
			{
				printf("\n*****************************\n");
				printf("Paran yetersiz, biraz çalýþ.\n\n");
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
					printf("\nKral bile böyle bi ziyafet çekmemiþti.\n");
					printf("Saygýnýðýn %.f'e yükseldi\n", power[3]);
					printf("Karnýn tamamen doydu.\n\n");
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
				printf("Paran yetersiz, biraz çalýþ.\n\n");
			}
			else
			{
				power[1] -= 10;

				//poisoned
				possib = rand() % ((10 + 1) - 1) + 1;
				if (possib == 1 || possib == 9 || possib == 4 || possib == 6)
				{
					printf("\n***********************************************");
					printf("\n Zehirlenerek kustun. Seni kasabaya götürdüler.\n Saygýnlýðýn %d puan düþtü.\n\n", possib);
					choice = '€';
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
					printf("\nAçlýk %.f'e yükseldi.\n\n", power[2]);
				}
			}
		}

		//update
		if (choice != '€')
		{
			{
				printf("- Z - Ziyafet\n");
				printf("- P - Patates\n");
				printf("- E - Ev yemekleri\n");
				printf("- M - Mantar\n");
				printf("- Ç - Çýkýþ\n");
				printf("- i - Bilgi\n");
				do {
					printf("Hangi menüyü istiyorsun: ");
					scanf(" %c", &choice);
					if (choice != '‡' && choice != '€' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '˜' && choice != 'z' && choice != 'Z')
						printf("Geçersiz, ");
				} while (choice != '‡' && choice != '€' && choice != 'E' && choice != 'e' && choice != 'p' && choice != 'P' && choice != 'M' && choice != 'm' && choice != 'i' && choice != '˜' && choice != 'z' && choice != 'Z');
			}
		}
	}
	printf("\n\n");
	displaytree(name);
}

void townmenu(double power[], char name[], double gold[],double enemy[])
{
	char choice = 'A';
	while (choice != '‡' && choice != '€') // it mans ç.
	{
		//display the statistics of character 
		townstat(power);

		//display and get choice
		{
			printf("- A - Arena\n");
			printf("- Y - Yemekhane\n");
			printf("- D - Dükkan\n");
			printf("- S - Spor\n");
			printf("- G - Görev\n");
			printf("- C - $ CASINO $\n");
			printf("- K - Kaydet\n");
			printf("- Ç - Çýkýþ\n");
			printf("- i - Bilgi\n");
			do {
				printf("Seçimini gir: ");
				scanf(" %c", &choice);
				if (choice != 'A' && choice != 'a' && choice != 'y' && choice != 'Y' && choice != 'd' && choice != 'D' && choice != 's' && choice != 'S' && choice != 'G' && choice != 'g' && choice != 'c' && choice != 'C' && choice != 'K' && choice != 'k' && choice != '‡' && choice != '€' && choice != 'i' && choice != '˜')
					printf("Geçersiz seçim, ");
			} while (choice != 'A' && choice != 'a' && choice != 'y' && choice != 'Y' && choice != 'd' && choice != 'D' && choice != 's' && choice != 'S' && choice != 'G' && choice != 'g' && choice != 'c' && choice != 'C' && choice != 'K' && choice != 'k' && choice != '‡' && choice != '€' && choice != 'i' && choice != '˜');
		}

		if (choice == 'i' || choice == '˜')
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