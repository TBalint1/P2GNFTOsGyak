#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUM_OF_SEMS 5

union semun {
  int              val;
  struct semid_ds *buf;
  unsigned short  *array;
  struct seminfo  *__buf;
};

int main(void) {
  key_t key = ftok("semset.c", (int)'S');
  int flag = 00666 | IPC_CREAT;
  int num_of_sems = NUM_OF_SEMS;
  int sem_id = semget(key, num_of_sems, flag);

  if (sem_id < 0) {
    perror("unsuccessful");
    return -1;
  } else {
    printf("Sem ID: %d\n", sem_id);
  }

  int command = SETVAL;
  union semun argument;
  argument.val = 0;

  int success = 1;

  for (int i = 0; i < num_of_sems; i++) {
    int status = semctl(sem_id, i, command, argument);
    printf(
      "Setting semaphore %d to %d - Status: %d\n",
      i, argument.val, status
    );

    if (status != 0) {
      success = 0;
    }
  }

  if (success == 1) {
    printf("Every semaphore set to %d\n", argument.val);
  }

  return 0;
}
