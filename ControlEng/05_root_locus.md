# Root Locus Examples

1. 실수 극점만 있을 경우
    ```
    clc; clear
    
    disp('systems with only real poles')
    s = tf('s');
    sys1 = 1/(s+1);
    sys2 = 1/((s+1)*(s+2));
    sys3 = 1/((s+1)*(s+2)*(s+3));
    sys4 = 1/((s+1)*(s+2)*(s+3)*(s+4));
    
    figure(1)
    set(gcf,'Position',[100 300 700 500])
    subplot(2,2,1)
    rlocus(sys1)
    subplot(2,2,2)
    rlocus(sys2)
    subplot(2,2,3)
    rlocus(sys3)
    subplot(2,2,4)
    rlocus(sys4)
    pause
    ```
    결과
    
    ![Alt text](https://github.com/goodgodgd/Fall_2018_Lectures/blob/master/figures/rlocus1.jpg)

2. 극점이 실수와 복소수 모두 있는 경우
    ```
    % continued code
    disp('systems with real and complex poles')
    sys1 = 1/((s+3)*(s^2+4*s+4));
    sys2 = 1/((s+1)*(s^2+4*s+4));
    sys3 = 1/((s+3)*(s^2+4*s+8));
    sys4 = 1/((s+1)*(s^2+4*s+8));
    
    subplot(2,2,1)
    rlocus(sys1)
    subplot(2,2,2)
    rlocus(sys2)
    subplot(2,2,3)
    rlocus(sys3)
    subplot(2,2,4)
    rlocus(sys4)
    pause
    ```
    결과
    
    ![Alt text](https://github.com/goodgodgd/Fall_2018_Lectures/blob/master/figures/rlocus2.jpg)

3. 실수 복소수 극점 + 실수 영점
    ```
    % continued code
    disp('systems with real and complex poles and zeros')
    sys1 = (s+2)/((s+1)*(s+3)*(s+4));
    sys2 = (s+5)/((s+1)*(s+3)*(s+4));
    sys3 = (s+1)/((s+2)*(s^2+6*s+10));
    sys4 = (s+4)/((s+2)*(s^2+6*s+10));
    
    subplot(2,2,1)
    rlocus(sys1)
    subplot(2,2,2)
    rlocus(sys2)
    subplot(2,2,3)
    rlocus(sys3)
    subplot(2,2,4)
    rlocus(sys4)
    pause
    ```
    결과
    
    ![Alt text](https://github.com/goodgodgd/Fall_2018_Lectures/blob/master/figures/rlocus3.jpg)
    
4. 기타 다양한 케이스들
    ```
    % continued code
    disp('other cases')
    sys1 = (s+2)/((s^2+2*s+4)*(s^2+6*s+10));
    sys2 = (s+5)/((s^2+2*s+4)*(s^2+6*s+10));
    sys3 = s*(s+2)/((s^2+2*s+4)*(s^2+6*s+10));
    sys4 = (s^2+4*s+10)/((s^2+2*s+4)*(s^2+8*s+30));
    
    subplot(2,2,1)
    rlocus(sys1)
    subplot(2,2,2)
    rlocus(sys2)
    subplot(2,2,3)
    rlocus(sys3)
    subplot(2,2,4)
    rlocus(sys4)
    ```
    결과
    
    ![Alt text](https://github.com/goodgodgd/Fall_2018_Lectures/blob/master/figures/rlocus4.jpg)
