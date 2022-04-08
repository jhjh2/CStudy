/* 자료, 자료구조, 알고리즘 */

// 자료 : banana, apple, pineapple
// 자료구조 : 자료들을 규칙이나 사용하기 쉬운 형태로 정리해서 보관하는 것
// ex) abc 순서로 정렬 -> apple, banana, pineapple
// 알고리즘 : 자료구조에 따라 정리된 데이터들에 접근하여 일을 처리하는 방법
//         : 컴퓨터로 문제를 풀기 위한 단계적 절차


/* 알고리즘의 성능 분석 */

// 알고리즘 A1과 A2가 있을 때
// 어느 것이 더 좋은가? 시간 / 공간
// 시간과 공간을 덜 사용하는 것이 좋은 알고리즘이다

// data -(입력)-> 알고리즘 -> 결과
// data의 갯수 n 입력 시
// A1 : n -> n^2 시간
// A2 : n -> 2^n 시간
// A1 >> A2


/* big-o notation*/

// A1 : n^2 => O{n^2}
// A2 : 2^n => O{2^n}

// A3 : 2 * n^2 => O{n^2}
// A4 : 3 * n^2 => O{n^2}
// A5 : n^2 + n + 1 => O{n^2}
// n이 충분히 커지면 2 또는 3을 곱하는 것이 유의미한 차이를 보이지 않기 때문에
// big-o notation에서는 단순화하여 표기한다

// O{1} <- n의 갯수에 영향을 받지 않는 꿈의 알고리즘
// O{n}
// O{n * logn}
// O{n^2}
// O{2^n}
// O{n!} <- n의 값이 커짐에 따라 커지므로 성능이 제일 나쁜 알고리즘


/* 입력 갯수에 다른 출력에 관한 식이 없는 경우의 성능 측정 */

#include <stdio.h>
#include <time.h> // clock() <-- 호출할 때의 clock count
                  // S <-- clock() 100, E <-- clock() 2000
                  // 2000 - 100 = 1900

// 수행시간 측정

int main(void)
{
    clock_t startTime, endTime; // int, char 같이 clock_t 도 데이터 타입의 한 종류
    int i;
    double k = 0.0;

    startTime = clock();

    // work
    for (i = 0; i < 100000; i++)
    {
        k = (k * k) / (double)i;
    }

    endTime = clock();

    printf("%d \n", endTime - startTime);
    // duration --> clock count

    printf("%d \n", (endTime - startTime) / CLOCKS_PER_SEC);
    // duration / CLOCKS_PER_SEC --> 초 단위
}


/* Abstract Data Type */

// 기본 데이터 타입 : int, char, ...
// 새로운 데이터 타입을 만드는 struct

// 자료구조에서 배우는 데이터 타입 : Abstract Data Type
// Abstract Data Type = data type + operation
// 어떤 데이터를 저장할 수 있고, 저장한 데이터로 무엇을 할 수 있는지 정의한 것