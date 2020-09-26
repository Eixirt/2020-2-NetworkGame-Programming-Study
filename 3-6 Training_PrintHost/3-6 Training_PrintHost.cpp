#define _WINSOCK_DEPRECATED_NO_WARNINGS // 최신 VC++ 컴파일 시 경고 방지
// #pragma warning(disable: 4996)
#pragma comment(lib, "ws2_32")

#include <iostream>
#include <WinSock2.h>

int main(int argc, char* argv[]) {
	WSADATA wsa;

	std::cout << "argc: " << argc << std::endl;
	if (argc != 2) {
		std::cout << "[!]Input Error" << std::endl;
		return 1;
	}

	std::cout << "=================================" << std::endl;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		std::cout << "[!]WSAStartup Error" << std::endl;
		return 1;
	}

	IN_ADDR addr;
	HOSTENT* host = NULL;
	char* hostName = argv[1];
	
	// 도메인 이름을 입력했을 경우
	if (isalpha(hostName[0])) {
		// std::cout << "Domain Name: " << hostName << std::endl;
		host = gethostbyname(hostName);
	}
	// IP 입력했을 경우
	else {
		std::cout << "IP: " << hostName << std::endl;
		addr.s_addr = inet_addr(hostName);
		if (addr.s_addr == INADDR_NONE) {
			std::cout << "IP 주소를 입력해주세요." << std::endl;
		}
		else {
			host = gethostbyaddr((char*)&addr, 4, AF_INET);
		}
	}

	// 정상적인 입력이 아닐 경우
	if (host == NULL) {
		std::cout << "Host Init Error." << std::endl;
		return 1;
	}

	std::cout << "Domain Name: " << host->h_name << std::endl;
	for (int i = 0; host->h_aliases[i]; ++i) {
		std::cout << "Aliase: " << host->h_aliases[i] << std::endl;
	}
	for (int i = 0; host->h_addr_list[i]; ++i) {
		addr.s_addr = *(u_long*)host->h_addr_list[i];
		std::cout << "Address: " << inet_ntoa(addr) << std::endl;
	}

	system("pause");
	WSACleanup();
	return 0;
}

