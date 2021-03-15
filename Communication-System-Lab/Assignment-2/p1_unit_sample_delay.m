clc; %clearing console

t = 0:1:20;
delay = 10;

y = [ones(1,1) zeros(1, 20)];
yD = [zeros(1, delay) ones(1,1) zeros(1, 20 - delay)];

subplot(211), stem(t, y, "filled");
title("No delay");
xlabel("t ->");
ylabel("𝛿(t) ->");

subplot(212), stem(t, yD, "filled");
title("10s delay");
xlabel("t ->");
ylabel("𝛿(t) ->");