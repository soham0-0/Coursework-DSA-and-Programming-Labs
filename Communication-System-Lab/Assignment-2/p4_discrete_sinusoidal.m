clc; %clearing console

t = 0:1:40;

A = 1.5;
f = 0.1;

phase = input("Enter phase angle: ");

subplot(211), stem(t, A*sin(2*pi*f*t), "filled");
title("Default");

subplot(212), stem(t, A*sin(2*pi*f*t + phase), "filled");
title("Shifted");