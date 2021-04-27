clc; %clearing console

t = 0:0.01:4;
fc = 10;
fm1 = 0.5;
fm2 = 1;
Am1 = 4;
Am2 = 3;
kf = 2;
m_t = Am1*cos(2*pi*fm1*t) + Am2*cos(2*pi*fm2*t);
y_t = cos(2*pi*fc*t);
x_t = (Am1/fm1*sin(2*pi*fm1*t) + Am2/fm2*sin(2*pi*fm2*t))*kf;
s_t = cos(2*pi*fc*t + x_t);

figure("name", "Time Domain");
subplot(211);
ylabel("Message");
plot(t, m_t);
subplot(212);
ylabel("Carrier");
plot(t,y_t);

figure('name', 'Frequency Domain');
subplot(211);
plot(abs(fftshift(fft(m_t))));
ylabel("Message");
subplot(212);
plot(abs(fftshift(fft(y_t))));
ylabel("Carrier");

figure("name", "Modulated Signal");
subplot(211)
plot(t,s_t);
title("Time Domain");
subplot(212);
plot(abs(fftshift(fft(s_t))));
title("Frequency Domain");