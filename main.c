#include <stdio.h>
#include <stdlib.h> // rand() 함수가 있는 거
#include <time.h> // 시간

int main() {
	srand(time(NULL)); // 시드값 생성

	int times = 0; // 횟수
	int num = rand()%1000+1; // 난수 생성해서 저장
	int scannum = 0; // 사용자가 입력한 숫자
        //printf("%d", num); // 디버깅용

	printf("**********스무고개 게임 - Guessing Game**********\n");
	printf("0부터 1000사이의 랜덤한 숫자를 20번 안에 맞추는 게임입니다.\n");
	while (1) {
		printf(">>");
		scanf("%d", &scannum);
		
		//만약 횟수가 20을 넘었다면
		if (times > 20) {
			printf("게임이 종료되었습니다. 숫자는 %d 였습니다.\n", num);
			break;
		}

		// 만약 사용자의 입력값이 1000을 넘었다면
		if (scannum > 1000) {
			printf("0~1000 사이의 숫자를 입력해 주세요.\n");
			times++;
		}
		
		//만약 입력값이 난수보다 크다면
		if (scannum > num && scannum < 1000) {
			printf("DOWN\n");
			times++;
		}

		//만약 입력값이 난수보다 작다면
		if (scannum < num && scannum < 1000) {
			printf("UP\n");
			times++;
		}

		// 숫자를 맞추면
		// 와 나 숫자를 맞췄을 때를 안 넣고 테스트하면서 왜 숫자를 맞췄는데 게임이 안 끝나 이러고 있었네
		if (scannum == num) {
			printf("숫자를 맞췄습니다. 숫자는 %d 였습니다.\n", num);
			break;
		}

		//printf("%d\n", times); //디버깅용

	}
	return 0;
}
