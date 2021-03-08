clc; %clearing console

theta = 0:0.000001:2*pi;
y = sin(theta);
x = cos(theta);

plot(y, x);
axis equal;