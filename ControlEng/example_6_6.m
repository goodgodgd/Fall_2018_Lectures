clc; clear

s = tf('s');
G = 1/(s*(s+1)*(s+4));

% 먼저 근궤적을 그려놓고 근궤적을 검증해보자
figure(1)
rlocus(G)
axis([-8 2 -5 5])
hold on

disp('1. G의 극점 영점 구하기')
poles = pole(G)
zeros = zero(G);
pause

disp('2. 근궤적의 점근선 구하기')
num_asym = size(poles,1) - size(zeros,1);
fprintf('발산하는 점근선의 개수: %d\n', num_asym)
asym_point = (sum(poles) - sum(zeros))/(num_asym);
fprintf('점근선과 실수축이 만나는 점: %f\n', asym_point)
for k=1:3
    angle = (2*k+1)*pi / num_asym;
    asymptote_angle = rad2deg(atan2(sin(angle), cos(angle)));
    fprintf('점근선의 각도: %f\n', asymptote_angle)
    % (asym_point, 0) -> (asym_point + 100*cos(angle), 100*sin(angle))
    plot([asym_point, asym_point + 100*cos(angle)], [0, 100*sin(angle)], '--')
end
fprintf('\n')
pause

disp('3. 분기점 구하기')
% 전달함수의 분모 계수 추출
[num, den] = tfdata(G);
% K(s) = -1/G(s) = -s*(s+1)*(s+4) = s^3 + 5*s^2 + 4*s
K_s = -den{1};
fprintf('K(s) = %ds^3 + %ds^2 + %ds^1 + %d\n', K_s(1), K_s(2), K_s(3), K_s(4))
% 분기점에서 dK/ds = 0
dK_s = polyder(K_s);
fprintf('dK(s)/ds = %ds^2 + %ds^1 + %ds\n', dK_s(1), dK_s(2), dK_s(3))
% 분기점 후보 구하기
ba = roots(dK_s);
break_away = 0;
for i=1:2
    % 분기점으로부터 다시 K(s_i) 계산하기
    K_i = K_s(1)*ba(i)^3 + K_s(2)*ba(i)^2 + K_s(3)*ba(i) + K_s(4);
    % 분기점에서 K는 양의 실수여야 한다.
    if K_i > 0
        break_away = ba(i);
        fprintf('분기점은 s = %f 이다. K = %f\n', ba(i), K_i)
    end
end
plot(break_away, 0, 'rd')
hold off
