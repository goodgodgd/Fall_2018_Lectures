% �۾������� �ִ� ��� ������ ������ �� ������ �غ�
clear
x = 0:0.1:10;
y1 = cos(x);
y2 = exp(-x);

% �׷����� ���� �׸��� ���� �׷����� ���ְ� ���� �׸��� ��
plot(x, y1)
plot(x, y2)
pause

% ���� �׷��� ���� �� �׷����� �׸����� hold on
plot(x, y1)
hold on
plot(x, y2)
pause

% ���� �׷��� ���� �����Ϸ��� hold off
hold off
plot(x, y1)