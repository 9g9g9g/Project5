#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void drawRoom(int);

void drawRoom(int catpos) {
	printf("######\n");
	printf("#H  B#\n");
	printf("#");

	for (int i = 1; i <= 4; i++) {
		if (i == catpos) {
			printf("C"); // 고양이 위치 출력
		}
		else {
			printf(" "); // 빈 공간 출력
		}
	}

	printf("#\n");
	printf("######\n\n");
}





int main(void)
{

	int soup_quantity = 0, intimacy_level = 2, pat, dice, catpos = 1;//soup_quantity:수프의 개수, intimacy_level:집사와의 관계, pat:0 or 1, dice:주사위 눈 catpos:고양이 위치
	char cat[100];//고양이 이름
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

		printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", cat, 6 - intimacy_level);
		dice = rand() % 6 + 1;
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d가 나왔습니다!\n", dice);
		if (dice >= 6 - intimacy_level) {
			printf("냄비 쪽으로 이동합니다.\n\n");
			if (catpos != 4) {
				catpos++;
			}
		}
		else if (dice < 6 - intimacy_level) {
			printf("집 쪽으로 이동합니다.\n\n");
			if (catpos > 1) {
				catpos--;
			}
		}
		//고양이 이동

		if (catpos == 4) {
			switch (rand() % 3 + 1) {
			case 1:printf("%s이(가) 감자 수프를 만들었습니다!\n", cat); break;
			case 2:printf("%s이(가) 양송이 수프를 만들었습니다!\n", cat); break;
			case 3:printf("%s이(가) 브로콜리 수프를 만들었습니다!\n", cat); break;
			}
			soup_quantity++;
			printf("현재까지 만든 수프: %d개\n\n", soup_quantity);
		}
		else if (catpos == 1) {
			printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n\n", cat);
		}
		//고양이 행동 

		Sleep(500);

		drawRoom(catpos);
		// 뱡만들기

		Sleep(500);

		printf("어떤 상호작용을 하시겠습니까?   0. 아무것도 하지 않음  1. 긁어 주기\n");
		while (1) {
			printf(">> ");
			scanf_s("%d", &pat);
			if (pat == 0 || pat == 1) {
				break;
			}
		}
		switch (pat) {
		case 0:
			printf("아무것도 하지 않았습니다.\n4/6의 확률로 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
			dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다!\n", dice);
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
			printf("%s의 턱을 긁어주었습니다.\n2/6의 확률로 친밀도가 높아집니다.\n주사위를 굴립니다. 또르륵...\n", cat);
			dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice);
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
		}
		//상호작용 1 누를떄

		Sleep(2500);
		system("cls");//지우고 상태부터 다시
	}
	return 0;
}
