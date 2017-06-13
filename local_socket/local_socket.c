/*******************************************************************************
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#define SERVER_PORT 13254
#define BUFLEN 128
#define LOCAL_IP_ADDR "127.0.0.1"

void run_serve(int sockfd)
{
	int	n;
	socklen_t		alen;
	char			buf[BUFLEN];
	struct sockaddr	addr;

	n = recvfrom(sockfd, buf, BUFLEN, 0, &addr, &alen);
	if(n < 0)
	{
		printf("run_serve : recv error!\n");
		// sprintf(buf, "run_serve : recv error!\n");
		// sendto(sockfd, buf, strlen(buf), 0, &addr, alen);
	}
	buf[BUFLEN - 1] = '\0';
	printf("run_serve rcv string: %s\n", buf);
		
}

void* client_run(void *arg)
{
	int client_fd = -1;
	struct sockaddr_in addr;
	socklen_t alen;
	char buf[BUFLEN];
	int ret;
	int n;

	client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(client_fd < 0)
	{
		pthread_exit((void *) client_fd);
	}
	bzero((char *) &addr, sizeof(addr));
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, LOCAL_IP_ADDR, &addr.sin_addr);
	addr.sin_port = htons(SERVER_PORT);

	while(1)
	{
		printf("enter your request \n");
		scanf("%s", buf);
		buf[BUFLEN - 1] = '\0';
		ret = sendto(client_fd, buf, ((strlen(buf) + 1) < BUFLEN)? strlen(buf) + 1 : BUFLEN , 0, &addr, sizeof(addr));
		if(ret < 0)
		{
			// n = recvfrom(client_fd, buf, BUFLEN, 0, &addr, &alen);
			printf("client_run : recv error!\n");
		}
		printf("client_run : send OK!!\n");
	}

}

int main(int argc, char *argv[])
{
	int serve_fd = -1;
	struct sockaddr_in addr;
	int optval = 1;
	int ret;
	pthread_t c_tid;

	serve_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(serve_fd < 0)
	{
		return serve_fd;
	}
	setsockopt(serve_fd, SOL_SOCKET, SO_REUSEADDR, optval, sizeof(optval));
	bzero((char *) &addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, LOCAL_IP_ADDR, &addr.sin_addr);
	addr.sin_port = htons(SERVER_PORT);
	ret = bind(serve_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
	if(ret < 0)
	{
		close(serve_fd);
		return ret;
	}
	ret = pthread_create(&c_tid, NULL, client_run, NULL);
	if(0 != ret)
	{
		close(serve_fd);
		return -1;
	}
	while(1)
	{
		run_serve(serve_fd);
		// usleep(100000);
	}
	
	

	return 0;
}

