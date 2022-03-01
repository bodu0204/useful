#include <stdio.h>
#include <time.h>

int main(void) {

    time_t start_time, end_time;

    /* 処理開始前の時間を取得 */
    start_time = time(NULL);

    /* 時間を計測する処理 */

    /* 処理終了後の時間を取得 */
    end_time = time(NULL);

    /* 計測時間の表示 */
    printf("start_time = %ld,\nend_time =   %ld,\nsizeof(time_t)= %zu\n",end_time, start_time, sizeof(time_t));
	printf("%ld.%ld.%ld\n", (end_time % (60 * 60 * 24)) / (60 * 60),(end_time % (60 * 60)) / 60,end_time % (60));

    return 0;
}
