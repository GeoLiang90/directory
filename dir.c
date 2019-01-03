#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char * argv[]){

  char directory[50];
  if (argc == 2){
    strcpy(directory, argv[1]);
  }
  else if(argc == 1){
  //If user input is empty, prompt user to input
  while(strlen(directory) < 1){
    printf("Enter a directory to check:");
    scanf("%s",directory);
  }

}
  printf("Checking directory: %s \n", directory);
  DIR * d;

  struct stat * info = malloc(sizeof(struct stat));
  int size = 0;

  d = opendir(directory);
  //if d does not exist, tell the user and exit early
  if(!d){
    perror("ERROR");
    exit(0);
  }

  struct dirent * entry;

  printf("Directories:\n");
  while (entry) {
    if (entry->d_type == DT_DIR) {
      printf("\t%s \n", entry->d_name);
    }
    entry = readdir(d);
  }
  closedir(d);

  d = opendir(directory);
  struct dirent * ent;
  printf("Regular files:\n");
  char filep[100];
  while (ent) {
  strcpy(filep,directory);
    if (ent->d_type == DT_REG) {
      printf("\t%s \n", ent->d_name);
      strcat(filep, ent->d_name);
      //Diagnostic msg for finding file path
      //printf("%s \n", filep);

      stat(filep, info);
      size += info->st_size;
    }
    ent = readdir(d);
  }
  closedir(d);
    printf(" Total Directory Size: %d Bytes \n", size);

  return 0;
}
