#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

union longdouble_union {
  long double ld;
  uint8_t bytes[sizeof(long double)];
};

int main() {
  char charType;
  int size_of_char = sizeof(charType) * 8;
  printf("Size of char: %zu byte(s)\n", sizeof(charType));
  printf("\tPrinted: %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("\tComputed: %d to %d\n", (int)(-1 * pow(2, size_of_char - 1)),
         (int)(pow(2, size_of_char - 1) - 1));

  unsigned char u_charType;
  printf("Size of unsigned char: %zu byte(s)\n", sizeof(u_charType));
  printf("\tPrinted: %d to %d\n", 0, UCHAR_MAX);
  printf("\tComputed: %d to %d\n", 0, (unsigned char)(-1));

  short int shortintType;
  int size_of_short_int = sizeof(shortintType) * 8;
  printf("Size of short int: %zu byte(s)\n", sizeof(shortintType));
  printf("\tPrinted: %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("\tComputed: %d to %d\n", (int)(-1 * pow(2, size_of_short_int - 1)),
         (int)(pow(2, size_of_short_int - 1) - 1));

  unsigned short int u_shortintType;
  printf("Size of unsigned short int: %zu byte(s)\n", sizeof(u_shortintType));
  printf("\tPrinted: %d to %d\n", 0, USHRT_MAX);
  printf("\tComputed: %d to %d\n", 0, (unsigned short int)(-1));

  int intType;
  int size_of_int = sizeof(intType) * 8;
  printf("Size of int: %zu byte(s)\n", sizeof(intType));
  printf("\tPrinted: %d to %d\n", INT_MIN, INT_MAX);
  printf("\tComputed: %ld to %ld\n", (long int)(-1 * pow(2, size_of_int - 1)),
         (long int)(pow(2, size_of_int - 1) - 1));

  unsigned int u_intType;
  printf("Size of unsigned int: %zu byte(s)\n", sizeof(u_intType));
  printf("\tPrinted: %u to %u\n", 0, UINT_MAX);
  printf("\tComputed: %u to %u\n", 0, (unsigned int)(-1));

  long int longintType;
  int size_of_long_int = sizeof(longintType) * 8;
  printf("Size of long int: %zu byte(s)\n", sizeof(longintType));
  printf("\tPrinted: %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("\tComputed: %ld to %ld\n",
         (long int)(-1 * pow(2, size_of_long_int - 1)),
         (long int)(pow(2, size_of_long_int - 1) - 1));

  long int u_longintType;
  printf("Size of unsigned long int: %zu byte(s)\n", sizeof(u_longintType));
  printf("\tPrinted: %d to %lu\n", 0, ULONG_MAX);
  printf("\tComputed: %d to %lu\n", 0, (unsigned long int)(-1));

  long long int longlongintType;
  int size_of_long_long_int = sizeof(longlongintType) * 8;
  printf("Size of long long int: %zu byte(s)\n", sizeof(longlongintType));
  printf("\tPrinted: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
  printf("\tComputed: %lld to %lld\n",
         (long long int)(-1 * pow(2, size_of_long_long_int - 1)),
         (long long int)(pow(2, size_of_long_long_int - 1) - 1));

  long long int u_longlongintType;
  printf("Size of unsigned long long int: %zu byte(s)\n",
         sizeof(u_longlongintType));
  printf("\tPrinted: %d to %llu\n", 0, ULLONG_MAX);
  printf("\tComputed: %d to %llu\n", 0, (unsigned long long int)(-1));

  float floatType;
  int min = 0x00800000;
  int true_min = 0x00000001;
  int max = 0x7f7fffff;
  printf("Size of float: %zu byte(s)\n", sizeof(floatType));
  printf("\tPrinted: min = %.10e\n", FLT_MIN);
  printf("\tPrinted: true min = %.10e\n", FLT_TRUE_MIN);
  printf("\tPrinted: max = %.10e\n", FLT_MAX);
  printf("\tComputed: min = %.10e\n", *((float *)(&min)));
  printf("\tComputed: true min = %.10e\n", *((float *)(&true_min)));
  printf("\tComputed: max = %.10e\n", *((float *)(&max)));

  double doubleType;
  long int db_min = 0x0010000000000001;
  long int db_true_min = 0x0000000000000001;
  long int db_max = 0x7FEFFFFFFFFFFFFF;
  printf("Size of double: %zu byte(s)\n", sizeof(doubleType));
  printf("\tPrinted: min = %.10e\n", DBL_MIN);
  printf("\tPrinted: true_min = %.10e\n", DBL_TRUE_MIN);
  printf("\tPrinted: max = %.10e\n", DBL_MAX);
  printf("\tComputed: min = %.10e\n", *((double *)(&db_min)));
  printf("\tComputed: true_min = %.10e\n", *((double *)(&db_true_min)));
  printf("\tComputed: max = %.10e\n", *((double *)(&db_max)));

  long double longdoubleType;

  union longdouble_union ldb_min = {
      .bytes = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00,
                0xd2, 0xc6, 0x50, 0xdb, 0x61, 0x59}};
  union longdouble_union ldb_true_min = {
      .bytes = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
  union longdouble_union ldb_max = {
      .bytes = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f,
                0x21, 0x7a, 0x67, 0x55, 0x00, 0x00}};

  printf("Size of long double: %zu byte(s)\n", sizeof(longdoubleType));
  printf("\tPrinted: min = %.10Le\n", LDBL_MIN);
  printf("\tPrinted: true_min = %.10Le\n", LDBL_TRUE_MIN);
  printf("\tPrinted: max = %.10Le\n", LDBL_MAX);
  printf("\tPrinted: min = %.10Le\n", ldb_min.ld);
  printf("\tPrinted: true_min = %.10Le\n", ldb_true_min.ld);
  printf("\tPrinted: max = %.10Le\n", ldb_max.ld);

  return 0;
}