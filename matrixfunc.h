#define MAX_SIZE 20
#define ERR -1
#define OK 0

void fill_matrix(int *matptr, int rows, int cols);
void print_matrix(int *matptr, int rows, int cols);

int min_mat(int *matptr, int rows, int cols, int *res);
int cnt_range(int *matptr, int rows, int cols, int k, int m, int *res);
int sum_range(int *matptr, int rows, int cols, int k, int m, int *res);