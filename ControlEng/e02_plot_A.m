% �۾������� �ִ� ��� ������ ������
clear

x = 0:0.1:10;
y1 = cos(x);
y2 = exp(-x);

% cos(x) �׸���
plot(x, y1)
pause

% cos(x), exp(-x) ���ÿ� �׸���
plot(x, y1, x, y2)
pause

% cos(x) ���� ������ �׸���
plot(x, y1, 'r.')
pause

% cos(x) �� ���� ������ �׸��� exp(-x)�� ���� �������� �׸���  
plot(x, y1, 'r.', x, y2, 'k--')