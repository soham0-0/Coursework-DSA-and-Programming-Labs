clc; %clearing console

t = 0:1:20;
delay = 10;

y = ones(1,21);
yD = [zeros(1, delay) ones(1, 21 - delay)];
yD_2 = [zeros(1, delay) 2*ones(1, 21 - delay)];

subplot(311), stem(t, y, "filled");
title("No delay");
xlabel("t ->");
ylabel("H(t) ->");
ylim([0 2]);

subplot(312), stem(t, yD, "filled");
title("10s delay");
xlabel("t ->");
ylabel("H(t) ->");
ylim([0 2]);

subplot(313), stem(t, yD_2, "filled");
title("10s delay with amplitude 2");
xlabel("t ->");
ylabel("H(t) ->");
ylim([0 2]);