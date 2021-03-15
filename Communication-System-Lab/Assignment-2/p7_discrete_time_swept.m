clc; %clearing console

t = 0:100;
y = chirp(t, 0, 1, 0.001);

stem(t, y, "filled");