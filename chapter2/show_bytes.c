#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    // "%.2x" 表明证书必须至少用两个数字的十六进制格式输出
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}

int main ()
{
  int val = 12345;
  int ival = val;
  float fval = (float) val;
  int *pval = &val;

  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}