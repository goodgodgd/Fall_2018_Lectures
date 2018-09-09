% 작업공간에 있는 모든 데이터 날리고 새 데이터 준비
clear
x = 0:0.1:10;
y1 = cos(x);
y2 = exp(-x);

% 그래프를 따로 그리면 기존 그래프를 없애고 새로 그리게 됨
plot(x, y1)
plot(x, y2)
pause

% 기존 그래프 위에 새 그래프를 그리려면 hold on
plot(x, y1)
hold on
plot(x, y2)
pause

% 기존 그래프 유지 해제하려면 hold off
hold off
plot(x, y1)