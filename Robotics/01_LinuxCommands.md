## Basic Linux Commands

#### 사전약속
box 안에서 각 줄의 앞에 붙는 기호의 의미
```
# 주석
$ 명령어 입력
> 명령어 출력
```
터미널 열기 단축키: alt + ctrl + t  


#### cd (change directory)
: 터미널에서 현재 경로를 변경하는 명령어  
아래와 같은 폴더 구조가 있을 때  
```
/home/ian  
/usr/local/bin/  
    /include/X11  

# 현재의 절대경로 확인
$ pwd
> /home/ian

# 절대경로 활용해 이동 (ian은 자신의 사용자명으로 대체)
~$ cd /usr/local
/usr/local$

# 사용자의 홈디렉토리로 이동
/usr/local$ cd ~
~$

# 다시 /usr/local로 이동
$ cd /usr/local
/usr/local$

# 상대경로: 하위 디렉토리인 bin으로 이동
/usr/local$ cd bin
/usr/local/bin$

# 상대경로: 다시 상위 디렉토리인 local로 이동
/usr/local/bin$ cd ..
/usr/local$

# 상대경로: 상위 디렉토리로 갔다가 그 아래 include/X11로 이동
/usr/local$ cd ../include/X11
/usr/include/X11$

# 상대경로: 상위 디렉토리로 두 번 이동
/usr/include/X11$ cd ../..
/usr$

# 사용자 홈 디렉토리를 상대경로를 이용하여 이동
/usr$ cd ../home/ian
~$
```

#### ls (list)
: 현재 경로에 있는 파일이나 폴더를 확인하는 명령어

```


```