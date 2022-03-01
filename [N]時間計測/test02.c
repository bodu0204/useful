#include <stdio.h>
#include <sys/time.h>

int main(void) {
    unsigned int sec;
    int nsec;
    double d_sec;

    struct timespec start_time, end_time;

    /* 処理開始前の時間を取得 */
    clock_gettime(CLOCK_REALTIME, &start_time);

    /* 時間を計測する処理 */

    /* 処理開始後の時間とクロックを取得 */
    clock_gettime(CLOCK_REALTIME, &end_time);

    /* 処理中の経過時間を計算 */
    sec = end_time.tv_sec - start_time.tv_sec;
    nsec = end_time.tv_nsec - start_time.tv_nsec;

    d_sec = (double)sec
        + (double)nsec / (1000 * 1000 * 1000);

    /* 計測時間の表示 */
    printf(
        "time:%f\n", d_sec
    );

    return 0;
}
