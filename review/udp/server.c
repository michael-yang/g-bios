#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>

#define LOCAL_PORT 1214
#define BUF_LEN 50
#define REMOTE_IP "127.0.0.1"

int main(int argc, const char *argv[])
{
	//socket
	int ret;
	int sk_fd;
	socklen_t size;
	char buff[BUF_LEN] = "hello";
	struct sockaddr_in local_addr, svr_addr;

	sk_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sk_fd < 0) {
		perror("socket()");
	}

	//init sockadd_in
	memset(&local_addr, 0, sizeof(local_addr));
	memset(&svr_addr, 0, sizeof(svr_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htonl(LOCAL_PORT);
	local_addr.sin_addr.s_addr = INADDR_ANY;

#if  0
	ret = inet_aton(REMOTE_IP, &remote_addr.sin_addr.s_addr);
	if (ret < 0) {
		perror("inet_aton()");
	}
#endif

	//bind
	ret = bind(sk_fd, (const struct sockaddr *)&local_addr, sizeof(local_addr));
	if (ret < 0) {
		perror("bind()");
		close(sk_fd);
	}

	//recvfrom
	size = sizeof(local_addr);
	while(1){
		ret = recvfrom(sk_fd, buff, sizeof(buff), 0, (struct sockaddr *)&svr_addr, &size);
		printf("%d\n", ret);
		printf("%s\n",buff);
	}

	//close
	close(sk_fd);

	return 0;
}
