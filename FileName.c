#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


int main(void)
{

	int soup = 0, com = 2, a, dice, catpos = 1, before = 1, b;//soup:������ ����, com:������� ����, a:0 or 1, dice:�ֻ��� �� catpos:����� ��ġ, before:����� �� ��ġ, ���� ����
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
		printf("������� ���� ����: %d��\n", soup);
		printf("������� ����(0~4): %d\n  ", com);
		switch (com) {
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

		printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", cat, 6 - com);
		dice = rand() % 6 + 1;
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		printf("%d�� ���Խ��ϴ�!\n", dice);
		if (dice >= 6 - com) {
			printf("���� ������ �̵��մϴ�.\n\n");
			if (catpos != 4) {
				catpos++;
			}
		}
		else if (dice < 6 - com) {
			printf("�� ������ �̵��մϴ�.\n\n");
			if (catpos > 1) {
				catpos--;
			}
		}
		//����� �̵�
		if (catpos == 4) {
			b = rand() % 3 + 1;
			switch (b) {
			case 1:printf("%s��(��) ���� ������ ��������ϴ�!\n", cat); break;
			case 2:printf("%s��(��) ����� ������ ��������ϴ�!\n", cat); break;
			case 3:printf("%s��(��) ����ݸ� ������ ��������ϴ�!\n", cat); break;
			}
			soup++;
			printf("������� ���� ����: %d��\n\n", soup);
		}
		else if (catpos == 1) {
			printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n\n", cat);
		}
		//����� �ൿ 
		Sleep(500);

		printf("######\n#H  B#\n");
		if (catpos > before) {
			switch (catpos) {
			case 2: printf("#.C  #\n"); before++; break;
			case 3: printf("# .C #\n"); before++; break;
			case 4: printf("#  .C#\n"); before++; break;
			}
		}
		else if (catpos < before) {
			switch (catpos) {
			case 1: printf("#C.  #\n"); before--; break;
			case 2: printf("# C. #\n"); before--; break;
			case 3: printf("#  C.#\n"); before--; break;
			}
		}
		else if (catpos == before) {
			switch (catpos) {
			case 1: printf("#C   #\n"); break;
			case 4: printf("#   C#\n"); break;
			}
		}


		printf("######\n\n");
		// �������
		Sleep(500);

		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0. �ƹ��͵� ���� ����  1. �ܾ� �ֱ�\n");
		while (1) {
			printf(">> ");
			scanf_s("%d", &a);
			if (a == 0 || a == 1) {
				break;
			}
		}
		switch (a) {
		case 0:
			printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n4/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			switch (dice) {
			case 1:
			case 2:
			case 3:
			case 4:
				if (com > 0) {
					com -= 1;
				}
				printf("ģ�е��� �������ϴ�.\n���� ģ�е�: %d\n", com);
				break;
			case 5:
			case 6:
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n���� ģ�е�: %d\n", com);
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
				printf("ģ�е��� �״���Դϴ�.\n���� ģ�е�: %d\n", com);
				break;
			case 5:
			case 6:
				if (com < 4) {
					com += 1;
				}
				printf("ģ�е��� �������ϴ�.\n���� ģ�е�: %d\n", com);
			}
		}
		//��ȣ�ۿ� 1 ������

		Sleep(2500);
		system("cls");//����� ���º��� �ٽ�
	}
	return 0;
}


