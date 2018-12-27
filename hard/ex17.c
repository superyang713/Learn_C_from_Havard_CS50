#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_ROW];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE #file;
  struct Database #db;
};

void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}
