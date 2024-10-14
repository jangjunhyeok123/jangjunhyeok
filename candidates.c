#include <stdio.h>
#include <stdlib.h>

int main() 
{
    typedef struct 
    {
    char name[10];
    char birthday[11]; // YYYY/MM/DD 형식
    char gender;       // 'F' 또는 'M'
    char email[50];     
    char nationality[20];
    float bmi;
    char main_skill[50];
    char secondary_skill[50];
    int korean_level;  // TOPIK 등급
    char mbti[5];
    char introduction[200];
} Member;

Member candidates[6];
int i = 0;
printf("####################################\n");
printf("     오디션 후보자 데이터 입력 \n");
printf("####################################\n");
while (i < 6) 
    {
        printf("후보자 %d의 정보를 입력합니다.\n", i + 1);
        printf("성명: ");
        scanf("%s", candidates[i].name);
        printf("생일(YYYYMMDD 형식): ");
        scanf("%s", candidates[i].birthday);
        printf("성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &candidates[i].gender);
        printf("메일 주소: ");
        scanf("%s", candidates[i].email);
        printf("국적: ");
        scanf("%s", candidates[i].nationality);
        printf("BMI: ");
        scanf("%f", &candidates[i].bmi);
        printf("주 스킬: ");
        scanf("%s", candidates[i].main_skill);
        printf("보조 스킬: ");
        scanf("%s", candidates[i].secondary_skill);
        printf("한국어 등급(TOPIK): ");
        scanf("%d", &candidates[i].korean_level);
        printf("MBTI: ");
        scanf("%s", candidates[i].mbti);
        printf("소개: ");
        getchar(); // 개행문자 제거
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);
        i++;
        printf("=================================\n");
    }

    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회 \n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 |  BMI  | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");

    for (i = 0; i < 6; i++) 
    {
        printf("%-7s | %-8s | %-4s | %-20s | %-4s | %5.1f | %-6s | %-6s | ", 
               candidates[i].name, candidates[i].birthday, 
               (candidates[i].gender == 'F' ? "여" : "남"), 
               candidates[i].email, candidates[i].nationality, 
               candidates[i].bmi, candidates[i].main_skill, 
               candidates[i].secondary_skill);
        
    }

    return 0;
}
