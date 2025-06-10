#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

char cat[100];//고양이 이름

//상태출력–*기분나빠짐-이동& 행동–방그리기–상호작용및결과–*CP 생산–*상점구매

void drawRoom(int, int);
int rollDice(void);
int moodplus1(int);
int moodplus2(int);
int moodminus1(int);
int broke(int, int, int, int);
int move(int, int, int, int);



void drawRoom(int catpos, int before) {
	printf("\n###############\n");
	printf("#H           B#\n");
	printf("#");

	for (int i = 1; i <= 13; i++) {
		if (i == catpos) {
			printf("C"); // 고양이 위치 출력
		}
		else if (i == before) {
			printf(".");
		}
		else {
			printf(" "); // 빈 공간 출력
		}
	}

	printf("#\n");
	printf("###############\n\n");
}//방 그리기

int rollDice() {
	int dice; 
	dice = rand() % 6 + 1;
	printf("주사위를 굴립니다. 또르륵...\n");
	printf("%d가 나왔습니다!\n", dice);
	return dice;
}//주사위 굴리기

int moodplus1(int cat_mood) {
	
	printf("%s의 기분이 조금 좋아졌습니다:%d->", cat, cat_mood);
	if (cat_mood < 3) {
		cat_mood++;
	}
	printf("%d\n", cat_mood);
	return cat_mood;
}//기분 +1


int moodplus2(int cat_mood) {

	printf("%s의 기분이 제법 좋아졌습니다:%d->", cat, cat_mood);
	if (cat_mood < 2) {
		cat_mood += 2;
	}
	else if (cat_mood = 2) {
		cat_mood++;
	}
	printf("%d\n", cat_mood);
	return cat_mood;
}//기분 +2

int moodminus1(int cat_mood) {
	printf("%s의 기분이 나빠집니다.: %d->", cat, cat_mood);
	if (cat_mood != 0) {
		cat_mood -= 1;	
	}
	printf("%d\n", cat_mood);
	return cat_mood;
}//기분 -1

int broke(int rat, int razer, int scratcherpos, int cat_towerpos) {
	printf("고양이가 미쳐 날뜁니다.\n일정 확률로 고양이가 물건을 부숩니다.");
	Sleep(100);
	int object;
	if (rand() % 100 < 40) {
		object = rand() % 4 + 1;
		switch (object) {
		case 1:
			if (rat == 1) {
				printf("고양이가 장난감 쥐를 높은 곳에서 떨어뜨립니다.."); break;
			}
			else {
				object = 0;
			}
		case 2:
			if (razer == 1) {
				printf("고양이가 레이저 포인터를 깨뭅니다.."); break;
			}
			else {
				object = 0;
			}
		case 3:
			if (scratcherpos > 0) {
				printf("고양이가 스크래처를 마구 긁어 다 닳았습니다."); break;
			}
			else {
				object = 0;
			}
		case 4:
			if (cat_towerpos > 0) {
				printf("고양이가 캣타워를 무너뜨립니다."); break;
			}object = 0;
		}
	}
	else {
		object = 0;
	}
	return object;
}//파괴신 고양이

int move(int catpos, int scratcherpos, int cat_towerpos, int cat_mood) {
	int a = catpos - scratcherpos, b = catpos - cat_towerpos;
	int A = a, B = b;
	if (a < 0) {
		A = -a;
	}
	if (b < 0) {
		B = -b;
	}
	if (scratcherpos > 0 && cat_towerpos > 0) {
		if (A < B) {
			if (a > 0) {
				catpos--;
				printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.");
			}
			else if (a < 0) {
				catpos++;
				printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.");
			}
		}
		else {
			if (b > 0) {
				catpos--;
				printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.");
			}
			else if (b < 0) {
				catpos++;
				printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.");
			}
		}
	}
	else if (scratcherpos > 0) {
		if (a > 0) {
			catpos--;
			printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.");
		}
		else if (a < 0) {
			catpos++;
			printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.");
		}
	}
	else if (cat_towerpos > 0) {
		if (b > 0) {
			catpos--;
			printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.");
		}
		else if (b < 0) {
			catpos++;
			printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.");
		}
	}
	else {
		printf("놀 거리가 없어서 ");
		moodminus1(cat_mood);
	}
	return catpos;
}








int main(void)
{

	int soup_quantity = 0, intimacy_level = 2, user_choice, dice, catpos = 1, before=0;//soup_quantity:수프의 개수, intimacy_level:집사와의 관계, user_choice:상호작용, dice:주사위 눈, catpos:고양이 위치, before: 고양이 전 위치
	int CP = 0, cat_mood = 3, scratcherpos = 0, cat_towerpos = 0; //CP:상점 자원, cat_mood:고양이 기분, scratcherpos:스크래처 유무와 위치, cat_towerpos:캣타워 유무와 위치
	int rat = 0, razer = 0, store=0;//rat:장남감 쥐 유무, rezer:레이저 포인트 유무, store:상점에서 고른 숫자
	int count = 1;
	srand((unsigned int)time(NULL));
	printf("****야옹이와 수프****\n\n");
	printf("      /\\_/\\\n /\\  / ° ° \\\n//\\\\ \\~(*)~/\n`  \\/   ^ /\n   | \\|| ||\n   \\ '|| ||\n    \\)()-())\n\n");
	printf("야옹이의 이름을 지어 주세요: ");
	gets_s(cat, sizeof(cat));
	printf("야옹이의 이름은 %s입니다.\n", cat);
	Sleep(1000);
	system("cls");//오프닝

	Sleep(500);

	while (1) {
		printf("==================== 현재상태 ====================\n");
		printf("현재까지 만든 수프: %d개\n", soup_quantity);
		printf("CP: %d 포인트\n", CP);
		printf("%s 기분(0~3): %d\n  ", cat, cat_mood);
		switch (cat_mood) {
		case 0:
			printf("기분이 매우 나쁩니다.\n"); break;
		case 1:
			printf("심심해 합니다\n"); break;
		case 2: 
			printf("식빵을 굽습니다.\n"); break;
		case 3:
			printf("골골송을 부릅니다.\n"); break;
		}

		printf("집사와의 관계(0~4): %d\n  ", intimacy_level);
		switch (intimacy_level) {
		case 0:
			printf("곁에 오는 것조차 싫어합니다.\n"); break;
		case 1:
			printf("간식 자판기 취급입니다.\n"); break;
		case 2:
			printf("그럭저럭 쓸 만한 집사입니다.\n"); break;
		case 3:
			printf("훌륭한 집사로 인정 받고 있습니다.\n"); break;
		case 4:
			printf("집사 껌딱지입니다.\n"); break;
		}
		printf("==================================================\n\n");//상태

		Sleep(500);

		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", intimacy_level, 6 - intimacy_level);
		dice = rollDice();
		if (dice < 6 - intimacy_level) {
			moodminus1(cat_mood);
		}
		//기분 나빠짐
		Sleep(500);

		switch (cat_mood) {
		case 0:
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.", cat);
			if (catpos > 1) {
				catpos--;
			}break;
		case 1:
			move(catpos, scratcherpos, cat_towerpos, cat_mood);

		case 2:
			printf("%s은(는) 기분 좋게 식빵을 굽고 있습니다.", cat); break;
		case 3:
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.", cat);
			if (catpos < 13) {
				catpos++;
			}break;
		}
		//고양이 이동

		if (before == 1 && catpos == 1) {
			moodplus1(cat_mood);
		}
		else if (catpos == 13) {
			switch (rand() % 3) {
			case 0:
				soup_quantity++;
				printf("%s이(가) 감자 수프를 만들었습니다!\n현재까지 만든 수프: %d\n", cat, soup_quantity); break;
			case 1:
				soup_quantity++;
				printf("%s이(가) 양송이 수프를 만들었습니다!\n현재까지 만든 수프: %d", cat, soup_quantity); break;
			case 2:
				soup_quantity++;
				printf("%s이(가) 브로콜리 수프를 만들었습니다.\n현재까지 만든 수프: %d\n", cat, soup_quantity); break;
			}
		}
		else if (catpos == scratcherpos) {
			printf("%s은(는) 스크래처를 긁고 놀았습니다.\n", cat);
			moodplus1(cat_mood);
		}
		else if (catpos == cat_towerpos) {
			printf("%s은(는) 캣타워를 뛰어다닙니다.\n", cat);
			moodplus2(cat_mood);
		}
		//고양이 행동 

		Sleep(500);

		drawRoom(catpos, before);
		// 방 그리기

		Sleep(500);

		if (rat == 0 && razer == 0) {
			printf("어떤 상호작용을 하시겠습니까?\n  0. 아무것도 하지 않음\n  1. 긁어 주기\n");
		}
		else if (rat == 1 && razer == 1) {
			printf("어떤 상호작용을 하시겠습니까?\n  0. 아무것도 하지 않음\n  1. 긁어 주기\n  2. 장난감 쥐로 놀아주기\n  3. 레이저 포인터로 놀아주기 \n");
		}
		else if (rat == 1) {
			printf("어떤 상호작용을 하시겠습니까?\n  0. 아무것도 하지 않음\n  1. 긁어 주기\n  2. 장난감 쥐로 놀아주기\n");
		}
		else if(razer == 1) {
			printf("어떤 상호작용을 하시겠습니까?\n  0. 아무것도 하지 않음\n  1. 긁어 주기\n  2. 레이저 포인터로 놀아주기\n");
		}
		
		while (1) {
			printf(">> ");
			scanf_s("%d", &user_choice);
			if (rat == 0 && razer == 0) {
				if (user_choice >= 0 && user_choice <= 1) {
					break;
				}
			}
			else if(rat == 1 && razer ==1) {
				if (user_choice >= 0 && user_choice <= 3) {
					break;
				}
			}
		else if (razer == 1) {
			if (user_choice >= 0 && user_choice <= 2) {
				break;
			}
		}
		else if (rat == 1) {
			if (user_choice >= 0 && user_choice <= 2) {
				break;
			}
			}
		}
		switch (user_choice) {
		case 0:
			moodminus1(cat_mood);
			printf("아무것도 하지 않았습니다.\n4/6의 확률로 친밀도가 떨어집니다.\n");
			dice = rollDice();
			switch (dice) {
			case 1:
			case 2:
			case 3:
			case 4:
				if (intimacy_level > 0) {
					intimacy_level -= 1;
				}
				printf("친밀도가 떨어집니다.\n현재 친밀도: %d\n", intimacy_level);
				break;
			case 5:
			case 6:
				printf("다행히 친밀도가 떨어지지 않았습니다.\n현재 친밀도: %d\n", intimacy_level);
				break;
			}
			break;
			//상호작용 0 누를때
		case 1:
			printf("%s의 기분이 그대로 입니다: %d", cat, cat_mood);
			printf("%s의 턱을 긁어주었습니다.\n2/6의 확률로 친밀도가 높아집니다.\n", cat);
			dice = rollDice();
			switch (dice) {
			case 1:
			case 2:
			case 3:
			case 4:
				printf("친밀도는 그대로입니다.\n현재 친밀도: %d\n", intimacy_level);
				break;
			case 5:
			case 6:
				if (intimacy_level < 4) {
					intimacy_level += 1;
				}
				printf("친밀도가 높아집니다.\n현재 친밀도: %d\n", intimacy_level);
			}
		case 2:
			if (rat == 0 && razer == 0) {
			}
			else if (rat == 1) {
				printf("장난감 쥐로 %s와 놀아 주었습니다.", cat);
				moodplus1(cat_mood);
			}
			else if (razer == 1) {
				printf("레이저 포이터로 %s와 신나게 놀아 주었습니다,", cat);
				moodplus2(cat_mood);
			}break;
		case 3:
			if (rat == 1 && razer == 1) {
				printf("레이저 포이터로 %s와 신나게 놀아 주었습니다,", cat);
				moodplus2(cat_mood);
			}break;
		}
		//상호작용
		Sleep(500);

		if (cat_mood - 1 + intimacy_level > 0) {
			CP += cat_mood - 1 + intimacy_level;
		}
		printf("%s의 기분(0~3): %d\n집사와의 친밀도(0~4): %d\n%s의 기분과 친밀도에 따라서 CP가 ", cat, cat_mood, intimacy_level, cat);
		if (cat_mood - 1 + intimacy_level >= 0) {
			printf("%d", cat_mood - 1 + intimacy_level);
		}
		else {
			printf("%d", 0);
		}
		printf("포인트 생산되었습니다.");
		//CP 생산


		printf("상점에서 물건을 구매할 수 있습니다.\n어떤 물건을 구매할까요?\n  0. 아무것도 사지 않는다.\n");
		printf("  1. 장난감 쥐: 1CP "); if (rat == 1)printf("(품절)");
		printf("\n  2. 레이저 포인터: 2CP "); if (razer == 1)printf("(품절)");
		printf("\n  3. 스크래처: 3CP "); if (scratcherpos != 0)printf("(품절)");
		printf("\n  4. 캣타워: 6CP "); if (cat_towerpos != 0)printf("(품절)");
		printf("\n");
		while (1) {
			scanf_s("%d", &store);
			if (store >= 0 && store <= 4) {
				switch (store) {
				case 0:
					printf("아무것도 사지 않는다.\n"); break;
				case 1:
					if (rat == 0 && CP >= 1) {
						rat = 1;
						printf("장난감 쥐를 구매했습니다, 보유 CP %d 포인트\n", CP);
					}
					else if (rat == 0 && CP < 1) {
						printf("CP가 부족합니다.\n");
					}
					else if (rat == 1) {
						printf("장난감 쥐를 이미 구매했습니다.");
					}break;
				case 2:
					if (razer == 0 && CP >= 2) {
						razer = 1;
						printf("레이저 포인터를 구매했습니다, 보유 CP %d 포인트\n", CP);
					}
					else if (razer == 0 && CP < 2) {
						printf("CP가 부족합니다.\n");
					}
					else if (razer == 1) {
						printf("레이저 포인터를 이미 구매했습니다.");
					}break;
				case 3:
					if (scratcherpos == 0 && CP >= 4) {
						while (1) {
							scratcherpos = rand() % 11 + 2;
							if (scratcherpos != cat_towerpos) {
								break;
							}
						}
						printf("스크래처를 구매했습니다, 보유 CP %d 포인트\n", CP);
					}
					else if (scratcherpos == 0 && CP < 4) {
						printf("CP가 부족합니다.\n");
					}
					else if (scratcherpos!=0) {
						printf("스크래처를 이미 구매했습니다.");
					}break;
				case 4:
					if (cat_towerpos == 0 && CP >= 6) {
						while (1) {
							cat_towerpos = rand() % 11 + 2;
							if (cat_towerpos != scratcherpos) {
								break;
							}
						}
						printf("캣타워를 구매했습니다, 보유 CP %d 포인트\n", CP);
					}
					else if (cat_towerpos == 0 && CP < 4) {
						printf("CP가 부족합니다.\n");
					}
					else if (cat_towerpos != 0) {
						printf("캣타워를 이미 구매했습니다.");
					}break;
				}
				break;
			}
		}
		//상점 구매

		if (count >= 3) {
			switch (broke(rat, razer, scratcherpos, cat_towerpos)) {
			case 0:
				printf("다행히 어떤 물건도 부서지지 않았습니다."); break;
			case 1:
				rat = 0; break;
			case 2:
				razer = 0; break;
			case 3:
				scratcherpos = 0; break;
			case 4:
				cat_towerpos = 0; break;
			}
			count = 0;
		}
		count++;
		Sleep(500);
		//돌발 퀘스트


		Sleep(2500);
		system("cls");//지우고 상태부터 다시
	}
	return 0;
}
