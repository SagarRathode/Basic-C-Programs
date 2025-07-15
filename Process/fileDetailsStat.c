/* write a program which accept directory/file name from command line and display information about file */
//implementation of stat command which is use for display information about file or directory

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat sb;
	printf("\n");

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname> as fileName \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

   printf("File type:                ");

   switch (sb.st_mode & S_IFMT) {

    case S_IFBLK:  printf("  Block device\n");            
	break;
    case S_IFCHR:  printf("  Character device\n");        
	break;
    case S_IFDIR:  printf("  Directory\n");               
	break;
    case S_IFIFO:  printf("  FIFO/pipe\n");               
	break;
    case S_IFLNK:  printf("  Symlink\n");                 
	break;
    case S_IFREG:  printf("  Regular file\n");            
	break;
    case S_IFSOCK: printf("  Socket\n");                  
	break;
    default:       printf("  Unknown?\n");                
	break;
    
    }

    printf("I-node number:              %ld\n", (long) sb.st_ino);

    printf("Mode:                       %lo (octal)\n",(unsigned long) sb.st_mode);

    printf("Link count:                 %ld\n", (long) sb.st_nlink);
    printf("Ownership:                  UID=%ld   GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
    printf("Device id if Special File:  %ld\n", (long) sb.st_rdev);//st_dev
    printf("Preferred I/O block size:   %ld bytes\n", (long) sb.st_blksize);
    printf("File size:                  %lld bytes\n", (long long) sb.st_size);
    printf("Blocks allocated:           %lld\n", (long long) sb.st_blocks);

    printf("Last status change:         %s", ctime(&sb.st_ctime));
    printf("Last file access:           %s", ctime(&sb.st_atime));
    printf("Last file modification:     %s", ctime(&sb.st_mtime));

    exit(EXIT_SUCCESS);
}

