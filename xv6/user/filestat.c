#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"


int
main(int argc, char *argv[])
{
   char *fileName = argv[1];
   int fd = open(fileName,O_CHECKED | O_RDWR);

   struct stat st;
   fstat(fd, &st);
   printf(1, "filename=%s checksum: %d \n type: %d  \n size =%d \n device number =%d \n inode number =%d\n links to file =%d\n ",
		     fileName,(int)st.checksum,(int)st.type,(int)st.size,st.dev,(int)st.ino,(int)st.nlink);
   exit();
}
