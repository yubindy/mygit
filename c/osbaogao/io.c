#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/mman.h> 
#define MAX 10000 

int main()
{
	int i=0;
	int count=0, fd=0;
	struct timeval tv1, tv2;
	int *array = (int *)malloc( sizeof(int)*MAX );

	gettimeofday( &tv1, NULL );
	fd=open( "mmap_test", O_RDWR);
	read(fd, (void *)array, sizeof(int)*MAX );
	gettimeofday(&tv2, NULL);
	printf( "Time of read: %ldms\n", tv2.tv_usec-tv1.tv_usec );
	gettimeofday( &tv1, NULL );
	for(i=0;i<MAX;i++)  ++array[ i ];
	write( fd, (void *)array, sizeof(int)*MAX );
	close( fd );
	gettimeofday( &tv2, NULL );
	printf( "Time of write: %ldms", tv2.tv_usec-tv1.tv_usec );
	fflush(stdout);
	pause();
}
