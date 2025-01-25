#include <stdio.h>
#include <string.h>

#include "ripemd160.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
int tests_run = 0;


static char *test_case_01() {
  char const * const input = "";
  uint8_t const expected[20] = {0x9c,0x11,0x85,0xa5,0xc5,0xe9,0xfc,0x54,0x61,0x28,0x08,0x97,0x7e,0xe8,0xf5,0x48,0xb2,0x25,0x8d,0x31};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 1 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_02() {
  char const * const input = "a";
  uint8_t const expected[20] = {0x0b, 0xdc, 0x9d, 0x2d, 0x25, 0x6b, 0x3e, 0xe9, 0xda, 0xae, 0x34, 0x7b, 0xe6, 0xf4, 0xdc, 0x83, 0x5a, 0x46, 0x7f, 0xfe};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 2 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_03() {
  char const * const input = "abc";
  uint8_t const expected[20] = {0x8e, 0xb2, 0x08, 0xf7, 0xe0, 0x5d, 0x98, 0x7a, 0x9b, 0x04, 0x4a, 0x8e, 0x98, 0xc6, 0xb0, 0x87, 0xf1, 0x5a, 0x0b, 0xfc};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 3 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_04() {
  char const * const input = "message digest";
  uint8_t const expected[20] = {0x5d, 0x06, 0x89, 0xef, 0x49, 0xd2, 0xfa, 0xe5, 0x72, 0xb8, 0x81, 0xb1, 0x23, 0xa8, 0x5f, 0xfa, 0x21, 0x59, 0x5f, 0x36};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 4 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_05() {
  char const * const input = "abcdefghijklmnopqrstuvwxyz";
  uint8_t const expected[20] = {0xf7, 0x1c, 0x27, 0x10, 0x9c, 0x69, 0x2c, 0x1b, 0x56, 0xbb, 0xdc, 0xeb, 0x5b, 0x9d, 0x28, 0x65, 0xb3, 0x70, 0x8d, 0xbc};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 5 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_06() {
  char const * const input = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
  uint8_t const expected[20] = {0x12, 0xa0, 0x53, 0x38, 0x4a, 0x9c, 0x0c, 0x88, 0xe4, 0x05, 0xa0, 0x6c, 0x27, 0xdc, 0xf4, 0x9a, 0xda, 0x62, 0xeb, 0x2b};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 6 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_07() {
  char const * const input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  uint8_t const expected[20] = {0xb0, 0xe2, 0x0b, 0x6e, 0x31, 0x16, 0x64, 0x02, 0x86, 0xed, 0x3a, 0x87, 0xa5, 0x71, 0x30, 0x79, 0xb2, 0x1f, 0x51, 0x89};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 7 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char *test_case_08() {
  char const * const input = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
  uint8_t const expected[20] = {0x9b, 0x75, 0x2e, 0x45, 0x57, 0x3d, 0x4b, 0x39, 0xf4, 0xdb, 0xd3, 0x32, 0x3c, 0xab, 0x82, 0xbf, 0x63, 0x32, 0x6b, 0xfb};
  uint8_t digest[20];
  ripemd160((uint8_t *)input, strlen(input), digest);
  mu_assert("test case 8 - hash mismatch", 0 == memcmp(expected, digest, 20));
  return 0;
}

static char * all_tests() {
    mu_run_test(test_case_01);
    mu_run_test(test_case_02);
    mu_run_test(test_case_03);
    mu_run_test(test_case_04);
    mu_run_test(test_case_05);
    mu_run_test(test_case_06);
    mu_run_test(test_case_07);
    mu_run_test(test_case_08);
    return 0;
}

int main(int argc, char * const argv[]) {
    char *result = all_tests();
    if(result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}