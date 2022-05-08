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

  int command = IPC_RMID;
  union semun argument;

  int status = semctl(sem_id, 0, command, argument);

  if (status < 0) {
    perror("unsuccessful");
    return -1;
  } else {
    printf("Sem set removed\n");
  }

  return 0;
}
