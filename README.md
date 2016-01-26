# File_System_Integrity_xv6
In this project, xv6 file system has been modified to add protection from data corruption. In real storage systems, silent corruption of data is a major concern, and thus many techniques are usually put in place to detect (and recover) from blocks that go bad.  
Three things have been implemented. 

First, modified the code to allow the user to create a new type of file that keeps a checksum for every block it points to. Checksums are used by modern storage systems in order to detect silent corruption.  

Second, Changed the file system to handle reads and writes differently for files with checksums. Specifically, when writing out such a file, Created a checksum for every block of the file; when reading such a file, checked and made sure the block still matches the stored checksum, returning an error code (-1) if it doesn't. In this way,  file system will be able to detect corruption!  

Third, for information purposes, Modified the stat() system call to dump some information about the file. Given a file name, not only prints out the file's size, etc., but also some information about the file's checksums (details below)
stat() struct is modified to 
struct stat {
    short type;     // Type of file
    int dev;        // Device number
    uint ino;       // Inode number on device
    short nlink;    // Number of links to file
    uint size;      // Size of file in bytes
    uchar checksum; //checksum of file
};
