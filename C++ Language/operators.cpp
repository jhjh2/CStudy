#define HUNGRY 0x1 // 16진수, 1
#define THIRSTY 0x2 // 2
#define TIRED 0x4 // 4
#define FIRE 0x8 // 8

#define COLD 0x10 // 16
#define AAA 0x20 // 32
#define BBB 0x40 // 64
#define CCC 0x80 // 128

#define DDD 0x100 // 256
#define EEE 0x200 // 512
#define FFF 0x400 // 1024
#define GGG 0x800 // 2048
// 1. 가독성
// 2. 유지보수 편의성

int main()
{
	// 연산자
	// 대입 연산자
	// =
	
	// 산술 연산자
	// +, -, *, /, %(모듈러스, 나머지 연산자, 피연산자가 모두 정수인 경우에만 사용 가능)
	int data = 10 + 10; // 20
	//data = data + 20;
	data += 20; // 40

	data = 10 % 3; // 1
	//data = 10. % 3.; // 오류 발생! 피연산자 중 하나라도 실수인 경우 나머지 연산자 사용 불가

	//data = 10. / 3.; // data 변수는 int 정수형으로 실수값을 저장 시 데이터 손실이 발생할 수 있다
	data = (int)(10. / 3.); // 형변환을 명시함으로써 의도한 것임을 표현

	// 실수를 상수로 적을 경우 소수점 뒤에 f를 붙이면 float 자료형으로, f를 붙이지 않으면 double 자료형으로 간주한다.
	// 0.1 == double(8 Byte), 0.1f == float(4 Byte)

	// 증감 연산자
	// ++, --
	// 한 단계 증가 또는 감소한다
	data = 0;
	data++;
	data--;

	++data; // 전위
	data++; // 후위

	// 후위 연산자로 사용하는 경우 연산자 우선순위가 가장 나중으로 밀린다
	int a = 10;
	data = a++; // data == 10, a == 11
	data = ++a; // a == 12, data == 12

	// 논리 연산자
	// !(역), &&(and), ||(or)
	// 결과 : 참(true), 거짓(false)
	// 참   : 0이 아닌 값, 주로 1
	// 거짓 : 0
	int truefalse = true; // 1
	truefalse = false; // 0

	bool isTrue = 100; // 1, true
	isTrue = true; // 1, true
	isTrue = false; // 0, false
	isTrue = 0; // 0, false

	isTrue = true;
	isTrue = !isTrue; // 0, false

	int iTrue = 100;
	iTrue = !iTrue; // 0

	iTrue = 0;
	iTrue = !iTrue; // 1

	iTrue = 100 && 200; // 1
	iTrue = 0 && 200; // 0

	iTrue = 0 || 200; // 1
	iTrue = 0 || 0; // 0

	// 비교 연산자
	// ==, !=, <, >, <=, >=
	// 결과 : 참, 거짓

	// 구문
	// if, else
	data = 0;
	if (100 && 200)
	{
		data = 100;
	}

	if (data == 100)
	{
		// if가 참인 경우 수행
	}
	else
	{
		// if가 거짓인 경우 수행
	}

	if (data == 100)
	{
		// if가 참인 경우 수행
	}
	else if (data == 200)
	{
		// else if가 참인 경우 수행
	}
	else
	{
		// 해당하는 조건이 없는 경우 수행
	}

	if (data == 100)
	{
		// if가 참인 경우 수행
	}
	else if (data == 200)
	{
		// else if가 참인 경우 수행
	}
	// 해당하는 조건이 없는 경우 아무것도 수행하지 않음
	
	// switch case
	int iTest = 10;
	switch (iTest)
	{
	case 10:
		// 수행할 구문 1
		break;
	case 20:
		// 수행할 구문 2
		break; 
	default:
		// 수행할 구문 3
		break;
	}
	
	if (iTest == 10)
	{
		// 수행할 구문 1
	}
	else if (iTest == 20)
	{
		// 수행할 구문 2
	}
	else
	{
		// 수행할 구문 3
	}

	switch (iTest)
	{
	case 10:
	case 20:
	case 30:
		// 수행할 구문 1
		break;
	default:
		// 수행할 구문 2
		break;
	}

	if (iTest == 10 || iTest == 20 || iTest == 30)
	{
		// 수행할 구문 1
	}
	else
	{
		// 수행할 구문 2
	}

	//case 10:과 case 20:의 구문을 수행하고 종료

	// 삼항 연산자
	// ? :
	iTest == 20 ? iTest = 100 : iTest = 200;

	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}

	// 비트 연산자
	// 쉬프트 <<, >>
	unsigned char byte = 1; // [ 0 0 0 0 0 0 0 1 ] == 1
	//byte = byte << 1; // [ 0 0 0 0 0 0 1 0 ] == 2 (1 * 2^1)
	byte <<= 2; // [ 0 0 0 0 0 1 0 0 ] == 4 (1 * 2^2)

	byte >>= 1; // [ 0 0 0 0 0 0 1 0 ] == 2 (4 / 2^1)

	byte = 13; // [ 0 0 0 0 1 1 0 1 ] == 13
	byte >>= 1; // [ 0 0 0 0 0 1 1 0 ] == 6 (13 / 2^1)

	// byte <<= n; 2^n 배수
	// byte >>= n; 2^n 으로 나눈 몫

	// 비트 곱(&), 합(|), xor(^), 반전(~)
	// 비트 단위로 연산을 진행
	// & : 둘 다 1인 경우 1
	// | : 둘 중 하나라도 1인 경우 1
	// ^ 같으면 0, 다르면 1
	// ~ 1은 0으로, 0은 1로

	// 특정 자리 비트 삽입
	unsigned int iStatus = 0; // [ 0 0 0 0 0 0 0 0 ]
	iStatus |= HUNGRY; //        [ 0 0 0 0 0 0 0 1 ] == HUNGRY
	//                           [ 0 0 0 0 0 0 0 1 ]
	iStatus |= THIRSTY; //       [ 0 0 0 0 0 0 1 0 ] == THIRSTY
	//                           [ 0 0 0 0 0 0 1 1 ]
	iStatus |= TIRED; //         [ 0 0 0 0 0 1 0 0 ] == TIRED
	//                           [ 0 0 0 0 0 1 1 1 ]

	// 특정 자리 비트 확인      [ 0 0 0 0 0 1 1 1 ]
	if (iStatus & THIRSTY) // [ 0 0 0 0 0 0 1 0 ] == THIRSTY
	{                      // [ 0 0 0 0 0 0 1 0 ] == 0이 아닌 수 -> true

	}

	// 특정 자리 비트 제거                          [ 0 0 0 0 0 1 1 1 ]
	iStatus &= ~TIRED; // ~[ 0 0 0 0 0 1 0 0 ] -> [ 1 1 1 1 1 0 1 1 ]
	//                                            [ 0 0 0 0 0 0 1 1 ]

	return 0;
}