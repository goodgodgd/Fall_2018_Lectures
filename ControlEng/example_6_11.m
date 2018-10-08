clc; clear

zeta = 0.456;
izeta = sqrt(1-zeta^2);
wn = 11.87;

x = -2*zeta*wn
y = 2*izeta*wn

z1 = rad2deg(atan2(y,8+x))
p1 = rad2deg(atan2(y,3+x))
p2 = rad2deg(atan2(y,6+x))
p3 = rad2deg(atan2(y,10+x))

ang_G = z1-p1-p2-p3
ang_zc = deg2rad(-180 - ang_G)
zc = y/tan(ang_zc)-x
