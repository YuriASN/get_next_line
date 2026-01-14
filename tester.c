#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>

int  main (void)  {
  int fd = open("", O_RDONLY);
  //int fd2 = open("", O_RDONLY);
  while (get_next_line(fd))
  {
    //get_next_line(fd);
    sleep (1) ;
  }
  close (fd);
  return (0);
}
