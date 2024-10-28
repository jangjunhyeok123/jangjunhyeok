#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // 배열 크기 지정 (최대 5명)
    char judges_array[5][512]; // 심사자 데이터 저장 배열
    int num_judges = 5; // 심사 풀 인원
    int selected_members = 4; // 선발 멤버 수
    int judge_count = 0;

    char project_name[100];
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    fgets(project_name, 100, stdin);

    // 문자열에서 개행 문자 제거
    for (int i = 0; project_name[i] != '\0'; i++) 
    {
        if (project_name[i] == '\n') 
        {
            project_name[i] = '\0';
            break;
        }
    }

    printf("> 심사 풀 인원: %d\n", num_judges);
    printf("> 선발 멤버 수: %d\n", selected_members);
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (judge_count < num_judges) 
    {
        char name[50], gender[10], affiliation[50], title[50], specialization[50], email[50], phone[20];
        printf("*심사자 %d:\n", judge_count + 1);

        // 정보 입력받기
        printf("이름: ");
        fgets(name, 50, stdin);
        for (int i = 0; name[i] != '\0'; i++) 
        {
            if (name[i] == '\n') 
            {
                name[i] = '\0';
                break;
            }
        }

        printf("성별: ");
        fgets(gender, 10, stdin);
        for (int i = 0; gender[i] != '\0'; i++) 
        {
            if (gender[i] == '\n') 
            {
                gender[i] = '\0';
                break;
            }
        }

        printf("소속: ");
        fgets(affiliation, 50, stdin);
        for (int i = 0; affiliation[i] != '\0'; i++) 
        {
            if (affiliation[i] == '\n') 
            {
                affiliation[i] = '\0';
                break;
            }
        }

        printf("직함: ");
        fgets(title, 50, stdin);
        for (int i = 0; title[i] != '\0'; i++) 
        {
            if (title[i] == '\n') 
            {
                title[i] = '\0';
                break;
            }
        }

        printf("전문분야: ");
        fgets(specialization, 50, stdin);
        for (int i = 0; specialization[i] != '\0'; i++) 
        {
            if (specialization[i] == '\n') 
            {
                specialization[i] = '\0';
                break;
            }
        }

        printf("메일: ");
        fgets(email, 50, stdin);
        for (int i = 0; email[i] != '\0'; i++) 
        {
            if (email[i] == '\n') 
            {
                email[i] = '\0';
                break;
            }
        }

        printf("전화: ");
        fgets(phone, 20, stdin);
        for (int i = 0; phone[i] != '\0'; i++)
        {
            if (phone[i] == '\n')
            {
                phone[i] = '\0';
                break;
            }
        }

        // 입력한 정보를 JSON 형식으로 저장
        snprintf(judges_array[judge_count], sizeof(judges_array[judge_count]),
            "{\"이름\":\"%s\", \"성별\":\"%s\", \"소속\":\"%s\", \"직함\":\"%s\", \"전문분야\":\"%s\", \"메일\":\"%s\", \"전화번호\":\"%s\"}",
            name, gender, affiliation, title, specialization, email, phone);

        judge_count++;
        printf("-----------------------------------\n");
    }

    // 입력 완료 후 심사자 풀 확인 여부 묻기
    char confirm;
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("“심사자 풀을 확인할까요?” (Y/N): ");
    confirm = getchar();

    if (confirm == 'Y' || confirm == 'y') 
    {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");
        for (int i = 0; i < num_judges; i++) 
        {
            printf("[심사자 %d]\n%s\n", i + 1, judges_array[i]);
            printf("-----------------------------------\n");
        }
    }
    else {
        printf("프로그램을 종료합니다.\n");
        exit(0);
    }

    return 0;
}
