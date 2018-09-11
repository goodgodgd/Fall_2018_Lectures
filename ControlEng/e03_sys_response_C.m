clc; clear
% �ý��� �����Լ� ����
s=tf('s') ;                                     
G_s=4*(s+2)/(s*(s+3)*(s+7))
% ���� ��ȯ �ý����� �����Լ�
sys=feedback(G_s,1)

% ���� ���� ���� ��� t=�ð�, u=�Է�, y=���
t=0:0.1:100;
u=t;
[y,t]=lsim(sys,u,t);

% �Է�(u)�� ���(y) �׸���
plot(t,u,'r-', t,y,'b-')
xlabel('Time(sec)')
ylabel('Amplitude')
title('Unity Feedback System: Ramp function')
grid