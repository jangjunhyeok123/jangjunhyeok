#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
void wait_seconds(int seconds)/*3초 대기를 위해서 함수wait_seconds 라는 함수를 선언합니다*/  
{
    volatile long long count = 0;/*3초 대기를 위해서 함수wait_seconds 라는 함수를 선언합니다*/ 
    const long long limit = 1000000000LL * seconds;// 적당한 큰 숫자로 카운트 제한 설정 10억이라는 큰 수이므로 정수형 변수는 longlong으로 선언했다. 그리고 이 값을 불변해야하는 값이므로 상수로 이용하기 위해서 함수 const를 사용했습니다.
    
  while (count < limit) {
        count++;  // 단순히 카운트를 증가시킴으로써 시간 지연을 유발합니다.
    }
}

void print_stars(int n)/*별을 출력하기 위한 함수 선언*/ 
{
    for (int i = 0; i < n; i++)/* i가 n보다 작을 때까지 반복합니다*/ 
    {
        putchar('*');  // putchar로 '*' 한 개씩 출력합니다.
    }
    putchar('\n');  // 줄 바꿉니다.
}

int main() {
    char name[100];//입력할 이름을 저장하기 위해서 문자열 크기를 나타냅니다.
    char date[11];  // "yyyy-mm-dd" 형식을 저장하기 위한 문자열 크기를 나타냅니다.
    
    // 사용자로부터 날짜와 이름을 입력 받음
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf_s("%s", date,sizeof(date));//키보드를 통해서 날짜를 입력합니다.
    printf("[당신의 이름을 입력하세요]: ");
    scanf_s("%s", name,sizeof(name));// 키보드를 통해서 이름을 입력합니다.
    
    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기
    wait_seconds(3);  //제가 만든 함수 wait_second를 통해서 3초 대기시킵니다. (실제로는 정확하지 않을 수 있습니다)

    // 화면 지우기 (터미널에 따라 다름)
    system("clear");   // 함수 system을 통해서 화면을 지웁니다. (터미널에 따라 다릅니다.)리눅스/유닉스의 경우 "clear", 윈도우의 경우 "cls"를 사용합니다.

    // 스플래시 화면 출력합니다.
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 정삼각형 출력합니다 (반복문으로 별 출력)
    for (int i = 1; i <= 5; i++) 
    {
        print_stars(i);  // i개 만큼 별을 출력
    }

    // 스플래시 문구 출력
    print_stars(1);
    printf("                         [마그라테아 ver 0.1]                               ");
    print_stars(5);
    
    print_stars(2);
    printf("   풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,            ");
    print_stars(4);
    
    print_stars(3);
    printf("   사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,       ");
    print_stars(3);
    
    print_stars(4);
    printf("    마그라테아에 오신걸 환영합니다.\"                                         ");
    print_stars(2);
    
    print_stars(5);
    printf("                                                                          ");
    print_stars(1);

    // 역삼각형 출력 (반복문으로 별 출력)
    for (int i = 5; i >= 1; i--) {
        print_stars(i);  // i개 만큼 별을 출력
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]: %s\n", name, date);
    printf("================================================================================\n");

    return 0;
}
