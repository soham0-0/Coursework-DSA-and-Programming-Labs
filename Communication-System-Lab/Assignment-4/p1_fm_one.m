clc; %clearing console

fm = 25;
fc = 400;
mi = 10;
t = 0:0.0001:0.12;

m = sin(2*pi*fm*t);
c = sin(2*pi*fc*t);
y = sin(2*pi*fc*t + (mi.*-cos(2*pi*fm*t)));

figure("name", "Time Domain");
subplot(311); plot(t,m); ylim([-2 2]);
ylabel('Signal'); xlabel('Time'); title('Modulating signal');
subplot(3,1,2); plot(t,c); ylim([-2 2]);
ylabel('Signal'); xlabel('Time'); title('Carrier signal');
subplot(313); plot(t,y); ylim([-2 2]);
ylabel('Amplitude'); xlabel('Time'); title('FM signal');

Fs = 10000;
y1 = fftshift(fft(m,length(m)));
N1 = length(y1);
n1 = (-0.5:1/N1:0.5-1/N1)*Fs;
f1 = sqrt(y1.*conj(y1));
y2 = fftshift(fft(c,length(c)));
N2 = length(y2);
n2 = (-0.5:1/N2:0.5-1/N2)*Fs;
f2 = sqrt(y2.*conj(y2));
y3 = fftshift(fft(y,length(y)));
N3 = length(y3);
n3 = (-0.5:1/N3:0.5-1/N3)*Fs;
f3 = sqrt(y3.*conj(y3));

figure("name", "Frequency Domain");
subplot(311); plot(n1,f1); ylim([0 600]); xlim([-1000 1000]);
ylabel('Amplitude'); xlabel('Frequency'); title('Modulating signal');
subplot(312); plot(n2,f2); ylim([0 600]); xlim([-1000 1000]);
ylabel('Amplitude'); xlabel('Frequency'); title('Carrier signal');
subplot(313); plot(n3,f3); ylim([0 600]); xlim([-1000 1000]);
ylabel('Amplitude'); xlabel('Frequency'); title('FM signal');