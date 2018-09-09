% 작업공간에 있는 모든 데이터 날리기
clear

x = 0:0.1:10;
y1 = cos(x);
y2 = exp(-x);

% cos(x) 그리기
plot(x, y1)
pause

% cos(x), exp(-x) 동시에 그리기
plot(x, y1, x, y2)
pause

% cos(x) 빨간 점으로 그리기
plot(x, y1, 'r.')
pause

% cos(x) 는 빨간 점으로 그리고 exp(-x)는 검은 점선으로 그리기  
plot(x, y1, 'r.', x, y2, 'k--')