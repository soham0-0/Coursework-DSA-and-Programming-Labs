clc; %clearing console

f_sample = 2;
dt = 1/f_sample;
duration = 100;
t = 0:dt:duration;
f2 = 0.5;
f1 = 0;
m = (f2 - f1)/(2*duration);
psi = 2*pi*cos(m*t.^2 +f1*t);
stem(t, psi, "filled");
ylim([-6.3 6.3]);