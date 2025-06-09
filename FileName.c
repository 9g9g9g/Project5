#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

//�������?*��г�����-�̵�& �ൿ?��׸���?��ȣ�ۿ�װ��?*CP ����?*��������

void drawRoom(int);
int rollDice(void);

void drawRoom(int catpos) {
	printf("###############\n");
	printf("#H           B#\n");
	printf("#");

	for (int i = 1; i <= 13; i++) {
		if (i == catpos) {
			printf("C"); // ����� ��ġ ���
		}
		else {
			printf(" "); // �� ���� ���
		}
	}

	printf("#\n");
	printf("###############\n\n");
}//�� �׸���

int rollDice() {
	int dice; 
	dice = rand() % 6 + 1;
	printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
	printf("%d�� ���Խ��ϴ�!\n", dice);
	return dice;
}//�ֻ��� ������



int main(void)
{

	int soup_quantity = 0, intimacy_level = 2, pat, dice, catpos = 1;//soup_quantity:������ ����, intimacy_level:������� ����, pat:���ٵ�� 0 or 1, dice:�ֻ��� ��, catpos:����� ��ġ
	int CP = 0, cat_mood = 3; //CP:���� �ڿ�, cat_mood:����� ���
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
		printf("CP: %d ����Ʈ\n", CP);
		printf("%s ���(0~3): %d\n  ", cat, cat_mood);
		switch (cat_mood) {
		case 0:
			printf("����� �ſ� ���޴ϴ�.\n");
		case 1:
			printf("�ɽ��� �մϴ�\n");
		case 2: 
			printf("�Ļ��� �����ϴ�.\n");
		case 3:
			printf("������ �θ��ϴ�.\n");
		}

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

		printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", intimacy_level, 6 - intimacy_level);
		dice = rollDice();
		if (dice < 6 - intimacy_level) {
			printf("%s�� ����� �������ϴ�.: %d->", cat, cat_mood);
			if (cat_mood != 0) {
				cat_mood -= 1;
				printf("%d\n", cat_mood);
			}
			else {
				printf("%d\n", cat_mood);
			}
		}
		//��� ������
		Sleep(500);

		switch (cat_mood) {
		case 0:
			printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.", cat);
			if (catpos > 1) {
				catpos--;
			}
		case 1:
			printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.", cat);
		case 2:
			printf("%s��(��) ��� ���� �Ļ��� ���� �ֽ��ϴ�.", cat);
		case 3:
			printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.", cat);
			if (catpos < 4) {
				catpos++;
			}
		}
		//����� �̵�

		
		//����� �ൿ 

		Sleep(500);

		drawRoom(catpos);
		// �� �׸���

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
			printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			dice = rollDice();
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
			printf("%s�� ���� �ܾ��־����ϴ�.\n2/6�� Ȯ���� ģ�е��� �������ϴ�.\n", cat);
			dice = rollDice();
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

		//CP ����

		//���� ����

		Sleep(2500);
		system("cls");//����� ���º��� �ٽ�
	}
	return 0;
}
