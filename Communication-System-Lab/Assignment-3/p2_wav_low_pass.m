clc; %clearing console

[y, fs] = audioread('sound1.wav');
N = length(y); 
t = linspace(0, N/fs, N);

subplot(411);
plot(t,y);
title('time domain sound wave plot');

f = linspace(-fs/2,fs/2,N);
S1 = abs(fftshift(fft(y)));
subplot(412);
plot(f, S1);
title('frequency domain sound plot');
xlim([-3000 3000]);

%Design the FIR LPF
f_cutoff = 1500; % cutoff frequency in Hz
order = 5000;
h = fir1(order,f_cutoff/(fs/2));
%freqz(h,1,1e5,fs);


m = filter(h,1,y);
subplot(413);
plot(t, m)
title('time domain filtered sound plot');

f = linspace(-fs/2,fs/2,length(m));
SS1 = abs(fftshift(fft(m)));
subplot(414);
plot(f, SS1);
title('frequency domain filtered sound plot');
xlim([-3000 3000]);