# ROS 설치 가이드

### 1. PC Setup

원문: http://emanual.robotis.com/docs/en/platform/turtlebot3/pc_setup/#pc-setup
***

#### 1.1 우분투 설치

우분투 설치는 제가 예전에 [여기](https://github.com/goodgodgd/Fall_2018_Lectures/blob/master/Robotics/00_LinuxInstallation.md) 
소개한 대로 가상 머신으로 설치하세요.
***

#### 1.2 ROS 설치

설치 스크립트를 다운 받아 스크립트를 실행한다.
```bash
$ sudo apt-get update
$ sudo apt-get upgrade
$ cd Downloads
$ wget https://raw.githubusercontent.com/ROBOTIS-GIT/robotis_tools/master/install_ros_kinetic.sh && chmod 755 ./install_ros_kinetic.sh && bash ./install_ros_kinetic.sh
```
설치 스크립트는 대략 다음과 같은 기능을 한다. 
- ros-desktop-full 설치
- catkin workspace를 만드는 작업
- ROS 환경설정: ~/.bashrc 수정

설치가 다 되어 "Complete!!!" 가 뜨면 **PC 리부트**
***

#### 1.3 터틀봇 제어 패키지 설치

터틀봇을 제어할 수 있는 패키지를 설치한다.
저장소에 없는 패키지는 소스를 받아 catkin 으로 빌드한다.

```bash
$ sudo apt-get install ros-kinetic-joy ros-kinetic-teleop-twist-joy ros-kinetic-teleop-twist-keyboard ros-kinetic-laser-proc ros-kinetic-rgbd-launch ros-kinetic-depthimage-to-laserscan ros-kinetic-rosserial-arduino ros-kinetic-rosserial-python ros-kinetic-rosserial-server ros-kinetic-rosserial-client ros-kinetic-rosserial-msgs ros-kinetic-amcl ros-kinetic-map-server ros-kinetic-move-base ros-kinetic-urdf ros-kinetic-xacro ros-kinetic-compressed-image-transport ros-kinetic-rqt-image-view ros-kinetic-gmapping ros-kinetic-navigation ros-kinetic-interactive-markers
$ cd ~/catkin_ws/src/
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3.git
$ cd ~/catkin_ws && catkin_make
```
***

#### 1.4 네트워크 설정

`gedit ~/.bashrc` 명령으로 .bashrc 파일을 열어보면 아래쪽에 ros 설치과정에서 추가된 스크립트가 있다.  
맨 아래를 보면 두 개의 주소를 볼 수 있다.
- `ROS_MASTER_URI` : 여러대의 PC가 통신하는 경우 한 PC가 master 역할을 해줘야한다. 통상 Remote PC가 그 역할을 한다.  
`ROS_MASTER_URI`는 master PC의 IP 주소이다.
- `ROS_HOSTNAME` : 자기 자신의 IP를 쓴다.

기본 설정은 하나의 PC안에서 모든 동작을 하는 것이므로 두 주소 모두 `localhost`로 되어있다.  
그러나 터틀봇의 SBC와 통신을 하기 위해서는 이를 IP 주소로 바꿔야 한다.  
`ROS_HOSTNAME` 에는 당연히 해당 PC의 IP를 쓰고 Remote PC가 master 역할을 하니 `ROS_MASTER_URI`에도 같은 주소를 쓴다.  
IP 주소는 `ifconfig` 명령어를 이용해 확인할 수 있다.    
`inet addr:192.168.xxx.xxx` 로 시작하는 주소를 찾아 쓴다.
다음은 설정 예시이다.
```bash
export ROS_MASTER_URI=http://192.168.0.49:11311
export ROS_HOSTNAME=192.168.0.49
```
