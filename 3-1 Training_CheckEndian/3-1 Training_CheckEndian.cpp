#pragma comment(lib, "ws2_32")
#include <iostream>
#include <WinSock2.h>

BOOL IsLittleEndian(u_long b);
BOOL IsBigEndian(u_long b);

int main(int argc, char* argv[]) {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	u_long byte = 0x12345678;

	std::cout << "Byte: " << std::hex << std::showbase << byte << std::endl;
	std::cout << "리틀 엔디안: " << ( IsLittleEndian(byte) ? ("True") : ("False") ) << std::endl;
	std::cout << "빅 엔디안: " << (IsBigEndian(byte) ? ("True") : ("False")) << std::endl;
	std::cout << std::endl;

	system("pause");
	WSACleanup();
	return 0;
}

BOOL IsLittleEndian(u_long b)
{
	char* c = (char*)&b;
	
	if ( *c == 0x78) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

BOOL IsBigEndian(u_long b)
{
	if ( *(char*)&b == 0x12) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
