#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{	
	// if (조건) { } else { }
	int age = 15;
	// 학생 / 일반인으로 구분 (일반인 : 20세 이상)
	if (age >= 20)
	{
		printf("adult.\n");
	}
	else
	{
		printf("student.\n");
	}

	// if (조건) { } else if { } else { }
	age = 8;
	// 초등학생(8 - 13) / 중학생 (14 - 16) / 고등학생 (17 - 19)
	if (age >= 8 && age <= 13)
	{
		printf("elementary school student.\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("middle school student.\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("high school student.\n");
	}
	else
	{
		printf("not a student.\n");
	}


	// break / continue
	// 1번부터 30번 까지 있는 반에서 1 - 5번 까지 조별 발표를 준비합니다
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("나머지 학생은 집에 가세요\n");
			break; // for문을 탈출한다
		}
		printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
	}

	// 1번부터 30번 까지 있는 반에서 7번 학생은 결석입니다
	// 7번을 제외하고 6번부터 10번까지 조별 발표를 준비하세요
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d 번 학생은 결석입니다\n", i);
				continue; // 이후의 문장을 실행하지 않고 다음 반복으로 넘어간다
			}
			printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
		}
		
	}

	// &&
	int a = 10;
	int b = 11;
	int c = 13;
	int d = 13;
	if (a == b && c == d)
	{
		printf("a와 b가 같고, c와 d도 같습니다.\n");
	}
	else
	{
		printf("값이 서로 다릅니다.\n");
	}

	// ||
	if (a == b || c == d)
	{
		printf("a와 b가 같거나, c와 d가 같습니다.\n");
	}
	else
	{
		printf("값이 서로 다릅니다.\n");
	}

	// 가위 0, 바위 1, 보 2
	srand(time(NULL));
	int i = rand() % 3; // 0 - 2 반환
	if (i == 0)
	{
		printf("가위\n");
	}
	else if (i == 1)
	{
		printf("바위\n");
	}
	else if (i == 2)
	{
		printf("보\n");
	}
	else
	{
		printf("모르겠어요.\n");
	}

	switch (i)
	{
	case 0:printf("가위\n"); break;
	case 1:printf("바위\n"); break;
	case 2:printf("보\n"); break;
	default:printf("모르겠어요.\n"); // break; 생략 가능
	}

	age = 25;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("elementary school student.\n"); break;
	case 14:
	case 15:
	case 16:printf("middle school student.\n"); break;
	case 17:
	case 18:
	case 19:printf("high school student.\n"); break;
	default:printf("not a student.\n");
	}

	// Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 - 100 사이의 숫자
	printf("숫자 : %d\n", num);
	int answer = 0; // 정답
	int chance = 5; // 기회
	while (1) // 1 : true, 0 : false
	{
		printf("남은 기회 %d 번\n", chance--);
		printf("숫자를 맞혀보세요 (1 - 100) : ");
		scanf_s("%d", &answer);

		if (answer > num)
		{
			printf("DOWN\n");
		}
		else if (answer < num)
		{
			printf("UP\n");
		}
		else if (answer == num)
		{
			printf("Correct!\n");
			break;
		}
		else
		{
			printf("Unknown error!\n");
		}

		if (chance == 0)
		{
			printf("Sorry, out of chance.\n");
			break;
		}
	}

	return 0;
}