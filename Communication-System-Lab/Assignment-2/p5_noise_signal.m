clc; %clearing console

m = 0:1:50;
y = 2.*m.*(0.9.^m);
noise = 2*rand(1, length(m));
x = y + noise;

subplot(311), stem(m, y, "filled");
title("Uncorrupted Signal");
xlabel("time");

subplot(312), stem(m, noise, "filled");
title("Noise Signal");
xlabel("time");

subplot(313), stem(m, x, "filled");
title("Noisy Sequence");
xlabel("time");

