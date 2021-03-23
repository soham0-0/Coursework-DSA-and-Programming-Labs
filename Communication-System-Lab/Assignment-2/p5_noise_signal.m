clc; %clearing console

t = 0:0.5:50;
m = rand(1, length(t));
noise = 2.*m.*(0.9.^m);
y = 2*sin(t);
yN = y + noise;

subplot(311), plot(t, y);
title("Uncorrupted Signal");
xlabel("time");

subplot(312), plot(t, noise);
title("Noise Signal");
xlabel("time");

subplot(313), plot(t, yN);
title("Noisy Sequence");
xlabel("time");