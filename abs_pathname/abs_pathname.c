/******************************************************************************
* Copyright (C), 2000-2017,  Electronic Technology Co., Ltd.
*                
* @filename: local_socket.c 
*                
* @author: Clarence.Chow <zhou_chenz@163.com> 
*                
* @version:
*                
* @date: 2017-6-12    
*                
* @brief:          
*                  
*                  
* @details:        
*                 
*    
*    
* @comment           
*******************************************************************************/
#include <sys/types.h>        
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char *argv[])
{
	struct timespec tp;
	printf("%s\n", get_current_dir_name());
	while(1)
	{
		clock_gettime(CLOCK_REALTIME, &tp);
		printf("sec: %d, nsec: %d\n", tp.tv_sec, tp.tv_nsec);
		usleep(200000);
	}
	return 0;
}

