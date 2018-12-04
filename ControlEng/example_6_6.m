clc; clear

s = tf('s');
G = 1/(s*(s+1)*(s+4));

% ���� �ٱ����� �׷����� �ٱ����� �����غ���
figure(1)
rlocus(G)
axis([-8 2 -5 5])
hold on

disp('1. G�� ���� ���� ���ϱ�')
poles = pole(G)
zeros = zero(G);
pause

disp('2. �ٱ����� ���ټ� ���ϱ�')
num_asym = size(poles,1) - size(zeros,1);
fprintf('�߻��ϴ� ���ټ��� ����: %d\n', num_asym)
asym_point = (sum(poles) - sum(zeros))/(num_asym);
fprintf('���ټ��� �Ǽ����� ������ ��: %f\n', asym_point)
for k=1:3
    angle = (2*k+1)*pi / num_asym;
    asymptote_angle = rad2deg(atan2(sin(angle), cos(angle)));
    fprintf('���ټ��� ����: %f\n', asymptote_angle)
    % (asym_point, 0) -> (asym_point + 100*cos(angle), 100*sin(angle))
    plot([asym_point, asym_point + 100*cos(angle)], [0, 100*sin(angle)], '--')
end
fprintf('\n')
pause

disp('3. �б��� ���ϱ�')
% �����Լ��� �и� ��� ����
[num, den] = tfdata(G);
% K(s) = -1/G(s) = -s*(s+1)*(s+4) = s^3 + 5*s^2 + 4*s
K_s = -den{1};
fprintf('K(s) = %ds^3 + %ds^2 + %ds^1 + %d\n', K_s(1), K_s(2), K_s(3), K_s(4))
% �б������� dK/ds = 0
dK_s = polyder(K_s);
fprintf('dK(s)/ds = %ds^2 + %ds^1 + %ds\n', dK_s(1), dK_s(2), dK_s(3))
% �б��� �ĺ� ���ϱ�
ba = roots(dK_s);
break_away = 0;
for i=1:2
    % �б������κ��� �ٽ� K(s_i) ����ϱ�
    K_i = K_s(1)*ba(i)^3 + K_s(2)*ba(i)^2 + K_s(3)*ba(i) + K_s(4);
    % �б������� K�� ���� �Ǽ����� �Ѵ�.
    if K_i > 0
        break_away = ba(i);
        fprintf('�б����� s = %f �̴�. K = %f\n', ba(i), K_i)
    end
end
plot(break_away, 0, 'rd')
hold off
