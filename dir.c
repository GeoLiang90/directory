#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
  DIR * d;
  d = opendir("./");
  struct dirent * entry;

  while (entry){
    entry = readdir(d);
    printf(" %s \n", entry->d_name);
  }
  closedir(d);
  return 0;
}
