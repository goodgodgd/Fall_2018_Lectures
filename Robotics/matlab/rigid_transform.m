clc; clear

% pose1 in global frame
p1 = [5, 4, pi/6];
theta = p1(3);
R1 = [cos(theta), -sin(theta); sin(theta), cos(theta)];
t1 = [p1(1); p1(2)];
T1 = [R1 t1; 0 0 1]

% pose2 relative to pose1
p2_1 = [3, 4, pi/3];
theta = p2_1(3);
R2_1 = [cos(theta), -sin(theta); sin(theta), cos(theta)];
t2_1 = [p2_1(1); p2_1(2)];
T2_1 = [R2_1 t2_1; 0 0 1]

% pose2 in global frame
T2 = T1 * T2_1

disp('transform point in 2')
pa_1 = [1,2,1]';
pa_g = T1*pa_1
inv_T2_1 = inv(T2_1)
pa_2 = T2_1\pa_1

disp('transform point in 3')
pb_2 = [3,2,1]';
pb_1 = T2_1 * pb_2
pb_g = T2 * pb_2


% x, y axes in homogeneous coordinates
baisic_axes = [0 0 1; 1 0 1; 0 1 1]';
frameg = baisic_axes;   % in global frame
frame1 = T1 * baisic_axes; % transform to frame1
frame2 = T2 * baisic_axes; % transform to frame2

% plot global frame with blue line
hold off
plot(frameg(1, [1 2]), frameg(2, [1 2]), 'b-', frameg(1, [1 3]), frameg(2, [1 3]), 'b-')
text(frameg(1, 1), frameg(2, 1)-0.1, 'global frame')
hold on
% plot frame1 with red line
plot(frame1(1, [1 2]), frame1(2, [1 2]), 'r-', frame1(1, [1 3]), frame1(2, [1 3]), 'r-')
text(frame1(1, 1), frame1(2, 1)-0.1, 'frame1')
% plot frame2 with black line
plot(frame2(1, [1 2]), frame2(2, [1 2]), 'k-', frame2(1, [1 3]), frame2(2, [1 3]), 'k-')
text(frame2(1, 1), frame2(2, 1)-0.1, 'frame2')
axis([-1 13 -1 13])

plot(pa_g(1), pa_g(2), '*')
plot(pb_g(1), pb_g(2), '*')
