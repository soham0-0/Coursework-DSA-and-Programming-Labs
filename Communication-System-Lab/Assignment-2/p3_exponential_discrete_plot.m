clc; %clearing console

x = 0:0.2:35;

subplot(211), stem(x, exp(x));

subplot(212), stem(x, exp(-x));