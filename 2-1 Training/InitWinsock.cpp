#pragma comment(lib, "ws2_32")
#include <iostream>
#include <WinSock2.h>

// # 유니코드 대신 멀티바이트로 바꿀것
int main(int argc, char* argv[]) {
	// 윈속 초기화 정보 구조체
	WSADATA wsa;

	// 윈속 초기화를 해야 사용 가능. 성공시 0 반환 / 그 외의 값 실패.
	
	// #  모든 윈속 프로그램은 소켓 함수를 호출하기 전에 반드시 윈소 초기화 함수인 WSAStartup()을 호출해야 합니다.
	// # WSAStartup() 함수는 프로그램에서 사용할 윈속 버전을 요청함으로써 윈속 라이브러리(WS2_32.DLL)를 초기화 하는 역할을 합니다. 
	// # 같은말로 WSAStartup() 함수가 실패할 경우 WS2_32.DLL이 메모리에 로드되지 않습니다.
	
	// 1.1 버전: MAKEWORD(1, 1) ex: 3.2 -> 0x0203 // 상위 8비트 마이너(부버전), 하위 8비트 메이저(주버전)
	if (WSAStartup(MAKEWORD(2, 1), &wsa) != 0) 
		return 1;
	MessageBox(NULL, "윈속 초기화 성공", "알림", MB_OK);
	
	// # https://m.blog.naver.com/PostView.nhn?blogId=seesend&logNo=140047359936&proxyReferer=https:%2F%2Fwww.google.com%2F
	// # MAKEWORD 매크로가 무슨 역할을 하는지 참고해볼 것
	std::cout << "wVersion: " << (WORD)LOBYTE(wsa.wVersion) << "." << (WORD)HIBYTE(wsa.wVersion) << std::endl;
	std::cout << "wHighVersion: " << ((wsa.wHighVersion >> 8) & 0xFF) << "." << (wsa.wHighVersion & 0xFF) << std::endl;
	std::cout << "szDescription: " << wsa.szDescription << std::endl;
	std::cout << "szSystemStatus: " << wsa.szSystemStatus << std::endl;
	system("pause");

	// 윈속 종료
	WSACleanup();

	return 0;
}