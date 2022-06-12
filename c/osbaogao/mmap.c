//mmap部分
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
	fd = open( "mmap_test", O_RDWR );
	array=mmap( NULL, sizeof(int)*MAX, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0 );
	for( i=0; i<MAX; i++)  
		++array[i];
	munmap( array, sizeof(int)*MAX );
	msync( array, sizeof(int)*MAX, MS_SYNC );
	close( fd );
	gettimeofday( &tv2, NULL );
	printf( "Time of mmap: %dms\n", tv2.tv_usec-tv1.tv_usec );
	pause(); 
}
