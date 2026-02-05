# IoT-Basic-Programming-2026
IoT 개발자 과정 - 기초 프로그래밍 언어 학습 repository


## 1일차
- Git, GitHub Desktop 설치
- Visual Studio Code 설치
- README 미리보기 단축키 => Ctrl + Shift + V


### C언어 학습 순서
- 기본
    1. 프로그램 기본
    2. 상수와 데이터 출력
    3. 변수와 데이터 입력
    4. 연산자
    5. 제어문 ( `분기문`, `반복문` )
    6. 함수

- 고급
    1. 배열
    2. `포인터`
    3. 배열과 포인터
    4. 문자열과 포인터
    5. 변수의 영역과 데이터 공유
    6. 다차열 포인터
    7. 구조체 자료형
    8. 파일 입출력
    9. 전처리와 분할 컴파일


### 프로그램 개요
- 프로그램 : `사용자의 요구`에 따라 `데이터`를 `처리`(표현, 이동, 저장, 로드 등)를 할 수 있는 `소프트웨어`
- 프로그램을 만드는 작업 : 프로그래밍(코딩, SW개발, 소프트 엔지니어 등)


### C 언어
- 1972년 켄 톰슨과 데니스 리치가 UNIX 운영체제 개발을 위해서 만든 언어
- C++, Java, C#, Python 등 모든 언어의 베이스가 되는 언어
- C99 표준에 따라서 학습


### 컴파일과 컴파일러
- 컴파일
    - 소스코드파일(텍스트파일)을 컴퓨터가 실행할 수 있는 파일로 변경, 생성하는 행위
    - 고급언어를 컴퓨터가 알아들을 수 있는 저급언어로 변경하는 행위
    - c, cpp --> 확장자 exe 파일로 생성
- 컴파일러
    - IDE(Integrity Development Enviroment - 통합 개발 도구)를 사용
    - `Visual Studio`, Visual Studio Code, Rider, Eclipse


### Visual Studio Community 설치
- https://visualstudio.microsoft.com/ko/ 경로 이동 후 무료 다운로드 받기 클릭
    1. Visual Studio Installer 실행
        ![alt text](image.png)
        
    2. 설치 중
        ![alt text](image-1.png)


### Visual Studio 프로젝트 생성
1. 새 프로젝트 생성
    ![alt text](image-2.png)

2. 새 프로젝트 구성
    - 솔루션 이름, 프로젝트 이름을 다르게 지정
    - 위치는 GitHub 저장소 하위에 위치
    ![alt text](image-3.png)

3. 새 프로젝트 추가
    - 기존 솔루션에 새 프로젝트 추가
    ![alt text](image-4.png)

4. 소스코드 확장자를 변경
    - *.cpp --> *.c 로 변경

5. Chapter01_01_app.c, Chapter01_02_app.c 코딩

6. 메뉴 디버기 > 디버그 하지 않고 시작 (Ctrl+F5) 진행

7. 전체 컴파일 과정
    ![alt text](image-5.png)

8. 프로젝트가 여러개일때
    - 솔루션 속성 > 시작 프로젝트 구성 > `현재 선택 영역`으로 선택

### C 기본 문법
1. 기본 사용법
    - 메인함수 작성법 : [확인](./DAY01/Chapter02_Solution/Chapter02_01_app/main.c)

    - 데이터 출력방법 : [확인](./DAY01/Chapter02_Solution/Chapter02_02_app/main.c)

    - 진법 사용방법 :
        - 2진수 => 컴퓨터의 데이터가 모두 0 ro 1 로만 저장되어 있으므로 사용
        - 8진수 => Bit로 데이터를 처리할 때 Bit 단위가 8이므로 사용
        - 16진수 => 255까지의 수를 짧게 표현하고자 사용
        - 10진수 => 사람이 흔히 사용

    - 진수별 표현법(10, 8, 16) : [확인](./DAY01/Chapter02_Solution/Chapter02_03_app/main.c)
        |10진수|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|
        |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
        |8진수|0|1|2|3|4|5|6|7|10|11|12|13|14|15|16|17|
        |16진수|0x0|0x1|0x2|0x3|0x4|0x5|0x6|0x7|0x8|0x9|0xA|0xB|0xC|0xD|0xE|0xF|
        


## 2일차

### C 기본 문법2

1. 기본 문법
    - 데이터 타입 : [확인](./DAY02/Chapter03_Solution/Chapter03_01_app/main.c)
    - 실수형 및 변수 : [확인](./DAY02/Chapter03_Solution/Chapter03_02_app/main.c)
    - 데이터 입력 : [확인](./DAY02/Chapter03_Solution/Chapter03_03_app/main.c)

    - 연산자 : [확인](./DAY02/Chapter04_Solution/Chapter04_01_app/main.c)

2. 문제 풀이
    - 1번 문제 : [확인](./DAY02/Chapter04_Solution/Chapter04_quiz_01/quiz01.c)
    - 2번 문제 : [확인](./DAY02/Chapter04_Solution/Chapter04_quiz_01/quiz02.c)
    - 4번 문제 : [확인](./DAY02/Chapter04_Solution/Chapter04_quiz_01/quiz04.c)


## 3일차

### C 기본 문법3

1. 제어문 - 선택문
    - if : [확인](./DAY03/Chapter05_Solution/Chapter05_01_app/main.c)
    - switch-case : [확인](./DAY03/Chapter05_Solution/Chapter05_02_app/main.c)
    
2. 반복문 
    - while, do ~ while : [확인](./DAY03/Chapter05_Solution/Chapter05_03_app/main.c)
    - for : [확인](./DAY03/Chapter05_Solution/Chapter05_04_app/main.c)
    - 구구단 : [확인](./DAY03/Chapter05_Solution/Chapter05_05_app/main.c)
    - 무한루프 : [확인](./DAY03/Chapter05_Solution/Chapter05_06_app/main.c)
    - continue, break : [확인](./DAY03/Chapter05_Solution/Chapter05_07_app/main.c)


3. **`디버깅`** 
    - 단축키
        - F5 : Debugging 시작
               Debug 중일때는 다음 Break Point까지 바로 진행.
        - Shift + F5 : Debugging 종료
        - F9 : `Break Point` Toggle 지정
        - F10 : Debugging 중 Source Code 1줄 실행
        - F11 : Source Code 내 `Function`이나 `Class`가 존재하면 내부로 진입
        - 로컬, 조사식 창 활용

4. 함수 
    - 함수 기본 : [확인](./DAY03/Chapter07_Solution/Chapter07_01_app/main.c)


## 4일차

### C 기본 문법4
1. 함수2
    - 함수 유형 : 
        - 매개변수 없는 함수
        - 반환값이 없는 함수
        - 매개변수와 반환값이 없는 함수
        - `매개변수, 반환값`이 있는 함수 - Chapter07_01_app
    - 재귀호출 함수 : [확인](./DAY03/Chapter07_Solution/Chapter07_03_app/main.c)

2. 배열
    - 동일 자료형의 묶음 - `array[10]`
    - 배열 선언, 초기화 : [확인](./DAY04/Chapter08_Solution/Chapter08_01_app/main.c)
    - 문자배열(문자열) : [확인](./DAY04/Chapter08_Solution/Chapter08_03_app/main.c)
    - 문자열 대소문자 변환 : [확인](./DAY04/Chapter08_Solution/Chapter08_Quiz_app/main.c)

        ![alt text](image-6.png)
    
3. 포인터
    - 변수에 담긴 데이터를 공유하기 위함.
    - 프로그램에서 사용하는 메모리를 절약하기 위한 목적.
    - 변수 스코프 : [확인](./DAY04/Chapter09_Solution/Chapter09_01_app/main.c)
    - 메모리 주소
        - 주소 연산자('&') : [확인](./DAY04/Chapter09_Solution/Chapter09_02_app/main.c)
        - 간접 참조 연산자(포인터 연산자'*') : [확인](./DAY04/Chapter09_Solution/Chapter09_03_app/main.c)

    
## 5일차

### C 기본 문법5

1. 포인터 
    - 포인터 이해