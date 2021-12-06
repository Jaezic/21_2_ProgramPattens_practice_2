#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100
#define NUM_CANDI 3
#define NUM_CITY 3
#define RANGE_AGE 60
#define SAMPLE_LINE 1
const char *candidate[NUM_CANDI] = {"Watshington", "Lincoln", "Clinton"};
const char *city[NUM_CITY] = {"LA", "NewYork", "D.C"};
struct PERSON
{
    char region[20];
    int age;
    int candidate_voted;
};

void generation()
{
    int tmp_city, tmp_age, tmp_candidate;
    FILE *myOutFile;
    myOutFile = fopen("ex2_vote.txt", "w");
    if (myOutFile == NULL)
    {
        printf("Could not open vote.txt!\n");
    }
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        tmp_city = rand() % NUM_CITY;       // 0 ~ 2 (3개)
        tmp_age = rand() % RANGE_AGE + 20;  //( 0 ~ 59 ) + 20 (60개)
        tmp_candidate = rand() % NUM_CANDI; // (0 ~ 2) (3개)
        fprintf(myOutFile, "%s %d %d\n", city[tmp_city], tmp_age, tmp_candidate);
    }
    fclose(myOutFile);
}

void init(struct PERSON *p, int num, const char *name)
{
    FILE *myInFile;
    myInFile = fopen("ex2_vote.txt", "r");
    if (myInFile == NULL)
    {
        printf("Could not open vote.txt!\n");
    }
    int i = 0;
    while (fscanf(myInFile, "%s %d %d", p[i].region, &p[i].age, &p[i].candidate_voted) != EOF)
    {
        i++;
    }
    fclose(myInFile);
}

int num_count(struct PERSON *p, int candidate, int line, int num)
{
    int count = 0;
    for (int i = 0; i < num; i += 1)
    {
        if (p[i].candidate_voted == candidate)
            count++;
    }
    return count;
}
int main()
{
    struct PERSON person[MAX];
    int num = MAX;
    int num_divide = 0;
    generation();

    init(person, num, "vote.txt");

    for (int i = 0; i < NUM_CANDI; i++)
    {
        int num_vote;
        num_vote = num_count(person, i, SAMPLE_LINE, num);
        num_divide = (num / SAMPLE_LINE);
        printf("%s %.1f\n", candidate[i], ((float)num_vote / (float)num_divide) * 100);
    }
    printf("Sampling size : %d\n", (num / SAMPLE_LINE));
    return 0;
}