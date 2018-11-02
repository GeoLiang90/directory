#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
  DIR * d;
  struct stat info;
  stat(filename, &info);

  // print file size
  int size = info.st_size;
  printf(" File size: [%d]\n", size);

  d = opendir("./");
  struct dirent * entry;
  printf("Directories:\n");
  while (entry) {
    if ( entry->d_type == DT_DIR) {
      printf("\t%s \n", entry->d_name);
    }
    entry = readdir(d);
  }
  closedir(d);

  d = opendir("./");
  struct dirent * ent;
  printf("Regular files:\n");
  while (ent) {
    if (ent->d_type == DT_REG) {
      printf("\t%s \n", ent->d_name);
      
    }
    ent = readdir(d);
  }
  closedir(d);
  return 0;
}
