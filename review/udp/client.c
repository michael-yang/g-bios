#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>

#define LOCAL_PORT 3214
#define BUF_LEN 50
#define REMOTE_IP "127.0.0.1"

int main(int argc, const char *argv[])
{
	//socket
	int ret;
	int sk_fd;
	char buff[BUF_LEN] = "hello";
	struct sockaddr_in svr_addr, remote_addr;

	sk_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sk_fd < 0) {
		perror("socket()");
	}

	//init sockadd_in
	memset(&svr_addr, 0, sizeof(svr_addr));
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(LOCAL_PORT);
	ret = inet_aton(REMOTE_IP, &remote_addr.sin_addr.s_addr);
	if (ret < 0) {
		perror("inet_aton()");
	}

	//svr_addr.sin_addr.s_addr = INADDR_ANY;

#if  0
	memset(&remote_addr, 0, sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_port = htonl(LOCAL_PORT);
	ret = inet_aton(REMOTE_IP, &remote_addr.sin_addr.s_addr);
	if (ret < 0) {
		perror("inet_aton()");
	}
#endif
	//bind
	ret = bind(sk_fd, (const struct sockaddr *)&svr_addr, sizeof(svr_addr));
	if (ret < 0) {
		perror("bind()");
	}

	//sendto
	ret = sendto(sk_fd, buff, sizeof(buff), 0, (const struct sockaddr *)&svr_addr, sizeof(svr_addr));
	if (ret < 0) {
		return ret;
	}
	//close
	close(sk_fd);
	return 0;
}
