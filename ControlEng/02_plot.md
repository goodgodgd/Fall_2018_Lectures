# 매틀랩으로 그래프 그리기

### 1. plot

- 그래프 하나 그리기: plot(x1, y1, 'option1')
- 여러 그래프 동시에 그리기: plot(x1, y1, 'option1', x2, y2, 'option2', ...)
- xn: 가로축 좌표
- yn: 세로축 좌표
- 'option': 선 스타일, 선 두께, 색상 지정
- 옵션 세부내용 참조: [링크](https://kr.mathworks.com/help/matlab/ref/plot.html?searchHighlight=plot&s_tid=doc_srchtitle#btzitot-LineSpec)

```
% 작업공간에 있는 모든 데이터 날리고 새 데이터 준비
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
```


### 2. 그래프 관련 함수

- **hold** 를 이용한 그래프 중첩
```
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
```

- 그래프 속성 표시
```
% 작업공간에 있는 모든 데이터 날리고 새 데이터 준비
clear
x = 0:0.1:10;
y1 = cos(x);
y2 = exp(-x);

% cos(x) 는 빨간 점으로 그리고 exp(-x)는 검은 점선으로 그리기  
plot(x, y1, 'r.', x, y2, 'k--')
pause

% 그래프 위에 제목 붙이기
title('Control Engineering')

% x, y축 이름 붙이기
xlabel('x축')
ylabel('y축')

% 그래프 영역 지정
axis([0 pi*3 -1.5 1.5])

% 그래프 안에 텍스트 표시
text(2, 1, 'text 함수를 이용한 텍스트 표시')

# 그래프 각 선에 대한 라벨 표시
legend('cos(x)', 'exp(-x)')
```
