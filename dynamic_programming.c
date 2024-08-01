#include <stdio.h>

#define LIMIT 10 // ナップサックの重さ制限
#define N 10      // アイテムの数

int weight[N + 1]; // アイテムの重さ
int profit[N + 1]; // アイテムの利益
int order[N + 1];      // 選択されたアイテムの個数
int gain[LIMIT + 1]; // 各重さにおける最大利益
int choice[LIMIT + 1]; // 各重さにおける選択されたアイテム

void dynamic_programming(int limit, int n) {
    int i, j, k;

    // 初期化
    for (i = 0; i <= limit; i++) {
        gain[i] = 0;
        choice[i] = 0;
    }

    // 利益の計算
    for (j = 1; j <= n; j++) {
        for (i = limit; i >= weight[j]; i--) {
            k = i - weight[j];
            if (gain[k] + profit[j] > gain[i]) {
                gain[i] = gain[k] + profit[j];
                choice[i] = j;
            }
        }
    }

    // 選択されたアイテムの記録
    for (j = 1; j <= n; j++) {
        order[j] = 0;
    }
    i = limit;
    while (choice[i] > 0) {
        k = choice[i];
        order[k]++;
        i -= weight[k];
    }
}

int main() {
    // weightとprofit配列の設定
    weight[1] = 2; profit[1] = 3;
    weight[2] = 3; profit[2] = 4;
    weight[3] = 4; profit[3] = 5;
    weight[4] = 5; profit[4] = 6;
    weight[5] = 9; profit[5] = 10;
    weight[6] = 7; profit[6] = 8;
    weight[7] = 3; profit[7] = 4;
    weight[8] = 4; profit[8] = 7;
    weight[9] = 2; profit[9] = 2;
    weight[10] = 1; profit[10] = 1;

    int limit = LIMIT;
    int n = N;

    dynamic_programming(limit, n);

    // 結果の表示
    printf("選択されたアイテム:\n");
    for (int j = 1; j <= n; j++) {
        if (order[j] > 0) {
            printf("アイテム %d: %d 個\n", j, order[j]);
        }
    }

    return 0;
}