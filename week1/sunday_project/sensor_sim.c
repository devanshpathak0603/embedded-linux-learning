#include <stdio.h>
#include <stdlib.h>

struct SensorStatus {
    unsigned int ready : 1;
    unsigned int error : 1;
    unsigned int mode  : 3;
};

int process_raw(int *data, int n) {
    printf("Raw readings: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");
    return 0;
}

int process_avg(int *data, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    printf("Average reading: %d\n", sum / n);
    return 0;
}

int main(int argc, char *argv[]) {
    struct SensorStatus status = {0};
    status.ready = 1;
    status.mode = 2;

    printf("Sensor status: ready=%d, error=%d, mode=%d\n",
           status.ready, status.error, status.mode);

    int n = 5;
    int *readings = malloc(n * sizeof(int));
    if (readings == NULL) {
        printf("Allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) readings[i] = (i + 1) * 7;

    int (*processor)(int *, int);
    if (argc > 1 && argv[1][0] == 'a') {
        processor = process_avg;
    } else {
        processor = process_raw;
    }
    processor(readings, n);

    free(readings);
    readings = NULL;

    return 0;
}
