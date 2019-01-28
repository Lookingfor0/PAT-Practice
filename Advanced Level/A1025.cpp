#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student
{
    char id[14];
    int score;
    int location;
    int local_rank;
};


bool cmp(Student a, Student b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}


int main()
{
    int N, num = 0;
    Student stu[30000];  // 为了方便总体排序，这里用不宜用二维数组
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int local_num;
        scanf("%d", &local_num);
        for(int j = 0; j < local_num; j++)
        {
            scanf("%s %d", stu[num + j].id, &stu[num + j].score);
            stu[num + j].location = i + 1;
        }
        // 求 local_rank
        sort(stu + num, stu + num + local_num, cmp);
        stu[num].local_rank = 1;
        for(int j = num + 1; j < num + local_num; j++)
        {
            if(stu[j].score == stu[j - 1].score)
                stu[j].local_rank = stu[j - 1].local_rank;
            else
                stu[j].local_rank = j - num + 1;
        }
        num += local_num;
    }
    // 求 final_rank 并输出
    sort(stu, stu + num, cmp);
    int r = 1;
    printf("%d\n", num);
    for(int i = 0; i < num; i++)
    {
        if(i > 0 && stu[i].score != stu[i - 1].score)
            r = i + 1;
        printf("%s %d %d %d\n", stu[i].id, r, stu[i].location, stu[i].local_rank);
    }
    return 0;
}

