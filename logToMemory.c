/*H**********************************************************************
* FILENAME :        logToMemory.c             
*
* DESCRIPTION :
*                    Writing to a file is expensive. Its faster to log to memory and then out to file in the end if timing in code matters
*
*
*
* AUTHOR :    Dakshil        
*
*H*/
#include <stdio.h>
#include <sys/stat.h>//for file size
long fsize(const char *filename) //function to get size of log file
{
    struct stat st; 

    if (stat(filename, &st) == 0)
        return (long)st.st_size;

    return -1; 
}
int
main (void)
{
  char *point;
  size_t size;
  FILE *stream;
  FILE *fp;
  fp = fopen( "log.txt" , "w" );//file to which we want to write
  stream = open_memstream (&point, &size);//open a memory stream to write to
  //do logging in the stream
  fprintf (stream, "log line 1\n");
  fprintf (stream, "log line 2\n");
  //end of logging
  fflush(stream);// flush the stream
  fclose (stream);//close the stream
  fwrite(point , 1 , size , fp );//write the stream out to file
  fclose(fp);//close file
  printf("%d\n",fsize("log.txt"));//check size of log file
  return 0;
}

