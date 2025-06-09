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
			printf("C"); // ����� ��ġ ���
		}
		else {
			printf(" "); // �� ���� ���
		}
	}

	printf("#\n");
	printf("######\n\n");
}





int main(void)
{

	int soup_quantity = 0, intimacy_level = 2, pat, dice, catpos = 1;//soup_quantity:������ ����, intimacy_level:������� ����, pat:0 or 1, dice:�ֻ��� �� catpos:����� ��ġ
	char cat[100];//����� �̸�
	srand((unsigned int)time(NULL));
	printf("****�߿��̿� ����****\n\n");
	printf("      /\\_/\\\n /\\  / �� �� \\\n//\\\\ \\~(*)~/\n`  \\/   ^ /\n   | \\|| ||\n   \\ '|| ||\n    \\)()-())\n\n");
	printf("�߿����� �̸��� ���� �ּ���: ");
	gets_s(cat, sizeof(cat));
	printf("�߿����� �̸��� %s�Դϴ�.\n", cat);
	Sleep(1000);
	system("cls");//������

	Sleep(500);

	while (1) {
		printf("==================== ������� ====================\n");
		printf("������� ���� ����: %d��\n", soup_quantity);
		printf("������� ����(0~4): %d\n  ", intimacy_level);
		switch (intimacy_level) {
		case 0:
			printf("�翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
		case 1:
			printf("���� ���Ǳ� ����Դϴ�.\n"); break;
		case 2:
			printf("�׷����� �� ���� �����Դϴ�.\n"); break;
		case 3:
			printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
		case 4:
			printf("���� �������Դϴ�.\n"); break;
		}
		printf("==================================================\n\n");//����

		Sleep(500);

		printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", cat, 6 - intimacy_level);
		dice = rand() % 6 + 1;
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		printf("%d�� ���Խ��ϴ�!\n", dice);
		if (dice >= 6 - intimacy_level) {
			printf("���� ������ �̵��մϴ�.\n\n");
			if (catpos != 4) {
				catpos++;
			}
		}
		else if (dice < 6 - intimacy_level) {
			printf("�� ������ �̵��մϴ�.\n\n");
			if (catpos > 1) {
				catpos--;
			}
		}
		//����� �̵�

		if (catpos == 4) {
			switch (rand() % 3 + 1) {
			case 1:printf("%s��(��) ���� ������ ��������ϴ�!\n", cat); break;
			case 2:printf("%s��(��) ����� ������ ��������ϴ�!\n", cat); break;
			case 3:printf("%s��(��) ����ݸ� ������ ��������ϴ�!\n", cat); break;
			}
			soup_quantity++;
			printf("������� ���� ����: %d��\n\n", soup_quantity);
		}
		else if (catpos == 1) {
			printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n\n", cat);
		}
		//����� �ൿ 

		Sleep(500);

		drawRoom(catpos);
		// �������

		Sleep(500);

		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0. �ƹ��͵� ���� ����  1. �ܾ� �ֱ�\n");
		while (1) {
			printf(">> ");
			scanf_s("%d", &pat);
			if (pat == 0 || pat == 1) {
				break;
			}
		}
		switch (pat) {
		case 0:
			printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n4/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			switch (dice) {
			case 1:
			case 2:
			case 3:
			case 4:
				if (intimacy_level > 0) {
					intimacy_level -= 1;
				}
				printf("ģ�е��� �������ϴ�.\n���� ģ�е�: %d\n", intimacy_level);
				break;
			case 5:
			case 6:
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n���� ģ�е�: %d\n", intimacy_level);
				break;
			}
			break;
			//��ȣ�ۿ� 0 ������
		case 1:
			printf("%s�� ���� �ܾ��־����ϴ�.\n2/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n", cat);
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", dice);
			switch (dice) {
			case 1:
			case 2:
			case 3:
			case 4:
				printf("ģ�е��� �״���Դϴ�.\n���� ģ�е�: %d\n", intimacy_level);
				break;
			case 5:
			case 6:
				if (intimacy_level < 4) {
					intimacy_level += 1;
				}
				printf("ģ�е��� �������ϴ�.\n���� ģ�е�: %d\n", intimacy_level);
			}
		}
		//��ȣ�ۿ� 1 ������

		Sleep(2500);
		system("cls");//����� ���º��� �ٽ�
	}
	return 0;
}
