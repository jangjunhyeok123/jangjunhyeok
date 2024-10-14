#include <stdio.h>
#include <stdlib.h>// 필요한 헤더 파일을 포함 시킵니다.

#define NUM_CANDIDATES 6
//후보자의 수를 6으로 정의합니다.
typedef struct {
    char name[50];
    char birthdate[11];
    char gender;
    char email[50];
    char nationality[30];
    float bmi;
    char main_skill[30];
    char sub_skill[30];
    int topik_level;
    char mbti[5];
    char introduction[256];
} Candidate;// 구조체를 정의하여 후보자의 정보를 저장합니다.

void inputCandidate(Candidate* candidate) //후보자의 정보를 입력하는 함수를 정의합니다.
{
    printf("성명: ");
    scanf(" %[^\n]", candidate->name);// 후보자의 이름을 입력받습니다.
    printf("생일(YYYY/MM/DD 형식): ");
    scanf(" %[^\n]", candidate->birthdate);// 후보자의 생일을 입력받습니다.
    printf("성별(여성이면 F 또는 남성이면 M): ");
    scanf(" %c", &candidate->gender);// 후보자의 성별을 입력받습니다.
    printf("메일 주소: ");
    scanf(" %[^\n]", candidate->email);// 후보자의 이메일을 입력받습니다.
    printf("국적: ");
    scanf(" %[^\n]", candidate->nationality);// 후보자의 이메일을 입력받습니다.
    printf("BMI: ");
    scanf("%f", &candidate->bmi);// 후보자의 bmi를 입력받습니다.
    printf("주 스킬: ");
    scanf(" %[^\n]", candidate->main_skill);//후보자의 주 스킬을 입력받습니다.
    printf("보조 스킬: ");
    scanf(" %[^\n]", candidate->sub_skill);// 후보자의 보조 스킬을 입력받습니다.
    printf("한국어 등급(TOPIK): ");
    scanf("%d", &candidate->topik_level);//후보자의 한국어 등급을 입력받습니다.
    printf("MBTI: ");
    scanf(" %[^\n]", candidate->mbti);// 후보자의 mbti를 입력 받습니다.
    printf("소개: ");
    scanf(" %[^\n]", candidate->introduction);// 후보자의 소개를 입력받습니다.
}

void printCandidate(const Candidate* candidate) //후보자의 정보를 형식에 맞춰 출력합니다.
{
    printf("%-10s | %-10s | %-2c | %-20s | %-10s | %-4.1f | %-10s | %-10s | %-5d | %-5s | %s\n",
        candidate->name, candidate->birthdate, candidate->gender, candidate->email, candidate->nationality,
        candidate->bmi, candidate->main_skill, candidate->sub_skill, candidate->topik_level, candidate->mbti,
        candidate->introduction);
}

int main() //프로그램의 진입시작하는 곳입니다.
{
    Candidate candidates[NUM_CANDIDATES];
    int i = 0;

    while (i < NUM_CANDIDATES) //반복문을 사용하여 각 후보자의 정보를 입력받습니다.
    {
        printf("후보자 %d의 정보를 입력합니다.\n", i + 1);
        inputCandidate(&candidates[i]);
        i++;
    }
//출력을 시작하기 전에 테이블의 헤더를 출력합니다.
    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일  | 성별 | 메   일            | 국적     | BMI  | 주스킬      | 보조스킬    | TOPIK | MBTI | 소개\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printCandidate(&candidates[i]);
    }// for 반복문을 사용하여 각 후보자의 정보를 출력하고. 프로그램을 정상적으로 종료합니다.

    return 0;
}
