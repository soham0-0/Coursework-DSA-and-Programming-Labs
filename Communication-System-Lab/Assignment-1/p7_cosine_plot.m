clc; %clearing console

t = -0.0002:0.000001:0.0002;
a = 1;
f = 10000;
y = a*cos(2*pi*f*t);

%using plot
figure(1);
plot(t, y);
title("using plot");

%using stem
figure(2);
stem(t, y);
title("using stem");
