clc; clear

zeta = 0.456;
izeta = sqrt(1-zeta^2);
wn = 11.87;
x1 = -zeta*wn; y1 = izeta*wn;

s = tf('s');
G1 = (s+8)/((s+3)*(s+6)*(s+10));
figure(1)
plot(x1, y1, '*k')
hold on
rlocus(G1)
axis([-50 2 -25 25])
set(gcf,'Position',[100 100 600 600])
hold off

x2 = 2*x1; y2 = 2*y1;
z1 = rad2deg(atan2(y2,8+x2))
p1 = rad2deg(atan2(y2,3+x2))
p2 = rad2deg(atan2(y2,6+x2))
p3 = rad2deg(atan2(y2,10+x2))

ang_G = z1-p1-p2-p3
ang_zc = deg2rad(-180 - ang_G)
zc = y2/tan(ang_zc)-x2

s = tf('s');
G2 = (s+zc)*(s+0.6)*(s+8)/(s*(s+3)*(s+6)*(s+10));
figure(2)
plot(x2, y2, '*k')
hold on
rlocus(G2)
axis([-100 2 -50 50])
set(gcf,'Position',[800 100 600 600])
hold off
