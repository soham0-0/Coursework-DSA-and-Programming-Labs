clc; %clearing console

t = 0:0.01:2;
fm = 2;             
fc = 20;            
Am = 2;
Ac = 10;

m = Am*sin(2*pi*fm*t);
c = Ac*cos(2*pi*fc*t);

y = m .* c;

subplot(311);
plot(t, m);
title('Baseband Signal');
xlabel('Time');
ylabel('Amplitude');

subplot(312);
plot(t, c);
title('Carrier Signal');
xlabel('Time');
ylabel('Amplitude');

subplot(313);
plot(t, y);
title('Modulated Signal');
xlabel('Time');
ylabel('Amplitude');