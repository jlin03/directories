#include <stdio.h> 
#include <dirent.h> 
#include <sys/stat.h>
#include <string.h>

int main() {
    struct dirent *e;
    DIR *d = opendir("test"); 

    char dirs[64][256];
    char files[64][256];

    int size = 0;

    e = readdir(d);
    int dC = 0;
    int fC = 0;

    while (e != NULL) {
      struct stat f;
      stat(e->d_name,&f);
      size+=f.st_size;

      if(e->d_type == DT_DIR) {
        strcpy(dirs[dC], e->d_name);
        dC++;
      }
      else {
        strcpy(files[fC], e->d_name);
        fC+=1;
      }
      e = readdir(d);
    }
    
    printf("Statistics for directory: test\n");
    printf("Total Diectory Size: %d Bytes\n",size);


    int dsize = dC;
    int fsize = fC;
    dC = 0;
    fC = 0;
    printf("Directories:\n");
    while (dC<dsize) {
      printf("\t\t%s\n", dirs[dC]);
      dC++;
    }
    printf("Files:\n");
    while (fC<fsize) {
      printf("\t\t%s\n", files[fC]);
      fC++;
    }


    //printf("\"%s\"  Size: %f %s  Permissions: %s  Last Access: %s",f,size,s,perms,ctime(&info.st_atime));
  
    closedir(d);     
    return 0; 




  return 0;
}
