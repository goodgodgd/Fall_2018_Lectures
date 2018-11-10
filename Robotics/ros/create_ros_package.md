# Create ROS package

교재 7.2장에서 ROS에서 토픽을 발행하고 구독하는 예제를 따라하며  
ROS 패키지를 만드는 과정도 함께 공부해 봅시다. 

## 1. 패키지 생성

패키지는 `catkin_create_pkg` 명령어를 이용해 생성할 수 있습니다.
```bash
# ros 패키지는 ~/catkin_ws/src 이곳에 생성해야 합니다.
$ cd ~/catkin_ws/src
# catkin_create_pkg [패키지 이름] [의존 패키지들]
$ catkin_create_pkg ros_tutorials_topic message_generation std_msgs roscpp
$ ls ros_tutorials_topic
CMakeLists.txt : 빌드 설정 파일
package.xml : 패키지 설정 파일
```

#### make, cmake, and catkin  
- 리눅스의 기본 빌드 시스템은 make이고 make를 이용해 빌드를 하기 위해서는 makefile 이라는 스크립트 필요  
- makefile 은 어떤 소스를 빌드해야 하는지 어떤 라이브러리를 링크해야 하는지 등의 빌드에 필요한 정보를 정해진 문법에 따라 기술함
- 문제는 makefile 이 쉘 스크립트 기반으로 되어 있어서 프로젝트가 복잡해 질수록 읽고 쓰기가 어렵다는 것
- cmake는 이 makefile을 좀 더 쉽게 생성할 수 있게 도와주는 빌드 시스템으로 현재 가장 일반적으로 많이 쓰임
- cmake는 빌드시 생기는 중간 생성물을 (.o) 신경쓰지 않고 소스에서 만들어질 결과물 (실행파일, 라이브러리)만 지정해주면 makefile 을 생성해 줌
- 물론 cmake 자체도 CMakeList.txt 라는 스크립트 파일을 cmake 문법에 따라 작성해줘야만 함
- ~~그럼 이걸 왜하나~~ 그래도 makefile을 직접 작성하는 것 보다는 훨씬 쉬움
- catkin은 cmake를 기반으로 ros를 위한 기능들이 추가된 빌드시스템
- catkin도 똑같이 CMakeList.txt 를 통해 빌드 설정을 하고 문법도 cmake와 동일하나 몇 가지 기능만 추가됨  

---

## 2. 패키지 설정 파일 수정

`catkin_create_pkg` 명령어로 패키지를 생성하면 기본적으로 `CMakeLists.txt`와 `package.xml`이 생기고 주석을 통해 다양한 설정들을 가이드하고 있다.  
- package.xml: ROS에서 패키지를 관리하는데 필요한 정보 기술   
설치 시  필요한 의존 패키지 정보, 패키지를 배포하는데 필요한 저자, 라이센스 등의 정보  
- CMakeLists.txt: 로컬에서 소스를 빌드하는데 필요한 설정 지정  

두 파일에 다양한 설정 항목들이 있는데 모두 다 항상 필요한 것은 아니고 예제에 나오는 설정 위주로 의미와 사용법을 알아보자.  

### 2.1 package.xml

다음은 ros_tutorials_topic을 위해 package.xml 을 작성한 예시이다.
```xml
<?xml version="1.0"?>
<!-- packages.xml: ros에서 패키지를 관리하는데 필요한 정보 담음 -->
<!-- 공식 패키지로 업로드시 공개해야 할 정보들 포함: 저자, 저작권 등 -->
<!-- 의존 패키지들을 지정하면 빌드시 설치되지 않은 의존 패키지 자동 설치 -->
<!-- xml version: 필수는 아님 -->

<package>
  <!-- 패키지 이름은 자동으로 지정됨, 수정할 시 이름이 틀리지 않게 주의 -->
  <name>ros_tutorials_topic</name>
  <!-- 기본 생성시 버전은 0.0.0 인데 원하는대로 수정 가능 -->
  <version>0.1.0</version>

  <!-- 위키를 만들면 자동으로 이 문구가 업로드 됨 -->
  <description>ROS turtorial package to learn the topic</description>
  <!-- 저작권, 저자, 관리자 등 추가정보 -->
  <license>BSD</license>
  <author email="id@sch.ac.kr">your name</author>
  <maintainer email="id@sch.ac.kr">your name</maintainer>
  <url type="repository">https://github.com/goodgodgd/Fall_2018_Lectures</url>
  <!-- 빌드 시스템 지정, catkin 쓰면 됨 -->
  <buildtool_depend>catkin</buildtool_depend>
  <!-- 빌드 할 때 의존성: 언어는 cpp, 표준 메시지 사용, 새 메시지 생성 -->
  <build_depend>roscpp</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_depend>message_generation</build_depend>
  <!-- 실행 할 때 의존성: 언어는 cpp, 표준 메시지 사용, 새 메시지 사용 -->
  <run_depend>roscpp</run_depend>
  <run_depend>std_msgs</run_depend>
  <run_depend>message_runtime</run_depend>
  <export></export>
</package>
```

### 2.2 CMakeList.txt

```cmake
# cmake 최소 버전: ubuntu 16.04에 설치되는 현재 버전은 3.5.1 이므로 만족
cmake_minimum_required(VERSION 2.8.3)
# 반드시!! pakages.xml의 <name>과 같은 이름으로 지정해야 함
project(ros_tutorials_topic)

# 의존성 패키지로 message_generation std_msgs roscpp 들이 필요하며 이 패키지들이 존재하지 않으면 빌드되지 않음
find_package(catkin REQUIRED COMPONENTS message_generation std_msgs roscpp)

# 메시지 선언: 새로 만들 메시지 파일 지정 - MsgTutorial.msg
add_message_files(FILES MsgTutorial.msg)
# 새로 만들 메시지가 의존하는 메시지 지정 - std_msgs
generate_messages(DEPENDENCIES std_msgs)

# 캐킨 패키지 옵션: 라이브러리, 캐킨 의존 패키지(ros 내부의 의존 패키지), 
#	시스템 의존 패키지 (ubuntu에 설치된 패키지) 기술
catkin_package(
  LIBRARIES ros_tutorials_topic
  CATKIN_DEPENDS std_msgs roscpp
)

# 인클루드 디렉토리 설정
# catkin_INCLUDE_DIRS: (캐킨이 관리하는) 설치된 ROS 패키지들의 헤더들이 있는 경로
# 패키지 내부에 헤더 파일이 있다면 ~/catkin_ws/src/package_name/include에 저장한 후
# include_directories(${catkin_INCLUDE_DIRS} include) 이렇게 경로 추가하면 됨
include_directories(${catkin_INCLUDE_DIRS})

# 이 패키지에는 topic_publisher, topic_subscriber 두 개의 실행 파일이 있다.

# topic_publisher 노드에 대한 빌드 옵션
# 실행파일은 src/topic_publisher.cpp 파일로부터 만든다.
add_executable(topic_publisher src/topic_publisher.cpp)
# 실행파일을 빌드하기 전에 메시지 파일 등을 먼저 헤더로 변환하여 빌드해야 한다.
# 새로운 메시지를 정의할 때 관습적으로 붙이자.
add_dependencies(topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# cmake 명령중 link_libraries 는 전체 빌드시 필요한 라이브러리를 지정한다.
# target_link_libraries 는 특정 타겟을 빌드할 때 필요한 라이브러리를 지정한다.
# 참조: https://www.tuwlab.com/27260
target_link_libraries(topic_publisher ${catkin_LIBRARIES})

# topic_subscriber 노드에 대한 빌드 옵션
add_executable(topic_subscriber src/topic_subscriber.cpp)
add_dependencies(topic_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(topic_subscriber ${catkin_LIBRARIES})
```
---

## 3. 메시지 파일 작성

#### 용어 정리
메시지라는 용어는 원래 노드간의 통신(토픽, 서비스, 액션)에 사용되는 데이터 형식을 의미한다.  
메시지를 파일로 정의할 때는 토픽 .msg 파일을 작성하고 서비스는 .srv, 액션은 .action 파일을 작성해서  
여기서 말하는 **메시지**는 토픽의 데이터 형식을 말한다.  

노드는 메시지에 고유의 네임을 붙여 정보를 보내고 수신 측에서도 네임으로 메시지를 식별하여 받는다.  
기본 메시지 자료형과 메시지 구성 방법은 위키를 참조한다. http://wiki.ros.org/msg  

`CMakeLists.txt`에서 메시지 파일을 추가하기 위해 다음 줄을 추가하였다.
```cmake
add_message_files(FILES MsgTutorial.msg)
```
메시지 파일을 추가해 보자.
```bash
$ roscd ros_tutorials_topic
$ mkdir msg
$ cd msg
$ gedit MsgTutorial.msg
```
gedit 창에서 다음과 같은 간단한 메시지를 작성해보자. time은 ros의 기본 타입으로서 seconds / nano seconds 두 가지 단위로 시간을 표현하며 int32 정수단위로 시간을 기록한다. time은 C++에서  ros::Time 형식으로 사용된다.
```
time stamp
int32 data
```
---

## 4. 퍼블리셔 노드 작성

퍼블리셔 노드의 실행파일을 생성하기 위해 `CMakeLists.txt`에 다음 줄을 추가하였다. 
```cmake
add_executable(topic_publisher src/topic_publisher.cpp)
```
실행 파일을 `src/topic_publisher.cpp` 로부터 만든다고 했으므로 소스 파일을 만든다.
```bash
$ roscd ros_tutorials_topic/src
$ gedit topic_publisher.cpp
```
소스 파일을 다음과 같이 작성하자.
```cpp
// ROS Default Header File
#include "ros/ros.h"
// MsgTutorial Message File Header. 빌드시 MsgTutorial.msg 파일로부터 자동 생성됨
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc, char **argv)		// Node Main Function
{
  // 노드 네임 초기화
  ros::init(argc, argv, "topic_publisher");
  // Node handle declaration for communication with ROS system
  ros::NodeHandle nh;

  // Declare publisher: 'ros_tutorial_pub' using the 'MsgTutorial'
  // 토픽 네임: 'ros_tutorial_msg' 
  // 퍼블리셔 큐 사이즈: 100 (100개의 메시지까지 버퍼에 쌓아둘 수 있음)
  ros::Publisher ros_tutorial_pub = 
  	nh.advertise<ros_tutorials_topic::MsgTutorial>
  		("ros_tutorial_msg", 100);

  // loop 빈도 설정, 초당 10번의 loop 반복
  ros::Rate loop_rate(10);

  // Declares message 'msg' in 'MsgTutorial' message file format
  ros_tutorials_topic::MsgTutorial msg;     
  int count = 0;

  // ros나 노드 상태에 이상이 생기지 않는 한 무한 반복
  while (ros::ok())
  {
    // msg.stamp 에 현재 시각 저장, msg.data 에 'count' 저장
    msg.stamp = ros::Time::now();
    msg.data  = count;

	// msg 변수 정보 출력
    ROS_INFO("send msg.stamp.sec = %d", msg.stamp.sec); 
    ROS_INFO("send msg.stamp.nsec = %d", msg.stamp.nsec);
    ROS_INFO("send msg.data = %d", msg.data);

	// msg를 발행
    ros_tutorial_pub.publish(msg);
    
    // 앞서 지정한 주기만큼(0.1s) 정지
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
```






















